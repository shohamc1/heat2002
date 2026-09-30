#include "global.h"
#include "data.h"

/* The high module's driver-name and not-available strings
   (0x08353260-0x083534B0), one sized row each: the layout
   gModule_DriverRoster and gModule_ChampionshipLockedTexts
   (src/data/module_championship_data.c) point into, every string
   padded with zero bytes to its slot. */
const u8 gModule_DriverCameronSheppard[20] = "CAMERON SHEPPARD";
const u8 gModule_DriverMikeMerren[12] = "MIKE MERREN";
const u8 gModule_DriverDarrenJackson[16] = "DARREN JACKSON";
const u8 gModule_DriverDaveMurphy[12] = "DAVE MURPHY";
const u8 gModule_DriverJonnieShearn[16] = "JONNIE SHEARN";
const u8 gModule_DriverWillGreenough[16] = "WILL GREENOUGH";
const u8 gModule_DriverTimCoode[12] = "TIM COODE";
const u8 gModule_DriverAdamBouskill[16] = "ADAM BOUSKILL";
const u8 gModule_DriverJamesDaly[12] = "JAMES DALY";
const u8 gModule_DriverChrisWalsh[12] = "CHRIS WALSH";
const u8 gModule_DriverJakeMay[12] = "JAKE MAY";
const u8 gModule_DriverSeanKendrick[16] = "SEAN KENDRICK";
const u8 gModule_DriverDanielEvans[16] = "DANIEL EVANS";
const u8 gModule_DriverAndrewBishop[16] = "ANDREW BISHOP";
const u8 gModule_DriverTimMunson[12] = "TIM MUNSON";
const u8 gModule_DriverNeilWilson[12] = "NEIL WILSON";
const u8 gModule_DriverJamesBrown[12] = "JAMES BROWN";
const u8 gModule_DriverMitchellSlater[16] = "MITCHELL SLATER";
const u8 gModule_DriverJayMcgee[12] = "JAY MCGEE";
const u8 gModule_DriverBrianLocke[12] = "BRIAN LOCKE";
const u8 gModule_DriverSterlingMarlin[16] = "STERLING MARLIN";
const u8 gModule_DriverRustyWallace[16] = "RUSTY WALLACE";
const u8 gModule_DriverJoeFried[12] = "JOE FRIED";
const u8 gModule_DriverJasonPope[12] = "JASON POPE";
const u8 gModule_DriverJeffGordon[12] = "JEFF GORDON";
const u8 gModule_DriverRickyRudd[12] = "RICKY RUDD";
const u8 gModule_DriverDaleJarrett[16] = "DALE JARRETT";
const u8 gModule_DriverKevinHarvick[16] = "KEVIN HARVICK";
const u8 gModule_DriverDaleEarnhardtJr[20] = "DALE EARNHARDT JR.";
const u8 gModule_DriverStevePark[12] = "STEVE PARK";
const u8 gModule_DriverNotAvailable[16] = "NOT AVAILABLE.";
const u8 gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop10[76] = "NOT AVAILABLE.                  YOU NEED TO FINISH A SEASON IN  THE TOP 10.";
const u8 gModule_DriverNotAvailableYouNeedToFinishASeasonInTheTop5[76] = "NOT AVAILABLE.                  YOU NEED TO FINISH A SEASON IN  THE TOP 5.";

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
