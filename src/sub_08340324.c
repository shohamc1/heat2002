#include "global.h"
#include "functions.h"
#include "variables.h"

extern u8 gModule_PitMenu[];
extern u8 gModule_BlankRow20_2[];
extern u32 gUnk_02027680[];
extern u32 gUnk_02027690[];
extern u32 gUnk_020276A0[];
extern u32 gUnk_020276AC[];
extern u8 gUnk_0203D4F0;
extern u8 gUnk_0203DDE0[];


void sub_08340324(u8 a)
{
    ModuleDrawText(gModule_PitMenu, 0x0B, 0x07);
    if (a != 0 || (gUnk_0203D4F0 & 4) == 0)
    {
        ModuleDrawText(gUnk_02027680[0], 0x06, 0x09);
        ModuleDrawText(gUnk_02027690[gUnk_0203DDE0[0]], 0x0D, 0x09);
    }
    else
        ModuleDrawText(gModule_BlankRow20_2, 0x06, 0x09);
    if (a != 1 || (gUnk_0203D4F0 & 4) == 0)
    {
        ModuleDrawText(gUnk_02027680[1], 0x06, 0x0A);
        ModuleDrawText(gUnk_020276A0[gUnk_0203DDE0[1]], 0x0D, 0x0A);
    }
    else
        ModuleDrawText(gModule_BlankRow28, 0x06, 0x0A);
    if (a != 2 || (gUnk_0203D4F0 & 4) == 0)
    {
        ModuleDrawText(gUnk_02027680[2], 0x06, 0x0B);
        ModuleDrawText(gUnk_020276AC[gUnk_0203DDE0[2]], 0x0D, 0x0B);
    }
    else
        ModuleDrawText(gModule_BlankRow28, 0x06, 0x0B);
    if (a != 3 || (gUnk_0203D4F0 & 4) == 0)
        ModuleDrawText(gUnk_02027680[3], 0x0D, 0x0C);
    else
        ModuleDrawText(gModule_BlankRow20_2, 0x0A, 0x0C);
    gUnk_0203D4F0++;
}
