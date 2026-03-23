#pragma once
#ifdef _WIN32
  #ifdef PLUGIN_EXPORTS
    #define PLUGIN_API __declspec(dllexport)
  #else
    #define PLUGIN_API __declspec(dllimport)
  #endif
#else
  #define PLUGIN_API
#endif

#include <cstdint>

extern "C" {
PLUGIN_API int PluginAPIVersion();

struct EngineAPI;
using EntityId = uint64_t;

struct Script {
    virtual ~Script() {}
    virtual void OnCreate(EngineAPI* engine, EntityId entity) = 0;
    virtual void OnUpdate(EngineAPI* engine, EntityId entity, float dt) = 0;
    virtual void OnDestroy(EngineAPI* engine, EntityId entity) = 0;
};

PLUGIN_API Script* CreateScriptByName(const char* name);
PLUGIN_API Script* CreateScriptByIndex(int idx);
PLUGIN_API void DestroyScriptInstance(Script* script);

PLUGIN_API int PluginScriptCount();
PLUGIN_API const char* PluginScriptNameAt(int idx);
} // extern "C"