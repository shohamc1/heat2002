#include "global.h"
#include "data.h"
#include "structs.h"
#include "variables.h"

/* The m4a music player and song tables (0x0801DA90-0x0801DBBC), as tmc's
 * src/sound.c holds them: five players (background music, engine sound and
 * three sound effects), then the 30 songs gSongTable indexes by number.
 * A row names its player's MusicPlayerInfo and track array in EWRAM/IWRAM
 * (symbols.ld) and a song names its header, the label mid2agb gives it in
 * data/sound/sounds.s. The ms and me columns are the players a song's
 * m4aSongNumStart and m4aSongNumStop go through; they carry the same index.
 * The high module has its own pair of tables, in module_tables.c. */

const struct MusicPlayer gMPlayTable[5] = {
    { &gBgMusicPlayer, gUnk_02000000, 10, 0 },
    { &gEngineSoundPlayer, gUnk_02000320, 1, 0 },
    { &gMPlayInfo_SE2, gUnk_02000370, 1, 0 },
    { &gMPlayInfo_SE3, gUnk_020003C0, 1, 0 },
    { &gMPlayInfo_SE4, gUnk_02000410, 1, 0 },
};

const struct Song gSongTable[30] = {
    { &song_dummy, 0, 0 },
    { &song_01, 0, 0 },
    { &song_02, 0, 0 },
    { &song_03, 0, 0 },
    { &song_dummy, 0, 0 },
    { &song_dummy, 0, 0 },
    { &song_dummy, 0, 0 },
    { &song_dummy, 0, 0 },
    { &song_08, 1, 1 },
    { &song_09, 1, 1 },
    { &song_10, 1, 1 },
    { &song_11, 2, 2 },
    { &song_12, 2, 2 },
    { &song_13, 2, 2 },
    { &song_14, 3, 3 },
    { &song_15, 3, 3 },
    { &song_16, 4, 4 },
    { &song_17, 4, 4 },
    { &song_18, 2, 2 },
    { &song_19, 2, 2 },
    { &song_20, 2, 2 },
    { &song_21, 3, 3 },
    { &song_22, 3, 3 },
    { &song_23, 3, 3 },
    { &song_24, 2, 2 },
    { &song_25, 2, 2 },
    { &song_26, 2, 2 },
    { &song_27, 2, 2 },
    { &song_28, 3, 3 },
    { &song_29, 2, 2 },
};
