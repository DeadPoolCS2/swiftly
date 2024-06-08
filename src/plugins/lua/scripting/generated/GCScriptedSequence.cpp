#include "../../../core/scripting/generated/classes/GCScriptedSequence.h"
#include "../core.h"

void SetupLuaClassGCScriptedSequence(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCScriptedSequence>("CScriptedSequence")
        .addProperty("Entry", &GCScriptedSequence::GetEntry, &GCScriptedSequence::SetEntry)
        .addProperty("PreIdle", &GCScriptedSequence::GetPreIdle, &GCScriptedSequence::SetPreIdle)
        .addProperty("Play", &GCScriptedSequence::GetPlay, &GCScriptedSequence::SetPlay)
        .addProperty("PostIdle", &GCScriptedSequence::GetPostIdle, &GCScriptedSequence::SetPostIdle)
        .addProperty("ModifierToAddOnPlay", &GCScriptedSequence::GetModifierToAddOnPlay, &GCScriptedSequence::SetModifierToAddOnPlay)
        .addProperty("NextScript", &GCScriptedSequence::GetNextScript, &GCScriptedSequence::SetNextScript)
        .addProperty("Entity", &GCScriptedSequence::GetEntity, &GCScriptedSequence::SetEntity)
        .addProperty("SyncGroup", &GCScriptedSequence::GetSyncGroup, &GCScriptedSequence::SetSyncGroup)
        .addProperty("MoveTo", &GCScriptedSequence::GetMoveTo, &GCScriptedSequence::SetMoveTo)
        .addProperty("MoveToGait", &GCScriptedSequence::GetMoveToGait, &GCScriptedSequence::SetMoveToGait)
        .addProperty("IsPlayingPreIdle", &GCScriptedSequence::GetIsPlayingPreIdle, &GCScriptedSequence::SetIsPlayingPreIdle)
        .addProperty("IsPlayingEntry", &GCScriptedSequence::GetIsPlayingEntry, &GCScriptedSequence::SetIsPlayingEntry)
        .addProperty("IsPlayingAction", &GCScriptedSequence::GetIsPlayingAction, &GCScriptedSequence::SetIsPlayingAction)
        .addProperty("IsPlayingPostIdle", &GCScriptedSequence::GetIsPlayingPostIdle, &GCScriptedSequence::SetIsPlayingPostIdle)
        .addProperty("DontRotateOther", &GCScriptedSequence::GetDontRotateOther, &GCScriptedSequence::SetDontRotateOther)
        .addProperty("IsRepeatable", &GCScriptedSequence::GetIsRepeatable, &GCScriptedSequence::SetIsRepeatable)
        .addProperty("ShouldLeaveCorpse", &GCScriptedSequence::GetShouldLeaveCorpse, &GCScriptedSequence::SetShouldLeaveCorpse)
        .addProperty("StartOnSpawn", &GCScriptedSequence::GetStartOnSpawn, &GCScriptedSequence::SetStartOnSpawn)
        .addProperty("DisallowInterrupts", &GCScriptedSequence::GetDisallowInterrupts, &GCScriptedSequence::SetDisallowInterrupts)
        .addProperty("CanOverrideNPCState", &GCScriptedSequence::GetCanOverrideNPCState, &GCScriptedSequence::SetCanOverrideNPCState)
        .addProperty("DontTeleportAtEnd", &GCScriptedSequence::GetDontTeleportAtEnd, &GCScriptedSequence::SetDontTeleportAtEnd)
        .addProperty("HighPriority", &GCScriptedSequence::GetHighPriority, &GCScriptedSequence::SetHighPriority)
        .addProperty("HideDebugComplaints", &GCScriptedSequence::GetHideDebugComplaints, &GCScriptedSequence::SetHideDebugComplaints)
        .addProperty("ContinueOnDeath", &GCScriptedSequence::GetContinueOnDeath, &GCScriptedSequence::SetContinueOnDeath)
        .addProperty("LoopPreIdleSequence", &GCScriptedSequence::GetLoopPreIdleSequence, &GCScriptedSequence::SetLoopPreIdleSequence)
        .addProperty("LoopActionSequence", &GCScriptedSequence::GetLoopActionSequence, &GCScriptedSequence::SetLoopActionSequence)
        .addProperty("LoopPostIdleSequence", &GCScriptedSequence::GetLoopPostIdleSequence, &GCScriptedSequence::SetLoopPostIdleSequence)
        .addProperty("SynchPostIdles", &GCScriptedSequence::GetSynchPostIdles, &GCScriptedSequence::SetSynchPostIdles)
        .addProperty("IgnoreLookAt", &GCScriptedSequence::GetIgnoreLookAt, &GCScriptedSequence::SetIgnoreLookAt)
        .addProperty("IgnoreGravity", &GCScriptedSequence::GetIgnoreGravity, &GCScriptedSequence::SetIgnoreGravity)
        .addProperty("DisableNPCCollisions", &GCScriptedSequence::GetDisableNPCCollisions, &GCScriptedSequence::SetDisableNPCCollisions)
        .addProperty("KeepAnimgraphLockedPost", &GCScriptedSequence::GetKeepAnimgraphLockedPost, &GCScriptedSequence::SetKeepAnimgraphLockedPost)
        .addProperty("DontAddModifiers", &GCScriptedSequence::GetDontAddModifiers, &GCScriptedSequence::SetDontAddModifiers)
        .addProperty("Radius", &GCScriptedSequence::GetRadius, &GCScriptedSequence::SetRadius)
        .addProperty("Repeat", &GCScriptedSequence::GetRepeat, &GCScriptedSequence::SetRepeat)
        .addProperty("PlayAnimFadeInTime", &GCScriptedSequence::GetPlayAnimFadeInTime, &GCScriptedSequence::SetPlayAnimFadeInTime)
        .addProperty("MoveInterpTime", &GCScriptedSequence::GetMoveInterpTime, &GCScriptedSequence::SetMoveInterpTime)
        .addProperty("AngRate", &GCScriptedSequence::GetAngRate, &GCScriptedSequence::SetAngRate)
        .addProperty("NotReadySequenceCount", &GCScriptedSequence::GetNotReadySequenceCount, &GCScriptedSequence::SetNotReadySequenceCount)
        .addProperty("WaitForBeginSequence", &GCScriptedSequence::GetWaitForBeginSequence, &GCScriptedSequence::SetWaitForBeginSequence)
        .addProperty("Saved_effects", &GCScriptedSequence::GetSaved_effects, &GCScriptedSequence::SetSaved_effects)
        .addProperty("SavedFlags", &GCScriptedSequence::GetSavedFlags, &GCScriptedSequence::SetSavedFlags)
        .addProperty("SavedCollisionGroup", &GCScriptedSequence::GetSavedCollisionGroup, &GCScriptedSequence::SetSavedCollisionGroup)
        .addProperty("Interruptable", &GCScriptedSequence::GetInterruptable, &GCScriptedSequence::SetInterruptable)
        .addProperty("SequenceStarted", &GCScriptedSequence::GetSequenceStarted, &GCScriptedSequence::SetSequenceStarted)
        .addProperty("PositionRelativeToOtherEntity", &GCScriptedSequence::GetPositionRelativeToOtherEntity, &GCScriptedSequence::SetPositionRelativeToOtherEntity)
        .addProperty("TargetEnt", &GCScriptedSequence::GetTargetEnt, &GCScriptedSequence::SetTargetEnt)
        .addProperty("NextCine", &GCScriptedSequence::GetNextCine, &GCScriptedSequence::SetNextCine)
        .addProperty("Thinking", &GCScriptedSequence::GetThinking, &GCScriptedSequence::SetThinking)
        .addProperty("InitiatedSelfDelete", &GCScriptedSequence::GetInitiatedSelfDelete, &GCScriptedSequence::SetInitiatedSelfDelete)
        .addProperty("IsTeleportingDueToMoveTo", &GCScriptedSequence::GetIsTeleportingDueToMoveTo, &GCScriptedSequence::SetIsTeleportingDueToMoveTo)
        .addProperty("AllowCustomInterruptConditions", &GCScriptedSequence::GetAllowCustomInterruptConditions, &GCScriptedSequence::SetAllowCustomInterruptConditions)
        .addProperty("ForcedTarget", &GCScriptedSequence::GetForcedTarget, &GCScriptedSequence::SetForcedTarget)
        .addProperty("DontCancelOtherSequences", &GCScriptedSequence::GetDontCancelOtherSequences, &GCScriptedSequence::SetDontCancelOtherSequences)
        .addProperty("ForceSynch", &GCScriptedSequence::GetForceSynch, &GCScriptedSequence::SetForceSynch)
        .addProperty("PreventUpdateYawOnFinish", &GCScriptedSequence::GetPreventUpdateYawOnFinish, &GCScriptedSequence::SetPreventUpdateYawOnFinish)
        .addProperty("EnsureOnNavmeshOnFinish", &GCScriptedSequence::GetEnsureOnNavmeshOnFinish, &GCScriptedSequence::SetEnsureOnNavmeshOnFinish)
        .addProperty("OnDeathBehavior", &GCScriptedSequence::GetOnDeathBehavior, &GCScriptedSequence::SetOnDeathBehavior)
        .addProperty("ConflictResponse", &GCScriptedSequence::GetConflictResponse, &GCScriptedSequence::SetConflictResponse)
        .addProperty("OnBeginSequence", &GCScriptedSequence::GetOnBeginSequence, &GCScriptedSequence::SetOnBeginSequence)
        .addProperty("OnActionStartOrLoop", &GCScriptedSequence::GetOnActionStartOrLoop, &GCScriptedSequence::SetOnActionStartOrLoop)
        .addProperty("OnEndSequence", &GCScriptedSequence::GetOnEndSequence, &GCScriptedSequence::SetOnEndSequence)
        .addProperty("OnPostIdleEndSequence", &GCScriptedSequence::GetOnPostIdleEndSequence, &GCScriptedSequence::SetOnPostIdleEndSequence)
        .addProperty("OnCancelSequence", &GCScriptedSequence::GetOnCancelSequence, &GCScriptedSequence::SetOnCancelSequence)
        .addProperty("OnCancelFailedSequence", &GCScriptedSequence::GetOnCancelFailedSequence, &GCScriptedSequence::SetOnCancelFailedSequence)
        .addProperty("OnScriptEvent", &GCScriptedSequence::GetOnScriptEvent, &GCScriptedSequence::SetOnScriptEvent)
        .addProperty("InteractionMainEntity", &GCScriptedSequence::GetInteractionMainEntity, &GCScriptedSequence::SetInteractionMainEntity)
        .addProperty("PlayerDeathBehavior", &GCScriptedSequence::GetPlayerDeathBehavior, &GCScriptedSequence::SetPlayerDeathBehavior)
        .endClass();
}