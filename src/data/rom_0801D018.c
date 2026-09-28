#include "global.h"
#include "data.h"

/* m4a frequency tables, the tables just before the sound range
 * (0x0801D018-0x0801D1FC). gMidiKeyToFreqTable packs each MIDI key octave
 * (low nibble, index into gMidiKeyToFreqOctaveBases) and right-shift (high nibble):
 * freq = gMidiKeyToFreqOctaveBases[key & 0xF] >> (key >> 4), MidiKeyToFreq
 * (src/sound/MidiKeyToFreq.c). gMidiKeyToFreqOctaveBases holds the 12 octave bases
 * 2^31 * 2^(j/12). */

const u8 gMidiKeyToFreqTable[180] = {
    224, 225, 226, 227, 228, 229, 230, 231,
    232, 233, 234, 235, 208, 209, 210, 211,
    212, 213, 214, 215, 216, 217, 218, 219,
    192, 193, 194, 195, 196, 197, 198, 199,
    200, 201, 202, 203, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187,
    160, 161, 162, 163, 164, 165, 166, 167,
    168, 169, 170, 171, 144, 145, 146, 147,
    148, 149, 150, 151, 152, 153, 154, 155,
    128, 129, 130, 131, 132, 133, 134, 135,
    136, 137, 138, 139, 112, 113, 114, 115,
    116, 117, 118, 119, 120, 121, 122, 123,
    96, 97, 98, 99, 100, 101, 102, 103,
    104, 105, 106, 107, 80, 81, 82, 83,
    84, 85, 86, 87, 88, 89, 90, 91,
    64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 48, 49, 50, 51,
    52, 53, 54, 55, 56, 57, 58, 59,
    32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27,
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11
};
// The 12 octave base frequencies, 2^31 * 2^(j/12), for gMidiKeyToFreqTable.
const u32 gMidiKeyToFreqOctaveBases[12] = {
    0x80000000, 0x879C7C97, 0x8FACD61E, 0x9837F052, 0xA14517CC, 0xAADC0848,
    0xB504F334, 0xBFC886BB, 0xCB2FF52A, 0xD744FCCB, 0xE411F03A, 0xF1A1BF39
};
// PCM samples per VBlank for each of the 12 SOUNDBIAS rates (SampleFreqSet).
const u16 gPcmSamplesPerVBlankTable[12] = {
    96, 132, 176, 224, 264, 304, 352, 448,
    528, 608, 672, 704
};
// CGB channel scale table: octave (low nibble, index into gCgbFreqTable) and
// right-shift (high nibble), for MidiKeyToCgbFreq (src/sound/cgb_sound.c).
const u8 gCgbScaleTable[132] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27,
    32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 48, 49, 50, 51,
    52, 53, 54, 55, 56, 57, 58, 59,
    64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 80, 81, 82, 83,
    84, 85, 86, 87, 88, 89, 90, 91,
    96, 97, 98, 99, 100, 101, 102, 103,
    104, 105, 106, 107, 112, 113, 114, 115,
    116, 117, 118, 119, 120, 121, 122, 123,
    128, 129, 130, 131, 132, 133, 134, 135,
    136, 137, 138, 139, 144, 145, 146, 147,
    148, 149, 150, 151, 152, 153, 154, 155,
    160, 161, 162, 163, 164, 165, 166, 167,
    168, 169, 170, 171
};
// The 12 CGB channel frequency offsets, for gCgbScaleTable.
const s16 gCgbFreqTable[12] = {
    -2004, -1891, -1785, -1685, -1591, -1501, -1417, -1337,
    -1262, -1192, -1125, -1062
};
// CGB channel 4 noise frequencies, for MidiKeyToCgbFreq.
const u8 gNoiseTable[60] = {
    215, 214, 213, 212, 199, 198, 197, 196,
    183, 182, 181, 180, 167, 166, 165, 164,
    151, 150, 149, 148, 135, 134, 133, 132,
    119, 118, 117, 116, 103, 102, 101, 100,
    87, 86, 85, 84, 71, 70, 69, 68,
    55, 54, 53, 52, 39, 38, 37, 36,
    23, 22, 21, 20, 7, 6, 5, 4,
    3, 2, 1, 0
};
// NR32 values per CGB channel 3 envelope volume (CgbSound, src/sound/cgb_sound.c).
const u8 gCgb3Vol[16] = {
    0, 0, 96, 96, 96, 96, 64, 64,
    64, 64, 128, 128, 128, 128, 32, 32
};
