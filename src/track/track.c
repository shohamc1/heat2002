#include "global.h"
#include "gba/compat.h"
#include "variables.h"
extern u16 gUnk_02022DF4;
/* struct Track and gTrackData come from include/structs.h via
   variables.h. */
/* Each case carries its own copy of the body so expand_case counts 12
   distinct labels and emits a jump table; cross-jumping then merges the
   twelve identical bodies, leaving every table entry at one address. */
#include "tilemap.h"
#include "functions.h"
extern u16 gUnk_02002220[];
extern u16 gUnk_0200BC70[];
extern u16 gUnk_02015690[];
extern u32 gUnk_02022DD8;
extern u32 gUnk_02022DF0;
extern u32 gUnk_0201567C;
extern u16 gTrackBgTilemap[];
extern u16 gTrackBgPalette[];
void LoadTrackTiles(u8 idx);
void BeginFadeToBrightenedPalette(s32 arg0, u16 *src);
void RleDecode16(u16 *src, u16 *dst, u16 count);
void FlushTrackBgBuffers(void);
void SetCameraPos(u32 x, u32 y);
void InitRaceCars(u32 idx);
void ResetRaceTimer(void);
#include "gba/defines.h"

void LoadTrackTiles(u8 idx)
{
    switch (idx) {
        case 0:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 1:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 2:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 3:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 4:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 5:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 6:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 7:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 8:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 9:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 10:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
        case 11:
            CpuCopy16(gTrackData[idx].unk04, VRAM, 0x8000);
            CpuCopy16(gTrackData[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
            gUnk_02022DE4 = 0;
            gUnk_0200BC34 = 0;
            gUnk_02022DF4 = 0;
            break;
    }
}

void LoadTrack(u32 idx)
{
    u16 a[0xE0];
    u16 b[0x20];
    u16 *t;

    LoadTrackTiles(idx);
    t = gTrackBgTilemap;
    CpuCopy16(t, BG_SCREEN_ADDR(24), 0x2000);
    CpuCopy16(gTrackData[idx].unk18, (u32)a, 0x200);
    CpuCopy16(t = gTrackBgPalette, (u32)b, 0x20);
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
    /* DrawTrackMapWindow: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32, u32, u16 *, u32 *, u16 *, u16))DrawTrackMapWindow)(
        0, 0, (u16 *)gUnk_02002208, (u32 *)TILEMAP_BUFFER(0), (u16 *)gUnk_0200221C, gUnk_02022DE4);
    ((void (*)(u32, u32, u16 *, u32 *, u16 *, u16))DrawTrackMapWindow)(
        0, 0, (u16 *)gUnk_0200BC54, (u32 *)TILEMAP_BUFFER(1), (u16 *)gUnk_02002210, gUnk_0200BC34);
    FlushTrackBgBuffers();
    SetCameraPos(0, 0);
    InitRaceCars(idx);
    ResetLapTimer();
    ResetRaceTimer();
    gNumFinishedCars = 0;
}

void UpdateTrackScroll(void)
{
    s32 x;
    s32 y;

    x = gCamera[6] - 0x78;
    y = gCamera[7] - 0x50;
    gUnk_0200BC48 = x & 0x0F;
    gUnk_0200BC4C = y & 0x1F;
    gUnk_02022DF8 = x & 0x0F;
    gUnk_0200BC2C = y & 0x1F;
    gUnk_02022DE0 = x & 0x0F;
    gUnk_02022DE8 = y & 0x1F;
    gUnk_02002218 = x & 0x10;
    x >>= 5;
    y >>= 5;
    /* DrawTrackMapWindow: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32, u32, u8 *, u32 *, u8 *, u16))DrawTrackMapWindow)(x, y, gUnk_02002208, (u32 *)TILEMAP_BUFFER(0),
                                                                     gUnk_0200221C, gUnk_02022DE4);
    ((void (*)(u32, u32, u8 *, u32 *, u8 *, u16))DrawTrackMapWindow)(x, y, gUnk_0200BC54, (u32 *)TILEMAP_BUFFER(1),
                                                                     gUnk_02002210, gUnk_0200BC34);
}
