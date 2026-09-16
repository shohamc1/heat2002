#include "global.h"
#include "gba/compat.h"

extern u16 gUnk_02022DE4;
extern u16 gUnk_0200BC34;
extern u16 gUnk_02022DF4;

struct Track {
    /* +0x00 */ u32 unk00;
    /* +0x04 */ u32 unk04;
    /* +0x08 */ u8 filler08[100 - 8];
};

extern struct Track gUnk_08364B0C[];

/* Each case carries its own copy of the body so expand_case counts 12
   distinct labels and emits a jump table; cross-jumping then merges the
   twelve identical bodies, leaving every table entry at one address. */
void sub_08003890(u8 idx)
{
    switch (idx) {
    case 0:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 1:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 2:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 3:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 4:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 5:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 6:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 7:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 8:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 9:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 10:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    case 11:
        CpuCopy16(gUnk_08364B0C[idx].unk04, VRAM, 0x8000);
        CpuCopy16(gUnk_08364B0C[idx].unk00, BG_CHAR_ADDR(2), 0x4000);
        gUnk_02022DE4 = 0;
        gUnk_0200BC34 = 0;
        gUnk_02022DF4 = 0;
        break;
    }
}
