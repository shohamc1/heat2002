#include "global.h"
#include "data.h"
#include "sin_table.h"

/* Sine lookup, one entry per 1/256 turn: sin(2*pi*i/256) * 256, rounded
 * (amplitude 256, max 256 at i=64, min -256 at i=192, zeros at 0/128/256).
 * 320 entries = 1.25 periods, so the interpolating users can read [i+1]
 * past the last full period. 0x0801CD08-0x0801CF88. The initialisers
 * live in sin_table.h, shared with the high module's byte-identical
 * copy (src/data/rom_08344E68.c): the ROM holds the table twice, once
 * per GBA. */

const s16 gSinTable[320] = SIN_TABLE;
