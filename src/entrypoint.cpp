#include <stdio.h>
#include <thread>
#include "entrypoint.h"

#include <tier1/convar.h>
#include <interfaces/interfaces.h>
#include <metamod_oslink.h>

#include <steam/steam_gameserver.h>

#include "addons/addons.h"
#include "addons/clients.h"
#include "configuration/Configuration.h"
#include "crashreporter/CrashReport.h"
#include "gameevents/gameevents.h"
#include "logs/Logger.h"
#include "translations/Translations.h"
#include "filters/ConsoleFilter.h"
#include "hooks/NativeHooks.h"
#include "player/PlayerManager.h"
#include "plugins/PluginManager.h"
#include "signatures/Signatures.h"
#include "signatures/Offsets.h"

SH_DECL_HOOK3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t &, ISource2WorldSession *, const char *);
SH_DECL_HOOK3_void(IServerGameDLL, GameFrame, SH_NOATTRIB, 0, bool, bool, bool);
SH_DECL_HOOK4_void(IServerGameClients, ClientActive, SH_NOATTRIB, 0, CPlayerSlot, bool, const char *, uint64);
SH_DECL_HOOK5_void(IServerGameClients, ClientDisconnect, SH_NOATTRIB, 0, CPlayerSlot, ENetworkDisconnectionReason, const char *, uint64, const char *);
SH_DECL_HOOK1_void(IServerGameClients, ClientSettingsChanged, SH_NOATTRIB, 0, CPlayerSlot);
SH_DECL_HOOK6_void(IServerGameClients, OnClientConnected, SH_NOATTRIB, 0, CPlayerSlot, const char *, uint64, const char *, const char *, bool);
SH_DECL_HOOK6(IServerGameClients, ClientConnect, SH_NOATTRIB, 0, bool, CPlayerSlot, const char *, uint64, const char *, bool, CBufferString *);
SH_DECL_HOOK2(IGameEventManager2, FireEvent, SH_NOATTRIB, 0, bool, IGameEvent *, bool);
SH_DECL_HOOK2_void(IServerGameClients, ClientCommand, SH_NOATTRIB, 0, CPlayerSlot, const CCommand &);
SH_DECL_HOOK3_void(ICvar, DispatchConCommand, SH_NOATTRIB, 0, ConCommandHandle, const CCommandContext &, const CCommand &);
SH_DECL_HOOK0_void(IServerGameDLL, GameServerSteamAPIActivated, SH_NOATTRIB, 0);

#ifdef _WIN32
FILE _ioccc[] = {*stdin, *stdout, *stderr};
extern "C" FILE *__cdecl __iob_func(void)
{
    return _ioccc;
}
#endif

//////////////////////////////////////////////////////////////
/////////////////  Core Variables & Functions  //////////////
////////////////////////////////////////////////////////////

Swiftly g_Plugin;
ISource2Server *server = nullptr;
IServerGameClients *gameclients = nullptr;
IVEngineServer2 *engine = nullptr;
IServerGameClients *g_clientsManager = nullptr;
ICvar *icvar = nullptr;
ICvar *g_pcVar = nullptr;
IGameResourceService *g_pGameResourceService = nullptr;
CEntitySystem *g_pEntitySystem = nullptr;
CGameEntitySystem *g_pGameEntitySystem = nullptr;
IGameEventManager2 *g_gameEventManager = nullptr;
IGameEventSystem *g_pGameEventSystem = nullptr;
CEntityListener g_entityListener;
CSteamGameServerAPIContext g_SteamAPI;
CSchemaSystem *g_pSchemaSystem2 = nullptr;

class CGameResourceService
{
public:
    CGameEntitySystem *GetGameEntitySystem()
    {
        return *reinterpret_cast<CGameEntitySystem **>((uintptr_t)(this) + g_Offsets->GetOffset("GameEntitySystem"));
    }
};

CGameEntitySystem *GameEntitySystem()
{
    return g_pGameEntitySystem;
}

//////////////////////////////////////////////////////////////
/////////////////      Internal Variables      //////////////
////////////////////////////////////////////////////////////

CUtlVector<FuncHookBase *> g_vecHooks;
CUtlVector<CGameEventListener *> g_GameEventListener;

Addons g_addons;
Configuration *g_Config = nullptr;
ConsoleFilter *g_conFilter = nullptr;
Translations *g_translations = nullptr;
Logger *g_Logger = nullptr;
PlayerManager *g_playerManager = nullptr;
PluginManager *g_pluginManager = nullptr;
Offsets *g_Offsets = nullptr;
Signatures *g_Signatures = nullptr;

//////////////////////////////////////////////////////////////
/////////////////          Core Class          //////////////
////////////////////////////////////////////////////////////

PLUGIN_EXPOSE(Swiftly, g_Plugin);
bool Swiftly::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
    PLUGIN_SAVEVARS();

    g_SMAPI->AddListener(this, this);

    GET_V_IFACE_CURRENT(GetEngineFactory, engine, IVEngineServer, INTERFACEVERSION_VENGINESERVER);
    GET_V_IFACE_CURRENT(GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetServerFactory, server, ISource2Server, INTERFACEVERSION_SERVERGAMEDLL);
    GET_V_IFACE_ANY(GetServerFactory, gameclients, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
    GET_V_IFACE_ANY(GetServerFactory, g_clientsManager, IServerGameClients, INTERFACEVERSION_SERVERGAMECLIENTS);
    GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkServerService, INetworkServerService, NETWORKSERVERSERVICE_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetEngineFactory, g_pNetworkMessages, INetworkMessages, NETWORKMESSAGES_INTERFACE_VERSION);
    GET_V_IFACE_ANY(GetFileSystemFactory, g_pFullFileSystem, IFileSystem, FILESYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameResourceService, IGameResourceService, GAMERESOURCESERVICESERVER_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pGameEventSystem, IGameEventSystem, GAMEEVENTSYSTEM_INTERFACE_VERSION);
    GET_V_IFACE_CURRENT(GetEngineFactory, g_pSchemaSystem2, CSchemaSystem, SCHEMASYSTEM_INTERFACE_VERSION);

    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &Swiftly::Hook_GameFrame, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientActive, gameclients, this, &Swiftly::Hook_ClientActive, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &Swiftly::Hook_ClientDisconnect, true);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientSettingsChanged, gameclients, this, &Swiftly::Hook_ClientSettingsChanged, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &Swiftly::Hook_OnClientConnected, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &Swiftly::Hook_ClientConnect, false);
    SH_ADD_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &Swiftly::Hook_StartupServer, true);
    SH_ADD_HOOK_MEMFUNC(ICvar, DispatchConCommand, icvar, this, &Swiftly::Hook_DispatchConCommand, false);
    SH_ADD_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIActivated, server, this, &Swiftly::Hook_GameServerSteamAPIActivated, false);

    g_pCVar = icvar;

    ConVar_Register(FCVAR_RELEASE | FCVAR_SERVER_CAN_EXECUTE | FCVAR_CLIENT_CAN_EXECUTE | FCVAR_GAMEDLL);

    if (!BeginCrashListener())
        PRINTRET("Crash Reporter failed to initialize.\n", false)

    g_pluginManager = new PluginManager();
    g_Config = new Configuration();
    g_conFilter = new ConsoleFilter();
    g_Signatures = new Signatures();
    g_Offsets = new Offsets();
    g_playerManager = new PlayerManager();
    g_Logger = new Logger();
    g_translations = new Translations();

    if (g_Config->LoadConfiguration())
        PRINT("The configurations has been succesfully loaded.\n");
    else
        PRINTRET("Failed to load configurations. The plugin will not work.\n", false)

    g_Config->LoadPluginConfigurations();
    g_Signatures->LoadSignatures();
    g_Offsets->LoadOffsets();

    g_addons.LoadAddons();

    if (!InitializeHooks())
        PRINTRET("Hooks failed to initialize.\n", false)
    else
        PRINT("Hooks initialized succesfully.\n");

    g_playerManager->LoadPlayers();
    g_conFilter->LoadFilters();
    g_translations->LoadTranslations();

    if (g_Config->FetchValue<bool>("core.console_filtering"))
        g_conFilter->Toggle();

    g_pluginManager->LoadPlugins();
    g_pluginManager->StartPlugins();

    if (late)
    {
        g_SteamAPI.Init();
        m_CallbackDownloadItemResult.Register(this, &Swiftly::OnAddonDownloaded);
    }

    g_addons.SetupThread();

    PRINT("Succesfully started.\n");

    return true;
}

void Swiftly::Hook_GameServerSteamAPIActivated()
{
    if (!CommandLine()->HasParm("-dedicated"))
        return;

    g_SteamAPI.Init();
    m_CallbackDownloadItemResult.Register(this, &Swiftly::OnAddonDownloaded);

    std::thread([&]() -> void
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

                    if (g_addons.GetStatus())
                        g_addons.RefreshAddons(true); })
        .detach();

    RETURN_META(MRES_IGNORED);
}

void Swiftly::OnAddonDownloaded(DownloadItemResult_t *pResult)
{
    g_addons.OnAddonDownloaded(pResult);
}

void Swiftly::AllPluginsLoaded()
{
}

bool Swiftly::Unload(char *error, size_t maxlen)
{
    g_pluginManager->StopPlugins();
    g_pluginManager->UnloadPlugins();

    UnloadHooks();
    UnregisterEventListeners();

    SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameFrame, server, this, &Swiftly::Hook_GameFrame, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientActive, gameclients, this, &Swiftly::Hook_ClientActive, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientDisconnect, gameclients, this, &Swiftly::Hook_ClientDisconnect, true);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientSettingsChanged, gameclients, this, &Swiftly::Hook_ClientSettingsChanged, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, OnClientConnected, gameclients, this, &Swiftly::Hook_OnClientConnected, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameClients, ClientConnect, gameclients, this, &Swiftly::Hook_ClientConnect, false);
    SH_REMOVE_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &Swiftly::Hook_StartupServer, true);
    SH_REMOVE_HOOK_MEMFUNC(ICvar, DispatchConCommand, icvar, this, &Swiftly::Hook_DispatchConCommand, false);
    SH_REMOVE_HOOK_MEMFUNC(IServerGameDLL, GameServerSteamAPIActivated, server, this, &Swiftly::Hook_GameServerSteamAPIActivated, false);

    g_pGameEntitySystem->RemoveListenerEntity(&g_entityListener);

    ConVar_Unregister();
    return true;
}

void Swiftly::OnLevelInit(char const *pMapName, char const *pMapEntities, char const *pOldLevel, char const *pLandmarkName, bool loadGame, bool background)
{
}

void Swiftly::OnLevelShutdown()
{
    g_translations->LoadTranslations();
    g_Config->LoadPluginConfigurations();
}

bool bDone = false;
void Swiftly::Hook_StartupServer(const GameSessionConfiguration_t &config, ISource2WorldSession *, const char *)
{
    if (!bDone)
    {
        g_pGameEntitySystem = ((CGameResourceService *)g_pGameResourceService)->GetGameEntitySystem();
        g_pEntitySystem = g_pGameEntitySystem;

        g_pGameEntitySystem->AddListenerEntity(&g_entityListener);

        bDone = true;
    }

    g_ClientsPendingAddon.RemoveAll();

    if (g_addons.GetStatus())
        g_addons.RefreshAddons();
}

void Swiftly::UpdatePlayers()
{
    // Credits to: https://github.com/Source2ZE/ServerListPlayersFix (Source2ZE Team)
    if (!engine->GetServerGlobals())
        return;

    for (int i = 0; i < engine->GetServerGlobals()->maxClients; i++)
    {
        auto steamId = engine->GetClientSteamID(CPlayerSlot(i));
        if (steamId)
        {
            auto controller = (CBasePlayerController *)g_pEntitySystem->GetEntityInstance(CEntityIndex(i + 1));
            if (controller)
                g_SteamAPI.SteamGameServer()->BUpdateUserData(*steamId, controller->m_iszPlayerName(), gameclients->GetPlayerScore(CPlayerSlot(i)));
        }
    }
}

void Swiftly::Hook_GameFrame(bool simulating, bool bFirstTick, bool bLastTick)
{
    static double g_flNextUpdate = 0.0;

    double curtime = Plat_FloatTime();
    if (curtime > g_flNextUpdate)
    {
        // Credits to: https://github.com/Source2ZE/ServerListPlayersFix (Source2ZE Team)
        UpdatePlayers();

        g_flNextUpdate = curtime + 5.0;
    }

    //////////////////////////////////////////////////////////////
    /////////////////            Player            //////////////
    ////////////////////////////////////////////////////////////
    for (uint16_t i = 0; i < g_playerManager->GetPlayerCap(); i++)
    {
        Player *player = g_playerManager->GetPlayer(i);
        if (!player)
            continue;

        if (player->HasCenterText())
            player->RenderCenterText();
    }

    while (!m_nextFrame.empty())
    {
        m_nextFrame.front()();
        m_nextFrame.pop_front();
    }
}

void Swiftly::Hook_ClientActive(CPlayerSlot slot, bool bLoadGame, const char *pszName, uint64 xuid)
{
}

void Swiftly::Hook_ClientDisconnect(CPlayerSlot slot, ENetworkDisconnectionReason reason, const char *pszName, uint64 xuid, const char *pszNetworkID)
{
    Player *player = g_playerManager->GetPlayer(slot);
    if (player)
        g_playerManager->UnregisterPlayer(slot);
}

void Swiftly::Hook_ClientSettingsChanged(CPlayerSlot slot)
{
}

void Swiftly::Hook_OnClientConnected(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, const char *pszAddress, bool bFakePlayer)
{
    if (bFakePlayer)
    {
        Player *player = new Player(true, slot.Get(), pszName, 0, "127.0.0.1");
        g_playerManager->RegisterPlayer(player);
    }
}

bool Swiftly::Hook_ClientConnect(CPlayerSlot slot, const char *pszName, uint64 xuid, const char *pszNetworkID, bool unk1, CBufferString *pRejectReason)
{
    if (!g_addons.OnClientConnect(xuid))
        RETURN_META_VALUE(MRES_IGNORED, true);

    std::string ip_address = explode(pszNetworkID, ":")[0];
    Player *player = new Player(false, slot.Get(), pszName, xuid, ip_address);
    g_playerManager->RegisterPlayer(player);

    player->SetConnected(true);

    RETURN_META_VALUE(MRES_IGNORED, true);
}

void Swiftly::Hook_DispatchConCommand(ConCommandHandle cmd, const CCommandContext &ctx, const CCommand &args)
{
}

void Swiftly::NextFrame(std::function<void()> fn)
{
    m_nextFrame.push_back(fn);
}

void CEntityListener::OnEntitySpawned(CEntityInstance *pEntity)
{
}

void CEntityListener::OnEntityParentChanged(CEntityInstance *pEntity, CEntityInstance *pNewParent)
{
}

void CEntityListener::OnEntityCreated(CEntityInstance *pEntity)
{
}

void CEntityListener::OnEntityDeleted(CEntityInstance *pEntity)
{
}

bool Swiftly::Pause(char *error, size_t maxlen)
{
    return true;
}

bool Swiftly::Unpause(char *error, size_t maxlen)
{
    return true;
}

const char *Swiftly::GetLicense()
{
    return "MIT License";
}

const char *Swiftly::GetVersion()
{
    return "rework";
}

const char *Swiftly::GetDate()
{
    return __DATE__;
}

const char *Swiftly::GetLogTag()
{
    return "SWIFTLY";
}

const char *Swiftly::GetAuthor()
{
    return "Swiftly Development Team";
}

const char *Swiftly::GetDescription()
{
    return "Swiftly - Framework";
}

const char *Swiftly::GetName()
{
    return "Swiftly";
}

const char *Swiftly::GetURL()
{
    return "https://github.com/swiftly-solution/swiftly/tree/rework";
}