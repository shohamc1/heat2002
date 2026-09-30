#ifndef ENGINE_SOUND_TABLES_H
#define ENGINE_SOUND_TABLES_H

/* The engine-sound tables the ROM holds twice, byte for byte: the main
 * program's gUnk_08364ADC, gEngineSoundFreqBases,
 * gEngineSoundRpmMultipliers and gUnk_08364AF9 (src/data/rom_08364AC8.c,
 * which says what they are) and the high module's at 0x0835DB6C and
 * 0x0835DC10-0x0835DC38 (src/data/rom_0835DB58.c),
 * each linked into its own image. One edit changes both GBAs. */

#define UNK_08364ADC { 4, 0, 0, 0 }
#define ENGINE_SOUND_FREQ_BASES { 1200, 700, 550, 500, 300 }
#define ENGINE_SOUND_RPM_MULTIPLIERS { 200, 190, 180, 160, 150 }
#define UNK_08364AF9 { 1, 1, 12, 2, 12, 12, 12, 2, 12, 12, 12, 12, 39, 0, 0 }

#endif
