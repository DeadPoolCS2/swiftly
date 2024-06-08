#include "../../../core/scripting/generated/classes/GC_OP_ControlpointLight.h"
#include "../core.h"

void SetupLuaClassGC_OP_ControlpointLight(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GC_OP_ControlpointLight>("C_OP_ControlpointLight")
        .addProperty("Scale", &GC_OP_ControlpointLight::GetScale, &GC_OP_ControlpointLight::SetScale)
        .addProperty("ControlPoint1", &GC_OP_ControlpointLight::GetControlPoint1, &GC_OP_ControlpointLight::SetControlPoint1)
        .addProperty("ControlPoint2", &GC_OP_ControlpointLight::GetControlPoint2, &GC_OP_ControlpointLight::SetControlPoint2)
        .addProperty("ControlPoint3", &GC_OP_ControlpointLight::GetControlPoint3, &GC_OP_ControlpointLight::SetControlPoint3)
        .addProperty("ControlPoint4", &GC_OP_ControlpointLight::GetControlPoint4, &GC_OP_ControlpointLight::SetControlPoint4)
        .addProperty("CPOffset1", &GC_OP_ControlpointLight::GetCPOffset1, &GC_OP_ControlpointLight::SetCPOffset1)
        .addProperty("CPOffset2", &GC_OP_ControlpointLight::GetCPOffset2, &GC_OP_ControlpointLight::SetCPOffset2)
        .addProperty("CPOffset3", &GC_OP_ControlpointLight::GetCPOffset3, &GC_OP_ControlpointLight::SetCPOffset3)
        .addProperty("CPOffset4", &GC_OP_ControlpointLight::GetCPOffset4, &GC_OP_ControlpointLight::SetCPOffset4)
        .addProperty("LightFiftyDist1", &GC_OP_ControlpointLight::GetLightFiftyDist1, &GC_OP_ControlpointLight::SetLightFiftyDist1)
        .addProperty("LightZeroDist1", &GC_OP_ControlpointLight::GetLightZeroDist1, &GC_OP_ControlpointLight::SetLightZeroDist1)
        .addProperty("LightFiftyDist2", &GC_OP_ControlpointLight::GetLightFiftyDist2, &GC_OP_ControlpointLight::SetLightFiftyDist2)
        .addProperty("LightZeroDist2", &GC_OP_ControlpointLight::GetLightZeroDist2, &GC_OP_ControlpointLight::SetLightZeroDist2)
        .addProperty("LightFiftyDist3", &GC_OP_ControlpointLight::GetLightFiftyDist3, &GC_OP_ControlpointLight::SetLightFiftyDist3)
        .addProperty("LightZeroDist3", &GC_OP_ControlpointLight::GetLightZeroDist3, &GC_OP_ControlpointLight::SetLightZeroDist3)
        .addProperty("LightFiftyDist4", &GC_OP_ControlpointLight::GetLightFiftyDist4, &GC_OP_ControlpointLight::SetLightFiftyDist4)
        .addProperty("LightZeroDist4", &GC_OP_ControlpointLight::GetLightZeroDist4, &GC_OP_ControlpointLight::SetLightZeroDist4)
        .addProperty("LightColor1", &GC_OP_ControlpointLight::GetLightColor1, &GC_OP_ControlpointLight::SetLightColor1)
        .addProperty("LightColor2", &GC_OP_ControlpointLight::GetLightColor2, &GC_OP_ControlpointLight::SetLightColor2)
        .addProperty("LightColor3", &GC_OP_ControlpointLight::GetLightColor3, &GC_OP_ControlpointLight::SetLightColor3)
        .addProperty("LightColor4", &GC_OP_ControlpointLight::GetLightColor4, &GC_OP_ControlpointLight::SetLightColor4)
        .addProperty("LightType1", &GC_OP_ControlpointLight::GetLightType1, &GC_OP_ControlpointLight::SetLightType1)
        .addProperty("LightType2", &GC_OP_ControlpointLight::GetLightType2, &GC_OP_ControlpointLight::SetLightType2)
        .addProperty("LightType3", &GC_OP_ControlpointLight::GetLightType3, &GC_OP_ControlpointLight::SetLightType3)
        .addProperty("LightType4", &GC_OP_ControlpointLight::GetLightType4, &GC_OP_ControlpointLight::SetLightType4)
        .addProperty("LightDynamic1", &GC_OP_ControlpointLight::GetLightDynamic1, &GC_OP_ControlpointLight::SetLightDynamic1)
        .addProperty("LightDynamic2", &GC_OP_ControlpointLight::GetLightDynamic2, &GC_OP_ControlpointLight::SetLightDynamic2)
        .addProperty("LightDynamic3", &GC_OP_ControlpointLight::GetLightDynamic3, &GC_OP_ControlpointLight::SetLightDynamic3)
        .addProperty("LightDynamic4", &GC_OP_ControlpointLight::GetLightDynamic4, &GC_OP_ControlpointLight::SetLightDynamic4)
        .addProperty("UseNormal", &GC_OP_ControlpointLight::GetUseNormal, &GC_OP_ControlpointLight::SetUseNormal)
        .addProperty("UseHLambert", &GC_OP_ControlpointLight::GetUseHLambert, &GC_OP_ControlpointLight::SetUseHLambert)
        .addProperty("ClampLowerRange", &GC_OP_ControlpointLight::GetClampLowerRange, &GC_OP_ControlpointLight::SetClampLowerRange)
        .addProperty("ClampUpperRange", &GC_OP_ControlpointLight::GetClampUpperRange, &GC_OP_ControlpointLight::SetClampUpperRange)
        .endClass();
}