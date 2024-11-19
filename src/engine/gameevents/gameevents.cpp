#include "gameevents.h"
#include "GGameEvents.h"
#include "../../memory/hooks/FuncHook.h"
#include "../../plugins/core/scripting.h"
#include "../../plugins/PluginManager.h"
#include "../../player/playermanager/PlayerManager.h"
#include "../../vendor/dynlib/module.h"

#include <vector>
#include <map>
#include <stack>

SH_DECL_HOOK2(IGameEventManager2, FireEvent, SH_NOATTRIB, 0, bool, IGameEvent*, bool);
SH_DECL_HOOK2(IGameEventManager2, LoadEventsFromFile, SH_NOATTRIB, 0, int, const char*, bool);
int loadEventFromFileHookID = -1;

std::stack<IGameEvent*> dupEvents;

void EventManager::Initialize()
{
    DynLibUtils::CModule servermodule = DetermineModuleByLibrary("server");
    auto CGameEventManagerVTable = servermodule.GetVirtualTableByName("CGameEventManager");
    loadEventFromFileHookID = SH_ADD_DVPHOOK(IGameEventManager2, LoadEventsFromFile, (IGameEventManager2*)((void*)CGameEventManagerVTable), SH_MEMBER(this, &EventManager::LoadEventsFromFile), false);
}

void EventManager::RegisterGameEvents()
{
    PLUGIN_PRINT("Game Events", "Loading game events...\n");
    for (auto it = gameEventsRegister.begin(); it != gameEventsRegister.end(); ++it)
    {
        if (!g_gameEventManager->FindListener(this, it->first.c_str()))
            g_gameEventManager->AddListener(this, it->first.c_str(), true);
    }
    PLUGIN_PRINTF("Game Events", "%d game events have been succesfully loaded.\n", gameEventsRegister.size());
}

int EventManager::LoadEventsFromFile(const char* filePath, bool searchAll)
{
    if (!g_gameEventManager) {
        g_gameEventManager = META_IFACEPTR(IGameEventManager2);
    
        SH_ADD_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnFireEvent), false);
        SH_ADD_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnPostFireEvent), true);
    }

    RETURN_META_VALUE(MRES_IGNORED, 0);
}

void EventManager::Shutdown()
{
    SH_REMOVE_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnFireEvent), false);
    SH_REMOVE_HOOK(IGameEventManager2, FireEvent, g_gameEventManager, SH_MEMBER(this, &EventManager::OnPostFireEvent), true);
    SH_REMOVE_HOOK_ID(loadEventFromFileHookID);

    g_gameEventManager->RemoveListener(this);
}

void EventManager::FireGameEvent(IGameEvent* pEvent) {}

bool EventManager::OnFireEvent(IGameEvent* pEvent, bool bDontBroadcast)
{
    if (!pEvent)
    {
        RETURN_META_VALUE(MRES_IGNORED, false);
    }

    std::string eventName = pEvent->GetName();
    PRINTF("%s\n", eventName.c_str());

    std::string prettyEventName = gameEventsRegister[eventName];
    if (!prettyEventName.empty())
    {
        PluginEvent* event = new PluginEvent("core", pEvent, nullptr);
        EventResult result = g_pluginManager->ExecuteEvent("core", prettyEventName, encoders::msgpack::SerializeToString({}), event);
        delete event;
        if (prettyEventName == "OnPlayerSpawn")
        {
            auto slot = pEvent->GetPlayerSlot("userid");
            Player* player = g_playerManager->GetPlayer(slot);
            if (player)
                player->SetFirstSpawn(false);
        }
        if (result != EventResult::Continue)
        {
            dupEvents.push(g_gameEventManager->DuplicateEvent(pEvent));
            g_gameEventManager->FreeEvent(pEvent);
            RETURN_META_VALUE(MRES_SUPERCEDE, false);
        }
    }

    dupEvents.push(g_gameEventManager->DuplicateEvent(pEvent));
    RETURN_META_VALUE(MRES_IGNORED, true);
}

bool EventManager::OnPostFireEvent(IGameEvent* pEvent, bool bDontBroadcast)
{
    if (!pEvent)
    {
        RETURN_META_VALUE(MRES_IGNORED, false);
    }

    IGameEvent* realGameEvent = dupEvents.top();

    std::string eventName = realGameEvent->GetName();

    std::string prettyEventName = gameEventsRegister[eventName];
    if (!prettyEventName.empty())
    {
        PluginEvent* event = new PluginEvent("core", realGameEvent, nullptr);
        EventResult result = g_pluginManager->ExecuteEvent("core", string_format("OnPost%s", prettyEventName.substr(2).c_str()), encoders::msgpack::SerializeToString({}), event);
        delete event;

        if (result != EventResult::Continue) {
            g_gameEventManager->FreeEvent(realGameEvent);
            dupEvents.pop();
            RETURN_META_VALUE(MRES_SUPERCEDE, false);
        }
    }

    g_gameEventManager->FreeEvent(realGameEvent);
    dupEvents.pop();
    RETURN_META_VALUE(MRES_IGNORED, true);
}