#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

struct EntityB0A0 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ u32 unk18;
};
struct EntityB120 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 unk18;
};


void RaceStartSplashTask(struct EntityB0A0 *e)
{
    u32 *sprite;
    u32 counter;
    u32 attr;
    u32 attr2;
    u8 frame;

    counter = e->unk18;
    frame = (u8)e->unk18 % 0x17;
    e->unk18 = counter + 1;
    sprite = RequestObjTiles16(gSplashSpriteFrames[frame]);
    if (sprite != 0)
    {
        register u32 attr asm("r6") = 0x80680040;
        u32 palBits;

        palBits = (RequestObjPalette((u32)gSplashSpritePalette) << 12) | 0x400;
        attr2 = sprite[4] | palBits;
        if (gIsLinkRace == 0)
            AddOamEntry(attr, attr2);
    }
    if (e->unk18 == 0x30)
    {
        RemoveTask((u32)e);
        FreeTask((u32)e);
    }
    /* DrawTextCentered: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u8 *, u32, u32))DrawTextCentered)(gText_BlankRowRaceMsg, 8, 1);
}


void LinkRaceStartSplashTask(struct EntityB120 *e)
{
    u32 *sprite;
    s32 counter;
    u32 frame;
    u32 attr2;
    u32 palBits;

    counter = e->unk18;
    frame = (u8)((u8)e->unk18 % 0x17);
    e->unk18 = counter + 1;
    if (e->unk18 > 0x1E)
    {
        sprite = RequestObjTiles16(gSplashSpriteFrames[frame]);
        if (sprite != 0)
        {
            register u32 attr asm("r6") = 0x80680040;

            palBits = (RequestObjPalette((u32)gSplashSpritePalette) << 12) | 0x400;
            attr2 = sprite[4] | palBits;
            if (gIsLinkRace == 0)
                AddOamEntry(attr, attr2);
        }
    }
    if (e->unk18 == 0x4E)
    {
        RemoveTask((u32)e);
        FreeTask((u32)e);
        gRaceStarted = 1;
    }
}

