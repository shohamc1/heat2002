#include "global.h"
#include "variables.h"
#include "functions.h"

extern u16 gUnk_020215EA[];

void sub_0833E3F8(u16 *dest, u8 idx)
{
    u16 v;

    v = *(idx + gUnk_020215EA);
    *dest = (gModule_FontTileEntries[v] & 0xFFF) | 0xE000;
}

void ModuleAddOamEntry(u32 a, u32 b);

void sub_0833E428(u32 x, u32 pal, u32 tiles, u32 a, u32 b)
{
    u32 arr[8];
    u32 *p;
    u32 i;

    arr[1] = 10;
    arr[4] = 10;
    arr[0] = tiles;
    arr[3] = sub_08344C50(a, 10);
    arr[2] = sub_08344BB8(a, 10);
    arr[6] = sub_08344BB8(sub_08344C50(b, 100), 10);
    arr[5] = sub_08344BB8(b, 100);
    arr[7] = 0;
    i = 0;
    pal &= 0xFF;
    p = arr;
    do {
        ModuleAddOamEntry(((x & 0x1FF) << 0x10) | pal, (*p++ + 0x3D4) | 0x3000);
        x += 4;
        i++;
    } while (i != 8);
}

extern u8 gUnk_0203B700[];


void sub_0833E4A4(void)
{
    u8 *d;
    s32 v;
    s32 w;

    d = gUnk_0203B700;
    v = (*(s32 *)&gModule_CountdownSeconds);
    d[1] = sub_08344C50(v, 10);
    d[0] = sub_08344BB8(v, 10);
    sub_0833E36C((u16 *)(gModule_TextLayerMapPtr[0] + 0x82), d[0]);
    sub_0833E36C((u16 *)(gModule_TextLayerMapPtr[0] + 0x86), d[1]);
    w = (*(s32 *)&gModule_CountdownMs);
    d[1] = sub_08344C50(sub_08344BB8(w, 10), 10);
    d[0] = sub_08344BB8(w, 100);
    sub_0833E3C8((u16 *)(gModule_TextLayerMapPtr[0] + 0xCA), 10);
    sub_0833E3C8((u16 *)(gModule_TextLayerMapPtr[0] + 0xCC), d[0]);
    sub_0833E3C8((u16 *)(gModule_TextLayerMapPtr[0] + 0xCE), d[1]);
}
