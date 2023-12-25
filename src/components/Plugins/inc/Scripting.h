#ifndef _components_plugins_scripting_h
#define _components_plugins_scripting_h

#include "../../../common.h"
#include "../../../hooks/Hooks.h"
#include "../../../hooks/GameEvents.h"
#include "../../../player/Player.h"
#include "../../../player/PlayerManager.h"
#include "../../../logs/Log.h"
#include "../../../http/ContentTypes.h"
#include "PluginsComponent.h"
#include "Plugin.h"

typedef bool (*Plugin_OnClientConnect)(uint32);
typedef void (*Plugin_OnClientDisconnect)(uint32);
typedef void (*Plugin_OnPlayerSpawn)(uint32);
typedef void (*Plugin_OnRoundPrestart)();
typedef void (*Plugin_OnRoundStart)(long, long, const char *);
typedef void (*Plugin_OnRoundEnd)(unsigned char, unsigned char, const char *, unsigned char, short, unsigned char);
typedef void (*Plugin_BombBeginPlant)(uint32, uint16);
typedef void (*Plugin_BombAbortPlant)(uint32, uint16);
typedef void (*Plugin_BombPlanted)(uint32, uint16);
typedef void (*Plugin_BombBeginDefuse)(uint32, uint16);
typedef void (*Plugin_BombAbortDefuse)(uint32, uint16);
typedef void (*Plugin_BombDefused)(uint32, uint16);
typedef void (*Plugin_BombExploded)(uint32, uint16);
typedef void (*Plugin_BombDropped)(uint32);
typedef void (*Plugin_BombPickup)(uint32);
typedef void (*Plugin_OnGameTick)(bool, bool, bool);
typedef bool (*Plugin_OnPlayerChat)(uint32, const char *, bool);
typedef void (*Plugin_OnMapLoad)(const char *);
typedef void (*Plugin_OnMapUnload)(const char *);
typedef bool (*Plugin_OnClientGameMessage)(uint32, int, const char *);
typedef void (*Plugin_OnPlayerDeath)(int, int, int, bool, const char *, bool, short, short, short, short, bool, bool, bool, bool, float, short, short, short);
typedef void (*Plugin_OnPlayerHurt)(int, int, short, short, short, const char *);
typedef bool (*Plugin_ShouldHearVoice)(uint32);

void scripting_Commands_RegisterCommand(const char *pluginName, const char *name, void *funcPtr);
void scripting_Commands_UnregisterCommand(const char *name);

const char *scripting_Configuration_Fetch(const char *key);
uint32 scripting_Configuration_FetchArraySize(const char *key);
bool scripting_Configuration_Exists(const char *key);

int scripting_Server_GetConvarInt(const char *name);
unsigned int scripting_Server_GetConvarUint(const char *name);
bool scripting_Server_GetConvarBool(const char *name);
float scripting_Server_GetConvarFloat(const char *name);
const char *scripting_Server_GetConvarString(const char *name);
EConVarType scripting_Server_GetConvarType(const char *name);
void scripting_Server_SetConvar(const char *name, ...);

bool scripting_Database_Connect(const char *connectionName);
const char *scripting_Database_EscapeString(const char *connectionName, const char *value);
const char *scripting_Database_Query(const char *connectionName, const char *query);

uint32_t scripting_Entity_Create();
void scripting_Entity_Spawn(uint32_t entityID);
void scripting_Entity_Destroy(uint32_t entityID);
void scripting_Entity_SetModel(uint32_t entityID, const char *model);
const char *scripting_Entity_GetCoords(uint32_t entityID);
void scripting_Entity_SetCoords(uint32_t entityID, float x, float y, float z);
const char *scripting_Entity_GetAngles(uint32_t entityID);
void scripting_Entity_SetAngles(uint32_t entityID, float x, float y, float z);
const char *scripting_Entity_GetColors(uint32_t entityID);
void scripting_Entity_SetColors(uint32_t entityID, int r, int g, int b, int a);

bool scripting_OnClientChat(CBasePlayerController *controller, const char *text, bool teamonly);
bool scripting_OnClientGameMessage(CBasePlayerController *controller, int destination, const char *text);
bool scripting_ShouldHearVoice(Player *player);

uint64_t scripting_HTTP_CreateRequest(const char *domain);
void scripting_HTTP_SetBody(uint64_t requestID, const char *body);
void scripting_HTTP_AddHeader(uint64_t requestID, const char *key, const char *value);
void scripting_HTTP_DeleteHeader(uint64_t requestID, const char *key);
void scripting_HTTP_AddMultipartFile(uint64_t requestID, const char *field, const char *content, const char *filename, const char *file_content_type);
void scripting_HTTP_SetContentType(uint64_t requestID, ContentType content_type);
void scripting_HTTP_SetBasicAuthentication(uint64_t requestID, const char *username, const char *password);
void scripting_HTTP_SetBearerAuthenticationToken(uint64_t requestID, const char *token);
void scripting_HTTP_SetFollowRedirect(uint64_t requestID, bool follow);
const char *scripting_HTTP_GetBody(uint64_t requestID);
int scripting_HTTP_GetStatusCode(uint64_t requestID);
const char *scripting_HTTP_GetError(uint64_t requestID);
void scripting_HTTP_Get(uint64_t requestID, const char *path);
void scripting_HTTP_Delete(uint64_t requestID, const char *path);
void scripting_HTTP_Post(uint64_t requestID, const char *path);
void scripting_HTTP_Put(uint64_t requestID, const char *path);
void scripting_HTTP_Patch(uint64_t requestID, const char *path);
void scripting_HTTP_Close(uint64_t requestID);

void scripting_Logger_CreateLogger(const char *plugin_name);
void scripting_Logger_WriteLog(const char *plugin_name, ELogType log_type, const char *text);

const char *scripting_Player_GetName(uint32 playerId);
uint64 scripting_Player_GetSteamID(uint32 playerId);
void scripting_Player_Drop(uint32 playerId, ENetworkDisconnectionReason reason);
bool scripting_Player_IsAuthenticated(uint32 playerId);
const char *scripting_Player_GetConvar(uint32 playerId, const char *name);
void scripting_Player_SendMessage(uint32 playerId, int dest, const char *text);
uint8 scripting_Player_GetTeam(uint32 playerId);
void scripting_Player_SetTeam(uint32 playerId, int team);
int scripting_Player_GetHealth(uint32 playerId);
void scripting_Player_SetHealth(uint32 playerId, int health);
void scripting_Player_TakeHealth(uint32 playerId, int health);
void scripting_Player_Kill(uint32 playerId);
void scripting_Players_SendMessage(int dest, const char *text);
int scripting_Player_GetArmor(uint32 playerId);
void scripting_Player_SetArmor(uint32 playerId, int armor);
void scripting_Player_TakeArmor(uint32 playerId, int armor);
const char *scripting_Player_GetClanTag(uint32 playerId);
void scripting_Player_SetClanTag(uint32 playerId, const char *tag);
void scripting_Player_SetVar(uint32 playerId, const char *name, int type, ...);
const char *scripting_Player_GetVar(uint32 playerId, const char *name);
uint32 scripting_Player_GetConnectedTime(uint32 playerId);
int scripting_Player_FetchMatchStat(uint32 playerId, PlayerStat stat);
void scripting_Player_SetMatchStat(uint32 playerId, PlayerStat stat, int value);
const char *scripting_Player_GetIPAddress(uint32 playerId);
const char *scripting_Player_GetCoords(uint32 playerId);
void scripting_Player_SetCoords(uint32 playerId, float x, float y, float z);
int scripting_Player_GetMoney(uint32 playerId);
void scripting_Player_SetMoney(uint32 playerId, int money);
void scripting_Player_TakeMoney(uint32 playerId, int money);

void scripting_Precacher_AddModel(const char *model);

void scripting_Server_ExecuteCommand(const char *str);
uint16 scripting_Server_GetMaxPlayers();
const char *scripting_Server_GetMapName();
bool scripting_Server_IsMapValid(const char *map);

const char *scripting_Translations_Fetch(const char *key);

void scripting_Print(const char *str);

void SetupLuaEnvironment(Plugin *plugin);

template <typename T, typename... Args>
void CallCPPFunctionNoReturn(std::string function, Args... args);
template <typename... Args>
void CallLuaFunctionNoReturn(std::string function, Args... args);

enum PlayerStat : int
{
    KILLS = 0,
    DEATHS = 1,
    ASSISTS = 2,
    DAMAGE = 3
};

#endif