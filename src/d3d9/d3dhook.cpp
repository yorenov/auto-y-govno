#include "d3dhook.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx9.h"
#include "../main.h"
#include <windows.h>
#include <imgui.h>

#include "../imgui/imgui_sdraw.h"

HWND game_hwnd = [] {
    if (const HWND *hwnd_ptr = *reinterpret_cast<HWND **>(0xC17054); hwnd_ptr != nullptr) {
        return *hwnd_ptr;
    }
    game_instance_init_hook.after += [](const auto &hook, const HWND &return_value, HINSTANCE inst) {
        game_hwnd = return_value;
    };
    return static_cast<HWND>(nullptr);
}();


std::optional<HRESULT> d3dhook::on_present(const decltype(present_hook) &hook, IDirect3DDevice9 *device_ptr, const RECT *, const RECT *, HWND, const RGNDATA *) {
    static bool ImGui_inited = false;
    if (!ImGui_inited) {
        ImGui::CreateContext();
        const ImGuiIO &io = ImGui::GetIO();
        (void) io;
        ImGui_ImplWin32_Init(game_hwnd);
        ImGui_ImplDX9_Init(device_ptr);
        ImGui::GetIO().Fonts->AddFontFromFileTTF(R"(C:\Windows\Fonts\Arial.ttf)", 16.5f,
                                                 nullptr, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
        ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

        const auto latest_wndproc_ptr = GetWindowLongPtrA(game_hwnd, GWLP_WNDPROC);
        wndproc_hook.set_dest(latest_wndproc_ptr);
        wndproc_hook.set_cb(&keyhook::on_wndproc);
        wndproc_hook.install();
        ImGui_inited = true;
    }
    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    if (tempVariables.is_open_menu) {
        imgui_init::Draw();
    }
    if (tempVariables.temp_is_open_menu != tempVariables.is_open_menu) {
        tempVariables.temp_is_open_menu = tempVariables.is_open_menu;
        showCursor(tempVariables.is_open_menu);
    }
    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
    return std::nullopt;
}

std::optional<HRESULT> d3dhook::on_lost(const decltype(reset_hook) &hook, IDirect3DDevice9 *device_ptr, D3DPRESENT_PARAMETERS *parameters) {
    ImGui_ImplDX9_InvalidateDeviceObjects();
    return std::nullopt;
}

void d3dhook::on_reset(const decltype(reset_hook) &hook, HRESULT &return_value, IDirect3DDevice9 *device_ptr,
                       D3DPRESENT_PARAMETERS *parameters) {
}

void *get_function_address(const int VTableIndex) {
    return (*reinterpret_cast<void ***>(keyhook::find_device(0x128000)))[VTableIndex];
}

void d3dhook::showCursor(bool state) {
    using RwD3D9GetCurrentD3DDevice_t = LPDIRECT3DDEVICE9(__cdecl *)();

    const auto rwCurrentD3dDevice{reinterpret_cast<
                                          RwD3D9GetCurrentD3DDevice_t>(0x7F9D50U)()};

    if (nullptr == rwCurrentD3dDevice) {
        return;
    }

    static DWORD
            updateMouseProtection,
            rsMouseSetPosProtFirst,
            rsMouseSetPosProtSecond;

    if (state)
    {
        VirtualProtect(reinterpret_cast<void *>(0x53F3C6U), 5U,
                       PAGE_EXECUTE_READWRITE, &updateMouseProtection);

        VirtualProtect(reinterpret_cast<void *>(0x53E9F1U), 5U,
                       PAGE_EXECUTE_READWRITE, &rsMouseSetPosProtFirst);

        VirtualProtect(reinterpret_cast<void *>(0x748A1BU), 5U,
                       PAGE_EXECUTE_READWRITE, &rsMouseSetPosProtSecond);

        // NOP: CPad::UpdateMouse
        *reinterpret_cast<uint8_t *>(0x53F3C6U) = 0xE9U;
        *reinterpret_cast<uint32_t *>(0x53F3C6U + 1U) = 0x15BU;

        // NOP: RsMouseSetPos
        memset(reinterpret_cast<void *>(0x53E9F1U), 0x90, 5U);
        memset(reinterpret_cast<void *>(0x748A1BU), 0x90, 5U);

        rwCurrentD3dDevice->ShowCursor(TRUE);
    }
    else
    {
        // Original: CPad::UpdateMouse
        memcpy(reinterpret_cast<void *>(0x53F3C6U), "\xE8\x95\x6C\x20\x00", 5U);

        // Original: RsMouseSetPos
        memcpy(reinterpret_cast<void *>(0x53E9F1U), "\xE8\xAA\xAA\x0D\x00", 5U);
        memcpy(reinterpret_cast<void *>(0x748A1BU), "\xE8\x80\x0A\xED\xFF", 5U);

        using CPad_ClearMouseHistory_t = void(__cdecl *)();
        using CPad_UpdatePads_t = void(__cdecl *)();

        reinterpret_cast<CPad_ClearMouseHistory_t>(0x541BD0U)();
        reinterpret_cast<CPad_UpdatePads_t>(0x541DD0U)();

        VirtualProtect(reinterpret_cast<void *>(0x53F3C6U), 5U,
                       updateMouseProtection, &updateMouseProtection);

        VirtualProtect(reinterpret_cast<void *>(0x53E9F1U), 5U,
                       rsMouseSetPosProtFirst, &rsMouseSetPosProtFirst);

        VirtualProtect(reinterpret_cast<void *>(0x748A1BU), 5U,
                       rsMouseSetPosProtSecond, &rsMouseSetPosProtSecond);

        rwCurrentD3dDevice->ShowCursor(FALSE);
    }
}