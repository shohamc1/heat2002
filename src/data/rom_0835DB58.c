#include "global.h"
#include "engine_sound_tables.h"

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

/* The place names src/data/rom_08345730.c defines. */
extern const u8 gModule_Text_1st[];
extern const u8 gModule_Text_2nd[];
extern const u8 gModule_Text_3rd[];
extern const u8 gModule_Text_4th[];
extern const u8 gModule_Text_5th[];

/* ROM 0x0835DB58-0x0835DB70, EWRAM 0x020250D8-0x020250F0: the twins of
 * the main program's gUnk_08364AC8 (the place names, 1ST to 5TH) and
 * gUnk_08364ADC (src/data/rom_08364AC8.c). ModuleRunRace writes
 * gUnk_020250EC in place, as RunRace writes its twin; the image runs
 * from EWRAM, so here the write sticks. */
const u32 gModule_020250D8[5] = { (u32)gModule_Text_1st, (u32)gModule_Text_2nd, (u32)gModule_Text_3rd,
                                  (u32)gModule_Text_4th, (u32)gModule_Text_5th };
const u8 gUnk_020250EC[4] = UNK_08364ADC;

/* High module (link slave) localized message table (ROM
 * 0x0835DB70-0x0835DC10, EWRAM 0x02025090-0x02025130): eight messages
 * (include/functions.h's MODULE_MSG_*) in the five languages the link
 * handshake negotiates (gModule_Language: EN, FR, DE, ES, IT).
 * ModuleGetString returns row[id][language]. The strings live in
 * src/data/rom_08345730.c. The ROM leaves the Italian OUT OF TIME row
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
