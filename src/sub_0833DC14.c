#include "global.h"

extern u8 gUnk_0203B850[];
extern u8 gUnk_0200CEEC[];
extern u8 gUnk_0200CEF8[];
extern u8 gUnk_0200CF04[];
extern u8 gUnk_0200CF10[];

u8 *sub_0833BD94(u16 a);
void sub_0833EE88(u8 *s, u32 a, u32 b);

void sub_0833DC14(void)
{
    sub_0833EE88(sub_0833BD94(3), 8, 1);

    switch (gUnk_0203B850[0]) {
    case 0:
        sub_0833EE88(gUnk_0200CEEC, 9, 1);
        break;
    case 1:
        sub_0833EE88(gUnk_0200CEF8, 9, 1);
        break;
    case 2:
        sub_0833EE88(gUnk_0200CF04, 9, 1);
        break;
    case 3:
        sub_0833EE88(gUnk_0200CF10, 9, 1);
        break;
    }
}
