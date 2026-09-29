#include "global.h"
#include "functions.h"
#include "gba/m4a_internal.h"

extern const u8 gUnk_0200C6F8[];
extern const u32 gUnk_0200C7AC[];

s32 ModuleMidiKeyToFreq(struct WaveData *track, u8 key, u32 fineTune)
{
    u8 idx;
    u32 fineTunePacked;
    u32 freq;
    u8 nextKeyByte;
    s32 scale;
    u32 freqStep;

    idx = key;
    fineTunePacked = fineTune << 24;
    if (idx > 0xB2) {
        idx = 0xB2;
        fineTunePacked = 0xFF000000;
    }
    freq = gUnk_0200C6F8[idx];
    freq = gUnk_0200C7AC[freq & 0xF] >> (freq >> 4);
    nextKeyByte = gUnk_0200C6F8[idx + 1];
    freqStep = gUnk_0200C7AC[nextKeyByte & 0xF] >> (nextKeyByte >> 4);
    scale = track->freq;
    freqStep -= freq;
    return sub_08339B78(scale, freq + sub_08339B78(freqStep, fineTunePacked));
}
