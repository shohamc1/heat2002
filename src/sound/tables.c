#include "global.h"
#include "data.h"
#include "structs.h"
#include "m4a.h"
#include "variables.h"

/* The players' track arrays in EWRAM (0x02000000-0x02000460), defined in
   address order (ldscript.ld's .bss_tables places the section at
   gUnk_02000000's address). Each row of gMPlayTable below names its
   player's array here; the background-music player owns 10 tracks, each
   sound-effect player one, and a struct MusicPlayerTrack is 0x50 bytes. */
EWRAM_DATA struct MusicPlayerTrack gUnk_02000000[10] = {0};
EWRAM_DATA struct MusicPlayerTrack gUnk_02000320[1] = {0};
EWRAM_DATA struct MusicPlayerTrack gUnk_02000370[1] = {0};
EWRAM_DATA struct MusicPlayerTrack gUnk_020003C0[1] = {0};
EWRAM_DATA struct MusicPlayerTrack gUnk_02000410[1] = {0};

/* The m4a music player and song tables (0x0801DA90-0x0801DBBC), as tmc's
 * src/sound.c holds them: five players (background music, engine sound and
 * three sound effects), then the 30 songs gSongTable indexes by number.
 * A row names its player's MusicPlayerInfo and track array in EWRAM/IWRAM
 * (symbols.ld) and a song names its header, the label mid2agb gives it in
 * data/sound/sounds.s. The ms column is the player m4aSongNumStart and
 * m4aSongNumStop use; no code reads me, which repeats it. The high module has its own pair of tables, in module_tables.c. */

const struct MusicPlayer gMPlayTable[5] = {
    { &gBgMusicPlayer, gUnk_02000000, 10, 0 },
    { &gEngineSoundPlayer, gUnk_02000320, 1, 0 },
    { &gMPlayInfo_SE2, gUnk_02000370, 1, 0 },
    { &gMPlayInfo_SE3, gUnk_020003C0, 1, 0 },
    { &gMPlayInfo_SE4, gUnk_02000410, 1, 0 },
};

#if PORTABLE
/* StopAllSongsAndVSyncOff (src/sound/stop_songs.c) walks song numbers
   0..0x63 although the table holds 30 rows; on the GBA the reads land in
   the ROM data that follows and every comparison quietly fails. A hosted
   build cannot read past the array, so the port pads the table to the
   walked range with dummy rows. The GBA build keeps the 30-row table. */
#define SONG_TABLE_ROWS (30 + 70)
#else
#define SONG_TABLE_ROWS 30
#endif

const struct Song gSongTable[SONG_TABLE_ROWS] = {
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
#if PORTABLE
    [30 ... 99] = { &song_dummy, 0, 0 },
#endif
};
