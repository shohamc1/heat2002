#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

extern u16 gUnk_08334E22[];

void sub_080058FC(u16 *dest, u8 idx)
{
    u16 v;

    v = *(idx + gUnk_08334E22);
    *dest = (gFontTileEntries[v] & 0xFFF) | 0xE000;
}

void sub_0800592C(u32 x, u32 pal, u32 tiles, u32 a, u32 b)
{
    u32 arr[8];
    u32 *p;
    u32 i;

    arr[1] = 10;
    arr[4] = 10;
    arr[0] = tiles;
    arr[3] = sub_080172C8(a, 10);
    arr[2] = sub_08017230(a, 10);
    arr[6] = sub_08017230(sub_080172C8(b, 100), 10);
    arr[5] = sub_08017230(b, 100);
    arr[7] = 0;
    i = 0;
    pal &= 0xFF;
    p = arr;
    do {
        AddOamEntry(((x & 0x1FF) << 0x10) | pal, (*p++ + 0x3D4) | 0x3000);
        x += 4;
        i++;
    } while (i != 8);
}

extern u8 gUnk_0202525C[];


void sub_080059A8(void)
{
    u8 *d;
    s32 v;
    s32 w;

    d = gUnk_0202525C;
    v = gCountdownSeconds;
    d[1] = sub_080172C8(v, 10);
    d[0] = sub_08017230(v, 10);
    DrawBigDigit((u16 *)((u8 *)(gTextLayerMapPtr[0] + 0x82)), d[0]);
    DrawBigDigit((u16 *)((u8 *)(gTextLayerMapPtr[0] + 0x86)), d[1]);
    w = (*(s32 *)&gCountdownMs);
    d[1] = sub_080172C8(sub_08017230(w, 10), 10);
    d[0] = sub_08017230(w, 100);
    DrawSmallDigit((u16 *)((u8 *)(gTextLayerMapPtr[0] + 0xCA)), 10);
    DrawSmallDigit((u16 *)((u8 *)(gTextLayerMapPtr[0] + 0xCC)), d[0]);
    DrawSmallDigit((u16 *)((u8 *)(gTextLayerMapPtr[0] + 0xCE)), d[1]);
}
