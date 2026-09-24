#include "global.h"

extern u8 gUnk_0200215C;           /* 0x0200215C */
extern u8 gUnk_020020C4;           /* 0x020020C4 */
extern u32 gUnk_0202CC04;          /* 0x0202CC04 */
extern void gUnk_0800B0A1(void);   /* Thumb entry: 0x0800B0A0 | 1 */

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B2C4(void)
{
    u32 r;

    if (gUnk_0200215C == 9)
        gUnk_0200215C = 6;
    if (gUnk_0200215C == 0x0D)
        gUnk_0200215C = 0x0C;
    if (gUnk_0200215C == 0x0E)
        gUnk_0200215C = 2;
    if (gUnk_0200215C == 0x0F)
        gUnk_0200215C = 0x10;
    if (gUnk_0200215C == 0x11)
        gUnk_0200215C = 5;
    gUnk_020020C4 = 1;
    r = AllocTask();
    if (r != 0) {
        *(u32 *)(r + 0x18) = 0;
        *(u32 *)(r + 0x0C) = (u32)gUnk_0800B0A1;
        AddTask(r);
        gUnk_0202CC04 = r;
    }
}
