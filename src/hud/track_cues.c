#include "global.h"
#include "car.h"
#include "functions.h"
#include "variables.h"

struct ObjTileCacheEntry
{
    u8 pad00[0x10]; /* age, pending, unk05-07, gfx, vramDest */
    u32 tileIndex;  /* OAM attr2 base: tile number, OR'd with palette/priority at each use */
};

extern const u8 *const gTrackCueIconGfxList[];
extern u8 gTrackCueIconPalette[];
extern u32 gUnk_0836524C[];
extern u16 gUnk_020251F8;
extern u16 gUnk_02025254;
void DrawTrackCueIcon(u8 a, u16 b);

void DrawTrackCueIcon(u8 cueId, u16 angle)
{
    u16 cmd[2];
    u32 *tileEntry;
    u32 attr;
    u32 attr2;
    u8 hFlip;
    u8 vFlip;
    register u8 zero asm("r10");
    u16 zero2;
    u16 *cmdPtr;
    if (angle != 0) {
        gUnk_020251F0 = angle;
        cmdPtr = cmd;
        zero = 0;
        zero2 = 0;
        cmdPtr[0] = 0x68;
        cmd[1] = zero2;
        tileEntry = RequestObjTiles16(gTrackCueIconGfxList[cueId & 7]);
        hFlip = (cueId & 8) >> 3;
        vFlip = (cueId & 0x10) >> 4;
        if (tileEntry == 0) {
            return;
        }
        gUnk_020251F0 = angle;
        attr = ((cmd[1] & 0xFF) | ((cmd[0] & 0x1FF) << 16)) | 0x80000000;
        attr2 =
            ((struct ObjTileCacheEntry *)tileEntry)->tileIndex | (RequestObjPalette((u32)gTrackCueIconPalette) << 12);
        attr |= 0x04000100;
        gUnk_0202523C = zero;
        gUnk_020253C8 = zero;
        if (hFlip != 0) {
            gUnk_0202523C = 1;
        }
        if (vFlip != 0) {
            gUnk_020253C8 = 1;
        }
        AddOamEntry(attr, attr2);
    } else {
        cmd[0] = 0x68;
        cmd[1] = angle;
        tileEntry = RequestObjTiles16(gTrackCueIconGfxList[cueId & 7]);
        hFlip = (cueId & 8) >> 3;
        vFlip = (cueId & 0x10) >> 4;
        if (tileEntry == 0) {
            return;
        }
        attr = ((cmd[1] & 0xFF) | ((cmd[0] & 0x1FF) << 16)) | 0x80000000;
        attr2 =
            ((struct ObjTileCacheEntry *)tileEntry)->tileIndex | (RequestObjPalette((u32)gTrackCueIconPalette) << 12);
        if (hFlip != 0) {
            attr |= 0x10000000;
        }
        if (vFlip != 0) {
            attr |= 0x20000000;
        }
        AddOamEntry(attr, attr2);
    }
}

void LoadTrackCues(u8 trackIdx)
{
    gUnk_02025244 = 1;
    gTrackCueList = gUnk_0836524C[trackIdx];
    (*(s8 *)&gTrackCueId) = -1;
    if (gTrackCueList == 0)
        gUnk_02025244 = gTrackCueList;
}

void UpdateTrackCues(u32 car)
{
    u8 pad[0x28];
    u8 *cueRecord;
    u32 progress;
    u32 cueEnd;

    if (gUnk_02025244 == 0)
        return;
    cueRecord = (u8 *)((struct Car *)car)->trackCueCursor;
    progress = (u32)((struct Car *)car)->progress & 0xFFFF;
    cueEnd = gUnk_02025254;
    if (progress <= cueEnd || cueEnd == 0) {
        if (*(s8 *)&gTrackCueId != -1 && gRaceEndState == 0)
            DrawTrackCueIcon(gTrackCueId, gUnk_020251F8);
    }
    progress = (u32)((struct Car *)car)->progress & 0xFFFF;
    if (progress >= *(u16 *)cueRecord) {
        do {
            gTrackCueId = cueRecord[2];
            gUnk_020251F8 = *(u16 *)(cueRecord + 4);
            gUnk_02025254 = *(u16 *)(cueRecord + 6);
            cueRecord += 8;
            ((struct Car *)car)->trackCueCursor = (u32)cueRecord;
        } while (progress >= *(u16 *)cueRecord);
    }
}
