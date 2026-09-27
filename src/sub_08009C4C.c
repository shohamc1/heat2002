#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

struct Thing {
    u8 pad00[0x10];
    u32 unk10;
};

struct Car {
    s32 posX;
    s32 unk04;
    s32 posZ;
    u8 pad0C[0x34 - 0x0C];
    u16 heading;
    u8 pad36[0x7D - 0x36];
    u8 unk7D;
    u8 pad7E[0x162 - 0x7E];
    u8 driverId;
    u8 pad163[0x172 - 0x163];
    u8 unk172;
    u8 pad173[0x190 - 0x173];
};

extern s32 gUnk_0200209C;
extern u32 *gUnk_08367640[];
extern u32 *gUnk_083676B8[];
extern u32 *gUnk_083681E8[];
extern u32 *gUnk_083681F8[];
extern u8 gUnk_0831D0EC[];

u32 AddDepthSortedSprite(u32 a, u32 b, u32 c);
struct Thing *sub_08007598(u32 a);
struct Thing *sub_080075E4(u32 a);
u32 WorldToScreen(s32 x, s32 y, s32 *out);

void DrawCar(struct Car *car, u8 idx)
{
    s32 pos[2];
    struct Thing *t;
    u32 t5;
    u16 y;
    u8 flip;
    s32 k;
    u32 *row;

    if ((u8)WorldToScreen(car->posX, car->posZ, pos) == 0)
        return;
    y = pos[1];
    pos[0] -= 0x18;
    pos[1] -= 0x10;
    if (car->unk7D != 0 && gIsLinkRace != 0 && (gUnk_0200209C & 8) != 0)
        return;
    k = (car->heading + 0x200) >> 10;
    k += 0x28;
    k &= 0x3F;
    flip = k & 0x20;
    k &= 0x1F;
    if (flip != 0)
        k = 0x20 - k;
    t5 = (u32)(RequestObjPalette((u32)gUnk_08367730[car->driverId]) << 24) >> 12;
    if (car->unk172 != 0)
        t5 |= 0x800;
    else
        t5 |= 0x400;
    if (flip == 0) {
        t = sub_080075E4(gUnk_08367640[car->driverId][k]);
        if (t != NULL) {
            AddDepthSortedSprite((pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80008000,
                         t->unk10 | t5, (u16)(y + 0x40));
        }
        t = sub_0800754C(gUnk_083676B8[car->driverId][k]);
        if (t != NULL) {
            AddDepthSortedSprite((pos[1] & 0xFF) | (((pos[0] + 0x10) & 0x1FF) << 16) | 0x80000000,
                         t->unk10 | t5, (u16)(y + 0x40));
        }
    } else {
        u8 *p162;
        register u32 a asm("r4");
        u32 b;
        u32 **tbl;

        tbl = gUnk_083676B8;
        p162 = &car->driverId;
        t = sub_0800754C(tbl[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80000000;
            b = t->unk10 | t5;
            a |= 0x10000000;
            AddDepthSortedSprite(a, b, (u16)(y + 0x40));
        }
        t = sub_080075E4(gUnk_08367640[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | (((pos[0] + 0x20) & 0x1FF) << 16) | 0x80008000;
            b = t->unk10 | t5;
            a |= 0x10000000;
            AddDepthSortedSprite(a, b, (u16)(y + 0x40));
        }
    }
    if (gIsLinkRace != 0) {
        row = gUnk_083681E8[idx];
        row += sub_080172C8(gUnk_0200209C >> 1, 7);
        pos[1] -= 0xC;
        pos[0] += 0x10;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x40000000;
        t = sub_08007630(*row);
        if (t == NULL)
            return;
        t5 = t->unk10 | 0x400;
        t5 |= (u32)(RequestObjPalette((u32)gUnk_08337C20) << 24) >> 12;
        AddDepthSortedSprite(k, t5, (u16)(y + 0x40));
    } else {
        row = gUnk_083681F8[car->driverId];
        pos[1] -= 8;
        pos[0] += 0x10;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x4000;
        t = sub_08007598(*row);
        if (t == NULL)
            return;
        t5 = t->unk10 | 0x400;
        t5 |= (u32)(RequestObjPalette((u32)gUnk_0831D0EC) << 24) >> 12;
        AddDepthSortedSprite(k, t5, (u16)(y + 0x40));
    }
}
