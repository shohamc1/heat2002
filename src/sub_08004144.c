#include "global.h"
#include "gba/defines.h"

void sub_080041A0(void);

void sub_08004144(void)
{
    u32 v = *(s16 *)(EWRAM_START + 0x22E18);
    u8 *p = (u8 *)(EWRAM_START + 0x22E14);
    if (v == 0)
        *p = v;
    if (*p != 0)
    {
        u32 i;
        u32 n;
        u32 *r3;
        u32 *r4;
        sub_080041A0();
        i = 0;
        n = 0x300;
        r3 = (u32 *)(EWRAM_START + 0x22E20);
        r4 = (u32 *)(EWRAM_START + 0x23A20);
        while (i != n)
        {
            *r3++ += *r4++;
            i++;
        }
        *(u16 *)(EWRAM_START + 0x22E18) = *(u16 *)(EWRAM_START + 0x22E18) - 1;
    }
    *(u8 *)(EWRAM_START + 0x22E10) = 1;
}
