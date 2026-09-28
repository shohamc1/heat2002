#include "global.h"
#include "functions.h"
#include "variables.h"


void ModuleAgeGfxCaches(void);
void ModuleClearOamBuffer(void);
u32 ModuleExchangeLinkInput(void);
void ModuleDrawTextCenteredHighlight(u8 *str, u32 y, u32 shade);
void ModuleM4aSoundVSyncOff(void);
void sub_08344B74(u32 a);
u32 ModuleReadLinkMenuKeys(void);
void ModuleFadeToColor(u32 a, u32 b);

void ModuleWaitForLinkRestart(void)
{
    u32 playerId;
    u32 keys;

    ModuleAgeGfxCaches();
    ModuleClearOamBuffer();
    for (;;)
    {
        gModule_VBlanksThisFrame = 0;
        if (ModuleExchangeLinkInput() != 0)
        {
            ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_LINK_FAIL), 0xA, 1);
            ModuleDrawTextCenteredHighlight(gModule_PleaseTurnOffYour_2, 0xC, 1);
            ModuleDrawTextCenteredHighlight(gModule_GameBoyAdvance_2, 0xD, 1);
            ModuleM4aMPlayStop((struct MusicPlayerInfo *)((u32)gUnk_02038F70));
            ModuleM4aMPlayStop((struct MusicPlayerInfo *)((u32)gUnk_02038FB0));
            ModuleM4aSoundVSyncOff();
            do
            {
                playerId = gModule_LinkPlayerId;
                if (playerId == 0)
                    playerId = *(volatile u16 *)0x04000130;
                sub_08344B74(playerId);
            } while (1);
        }
        else
        {
            if (gModule_LinkPlayerId != 0)
            {
                ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_WAITING), 0xE, 1);
            }
            else
            {
                ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_PRESS_START), 0xE, 1);
            }
        }
        keys = (u16)ModuleReadLinkMenuKeys();
        if ((keys & 8) == 0)
            continue;
        ModuleFadeToColor(0, 0x32);
        return;
    }
}
