#include "global.h"
#include "variables.h"

struct Thing {
    u8 pad00[0x10];
    u32 unk10;
};

struct Car {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    u8 pad0C[0x34 - 0x0C];
    u16 unk34;
    u8 pad36[0x7D - 0x36];
    u8 finished;
    u8 pad7E[0x162 - 0x7E];
    u8 unk162;
    u8 pad163[0x172 - 0x163];
    u8 behindBgFlag;
    u8 pad173[0x190 - 0x173];
};

extern u32 *gUnk_02026E14[];
extern u32 *gUnk_02026E18[];
extern u32 *gUnk_0202773C[];
extern u8 gUnk_0201B590[];

u32 ModuleAddDepthSortedSprite(u32 a, u32 b, u32 c);
struct Thing *ModuleRequestObjTiles16(u32 a);
struct Thing *ModuleRequestObjTiles2(u32 a);
struct Thing *ModuleRequestObjTiles8(u32 a);
struct Thing *ModuleRequestObjTiles4(u32 a);
u8 ModuleRequestObjPalette(u32 a);
u32 sub_08341644(s32 x, s32 y, s32 *out);

void sub_083416DC(struct Car *car, u8 idx)
{
    s32 pos[2];
    struct Thing *t;
    u32 t5;
    u16 y;
    u8 flip;
    s32 k;
    u32 *row;

    if ((u8)sub_08341644(car->unk00, car->unk08, pos) == 0)
        return;
    y = pos[1];
    pos[0] -= 0x18;
    pos[1] -= 0x10;
    if (car->finished != 0 && gModule_IsLinkRace != 0 && (gModule_FrameCounter & 8) != 0)
        return;
    k = (car->unk34 + 0x200) >> 10;
    k += 0x28;
    k &= 0x3F;
    flip = k & 0x20;
    k &= 0x1F;
    if (flip != 0)
        k = 0x20 - k;
    t5 = (u32)(ModuleRequestObjPalette(gUnk_02026E1C[car->unk162]) << 24) >> 12;
    if (car->behindBgFlag != 0)
        t5 |= 0x800;
    else
        t5 |= 0x400;
    if (flip == 0) {
        t = ModuleRequestObjTiles8(gUnk_02026E14[car->unk162][k]);
        if (t != NULL) {
            ModuleAddDepthSortedSprite((pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80008000,
                         t->unk10 | t5, (u16)(y + 0x40));
        }
        t = ModuleRequestObjTiles16(gUnk_02026E18[car->unk162][k]);
        if (t != NULL) {
            ModuleAddDepthSortedSprite((pos[1] & 0xFF) | (((pos[0] + 0x10) & 0x1FF) << 16) | 0x80000000,
                         t->unk10 | t5, (u16)(y + 0x40));
        }
    } else {
        u8 *p162;
        register u32 a asm("r4");
        u32 b;
        u32 **tbl;

        tbl = gUnk_02026E18;
        p162 = &car->unk162;
        t = ModuleRequestObjTiles16(tbl[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80000000;
            b = t->unk10 | t5;
            a |= 0x10000000;
            ModuleAddDepthSortedSprite(a, b, (u16)(y + 0x40));
        }
        t = ModuleRequestObjTiles8(gUnk_02026E14[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | (((pos[0] + 0x20) & 0x1FF) << 16) | 0x80008000;
            b = t->unk10 | t5;
            a |= 0x10000000;
            ModuleAddDepthSortedSprite(a, b, (u16)(y + 0x40));
        }
    }
    if (gModule_IsLinkRace != 0) {
        row = gUnk_0202772C[idx];
        row += (gModule_FrameCounter >> 1) % 7;
        pos[1] -= 0xC;
        pos[0] += 0x10;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x40000000;
        t = ModuleRequestObjTiles4(*row);
        if (t == NULL)
            return;
        t5 = t->unk10 | 0x400;
        t5 |= (u32)(ModuleRequestObjPalette(gUnk_020243E8) << 24) >> 12;
        ModuleAddDepthSortedSprite(k, t5, (u16)(y + 0x40));
    } else {
        row = gUnk_0202773C[car->unk162];
        pos[1] -= 8;
        pos[0] += 0x10;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x4000;
        t = ModuleRequestObjTiles2(*row);
        if (t == NULL)
            return;
        t5 = t->unk10 | 0x400;
        t5 |= (u32)(ModuleRequestObjPalette(gUnk_0201B590) << 24) >> 12;
        ModuleAddDepthSortedSprite(k, t5, (u16)(y + 0x40));
    }
}
