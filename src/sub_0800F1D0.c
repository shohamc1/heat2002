#include "global.h"

extern u32 gText_Congratulations[];
extern u32 gText_YouAreAllowedTo[];
extern u32 gText_StayOnThisTeam[];

void MessageBox(u32 a, u32 b, u32 c);

void sub_0800F1D0(void)
{
    MessageBox((u32)gText_Congratulations, (u32)gText_YouAreAllowedTo, (u32)gText_StayOnThisTeam);
}
