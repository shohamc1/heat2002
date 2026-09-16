#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/m4a_internal.h"

/* m4aSoundVSyncOn (high copy) */

void sub_0833AF0C(void)
{
    struct SoundInfo *soundInfo = (struct SoundInfo *)SOUND_INFO_PTR;
    u32 ident = soundInfo->ident;

    if (ident != ID_NUMBER)
    {
        REG_DMA1CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
        REG_DMA2CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
        soundInfo->pcmDmaCounter = 0;
        soundInfo->ident = ident - 10;
    }
}
