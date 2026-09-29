#include "global.h"
#include "../data/m4a_engine_tables.h"

/* The high module's copies of the m4a engine tables (ROM 0x08345178-0x08345390,
 * EWRAM 0x0200C6F8-0x0200C910), byte-identical to the main program's at
 * 0x0801D018-0x0801D230 (src/data/rom_0801D018.c, which says what each table
 * is for): the ROM holds them twice, one set per GBA. m4a_engine_tables.h
 * shares the initialisers, so one edit changes both copies. The readers
 * reach these by their gModule_ names (ModuleMidiKeyToFreq.c,
 * module_m4a_init.c, module_cgb_sound.c); lib/m4a_1.s's high copy reaches
 * gModule_ClockTable through the Makefile's gClockTable rename. */

const u8 gModule_MidiKeyToFreqTable[180] = MIDI_KEY_TO_FREQ_TABLE;
const u32 gModule_MidiKeyToFreqOctaveBases[12] = MIDI_KEY_TO_FREQ_OCTAVE_BASES;
const u16 gModule_PcmSamplesPerVBlankTable[12] = PCM_SAMPLES_PER_VBLANK_TABLE;
const u8 gModule_CgbScaleTable[132] = CGB_SCALE_TABLE;
const s16 gModule_CgbFreqTable[12] = CGB_FREQ_TABLE;
const u8 gModule_NoiseTable[60] = NOISE_TABLE;
const u8 gModule_Cgb3Vol[16] = CGB_3VOL;
const u8 gModule_ClockTable[52] = CLOCK_TABLE;
