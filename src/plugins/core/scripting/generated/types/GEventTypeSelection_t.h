#ifndef _geventtypeselection_t_h
#define _geventtypeselection_t_h

enum class EventTypeSelection_t : uint64_t
{
    PARTICLE_EVENT_TYPE_MASK_NONE = 0x0,
    PARTICLE_EVENT_TYPE_MASK_SPAWNED = 0x1,
    PARTICLE_EVENT_TYPE_MASK_KILLED = 0x2,
    PARTICLE_EVENT_TYPE_MASK_COLLISION = 0x4,
    PARTICLE_EVENT_TYPE_MASK_FIRST_COLLISION = 0x8,
    PARTICLE_EVENT_TYPE_MASK_COLLISION_STOPPED = 0x10,
    PARTICLE_EVENT_TYPE_MASK_KILLED_ON_COLLISION = 0x20,
    PARTICLE_EVENT_TYPE_MASK_USER_1 = 0x40,
    PARTICLE_EVENT_TYPE_MASK_USER_2 = 0x80,
    PARTICLE_EVENT_TYPE_MASK_USER_3 = 0x100,
    PARTICLE_EVENT_TYPE_MASK_USER_4 = 0x200,
};

#endif