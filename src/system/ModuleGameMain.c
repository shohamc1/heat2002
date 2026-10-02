#include "global.h"
#include "functions.h"
#include "variables.h"
#include "gba/defines.h"
#include "gba/io_reg.h"

extern u8 gUnk_02039190;
extern u8 gModule_PleaseTurnOffYour[];
extern u8 gModule_GameBoyAdvance[];


void ModuleGameMain(void)
{
    register u8 z1 PIN(r9);
    u32 z2;
    u32 eight;
    volatile u16 *p128;
    volatile u16 *ie;
    volatile u16 *ds;
    register volatile u16 *p PIN(r1);

    p128 = (volatile u16 *)REG_ADDR_SIOCNT;
    z1 = 0;
    z2 = 0;
    p128[1] = z2;
    ModuleInitIntrHandlers();
    ie = (volatile u16 *)REG_ADDR_IE;
    *ie = z2;
    REG_IME = 1;
    ds = (volatile u16 *)REG_ADDR_DISPSTAT;
    eight = 8;
    *ds = eight;
    ModuleReadKeys();
    gUnk_020390C4 = z1;
    ModuleSetVBlankCallback(ModuleMainVBlankCallback);
    *ie = 0x2001;
    *ds = eight;
    ModuleFillFadePalette(RGB_WHITE);
    ModuleFadeToColor(0, 50);
    ModuleWaitForVBlank();
    p = (volatile u16 *)REG_ADDR_BG3CNT;
    *p = 0x3D0B;
    p -= 1;
    *p = 0x1E01;
    p -= 1;
    *p = 0x1F02;
    p -= 1;
    *p = 0x1C0C;
    p += 0x25;
    *p = 0x808;
    p -= 1;
    *p = 0x740;
    p -= 0x28;
    *p = 0x1D40;
    ModuleM4aSoundInit();
    ModuleM4aSoundVSyncOn();
    gModule_VBlanksThisFrame = z2;
    for (;;) {
        gUnk_02039194 = 3;
        ModuleLinkHandshake();
        gModule_IsLinkRace = 1;
        gUnk_02039190 = 0;
        ModuleFadeToColor(0, 10);
        if (ModuleRunRace(0, 4, 0)) {
            ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_LINK_FAIL), 10, 1);
            ModuleDrawTextCenteredHighlight(gModule_PleaseTurnOffYour, 12, 1);
            ModuleDrawTextCenteredHighlight(gModule_GameBoyAdvance, 13, 1);
            ModuleM4aMPlayStop(&gModule_BgMusicPlayer);
            ModuleM4aMPlayStop(&gModule_EngineSoundPlayer);
            ModuleM4aSoundVSyncOff();
            for (;;) {
                ModuleUpdateSprites();
                sub_08344B74();
            }
        }
        ModuleSortLinkCarsByTime();
        ModuleWaitForLinkRestart();
    }
}
