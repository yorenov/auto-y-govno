#pragma once
#include <Windows.h>

struct stTempVariables {
    //ImGui menu
    bool is_open_menu{}; // true = enable menu, false = disable menu
    bool temp_is_open_menu{};
    bool debug{};
    bool enableClick{};
}; extern stTempVariables tempVariables;