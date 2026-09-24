#include "global.h"

extern u32 gUnk_02025DB0[]; /* 0x02025DB0 */
extern u32 gUnk_02025400[]; /* 0x02025400 */
extern u32 gUnk_020255E0[]; /* 0x020255E0 */
extern u32 gUnk_02025AE0[]; /* 0x02025AE0 */
extern u32 gUnk_02025C70[]; /* 0x02025C70 */
extern u32 gUnk_02025860[]; /* 0x02025860 */
extern u32 gUnk_02025E00[]; /* 0x02025E00 */

void AgeGfxCaches(void)
{
    u32 *p;
    u32 *a2;
    u32 *a3;
    u32 *a4;
    u32 *a5;
    u32 *a6;
    u32 *q;
    u32 i;

    p = gUnk_02025DB0;
    i = 0;
    a2 = gUnk_02025400;
    a3 = gUnk_020255E0;
    a4 = gUnk_02025AE0;
    a5 = gUnk_02025C70;
    a6 = gUnk_02025860;
    q = gUnk_02025E00;
    for (; i != 4; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a2;
    for (i = 0; i != 0x18; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a3;
    for (i = 0; i != 0x20; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a4;
    for (i = 0; i != 0x14; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a5;
    for (i = 0; i != 0x10; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a6;
    for (i = 0; i != 0x20; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = q;
    for (i = 0; i != 0x10; i++, p += 3) {
        if (*(u8 *)p == 0)
            *(u32 *)(p + 1) = 0xFFFF;
        else
            (*(u8 *)p)--;
    }
}
