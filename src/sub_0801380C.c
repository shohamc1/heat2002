#include "global.h"
#include "functions.h"

extern u8 gText_Overwrite[];
extern u8 gText_YouWillLoseThe[];
extern u8 gText_PreviouslySavedCareer[];
extern u8 gText_AreYouSure[];
extern u8 gText_No[];
extern u8 gText_Yes[];


void sub_0801380C(u8 a)
{
    u32 v;

    DummyUiFontLoad((u32)gText_Overwrite);
    DrawTextCenteredHighlight(gText_YouWillLoseThe, 7, 1);
    DrawTextCenteredHighlight(gText_PreviouslySavedCareer, 8, 1);
    DrawTextCenteredHighlight(gText_AreYouSure, 0xA, 1);
    v = (u32)gText_No;
    DrawTextCenteredHighlight(v, 0xC, a == 0);
    v = (u32)gText_Yes;
    DrawTextCenteredHighlight(v, 0xE, a == 1);
}
