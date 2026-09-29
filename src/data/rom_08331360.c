#include "global.h"
#include "data.h"

/* 0x08331360: 16-color OBJ palette for the minimap track-surface
 * tiles drawn around the player (sub_08008160, with gTrackTileSpriteFrames). */
const u8 gTrackTileSpritePalette[] = INCBIN_U8("build/assets/graphics/palettes/track_tile_sprite.pal.bin");
