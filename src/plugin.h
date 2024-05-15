#pragma once

#include <kthook/kthook.hpp>

using CTimerProto = void(__cdecl*)();

class Plugin {
public:
    explicit Plugin(HMODULE hModule);
    HMODULE hModule;
private:
    kthook::kthook_simple<CTimerProto> hookCTimerUpdate{ reinterpret_cast<void*>(0x561B10) };
    static void mainloop(const decltype(hookCTimerUpdate)& hook);
};