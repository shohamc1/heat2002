#include "global.h"
#include "functions.h"

extern const u8 gText_BadLuck[];
extern const u8 gText_YouVeBeenKicked[];
extern const u8 gText_OffTheTeam[];

void sub_0800F1B4(void)
{
    MessageBox(gText_BadLuck, gText_YouVeBeenKicked, gText_OffTheTeam);
}
