#include "global.h"
#include "gba/io_reg.h"

void MainVBlankCallback(void);

extern u16 gKeysPressed;
extern u8 gIsLinkRace;
extern u8 gTrackId;
extern u8 gNumLaps;
extern u8 gUnk_0202CD90[];
extern u8 gUnk_0806C688[];
extern u8 SendMultibootIsland(void);
extern void InitIntrHandlers(void);
extern void ReadKeys(void);
extern void SetVBlankCallback(u32 a);
extern void sub_08001170(void);
extern void sub_0800184C(void);
extern void SetLinkSerialIntr(void);
extern void FadeToColor(u32 a, u32 b);
extern void WaitForVBlank(void);
extern void DetectLinkPlayers(void);
extern u8 RunRace(u32 a, u32 b, void *c);
extern u32 GetString(u32 a);
extern void DrawTextCentered(u32 a, u32 b, u32 c);
extern void StopAllSongsAndVSyncOff(void);
extern void SortLinkCarsByTime(void);
extern void sub_080053B8(void);
u8 StartSinglePakLink(void)
{
    s32 i;
    if (SendMultibootIsland() == 1)
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
        if (RunRace(a0, a1, gUnk_0202CD90) != 0) {
        DrawTextCentered(GetString(0x75), 0x0A, 1);
        DrawTextCentered((u32)gUnk_0806C688, 0x0C, 1);
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
