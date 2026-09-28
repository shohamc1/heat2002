#include "global.h"
#include "functions.h"

extern u32 gUnk_0202B370[];
extern u8 gUnk_0201F370[];

u32 sub_08341644(s32 x, s32 y, s32 *out);
u32 *ModuleRequestObjTiles16(u32 a);
u32 sub_08343464(s32 x, s32 y);
s32 ModuleRequestObjPalette(u32 a);
u32 ModuleAddOamEntry(u32 a, u32 b);

struct Unk08342FF0
{
    s32 f00;
    s32 f04;
    s32 f08;
    u8 pad0C[0x18 - 0x0C];
    s32 f18;
    s32 f1C;
    u8 pad20[0x28 - 0x20];
    s32 f28;
    u8 pad2C[0x30 - 0x2C];
    s32 f30;
};

struct Unk08342FF0Sprite
{
    u8 pad00[0x10];
    u32 f10;
};

void sub_08342FF0(struct Unk08342FF0 *e)
{
    s32 out[2];
    struct Unk08342FF0Sprite *oam;
    u32 attr;
    u32 t;
    u8 v;
    s32 x0;
    s32 y;
    s32 t18;

    if (((u32)sub_08341644(e->f00, e->f08, out) << 24) != 0)
    {
        x0 = out[0];
        out[0] = x0 - 8;
        y = out[1] - 8;
        out[1] = y + (e->f04 >> 1);
        if ((u32)(x0 + 0x17) <= 0x10E && out[1] <= 0x9F && out[1] > -0x10)
        {
            oam = ModuleRequestObjTiles16(gUnk_0202B370[e->f18 & 0x1F]);
            if (oam != 0)
            {
                v = sub_08343464(e->f00 >> 19, e->f08 >> 19);
                if (v & 1)
                {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    t = ((u8)ModuleRequestObjPalette((u32)gUnk_0201F370) << 12) | 0x800;
                    ModuleAddOamEntry(attr, oam->f10 | t);
                }
                else
                {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    t = ((u8)ModuleRequestObjPalette((u32)gUnk_0201F370) << 12) | 0x400;
                    ModuleAddOamEntry(attr, oam->f10 | t);
                }
            }
        }
    }
    t18 = e->f18 + 1;
    e->f18 = t18;
    e->f04 = e->f04 - e->f1C;
    e->f00 = e->f00 + e->f28;
    e->f08 = e->f08 + e->f30;
    if (t18 == 0x20)
    {
        ModuleRemoveTask((u32)e);
        ModuleFreeTask((u32)e);
    }
}
