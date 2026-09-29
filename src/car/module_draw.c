#include "global.h"
#include "variables.h"
#include "car.h"

struct Thing
{
    u8 pad00[0x10];
    u32 unk10;
};
extern u32 *gUnk_02026E14[];
extern u32 *gUnk_02026E18[];
extern u32 *gUnk_0202773C[];
extern u8 gUnk_0201B590[];
u32 ModuleAddDepthSortedSprite(u32 a, u32 b, u16 c);
struct Thing *ModuleRequestObjTiles16(u32 a);
struct Thing *ModuleRequestObjTiles2(u32 a);
struct Thing *ModuleRequestObjTiles8(u32 a);
struct Thing *ModuleRequestObjTiles4(u32 a);
u8 ModuleRequestObjPalette(u32 a);
u8 ModuleWorldToScreen(s32 x, s32 y, s32 *out);

void ModuleDrawCar(struct Car *car, u8 idx)
{
    s32 pos[2];
    struct Thing *t;
    u32 t5;
    u16 y;
    u8 flip;
    s32 k;
    u32 *row;

    if (ModuleWorldToScreen(car->posX, car->posZ, pos) == 0)
        return;
    y = pos[1];
    pos[0] -= 0x18;
    pos[1] -= 0x10;
    if (car->finished != 0 && gModule_IsLinkRace != 0 && (gModule_FrameCounter & 8) != 0)
        return;
    k = (car->heading + 0x200) >> 10;
    k += 0x28;
    k &= 0x3F;
    flip = k & 0x20;
    k &= 0x1F;
    if (flip != 0)
        k = 0x20 - k;
    t5 = (u32)(ModuleRequestObjPalette(gUnk_02026E1C[car->driverId]) << 24) >> 12;
    if (car->behindBgFlag != 0)
        t5 |= 0x800;
    else
        t5 |= 0x400;
    if (flip == 0) {
        t = ModuleRequestObjTiles8(gUnk_02026E14[car->driverId][k]);
        if (t != NULL) {
            ModuleAddDepthSortedSprite((pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80008000, t->unk10 | t5,
                                       y + 0x40);
        }
        t = ModuleRequestObjTiles16(gUnk_02026E18[car->driverId][k]);
        if (t != NULL) {
            ModuleAddDepthSortedSprite((pos[1] & 0xFF) | (((pos[0] + 0x10) & 0x1FF) << 16) | 0x80000000, t->unk10 | t5,
                                       y + 0x40);
        }
    } else {
        u8 *p162;
        register u32 a asm("r4");
        u32 b;
        u32 **tbl;

        tbl = gUnk_02026E18;
        p162 = &car->driverId;
        t = ModuleRequestObjTiles16(tbl[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80000000;
            b = t->unk10 | t5;
            a |= 0x10000000;
            ModuleAddDepthSortedSprite(a, b, y + 0x40);
        }
        t = ModuleRequestObjTiles8(gUnk_02026E14[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | (((pos[0] + 0x20) & 0x1FF) << 16) | 0x80008000;
            b = t->unk10 | t5;
            a |= 0x10000000;
            ModuleAddDepthSortedSprite(a, b, y + 0x40);
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
        ModuleAddDepthSortedSprite(k, t5, y + 0x40);
    } else {
        row = gUnk_0202773C[car->driverId];
        pos[1] -= 8;
        pos[0] += 0x10;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x4000;
        t = ModuleRequestObjTiles2(*row);
        if (t == NULL)
            return;
        t5 = t->unk10 | 0x400;
        t5 |= (u32)(ModuleRequestObjPalette(gUnk_0201B590) << 24) >> 12;
        ModuleAddDepthSortedSprite(k, t5, y + 0x40);
    }
}

void ModuleDrawAllCars(void)
{
    u32 i;
    u32 limit;
    struct Car *p;

    limit = gModule_NumCars[0];
    if (gModule_IsLinkRace != 0)
        limit = gModule_NumLinkPlayers[0];
    p = gModule_Cars;
    for (i = 0; i != limit; i++, p++) {
        if (gModule_GameMode[0] != 2 || i == 0)
            ModuleDrawCar(p, i);
    }
}
