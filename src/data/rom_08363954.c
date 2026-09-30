#include "global.h"
#include "structs.h"

extern const u8 gModule_Frontleft[];
extern const u8 gModule_Frontright[];
extern const u8 gModule_Rearleft[];
extern const u8 gModule_Rearright[];
extern const u8 gModule_Back[];
extern const u8 gModule_Front[];
extern const u8 gModule_Left[];
extern const u8 gModule_Right[];
/* The wall-data labels data/rom_0836012C.s defines (EWRAM names). */
extern struct Pt gUnk_02027810[];
extern struct WallRec gUnk_02027DB0[];
extern u16 gUnk_020293F0[];
extern u16 gUnk_02029CD4[];

/* High module (link slave) wall and tyre-name tables (ROM
 * 0x08363954-0x08363988, EWRAM 0x0202AF44-0x0202AF78). */

/* The link track's walls (struct TrackWalls, structs.h): the wall
 * vertices, wall records and the 48x48 cell grid module_walls.c walks.
 * The main program's twelve-row gTrackWallTables
 * (src/data/rom_083FD91C.c) says what each field is; this one row's
 * blobs live in the module's track-data tail, labelled by their EWRAM
 * addresses in data/rom_0836012C.s. */
const struct TrackWalls gModule_TrackWallTables[1] = {
    { gUnk_02027810, gUnk_02027DB0, 0xB2, gUnk_020293F0, gUnk_02029CD4 },
};

/* The eight tyre-position names in the pit menu's order, the twin of
 * the main program's gUnk_083FDA0C (src/data/rom_083FD91C.c); the
 * strings are high_module_text.c's tyre block. */
const u8 *const gModule_TirePositionTexts[8] = { gModule_Frontleft, gModule_Frontright, gModule_Rearleft,
                                                 gModule_Rearright, gModule_Back,      gModule_Front,
                                                 gModule_Left,      gModule_Right };
