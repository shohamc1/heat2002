#include "global.h"

extern u16 gUnk_0203761C;           /* 0x020005CC */
extern u8 gUnk_0203B6F4;           /* 0x02025248 */
extern u8 gUnk_0203B82C;           /* 0x0202539C */

extern void sub_08339B4C(void);
extern void sub_08339B18(void);
extern void sub_0833DA2C(u8 a);

u8 sub_0833DB24(void)
{
    u8 unused[0x200];
    u16 v;
    u32 w;
    gUnk_0203B6F4 = 0;
    sub_08339B4C();
    while (1) {

    if (gUnk_0203761C & 0xC0)
        gUnk_0203B6F4 ^= 1;
    v = gUnk_0203761C & 8;
    if (v != 0) {
        gUnk_0203B82C = 0;
        sub_0833DA2C(3);
        return 0;
    }
    w = gUnk_0203761C & 1;
    if (w != 0) {
        gUnk_0203B82C = v;
        sub_0833DA2C(3);
        return gUnk_0203B6F4 + 1;
    }
    if (gUnk_0203761C & 2) {
        gUnk_0203B82C = w;
        sub_0833DA2C(3);
        gUnk_0203B6F4 = w;
        return 1;
    }
    sub_0833DA2C(gUnk_0203B6F4);
    sub_08339B18();
        gUnk_0203B82C++;
        sub_08339B4C();
    }
}
