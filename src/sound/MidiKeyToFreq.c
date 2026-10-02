#include "global.h"
#include "functions.h"
#include "gba/m4a_internal.h"

extern const u8 gMidiKeyToFreqTable[];
extern const u32 gMidiKeyToFreqOctaveBases[];

s32 MidiKeyToFreq(struct WaveData *arg0, u8 arg1, u32 arg2)
{
    u8 idx;
    u32 packed;
    u32 t;
    u8 b;
    s32 next;
    u32 diff;

    idx = arg1;
    packed = arg2 << 24;
    if (idx > 178) {
        idx = 178;
        packed = 0xFF000000;
    }
    t = gMidiKeyToFreqTable[idx];
    t = gMidiKeyToFreqOctaveBases[t & 0xF] >> (t >> 4);
    b = gMidiKeyToFreqTable[idx + 1];
    diff = gMidiKeyToFreqOctaveBases[b & 0xF] >> (b >> 4);
    next = arg0->freq;
    diff -= t;
    return umul3232H32(next, t + umul3232H32(diff, packed));
}
