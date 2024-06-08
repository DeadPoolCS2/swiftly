#include "../../../core/scripting/generated/classes/GCFuncTrackTrain.h"
#include "../core.h"

void SetupLuaClassGCFuncTrackTrain(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFuncTrackTrain>("CFuncTrackTrain")
        .addProperty("Ppath", &GCFuncTrackTrain::GetPpath, &GCFuncTrackTrain::SetPpath)
        .addProperty("Length", &GCFuncTrackTrain::GetLength, &GCFuncTrackTrain::SetLength)
        .addProperty("PosPrev", &GCFuncTrackTrain::GetPosPrev, &GCFuncTrackTrain::SetPosPrev)
        .addProperty("Prev", &GCFuncTrackTrain::GetPrev, &GCFuncTrackTrain::SetPrev)
        .addProperty("ControlMins", &GCFuncTrackTrain::GetControlMins, &GCFuncTrackTrain::SetControlMins)
        .addProperty("ControlMaxs", &GCFuncTrackTrain::GetControlMaxs, &GCFuncTrackTrain::SetControlMaxs)
        .addProperty("LastBlockPos", &GCFuncTrackTrain::GetLastBlockPos, &GCFuncTrackTrain::SetLastBlockPos)
        .addProperty("LastBlockTick", &GCFuncTrackTrain::GetLastBlockTick, &GCFuncTrackTrain::SetLastBlockTick)
        .addProperty("Volume", &GCFuncTrackTrain::GetVolume, &GCFuncTrackTrain::SetVolume)
        .addProperty("Bank", &GCFuncTrackTrain::GetBank, &GCFuncTrackTrain::SetBank)
        .addProperty("OldSpeed", &GCFuncTrackTrain::GetOldSpeed, &GCFuncTrackTrain::SetOldSpeed)
        .addProperty("BlockDamage", &GCFuncTrackTrain::GetBlockDamage, &GCFuncTrackTrain::SetBlockDamage)
        .addProperty("Height", &GCFuncTrackTrain::GetHeight, &GCFuncTrackTrain::SetHeight)
        .addProperty("MaxSpeed", &GCFuncTrackTrain::GetMaxSpeed, &GCFuncTrackTrain::SetMaxSpeed)
        .addProperty("Dir", &GCFuncTrackTrain::GetDir, &GCFuncTrackTrain::SetDir)
        .addProperty("SoundMove", &GCFuncTrackTrain::GetSoundMove, &GCFuncTrackTrain::SetSoundMove)
        .addProperty("SoundMovePing", &GCFuncTrackTrain::GetSoundMovePing, &GCFuncTrackTrain::SetSoundMovePing)
        .addProperty("SoundStart", &GCFuncTrackTrain::GetSoundStart, &GCFuncTrackTrain::SetSoundStart)
        .addProperty("SoundStop", &GCFuncTrackTrain::GetSoundStop, &GCFuncTrackTrain::SetSoundStop)
        .addProperty("StrPathTarget", &GCFuncTrackTrain::GetStrPathTarget, &GCFuncTrackTrain::SetStrPathTarget)
        .addProperty("MoveSoundMinDuration", &GCFuncTrackTrain::GetMoveSoundMinDuration, &GCFuncTrackTrain::SetMoveSoundMinDuration)
        .addProperty("MoveSoundMaxDuration", &GCFuncTrackTrain::GetMoveSoundMaxDuration, &GCFuncTrackTrain::SetMoveSoundMaxDuration)
        .addProperty("MoveSoundMinPitch", &GCFuncTrackTrain::GetMoveSoundMinPitch, &GCFuncTrackTrain::SetMoveSoundMinPitch)
        .addProperty("MoveSoundMaxPitch", &GCFuncTrackTrain::GetMoveSoundMaxPitch, &GCFuncTrackTrain::SetMoveSoundMaxPitch)
        .addProperty("OrientationType", &GCFuncTrackTrain::GetOrientationType, &GCFuncTrackTrain::SetOrientationType)
        .addProperty("VelocityType", &GCFuncTrackTrain::GetVelocityType, &GCFuncTrackTrain::SetVelocityType)
        .addProperty("OnStart", &GCFuncTrackTrain::GetOnStart, &GCFuncTrackTrain::SetOnStart)
        .addProperty("OnNext", &GCFuncTrackTrain::GetOnNext, &GCFuncTrackTrain::SetOnNext)
        .addProperty("OnArrivedAtDestinationNode", &GCFuncTrackTrain::GetOnArrivedAtDestinationNode, &GCFuncTrackTrain::SetOnArrivedAtDestinationNode)
        .addProperty("ManualSpeedChanges", &GCFuncTrackTrain::GetManualSpeedChanges, &GCFuncTrackTrain::SetManualSpeedChanges)
        .addProperty("DesiredSpeed", &GCFuncTrackTrain::GetDesiredSpeed, &GCFuncTrackTrain::SetDesiredSpeed)
        .addProperty("AccelSpeed", &GCFuncTrackTrain::GetAccelSpeed, &GCFuncTrackTrain::SetAccelSpeed)
        .addProperty("DecelSpeed", &GCFuncTrackTrain::GetDecelSpeed, &GCFuncTrackTrain::SetDecelSpeed)
        .addProperty("AccelToSpeed", &GCFuncTrackTrain::GetAccelToSpeed, &GCFuncTrackTrain::SetAccelToSpeed)
        .endClass();
}