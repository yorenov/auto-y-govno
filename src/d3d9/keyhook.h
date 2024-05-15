#pragma once

#include <Windows.h>
#include <string>
#include <kthook/kthook.hpp>

inline kthook::kthook_simple<WNDPROC> wndproc_hook{};

namespace keyhook {
    HRESULT __stdcall on_wndproc(const decltype(wndproc_hook) &hook, HWND hwnd, const UINT uMsg, const WPARAM wParam,
                                 const LPARAM lParam);
    std::uintptr_t find_device(std::uint32_t LenId);
};