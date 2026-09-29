#include "global.h"
#include "data.h"

/* 0x08331F88: two 16-color OBJ palettes for the damaged-car smoke
 * particles (DamageSmokeTask, spawned while damage is high); the first
 * is the skid-smoke palette (gSkidSmokePalette) again. */
const u8 gDamageSmokePalettes[] = INCBIN_U8("build/assets/graphics/palettes/damage_smoke.pal.bin");
