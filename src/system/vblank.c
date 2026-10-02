#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "functions.h"
#include "variables.h"

void DummyIntr(void);
void IntrMain(void);
void VBlankIntr(void);
void ClearVBlankFlag(void);
void AckVBlank(void);

/* The file's RAM variables, defined in address order (ldscript.ld's
   .bss_vblank places the section at gVBlankCallback's address).
   gIntrTable's 14 slots end at gKeysHeld (ReadKeys' held/pressed pair,
   the only writer); the static gap arrays pad only the addresses no
   identified symbol covers. gUnk_020005D0 is IntrMain's EWRAM copy (the
   DmaCopy16 in InitIntrHandlers fills it, and INTR_VECTOR points at it),
   ending at gUnk_02000DD0, the vblank-acknowledged flag AckVBlank sets. */
EWRAM_DATA IntrFunc gVBlankCallback = 0;
static EWRAM_DATA u8 vblank_gap584[0xC] = {0};
EWRAM_DATA IntrFunc gIntrTable[14] = {0};
EWRAM_DATA u16 gKeysHeld = 0;                    /* 0x020005C8 */
static EWRAM_DATA u8 vblank_gap5CA[0x2] = {0};
EWRAM_DATA u16 gKeysPressed = 0;                 /* 0x020005CC */
static EWRAM_DATA u8 vblank_gap5CE[0x2] = {0};
EWRAM_DATA u8 gUnk_020005D0[0x800] = {0};
EWRAM_DATA u16 gUnk_02000DD0 = 0;

void InitIntrHandlers(void)
{
    ClearVBlankFlag();
    gVBlankCallback = DummyIntr;
#if PLATFORM_GBA
    DmaCopy16(3, (u32)IntrMain, gUnk_020005D0, 0x800);
    INTR_VECTOR = (void *)gUnk_020005D0;
#else
    // The platform layer dispatches interrupts from C (its IntrMain), so
    // there is no dispatcher to copy into EWRAM.
    INTR_VECTOR = IntrMain;
#endif
    REG_WAITCNT = WAITCNT_SRAM_4 | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1 | WAITCNT_PREFETCH_ENABLE;
    gIntrTable[1] = VBlankIntr;
    gIntrTable[0] = DummyIntr;
    gIntrTable[2] = DummyIntr;
    gIntrTable[3] = DummyIntr;
    gIntrTable[4] = DummyIntr;
    gIntrTable[5] = DummyIntr;
    gIntrTable[6] = DummyIntr;
    gIntrTable[7] = DummyIntr;
    gIntrTable[8] = DummyIntr;
    gIntrTable[9] = DummyIntr;
    gIntrTable[10] = DummyIntr;
    gIntrTable[11] = DummyIntr;
    gIntrTable[12] = DummyIntr;
    gIntrTable[13] = DummyIntr;
}

void SetVBlankCallback(void (*callback)(void))
{
    gVBlankCallback = callback;
    if (callback == NULL)
        gVBlankCallback = DummyIntr;
}

void VBlankIntr(void)
{
    if (gVBlankCallback != NULL)
        gVBlankCallback();
    AckVBlank();
}

void DummyIntr(void)
{}

void ClearVBlankFlag(void)
{ *(vu16 *)&gUnk_02000DD0 &= 0xFFFE; }

void AckVBlank(void)
{
    REG_IF = 1;
    gUnk_02000DD0 = 1;
}

void WaitForVBlank(void)
{
    volatile u16 *r2;
    u16 r1;
    u32 r0;
    u32 r3;

    ClearVBlankFlag();
    r2 = (volatile u16 *)&gUnk_02000DD0;
    r3 = 1;
    do {
#if PLATFORM_GBA
        __asm__ volatile("swi 0x02");
#else
        // The platform layer's frame pump: draws the frame, fires the
        // VBlank interrupt and returns when the next game frame is due.
        VBlankIntrWait();
#endif
        r1 = *r2;
        r0 = r3 & r1;
    } while (r0 == 0);
}
