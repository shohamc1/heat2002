#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "gba/syscall.h"
#include "functions.h"
#include "data.h"
#include "variables.h"

void sub_0800DFC0(void);
void SioTransferIntr(void);

extern u32 gUnk_0807C9E8;
extern const u8 *gUnk_083FDA50[];
extern u32 gUnk_0807C9CC[];
extern u8 gUnk_0807C9F0[];
extern u8 gUnk_0807CA08[];
extern u8 gUnk_0807CA20[];
extern u8 gUnk_0807CA34[];
extern u8 gUnk_0807CB58[];
extern u8 gUnk_0202E960[];

void SioTransferInit(u32 a1, u32 a2);
void sub_0800DE9C(u16 x, u16 y);
void sub_0800DE60(u32 id, u32 c);
u32 SioTransferUpdate(u32 *frame);

u32 SendMultibootPayload(void)
{
    u32 frame;
    u8 idx;
    u16 i;
    u8 t;

    frame = 0;
    idx = 0;
    REG_IE = INTR_FLAG_VBLANK;
    if (RomHeaderMagic == 0x96 && RomHeaderGameCode == gUnk_0807C9E8)
        REG_IE |= INTR_FLAG_GAMEPAK;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    REG_IME = 1;
    gUnk_02000590[1] = (u32)sub_0800DFC0;
    gUnk_02000590[0] = (u32)SioTransferIntr;
    REG_DISPCNT &= ~DISPCNT_OBJ_ON;
    for (i = 0; i < 3; i++)
        LZ77UnCompVram(gUnk_083FDA50[i], (void *)(OBJ_VRAM0 + i * 0x200));
    DmaCopy32(3, gUnk_0807CB58, OBJ_PLTT, 0xA0);
    DmaFill32(3, 0xA0, gUnk_0202E960, 0x400);
    CpuFastSet(gUnk_0202E960, (void *)OAM, 0x100);
    REG_DISPCNT |= DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP;
    SioTransferInit(1, gUnk_0807C9CC[idx]);
    for (i = 0; i < 4; i++)
        DrawTextCenteredHighlight(gUnk_0807C9F0, i + 8, 1);
    for (;;) {
        t = ((idx << 15) + frame * 4) >> 10;
        sub_0800DE9C(t, 100);
        sub_0800DE60(t, 100);
        DrawTextCenteredHighlight(gUnk_0807CA08, 8, 1);
        DrawTextCenteredHighlight(gUnk_0807CA20, 9, 1);
        DrawTextCenteredHighlight(gUnk_0807CA34, 10, 1);
        if (SioTransferUpdate(&frame)) {
            idx++;
            /* goto, not break: expand_end_loop rolls a loop that has a
               break into exit-test-at-bottom form, and the ROM's loop is
               not rolled. */
            if (idx == 7)
                goto done;
            SioTransferInit(1, gUnk_0807C9CC[idx]);
            frame = 0;
        }
        CpuFastSet(gUnk_0202E960, (void *)OAM, 0x100);
        VBlankIntrWait();
    }
done:
    DmaFill32(3, 0xA0, gUnk_0202E960, 0x400);
    CpuFastSet(gUnk_0202E960, (void *)OAM, 0x100);
    sub_0800DFCC();
    return 0;
}
