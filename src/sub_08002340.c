#include "global.h"
#include "gba/m4a_internal.h"
#include "m4a.h"

/* ply_memacc. The whole function is one switch on the first operand byte;
 * luvdis left the jump table and every case body as .byte rows inside the
 * block, so its true extent runs to 0x08002496. This ROM's revision keeps
 * memAccArea at MusicPlayerInfo+0x18 (the header's gap[8] before it). */


#define MEMACC_COND_JUMP(cond) \
    if (cond)                  \
        goto cond_true;        \
    else                       \
        goto cond_false;

void sub_08002340(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 op;
    u8 *addr;
    u8 data;

    op = *track->cmdPtr;
    track->cmdPtr++;

    addr = mplayInfo->memAccArea + *track->cmdPtr;
    track->cmdPtr++;

    data = *track->cmdPtr;
    track->cmdPtr++;

    switch (op) {
    case 0:
        *addr = data;
        return;
    case 1:
        *addr += data;
        return;
    case 2:
        *addr -= data;
        return;
    case 3:
        *addr = mplayInfo->memAccArea[data];
        return;
    case 4:
        *addr += mplayInfo->memAccArea[data];
        return;
    case 5:
        *addr -= mplayInfo->memAccArea[data];
        return;
    case 6:
        MEMACC_COND_JUMP(*addr == data)
        return;
    case 7:
        MEMACC_COND_JUMP(*addr != data)
        return;
    case 8:
        MEMACC_COND_JUMP(*addr > data)
        return;
    case 9:
        MEMACC_COND_JUMP(*addr >= data)
        return;
    case 10:
        MEMACC_COND_JUMP(*addr <= data)
        return;
    case 11:
        MEMACC_COND_JUMP(*addr < data)
        return;
    case 12:
        MEMACC_COND_JUMP(*addr == mplayInfo->memAccArea[data])
        return;
    case 13:
        MEMACC_COND_JUMP(*addr != mplayInfo->memAccArea[data])
        return;
    case 14:
        MEMACC_COND_JUMP(*addr > mplayInfo->memAccArea[data])
        return;
    case 15:
        MEMACC_COND_JUMP(*addr >= mplayInfo->memAccArea[data])
        return;
    case 16:
        MEMACC_COND_JUMP(*addr <= mplayInfo->memAccArea[data])
        return;
    case 17:
        MEMACC_COND_JUMP(*addr < mplayInfo->memAccArea[data])
        return;
    default:
        return;
    }

cond_true:
    ((MPlayFunc)(*&gUnk_02001D90[1]))(mplayInfo, track);
    return;

cond_false:
    track->cmdPtr += 4;
}
