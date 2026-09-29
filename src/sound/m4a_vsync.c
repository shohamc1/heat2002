#include "global.h"
#include "gba/compat.h"
#include "gba/m4a_internal.h"

/* m4aSoundVSyncOff */
#include "gba/defines.h"
#include "gba/io_reg.h"
/* m4aSoundVSyncOn */

void m4aSoundVSyncOff(void)
{
    struct SoundInfo *soundInfo = (struct SoundInfo *)SOUND_INFO_PTR;
    u32 ident = soundInfo->ident;

    if (ident - ID_NUMBER <= 1) {
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

void m4aSoundVSyncOn(void)
{
    struct SoundInfo *soundInfo = (struct SoundInfo *)SOUND_INFO_PTR;
    u32 ident = soundInfo->ident;

    if (ident != ID_NUMBER) {
        REG_DMA1CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
        REG_DMA2CNT_H = DMA_ENABLE | DMA_START_SPECIAL | DMA_32BIT | DMA_REPEAT;
        soundInfo->pcmDmaCounter = 0;
        soundInfo->ident = ident - 10;
    }
}
