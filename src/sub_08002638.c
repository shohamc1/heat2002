#include "global.h"
#include "functions.h"
#include "variables.h"

void MainVBlankCallback(void);

void RegisterRamReset(u32 r0);
void FillFadePalette(u16 color);
u32 MainMenuLoop(void);

void GameMain(void)
{
    register u8 z1 asm("r9");
    u32 z2;
    u32 eight;
    volatile u16 *p128;
    volatile u16 *ie;
    volatile u16 *ds;
    register volatile u16 *p asm("r1");

    RegisterRamReset(1);
    p128 = (volatile u16 *)0x04000128;
    z1 = 0;
    z2 = 0;
    p128[1] = z2;
    InitIntrHandlers();
    ie = (volatile u16 *)0x04000200;
    *ie = z2;
    *(volatile u16 *)0x04000208 = 1;
    ds = (volatile u16 *)0x04000004;
    eight = 8;
    *ds = eight;
    ReadKeys();
    gUnk_020020B4 = z1;
    SetVBlankCallback((u32)MainVBlankCallback);
    *ie = 0x2001;
    *ds = eight;
    FillFadePalette(0x7FFF);
    FadeToColor(0, 0x32);
    WaitForVBlank();
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
    gUnk_02002124 = z2;
    for (;;)
        MainMenuLoop();
}
