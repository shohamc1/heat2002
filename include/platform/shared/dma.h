#ifndef GUARD_PLATFORM_SHARED_DMA_H
#define GUARD_PLATFORM_SHARED_DMA_H

// Hosted DMA emulation, after sa2's include/platform/shared/dma.h.
// game code writes the DMA registers through DmaSet/DmaStop/DmaWait
// (include/gba/dma_macros.h makes them functions under PORTABLE); the
// platform layer records each transfer here and RunDMAs replays the
// enabled ones at the start types the hardware would fire them on.

#include "config.h"
#include "global.h"

#define DMA_DEST_MASK 0x0060
#define DMA_SRC_MASK  0x0180

#define DMA_COUNT 4

typedef struct DMATransfer
{
    union
    {
        const void *src;
        const u16 *src16;
        const u32 *src32;
    };
    union
    {
        void *dst;
        vu16 *dst16;
        vu32 *dst32;
    };
    u32 size;
    u16 control;
} DMATransfer;

extern struct DMATransfer DMAList[DMA_COUNT];

typedef enum
{
    DMA_NOW,
    DMA_VBLANK,
    DMA_HBLANK,
    DMA_SPECIAL,
} DmaStartTypes;

void RunDMAs(DmaStartTypes type);

#endif // GUARD_PLATFORM_SHARED_DMA_H
