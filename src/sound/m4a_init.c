#include "global.h"
#include "gba/compat.h"
#include "gba/m4a_internal.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#if PORTABLE
#include "platform/platform.h"
#endif

void ply_note(void);
/* SoundInit */
/* SampleFreqSet */
extern u16 gPcmSamplesPerVBlankTable[];
/* m4aSoundMode */
/* m4aSoundVSyncOff */

void SoundInit(struct SoundInfo *soundInfo)
{

    soundInfo->ident = 0;
    if (REG_DMA1CNT & (DMA_REPEAT << 16))
        REG_DMA1CNT = ((DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED) << 16) | 4;
    if (REG_DMA2CNT & (DMA_REPEAT << 16))
        REG_DMA2CNT = ((DMA_ENABLE | DMA_32BIT | DMA_DEST_FIXED) << 16) | 4;
    REG_DMA1CNT_H = DMA_32BIT;
    REG_DMA2CNT_H = DMA_32BIT;
    REG_SOUNDCNT_X = (SOUND_MASTER_ENABLE | SOUND_1_ON | SOUND_2_ON | SOUND_3_ON | SOUND_4_ON);
    REG_SOUNDCNT_H =
        (SOUND_ALL_MIX_FULL | SOUND_A_RIGHT_OUTPUT | SOUND_A_FIFO_RESET | SOUND_B_LEFT_OUTPUT | SOUND_B_FIFO_RESET);
    REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | 0x40;
    REG_DMA1SAD = ADDR_WORD(soundInfo->pcmBuffer);
    REG_DMA1DAD = ADDR_WORD(REG_ADDR_FIFO_A);
    REG_DMA2SAD = ADDR_WORD(soundInfo->pcmBuffer) + PCM_DMA_BUF_SIZE;
    REG_DMA2DAD = ADDR_WORD(REG_ADDR_FIFO_B);
    SOUND_INFO_PTR = soundInfo;
    CpuFill32(0, soundInfo, sizeof(struct SoundInfo));
    soundInfo->maxChans = 8;
    soundInfo->masterVolume = 0xF;
    soundInfo->plynote = (PlyNoteFunc)ply_note;
    soundInfo->CgbSound = (CgbSoundFunc)DummyCgbSound;
    soundInfo->CgbOscOff = (CgbOscOffFunc)DummyCgbSound;
    soundInfo->MidiKeyToCgbFreq = (MidiKeyToCgbFreqFunc)DummyCgbSound;
    soundInfo->ExtVolPit = (ExtVolPitFunc)DummyCgbSound;
    {
        MPlayFunc *jumpTable = gMPlayJumpTable;

        MPlayJumpTableCopy(jumpTable);
        soundInfo->MPlayJumpTable = jumpTable;
    }
    SampleFreqSet(0x40000);
    soundInfo->ident = ID_NUMBER;
}

void SampleFreqSet(u32 freq)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;

    freq = (freq & (0xF0 << 12)) >> 16;
    {
        u32 timerOff = 0;

        soundInfo->freq = freq;
        {
#if PORTABLE
            /* Hosted mixer timing: a fixed
               sample count per frame at the rate sdl2.c opens the audio
               device at (platform.h). The GBA branch's hardware tables and
               timer mean nothing on the host. */
            soundInfo->pcmSamplesPerVBlank = PLATFORM_AUDIO_SAMPLES_PER_FRAME;
            soundInfo->pcmDmaPeriod = PCM_DMA_BUF_SIZE / PLATFORM_AUDIO_SAMPLES_PER_FRAME;
            soundInfo->pcmFreq = PLATFORM_AUDIO_RATE;
            soundInfo->sampleRateReciprocal = 1.0f / soundInfo->pcmFreq;
#else
            u16 pcmSamplesPerVBlank = gPcmSamplesPerVBlankTable[freq - 1];

            soundInfo->pcmSamplesPerVBlank = pcmSamplesPerVBlank;
            soundInfo->pcmDmaPeriod = sub_08017230(0xC6 << 3, pcmSamplesPerVBlank);
            soundInfo->pcmFreq = sub_08017230(pcmSamplesPerVBlank * 0x00091D1B + 0x1388, 0x2710);
            soundInfo->divFreq = (sub_08017230(0x80 << 17, soundInfo->pcmFreq) + 1) >> 1;
#endif
            REG_TM0CNT_H = timerOff;
#if !PORTABLE
            {
                volatile u16 *tm0CntAddr = (volatile u16 *)REG_ADDR_TM0CNT;

                *tm0CntAddr = -sub_08017230(0x00044940, pcmSamplesPerVBlank);
            }
#endif
        }
        m4aSoundVSyncOn();
#if !PORTABLE
        /* Synchronise the timer start with the last visible scanline.
           A hosted build is single-threaded: REG_VCOUNT only moves when
           the platform's frame pump runs, so waiting for it to pass
           through 0x9F mid-frame cannot finish. The wait is timing-only
           (the mixer owns the hosted timing), so the port skips it. */
        while (*(volatile u8 *)REG_ADDR_VCOUNT == 0x9F)
            ;
        while (*(volatile u8 *)REG_ADDR_VCOUNT != 0x9F)
            ;
#endif
        REG_TM0CNT_H = TIMER_ENABLE;
    }
}

void m4aSoundMode(u32 mode)
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
        m4aSoundVSyncOff();
        SampleFreqSet(temp);
    }
    soundInfo->ident = ID_NUMBER;
}
