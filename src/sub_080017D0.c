#include "global.h"
#include "gba/compat.h"
#include "gba/m4a_internal.h"

/* m4aSoundVSyncOff */

void sub_080017D0(void)
{
    struct SoundInfo *soundInfo = (struct SoundInfo *)SOUND_INFO_PTR;
    u32 ident = soundInfo->ident;

    if (ident - ID_NUMBER <= 1)
    {
        soundInfo->ident = ident + 10;
        if (REG_DMA1CNT & (DMA_REPEAT << 16))
            REG_DMA1CNT = 0x84400004;
        if (REG_DMA2CNT & (DMA_REPEAT << 16))
            REG_DMA2CNT = 0x84400004;
        REG_DMA1CNT_H = DMA_32BIT;
        REG_DMA2CNT_H = DMA_32BIT;
        CpuFill32(0, (u32)soundInfo->pcmBuffer, sizeof(soundInfo->pcmBuffer));
    }
}
