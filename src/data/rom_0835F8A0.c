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
