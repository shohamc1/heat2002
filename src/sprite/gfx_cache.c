#include "global.h"
#include "gba/defines.h"
#include "variables.h"
extern u16 gObjTileCache64Tiles[];
extern u16 gObjTileCache16Tiles[];
extern u16 gObjTileCache2Tiles[];
extern u16 gObjTileCache8Tiles[];
extern u16 gObjTileCache4Tiles[];
extern u16 gObjTileCache1Tiles[];
void sub_08007304(u32 a, u16 *b, u32 *c);

void InitGfxCaches(void)
{
    u32 i;
    u32 color;
    u32 *q;

    {
        u16 *b = gObjTileCache64Tiles;
        u32 *c = gObjTileCache64;
        sub_08007304(4, b, c);
    }
    {
        u16 *b = gObjTileCache16Tiles;
        u32 *c = gObjTileCache16;
        sub_08007304(0x18, b, c);
    }
    {
        u16 *b = gObjTileCache2Tiles;
        u32 *c = gObjTileCache2;
        sub_08007304(0x20, b, c);
    }
    {
        u16 *b = gObjTileCache8Tiles;
        u32 *c = gObjTileCache8;
        sub_08007304(0x14, b, c);
    }
    {
        u16 *b = gObjTileCache4Tiles;
        u32 *c = gObjTileCache4;
        sub_08007304(0x10, b, c);
    }
    {
        u16 *b = gObjTileCache1Tiles;
        u32 *c = gObjTileCache1;
        sub_08007304(0x20, b, c);
    }
    i = 0;
    color = OBJ_PLTT;
    q = gObjPaletteCache;
    for (; i != 0x10; q += 3, i++) {
        sub_080072F4((void *)q);
        *(u32 *)((u8 *)q + 8) = color;
        color += 0x20;
    }
}

void AgeGfxCaches(void)
{
    u32 *p;
    u32 *a2;
    u32 *a3;
    u32 *a4;
    u32 *a5;
    u32 *a6;
    u32 *q;
    u32 i;

    p = gObjTileCache64;
    i = 0;
    a2 = gObjTileCache16;
    a3 = gObjTileCache2;
    a4 = gObjTileCache8;
    a5 = gObjTileCache4;
    a6 = gObjTileCache1;
    q = gObjPaletteCache;
    for (; i != 4; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a2;
    for (i = 0; i != 0x18; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a3;
    for (i = 0; i != 0x20; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a4;
    for (i = 0; i != 0x14; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a5;
    for (i = 0; i != 0x10; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = a6;
    for (i = 0; i != 0x20; i++, p += 5) {
        if (p[0] == 0)
            p[2] = 0xFFFF;
        else
            p[0]--;
    }
    p = q;
    for (i = 0; i != 0x10; i++, p += 3) {
        if (*(u8 *)p == 0)
            *(u32 *)(p + 1) = 0xFFFF;
        else
            (*(u8 *)p)--;
    }
}
