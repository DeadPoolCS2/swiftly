#include "../../../core/scripting/generated/classes/GCHostage.h"
#include "../core.h"

void SetupLuaClassGCHostage(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCHostage>("CHostage")
        .addProperty("OnHostageBeginGrab", &GCHostage::GetOnHostageBeginGrab, &GCHostage::SetOnHostageBeginGrab)
        .addProperty("OnFirstPickedUp", &GCHostage::GetOnFirstPickedUp, &GCHostage::SetOnFirstPickedUp)
        .addProperty("OnDroppedNotRescued", &GCHostage::GetOnDroppedNotRescued, &GCHostage::SetOnDroppedNotRescued)
        .addProperty("OnRescued", &GCHostage::GetOnRescued, &GCHostage::SetOnRescued)
        .addProperty("EntitySpottedState", &GCHostage::GetEntitySpottedState, &GCHostage::SetEntitySpottedState)
        .addProperty("SpotRules", &GCHostage::GetSpotRules, &GCHostage::SetSpotRules)
        .addProperty("UiHostageSpawnExclusionGroupMask", &GCHostage::GetUiHostageSpawnExclusionGroupMask, &GCHostage::SetUiHostageSpawnExclusionGroupMask)
        .addProperty("HostageSpawnRandomFactor", &GCHostage::GetHostageSpawnRandomFactor, &GCHostage::SetHostageSpawnRandomFactor)
        .addProperty("Remove", &GCHostage::GetRemove, &GCHostage::SetRemove)
        .addProperty("Vel", &GCHostage::GetVel, &GCHostage::SetVel)
        .addProperty("IsRescued", &GCHostage::GetIsRescued, &GCHostage::SetIsRescued)
        .addProperty("JumpedThisFrame", &GCHostage::GetJumpedThisFrame, &GCHostage::SetJumpedThisFrame)
        .addProperty("HostageState", &GCHostage::GetHostageState, &GCHostage::SetHostageState)
        .addProperty("Leader", &GCHostage::GetLeader, &GCHostage::SetLeader)
        .addProperty("LastLeader", &GCHostage::GetLastLeader, &GCHostage::SetLastLeader)
        .addProperty("ReuseTimer", &GCHostage::GetReuseTimer, &GCHostage::SetReuseTimer)
        .addProperty("HasBeenUsed", &GCHostage::GetHasBeenUsed, &GCHostage::SetHasBeenUsed)
        .addProperty("Accel", &GCHostage::GetAccel, &GCHostage::SetAccel)
        .addProperty("IsRunning", &GCHostage::GetIsRunning, &GCHostage::SetIsRunning)
        .addProperty("IsCrouching", &GCHostage::GetIsCrouching, &GCHostage::SetIsCrouching)
        .addProperty("JumpTimer", &GCHostage::GetJumpTimer, &GCHostage::SetJumpTimer)
        .addProperty("IsWaitingForLeader", &GCHostage::GetIsWaitingForLeader, &GCHostage::SetIsWaitingForLeader)
        .addProperty("RepathTimer", &GCHostage::GetRepathTimer, &GCHostage::SetRepathTimer)
        .addProperty("InhibitDoorTimer", &GCHostage::GetInhibitDoorTimer, &GCHostage::SetInhibitDoorTimer)
        .addProperty("InhibitObstacleAvoidanceTimer", &GCHostage::GetInhibitObstacleAvoidanceTimer, &GCHostage::SetInhibitObstacleAvoidanceTimer)
        .addProperty("WiggleTimer", &GCHostage::GetWiggleTimer, &GCHostage::SetWiggleTimer)
        .addProperty("IsAdjusted", &GCHostage::GetIsAdjusted, &GCHostage::SetIsAdjusted)
        .addProperty("HandsHaveBeenCut", &GCHostage::GetHandsHaveBeenCut, &GCHostage::SetHandsHaveBeenCut)
        .addProperty("HostageGrabber", &GCHostage::GetHostageGrabber, &GCHostage::SetHostageGrabber)
        .addProperty("PositionWhenStartedDroppingToGround", &GCHostage::GetPositionWhenStartedDroppingToGround, &GCHostage::SetPositionWhenStartedDroppingToGround)
        .addProperty("GrabbedPos", &GCHostage::GetGrabbedPos, &GCHostage::SetGrabbedPos)
        .addProperty("ApproachRewardPayouts", &GCHostage::GetApproachRewardPayouts, &GCHostage::SetApproachRewardPayouts)
        .addProperty("PickupEventCount", &GCHostage::GetPickupEventCount, &GCHostage::SetPickupEventCount)
        .addProperty("SpawnGroundPos", &GCHostage::GetSpawnGroundPos, &GCHostage::SetSpawnGroundPos)
        .addProperty("HostageResetPosition", &GCHostage::GetHostageResetPosition, &GCHostage::SetHostageResetPosition)
        .endClass();
}