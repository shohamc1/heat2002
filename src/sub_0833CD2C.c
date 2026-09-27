#include "global.h"
#define GBA_CPUSET sub_08344B64
#include "tilemap.h"
#include "gba/compat.h"
#include "functions.h"
#include "variables.h"

/* struct Track comes from include/structs.h via variables.h; it is the
   record type of gModule_TrackData, also from variables.h. */

extern u16 gUnk_02022428[];
extern u16 gUnk_02021394[];
extern u32 gUnk_02039288;
extern u32 gUnk_02039224;
extern u32 gUnk_020392A0;
extern u32 gUnk_02039280;

void sub_0833CCD4(u8 idx);
void sub_0833D31C(s32 arg0, u16 *src);
void sub_0833CFC8(u32 x, u32 y, u16 *map, u32 *dest, u16 *charBase, u16 a6);
void sub_0833D094(void);
void sub_0833D564(u32 x, u32 y);
void sub_0834108C(u32 idx);
void sub_0833E078(void);

void sub_0833CD2C(u32 idx)
{
    u16 a[0xE0];
    u16 b[0x20];
    u16 *t;

    sub_0833CCD4(idx);
    t = gUnk_02022428;
    CpuCopy16(t, BG_SCREEN_ADDR(24), 0x2000);
    CpuCopy16(gModule_TrackData[idx].unk18, (u32)a, 0x200);
    CpuCopy16(t = gUnk_02021394, (u32)b, 0x20);
    sub_0833D31C(0x1E, a);
    gUnk_02039244 = gModule_TrackData[idx].unk2C;
    gUnk_02039288 = gModule_TrackData[idx].unk34;
    gUnk_02039228 = gModule_TrackData[idx].unk20;
    gUnk_02039268 = gModule_TrackData[idx].unk24;
    gUnk_02039224 = gModule_TrackData[idx].unk28;
    gUnk_02039238 = gModule_TrackData[idx].unk0C;
    gUnk_0203922C = gModule_TrackData[idx].unk10;
    gUnk_020392A0 = gModule_TrackData[idx].unk3C;
    gUnk_02039280 = gModule_TrackData[idx].unk40;
    gUnk_0203929C = (u8 *)gModule_TrackData[idx].unk48;
    if (idx == 0)
        gModule_TrackMapWidth[0] = 0x7D;
    if (idx == 1)
        gModule_TrackMapWidth[0] = 0x70;
    if (idx == 2)
        gModule_TrackMapWidth[0] = 0xA8;
    if (idx == 3)
        gModule_TrackMapWidth[0] = 0x6B;
    if (idx == 4)
        gModule_TrackMapWidth[0] = 0xA3;
    if (idx == 5)
        gModule_TrackMapWidth[0] = 0xA6;
    if (idx == 6)
        gModule_TrackMapWidth[0] = 0x7D;
    if (idx == 8)
        gModule_TrackMapWidth[0] = 0x7D;
    if (idx == 9)
        gModule_TrackMapWidth[0] = 0x7D;
    if (idx == 10)
        gModule_TrackMapWidth[0] = 0x5E;
    if (idx == 11)
        gModule_TrackMapWidth[0] = 0x7D;
    sub_0833CFC8(0, 0, gUnk_02039228, (u32 *)TILEMAP_BUFFER(1), gUnk_02039238, gUnk_02039294);
    sub_0833CFC8(0, 0, gUnk_02039268, (u32 *)TILEMAP_BUFFER(2), gUnk_0203922C, gUnk_02039248);
    sub_0833D094();
    sub_0833D564(0, 0);
    sub_0834108C(idx);
    sub_0833E05C();
    sub_0833E078();
    gModule_NumFinishedCars = 0;
}
