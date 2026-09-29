#include "global.h"

struct EntityB658;
struct EntityB7E0;
struct Unk0800B8EC;

void DraftStreakTask(struct EntityB658 *);
u32 AllocTask(void);
void AddTask(u32 a);
#include "data.h"
#include "functions.h"
#include "car.h"
struct EntityB658
{
    u8 pad00[0x08];
    s32 unk08;
    u8 pad0C[0x18 - 0x0C];
    s32 unk18;
    s32 unk1C;
    u8 pad20[0x34 - 0x20];
    u8 unk34;
};
extern const u8 *const gDraftStreakFrames[];
extern u8 gDraftStreakPalette[];
u32 WorldToScreen(s32 x, s32 y, s32 *out);
u32 *RequestObjTiles1Compressed(u32 a);
void SkidSmokeTask(struct EntityB7E0 *);
struct EntityB7E0
{
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x18 - 0x0C];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x28 - 0x1C];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ s32 unk30;
};
extern const u8 *const gSkidSmokeFrames[]; /* 0x083FF60C */
extern u8 gSkidSmokePalette[];             /* 0x08330D18 */
void DamageSmokeTask(struct Unk0800B8EC *);
extern const u8 *const gDamageSmokeFrames[];
extern u8 gDamageSmokePalettes[];
u32 GetTrackTileType(s32 x, s32 y);
struct Unk0800B8EC
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
struct Unk0800B8ECSprite
{
    u8 pad00[0x10];
    u32 f10;
};

void DummyWallHitHook(void)
{}

void AddDraftStreakTask(u8 carIdx, u8 cornerIdx)
{
    u32 task;

    task = AllocTask();
    if (task != 0) {
        *(u32 *)(task + 0x18) = 0;
        *(u8 *)(task + 0x34) = carIdx;
        *(u32 *)(task + 0x20) = 2;
        *(u32 *)(task + 0x00) = 0;
        *(u32 *)(task + 0x04) = 0;
        *(u32 *)(task + 0x08) = 0x80000;
        *(u32 *)(task + 0x1C) = cornerIdx;
        *(u32 *)(task + 0x0C) = (u32)DraftStreakTask;
        AddTask(task);
    }
}

void DraftStreakTask(struct EntityB658 *e)
{
    struct Car *car;
    s32 pos[2];
    s32 cornerX;
    s32 cornerZ;
    s32 angle;
    s32 sin;
    s32 cos;
    s32 rel;
    s32 dx;
    s32 dy;
    u32 *sprite;
    u32 attr;
    u32 palBits;
    u32 attr2;
    s32 screenX;
    car = &gCars[e->unk34];
    cornerX = car->nextCornerX[e->unk1C + 2];
    cornerZ = car->nextCornerZ[e->unk1C + 2];
    angle = car->heading >> 8;
    sin = gSinTable[angle];
    cos = gSinTable[angle + 0x40];
    rel = (dy = e->unk08 + 0xFFF60000);
    dx = (-(rel * sin)) >> 8;
    dy = (dy * cos) >> 8;
    cornerX = cornerX + dx;
    cornerZ = cornerZ + dy;
    if ((WorldToScreen(cornerX, cornerZ, pos) << 0x18) != 0) {
        screenX = pos[0];
        pos[0] = screenX - 4;
        pos[1] = pos[1] - 6;
        if (((((u32)(screenX + 0x1B)) <= 0x10E) && (pos[1] <= 0x9F)) && (pos[1] > (-0x20))) {
            sprite = RequestObjTiles1Compressed(gDraftStreakFrames[e->unk18 & 0xF]);
            if (sprite != 0) {
                attr = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 0x10);
                palBits = (RequestObjPalette((u32)gDraftStreakPalette) << 12) | 0x800;
                attr2 = sprite[4] | palBits;
                AddOamEntry(attr, attr2);
            }
        }
    }
    e->unk18 = e->unk18 + 1;
    e->unk08 = e->unk08 + 0x10000;
    if (e->unk18 == 0x10) {
        RemoveTask((u32)e);
        FreeTask((u32)e);
    }
}

void AddSkidSmokeTask(u8 carIdx, u8 cornerIdx)
{
    u32 task;
    u32 cornerX, cornerZ;
    struct Car *car;

    task = AllocTask();
    if (task != 0) {
        car = &gCars[carIdx];
        *(u32 *)(task + 0x18) = 0;
        *(u8 *)(task + 0x34) = carIdx;
        *(u32 *)(task + 0x1C) = cornerIdx;
        *(u32 *)(task + 0x20) = 2;
        cornerX = car->nextCornerX[cornerIdx];
        *(u32 *)(task + 0x00) = cornerX;
        *(u32 *)(task + 0x04) = 0;
        cornerZ = car->nextCornerZ[cornerIdx];
        *(u32 *)(task + 0x08) = cornerZ;
        *(u32 *)(task + 0x28) = cornerX - car->cornerX[cornerIdx];
        *(u32 *)(task + 0x30) = cornerZ - car->cornerZ[cornerIdx];
        *(u32 *)(task + 0x0C) = (u32)SkidSmokeTask;
        AddTask(task);
    }
}

void SkidSmokeTask(struct EntityB7E0 *e)
{
    s32 pos[2];
    u32 *sprite;
    u32 attr;
    u32 palBits;
    u32 attr2;
    s32 screenX;
    s32 riseY;

    if ((WorldToScreen(e->unk00, e->unk08, pos) << 0x18) != 0) {
        screenX = pos[0];
        pos[0] = screenX - 4;
        riseY = pos[1] - 4;
        pos[1] = riseY + (e->unk04 >> 2);
        if ((u32)(screenX + 0x1B) <= 0x10E && pos[1] <= 0x9F && pos[1] > -0x20) {
            sprite = RequestObjTiles1Compressed(gSkidSmokeFrames[((e->unk18 + 8) & 7) + 8]);
            if (sprite != 0) {
                attr = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 0x10);
                palBits = (RequestObjPalette((u32)gSkidSmokePalette) << 12) | 0x800;
                attr2 = sprite[4] | palBits;
                AddOamEntry(attr, attr2);
            }
        }
    }
    e->unk18 = e->unk18 + 2;
    e->unk04 = e->unk04 - 1;
    e->unk00 = e->unk00 + (e->unk28 >> 1);
    e->unk08 = e->unk08 + (e->unk30 >> 1);
    if (e->unk18 == 0x10) {
        RemoveTask((u32)e);
        FreeTask((u32)e);
    }
}

void AddDamageSmokeTask(s32 *car)
{
    u32 task;

    task = AllocTask();
    if (task != 0) {
        *(u32 *)(task + 0x18) = 0;
        *(u32 *)(task + 0x1C) = 2;
        *(u32 *)(task + 0x00) = car[0];
        *(u32 *)(task + 0x04) = -6;
        *(u32 *)(task + 0x08) = car[2];
        *(u32 *)(task + 0x28) = car[3] >> 1;
        *(u32 *)(task + 0x30) = car[5] >> 1;
        *(u32 *)(task + 0x0C) = (u32)DamageSmokeTask;
        AddTask(task);
    }
}

void DamageSmokeTask(struct Unk0800B8EC *e)
{
    s32 out[2];
    struct Unk0800B8ECSprite *sprite;
    u32 attr;
    u32 palBits;
    u8 tileType;
    s32 screenX;
    s32 screenY;
    s32 frame;

    if (((u32)WorldToScreen(e->f00, e->f08, out) << 24) != 0) {
        screenX = out[0];
        out[0] = screenX - 8;
        screenY = out[1] - 8;
        out[1] = screenY + (e->f04 >> 1);
        if ((u32)(screenX + 0x17) <= 0x10E && out[1] <= 0x9F && out[1] > -0x10) {
            sprite = RequestObjTiles16(gDamageSmokeFrames[e->f18 & 0x1F]);
            if (sprite != 0) {
                tileType = GetTrackTileType(e->f00 >> 19, e->f08 >> 19);
                if (tileType & 1) {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    palBits = ((u8)RequestObjPalette((u32)gDamageSmokePalettes) << 12) | 0x800;
                    AddOamEntry(attr, sprite->f10 | palBits);
                } else {
                    attr = (out[1] & 0xFF) | ((out[0] & 0x1FF) << 16) | 0x40000000;
                    palBits = ((u8)RequestObjPalette((u32)gDamageSmokePalettes) << 12) | 0x400;
                    AddOamEntry(attr, sprite->f10 | palBits);
                }
            }
        }
    }
    frame = e->f18 + 1;
    e->f18 = frame;
    e->f04 = e->f04 - e->f1C;
    e->f00 = e->f00 + e->f28;
    e->f08 = e->f08 + e->f30;
    if (frame == 0x20) {
        RemoveTask((u32)e);
        FreeTask((u32)e);
    }
}
