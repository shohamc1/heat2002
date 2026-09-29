#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

struct Task
{
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 timer; /* LinkRaceStartSplashTask compares it signed (ble) */
};

void RaceStartSplashTask(struct Task *e)
{
    u32 *sprite;
    u32 counter;
    u32 attr;
    u32 attr2;
    u8 frame;

    counter = e->timer;
    frame = (u8)e->timer % 0x17;
    e->timer = counter + 1;
    sprite = RequestObjTiles16(gSplashSpriteFrames[frame]);
    if (sprite != 0) {
        register u32 attr asm("r6") = 0x80680040;
        u32 palBits;

        palBits = (RequestObjPalette((u32)gSplashSpritePalette) << 12) | 0x400;
        attr2 = sprite[4] | palBits;
        if (gIsLinkRace == 0)
            AddOamEntry(attr, attr2);
    }
    if (e->timer == 0x30) {
        RemoveTask((u32)e);
        FreeTask((u32)e);
    }
    DrawTextCentered(gText_BlankRowRaceMsg, 8, 1);
}

void LinkRaceStartSplashTask(struct Task *e)
{
    u32 *sprite;
    s32 counter;
    u32 frame;
    u32 attr2;
    u32 palBits;

    counter = e->timer;
    frame = (u8)((u8)e->timer % 0x17);
    e->timer = counter + 1;
    if (e->timer > 0x1E) {
        sprite = RequestObjTiles16(gSplashSpriteFrames[frame]);
        if (sprite != 0) {
            register u32 attr asm("r6") = 0x80680040;

            palBits = (RequestObjPalette((u32)gSplashSpritePalette) << 12) | 0x400;
            attr2 = sprite[4] | palBits;
            if (gIsLinkRace == 0)
                AddOamEntry(attr, attr2);
        }
    }
    if (e->timer == 0x4E) {
        RemoveTask((u32)e);
        FreeTask((u32)e);
        gRaceStarted = 1;
    }
}
