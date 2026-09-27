#include "global.h"
#include "gba/defines.h"
#include "variables.h"

extern u32 gObjTileCache64Tiles[];
extern u32 gObjTileCache16Tiles[];
extern u32 gObjTileCache2Tiles[];
extern u32 gObjTileCache8Tiles[];
extern u32 gObjTileCache4Tiles[];
extern u32 gObjTileCache1Tiles[];

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
