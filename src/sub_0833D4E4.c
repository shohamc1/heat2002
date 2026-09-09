#include "global.h"

extern u8 gUnk_020392C0; /* 0x020392C0 */

void sub_08344B64(u32, u32, u32);

void sub_0833D4E4(void)
{
    if (gUnk_020392C0 != 0) {
        sub_08344B64(0x0203AAD0, 0xA0 << 19, 0x80 << 1);
        gUnk_020392C0 = 0;
    }
}
