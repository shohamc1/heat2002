#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

extern u8 gText_PitMenu[];
extern u8 gText_BlankRowPitMenu[];
extern const u8 *const gPitMenuRowLabelTexts[];
extern const u8 *const gPitMenuTireOptionTexts[];
extern const u8 *const gPitMenuFuelOptionTexts[];
extern const u8 *const gPitMenuRepairOptionTexts[];
extern u8 gPitMenuBlinkCounter;


void sub_08007F44(u8 a)
{
    sub_0800649C(gText_PitMenu, 0x0B, 0x07);
    if (a != 0 || (gPitMenuBlinkCounter & 4) == 0)
    {
        sub_0800649C(gPitMenuRowLabelTexts[0], 0x06, 0x09);
        sub_0800649C(gPitMenuTireOptionTexts[gPitServiceSelections[0]], 0x0D, 0x09);
    }
    else
        sub_0800649C(gText_BlankRowPitMenu, 0x06, 0x09);
    if (a != 1 || (gPitMenuBlinkCounter & 4) == 0)
    {
        sub_0800649C(gPitMenuRowLabelTexts[1], 0x06, 0x0A);
        sub_0800649C(gPitMenuFuelOptionTexts[gPitServiceSelections[1]], 0x0D, 0x0A);
    }
    else
        sub_0800649C(gText_BlankRow28, 0x06, 0x0A);
    if (a != 2 || (gPitMenuBlinkCounter & 4) == 0)
    {
        sub_0800649C(gPitMenuRowLabelTexts[2], 0x06, 0x0B);
        sub_0800649C(gPitMenuRepairOptionTexts[gPitServiceSelections[2]], 0x0D, 0x0B);
    }
    else
        sub_0800649C(gText_BlankRow28, 0x06, 0x0B);
    if (a != 3 || (gPitMenuBlinkCounter & 4) == 0)
        sub_0800649C(gPitMenuRowLabelTexts[3], 0x0D, 0x0C);
    else
        sub_0800649C(gText_BlankRowPitMenu, 0x0A, 0x0C);
    gPitMenuBlinkCounter++;
}
