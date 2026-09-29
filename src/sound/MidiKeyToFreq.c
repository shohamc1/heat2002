#include "global.h"
#include "functions.h"

struct Unk10CC
{
    u8 filler0[0x4];
    s32 unk4;
};

extern const u8 gMidiKeyToFreqTable[];
extern const u32 gMidiKeyToFreqOctaveBases[];

s32 MidiKeyToFreq(struct Unk10CC *arg0, u8 arg1, u32 arg2)
{
    u8 idx;
    u32 packed;
    u32 t;
    u8 b;
    s32 next;
    u32 diff;

    idx = arg1;
    packed = arg2 << 24;
    if (idx > 0xB2) {
        idx = 0xB2;
        packed = 0xFF000000;
    }
    t = gMidiKeyToFreqTable[idx];
    t = gMidiKeyToFreqOctaveBases[t & 0xF] >> (t >> 4);
    b = gMidiKeyToFreqTable[idx + 1];
    diff = gMidiKeyToFreqOctaveBases[b & 0xF] >> (b >> 4);
    next = arg0->unk4;
    diff -= t;
    return umul3232H32(next, t + umul3232H32(diff, packed));
}
