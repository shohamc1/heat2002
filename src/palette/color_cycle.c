#include "global.h"
#include "gba/compat.h"
#include "functions.h"
#include "variables.h"

extern u32 gUnk_0202EDE4;
extern u16 gUnk_0202EDF0[];
#if PLATFORM_GBA
extern u16 gUnk_0500013C;                 /* 0x0500013C */
#else
/* Palette RAM lvalue (BG palette word 0x9E) as a host PLTT cell; the
   only use takes its address for CpuSet. */
#define gUnk_0500013C (*(u16 *)((u8 *)PLTT + 0x13C))
#endif

void sub_08010768(s32 a)
{
    s32 r;
    u16 *p;
    register s32 n PIN(r1) = -a;

    r = sub_080172C8(n, 6);
    if (r < 0)
        r += 6;
    gUnk_0202EED0 = r;
    p = gUnk_0202EDF0;
    LoadFadePalette(p);
    CpuSet((void *)p, (void *)PLTT, 0x40);
}

void CyclePaletteColor(void)
{
    u32 idx;
    u16 color;

    idx = (gUnk_0202EDE4 + 1) & 0x1F;
    gUnk_0202EDE4 = idx;
    color = 0x6800 | (idx << 5);
    CpuSet((void *)&color, (void *)&gUnk_0500013C, 1);
}
