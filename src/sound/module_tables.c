#include "global.h"
#include "structs.h"
#include "variables.h"

/* The high module's music player and song tables (ROM 0x083454F4-0x083456EC,
 * EWRAM 0x0200CA74-0x0200CC6C), the twin of the main program's
 * src/sound/tables.c: four players (gNumMusicPlayersHigh), then 57 song
 * numbers -- all but two point at the empty module_song_dummy. The row's
 * players and track arrays live in the module's EWRAM outside the image
 * (symbols.ld); the songs themselves are in data/sound/module_songs.s. */

extern struct MusicPlayerTrack gUnk_02037000[]; /* gModule_MPlayTable's track arrays */
extern struct MusicPlayerTrack gUnk_02037280[];
extern struct MusicPlayerTrack gUnk_02037460[];
extern struct MusicPlayerTrack gUnk_02037500[];
extern struct SongHeader module_song_dummy; /* data/sound/module_songs.s */
extern struct SongHeader module_song_48;
extern struct SongHeader module_song_56;

const struct MusicPlayer gModule_MPlayTable[4] = {
    { &gModule_BgMusicPlayer, gUnk_02037000, 8, 0 },
    { &gModule_EngineSoundPlayer, gUnk_02037280, 6, 0 },
    { &gUnk_02038FF0, gUnk_02037460, 2, 0 },
    { &gUnk_02039040, gUnk_02037500, 2, 0 },
};

const struct Song gModule_SongTable[57] = {
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_48, 3, 3 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_dummy, 0, 0 },
    { &module_song_56, 1, 1 },
};
