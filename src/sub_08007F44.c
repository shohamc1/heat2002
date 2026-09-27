#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

extern u8 gUnk_0806C894[];
extern u8 gText_BlankRowPitMenu[];
extern u32 gPitMenuRowLabelTexts[];
extern u32 gPitMenuTireOptionTexts[];
extern u32 gPitMenuFuelOptionTexts[];
extern u32 gPitMenuRepairOptionTexts[];
extern u8 gPitMenuBlinkCounter;


void sub_08007F44(u8 a)
{
    sub_0800649C((u8 *)((u32)gUnk_0806C894), 0x0B, 0x07);
    if (a != 0 || (gPitMenuBlinkCounter & 4) == 0)
    {
        sub_0800649C((u8 *)gPitMenuRowLabelTexts[0], 0x06, 0x09);
        sub_0800649C((u8 *)(gPitMenuTireOptionTexts[gPitServiceSelections[0]]), 0x0D, 0x09);
    }
    else
        sub_0800649C((u8 *)((u32)gText_BlankRowPitMenu), 0x06, 0x09);
    if (a != 1 || (gPitMenuBlinkCounter & 4) == 0)
    {
        sub_0800649C((u8 *)gPitMenuRowLabelTexts[1], 0x06, 0x0A);
        sub_0800649C((u8 *)(gPitMenuFuelOptionTexts[gPitServiceSelections[1]]), 0x0D, 0x0A);
    }
    else
        sub_0800649C((u8 *)((u32)gUnk_0806C878), 0x06, 0x0A);
    if (a != 2 || (gPitMenuBlinkCounter & 4) == 0)
    {
        sub_0800649C((u8 *)gPitMenuRowLabelTexts[2], 0x06, 0x0B);
        sub_0800649C((u8 *)(gPitMenuRepairOptionTexts[gPitServiceSelections[2]]), 0x0D, 0x0B);
    }
    else
        sub_0800649C((u8 *)((u32)gUnk_0806C878), 0x06, 0x0B);
    if (a != 3 || (gPitMenuBlinkCounter & 4) == 0)
        sub_0800649C((u8 *)gPitMenuRowLabelTexts[3], 0x0D, 0x0C);
    else
        sub_0800649C((u8 *)((u32)gText_BlankRowPitMenu), 0x0A, 0x0C);
    gPitMenuBlinkCounter++;
}
