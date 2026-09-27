#include "global.h"
#define GBA_CPUSET sub_08344B64
#include "gba/compat.h"
#include "gba/m4a_internal.h"
#include "m4a.h"
#include "variables.h"

/* SoundInit (high copy) */


void sub_0833A018(u32 a);
void sub_0833AD00(u32 a);
void sub_0833A4FC(void);
void sub_0833BC78(void);

void sub_0833AC08(struct SoundInfo *soundInfo)
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
    soundInfo->plynote = (PlyNoteFunc)sub_0833A4FC;
    soundInfo->CgbSound = (CgbSoundFunc)sub_0833BC78;
    soundInfo->CgbOscOff = (CgbOscOffFunc)sub_0833BC78;
    soundInfo->MidiKeyToCgbFreq = (MidiKeyToCgbFreqFunc)sub_0833BC78;
    soundInfo->ExtVolPit = (ExtVolPitFunc)sub_0833BC78;
    {
        MPlayFunc *t = gUnk_02038DE0;

        sub_0833A018((u32)t);
        soundInfo->MPlayJumpTable = t;
    }
    sub_0833AD00(0x40000);
    soundInfo->ident = ID_NUMBER;
}
