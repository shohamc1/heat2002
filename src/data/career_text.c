#include "global.h"
#include "data.h"

/* High module (link slave) career decision and team text
 * (0x083534B0-0x083537BC): the career negotiation screen's fixed
 * strings, then the team names. Byte-identical to the main program's
 * counterparts in src/data/game_text.c (which names what each is for):
 * the ROM holds them twice, once per GBA. */

const u8 gModule_CareerDecision[] = "CAREER DECISION";
const u8 gModule_StayOnThisTeam[20] = "STAY ON THIS TEAM";
// sub_08344684.c draws this one under the two lines above.
const u8 gModule_ChooseANewTeam[20] = "CHOOSE A NEW TEAM";
const u8 gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf37SecondsOnHooleyDowns[96] =
    "TO QUALIFY FOR THIS TEAM, YOU   WILL NEED TO BEAT A LAP TIME    OF 37 SECONDS ON HOOLEY DOWNS.";
const u8 gModule_ToQualifyForThisTeamYouWillNeedToBeatALapTimeOf33SecondsOnHooleyDowns[96] =
    "TO QUALIFY FOR THIS TEAM, YOU   WILL NEED TO BEAT A LAP TIME    OF 33 SECONDS ON HOOLEY DOWNS.";
const u8 gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop20[80] =
    "TO STAY IN THIS TEAM, YOU WILL  NEED TO FINISH THE SEASON       IN THE TOP 20.";
const u8 gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop10[80] =
    "TO STAY IN THIS TEAM, YOU WILL  NEED TO FINISH THE SEASON       IN THE TOP 10.";
const u8 gModule_ToStayInThisTeamYouWillNeedToFinishTheSeasonInTheTop5[80] =
    "TO STAY IN THIS TEAM, YOU WILL  NEED TO FINISH THE SEASON       IN THE TOP 5.";
/* The career teams, in championship order. */
const u8 gModule_TeamCrawfish[16] = "TEAM CRAWFISH";
const u8 gModule_Darby[8] = "DARBY";
const u8 gModule_EricHayashiMotorsports[28] = "ERIC HAYASHI MOTORSPORTS";
const u8 gModule_MikeMacconellRacing[24] = "MIKE MACCONELL RACING";
const u8 gModule_TeamTino[12] = "TEAM TINO";
const u8 gModule_TtMotorsports[16] = "TT MOTORSPORTS";
const u8 gModule_AndylandRacing[] = "ANDYLAND RACING";
const u8 gModule_JimFerrisMotorsports[24] = "JIM FERRIS MOTORSPORTS";
const u8 gModule_ChipGanassi[16] = "CHIP GANASSI";
const u8 gModule_Penske[8] = "PENSKE";
const u8 gModule_KravitzRacing[16] = "KRAVITZ RACING";
const u8 gModule_MackneyMotorsports[] = "MACKNEY MOTORSPORTS";
const u8 gModule_DalyEnterprises[20] = "DALY ENTERPRISES";
const u8 gModule_HendrickMotorsports[24] = "HENDRICK MOTORSPORTS";
const u8 gModule_Ryr[] = "RYR";
const u8 gModule_Rcr[] = "RCR";
const u8 gModule_Dei[] = "DEI";
const u8 gModule_UnderscoreRow32[32] = "______________________________";
