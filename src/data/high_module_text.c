#include "global.h"
#include "data.h"

/* High module (link slave) localized race text (ROM 0x08345730-0x08345940,
 * EWRAM 0x0200CCB0-0x0200CEC0): the place names and the eight messages
 * ModuleGetString looks up in gModule_LocalizedText
 * (src/data/module_race_data.c), each in the five languages the link
 * handshake negotiates (EN/FR/DE/ES/IT, gModule_Language). The ROM
 * leaves the Italian OUT OF TIME row empty. The placing names
 * (1ST..5TH) sit in front; gModule_020250D8 (module_race_data.c) points at
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

/* High module (link slave) text: turn-off warning, players, pit menu
 * (0x08345940-0x08345BF8). */

const u8 gModule_PleaseTurnOffYour[24] = "PLEASE TURN OFF YOUR";
const u8 gModule_GameBoyAdvance[20] = "GAME BOY& ADVANCE.";
const u8 gModule_Player1[12] = "PLAYER 1";
const u8 gModule_Player2[12] = "PLAYER 2";
const u8 gModule_Player3[12] = "PLAYER 3";
const u8 gModule_Player4[12] = "PLAYER 4";
const u8 gModule_PleaseTurnOffYour_2[24] = "PLEASE TURN OFF YOUR";
const u8 gModule_GameBoyAdvance_2[20] = "GAME BOY& ADVANCE";
const u8 gModule_PitStopNeeded[20] = "PIT STOP NEEDED!";
const u8 gModule_BlankRow20[20] = "                ";
const u8 gModule_Pos[] = "POS";
const u8 gModule_BlankRow16[16] = "            ";
const u8 gModule_Lap[] = "LAP";
const u8 gModule_TimeLabel[8] = "TIME:";
const u8 gModule_PitLabelBlock[200] =
    "BEST:\000\000\00001234\000\000\000 \000\000\000                              \000\000OK\000\000DAMAGE:\000FUEL  "
    ":\000TIRES :\000NONE     \000\000\000RIGHT 2  \000\000\000LEFT 2   \000\000\000ALL TIRES\000\000\000NONE          "
    " \000SPLASH AND DASH\000FULL TANK      \000NO REPAIR\000\000\000REPAIR   ";
const u8 gModule_BlankRow12[12] = "        ";
const u8 gModule_BlankRow24[] = "                       ";
const u8 gModule_BlankRow28[] = "                           ";
const u8 gModule_PitMenu[12] = "PIT MENU";
const u8 gModule_BlankRow20_2[20] = "                  ";
const u8 gModule_Timer[8] = "TIMER";
const u8 gModule_MPH[] = "MPH";
const u8 gModule_BlankRow8[8] = "      ";
const u8 gModule_BlankRow12_2[12] = "         ";
const u8 gModule_Demo[28] = "                \000\000\000\000DEMO";
const u8 gModule_DemoMode[12] = "DEMO MODE";
const u8 gModule_OutOfTime[] = "         \000\000\000OUT OF TIME";
/* Tyre-position names, the module's pit-menu damage rows (0x08345B98,
 * EWRAM 0x0200D118): the leading blank row the splash and lap-time
 * screens draw through (module_splash.c, module_lap_time.c), then the
 * twins of the main program's gText_Rearright..gText_Back
 * (src/data/link_text.c); the pointer table in the module's tail data
 * names them. */
const u8 gUnk_0200D118[16] = "              ";
const u8 gModule_Rearright[12] = "REARRIGHT";
const u8 gModule_Rearleft[12] = "REARLEFT";
const u8 gModule_Frontright[12] = "FRONTRIGHT";
const u8 gModule_Frontleft[12] = "FRONTLEFT";
const u8 gModule_Right[8] = "RIGHT";
const u8 gModule_Left[8] = "LEFT";
const u8 gModule_Front[8] = "FRONT";
const u8 gModule_Back[8] = "BACK";
