#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/m4a_internal.h"
#include "functions.h"
#include "variables.h"

/* SampleFreqSet */

extern u16 gUnk_0801D0FC[];
void sub_08001640(u32 freq)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;

    freq = (freq & (0xF0 << 12)) >> 16;
    {
        u32 r6 = 0;

        soundInfo->freq = freq;
        {
            u16 pcmSamplesPerVBlank = gUnk_0801D0FC[freq - 1];

            soundInfo->pcmSamplesPerVBlank = pcmSamplesPerVBlank;
            soundInfo->pcmDmaPeriod = sub_08017230(0xC6 << 3, pcmSamplesPerVBlank);
            soundInfo->pcmFreq = sub_08017230(pcmSamplesPerVBlank * 0x00091D1B + 0x1388, 0x2710);
            soundInfo->divFreq = (sub_08017230(0x80 << 17, soundInfo->pcmFreq) + 1) >> 1;
            REG_TM0CNT_H = r6;
            {
                u32 t2 = REG_ADDR_TM0CNT;

                *(volatile u16 *)t2 = -sub_08017230(0x00044940, pcmSamplesPerVBlank);
            }
        }
        sub_0800184C();
        while (*(volatile u8 *)REG_ADDR_VCOUNT == 0x9F)
            ;
        while (*(volatile u8 *)REG_ADDR_VCOUNT != 0x9F)
            ;
        REG_TM0CNT_H = TIMER_ENABLE;
    }
}
