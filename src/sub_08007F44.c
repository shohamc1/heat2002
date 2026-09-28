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
    DrawTextAt(gText_PitMenu, 0x0B, 0x07);
    if (a != 0 || (gPitMenuBlinkCounter & 4) == 0)
    {
        DrawTextAt(gPitMenuRowLabelTexts[0], 0x06, 0x09);
        DrawTextAt(gPitMenuTireOptionTexts[gPitServiceSelections[0]], 0x0D, 0x09);
    }
    else
        DrawTextAt(gText_BlankRowPitMenu, 0x06, 0x09);
    if (a != 1 || (gPitMenuBlinkCounter & 4) == 0)
    {
        DrawTextAt(gPitMenuRowLabelTexts[1], 0x06, 0x0A);
        DrawTextAt(gPitMenuFuelOptionTexts[gPitServiceSelections[1]], 0x0D, 0x0A);
    }
    else
        DrawTextAt(gText_BlankRow28, 0x06, 0x0A);
    if (a != 2 || (gPitMenuBlinkCounter & 4) == 0)
    {
        DrawTextAt(gPitMenuRowLabelTexts[2], 0x06, 0x0B);
        DrawTextAt(gPitMenuRepairOptionTexts[gPitServiceSelections[2]], 0x0D, 0x0B);
    }
    else
        DrawTextAt(gText_BlankRow28, 0x06, 0x0B);
    if (a != 3 || (gPitMenuBlinkCounter & 4) == 0)
        DrawTextAt(gPitMenuRowLabelTexts[3], 0x0D, 0x0C);
    else
        DrawTextAt(gText_BlankRowPitMenu, 0x0A, 0x0C);
    gPitMenuBlinkCounter++;
}
