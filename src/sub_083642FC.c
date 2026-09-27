#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "data.h"
#include "variables.h"

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
void sub_083644B4(u32 a1, u32 a2);
void sub_083641D8(u16 x, u16 y);
void sub_0836419C(s16 a, u8 b);
u32 sub_08364550(u32 *a1);
void _08364810(u32 target);

void sub_083642FC(void)
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
    sub_083644B4(0, gUnk_02000964[idx]);
    for (;;) {
        t = ((idx << 15) + frame * 4) >> 10;
        sub_083641D8(t, 100);
        sub_0836419C(t, 100);
        if (sub_08364550(&frame)) {
            idx++;
            if (idx == 7)
                break;
            sub_083644B4(0, gUnk_02000964[idx]);
            frame = 0;
        }
        sub_083647F8((s16 *)gIsland_OamBuffer, (void *)OAM, 0x100);
        sub_08364808();
    }
    sub_08364804(0xE2);
    _08364810((u32)gUnk_02000D00);
}
