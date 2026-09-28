#include "global.h"
#include "variables.h"


u32 SortSpritesByDepth(void)
{
    u8 swapped;
    u32 i;
    u16 a;
    u16 b;
    u8 *ea;
    u8 *eb;

outer:
    swapped = 0;
    i = 0;
    do {
        a = gSpriteOrderTable[i];
        b = gSpriteOrderTable[i + 1];
        ea = gUnk_02024C40 + a * 12;
        eb = gUnk_02024C40 + b * 12;
        if (*(u16 *)(ea + 8) < *(u16 *)(eb + 8)) {
            gSpriteOrderTable[i] = b;
            gSpriteOrderTable[i + 1] = a;
            swapped = 1;
        }
        i++;
    } while (i != 0x3F);
    if (swapped)
        goto outer;
}
