#include "../../../core/scripting/generated/classes/GC_OP_WorldTraceConstraint.h"
#include "../core.h"

void SetupLuaClassGC_OP_WorldTraceConstraint(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_WorldTraceConstraint>("C_OP_WorldTraceConstraint")
        .addProperty("CP", &GC_OP_WorldTraceConstraint::GetCP, &GC_OP_WorldTraceConstraint::SetCP)
        .addProperty("CpOffset", &GC_OP_WorldTraceConstraint::GetCpOffset, &GC_OP_WorldTraceConstraint::SetCpOffset)
        .addProperty("CollisionMode", &GC_OP_WorldTraceConstraint::GetCollisionMode, &GC_OP_WorldTraceConstraint::SetCollisionMode)
        .addProperty("CollisionModeMin", &GC_OP_WorldTraceConstraint::GetCollisionModeMin, &GC_OP_WorldTraceConstraint::SetCollisionModeMin)
        .addProperty("TraceSet", &GC_OP_WorldTraceConstraint::GetTraceSet, &GC_OP_WorldTraceConstraint::SetTraceSet)
        .addProperty("CollisionGroupName", &GC_OP_WorldTraceConstraint::GetCollisionGroupName, &GC_OP_WorldTraceConstraint::SetCollisionGroupName)
        .addProperty("WorldOnly", &GC_OP_WorldTraceConstraint::GetWorldOnly, &GC_OP_WorldTraceConstraint::SetWorldOnly)
        .addProperty("BrushOnly", &GC_OP_WorldTraceConstraint::GetBrushOnly, &GC_OP_WorldTraceConstraint::SetBrushOnly)
        .addProperty("IncludeWater", &GC_OP_WorldTraceConstraint::GetIncludeWater, &GC_OP_WorldTraceConstraint::SetIncludeWater)
        .addProperty("IgnoreCP", &GC_OP_WorldTraceConstraint::GetIgnoreCP, &GC_OP_WorldTraceConstraint::SetIgnoreCP)
        .addProperty("CpMovementTolerance", &GC_OP_WorldTraceConstraint::GetCpMovementTolerance, &GC_OP_WorldTraceConstraint::SetCpMovementTolerance)
        .addProperty("RetestRate", &GC_OP_WorldTraceConstraint::GetRetestRate, &GC_OP_WorldTraceConstraint::SetRetestRate)
        .addProperty("TraceTolerance", &GC_OP_WorldTraceConstraint::GetTraceTolerance, &GC_OP_WorldTraceConstraint::SetTraceTolerance)
        .addProperty("CollisionConfirmationSpeed", &GC_OP_WorldTraceConstraint::GetCollisionConfirmationSpeed, &GC_OP_WorldTraceConstraint::SetCollisionConfirmationSpeed)
        .addProperty("MaxTracesPerFrame", &GC_OP_WorldTraceConstraint::GetMaxTracesPerFrame, &GC_OP_WorldTraceConstraint::SetMaxTracesPerFrame)
        .addProperty("RadiusScale", &GC_OP_WorldTraceConstraint::GetRadiusScale, &GC_OP_WorldTraceConstraint::SetRadiusScale)
        .addProperty("BounceAmount", &GC_OP_WorldTraceConstraint::GetBounceAmount, &GC_OP_WorldTraceConstraint::SetBounceAmount)
        .addProperty("SlideAmount", &GC_OP_WorldTraceConstraint::GetSlideAmount, &GC_OP_WorldTraceConstraint::SetSlideAmount)
        .addProperty("RandomDirScale", &GC_OP_WorldTraceConstraint::GetRandomDirScale, &GC_OP_WorldTraceConstraint::SetRandomDirScale)
        .addProperty("DecayBounce", &GC_OP_WorldTraceConstraint::GetDecayBounce, &GC_OP_WorldTraceConstraint::SetDecayBounce)
        .addProperty("KillonContact", &GC_OP_WorldTraceConstraint::GetKillonContact, &GC_OP_WorldTraceConstraint::SetKillonContact)
        .addProperty("MinSpeed", &GC_OP_WorldTraceConstraint::GetMinSpeed, &GC_OP_WorldTraceConstraint::SetMinSpeed)
        .addProperty("SetNormal", &GC_OP_WorldTraceConstraint::GetSetNormal, &GC_OP_WorldTraceConstraint::SetSetNormal)
        .addProperty("StickOnCollisionField", &GC_OP_WorldTraceConstraint::GetStickOnCollisionField, &GC_OP_WorldTraceConstraint::SetStickOnCollisionField)
        .addProperty("StopSpeed", &GC_OP_WorldTraceConstraint::GetStopSpeed, &GC_OP_WorldTraceConstraint::SetStopSpeed)
        .addProperty("EntityStickDataField", &GC_OP_WorldTraceConstraint::GetEntityStickDataField, &GC_OP_WorldTraceConstraint::SetEntityStickDataField)
        .addProperty("EntityStickNormalField", &GC_OP_WorldTraceConstraint::GetEntityStickNormalField, &GC_OP_WorldTraceConstraint::SetEntityStickNormalField)
        .endClass();
}