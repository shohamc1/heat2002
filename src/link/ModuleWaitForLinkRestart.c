#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"


void ModuleWaitForLinkRestart(void)
{
    u32 playerId;
    u32 keys;

    ModuleAgeGfxCaches();
    ModuleClearOamBuffer();
    for (;;) {
        gModule_VBlanksThisFrame = 0;
        if (ModuleExchangeLinkInput() != 0) {
            ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_LINK_FAIL), 10, 1);
            ModuleDrawTextCenteredHighlight(gModule_PleaseTurnOffYour_2, 12, 1);
            ModuleDrawTextCenteredHighlight(gModule_GameBoyAdvance_2, 13, 1);
            ModuleM4aMPlayStop(&gModule_BgMusicPlayer);
            ModuleM4aMPlayStop(&gModule_EngineSoundPlayer);
            ModuleM4aSoundVSyncOff();
            do {
                playerId = gModule_LinkPlayerId;
                if (playerId == 0)
                    playerId = REG_KEYINPUT;
                ((void (*)(u32))sub_08344B74)(playerId);
            } while (1);
        } else {
            if (gModule_LinkPlayerId != 0) {
                ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_WAITING), 14, 1);
            } else {
                ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_PRESS_START), 14, 1);
            }
        }
        keys = (u16)ModuleReadLinkMenuKeys();
        if ((keys & 8) == 0)
            continue;
        ModuleFadeToColor(0, 50);
        return;
    }
}
