#include "global.h"
#include "engine_sound_tables.h"
#include "structs.h"
#include "race_setup_tables.h"

extern const u8 gModule_Text_Checkpoint[];
extern const u8 gModule_Text_DeKontrollpunkt[];
extern const u8 gModule_Text_DeLapTime[];
extern const u8 gModule_Text_DeLinkFail[];
extern const u8 gModule_Text_DeOutOfTime[];
extern const u8 gModule_Text_DePressStart[];
extern const u8 gModule_Text_DeRaceOver[];
extern const u8 gModule_Text_DeWaiting[];
extern const u8 gModule_Text_EsControl[];
extern const u8 gModule_Text_EsLapTime[];
extern const u8 gModule_Text_EsLinkFail[];
extern const u8 gModule_Text_EsOutOfTime[];
extern const u8 gModule_Text_EsPressStart[];
extern const u8 gModule_Text_EsRaceOver[];
extern const u8 gModule_Text_EsWaiting[];
extern const u8 gModule_Text_FrControle[];
extern const u8 gModule_Text_FrLapTime[];
extern const u8 gModule_Text_FrLinkFail[];
extern const u8 gModule_Text_FrOutOfTime[];
extern const u8 gModule_Text_FrPressStart[];
extern const u8 gModule_Text_FrRaceOver[];
extern const u8 gModule_Text_FrWaiting[];
extern const u8 gModule_Text_ItControllo[];
extern const u8 gModule_Text_ItLapTime[];
extern const u8 gModule_Text_ItLinkFail[];
extern const u8 gModule_Text_ItOutOfTime[];
extern const u8 gModule_Text_ItPressStart[];
extern const u8 gModule_Text_ItRaceOver[];
extern const u8 gModule_Text_ItWaiting[];
extern const u8 gModule_Text_LapTime[];
extern const u8 gModule_Text_LinkFail[];
extern const u8 gModule_Text_OutOfTime[];
extern const u8 gModule_Text_Pausa[];
extern const u8 gModule_Text_Pause[];
extern const u8 gModule_Text_PressStart[];
extern const u8 gModule_Text_RaceOver[];
extern const u8 gModule_Text_Waiting[];

/* no variables.h needed: ModuleGetString.c declares this table locally,
   and this file needs nothing else from it. */

/* The place names src/data/high_module_text.c defines. */
extern const u8 gModule_Text_1st[];
extern const u8 gModule_Text_2nd[];
extern const u8 gModule_Text_3rd[];
extern const u8 gModule_Text_4th[];
extern const u8 gModule_Text_5th[];

/* The track-data blob labels data/rom_08345BF8.s defines (EWRAM names):
 * the u16 ones fill this record's pointer fields, the u32-word ones its
 * raw word fields (cast at the use). */
extern u16 gUnk_0201044C[];
extern u16 gUnk_02013FAC[];
extern u16 gUnk_0200D378[];
extern u32 gUnk_0201242C[];
extern u32 gUnk_02018DA0[];
extern u32 gUnk_02017080[];
extern u32 gUnk_02013DAC[];

/* Three rows inside gModule_PitLabelBlock (high_module_text.c), named
 * in symbols.ld. */
extern const u8 gUnk_0200CF98[]; /* 01234 */
extern const u8 gUnk_0200CFA0[]; /* a blank row of 4 */
extern const u8 gUnk_0200CFA4[]; /* a blank row of 32 */

/* no variables.h: it declares gModule_TextLayerMapPtr without const and
   gModule_TrackData as non-const struct Track, which the readers' bytes
   need; this file needs nothing else from it. */

/* ROM 0x0835DB58-0x0835DB70, EWRAM 0x020250D8-0x020250F0: the twins of
 * the main program's gUnk_08364AC8 (the place names, 1ST to 5TH) and
 * gUnk_08364ADC (src/data/race_data.c). ModuleRunRace writes
 * gUnk_020250EC in place, as RunRace writes its twin; the image runs
 * from EWRAM, so here the write sticks. */
const u32 gModule_020250D8[5] = { (u32)gModule_Text_1st, (u32)gModule_Text_2nd, (u32)gModule_Text_3rd,
                                  (u32)gModule_Text_4th, (u32)gModule_Text_5th };
const u8 gUnk_020250EC[4] = UNK_08364ADC;

/* High module (link slave) localized message table (ROM
 * 0x0835DB70-0x0835DC10, EWRAM 0x020250F0-0x02025190): eight messages
 * (include/functions.h's MODULE_MSG_*) in the five languages the link
 * handshake negotiates (gModule_Language: EN, FR, DE, ES, IT).
 * ModuleGetString returns row[id][language]. The strings live in
 * src/data/high_module_text.c. The ROM leaves the Italian OUT OF TIME row
 * empty. */

const u8 *const gModule_LocalizedText[8][5] = {
    /* LINK_FAIL */ { gModule_Text_LinkFail, gModule_Text_FrLinkFail, gModule_Text_DeLinkFail, gModule_Text_EsLinkFail, gModule_Text_ItLinkFail },
    /* WAITING */ { gModule_Text_Waiting, gModule_Text_FrWaiting, gModule_Text_DeWaiting, gModule_Text_EsWaiting, gModule_Text_ItWaiting },
    /* PRESS_START */ { gModule_Text_PressStart, gModule_Text_FrPressStart, gModule_Text_DePressStart, gModule_Text_EsPressStart, gModule_Text_ItPressStart },
    /* PAUSE */ { gModule_Text_Pause, gModule_Text_Pause, gModule_Text_Pause, gModule_Text_Pausa, gModule_Text_Pausa },
    /* RACE_OVER */ { gModule_Text_RaceOver, gModule_Text_FrRaceOver, gModule_Text_DeRaceOver, gModule_Text_EsRaceOver, gModule_Text_ItRaceOver },
    /* OUT_OF_TIME */ { gModule_Text_OutOfTime, gModule_Text_FrOutOfTime, gModule_Text_DeOutOfTime, gModule_Text_EsOutOfTime, gModule_Text_ItOutOfTime },
    /* LAP_TIME */ { gModule_Text_LapTime, gModule_Text_FrLapTime, gModule_Text_DeLapTime, gModule_Text_EsLapTime, gModule_Text_ItLapTime },
    /* CHECKPOINT */ { gModule_Text_Checkpoint, gModule_Text_FrControle, gModule_Text_DeKontrollpunkt, gModule_Text_EsControl, gModule_Text_ItControllo },
};

/* The engine-sound twins (ROM 0x0835DC10-0x0835DC38, EWRAM
 * 0x02025190-0x020251B8): ModuleRunRace plays each gear's base
 * frequency plus rpm times its multiplier, as RunRace does with the main
 * program's tables. The initialisers live in engine_sound_tables.h. */
const u32 gModule_EngineSoundFreqBases[5] = ENGINE_SOUND_FREQ_BASES;
const u8 gModule_EngineSoundRpmMultipliers[5] = ENGINE_SOUND_RPM_MULTIPLIERS;
// No module code reads these bytes yet.
const u8 gModule_020251A9[15] = UNK_08364AF9;

/* High module (link slave) fixed HUD and track data (ROM
 * 0x0835DC38-0x0835DCA0, EWRAM 0x020251B8-0x02025220). */

/* The text layer's BG map base in VRAM, the twin of the main program's
 * gTextLayerMapPtr (src/data/race_data.c): the module's HUD draws
 * through this pointer. Its users declare it as u16 *x, u32 x. */
const u32 gModule_TextLayerMapPtr[1] = { 0x600E000 };

/* The one track the link race runs (struct Track, structs.h): track 7,
 * the championship's link-only layout. The main program's twelve-record
 * gTrackData (src/data/race_data.c) says what each field is; this
 * record's blobs live in the module's track data around 0x0834A000,
 * labelled by their EWRAM addresses in data/rom_08345BF8.s. */
const struct Track gModule_TrackData[1] = {
    { (u32)gUnk_0201242C,
      (u32)gUnk_02018DA0,
      (u32)gUnk_02018DA0,
      gUnk_0201044C,
      gUnk_02017080,
      (u32)gUnk_02017080,
      (u32)gUnk_02013DAC,
      0x0,
      gUnk_0200D378,
      gUnk_02013FAC,
      (u32)gUnk_02013FAC,
      0x7d,
      0x64,
      0x7d,
      0x64,
      0x0,
      0x0,
      0x0,
      0x0,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      0x0,
      0x0,
      0x0,
      { 0, 0 } },
};

/* gUnk_0200D378 (0x08345DF8), gUnk_0201044C (0x08348ECC),
 * gUnk_0201242C (0x0834AEAC), gUnk_02013DAC (0x0834C82C),
 * gUnk_02013FAC (0x0834CA2C), gUnk_02017080 (0x0834FB00) and
 * gUnk_02018DA0 (0x08351820): the track's BG maps, metatiles, tile
 * sheets and palette, labelled in data/rom_08345BF8.s, which builds
 * them from track 7's editable files. */

/* ROM 0x0835DCA0-0x0835DCB8: the twins of the main program's
 * gTrackCountdownExtraSeconds (built from race_setup_tables.h) and the
 * three text pointers after it, gUnk_0836533C to gUnk_08365344
 * (src/data/rom_0836524C.c), here pointing at the module's own rows. */
const u8 gModule_TrackCountdownExtraSeconds[12] = TRACK_COUNTDOWN_EXTRA_SECONDS;
const u32 gModule_0202522C = (u32)gUnk_0200CF98;
u8 *const gUnk_02025230 = (u8 *)gUnk_0200CFA0;
const u32 gUnk_02025234 = (u32)gUnk_0200CFA4;
