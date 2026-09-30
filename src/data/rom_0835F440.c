#include "global.h"
#include "structs.h"
#include "race_setup_tables.h"

/* The track-segment blob label data/rom_0835DCA0.s defines (EWRAM
 * name). */
extern struct TrackSeg gUnk_02025E20[];

/* The frame lists src/data/rom_083639A8.c defines, and the first
 * driver palette in the module's copy fragment data/rom_08354010.s. */
extern const u8 *const gModule_CarSpriteHalfAFrames[];
extern const u8 *const gModule_CarSpriteHalfBFrames[];
extern const u8 gModule_0201E748[];

/* High module (link slave) track-segment table (ROM 0x0835F440,
 * EWRAM 0x02025E60): the one row ModuleLoadTrackSegs loads its
 * gModule_TrackSegs from. The segment records themselves live in the
 * module's track-data blob behind gUnk_02025E20
 * (data/rom_0835DCA0.s). */

const struct TrackSeg *const gModule_TrackSegTables[1] = { gUnk_02025E20 };

/* High module (link slave) sprite-cache slots, pit and points tables
 * (ROM 0x0835F444-0x0835F8A0, EWRAM 0x020269C4-0x02026E20), the twins of
 * the main program's gObjTileCache64Tiles to gRacePointsTable
 * (src/data/race_setup.c, which says what each is for): the numbers
 * build from race_setup_tables.h. The car sprite and palette tables
 * hold one row each, where the main program's hold 30. */

const u16 gModule_ObjTileCache64Tiles[4] = OBJ_TILE_CACHE_64_TILES;
const u16 gModule_ObjTileCache16Tiles[24] = OBJ_TILE_CACHE_16_TILES;
const u16 gModule_ObjTileCache2Tiles[32] = OBJ_TILE_CACHE_2_TILES;
const u16 gModule_ObjTileCache8Tiles[20] = OBJ_TILE_CACHE_8_TILES;
const u16 gModule_ObjTileCache4Tiles[16] = OBJ_TILE_CACHE_4_TILES;
const u16 gModule_ObjTileCache1Tiles[32] = OBJ_TILE_CACHE_1_TILES;
const u32 gModule_PitStallPositions[192] = PIT_STALL_POSITIONS;
const u16 gModule_PitEntryProgressPoints[12] = PIT_ENTRY_PROGRESS_POINTS;
const u16 gModule_PitExitProgressPoints[12] = PIT_EXIT_PROGRESS_POINTS;
const u8 gModule_RacePointsTable[32] = RACE_POINTS_TABLE;
const u8 *const *const gModule_DriverCarSpriteHalfATables[1] = { gModule_CarSpriteHalfAFrames };
const u8 *const *const gModule_DriverCarSpriteHalfBTables[1] = { gModule_CarSpriteHalfBFrames };
const u8 *const gModule_DriverPalettes[1] = { gModule_0201E748 };
