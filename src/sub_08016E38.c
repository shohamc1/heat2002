#include "global.h"

extern u32 gUnk_0202F240;
extern u8 gUnk_083393EC[];
extern u8 gUnk_083393F8[];

u32 sub_08016E38(u16 arg0)
{
    u32 r2 = 0;

    if (arg0 == 4) {
        gUnk_0202F240 = (u32)gUnk_083393EC;
    } else if (arg0 == 0x40) {
        gUnk_0202F240 = (u32)gUnk_083393F8;
    } else {
        gUnk_0202F240 = (u32)gUnk_083393EC;
        r2 = 1;
    }
    return r2;
}
