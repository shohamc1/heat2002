#include "global.h"
#include "data.h"

/* 0x08331188: 16-color OBJ palette (white ramp) for the drafting
 * streak particles at the car's corners (sub_0800B658, spawned while
 * drafting). */
const u8 gDraftStreakPalette[] = INCBIN_U8("build/assets/unknown/data_08331188.bin");
