#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gUnk_02039190;
void ModuleMainVBlankCallback(void);
extern u8 gModule_PleaseTurnOffYour[];
extern u8 gModule_GameBoyAdvance[];

void ModuleInitIntrHandlers(void);
void ModuleSetVBlankCallback(void (*callback)(void));
void ModuleFillFadePalette(u16 color);
void ModuleFadeToColor(u32 r0, u32 r1);
void ModuleM4aSoundInit(void);
u8 ModuleRunRace(u32 r0, u32 r1, u32 r2);
void ModuleDrawTextCenteredHighlight(u32 r0, u32 r1, u32 r2);
void ModuleM4aSoundVSyncOff(void);
void ModuleUpdateSprites(void);
void sub_08344B74(void);
void ModuleSortLinkCarsByTime(void);
void ModuleWaitForLinkRestart(void);

void ModuleGameMain(void)
{
    register u8 z1 asm("r9");
    u32 z2;
    u32 eight;
    volatile u16 *p128;
    volatile u16 *ie;
    volatile u16 *ds;
    register volatile u16 *p asm("r1");

    p128 = (volatile u16 *)0x04000128;
    z1 = 0;
    z2 = 0;
    p128[1] = z2;
    ModuleInitIntrHandlers();
    ie = (volatile u16 *)0x04000200;
    *ie = z2;
    *(volatile u16 *)0x04000208 = 1;
    ds = (volatile u16 *)0x04000004;
    eight = 8;
    *ds = eight;
    ModuleReadKeys();
    gUnk_020390C4 = z1;
    ModuleSetVBlankCallback(ModuleMainVBlankCallback);
    *ie = 0x2001;
    *ds = eight;
    ModuleFillFadePalette(0x7FFF);
    ModuleFadeToColor(0, 0x32);
    ModuleWaitForVBlank();
    p = (volatile u16 *)0x0400000E;
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
        ModuleFadeToColor(0, 0x0A);
        if (ModuleRunRace(0, 4, 0)) {
            ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_LINK_FAIL), 0x0A, 1);
            ModuleDrawTextCenteredHighlight((u32)gModule_PleaseTurnOffYour, 0x0C, 1);
            ModuleDrawTextCenteredHighlight((u32)gModule_GameBoyAdvance, 0x0D, 1);
            ModuleM4aMPlayStop(&gUnk_02038F70);
            ModuleM4aMPlayStop(&gUnk_02038FB0);
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
