#include "global.h"

/* The pit-menu label rows inside gModule_PitLabelBlock
 * (src/data/high_module_text.c), named by their EWRAM addresses in
 * symbols.ld. */
extern const u8 gUnk_0200CFC4[]; /* OK */
extern const u8 gUnk_0200CFC8[]; /* DAMAGE: */
extern const u8 gUnk_0200CFD0[]; /* FUEL  : */
extern const u8 gUnk_0200CFD8[]; /* TIRES : */
extern const u8 gUnk_0200CFE0[]; /* NONE      */
extern const u8 gUnk_0200CFEC[]; /* RIGHT 2   */
extern const u8 gUnk_0200CFF8[]; /* LEFT 2    */
extern const u8 gUnk_0200D004[]; /* ALL TIRES */
extern const u8 gUnk_0200D010[]; /* NONE           */
extern const u8 gUnk_0200D020[]; /* SPLASH AND DASH */
extern const u8 gUnk_0200D030[]; /* FULL TANK      */

/* High module (link slave) pit-menu option text tables (ROM
 * 0x08360100-0x0836012C, EWRAM 0x02027680-0x020276AC): the fixed row
 * labels and the tyre and fuel option rows, in the main program's order sub_083402D8.c draws, the
 * twins of the main program's gPitMenuRowLabelTexts /
 * gPitMenuTireOptionTexts / gPitMenuFuelOptionTexts
 * (src/data/race_setup.c). Each entry points into
 * gModule_PitLabelBlock's packed strings. */

const u8 *const gModule_PitMenuRowLabelTexts[4] = { gUnk_0200CFD8, gUnk_0200CFD0, gUnk_0200CFC8, gUnk_0200CFC4 };
const u8 *const gModule_PitMenuTireOptionTexts[4] = { gUnk_0200D004, gUnk_0200CFF8, gUnk_0200CFEC, gUnk_0200CFE0 };
const u8 *const gModule_PitMenuFuelOptionTexts[3] = { gUnk_0200D030, gUnk_0200D020, gUnk_0200D010 };
