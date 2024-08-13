#include "../scripting.h"

#include <module.h>
#include "../../../utils/module.h"

void* FindSignature(const char* moduleName, const char* bytes);

PluginMemory::PluginMemory()
{
    m_ptr = nullptr;
}

void PluginMemory::LoadFromPtr(void* ptr)
{
    m_ptr = ptr;
}
void PluginMemory::LoadFromAddress(std::string addr)
{
    if (!starts_with(addr, "0x")) return;

    m_ptr = (void*)(strtol(addr.c_str(), nullptr, 16));
}

void PluginMemory::LoadFromSignatureName(std::string signature_name)
{
    m_ptr = g_Signatures->FetchRawSignature(signature_name);
}

void PluginMemory::LoadFromSignature(std::string library, std::string signature)
{
    void* sig = nullptr;
    if (signature.find("?") == std::string::npos)
    {
        std::string finalSig = (signature.at(0) == '@') ? signature : ("\\x" + replace(signature, " ", "\\x"));
        sig = FindSignature(library.c_str(), finalSig.c_str());
        if (sig == nullptr)
            return;
    }
    else
    {
        DynLibUtils::CModule module(library == "server" ? server : nullptr);
        DynLibUtils::CMemory sg = module.FindPattern(signature);
        if (!sg)
            return;

        sig = sg.RCast<void*>();
    }

    m_ptr = sig;
}

void PluginMemory::AddOffset(int64_t offset)
{
    m_ptr = ((char*)m_ptr) + offset;
}
void PluginMemory::RemoveOffset(int64_t offset)
{
    m_ptr = ((char*)m_ptr) - offset;
}

void PluginMemory::AccessVTable(int64_t offset)
{
    void* pt = m_ptr;
    m_ptr = reinterpret_cast<void***>(pt)[0][offset];
    accessedVTable = true;
}

bool PluginMemory::AccessedVTable()
{
    return accessedVTable;
}

void PluginMemory::Clear()
{
    m_ptr = nullptr;
}

void PluginMemory::SetBool(bool value)
{
    *((bool*)(m_ptr)) = value;
}
void PluginMemory::SetInt(int value)
{
    *((int*)(m_ptr)) = value;
}
void PluginMemory::SetInt64(int64_t value)
{
    *((int64_t*)(m_ptr)) = value;
}
void PluginMemory::SetUint(uint32_t value)
{
    *((uint32_t*)(m_ptr)) = value;
}
void PluginMemory::SetUint64(uint64_t value)
{
    *((uint64_t*)(m_ptr)) = value;
}
void PluginMemory::SetFloat(float value)
{
    *((float*)(m_ptr)) = value;
}
void PluginMemory::SetDouble(double value)
{
    *((double*)(m_ptr)) = value;
}

bool PluginMemory::GetBool()
{
    return *((bool*)(m_ptr));
}
int PluginMemory::GetInt()
{
    return *((int*)(m_ptr));
}
int64_t PluginMemory::GetInt64()
{
    return *((int64_t*)(m_ptr));
}
uint32_t PluginMemory::GetUint()
{
    return *((uint32_t*)(m_ptr));
}
uint64_t PluginMemory::GetUint64()
{
    return *((uint64_t*)(m_ptr));
}
float PluginMemory::GetFloat()
{
    return *((float*)(m_ptr));
}
double PluginMemory::GetDouble()
{
    return *((double*)(m_ptr));
}

std::string PluginMemory::GetPtr()
{
    return string_format("%p", m_ptr);
}

bool PluginMemory::IsValid()
{
    return (m_ptr != nullptr);
}

void* PluginMemory::GetRawPtr()
{
    return m_ptr;
}