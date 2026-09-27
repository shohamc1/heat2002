#include "global.h"
#include "data.h"

extern u16 gUnk_08334E22[];

void sub_080058FC(u16 *dest, u8 idx)
{
    u16 v;

    v = *(idx + gUnk_08334E22);
    *dest = (gFontTileEntries[v] & 0xFFF) | 0xE000;
}
