#include "global.h"
#include "functions.h"

extern const u8 gText_Congratulations[];
extern const u8 gText_YouAreAllowedTo[];
extern const u8 gText_StayOnThisTeam[];

void sub_0800F1D0(void)
{
    MessageBox(gText_Congratulations, gText_YouAreAllowedTo, gText_StayOnThisTeam);
}
