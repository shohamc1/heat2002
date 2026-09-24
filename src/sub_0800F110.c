#include "global.h"

extern u32 gUnk_083FDB98[][2]; /* 0x083FDB98, 8-byte entries */

u32 GetDriverName(u8 r0)
{
    return gUnk_083FDB98[r0][0];
}
