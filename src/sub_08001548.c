#include "global.h"
#include "gba/compat.h"
#include "gba/m4a_internal.h"

void ply_note(void);
void sub_080025B8(void);

/* SoundInit */

extern struct SoundInfo *gUnk_03007FF0;
extern MPlayFunc gUnk_02001D90[];

void sub_08001640(u32 a);

void sub_08001548(struct SoundInfo *soundInfo)
{

    soundInfo->ident = 0;
    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT = 0x84400004;
    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT = 0x84400004;
    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;
    REG_SOUNDCNT_X = (SOUND_MASTER_ENABLE | SOUND_1_ON | SOUND_2_ON | SOUND_3_ON | SOUND_4_ON);
    REG_SOUNDCNT_H = (SOUND_ALL_MIX_FULL | SOUND_A_RIGHT_OUTPUT | SOUND_A_FIFO_RESET | SOUND_B_LEFT_OUTPUT | SOUND_B_FIFO_RESET);
    REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | 0x40;
    REG_DMA1SAD = (u32)soundInfo->pcmBuffer;
    REG_DMA1DAD = REG_ADDR_FIFO_A;
    REG_DMA2SAD = (u32)soundInfo->pcmBuffer + PCM_DMA_BUF_SIZE;
    REG_DMA2DAD = REG_ADDR_FIFO_B;
    SOUND_INFO_PTR = soundInfo;
    CpuFill32(0, (u32)soundInfo, sizeof(struct SoundInfo));
    soundInfo->maxChans = 8;
    soundInfo->masterVolume = 0xF;
    soundInfo->plynote = (PlyNoteFunc)ply_note;
    soundInfo->CgbSound = (CgbSoundFunc)sub_080025B8;
    soundInfo->CgbOscOff = (CgbOscOffFunc)sub_080025B8;
    soundInfo->MidiKeyToCgbFreq = (MidiKeyToCgbFreqFunc)sub_080025B8;
    soundInfo->ExtVolPit = (ExtVolPitFunc)sub_080025B8;
    {
        MPlayFunc *t = gUnk_02001D90;

        MPlayJumpTableCopy(t);
        soundInfo->MPlayJumpTable = t;
    }
    sub_08001640(0x40000);
    soundInfo->ident = ID_NUMBER;
}
