#include "global.h"

extern u32 gUnk_0203B84C; /* 0x0203B84C */
extern u32 gUnk_0203B6CC; /* 0x0203B6CC */
extern u8 gUnk_0203B6F0; /* 0x0203B6F0 */
extern u8 gUnk_0203B6E8; /* 0x0203B6E8 */
extern u8 gUnk_0203916C; /* 0x0203916C */
extern u8 gUnk_0203E120; /* 0x0203E120 */
extern u8 gUnk_02025220[]; /* 0x02025220 */
extern u8 gUnk_020390DC; /* 0x020390DC */

void sub_0833E0AC(void)
{
    int v;
    u8 *e;

    gUnk_0203B84C = 0;
    gUnk_0203B6CC = gUnk_0203B6F0;
    gUnk_0203B6E8 = 1;
    if (gUnk_0203916C == 0xA)
        gUnk_0203B6CC = 0x14;
    if (gUnk_0203916C == 0)
    {
        v = (u8)(3 - gUnk_0203E120);
        e = gUnk_02025220;
        e += gUnk_020390DC;
        v += 3;
        gUnk_0203B6CC = *e + v;
    }
}
