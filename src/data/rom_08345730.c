#include "global.h"

/* High module (link slave) localized race text (ROM 0x08345730-0x08345940,
 * EWRAM 0x0200CCB0-0x0200CEC0): the place names and the eight messages
 * ModuleGetString looks up in gModule_LocalizedText
 * (src/data/rom_0835DB58.c), each in the five languages the link
 * handshake negotiates (EN/FR/DE/ES/IT, gModule_Language). The ROM
 * leaves the Italian OUT OF TIME row empty. The placing names
 * (1ST..5TH) sit in front; gModule_020250D8 (rom_0835DB58.c) points at
 * them, as the main program's gUnk_08364AC8 points at its own. */

const u8 gModule_Text_5th[4] = "5TH";
const u8 gModule_Text_4th[4] = "4TH";
const u8 gModule_Text_3rd[4] = "3RD";
const u8 gModule_Text_2nd[4] = "2ND";
const u8 gModule_Text_1st[4] = "1ST";
/* CHECKPOINT (MODULE_MSG_CHECKPOINT) */
const u8 gModule_Text_ItControllo[12] = "CONTROLLO!";
const u8 gModule_Text_EsControl[12] = "$CONTROL!";
const u8 gModule_Text_DeKontrollpunkt[16] = "KONTROLLPUNKT";
const u8 gModule_Text_FrControle[12] = "CONTROLE !";
const u8 gModule_Text_Checkpoint[12] = "CHECKPOINT!";
/* LAP TIME (MODULE_MSG_LAP_TIME) */
const u8 gModule_Text_ItLapTime[12] = "TEMPO: %s";
const u8 gModule_Text_EsLapTime[12] = "TIEMPO: %s";
const u8 gModule_Text_DeLapTime[12] = "RUNDE: %s";
const u8 gModule_Text_FrLapTime[12] = "TEMPS : %s";
const u8 gModule_Text_LapTime[16] = "LAP TIME: %s";
/* OUT OF TIME (MODULE_MSG_OUT_OF_TIME) */
const u8 gModule_Text_ItOutOfTime[16] = "TEMPO SCADUTO";
const u8 gModule_Text_EsOutOfTime[16] = "FUERA DE TIEMPO";
const u8 gModule_Text_DeOutOfTime[16] = "ZEIT ABGELAUFEN";
const u8 gModule_Text_FrOutOfTime[16] = "TEMPS ECOULE";
const u8 gModule_Text_OutOfTime[12] = "OUT OF TIME";
/* RACE OVER (MODULE_MSG_RACE_OVER) */
const u8 gModule_Text_ItRaceOver[12] = "FINE GARA";
const u8 gModule_Text_EsRaceOver[16] = "FIN DE CARRERA";
const u8 gModule_Text_DeRaceOver[16] = "RENNEN BEENDET";
const u8 gModule_Text_FrRaceOver[16] = "COURSE TERMINEE";
const u8 gModule_Text_RaceOver[12] = "RACE OVER";
/* PAUSE (MODULE_MSG_PAUSE) */
const u8 gModule_Text_Pausa[8] = "PAUSA";
const u8 gModule_Text_Pause[8] = "PAUSE";
/* PRESS START (MODULE_MSG_PRESS_START) */
const u8 gModule_Text_ItPressStart[12] = "PREMI START";
const u8 gModule_Text_EsPressStart[12] = "PULSA START";
const u8 gModule_Text_DePressStart[16] = "DRUCKE START";
const u8 gModule_Text_FrPressStart[20] = "APPUYER SUR START";
const u8 gModule_Text_PressStart[12] = "PRESS START";
/* WAITING (MODULE_MSG_WAITING) */
const u8 gModule_Text_ItWaiting[12] = "IN ATTESA";
const u8 gModule_Text_EsWaiting[12] = "EN ESPERA";
const u8 gModule_Text_DeWaiting[8] = "WARTE";
const u8 gModule_Text_FrWaiting[12] = "EN ATTENTE";
const u8 gModule_Text_Waiting[8] = "WAITING";
/* LINK FAIL (MODULE_MSG_LINK_FAIL) */
const u8 gModule_Text_ItLinkFail[24] = "COLLEGAMENTO FALLITO";
const u8 gModule_Text_EsLinkFail[16] = "FALLO ENLACE";
const u8 gModule_Text_DeLinkFail[24] = "VERBINDUNG GESCHEITERT";
const u8 gModule_Text_FrLinkFail[16] = "ECHEC DE LINK";
const u8 gModule_Text_LinkFail[12] = "LINK FAIL";
