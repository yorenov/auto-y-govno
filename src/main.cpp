#include "plugin.h"
#include "main.h"
#include <memory>

stTempVariables tempVariables;

[[maybe_unused]] std::unique_ptr<Plugin> plugin;

[[maybe_unused]] BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
    if (dwReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        plugin = std::make_unique<Plugin>(hModule);
    }
    return TRUE;
}