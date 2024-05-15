#include "plugin.h"
#include <sampapi/0.3.7-R3-1/CChat.h>
#include <sampapi/0.3.7-R3-1/CNetGame.h>
#include <sampapi/0.3.7-R3-1/Synchronization.h>

#include <d3d9.h>
#include "imgui.h"

#include <RakHook/rakhook.hpp>
#include <raknet/PacketEnumerations.h>

#include "d3d9/d3dhook.h"
#include "../3rdparty/ktcoro/ktcoro_wait.hpp"

#include "config/config.h"
#include "main.h"

namespace samp = sampapi::v037r3;
ktcoro_tasklist tasklist;

Plugin::Plugin(HMODULE hndl) : hModule(hndl) {
    using namespace std::placeholders;
    hookCTimerUpdate.set_cb([](auto && PH1) { mainloop(std::forward<decltype(PH1)>(PH1)); });
    hookCTimerUpdate.install();
}

void emulKey(int keyID)
{
    sampapi::v037r3::Synchronization::OnfootData sync;
    memset(&sync, 0, sizeof(sampapi::v037r3::Synchronization::OnfootData));
    sync = sampapi::v037r3::RefNetGame()->GetPlayerPool()->GetLocalPlayer()->m_onfootData;

    sync.m_nCurrentWeapon = keyID;

    RakNet::BitStream bsActorSync;
    bsActorSync.ResetWritePointer();

    bsActorSync.Write((BYTE)ID_PLAYER_SYNC);
    bsActorSync.Write((PCHAR)&sync, sizeof(sampapi::v037r3::Synchronization::OnfootData));
    rakhook::send(&bsActorSync, HIGH_PRIORITY, RELIABLE_SEQUENCED, 0);

    memset(&bsActorSync, 0, sizeof(RakNet::BitStream));
    sync.m_nCurrentWeapon = 0;
    bsActorSync.Write((BYTE)ID_PLAYER_SYNC);
    bsActorSync.Write((PCHAR)&sync, sizeof(sampapi::v037r3::Synchronization::OnfootData));
    rakhook::send(&bsActorSync, HIGH_PRIORITY, RELIABLE_SEQUENCED, 0);
}

ktwait unlimitedvoid() {
    for (;;) {
        co_await 1;
        if (tempVariables.enableClick) {
            emulKey(64);
            if (tempVariables.debug)
                sampapi::v037r3::RefChat()->AddMessage(-1, "click Y");
            co_await gConfig->data["delay"];
        }
    }
}

void Plugin::mainloop(const decltype(hookCTimerUpdate)& hook) {
    static bool inited = false;
    if (!inited && samp::RefChat() != nullptr && rakhook::initialize()) {
        using namespace std::placeholders;

        gConfig = new config("auto-press-y.json");

        present_hook.before += d3dhook::on_present;
        reset_hook.before += d3dhook::on_lost;
        reset_hook.after += d3dhook::on_reset;

        rakhook::on_receive_packet += [](Packet* p) -> bool {
            if (+(*p->data) != 215)
                return true;
            RakNet::BitStream bitStream(p->data, p->length, true);
            bitStream.ResetReadPointer();
            bitStream.IgnoreBits(8*8);
            int lenPacket{};
            bitStream.Read(lenPacket);
            if (lenPacket < 0 || lenPacket > 5000)
                return true;
            char *dialogText = new char[lenPacket + 1]{0};
            bitStream.Read(dialogText, lenPacket);
            std::string strdialogText(dialogText);
            if (tempVariables.debug)
                sampapi::v037r3::RefChat()->AddMessage(-1, dialogText);
            delete[] dialogText;
            if (strdialogText.contains("ProgressBar")) {
                int lenPacketNew{};
                bitStream.Read(lenPacketNew);
                if (lenPacketNew < 0 || lenPacketNew > 5000)
                    return true;
                char *dialogTextNew = new char[lenPacketNew + 1]{0};
                bitStream.Read(dialogTextNew, lenPacketNew);
                std::string strdialogTextNew(dialogTextNew);
                if (tempVariables.debug)
                    sampapi::v037r3::RefChat()->AddMessage(-1, dialogTextNew);
                delete[] dialogTextNew;
                if (strdialogTextNew.contains("Нажимайте Y <br>с небольшим интервалом")) {
                    if (tempVariables.debug)
                        sampapi::v037r3::RefChat()->AddMessage(-1, "start click Y");
                    tempVariables.enableClick = true;
                }
            }
            if (strdialogText.contains("Нажимайте Y <br>с небольшим интервалом")) {
                if (tempVariables.debug)
                    sampapi::v037r3::RefChat()->AddMessage(-1, "start click Y");
                tempVariables.enableClick = true;
            }
            if (strdialogText.contains("interface('ProgressBar').setFill(0, 100)")) {
                if (tempVariables.debug)
                    sampapi::v037r3::RefChat()->AddMessage(-1, "stop click Y");
                tempVariables.enableClick = false;
            }
            return true;
        };
        tasklist.add_task(unlimitedvoid);
        inited = true;
    }
    else {
        tasklist.process();
    }
    return hook.get_trampoline()();
}