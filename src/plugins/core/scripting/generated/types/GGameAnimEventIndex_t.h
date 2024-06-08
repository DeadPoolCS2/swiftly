#ifndef _ggameanimeventindex_t_h
#define _ggameanimeventindex_t_h

enum class GameAnimEventIndex_t : uint64_t
{
    AE_EMPTY = 0x0,
    AE_CL_PLAYSOUND = 0x1,
    AE_CL_PLAYSOUND_ATTACHMENT = 0x2,
    AE_CL_PLAYSOUND_POSITION = 0x3,
    AE_SV_PLAYSOUND = 0x4,
    AE_CL_STOPSOUND = 0x5,
    AE_CL_PLAYSOUND_LOOPING = 0x6,
    AE_CL_CREATE_PARTICLE_EFFECT = 0x7,
    AE_CL_STOP_PARTICLE_EFFECT = 0x8,
    AE_CL_CREATE_PARTICLE_EFFECT_CFG = 0x9,
    AE_SV_CREATE_PARTICLE_EFFECT_CFG = 0xa,
    AE_SV_STOP_PARTICLE_EFFECT = 0xb,
    AE_FOOTSTEP = 0xc,
    AE_RAGDOLL = 0xd,
    AE_CL_STOP_RAGDOLL_CONTROL = 0xe,
    AE_CL_ENABLE_BODYGROUP = 0xf,
    AE_CL_DISABLE_BODYGROUP = 0x10,
    AE_BODYGROUP_SET_VALUE = 0x11,
    AE_CL_BODYGROUP_SET_VALUE_CMODEL_WPN = 0x12,
    AE_WEAPON_PERFORM_ATTACK = 0x13,
    AE_FIRE_INPUT = 0x14,
    AE_CL_CLOTH_ATTR = 0x15,
    AE_CL_CLOTH_GROUND_OFFSET = 0x16,
    AE_CL_CLOTH_STIFFEN = 0x17,
    AE_CL_CLOTH_EFFECT = 0x18,
    AE_CL_CREATE_ANIM_SCOPE_PROP = 0x19,
    AE_SV_IKLOCK = 0x1a,
    AE_PULSE_GRAPH = 0x1b,
    AE_PULSE_GRAPH_LOOKAT = 0x1c,
    AE_PULSE_GRAPH_AIMAT = 0x1d,
    AE_PULSE_GRAPH_IKLOCKLEFTARM = 0x1e,
    AE_PULSE_GRAPH_IKLOCKRIGHTARM = 0x1f,
    AE_CL_WEAPON_TRANSITION_INTO_HAND = 0x20,
    AE_CL_BODYGROUP_SET_TO_CLIP = 0x21,
    AE_CL_BODYGROUP_SET_TO_NEXTCLIP = 0x22,
    AE_SV_SHOW_SILENCER = 0x23,
    AE_SV_ATTACH_SILENCER_COMPLETE = 0x24,
    AE_SV_HIDE_SILENCER = 0x25,
    AE_SV_DETACH_SILENCER_COMPLETE = 0x26,
    AE_CL_EJECT_MAG = 0x27,
    AE_WPN_COMPLETE_RELOAD = 0x28,
    AE_WPN_HEALTHSHOT_INJECT = 0x29,
    AE_CL_C4_SCREEN_TEXT = 0x2a,
    AE_GRENADE_THROW_COMPLETE = 0x2b,
};

#endif