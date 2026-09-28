#include "global.h"
#include "variables.h"

#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "data.h"
extern u32 gUnk_020009B8;
void sub_083640B0(void);
extern u8 *gUnk_02000BD4[];
extern u32 gUnk_02000A9C[];
extern u16 gUnk_05000200[];
extern u32 gUnk_02000964[];
extern u8 gUnk_02000D00[];
void sub_08364804(u32 flags);
void sub_08364800(const void *src, void *dest);
void sub_083647F8(const void *src, void *dest, u32 control);
void sub_08364808(void);
void IslandSioTransferInit(u32 a1, u32 a2);
void IslandDrawLinkProgressBar(u16 x, u16 y);
void IslandDrawMultibootProgressMarker(s16 a, u8 b);
u32 IslandSioTransferUpdate(u32 *a1);
void _08364810(u32 target);


void IslandDrawLinkProgressBar(u16 progress, u16 y)
{
    s16 *oam = (s16 *)gIsland_OamBuffer;
    s16 *oamPtr;
    u16 *capAttr1;
    u16 *capAttr2;
    s32 m1, m2, attr1Mask, attr2Mask;
    u8 *obj;
    u16 seg;
    s32 segPos;
    s32 tile;
    u16 tileNum;

    capAttr1 = &oam[0x25];
    m1 = ~0x1FF;
    *capAttr1 &= m1;
    ((u8 *)oam)[0x48] = y;
    ((u8 *)oam)[0x4B] = (((u8 *)oam)[0x4B] & 0x3F) | 0x80;
    ((u8 *)oam)[0x4D] &= 0x0F;
    capAttr2 = &oam[0x26];
    m2 = ~0x3FF;
    *capAttr2 = (*capAttr2 & m2) | 0x10;

    for (seg = 0, oamPtr = oam, attr1Mask = m1, attr2Mask = m2; seg < 8; seg++) {
        obj = (u8 *)((seg + 10) * 8 + (u32)oamPtr);
        segPos = seg * 32 + 32;
        tileNum = segPos & 0x1FF;
        tile = tileNum;
        *(u16 *)&obj[2] = (*(u16 *)&obj[2] & attr1Mask) | tile;
        obj[0] = y;
        obj[3] = (obj[3] & 0x3F) | 0x80;
        obj[5] &= 0x0F;
        if (progress < segPos)
            *(u16 *)&obj[4] = (*(u16 *)&obj[4] & attr2Mask) | 0x20;
        else
            *(u16 *)&obj[4] = (*(u16 *)&obj[4] & attr2Mask) | 0x10;
    }

    oam[0x41] = (oam[0x41] & ~0x1FF) | 0xD0;
    ((u8 *)oam)[0x80] = y;
    ((u8 *)oam)[0x83] = (((u8 *)oam)[0x83] & 0x3F) | 0x80;
    ((u8 *)oam)[0x85] &= 0x0F;
    oam[0x42] = (oam[0x42] & ~0x3FF) | 0x20;
}


void IslandAgbMain(void)
{
    u32 frame;
    u8 idx;
    u16 i;
    u8 t;

    frame = 0;
    idx = 0;
    sub_08364804(2);
    DmaCopy32(3, sub_083640B0, gIsland_IntrMainBuffer, 0x800);
    gIntrVector = (u32)gIsland_IntrMainBuffer;
    REG_IE = INTR_FLAG_VBLANK;
    if (RomHeaderMagic == 0x96 && RomHeaderGameCode == gUnk_020009B8)
        REG_IE |= INTR_FLAG_GAMEPAK;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    DmaFill32(3, 0, (void *)VRAM, 0x18000);
    for (i = 0; i < 3; i++)
        sub_08364800(gUnk_02000BD4[i], (void *)(OBJ_VRAM0 + i * 0x200));
    DmaCopy32(3, gUnk_02000A9C, gUnk_05000200, 0x20);
    *(vu16 *)0x04000008 = 0x89;
    REG_DISPCNT = DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP;
    REG_IE = INTR_FLAG_VBLANK;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    REG_IME = 1;
    DmaFill32(3, 0xA0, (s16 *)gIsland_OamBuffer, 0x400);
    IslandSioTransferInit(0, gUnk_02000964[idx]);
    for (;;) {
        t = ((idx << 15) + frame * 4) >> 10;
        IslandDrawLinkProgressBar(t, 100);
        IslandDrawMultibootProgressMarker(t, 100);
        if (IslandSioTransferUpdate(&frame)) {
            idx++;
            if (idx == 7)
                break;
            IslandSioTransferInit(0, gUnk_02000964[idx]);
            frame = 0;
        }
        sub_083647F8((s16 *)gIsland_OamBuffer, (void *)OAM, 0x100);
        sub_08364808();
    }
    sub_08364804(0xE2);
    _08364810((u32)gUnk_02000D00);
}

