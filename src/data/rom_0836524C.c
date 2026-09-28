#include "global.h"
#include "data.h"

extern const u8 gText_01234[];
extern const u8 gText_BlankRow4[];
extern const u8 gText_BlankRow32[];
extern const u8 gUnk_08364FBC[];
extern const u8 gUnk_0836500C[];
extern const u8 gUnk_0836509C[];
extern const u8 gUnk_08365114[];
extern const u8 gUnk_08365174[];
extern const u8 gUnk_083651C4[];

const u32 gUnk_0836524C[] = {
    (u32)gUnk_08364FBC, 0, (u32)gUnk_0836500C, 0, (u32)gUnk_0836509C,
    (u32)gUnk_08365114, 0, 0, 0, (u32)gUnk_083651C4, 0, (u32)gUnk_08365174, 0,
    0, 0, 0, 0x2000, 0xFF, 0xFF, 0xFF, 0xFF, 0x18000, 0x4, 0x4, 0x4, 0x4,
    0x400
};
const s32 gUnk_083652B8[] = INCBIN_S32("build/assets/unknown/data_083652B8.bin");
const s32 gUnk_083652E0[] = INCBIN_S32("build/assets/unknown/data_083652E0.bin");
const s32 gUnk_08365308[] = INCBIN_S32("build/assets/unknown/data_08365308.bin");
const u8 gTrackCountdownExtraSeconds[] = INCBIN_U8("build/assets/unknown/data_08365330.bin");
// Its users declare it as u8 *x.
const u32 gUnk_0836533C = (u32)gText_01234;
// Its users declare it as u8 *x.
u8 * const gUnk_08365340 = (u8 *)gText_BlankRow4;
// Its users declare it as u8 *x.
const u32 gUnk_08365344 = (u32)gText_BlankRow32;
