#include "global.h"
#include "structs.h"
#include "race_setup_tables.h"

/* High module (link slave) tire-grip setups (ROM 0x0835F8A0-0x0835FB0C,
 * EWRAM 0x02026E20-0x0202708C), byte-identical to the main program's
 * gTireGripDefaults (src/data/race_setup.c, which says what each row is
 * for): the ROM holds them twice, once per GBA. race_setup_tables.h
 * shares the initialisers, so one edit changes both copies.
 * ModuleSetTireGrip.c loads row 0 for every car in a link race. */

const struct TireGripSetup gModule_TireGripDefaults[31] = TIRE_GRIP_DEFAULTS;

/* The rest of the car setup tables (ROM 0x0835FB0C-0x0835FBFC, EWRAM
 * 0x0202708C-0x0202717C): track 7's row of the main program's
 * gTrackStartGrids, then the twins of its seven car setups and AI gear
 * rows, gUnk_08367B64 to gUnk_08367C2E (src/data/race_setup.c, which
 * says what each is for). Both build from race_setup_tables.h. */

const struct TrackGrid gModule_TrackStartGrids[1] = { TRACK_7_START_GRID };
const u16 gModule_020270A8[5] = UNK_08367B64;
const u16 gModule_020270B2[5] = UNK_08367B6E;
const u16 gModule_020270BC[5] = UNK_08367B78;
const u16 gModule_020270C6[5] = UNK_08367B82;
const u16 gModule_020270D0[5] = UNK_08367B8C;
const u16 gModule_020270DA[5] = UNK_08367B96;
const u16 gModule_020270E4[5] = UNK_08367BA0;
const u16 gModule_020270EE[5] = UNK_08367BAA;
const u16 gModule_020270F8[5] = UNK_08367BB4;
const u16 gModule_02027102[5] = UNK_08367BBE;
const u16 gModule_0202710C[5] = UNK_08367BC8;
const u16 gModule_02027116[5] = UNK_08367BD2;
const u16 gModule_02027120[5] = UNK_08367BDC;
const u16 gModule_0202712A[5] = UNK_08367BE6;
const u16 gModule_02027134[5] = UNK_08367BF0;
const u16 gModule_AiDriverGearPowerTable[5] = AI_DRIVER_GEAR_POWER_TABLE;
const u16 gModule_02027148[1] = UNK_08367C04;
const u16 gModule_AiDriverGearRatioTable[5] = AI_DRIVER_GEAR_RATIO_TABLE;
const u16 gModule_AiDriverRpmPerSpeedTable[5] = AI_DRIVER_RPM_PER_SPEED_TABLE;
const u16 gModule_0202715E[5] = UNK_08367C1A;
const u16 gModule_02027168[5] = UNK_08367C24;
const u16 gModule_02027172[5] = UNK_08367C2E;
