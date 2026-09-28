#include "global.h"
#include "functions.h"
#include "variables.h"

struct Unk08341A30Ent
{
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
};


struct Unk08341A30Ent *ModuleRequestObjTiles4(u32 a);
u32 ModuleRequestObjPalette(u32 a);
void ModuleAddOamEntry(u32 a, u32 b);

void ModuleDrawLinkMarker(u32 x, u32 y, u32 carIdx)
{
    u32 *frames;
    struct Unk08341A30Ent *sprite;
    u32 attr2;

    frames = gUnk_0202772C[carIdx];
    frames += sub_08344C50(gModule_FrameCounter >> 1, 7);
    y &= 0xFF;
    y |= (x & 0x1FF) << 16;
    y |= 0x40000000;
    sprite = ModuleRequestObjTiles4(*frames);
    if (sprite == 0)
        return;
    attr2 = sprite->field_10;
    attr2 |= (ModuleRequestObjPalette((u32 *)gUnk_020243E8) << 24) >> 12;
    ModuleAddOamEntry(y, attr2);
}
