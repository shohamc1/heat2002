#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

extern u8 *gChampionshipTeamNames[];
extern u8 *gChampionshipQualifyTexts[];
extern u8 *gChampionshipLockedTexts[];


void sub_08010AA4(u8 idx)
{
    u8 *p;

    p = gText_BlankRowMenu;
    DrawText(p, 0, 4, 0);
    DrawTextCenteredHighlight(gChampionshipTeamNames[idx], 4, 1);
    DrawText(p, 0, 0x11, 0);
    DrawText(p, 0, 0x12, 0);
    DrawText(p, 0, 0x13, 0);
    if (gChampionshipAvailable[idx] != 0)
        DrawText(gChampionshipQualifyTexts[idx], 0, 0x11, 1);
    else
        DrawText(gChampionshipLockedTexts[idx], 0, 0x11, 1);
}
