#include "../../../core/scripting/generated/classes/GCEnvVolumetricFogController.h"
#include "../core.h"

void SetupLuaClassGCEnvVolumetricFogController(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCEnvVolumetricFogController>("CEnvVolumetricFogController")
        .addProperty("Scattering", &GCEnvVolumetricFogController::GetScattering, &GCEnvVolumetricFogController::SetScattering)
        .addProperty("Anisotropy", &GCEnvVolumetricFogController::GetAnisotropy, &GCEnvVolumetricFogController::SetAnisotropy)
        .addProperty("FadeSpeed", &GCEnvVolumetricFogController::GetFadeSpeed, &GCEnvVolumetricFogController::SetFadeSpeed)
        .addProperty("DrawDistance", &GCEnvVolumetricFogController::GetDrawDistance, &GCEnvVolumetricFogController::SetDrawDistance)
        .addProperty("FadeInStart", &GCEnvVolumetricFogController::GetFadeInStart, &GCEnvVolumetricFogController::SetFadeInStart)
        .addProperty("FadeInEnd", &GCEnvVolumetricFogController::GetFadeInEnd, &GCEnvVolumetricFogController::SetFadeInEnd)
        .addProperty("IndirectStrength", &GCEnvVolumetricFogController::GetIndirectStrength, &GCEnvVolumetricFogController::SetIndirectStrength)
        .addProperty("IndirectTextureDimX", &GCEnvVolumetricFogController::GetIndirectTextureDimX, &GCEnvVolumetricFogController::SetIndirectTextureDimX)
        .addProperty("IndirectTextureDimY", &GCEnvVolumetricFogController::GetIndirectTextureDimY, &GCEnvVolumetricFogController::SetIndirectTextureDimY)
        .addProperty("IndirectTextureDimZ", &GCEnvVolumetricFogController::GetIndirectTextureDimZ, &GCEnvVolumetricFogController::SetIndirectTextureDimZ)
        .addProperty("BoxMins", &GCEnvVolumetricFogController::GetBoxMins, &GCEnvVolumetricFogController::SetBoxMins)
        .addProperty("BoxMaxs", &GCEnvVolumetricFogController::GetBoxMaxs, &GCEnvVolumetricFogController::SetBoxMaxs)
        .addProperty("Active", &GCEnvVolumetricFogController::GetActive, &GCEnvVolumetricFogController::SetActive)
        .addProperty("StartAnisotropy", &GCEnvVolumetricFogController::GetStartAnisotropy, &GCEnvVolumetricFogController::SetStartAnisotropy)
        .addProperty("StartScattering", &GCEnvVolumetricFogController::GetStartScattering, &GCEnvVolumetricFogController::SetStartScattering)
        .addProperty("StartDrawDistance", &GCEnvVolumetricFogController::GetStartDrawDistance, &GCEnvVolumetricFogController::SetStartDrawDistance)
        .addProperty("DefaultAnisotropy", &GCEnvVolumetricFogController::GetDefaultAnisotropy, &GCEnvVolumetricFogController::SetDefaultAnisotropy)
        .addProperty("DefaultScattering", &GCEnvVolumetricFogController::GetDefaultScattering, &GCEnvVolumetricFogController::SetDefaultScattering)
        .addProperty("DefaultDrawDistance", &GCEnvVolumetricFogController::GetDefaultDrawDistance, &GCEnvVolumetricFogController::SetDefaultDrawDistance)
        .addProperty("StartDisabled", &GCEnvVolumetricFogController::GetStartDisabled, &GCEnvVolumetricFogController::SetStartDisabled)
        .addProperty("EnableIndirect", &GCEnvVolumetricFogController::GetEnableIndirect, &GCEnvVolumetricFogController::SetEnableIndirect)
        .addProperty("IndirectUseLPVs", &GCEnvVolumetricFogController::GetIndirectUseLPVs, &GCEnvVolumetricFogController::SetIndirectUseLPVs)
        .addProperty("IsMaster", &GCEnvVolumetricFogController::GetIsMaster, &GCEnvVolumetricFogController::SetIsMaster)
        .addProperty("ForceRefreshCount", &GCEnvVolumetricFogController::GetForceRefreshCount, &GCEnvVolumetricFogController::SetForceRefreshCount)
        .addProperty("NoiseSpeed", &GCEnvVolumetricFogController::GetNoiseSpeed, &GCEnvVolumetricFogController::SetNoiseSpeed)
        .addProperty("NoiseStrength", &GCEnvVolumetricFogController::GetNoiseStrength, &GCEnvVolumetricFogController::SetNoiseStrength)
        .addProperty("NoiseScale", &GCEnvVolumetricFogController::GetNoiseScale, &GCEnvVolumetricFogController::SetNoiseScale)
        .addProperty("FirstTime", &GCEnvVolumetricFogController::GetFirstTime, &GCEnvVolumetricFogController::SetFirstTime)
        .endClass();
}