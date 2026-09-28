#include "global.h"
#include "functions.h"

extern const u8 gText_CareerDecision[];
extern const u8 gText_StayOnThisTeam_2[];
extern const u8 gText_ChooseANewTeam[];


void sub_0800F1EC(u8 a)
{
    const u8 *p;

    DrawBigText(gText_CareerDecision);
    p = gText_StayOnThisTeam_2;
    DrawTextCenteredHighlight(p, 8, a == 0);
    p = gText_ChooseANewTeam;
    DrawTextCenteredHighlight(p, 0xA, a == 1);
}
