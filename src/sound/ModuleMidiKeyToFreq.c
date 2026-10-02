#include "global.h"
#include "functions.h"
#include "gba/m4a_internal.h"

extern const u8 gModule_MidiKeyToFreqTable[];
extern const u32 gModule_MidiKeyToFreqOctaveBases[];

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
    if (idx > 178) {
        idx = 178;
        fineTunePacked = 0xFF000000;
    }
    freq = gModule_MidiKeyToFreqTable[idx];
    freq = gModule_MidiKeyToFreqOctaveBases[freq & 0xF] >> (freq >> 4);
    nextKeyByte = gModule_MidiKeyToFreqTable[idx + 1];
    freqStep = gModule_MidiKeyToFreqOctaveBases[nextKeyByte & 0xF] >> (nextKeyByte >> 4);
    scale = track->freq;
    freqStep -= freq;
    return sub_08339B78(scale, freq + sub_08339B78(freqStep, fineTunePacked));
}
