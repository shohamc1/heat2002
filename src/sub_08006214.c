#include "global.h"
#include "data.h"
#include "variables.h"


void sub_08006214(void)
{
    u16 *dst;
    u8 i;
    u8 j;
    u32 off;

    dst = (*(u16 **)&gTextLayerMapPtr) + 0x1D4;
    i = 0;
    do {
        j = 0;
        do {
            off = 2 * ((i + 8) * 68 + j + 0x33);
            *dst++ = gFontTileEntries[*(u16 *)((u8 *)gFontGlyphGrid + off)] | 0xE000;
            j++;
        } while (j != 10);
        dst += 0x16;
        i++;
    } while (i != 6);
    dst = (*(u16 **)&gTextLayerMapPtr) + 0x1D4;
    if (gDamagePitsEnabled == 0) {
        i = 0;
        do {
            j = 0;
            do {
                *dst++ = 0x47;
                j++;
            } while (j != 4);
            dst += 0x1C;
            i++;
        } while (i != 6);
    }
}
