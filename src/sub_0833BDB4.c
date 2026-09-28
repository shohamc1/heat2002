#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gUnk_02039190;
void sub_0833C5B0(void);
extern u8 gModule_PleaseTurnOffYour[];
extern u8 gModule_GameBoyAdvance[];

void sub_08339A40(void);
void sub_08339AB8(u32 r0);
void sub_0833D250(u16 color);
void sub_0833D510(u32 r0, u32 r1);
void sub_0833A830(void);
u8 sub_0833BF80(u32 r0, u32 r1, u32 r2);
void ModuleDrawTextCenteredHighlight(u32 r0, u32 r1, u32 r2);
void sub_0833AE90(void);
void sub_0833D9D8(void);
void sub_08344B74(void);
void sub_0833BCF8(void);
void sub_0833DE98(void);

void sub_0833BDB4(void)
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
    sub_08339A40();
    ie = (volatile u16 *)0x04000200;
    *ie = z2;
    *(volatile u16 *)0x04000208 = 1;
    ds = (volatile u16 *)0x04000004;
    eight = 8;
    *ds = eight;
    sub_08339B4C();
    gUnk_020390C4 = z1;
    sub_08339AB8((u32)sub_0833C5B0);
    *ie = 0x2001;
    *ds = eight;
    sub_0833D250(0x7FFF);
    sub_0833D510(0, 0x32);
    sub_08339B18();
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
    sub_0833A830();
    sub_0833AF0C();
    gModule_VBlanksThisFrame = z2;
    for (;;) {
        gUnk_02039194 = 3;
        ModuleLinkHandshake();
        gModule_IsLinkRace = 1;
        gUnk_02039190 = 0;
        sub_0833D510(0, 0x0A);
        if (sub_0833BF80(0, 4, 0)) {
            ModuleDrawTextCenteredHighlight(ModuleGetString(MODULE_MSG_LINK_FAIL), 0x0A, 1);
            ModuleDrawTextCenteredHighlight((u32)gModule_PleaseTurnOffYour, 0x0C, 1);
            ModuleDrawTextCenteredHighlight((u32)gModule_GameBoyAdvance, 0x0D, 1);
            sub_0833B074((struct MusicPlayerInfo *)((u32)gUnk_02038F70));
            sub_0833B074((struct MusicPlayerInfo *)((u32)gUnk_02038FB0));
            sub_0833AE90();
            for (;;) {
                sub_0833D9D8();
                sub_08344B74();
            }
        }
        sub_0833BCF8();
        sub_0833DE98();
    }
}
