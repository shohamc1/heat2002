#include "global.h"
#include "variables.h"

#include "functions.h"
extern u8 gModule_Player1[];
extern u8 gModule_Player2[];
extern u8 gModule_Player3[];
extern u8 gModule_Player4[];
void ModuleDrawTextCenteredHighlight(u8 *s, u32 a, u32 b);
extern u32 gUnk_02038FF0[];
extern u32 gUnk_02039040[];
void ModuleReadLinkMenuKeys(void);
u32 ModuleExchangeLinkInput(void);
void ModuleM4aSoundVSyncOff(void);
void sub_08344B74(void);
void ModuleClearPausedPlayerText(void);
void ModuleDrawPausedPlayerText(void);

u32 ModuleLinkPauseMenu(void)
{
    u8 unused[0x200];

    gUnk_0203B850[0] = 0xFF;
    return 0;
}

void ModuleDrawPausedPlayerText(void)
{
    ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_PAUSE), 8, 1);

    switch (gUnk_0203B850[0]) {
        case 0:
            ModuleDrawTextCenteredHighlight(gModule_Player1, 9, 1);
            break;
        case 1:
            ModuleDrawTextCenteredHighlight(gModule_Player2, 9, 1);
            break;
        case 2:
            ModuleDrawTextCenteredHighlight(gModule_Player3, 9, 1);
            break;
        case 3:
            ModuleDrawTextCenteredHighlight(gModule_Player4, 9, 1);
            break;
    }
}

void ModuleClearPausedPlayerText(void)
{
    u8 col = 0;

    do {
        u16 *map = (u16 *)(*(volatile u32 *)&gModule_TextLayerMapPtr); /* per-iteration reload, as the ROM loop */
        u16 *dest = (u16 *)(2 * col + (u32)map);
        dest[0x100] = 0x47;
        dest[0x120] = 0x47;
        col++;
    } while (col != 0x1B);
}

u8 ModuleSinglePakPauseMenu(void)
{
    volatile u8 unused[512];
    u32 done;
    u16 startMask;

    gUnk_0203B850[0] = 0xFF;
    ModuleReadLinkMenuKeys();
    if (gUnk_0203B6FC & 8) {
        ModuleM4aMPlayStop((struct MusicPlayerInfo *)gUnk_02038F70);
        ModuleM4aMPlayStop((struct MusicPlayerInfo *)gUnk_02038FB0);
        ModuleM4aMPlayStop((struct MusicPlayerInfo *)gUnk_02038FF0);
        ModuleM4aMPlayStop((struct MusicPlayerInfo *)gUnk_02039040);
        for (;;) {
            gModule_VBlanksThisFrame = 0;
            if (ModuleExchangeLinkInput() != 0) {
                ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_LINK_FAIL), 0xA, 1);
                ModuleDrawTextCenteredHighlight((u32 *)gModule_PleaseTurnOffYour_2, 0xC, 1);
                ModuleDrawTextCenteredHighlight((u32 *)gModule_GameBoyAdvance_2, 0xD, 1);
                ModuleM4aSoundVSyncOff();
                done = 0;
                do {
                    if (gModule_LinkPlayerId == 0)
                        return 0x27;
                    sub_08344B74();
                } while (done == 0);
            }
            ModuleReadLinkMenuKeys();
            startMask = gUnk_0203B6FC & 8;
            if (startMask != 0) {
                ModuleClearPausedPlayerText();
                return 1;
            }
            ModuleDrawPausedPlayerText();
            (*(u32 *)&gModule_FrameCounter) = (*(u32 *)&gModule_FrameCounter) + 1;
            gModule_VBlankWorkDone = startMask;
        spin:
            if (gModule_VBlankWorkDone == 0)
                goto spin;
        }
    }
    return 0;
}
