#include "global.h"
#include "functions.h"
#include "variables.h"
#include "gba/syscall.h"
#include "gba/defines.h"
#include "gba/io_reg.h"



void GameMain(void)
{
    register u8 z1 PIN(r9);
    u32 z2;
    u32 eight;
    volatile u16 *p128;
    volatile u16 *ie;
    volatile u16 *ds;
    register volatile u16 *p PIN(r1);

    RegisterRamReset(RESET_EWRAM);
    p128 = (volatile u16 *)REG_ADDR_SIOCNT;
    z1 = 0;
    z2 = 0;
    p128[1] = z2;
    InitIntrHandlers();
    ie = (volatile u16 *)REG_ADDR_IE;
    *ie = z2;
    REG_IME = 1;
    ds = (volatile u16 *)REG_ADDR_DISPSTAT;
    eight = 8;
    *ds = eight;
    ReadKeys();
    gUnk_020020B4 = z1;
    SetVBlankCallback(MainVBlankCallback);
    *ie = 0x2001;
    *ds = eight;
    FillFadePalette(RGB_WHITE);
    FadeToColor(0, 50);
    WaitForVBlank();
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
    gVBlankCounter = z2;
    for (;;)
        MainMenuLoop();
}
