#include "../../../core/scripting/generated/classes/GCCSPlayerController.h"
#include "../core.h"

void SetupLuaClassGCCSPlayerController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCCSPlayerController>("CCSPlayerController")
        .addProperty("InGameMoneyServices", &GCCSPlayerController::GetInGameMoneyServices, &GCCSPlayerController::SetInGameMoneyServices)
        .addProperty("InventoryServices", &GCCSPlayerController::GetInventoryServices, &GCCSPlayerController::SetInventoryServices)
        .addProperty("ActionTrackingServices", &GCCSPlayerController::GetActionTrackingServices, &GCCSPlayerController::SetActionTrackingServices)
        .addProperty("DamageServices", &GCCSPlayerController::GetDamageServices, &GCCSPlayerController::SetDamageServices)
        .addProperty("Ping", &GCCSPlayerController::GetPing, &GCCSPlayerController::SetPing)
        .addProperty("HasCommunicationAbuseMute", &GCCSPlayerController::GetHasCommunicationAbuseMute, &GCCSPlayerController::SetHasCommunicationAbuseMute)
        .addProperty("CrosshairCodes", &GCCSPlayerController::GetCrosshairCodes, &GCCSPlayerController::SetCrosshairCodes)
        .addProperty("PendingTeamNum", &GCCSPlayerController::GetPendingTeamNum, &GCCSPlayerController::SetPendingTeamNum)
        .addProperty("CompTeammateColor", &GCCSPlayerController::GetCompTeammateColor, &GCCSPlayerController::SetCompTeammateColor)
        .addProperty("EverPlayedOnTeam", &GCCSPlayerController::GetEverPlayedOnTeam, &GCCSPlayerController::SetEverPlayedOnTeam)
        .addProperty("AttemptedToGetColor", &GCCSPlayerController::GetAttemptedToGetColor, &GCCSPlayerController::SetAttemptedToGetColor)
        .addProperty("TeammatePreferredColor", &GCCSPlayerController::GetTeammatePreferredColor, &GCCSPlayerController::SetTeammatePreferredColor)
        .addProperty("TeamChanged", &GCCSPlayerController::GetTeamChanged, &GCCSPlayerController::SetTeamChanged)
        .addProperty("InSwitchTeam", &GCCSPlayerController::GetInSwitchTeam, &GCCSPlayerController::SetInSwitchTeam)
        .addProperty("HasSeenJoinGame", &GCCSPlayerController::GetHasSeenJoinGame, &GCCSPlayerController::SetHasSeenJoinGame)
        .addProperty("JustBecameSpectator", &GCCSPlayerController::GetJustBecameSpectator, &GCCSPlayerController::SetJustBecameSpectator)
        .addProperty("SwitchTeamsOnNextRoundReset", &GCCSPlayerController::GetSwitchTeamsOnNextRoundReset, &GCCSPlayerController::SetSwitchTeamsOnNextRoundReset)
        .addProperty("RemoveAllItemsOnNextRoundReset", &GCCSPlayerController::GetRemoveAllItemsOnNextRoundReset, &GCCSPlayerController::SetRemoveAllItemsOnNextRoundReset)
        .addProperty("Clan", &GCCSPlayerController::GetClan, &GCCSPlayerController::SetClan)
        .addProperty("ClanName", &GCCSPlayerController::GetClanName, &GCCSPlayerController::SetClanName)
        .addProperty("CoachingTeam", &GCCSPlayerController::GetCoachingTeam, &GCCSPlayerController::SetCoachingTeam)
        .addProperty("PlayerDominated", &GCCSPlayerController::GetPlayerDominated, &GCCSPlayerController::SetPlayerDominated)
        .addProperty("PlayerDominatingMe", &GCCSPlayerController::GetPlayerDominatingMe, &GCCSPlayerController::SetPlayerDominatingMe)
        .addProperty("CompetitiveRanking", &GCCSPlayerController::GetCompetitiveRanking, &GCCSPlayerController::SetCompetitiveRanking)
        .addProperty("CompetitiveWins", &GCCSPlayerController::GetCompetitiveWins, &GCCSPlayerController::SetCompetitiveWins)
        .addProperty("CompetitiveRankType", &GCCSPlayerController::GetCompetitiveRankType, &GCCSPlayerController::SetCompetitiveRankType)
        .addProperty("CompetitiveRankingPredicted_Win", &GCCSPlayerController::GetCompetitiveRankingPredicted_Win, &GCCSPlayerController::SetCompetitiveRankingPredicted_Win)
        .addProperty("CompetitiveRankingPredicted_Loss", &GCCSPlayerController::GetCompetitiveRankingPredicted_Loss, &GCCSPlayerController::SetCompetitiveRankingPredicted_Loss)
        .addProperty("CompetitiveRankingPredicted_Tie", &GCCSPlayerController::GetCompetitiveRankingPredicted_Tie, &GCCSPlayerController::SetCompetitiveRankingPredicted_Tie)
        .addProperty("EndMatchNextMapVote", &GCCSPlayerController::GetEndMatchNextMapVote, &GCCSPlayerController::SetEndMatchNextMapVote)
        .addProperty("ActiveQuestId", &GCCSPlayerController::GetActiveQuestId, &GCCSPlayerController::SetActiveQuestId)
        .addProperty("QuestProgressReason", &GCCSPlayerController::GetQuestProgressReason, &GCCSPlayerController::SetQuestProgressReason)
        .addProperty("PlayerTvControlFlags", &GCCSPlayerController::GetPlayerTvControlFlags, &GCCSPlayerController::SetPlayerTvControlFlags)
        .addProperty("DraftIndex", &GCCSPlayerController::GetDraftIndex, &GCCSPlayerController::SetDraftIndex)
        .addProperty("MsQueuedModeDisconnectionTimestamp", &GCCSPlayerController::GetMsQueuedModeDisconnectionTimestamp, &GCCSPlayerController::SetMsQueuedModeDisconnectionTimestamp)
        .addProperty("UiAbandonRecordedReason", &GCCSPlayerController::GetUiAbandonRecordedReason, &GCCSPlayerController::SetUiAbandonRecordedReason)
        .addProperty("CannotBeKicked", &GCCSPlayerController::GetCannotBeKicked, &GCCSPlayerController::SetCannotBeKicked)
        .addProperty("EverFullyConnected", &GCCSPlayerController::GetEverFullyConnected, &GCCSPlayerController::SetEverFullyConnected)
        .addProperty("AbandonAllowsSurrender", &GCCSPlayerController::GetAbandonAllowsSurrender, &GCCSPlayerController::SetAbandonAllowsSurrender)
        .addProperty("AbandonOffersInstantSurrender", &GCCSPlayerController::GetAbandonOffersInstantSurrender, &GCCSPlayerController::SetAbandonOffersInstantSurrender)
        .addProperty("Disconnection1MinWarningPrinted", &GCCSPlayerController::GetDisconnection1MinWarningPrinted, &GCCSPlayerController::SetDisconnection1MinWarningPrinted)
        .addProperty("ScoreReported", &GCCSPlayerController::GetScoreReported, &GCCSPlayerController::SetScoreReported)
        .addProperty("DisconnectionTick", &GCCSPlayerController::GetDisconnectionTick, &GCCSPlayerController::SetDisconnectionTick)
        .addProperty("ControllingBot", &GCCSPlayerController::GetControllingBot, &GCCSPlayerController::SetControllingBot)
        .addProperty("HasControlledBotThisRound", &GCCSPlayerController::GetHasControlledBotThisRound, &GCCSPlayerController::SetHasControlledBotThisRound)
        .addProperty("HasBeenControlledByPlayerThisRound", &GCCSPlayerController::GetHasBeenControlledByPlayerThisRound, &GCCSPlayerController::SetHasBeenControlledByPlayerThisRound)
        .addProperty("BotsControlledThisRound", &GCCSPlayerController::GetBotsControlledThisRound, &GCCSPlayerController::SetBotsControlledThisRound)
        .addProperty("CanControlObservedBot", &GCCSPlayerController::GetCanControlObservedBot, &GCCSPlayerController::SetCanControlObservedBot)
        .addProperty("PlayerPawn", &GCCSPlayerController::GetPlayerPawn, &GCCSPlayerController::SetPlayerPawn)
        .addProperty("ObserverPawn", &GCCSPlayerController::GetObserverPawn, &GCCSPlayerController::SetObserverPawn)
        .addProperty("DesiredObserverMode", &GCCSPlayerController::GetDesiredObserverMode, &GCCSPlayerController::SetDesiredObserverMode)
        .addProperty("DesiredObserverTarget", &GCCSPlayerController::GetDesiredObserverTarget, &GCCSPlayerController::SetDesiredObserverTarget)
        .addProperty("PawnIsAlive", &GCCSPlayerController::GetPawnIsAlive, &GCCSPlayerController::SetPawnIsAlive)
        .addProperty("PawnHealth", &GCCSPlayerController::GetPawnHealth, &GCCSPlayerController::SetPawnHealth)
        .addProperty("PawnArmor", &GCCSPlayerController::GetPawnArmor, &GCCSPlayerController::SetPawnArmor)
        .addProperty("PawnHasDefuser", &GCCSPlayerController::GetPawnHasDefuser, &GCCSPlayerController::SetPawnHasDefuser)
        .addProperty("PawnHasHelmet", &GCCSPlayerController::GetPawnHasHelmet, &GCCSPlayerController::SetPawnHasHelmet)
        .addProperty("PawnCharacterDefIndex", &GCCSPlayerController::GetPawnCharacterDefIndex, &GCCSPlayerController::SetPawnCharacterDefIndex)
        .addProperty("PawnLifetimeStart", &GCCSPlayerController::GetPawnLifetimeStart, &GCCSPlayerController::SetPawnLifetimeStart)
        .addProperty("PawnLifetimeEnd", &GCCSPlayerController::GetPawnLifetimeEnd, &GCCSPlayerController::SetPawnLifetimeEnd)
        .addProperty("PawnBotDifficulty", &GCCSPlayerController::GetPawnBotDifficulty, &GCCSPlayerController::SetPawnBotDifficulty)
        .addProperty("OriginalControllerOfCurrentPawn", &GCCSPlayerController::GetOriginalControllerOfCurrentPawn, &GCCSPlayerController::SetOriginalControllerOfCurrentPawn)
        .addProperty("Score", &GCCSPlayerController::GetScore, &GCCSPlayerController::SetScore)
        .addProperty("RoundScore", &GCCSPlayerController::GetRoundScore, &GCCSPlayerController::SetRoundScore)
        .addProperty("RoundsWon", &GCCSPlayerController::GetRoundsWon, &GCCSPlayerController::SetRoundsWon)
        .addProperty("Kills", &GCCSPlayerController::GetKills, &GCCSPlayerController::SetKills)
        .addProperty("MvpNoMusic", &GCCSPlayerController::GetMvpNoMusic, &GCCSPlayerController::SetMvpNoMusic)
        .addProperty("MvpReason", &GCCSPlayerController::GetMvpReason, &GCCSPlayerController::SetMvpReason)
        .addProperty("MusicKitID", &GCCSPlayerController::GetMusicKitID, &GCCSPlayerController::SetMusicKitID)
        .addProperty("MusicKitMVPs", &GCCSPlayerController::GetMusicKitMVPs, &GCCSPlayerController::SetMusicKitMVPs)
        .addProperty("MVPs", &GCCSPlayerController::GetMVPs, &GCCSPlayerController::SetMVPs)
        .addProperty("UpdateCounter", &GCCSPlayerController::GetUpdateCounter, &GCCSPlayerController::SetUpdateCounter)
        .addProperty("SmoothedPing", &GCCSPlayerController::GetSmoothedPing, &GCCSPlayerController::SetSmoothedPing)
        .addProperty("LastHeldVoteTimer", &GCCSPlayerController::GetLastHeldVoteTimer, &GCCSPlayerController::SetLastHeldVoteTimer)
        .addProperty("ShowHints", &GCCSPlayerController::GetShowHints, &GCCSPlayerController::SetShowHints)
        .addProperty("NextTimeCheck", &GCCSPlayerController::GetNextTimeCheck, &GCCSPlayerController::SetNextTimeCheck)
        .addProperty("JustDidTeamKill", &GCCSPlayerController::GetJustDidTeamKill, &GCCSPlayerController::SetJustDidTeamKill)
        .addProperty("PunishForTeamKill", &GCCSPlayerController::GetPunishForTeamKill, &GCCSPlayerController::SetPunishForTeamKill)
        .addProperty("GaveTeamDamageWarning", &GCCSPlayerController::GetGaveTeamDamageWarning, &GCCSPlayerController::SetGaveTeamDamageWarning)
        .addProperty("GaveTeamDamageWarningThisRound", &GCCSPlayerController::GetGaveTeamDamageWarningThisRound, &GCCSPlayerController::SetGaveTeamDamageWarningThisRound)
        .addProperty("DblLastReceivedPacketPlatFloatTime", &GCCSPlayerController::GetDblLastReceivedPacketPlatFloatTime, &GCCSPlayerController::SetDblLastReceivedPacketPlatFloatTime)
        .addProperty("SuspiciousHitCount", &GCCSPlayerController::GetSuspiciousHitCount, &GCCSPlayerController::SetSuspiciousHitCount)
        .addProperty("NonSuspiciousHitStreak", &GCCSPlayerController::GetNonSuspiciousHitStreak, &GCCSPlayerController::SetNonSuspiciousHitStreak)
        .endClass();
}