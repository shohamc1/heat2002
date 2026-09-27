#include "global.h"
#include "tilemap.h"
#include "gba/compat.h"
#include "functions.h"
#include "variables.h"

extern u16 gUnk_02002220[];
extern u16 gUnk_0200BC70[];
extern u16 gUnk_02015690[];
extern u32 gUnk_02022DD8;
extern u32 gUnk_02022DF0;
extern u32 gUnk_0201567C;
extern u16 gUnk_08335C60[];
extern u16 gUnk_08334BCC[];

/* struct Track and gTrackData come from include/structs.h via
   variables.h. */

void LoadTrackTiles(u8 idx);
void BeginFadeToBrightenedPalette(s32 arg0, u16 *src);
void RleDecode16(u16 *src, u16 *dst, u16 count);
void FlushTrackBgBuffers(void);
void SetCameraPos(u32 x, u32 y);
void InitRaceCars(u32 idx);
void ResetRaceTimer(void);

void LoadTrack(u32 idx)
{
    u16 a[0xE0];
    u16 b[0x20];
    u16 *t;

    LoadTrackTiles(idx);
    t = gUnk_08335C60;
    CpuCopy16(t, BG_SCREEN_ADDR(24), 0x2000);
    CpuCopy16(gTrackData[idx].unk18, (u32)a, 0x200);
    CpuCopy16(t = gUnk_08334BCC, (u32)b, 0x20);
    BeginFadeToBrightenedPalette(0x1E, a);
    gBgMapWidth = gTrackData[idx].unk2C;
    gUnk_02022DD8 = gTrackData[idx].unk34;
    gUnk_02002208 = (u8 *)gUnk_02002220;
    gUnk_0200BC54 = (u8 *)gUnk_0200BC70;
    RleDecode16(gTrackData[idx].unk20, gUnk_02002220, gTrackData[idx].unk5C);
    RleDecode16(gTrackData[idx].unk24, gUnk_0200BC70, gTrackData[idx].unk5E);
    gUnk_0200221C = (u8 *)gTrackData[idx].unk0C;
    gUnk_02002210 = (u8 *)gTrackData[idx].unk10;
    gUnk_02022DF0 = gTrackData[idx].unk3C;
    gUnk_0201567C = gTrackData[idx].unk40;
    *(u32 *)&gUnk_0200BC50 = (u32)gUnk_02015690;
    RleDecode16(gTrackData[idx].unk44, gUnk_02015690, gTrackData[idx].unk60);
    gUnk_02022DEC[0] = gTrackData[idx].unk48;
    if (idx == 0)
        gTrackMapWidth[0] = 0x7D;
    if (idx == 1)
        gTrackMapWidth[0] = 0x70;
    if (idx == 2)
        gTrackMapWidth[0] = 0xA8;
    if (idx == 3)
        gTrackMapWidth[0] = 0x6B;
    if (idx == 4)
        gTrackMapWidth[0] = 0xA3;
    if (idx == 5)
        gTrackMapWidth[0] = 0xA6;
    if (idx == 6)
        gTrackMapWidth[0] = 0x7D;
    if (idx == 8)
        gTrackMapWidth[0] = 0x7D;
    if (idx == 9)
        gTrackMapWidth[0] = 0x7D;
    if (idx == 10)
        gTrackMapWidth[0] = 0x5E;
    if (idx == 11)
        gTrackMapWidth[0] = 0x7D;
    /* sub_08003BFC: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32, u32, u16 *, u32 *, u16 *, u16))sub_08003BFC)(0, 0, (u16 *)gUnk_02002208, (u32 *)TILEMAP_BUFFER(0), (u16 *)gUnk_0200221C, gUnk_02022DE4);
    ((void (*)(u32, u32, u16 *, u32 *, u16 *, u16))sub_08003BFC)(0, 0, (u16 *)gUnk_0200BC54, (u32 *)TILEMAP_BUFFER(1), (u16 *)gUnk_02002210, gUnk_0200BC34);
    FlushTrackBgBuffers();
    SetCameraPos(0, 0);
    InitRaceCars(idx);
    ResetLapTimer();
    ResetRaceTimer();
    gNumFinishedCars = 0;
}
