#include "global.h"
#include "data.h"

extern const u8 gHighModuleRom[];

// The high module's 32 KB chunks, as SendMultibootPayload sends them.
const u32 gUnk_0807C9CC[] = {
    (u32)gHighModuleRom, (u32)gHighModuleRom + 0x8000,
    (u32)gHighModuleRom + 0x10000, (u32)gHighModuleRom + 0x18000,
    (u32)gHighModuleRom + 0x20000, (u32)gHighModuleRom + 0x28000,
    (u32)gHighModuleRom + 0x30000
};
// Its users declare it as u32 x.
const u32 gUnk_0807C9E8[] = INCBIN_U32("build/assets/unknown/data_0807C9E8.bin");
const u8 gUnk_0807C9F0[] = INCBIN_U8("build/assets/unknown/data_0807C9F0.bin");
const u8 gUnk_0807CA08[] = INCBIN_U8("build/assets/unknown/data_0807CA08.bin");
const u8 gUnk_0807CA20[] = INCBIN_U8("build/assets/unknown/data_0807CA20.bin");
const u8 gUnk_0807CA34[] = INCBIN_U8("build/assets/unknown/data_0807CA34.bin");
const u8 gUnk_0807CA60[] = INCBIN_U8("build/assets/unknown/data_0807CA60.bin");
