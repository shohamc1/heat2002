#include "global.h"

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

/* High module (link slave) localized message table (ROM
 * 0x0835DB70-0x0835DC10, EWRAM 0x02025090-0x02025130): eight messages
 * (include/functions.h's MODULE_MSG_*) in the five languages the link
 * handshake negotiates (gModule_Language: EN, FR, DE, ES, IT).
 * ModuleGetString returns row[id][language]. The strings live in
 * src/data/rom_08345730.c; the same forty words sit a second time in
 * gUnk_02024F70's sprite block (0x0200D170), which stays a blob. The
 * ROM leaves the Italian OUT OF TIME row empty. */

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
