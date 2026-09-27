#include "global.h"
#include "data.h"

extern const u8 gUnk_08330D38[];
extern const u8 gUnk_08330D58[];
extern const u8 gUnk_08330D78[];
extern const u8 gUnk_08330D98[];
extern const u8 gUnk_08330DB8[];
extern const u8 gUnk_08330DD8[];
extern const u8 gUnk_08330DF8[];
extern const u8 gUnk_08330E18[];
extern const u8 gUnk_08330E38[];
extern const u8 gUnk_08330E58[];
extern const u8 gUnk_08330E78[];
extern const u8 gUnk_08330E98[];
extern const u8 gUnk_08330EB8[];
extern const u8 gUnk_08330ED8[];
extern const u8 gUnk_08330EF8[];
extern const u8 gUnk_08330F18[];
extern const u8 gUnk_08330F38[];
extern const u8 gUnk_08330F58[];
extern const u8 gUnk_08330F78[];
extern const u8 gUnk_08330F98[];
extern const u8 gUnk_08330FB8[];
extern const u8 gUnk_08330FD8[];
extern const u8 gUnk_08330FF8[];
extern const u8 gUnk_08331018[];
extern const u8 gUnk_08331038[];
extern const u8 gUnk_08331058[];
extern const u8 gUnk_08331078[];
extern const u8 gUnk_083311A8[];
extern const u8 gUnk_083311C8[];
extern const u8 gUnk_08365348[];
extern const u8 gUnk_08365618[];
extern const u8 gUnk_08365798[];
extern const u8 gUnk_08365A38[];
extern const u8 gUnk_08365CC0[];
extern const u8 gUnk_08366140[];
extern const u8 gUnk_08366470[];
extern const u8 gUnk_08366620[];
extern const u8 gUnk_083668A8[];
extern const u8 gUnk_08366A58[];
extern const u8 gUnk_08366DE8[];
extern const u8 gUnk_08366F38[];
extern const u8 gUnk_083FEF80[];
extern const u8 gUnk_083FF004[];
extern const u8 gUnk_083FF088[];
extern const u8 gUnk_083FF10C[];
extern const u8 gUnk_083FF190[];
extern const u8 gUnk_083FF214[];
extern const u8 gUnk_083FF298[];
extern const u8 gUnk_083FF31C[];
extern const u8 gUnk_083FF3A0[];
extern const u8 gUnk_083FF424[];
extern const u8 gUnk_083FF4A8[];
extern const u8 gUnk_083FF52C[];

// Its users declare it as struct SegBC4C *x[], u32 x[].
const u32 gUnk_083671C0[] = {
    (u32)gUnk_08365348, (u32)gUnk_08365618, (u32)gUnk_08365798,
    (u32)gUnk_08365A38, (u32)gUnk_08365CC0, (u32)gUnk_08366140,
    (u32)gUnk_08366470, (u32)gUnk_08366620, (u32)gUnk_083668A8,
    (u32)gUnk_08366A58, (u32)gUnk_08366DE8, (u32)gUnk_08366F38
};
const u32 gObjTileCache64Tiles[] = INCBIN_U32("build/assets/unknown/data_083671F0.bin");
const u32 gObjTileCache16Tiles[] = INCBIN_U32("build/assets/unknown/data_083671F8.bin");
const u32 gObjTileCache2Tiles[] = INCBIN_U32("build/assets/unknown/data_08367228.bin");
const u32 gObjTileCache8Tiles[] = INCBIN_U32("build/assets/unknown/data_08367268.bin");
const u32 gObjTileCache4Tiles[] = INCBIN_U32("build/assets/unknown/data_08367290.bin");
const u32 gObjTileCache1Tiles[] = INCBIN_U32("build/assets/unknown/data_083672B0.bin");
// Its users declare it as s32 x[], u32 x[].
const u32 gPitStallPositions[] = INCBIN_U32("build/assets/unknown/data_083672F0.bin");
const u16 gPitEntryProgressPoints[] = INCBIN_U16("build/assets/unknown/data_083675F0.bin");
const u16 gPitExitProgressPoints[] = INCBIN_U16("build/assets/unknown/data_08367608.bin");
const u8 gRacePointsTable[] = INCBIN_U8("build/assets/unknown/data_08367620.bin");
// Its users declare it as u32 *x[].
const u32 gDriverCarSpriteHalfATables[] = {
    (u32)gUnk_083FF424, (u32)gUnk_083FF424, (u32)gUnk_083FF52C,
    (u32)gUnk_083FF004, (u32)gUnk_083FF52C, (u32)gUnk_083FF214,
    (u32)gUnk_083FF10C, (u32)gUnk_083FF31C, (u32)gUnk_083FF52C,
    (u32)gUnk_083FF52C, (u32)gUnk_083FF31C, (u32)gUnk_083FF214,
    (u32)gUnk_083FF31C, (u32)gUnk_083FF424, (u32)gUnk_083FF10C,
    (u32)gUnk_083FF10C, (u32)gUnk_083FF424, (u32)gUnk_083FF214,
    (u32)gUnk_083FF10C, (u32)gUnk_083FF214, (u32)gUnk_083FF424,
    (u32)gUnk_083FF214, (u32)gUnk_083FF52C, (u32)gUnk_083FF10C,
    (u32)gUnk_083FF31C, (u32)gUnk_083FF004, (u32)gUnk_083FF004,
    (u32)gUnk_083FF004, (u32)gUnk_083FF31C, (u32)gUnk_083FF004
};
// Its users declare it as u32 *x[].
const u32 gDriverCarSpriteHalfBTables[] = {
    (u32)gUnk_083FF3A0, (u32)gUnk_083FF3A0, (u32)gUnk_083FF4A8,
    (u32)gUnk_083FEF80, (u32)gUnk_083FF4A8, (u32)gUnk_083FF190,
    (u32)gUnk_083FF088, (u32)gUnk_083FF298, (u32)gUnk_083FF4A8,
    (u32)gUnk_083FF4A8, (u32)gUnk_083FF298, (u32)gUnk_083FF190,
    (u32)gUnk_083FF298, (u32)gUnk_083FF3A0, (u32)gUnk_083FF088,
    (u32)gUnk_083FF088, (u32)gUnk_083FF3A0, (u32)gUnk_083FF190,
    (u32)gUnk_083FF088, (u32)gUnk_083FF190, (u32)gUnk_083FF3A0,
    (u32)gUnk_083FF190, (u32)gUnk_083FF4A8, (u32)gUnk_083FF088,
    (u32)gUnk_083FF298, (u32)gUnk_083FEF80, (u32)gUnk_083FEF80,
    (u32)gUnk_083FEF80, (u32)gUnk_083FF298, (u32)gUnk_083FEF80
};
// Its users declare it as u32 *x[].
const u32 gDriverPalettes[] = {
    (u32)gUnk_08330D38, (u32)gUnk_08330D58, (u32)gUnk_08330D78,
    (u32)gUnk_08330D98, (u32)gUnk_08330DB8, (u32)gUnk_08330DD8,
    (u32)gUnk_083311A8, (u32)gUnk_083311C8, (u32)gUnk_08330DF8,
    (u32)gUnk_08330E18, (u32)gUnk_08330E38, (u32)gUnk_08330E58,
    (u32)gUnk_08330E78, (u32)gUnk_08330E98, (u32)gUnk_08330EB8,
    (u32)gUnk_08330ED8, (u32)gUnk_08330EF8, (u32)gUnk_08330F18,
    (u32)gUnk_08330F38, (u32)gUnk_08330F58, (u32)gUnk_08330F78,
    (u32)gUnk_08330F98, (u32)gUnk_08330FB8, (u32)gUnk_08330FD8,
    (u32)gUnk_08330FF8, (u32)gUnk_08331018, (u32)gUnk_08331038,
    (u32)gUnk_08330D98, (u32)gUnk_08331058, (u32)gUnk_08331078
};
const u32 gTireGripDefaults[] = INCBIN_U32("build/assets/unknown/data_083677A8.bin");
// Its users declare it as struct Track x[].
const u32 gUnk_08367A14[] = INCBIN_U32("build/assets/unknown/data_08367A14.bin");
const u16 gUnk_08367B8C[] = INCBIN_U16("build/assets/unknown/data_08367B8C.bin");
const u8 gUnk_08367C10[] = INCBIN_U8("build/assets/unknown/data_08367C10.bin");
