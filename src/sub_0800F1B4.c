#include "global.h"

extern const u8 gText_BadLuck[];
extern const u8 gText_YouVeBeenKicked[];
extern const u8 gText_OffTheTeam[];

void MessageBox(u32, u32, u32);

void sub_0800F1B4(void)
{
    MessageBox((u32)gText_BadLuck, (u32)gText_YouVeBeenKicked, (u32)gText_OffTheTeam);
}
