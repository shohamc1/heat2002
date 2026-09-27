#include "global.h"

extern u8 gUnk_0203DE30[];         /* 0x0203DE30 */
extern u8 gUnk_0200D118[];         /* 0x0200D118 */

u32 sub_0833BD94(u16 a);
extern void sub_0833EF0C(u8 *str, u32 a2, u32 a3);
void sub_0833FFA8(u32 a);
void sub_0833FF84(u32 a);

void sub_08342B54(u32 a)
{
    u8 unused[0x28];

    sub_0833EF0C(sub_0833BD94(0x06), 9, 5);
    sub_0833EF0C((u32)gUnk_0203DE30, 0xD, 5);
    if (--*(u32 *)(a + 0x18) == 0)
    {
        sub_0833EF0C((u32)gUnk_0200D118, 9, 5);
        sub_0833FFA8(a);
        sub_0833FF84(a);
    }
}
