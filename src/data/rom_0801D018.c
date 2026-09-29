#include "global.h"
#include "data.h"
#include "m4a_engine_tables.h"

/* m4a frequency tables, the tables just before the sound range
 * (0x0801D018-0x0801D230). gMidiKeyToFreqTable packs each MIDI key octave
 * (low nibble, index into gMidiKeyToFreqOctaveBases) and right-shift (high nibble):
 * freq = gMidiKeyToFreqOctaveBases[key & 0xF] >> (key >> 4), MidiKeyToFreq
 * (src/sound/MidiKeyToFreq.c). gMidiKeyToFreqOctaveBases holds the 12 octave bases
 * 2^31 * 2^(j/12). The initialisers live in m4a_engine_tables.h, shared with
 * the high module's byte-identical copies (src/sound/module_engine_tables.c):
 * the ROM holds these tables twice, once per GBA. */

const u8 gMidiKeyToFreqTable[180] = MIDI_KEY_TO_FREQ_TABLE;
// The 12 octave base frequencies, 2^31 * 2^(j/12), for gMidiKeyToFreqTable.
const u32 gMidiKeyToFreqOctaveBases[12] = MIDI_KEY_TO_FREQ_OCTAVE_BASES;
// PCM samples per VBlank for each of the 12 SOUNDBIAS rates (SampleFreqSet).
const u16 gPcmSamplesPerVBlankTable[12] = PCM_SAMPLES_PER_VBLANK_TABLE;
// CGB channel scale table: octave (low nibble, index into gCgbFreqTable) and
// right-shift (high nibble), for MidiKeyToCgbFreq (src/sound/cgb_sound.c).
const u8 gCgbScaleTable[132] = CGB_SCALE_TABLE;
// The 12 CGB channel frequency offsets, for gCgbScaleTable.
const s16 gCgbFreqTable[12] = CGB_FREQ_TABLE;
// CGB channel 4 noise frequencies, for MidiKeyToCgbFreq.
const u8 gNoiseTable[60] = NOISE_TABLE;
// NR32 values per CGB channel 3 envelope volume (CgbSound, src/sound/cgb_sound.c).
const u8 gCgb3Vol[16] = CGB_3VOL;
// The m4a driver's per-frame clock table (0x0801D1FC-0x0801D230): the tempo
// units each VBlank tick of a 52-tick second is worth, then three zero
// bytes. lib/m4a_1.s's SoundMain reads it; m4a_engine_tables.h describes it.
const u8 gClockTable[52] = CLOCK_TABLE;
