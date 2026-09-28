#include "global.h"
#include "data.h"

/* 0x08330D18: 16-color OBJ palette (gray-brown ramp) for the
 * tire-skid smoke particles (sub_0800B7E0, spawned when tire slip
 * exceeds gTireSlipLimit). */
const u8 gSkidSmokePalette[] = INCBIN_U8("build/assets/unknown/data_08330D18.bin");
