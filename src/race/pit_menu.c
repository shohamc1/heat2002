#include "global.h"
#include "data.h"
#include "functions.h"

extern u8 gText_BlankRow12[];
extern u8 gText_BlankRow24[];
#include "variables.h"
extern u8 gText_PitMenu[];
extern u8 gText_BlankRowPitMenu[];
extern const u8 *const gPitMenuRowLabelTexts[];
extern const u8 *const gPitMenuTireOptionTexts[];
extern const u8 *const gPitMenuFuelOptionTexts[];
extern const u8 *const gPitMenuRepairOptionTexts[];
extern u8 gPitMenuBlinkCounter;


void ClearPitMenu(void)
{
    u32 blankText;

    DrawTextAt(gText_BlankRow12, 0x0B, 0x07);
    blankText = (u32)gText_BlankRow24;
    DrawTextAt(blankText, 0x06, 0x09);
    DrawTextAt(blankText, 0x06, 0x0A);
    blankText = (u32)gText_BlankRow28;
    DrawTextAt(blankText, 0x06, 0x0B);
    DrawTextAt(blankText, 0x0A, 0x0C);
}


void DrawPitMenu(u8 cursorRow)
{
    DrawTextAt(gText_PitMenu, 0x0B, 0x07);
    if (cursorRow != 0 || (gPitMenuBlinkCounter & 4) == 0)
    {
        DrawTextAt(gPitMenuRowLabelTexts[0], 0x06, 0x09);
        DrawTextAt(gPitMenuTireOptionTexts[gPitServiceSelections[0]], 0x0D, 0x09);
    }
    else
        DrawTextAt(gText_BlankRowPitMenu, 0x06, 0x09);
    if (cursorRow != 1 || (gPitMenuBlinkCounter & 4) == 0)
    {
        DrawTextAt(gPitMenuRowLabelTexts[1], 0x06, 0x0A);
        DrawTextAt(gPitMenuFuelOptionTexts[gPitServiceSelections[1]], 0x0D, 0x0A);
    }
    else
        DrawTextAt(gText_BlankRow28, 0x06, 0x0A);
    if (cursorRow != 2 || (gPitMenuBlinkCounter & 4) == 0)
    {
        DrawTextAt(gPitMenuRowLabelTexts[2], 0x06, 0x0B);
        DrawTextAt(gPitMenuRepairOptionTexts[gPitServiceSelections[2]], 0x0D, 0x0B);
    }
    else
        DrawTextAt(gText_BlankRow28, 0x06, 0x0B);
    if (cursorRow != 3 || (gPitMenuBlinkCounter & 4) == 0)
        DrawTextAt(gPitMenuRowLabelTexts[3], 0x0D, 0x0C);
    else
        DrawTextAt(gText_BlankRowPitMenu, 0x0A, 0x0C);
    gPitMenuBlinkCounter++;
}


void InitPitMenu(void)
{
    gPitMenuCursorRow = 0;
    gPitServiceSelections[0] = 0;
    gPitServiceSelections[1] = 0;
    gPitServiceSelections[2] = 0;
    gPitMenuActive = 1;
}


void UpdatePitMenu(void)
{
    DrawPitMenu(gPitMenuCursorRow);
    gPitMenuCursorRow = MenuMoveVerticalSilent(gKeysPressed, gPitMenuCursorRow, 0, 3);
    if (gPitMenuCursorRow == 0)
        gPitServiceSelections[0] = MenuMoveHorizontalSilent(gKeysPressed, gPitServiceSelections[0], 0, 3);
    if (gPitMenuCursorRow == 1)
        gPitServiceSelections[1] = MenuMoveHorizontalSilent(gKeysPressed, gPitServiceSelections[1], 0, 2);
    if (gPitMenuCursorRow == 2)
        gPitServiceSelections[2] = MenuMoveHorizontalSilent(gKeysPressed, gPitServiceSelections[2], 0, 1);
    if (gPitMenuCursorRow == 3 && (gKeysPressed & 1))
    {
        gPitMenuActive = 0;
        gPitServiceEnabled = 1;
        if (gPitServiceSelections[0] == 3 && gPitServiceSelections[1] == 2 && gPitServiceSelections[2] == 1)
            gPitServiceEnabled = 0;
        ClearPitMenu();
    }
}

