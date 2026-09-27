#include "global.h"

extern u8 gUnk_020020C4;           /* 0x020020C4 */
extern u8 gUnk_020021E0;           /* 0x020021E0 */
extern u8 gUnk_0200215C[];           /* 0x0200215C */
extern u32 gUnk_0202CC04;          /* 0x0202CC04 */
void sub_0800B120(void);

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B334(void)
{
    u32 r;

    gUnk_020020C4 = 0;
    gUnk_020021E0 = 0;
    if (gUnk_0200215C[0] == 3 || gUnk_0200215C[0] == 4) {
        r = AllocTask();
        if (r != 0) {
            *(u32 *)(r + 0x18) = 0;
            *(u32 *)(r + 0x0C) = (u32)sub_0800B120;
            AddTask(r);
            gUnk_0202CC04 = r;
        }
    }
}
