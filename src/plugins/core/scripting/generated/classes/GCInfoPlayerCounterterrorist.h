class GCInfoPlayerCounterterrorist;

#ifndef _gccinfoplayercounterterrorist_h
#define _gccinfoplayercounterterrorist_h

#include "../../../scripting.h"




class GCInfoPlayerCounterterrorist
{
private:
    void *m_ptr;

public:
    GCInfoPlayerCounterterrorist() {}
    GCInfoPlayerCounterterrorist(void *ptr) : m_ptr(ptr) {}



    bool IsValid() { return (m_ptr != nullptr); }
};

#endif