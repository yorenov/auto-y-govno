#include "imgui_sdraw.h"
#include "../main.h"
#include "config/config.h"
#include <sampapi/0.3.7-R3-1/CNetGame.h>

void imgui_init::Draw() {
    ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2),
                            ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(300.f, 150.f), ImGuiCond_FirstUseEver);
    ImGui::Begin("auto-press-y");

    if (ImGui::Checkbox("Debug", &tempVariables.debug); tempVariables.debug) {
        ImGui::Text("Current weapon %d",
                    sampapi::v037r3::RefNetGame()->GetPlayerPool()->GetLocalPlayer()->m_onfootData.m_nCurrentWeapon);
        ImGui::Text("Special key %d",
                    sampapi::v037r3::RefNetGame()->GetPlayerPool()->GetLocalPlayer()->m_onfootData.m_controllerState.m_value);
    }
    ImGui::SeparatorText("Задержка клика Y");
    static int delay = gConfig->data["delay"].get<int>();
    if (ImGui::InputInt("Delay", &delay)) {
        gConfig->data["delay"] = delay;
        gConfig->save();
    }

    ImGui::End();
}