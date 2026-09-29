#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

struct Car
{
    s32 posX;
    s32 unk04;
    s32 posZ;
    u8 pad0C[0x34 - 0x0C];
    u16 heading;
    u8 pad36[0x7D - 0x36];
    u8 finished;
    u8 pad7E[0x162 - 0x7E];
    u8 driverId;
    u8 pad163[0x172 - 0x163];
    u8 behindBgFlag;
    u8 pad173[0x190 - 0x173];
};

extern u32 *gDriverCarSpriteHalfATables[];
extern u32 *gDriverCarSpriteHalfBTables[];
extern const u32 *const gDriverNumberFrameLists[];
extern u8 gDriverNumberPalette[];

u32 AddDepthSortedSprite(u32 a, u32 b, u16 c);
u32 WorldToScreen(s32 x, s32 y, s32 *out);

void DrawCar(struct Car *car, u8 idx)
{
    s32 pos[2];
    struct ObjTileCacheEntry *t;
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
    if (car->finished != 0 && gIsLinkRace != 0 && (gFrameCounter & 8) != 0)
        return;
    k = (car->heading + 0x200) >> 10;
    k += 0x28;
    k &= 0x3F;
    flip = k & 0x20;
    k &= 0x1F;
    if (flip != 0)
        k = 0x20 - k;
    t5 = (u32)(RequestObjPalette((u32)gDriverPalettes[car->driverId]) << 24) >> 12;
    if (car->behindBgFlag != 0)
        t5 |= 0x800;
    else
        t5 |= 0x400;
    if (flip == 0) {
        t = RequestObjTiles8(gDriverCarSpriteHalfATables[car->driverId][k]);
        if (t != NULL) {
            AddDepthSortedSprite((pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80008000, t->tileIndex | t5, y + 0x40);
        }
        t = RequestObjTiles16(gDriverCarSpriteHalfBTables[car->driverId][k]);
        if (t != NULL) {
            AddDepthSortedSprite((pos[1] & 0xFF) | (((pos[0] + 0x10) & 0x1FF) << 16) | 0x80000000, t->tileIndex | t5,
                                 y + 0x40);
        }
    } else {
        u8 *p162;
        register u32 a asm("r4");
        u32 b;
        const u32 *const *tbl;

        tbl = gDriverCarSpriteHalfBTables;
        p162 = &car->driverId;
        t = RequestObjTiles16(tbl[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x80000000;
            b = t->tileIndex | t5;
            a |= 0x10000000;
            AddDepthSortedSprite(a, b, y + 0x40);
        }
        t = RequestObjTiles8(gDriverCarSpriteHalfATables[*p162][k]);
        if (t != NULL) {
            a = (pos[1] & 0xFF) | (((pos[0] + 0x20) & 0x1FF) << 16) | 0x80008000;
            b = t->tileIndex | t5;
            a |= 0x10000000;
            AddDepthSortedSprite(a, b, y + 0x40);
        }
    }
    if (gIsLinkRace != 0) {
        row = (u32 *)gLinkMarkerFrameLists[idx];
        row += sub_080172C8(gFrameCounter >> 1, 7);
        pos[1] -= 0xC;
        pos[0] += 0x10;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x40000000;
        t = RequestObjTiles4(*row);
        if (t == NULL)
            return;
        t5 = t->tileIndex | 0x400;
        t5 |= (u32)(RequestObjPalette((u32)gLinkMarkerPalette) << 24) >> 12;
        AddDepthSortedSprite(k, t5, y + 0x40);
    } else {
        row = (u32 *)gDriverNumberFrameLists[car->driverId];
        pos[1] -= 8;
        pos[0] += 0x10;
        k = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 16) | 0x4000;
        t = RequestObjTiles2(*row);
        if (t == NULL)
            return;
        t5 = t->tileIndex | 0x400;
        t5 |= (u32)(RequestObjPalette((u32)gDriverNumberPalette) << 24) >> 12;
        AddDepthSortedSprite(k, t5, y + 0x40);
    }
}
