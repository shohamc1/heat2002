#include "global.h"
#include "gba/compat.h"
#include "gba/m4a_internal.h"
#include "m4a.h"
#include "variables.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "functions.h"

#define GBA_CPUSET sub_08344B64

/* SoundInit (high copy) */
void sub_0833A018(MPlayFunc *jumpTable);
void ModuleSampleFreqSet(u32 a);
void sub_0833A4FC(void);
void ModuleDummyCgbSound(void);
/* SampleFreqSet (high copy) */
extern u16 gUnk_0200C7DC[];
/* m4aSoundMode (high copy) */
void ModuleM4aSoundVSyncOff(void);

void ModuleSoundInit(struct SoundInfo *soundInfo)
{

    soundInfo->ident = 0;
    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT = 0x84400004;
    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT = 0x84400004;
    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;
    REG_SOUNDCNT_X = (SOUND_MASTER_ENABLE | SOUND_1_ON | SOUND_2_ON | SOUND_3_ON | SOUND_4_ON);
    REG_SOUNDCNT_H =
        (SOUND_ALL_MIX_FULL | SOUND_A_RIGHT_OUTPUT | SOUND_A_FIFO_RESET | SOUND_B_LEFT_OUTPUT | SOUND_B_FIFO_RESET);
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
    soundInfo->CgbSound = (CgbSoundFunc)ModuleDummyCgbSound;
    soundInfo->CgbOscOff = (CgbOscOffFunc)ModuleDummyCgbSound;
    soundInfo->MidiKeyToCgbFreq = (MidiKeyToCgbFreqFunc)ModuleDummyCgbSound;
    soundInfo->ExtVolPit = (ExtVolPitFunc)ModuleDummyCgbSound;
    {
        MPlayFunc *jumpTable = gModule_MPlayJumpTable;

        sub_0833A018(jumpTable);
        soundInfo->MPlayJumpTable = jumpTable;
    }
    ModuleSampleFreqSet(0x40000);
    soundInfo->ident = ID_NUMBER;
}

void ModuleSampleFreqSet(u32 freq)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;

    freq = (freq & (0xF0 << 12)) >> 16;
    {
        u32 timerOff = 0;

        soundInfo->freq = freq;
        {
            u16 pcmSamplesPerVBlank = gUnk_0200C7DC[freq - 1];

            soundInfo->pcmSamplesPerVBlank = pcmSamplesPerVBlank;
            soundInfo->pcmDmaPeriod = sub_08344BB8(0xC6 << 3, pcmSamplesPerVBlank);
            soundInfo->pcmFreq = sub_08344BB8(pcmSamplesPerVBlank * 0x00091D1B + 0x1388, 0x2710);
            soundInfo->divFreq = (sub_08344BB8(0x80 << 17, soundInfo->pcmFreq) + 1) >> 1;
            REG_TM0CNT_H = timerOff;
            {
                u32 tm0CntAddr = REG_ADDR_TM0CNT;

                *(volatile u16 *)tm0CntAddr = -sub_08344BB8(0x00044940, pcmSamplesPerVBlank);
            }
        }
        ModuleM4aSoundVSyncOn();
        while (*(volatile u8 *)REG_ADDR_VCOUNT == 0x9F)
            ;
        while (*(volatile u8 *)REG_ADDR_VCOUNT != 0x9F)
            ;
        REG_TM0CNT_H = TIMER_ENABLE;
    }
}

void ModuleM4aSoundMode(u32 mode)
{
    struct SoundInfo *soundInfo = (struct SoundInfo *)SOUND_INFO_PTR;
    u32 temp;
    u8 *chan;

    if (soundInfo->ident != ID_NUMBER)
        return;
    soundInfo->ident = soundInfo->ident + 1;
    temp = mode & 0xFF;
    if (temp != 0) {
        temp &= 0x7F;
        soundInfo->reverb = temp;
    }
    temp = mode & 0xF00;
    if (temp != 0) {
        soundInfo->maxChans = temp >> 8;
        for (temp = MAX_DIRECTSOUND_CHANNELS, chan = &soundInfo->chans[0].statusFlags; temp != 0;
             temp--, chan += sizeof(struct SoundChannel))
            *chan = 0;
    }
    temp = mode & 0xF000;
    if (temp != 0)
        soundInfo->masterVolume = temp >> 12;
    temp = mode & 0xB00000;
    if (temp != 0) {
        temp = (temp & 0x300000) >> 14;
        REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | temp;
    }
    temp = mode & 0xF0000;
    if (temp != 0) {
        ModuleM4aSoundVSyncOff();
        ModuleSampleFreqSet(temp);
    }
    soundInfo->ident = ID_NUMBER;
}
