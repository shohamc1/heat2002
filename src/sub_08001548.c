#include "global.h"
#include "gba/compat.h"

struct SndWork
{
    u32 magic;
    u8 filler4[2];
    u8 unk6;
    u8 unk7;
    u8 filler8[0x28 - 0x08];
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
};

extern struct SndWork *gUnk_03007FF0;
extern u32 gUnk_02001D90[];

void sub_08000958(u32 a);
void sub_08001640(u32 a);

void sub_08001548(struct SndWork *a1)
{

    a1->magic = 0;
    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT = 0x84400004;
    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT = 0x84400004;
    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;
    REG_SOUNDCNT_X = (SOUND_MASTER_ENABLE | SOUND_1_ON | SOUND_2_ON | SOUND_3_ON | SOUND_4_ON);
    REG_SOUNDCNT_H = (SOUND_ALL_MIX_FULL | SOUND_A_RIGHT_OUTPUT | SOUND_A_FIFO_RESET | SOUND_B_LEFT_OUTPUT | SOUND_B_FIFO_RESET);
    REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | 0x40;
    REG_DMA1SAD = (u32)a1 + 0x350;
    REG_DMA1DAD = REG_ADDR_FIFO_A;
    REG_DMA2SAD = (u32)a1 + 0x980;
    REG_DMA2DAD = REG_ADDR_FIFO_B;
    SOUND_INFO_PTR = a1;
    CpuFill32(0, (u32)a1, 0xFB0);
    a1->unk6 = 8;
    a1->unk7 = 0xF;
    a1->unk38 = 0x08000E3D;
    a1->unk28 = 0x080025B9;
    a1->unk2C = 0x080025B9;
    a1->unk30 = 0x080025B9;
    a1->unk3C = 0x080025B9;
    {
        u32 *t = gUnk_02001D90;

        sub_08000958((u32)t);
        a1->unk34 = (u32)t;
    }
    sub_08001640(0x40000);
    a1->magic = 0x68736D53;
}
