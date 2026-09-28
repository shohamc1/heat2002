#include "global.h"

extern u32 gModule_CareerDecision[];
extern u32 gModule_StayOnThisTeam[];
extern u32 gUnk_0201AA54[];

void ModuleDrawBigText(u32 a);
void sub_0833F3C0(u32 a, u32 b, u32 c);

void sub_08344738(u8 a)
{
    u32 p;

    ModuleDrawBigText(gModule_CareerDecision);
    p = (u32)gModule_StayOnThisTeam;
    sub_0833F3C0(p, 8, a == 0);
    p = (u32)gUnk_0201AA54;
    sub_0833F3C0(p, 0xA, a == 1);
}
