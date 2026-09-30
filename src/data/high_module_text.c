#include "global.h"
#include "data.h"

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
