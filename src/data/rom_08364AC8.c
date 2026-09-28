#include "global.h"
#include "structs.h"
/* no data.h: it declares gTextLayerMapPtr without const,
   which the users' bytes need; this file needs nothing else from it. */

extern const u8 gText_5th[];
extern const u8 gText_4th[];
extern const u8 gText_3rd[];
extern const u8 gText_2nd[];
extern const u8 gText_1st[];
extern u16 gUnk_0807CE30[];
extern u16 gUnk_0807EDEC[];
extern const u8 gUnk_08086D6C[];
extern const u8 gUnk_0808A98C[];
extern u16 gUnk_0808AB8C[];
extern u16 gUnk_0808C638[];
extern const u8 gUnk_080954F8[];
extern const u8 gUnk_0809C718[];
extern u16 gUnk_0809C918[];
extern u16 gUnk_0809D954[];
extern const u8 gUnk_080A6C74[];
extern u16 gUnk_080AAD54[];
extern u16 gUnk_080ABC14[];
extern const u8 gUnk_080B1434[];
extern const u8 gUnk_080B9234[];
extern u16 gUnk_080B9434[];
extern u16 gUnk_080BAEF0[];
extern const u8 gUnk_080CA7F0[];
extern u16 gUnk_080CE6D0[];
extern u16 gUnk_080D1EF0[];
extern const u8 gUnk_080EC8B0[];
extern const u8 gUnk_080F3FD0[];
extern u16 gUnk_080F41D0[];
extern u16 gUnk_080F613C[];
extern const u8 gUnk_0810721C[];
extern u16 gUnk_0810B27C[];
extern u16 gUnk_0810E2B0[];
extern const u8 gUnk_08125DD0[];
extern u16 gUnk_0812DF70[];
extern u16 gUnk_0812FE5C[];
extern const u8 gUnk_0813EDFC[];
extern const u8 gUnk_081428DC[];
extern u16 gUnk_08142ADC[];
extern u16 gUnk_08145D84[];
extern const u8 gUnk_0815E024[];
extern const u8 gUnk_08166024[];
extern u16 gUnk_08166224[];
extern u16 gUnk_081698F0[];
extern const u8 gUnk_08178110[];
extern u16 gUnk_0817C190[];
extern u16 gUnk_0817E918[];
extern const u8 gUnk_0818F958[];
extern const u8 gUnk_08197518[];
extern u16 gUnk_08197718[];
extern u16 gUnk_08198DC8[];
extern const u8 gUnk_081A34C8[];
extern u16 gUnk_081A4B88[];
extern u16 gUnk_081A7164[];
extern const u8 gUnk_081B4F24[];
extern u16 gUnk_081BCEE4[];
extern u16 gUnk_081C317C[];
extern const u8 gUnk_081C515C[];
extern const u8 gUnk_081C6ADC[];
extern u16 gUnk_081C6CDC[];
extern u16 gUnk_081C7EA8[];
extern const u8 gUnk_081C9BC8[];
extern const u8 gUnk_081CB608[];
extern u16 gUnk_081CB808[];
extern u16 gUnk_081CDE68[];
extern const u8 gUnk_081DECC8[];
extern u16 gUnk_081E2188[];
extern u16 gUnk_081E4A64[];
extern const u8 gUnk_081F8744[];
extern const u8 gUnk_08200444[];
extern u16 gUnk_08200644[];
extern u16 gUnk_08203A14[];
extern const u8 gUnk_0820E234[];
extern u16 gUnk_082121D4[];
extern u16 gUnk_08215980[];
extern const u8 gUnk_08228880[];
extern u16 gUnk_082307A0[];
extern u16 gUnk_08231DC8[];
extern const u8 gUnk_0823F128[];
extern const u8 gUnk_08242CA8[];
extern u16 gUnk_08242EA8[];
extern u16 gUnk_08244C24[];
extern const u8 gUnk_08253884[];
extern const u8 gUnk_0825B764[];
extern u16 gUnk_0825B964[];
extern u16 gUnk_0825D510[];
extern const u8 gUnk_082683F0[];
extern u16 gUnk_0826BC70[];
extern u16 gUnk_0826DE48[];
extern const u8 gUnk_0827AAA8[];
extern u16 gUnk_08282468[];
extern const u8 gUnk_08283E0C[];
extern u16 gUnk_0828519C[];
extern const u8 gUnk_082855D8[];
extern u16 gUnk_08285968[];
extern const u8 gUnk_082876D4[];
extern u16 gUnk_08288BD4[];
extern const u8 gUnk_0828AA90[];
extern u16 gUnk_0828BA60[];
extern const u8 gUnk_0828DD4C[];
extern u16 gUnk_0828F52C[];
extern const u8 gUnk_082914A0[];
extern u16 gUnk_08292650[];
extern const u8 gUnk_08293548[];
extern u16 gUnk_082939A8[];
extern const u8 gUnk_08295820[];
extern u16 gUnk_08296A30[];
extern const u8 gUnk_08298BE4[];
extern u16 gUnk_08299AF4[];
extern const u8 gUnk_0829B024[];
extern u16 gUnk_0829C7B4[];
extern const u8 gUnk_0829DBB0[];

const u32 gUnk_08364AC8[] = {
    (u32)gText_1st, (u32)gText_2nd, (u32)gText_3rd,
    (u32)gText_4th, (u32)gText_5th
};
// Its users declare it as u8 x.
const u8 gUnk_08364ADC[4] = { 4, 0, 0, 0 };
// The engine-sound base frequencies per gear; RunRace adds
// rpm * gEngineSoundRpmMultipliers[gear] >> 6 before playing (src/race/RunRace.c).
const u32 gEngineSoundFreqBases[5] = { 1200, 700, 550, 500, 300 };
// The engine-sound rpm multipliers per gear (gears 0-4, like
// gEngineSoundFreqBases).
const u8 gEngineSoundRpmMultipliers[5] = { 200, 190, 180, 160, 150 };
// No decompiled code reads these bytes yet.
const u8 gUnk_08364AF9[15] = {
    1, 1, 12, 2, 12, 12, 12, 2, 12, 12, 12, 12, 39, 0, 0
};
// Its users declare it as u16 *x, u32 *x, u32 x, u32 x[], vu32 x[].
// The one word is the text layer's BG map base in VRAM.
const u32 gTextLayerMapPtr[1] = { 0x600E000 };
// Its users declare it as struct Track x[].
// The 12 track records (struct Track, structs.h), one line per track:
// map tile/tilemap blobs, lane pointer tables, grid extents, the
// cell-value shuffles, and the per-track lap constants.
const struct Track gTrackData[12] = {
    { (u32)gUnk_08086D6C, (u32)gUnk_080954F8, 0x0, gUnk_0807EDEC, gUnk_0808C638, 0x0, (u32)gUnk_0808A98C, 0x0, gUnk_0807CE30, gUnk_0808AB8C, 0x0, 0x7d, 0x64, 0x7d, 0x64, 0x0, 0x0, gUnk_08282468, (u32)gUnk_08283E0C, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xfde, 0xd56, 0xcd2, { 0, 0 } },
    { (u32)gUnk_080A6C74, (u32)gUnk_080B1434, 0x0, gUnk_0809D954, gUnk_080ABC14, 0x0, (u32)gUnk_0809C718, 0x0, gUnk_0809C918, gUnk_080AAD54, 0x0, 0x7d, 0x64, 0x7d, 0x64, 0x0, 0x0, gUnk_0828519C, (u32)gUnk_082855D8, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0x81d, 0x75c, 0x21e, { 0, 0 } },
    { (u32)gUnk_080CA7F0, (u32)gUnk_080EC8B0, 0x0, gUnk_080BAEF0, gUnk_080D1EF0, 0x0, (u32)gUnk_080B9234, 0x0, gUnk_080B9434, gUnk_080CE6D0, 0x0, 0x7d, 0x64, 0x7d, 0x64, 0x0, 0x0, gUnk_08285968, (u32)gUnk_082876D4, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xd5d, 0x1c10, 0xeb5, { 0, 0 } },
    { (u32)gUnk_0810721C, (u32)gUnk_08125DD0, 0x0, gUnk_080F613C, gUnk_0810E2B0, 0x0, (u32)gUnk_080F3FD0, 0x0, gUnk_080F41D0, gUnk_0810B27C, (u32)gUnk_0810B27C, 0x7d, 0x64, 0x7d, 0x64, 0x0, 0x0, gUnk_08288BD4, (u32)gUnk_0828AA90, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xfb5, 0x1819, 0xf5d, { 0, 0 } },
    { (u32)gUnk_0813EDFC, (u32)gUnk_0815E024, 0x0, gUnk_0812FE5C, gUnk_08145D84, 0x0, (u32)gUnk_081428DC, 0x0, gUnk_0812DF70, gUnk_08142ADC, (u32)gUnk_08142ADC, 0x7d, 0x64, 0x7d, 0x64, 0x0, 0x0, gUnk_0828BA60, (u32)gUnk_0828DD4C, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xf75, 0x194d, 0x1176, { 0, 0 } },
    { (u32)gUnk_08178110, (u32)gUnk_0818F958, 0x0, gUnk_081698F0, gUnk_0817E918, 0x0, (u32)gUnk_08166024, 0x0, gUnk_08166224, gUnk_0817C190, (u32)gUnk_0817C190, 0x9b, 0x5a, 0x9b, 0x5a, 0x0, 0x0, gUnk_0828F52C, (u32)gUnk_082914A0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0x1b66, 0x13c3, 0xfba, { 0, 0 } },
    { (u32)gUnk_081A34C8, (u32)gUnk_081B4F24, 0x0, gUnk_08198DC8, gUnk_081A7164, 0x0, (u32)gUnk_08197518, 0x0, gUnk_08197718, gUnk_081A4B88, (u32)gUnk_081A4B88, 0x7d, 0x64, 0x7d, 0x64, 0x0, 0x0, gUnk_08292650, (u32)gUnk_08293548, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xb58, 0x12ec, 0x77c, { 0, 0 } },
    { (u32)gUnk_081C515C, (u32)gUnk_081C9BC8, 0x0, gUnk_081C317C, gUnk_081C7EA8, 0x0, (u32)gUnk_081C6ADC, 0x0, gUnk_081BCEE4, gUnk_081C6CDC, (u32)gUnk_081C6CDC, 0x7d, 0x64, 0x7d, 0x64, 0x0, 0x0, 0, 0x0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0x314c, 0x8e6, 0x0, { 0, 0 } },
    { (u32)gUnk_081DECC8, (u32)gUnk_081F8744, 0x0, gUnk_081CDE68, gUnk_081E4A64, 0x0, (u32)gUnk_081CB608, 0x0, gUnk_081CB808, gUnk_081E2188, (u32)gUnk_081E2188, 0x7d, 0x64, 0x7d, 0x64, 0x0, 0x0, gUnk_082939A8, (u32)gUnk_08295820, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0x132f, 0x146d, 0xf3b, { 0, 0 } },
    { (u32)gUnk_0820E234, (u32)gUnk_08228880, 0x0, gUnk_08203A14, gUnk_08215980, 0x0, (u32)gUnk_08200444, 0x0, gUnk_08200644, gUnk_082121D4, (u32)gUnk_082121D4, 0xba, 0x6a, 0xba, 0x6a, 0x0, 0x0, gUnk_08296A30, (u32)gUnk_08298BE4, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0x19e8, 0x1bd6, 0x10da, { 0, 0 } },
    { (u32)gUnk_0823F128, (u32)gUnk_08253884, 0x0, gUnk_08231DC8, gUnk_08244C24, 0x0, (u32)gUnk_08242CA8, 0x0, gUnk_082307A0, gUnk_08242EA8, (u32)gUnk_08242EA8, 0x7d, 0x64, 0x7d, 0x64, 0x0, 0x0, gUnk_08299AF4, (u32)gUnk_0829B024, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xb14, 0xebd, 0xa97, { 0, 0 } },
    { (u32)gUnk_082683F0, (u32)gUnk_0827AAA8, 0x0, gUnk_0825D510, gUnk_0826DE48, 0x0, (u32)gUnk_0825B764, 0x0, gUnk_0825B964, gUnk_0826BC70, (u32)gUnk_0826BC70, 0x7d, 0x6a, 0x7d, 0x6a, 0x0, 0x0, gUnk_0829C7B4, (u32)gUnk_0829DBB0, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0xdd5, 0x10eb, 0x9fd, { 0, 0 } },
};
