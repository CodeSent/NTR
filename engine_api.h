#pragma once
#include <cstdint>

extern "C" {
using EntityId = uint64_t;

struct EngineAPI {
    void (*Log)(const char* message);
    void (*AddComponent)(EntityId entity, const char* component);
    void (*RemoveComponent)(EntityId entity, const char* component);
    void* (*AllocMemory)(size_t size);
    void (*FreeMemory)(void* ptr);
};
} // extern "C"