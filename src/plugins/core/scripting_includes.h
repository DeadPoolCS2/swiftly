#pragma once

#include "../../common.h"
#include "../../entrypoint.h"
#include "../Plugin.h"
#include "../PluginManager.h"
#include "../../database/DatabaseManager.h"
#include "../../types/LogType.h"
#include "../../logs/Logger.h"
#include "../../sdk/schema.h"
#include "../../utils/plat.h"
#include "ehandle.h"

//////////////////////////////////////////////////////////////
/////////////////            Schema            //////////////
////////////////////////////////////////////////////////////

template <typename T>
T GetSchemaValue(void* ptr, const char* className, const char* fieldName)
{
    auto m_key = sch::GetOffset(className, fieldName);

    return *reinterpret_cast<std::add_pointer_t<T>>((uintptr_t)(ptr)+m_key);
}

template <typename T>
T* GetSchemaValuePtr(void* ptr, const char* className, const char* fieldName)
{
    auto m_key = sch::GetOffset(className, fieldName);

    return reinterpret_cast<std::add_pointer_t<T>>((uintptr_t)(ptr)+m_key);
}

void* GetSchemaPtr(void* ptr, const char* className, const char* fieldName);

void WriteSchemaPtrValue(void* ptr, const char* className, const char* fieldName, bool isStruct, byte* value, int size);

template <typename T>
void SetSchemaValue(void* ptr, const char* className, const char* fieldName, bool isStruct, T value)
{
    auto m_key = sch::GetOffset(className, fieldName);

    SetStateChanged((uintptr_t)ptr, className, fieldName, 0, isStruct);
    *reinterpret_cast<std::add_pointer_t<T>>((uintptr_t)(ptr)+m_key) = value;
}

template <typename T>
void SetSchemaValueCUtlVector(void* ptr, const char* className, const char* fieldName, bool isStruct, std::vector<T> value)
{
    auto m_key = sch::GetOffset(className, fieldName);

    SetStateChanged((uintptr_t)ptr, className, fieldName, 0, isStruct);

    CUtlVector<T>* vec = reinterpret_cast<CUtlVector<T> *>((uintptr_t)(ptr)+m_key);
    vec->Purge();
    for (auto elem : value)
        vec->AddToTail(elem);

    SetStateChanged((uintptr_t)ptr, className, fieldName, 0, isStruct);
}