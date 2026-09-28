#include "global.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

void MainVBlankCallback(void);

extern u8 gUnk_0202CD90[];
extern u8 gText_PressStartToExit[];
u8 StartSinglePakLink(void)
{
    s32 i;
    /* SendMultibootIsland: this file's old prototype returns u8; the
       matched definition returns u32; call through a function pointer. */
    if (((u8 (*)(void))SendMultibootIsland)() == 1)
        return 1;
    InitIntrHandlers();
    REG_IE = 0;
    REG_IME = 1;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    ReadKeys();
    SetVBlankCallback((u32)MainVBlankCallback);
    REG_IE = INTR_FLAG_GAMEPAK | INTR_FLAG_VBLANK;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    sub_08001170();
    sub_0800184C();
    SetLinkSerialIntr();
    FadeToColor(0, 0x0A);
    i = 0;
    do {
        WaitForVBlank();
        i++;
    } while (i != 0x32);
loop:
    gIsLinkRace = 1;
    DetectLinkPlayers();
    gIsLinkRace = 1;
    gTrackId = 7;
    gNumLaps = 3;
    {
        /* The ROM loads the address after the two constants. The stock
           compiler precomputes an address argument before the other
           argument registers are loaded, unless those are already in place:
           pinning them emits their loads first. */
        register u32 a0 asm("r0") = 0;
        register u32 a1 asm("r1") = 4;
        /* RunRace: the ROM caller passes a third argument the matched definition drops; call
           through a function pointer with the old prototype. */
        if (((u8 (*)(u32, u32, void *))RunRace)(a0, a1, gUnk_0202CD90) != 0) {
        /* DrawTextCentered: the ROM callers pass a third argument the matched definition drops; call
           through a function pointer with the old prototype. */
        ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x75), 0x0A, 1);
        ((void (*)(u32, u32, u32))DrawTextCentered)((u32)gText_PressStartToExit, 0x0C, 1);
        StopAllSongsAndVSyncOff();
wait1:
        ReadKeys();
        if ((gKeysPressed & 8) == 0)
            goto wait1;
wait2:
        ReadKeys();
        if (gKeysPressed & 8)
            goto wait2;
        FadeToColor(0, 0x32);
    } else {
        SortLinkCarsByTime();
        sub_080053B8();
        goto loop;
    }
    }
}
