#include "global.h"
#include "gba/m4a_internal.h"

/* ply_xwave, high-module copy. */

#define READ_XCMD_BYTE(var, n)         \
    {                                  \
        u32 byte = track->cmdPtr[(n)]; \
        byte <<= n * 8;                \
        (var) &= ~(0xFF << (n * 8));   \
        (var) |= byte;                 \
    }

void sub_0833BB8C(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 wav;

    READ_XCMD_BYTE(wav, 0)
    READ_XCMD_BYTE(wav, 1)
    READ_XCMD_BYTE(wav, 2)
    READ_XCMD_BYTE(wav, 3)

    track->tone.wav = (struct WaveData *)wav;
    track->cmdPtr += 4;
}
