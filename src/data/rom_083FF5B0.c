#include "global.h"
#include "data.h"

/* 0x083FF5B0-0x083FF724: OBJ gfx frame lists. gSplashSpriteFrames is
 * the 23-frame animation shared by the splash loop (RaceStartSplashTask), the
 * race intro (LinkRaceStartSplashTask) and the start countdown (sub_0800B1A4);
 * the four tables after it feed the race particle effects and the
 * minimap track tiles. */

extern const u8 gUnk_0832FA68[];
extern const u8 gUnk_0832FB20[];
extern const u8 gUnk_0832FBD8[];
extern const u8 gUnk_0832FC88[];
extern const u8 gUnk_0832FD24[];
extern const u8 gUnk_0832FDBC[];
extern const u8 gUnk_0832FE58[];
extern const u8 gUnk_0832FF34[];
extern const u8 gUnk_0832FFFC[];
extern const u8 gUnk_083300C8[];
extern const u8 gUnk_0833018C[];
extern const u8 gUnk_08330240[];
extern const u8 gUnk_083302FC[];
extern const u8 gUnk_083303BC[];
extern const u8 gUnk_08330468[];
extern const u8 gUnk_08330504[];
extern const u8 gUnk_0833059C[];
extern const u8 gUnk_08330628[];
extern const u8 gUnk_083306FC[];
extern const u8 gUnk_083307BC[];
extern const u8 gUnk_08330880[];
extern const u8 gUnk_0833095C[];
extern const u8 gUnk_08330A1C[];
extern const u8 gUnk_08330AF4[];
extern const u8 gUnk_08330B0C[];
extern const u8 gUnk_08330B24[];
extern const u8 gUnk_08330B40[];
extern const u8 gUnk_08330B5C[];
extern const u8 gUnk_08330B7C[];
extern const u8 gUnk_08330BA4[];
extern const u8 gUnk_08330BCC[];
extern const u8 gUnk_08330BF4[];
extern const u8 gUnk_08330C1C[];
extern const u8 gUnk_08330C40[];
extern const u8 gUnk_08330C68[];
extern const u8 gUnk_08330C90[];
extern const u8 gUnk_08330CB8[];
extern const u8 gUnk_08330CDC[];
extern const u8 gUnk_08330CFC[];
extern const u8 gUnk_08331098[];
extern const u8 gUnk_083310A8[];
extern const u8 gUnk_083310B8[];
extern const u8 gUnk_083310C8[];
extern const u8 gUnk_083310D8[];
extern const u8 gUnk_083310E8[];
extern const u8 gUnk_083310F8[];
extern const u8 gUnk_08331108[];
extern const u8 gUnk_08331118[];
extern const u8 gUnk_08331128[];
extern const u8 gUnk_08331138[];
extern const u8 gUnk_08331148[];
extern const u8 gUnk_08331158[];
extern const u8 gUnk_08331164[];
extern const u8 gUnk_08331170[];
extern const u8 gUnk_0833117C[];
extern const u8 gUnk_083311E8[];
extern const u8 gUnk_08331224[];
extern const u8 gUnk_08331260[];
extern const u8 gUnk_083312A0[];
extern const u8 gUnk_083312E0[];
extern const u8 gUnk_08331320[];
extern const u8 gUnk_08331380[];
extern const u8 gUnk_083313A0[];
extern const u8 gUnk_083313C8[];
extern const u8 gUnk_083313F8[];
extern const u8 gUnk_08331438[];
extern const u8 gUnk_08331480[];
extern const u8 gUnk_083314CC[];
extern const u8 gUnk_08331520[];
extern const u8 gUnk_08331574[];
extern const u8 gUnk_083315D0[];
extern const u8 gUnk_08331638[];
extern const u8 gUnk_083316A8[];
extern const u8 gUnk_0833171C[];
extern const u8 gUnk_08331798[];
extern const u8 gUnk_0833181C[];
extern const u8 gUnk_083318A0[];
extern const u8 gUnk_08331924[];
extern const u8 gUnk_083319A8[];
extern const u8 gUnk_08331A28[];
extern const u8 gUnk_08331AA8[];
extern const u8 gUnk_08331B20[];
extern const u8 gUnk_08331B94[];
extern const u8 gUnk_08331C08[];
extern const u8 gUnk_08331C7C[];
extern const u8 gUnk_08331CEC[];
extern const u8 gUnk_08331D54[];
extern const u8 gUnk_08331DBC[];
extern const u8 gUnk_08331E1C[];
extern const u8 gUnk_08331E74[];
extern const u8 gUnk_08331EC4[];
extern const u8 gUnk_08331F0C[];
extern const u8 gUnk_08331F4C[];

const u8 *const gSplashSpriteFrames[] = { gUnk_0832FA68, gUnk_0832FB20, gUnk_0832FBD8, gUnk_0832FC88, gUnk_0832FD24,
                                          gUnk_0832FDBC, gUnk_0832FE58, gUnk_0832FF34, gUnk_0832FFFC, gUnk_083300C8,
                                          gUnk_0833018C, gUnk_08330240, gUnk_083302FC, gUnk_083303BC, gUnk_08330468,
                                          gUnk_08330504, gUnk_0833059C, gUnk_08330628, gUnk_083306FC, gUnk_083307BC,
                                          gUnk_08330880, gUnk_0833095C, gUnk_08330A1C };
const u8 *const gSkidSmokeFrames[] = { gUnk_08330AF4, gUnk_08330B0C, gUnk_08330B24, gUnk_08330B40,
                                       gUnk_08330B5C, gUnk_08330B7C, gUnk_08330BA4, gUnk_08330BCC,
                                       gUnk_08330BF4, gUnk_08330C1C, gUnk_08330C40, gUnk_08330C68,
                                       gUnk_08330C90, gUnk_08330CB8, gUnk_08330CDC, gUnk_08330CFC };
const u8 *const gDraftStreakFrames[] = { gUnk_08331098, gUnk_083310A8, gUnk_083310B8, gUnk_083310C8,
                                         gUnk_083310D8, gUnk_083310E8, gUnk_083310F8, gUnk_08331108,
                                         gUnk_08331118, gUnk_08331128, gUnk_08331138, gUnk_08331148,
                                         gUnk_08331158, gUnk_08331164, gUnk_08331170, gUnk_0833117C };
const u8 *const gTrackTileSpriteFrames[] = { gUnk_083311E8, gUnk_08331224, gUnk_08331260,
                                             gUnk_083312A0, gUnk_083312E0, gUnk_08331320 };
const u8 *const gDamageSmokeFrames[] = { gUnk_08331380, gUnk_083313A0, gUnk_083313C8, gUnk_083313F8, gUnk_08331438,
                                         gUnk_08331480, gUnk_083314CC, gUnk_08331520, gUnk_08331574, gUnk_083315D0,
                                         gUnk_08331638, gUnk_083316A8, gUnk_0833171C, gUnk_08331798, gUnk_0833181C,
                                         gUnk_083318A0, gUnk_08331924, gUnk_083319A8, gUnk_08331A28, gUnk_08331AA8,
                                         gUnk_08331B20, gUnk_08331B94, gUnk_08331C08, gUnk_08331C7C, gUnk_08331CEC,
                                         gUnk_08331D54, gUnk_08331DBC, gUnk_08331E1C, gUnk_08331E74, gUnk_08331EC4,
                                         gUnk_08331F0C, gUnk_08331F4C };
