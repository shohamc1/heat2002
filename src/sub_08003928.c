#include "global.h"
#include "tilemap.h"
#include "gba/compat.h"
#include "functions.h"
#include "variables.h"

extern u16 *gUnk_02002208;
extern u16 *gUnk_0200BC54;
extern u16 gUnk_02002220[];
extern u16 gUnk_0200BC70[];
extern u16 gUnk_02015690[];
extern u16 *gUnk_0200BC50;
extern u16 *gUnk_0200221C;
extern u16 *gUnk_02002210;
extern u32 gUnk_02022DD8;
extern u32 gUnk_02022DF0;
extern u32 gUnk_0201567C;
extern u32 gUnk_03000800[];
extern u16 gUnk_08335C60[];
extern u16 gUnk_08334BCC[];

struct Track {
    /* +0x00 */ u32 unk00;
    /* +0x04 */ u32 unk04;
    /* +0x08 */ u32 unk08;
    /* +0x0C */ u16 *unk0C;
    /* +0x10 */ u16 *unk10;
    /* +0x14 */ u32 unk14;
    /* +0x18 */ u32 unk18;
    /* +0x1C */ u32 unk1C;
    /* +0x20 */ u16 *unk20;
    /* +0x24 */ u16 *unk24;
    /* +0x28 */ u32 unk28;
    /* +0x2C */ u32 unk2C;
    /* +0x30 */ u32 unk30;
    /* +0x34 */ u32 unk34;
    /* +0x38 */ u32 unk38;
    /* +0x3C */ u32 unk3C;
    /* +0x40 */ u32 unk40;
    /* +0x44 */ u16 *unk44;
    /* +0x48 */ u32 unk48;
    /* +0x4C */ u8 filler4C[0x5C - 0x4C];
    /* +0x5C */ u16 unk5C;
    /* +0x5E */ u16 unk5E;
    /* +0x60 */ u16 unk60;
    /* +0x62 */ u8 filler62[0x64 - 0x62];
};

extern struct Track gUnk_08364B0C[];

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
    CpuCopy16(gUnk_08364B0C[idx].unk18, (u32)a, 0x200);
    CpuCopy16(t = gUnk_08334BCC, (u32)b, 0x20);
    BeginFadeToBrightenedPalette(0x1E, a);
    gUnk_0200BC30 = gUnk_08364B0C[idx].unk2C;
    gUnk_02022DD8 = gUnk_08364B0C[idx].unk34;
    gUnk_02002208 = gUnk_02002220;
    gUnk_0200BC54 = gUnk_0200BC70;
    RleDecode16(gUnk_08364B0C[idx].unk20, gUnk_02002220, gUnk_08364B0C[idx].unk5C);
    RleDecode16(gUnk_08364B0C[idx].unk24, gUnk_0200BC70, gUnk_08364B0C[idx].unk5E);
    gUnk_0200221C = gUnk_08364B0C[idx].unk0C;
    gUnk_02002210 = gUnk_08364B0C[idx].unk10;
    gUnk_02022DF0 = gUnk_08364B0C[idx].unk3C;
    gUnk_0201567C = gUnk_08364B0C[idx].unk40;
    gUnk_0200BC50 = gUnk_02015690;
    RleDecode16(gUnk_08364B0C[idx].unk44, gUnk_02015690, gUnk_08364B0C[idx].unk60);
    gUnk_02022DEC[0] = gUnk_08364B0C[idx].unk48;
    if (idx == 0)
        gUnk_02002200[0] = 0x7D;
    if (idx == 1)
        gUnk_02002200[0] = 0x70;
    if (idx == 2)
        gUnk_02002200[0] = 0xA8;
    if (idx == 3)
        gUnk_02002200[0] = 0x6B;
    if (idx == 4)
        gUnk_02002200[0] = 0xA3;
    if (idx == 5)
        gUnk_02002200[0] = 0xA6;
    if (idx == 6)
        gUnk_02002200[0] = 0x7D;
    if (idx == 8)
        gUnk_02002200[0] = 0x7D;
    if (idx == 9)
        gUnk_02002200[0] = 0x7D;
    if (idx == 10)
        gUnk_02002200[0] = 0x5E;
    if (idx == 11)
        gUnk_02002200[0] = 0x7D;
    /* sub_08003BFC: this file's old local prototype differs from
       functions.h; call through the old signature (solved-walls 31). */
    ((void (*)(u32, u32, u16 *, u32 *, u16 *, u16))sub_08003BFC)(0, 0, gUnk_02002208, (u32 *)TILEMAP_BUFFER(0), gUnk_0200221C, gUnk_02022DE4);
    ((void (*)(u32, u32, u16 *, u32 *, u16 *, u16))sub_08003BFC)(0, 0, gUnk_0200BC54, (u32 *)TILEMAP_BUFFER(1), gUnk_02002210, gUnk_0200BC34);
    FlushTrackBgBuffers();
    SetCameraPos(0, 0);
    InitRaceCars(idx);
    ResetLapTimer();
    ResetRaceTimer();
    gUnk_020253D4 = 0;
}
