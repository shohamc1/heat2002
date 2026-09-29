#include "global.h"
#include "variables.h"

void AckVBlank(void);
void ClearVBlankFlag(void);

void VBlankIntr(void)
{
    if (gVBlankCallback[0] != 0)
        /* gVBlankCallback[0]: this file's old local prototype differs from
           functions.h; call through the old signature (solved-walls 31). */
        ((void (*)(void))gVBlankCallback[0])();
    AckVBlank();
}

void DummyIntr(void)
{}

void ClearVBlankFlag(void)
{ *(vu16 *)&gUnk_02000DD0 &= 0xFFFE; }

void AckVBlank(void)
{
    *(volatile u16 *)0x04000202 = 1;
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
        __asm__ volatile("swi 0x02");
        r1 = *r2;
        r0 = r3 & r1;
    } while (r0 == 0);
}
