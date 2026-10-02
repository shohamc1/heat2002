#include "global.h"
#include "gba/defines.h"
#include "structs.h"
#include "engine_sound_tables.h"

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

#if PLATFORM_GBA
const u32 gUnk_08364AC8[] = { (u32)gText_1st, (u32)gText_2nd, (u32)gText_3rd, (u32)gText_4th, (u32)gText_5th };
#else
// Hosted twin: the five words are the 1st-5th place texts, held as
// pointers at host width. The only live user (multiboot.c) takes the
// symbol's address as the ROM-end marker, so the element type is free.
const u8 *const gUnk_08364AC8[] = { gText_1st, gText_2nd, gText_3rd, gText_4th, gText_5th };
#endif
// Its users declare it as u8 x.
const u8 gUnk_08364ADC[4] = UNK_08364ADC;
// The engine-sound base frequencies per gear; RunRace adds
// rpm * gEngineSoundRpmMultipliers[gear] >> 6 before playing (src/race/RunRace.c).
const u32 gEngineSoundFreqBases[5] = ENGINE_SOUND_FREQ_BASES;
// The engine-sound rpm multipliers per gear (gears 0-4, like
// gEngineSoundFreqBases).
const u8 gEngineSoundRpmMultipliers[5] = ENGINE_SOUND_RPM_MULTIPLIERS;
// No decompiled code reads these bytes yet.
const u8 gUnk_08364AF9[15] = UNK_08364AF9;
// Its users declare it as u16 *x, u32 *x, u32 x, u32 x[], vu32 x[].
// The one word is the text layer's BG map base in VRAM; the hosted build
// stores the same base as a real pointer into its VRAM array.
#if PLATFORM_GBA
const u32 gTextLayerMapPtr[1] = { 0x600E000 };
#else
const u8 *gTextLayerMapPtr[1] = { VRAM + 0xE000 };
#endif
// Its users declare it as struct Track x[].
// The 12 track records (struct Track, structs.h), one line per track:
// map tile/tilemap blobs, lane pointer tables, grid extents, the
// cell-value shuffles, and the per-track lap constants. The three RLE
// stream lengths INCBIN the .len files the track asset type builds from
// each track's editable .tmx (assets/tracks/NAME/), so an edit to a map
// layer moves the lengths with the stream it re-encodes.
const struct Track gTrackData[12] = {
    { gUnk_08086D6C,
      gUnk_080954F8,
      0x0,
      gUnk_0807EDEC,
      gUnk_0808C638,
      0x0,
      gUnk_0808A98C,
      0x0,
      gUnk_0807CE30,
      gUnk_0808AB8C,
      0x0,
      125,
      100,
      125,
      100,
      0x0,
      0x0,
      gUnk_08282468,
      gUnk_08283E0C,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/hooley_downs/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/hooley_downs/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/hooley_downs/cellMap.len"),
      { 0, 0 } },
    { gUnk_080A6C74,
      gUnk_080B1434,
      0x0,
      gUnk_0809D954,
      gUnk_080ABC14,
      0x0,
      gUnk_0809C718,
      0x0,
      gUnk_0809C918,
      gUnk_080AAD54,
      0x0,
      125,
      100,
      125,
      100,
      0x0,
      0x0,
      gUnk_0828519C,
      gUnk_082855D8,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/darlington_raceway/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/darlington_raceway/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/darlington_raceway/cellMap.len"),
      { 0, 0 } },
    { gUnk_080CA7F0,
      gUnk_080EC8B0,
      0x0,
      gUnk_080BAEF0,
      gUnk_080D1EF0,
      0x0,
      gUnk_080B9234,
      0x0,
      gUnk_080B9434,
      gUnk_080CE6D0,
      0x0,
      125,
      100,
      125,
      100,
      0x0,
      0x0,
      gUnk_08285968,
      gUnk_082876D4,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/green_valley/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/green_valley/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/green_valley/cellMap.len"),
      { 0, 0 } },
    { gUnk_0810721C,
      gUnk_08125DD0,
      0x0,
      gUnk_080F613C,
      gUnk_0810E2B0,
      0x0,
      gUnk_080F3FD0,
      0x0,
      gUnk_080F41D0,
      gUnk_0810B27C,
      gUnk_0810B27C,
      125,
      100,
      125,
      100,
      0x0,
      0x0,
      gUnk_08288BD4,
      gUnk_0828AA90,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/michigan_international_speedway/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/michigan_international_speedway/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/michigan_international_speedway/cellMap.len"),
      { 0, 0 } },
    { gUnk_0813EDFC,
      gUnk_0815E024,
      0x0,
      gUnk_0812FE5C,
      gUnk_08145D84,
      0x0,
      gUnk_081428DC,
      0x0,
      gUnk_0812DF70,
      gUnk_08142ADC,
      gUnk_08142ADC,
      125,
      100,
      125,
      100,
      0x0,
      0x0,
      gUnk_0828BA60,
      gUnk_0828DD4C,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/great_canyon/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/great_canyon/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/great_canyon/cellMap.len"),
      { 0, 0 } },
    { gUnk_08178110,
      gUnk_0818F958,
      0x0,
      gUnk_081698F0,
      gUnk_0817E918,
      0x0,
      gUnk_08166024,
      0x0,
      gUnk_08166224,
      gUnk_0817C190,
      gUnk_0817C190,
      155,
      90,
      155,
      90,
      0x0,
      0x0,
      gUnk_0828F52C,
      gUnk_082914A0,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/fuji_port/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/fuji_port/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/fuji_port/cellMap.len"),
      { 0, 0 } },
    { gUnk_081A34C8,
      gUnk_081B4F24,
      0x0,
      gUnk_08198DC8,
      gUnk_081A7164,
      0x0,
      gUnk_08197518,
      0x0,
      gUnk_08197718,
      gUnk_081A4B88,
      gUnk_081A4B88,
      125,
      100,
      125,
      100,
      0x0,
      0x0,
      gUnk_08292650,
      gUnk_08293548,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/crawfish_raceway/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/crawfish_raceway/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/crawfish_raceway/cellMap.len"),
      { 0, 0 } },
    { gUnk_081C515C,
      gUnk_081C9BC8,
      0x0,
      gUnk_081C317C,
      gUnk_081C7EA8,
      0x0,
      gUnk_081C6ADC,
      0x0,
      gUnk_081BCEE4,
      gUnk_081C6CDC,
      gUnk_081C6CDC,
      125,
      100,
      125,
      100,
      0x0,
      0x0,
      0,
      0x0,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/purley_park/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/purley_park/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/purley_park/cellMap.len"),
      { 0, 0 } },
    { gUnk_081DECC8,
      gUnk_081F8744,
      0x0,
      gUnk_081CDE68,
      gUnk_081E4A64,
      0x0,
      gUnk_081CB608,
      0x0,
      gUnk_081CB808,
      gUnk_081E2188,
      gUnk_081E2188,
      125,
      100,
      125,
      100,
      0x0,
      0x0,
      gUnk_082939A8,
      gUnk_08295820,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/kansas_speedway/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/kansas_speedway/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/kansas_speedway/cellMap.len"),
      { 0, 0 } },
    { gUnk_0820E234,
      gUnk_08228880,
      0x0,
      gUnk_08203A14,
      gUnk_08215980,
      0x0,
      gUnk_08200444,
      0x0,
      gUnk_08200644,
      gUnk_082121D4,
      gUnk_082121D4,
      186,
      106,
      186,
      106,
      0x0,
      0x0,
      gUnk_08296A30,
      gUnk_08298BE4,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/asphalt_city/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/asphalt_city/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/asphalt_city/cellMap.len"),
      { 0, 0 } },
    { gUnk_0823F128,
      gUnk_08253884,
      0x0,
      gUnk_08231DC8,
      gUnk_08244C24,
      0x0,
      gUnk_08242CA8,
      0x0,
      gUnk_082307A0,
      gUnk_08242EA8,
      gUnk_08242EA8,
      125,
      100,
      125,
      100,
      0x0,
      0x0,
      gUnk_08299AF4,
      gUnk_0829B024,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/phoenix_international_raceway/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/phoenix_international_raceway/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/phoenix_international_raceway/cellMap.len"),
      { 0, 0 } },
    { gUnk_082683F0,
      gUnk_0827AAA8,
      0x0,
      gUnk_0825D510,
      gUnk_0826DE48,
      0x0,
      gUnk_0825B764,
      0x0,
      gUnk_0825B964,
      gUnk_0826BC70,
      gUnk_0826BC70,
      125,
      106,
      125,
      106,
      0x0,
      0x0,
      gUnk_0829C7B4,
      gUnk_0829DBB0,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      INCBIN_U16("build/assets/tracks/infogrames_super_speedway/bg3Map.len"),
      INCBIN_U16("build/assets/tracks/infogrames_super_speedway/bg2Map.len"),
      INCBIN_U16("build/assets/tracks/infogrames_super_speedway/cellMap.len"),
      { 0, 0 } },
};
