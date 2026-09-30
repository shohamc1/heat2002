#include "global.h"
#include "structs.h"

/* The track-segment blob label data/rom_0835DCA0.s defines (EWRAM
 * name). */
extern struct TrackSeg gUnk_02025E20[];

/* High module (link slave) track-segment table (ROM 0x0835F440,
 * EWRAM 0x02025E60): the one row ModuleLoadTrackSegs loads its
 * gModule_TrackSegs from. The segment records themselves live in the
 * module's track-data blob behind gUnk_02025E20
 * (data/rom_0835DCA0.s). */

const struct TrackSeg *const gModule_TrackSegTables[1] = { gUnk_02025E20 };
