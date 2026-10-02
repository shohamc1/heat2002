#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

extern u8 gText_BlankRow12[];
extern u8 gText_BlankRow24[];
extern u8 gText_PitMenu[];
extern u8 gText_BlankRowPitMenu[];
extern const u8 *const gPitMenuRowLabelTexts[];
extern const u8 *const gPitMenuTireOptionTexts[];
extern const u8 *const gPitMenuFuelOptionTexts[];
extern const u8 *const gPitMenuRepairOptionTexts[];
extern u8 gPitMenuBlinkCounter;

void ClearPitMenu(void)
{
    const u8 *blankText;

    DrawTextAt(gText_BlankRow12, 11, 7);
    blankText = gText_BlankRow24;
    DrawTextAt(blankText, 6, 9);
    DrawTextAt(blankText, 6, 10);
    blankText = gText_BlankRow28;
    DrawTextAt(blankText, 6, 11);
    DrawTextAt(blankText, 10, 12);
}

void DrawPitMenu(u8 cursorRow)
{
    DrawTextAt(gText_PitMenu, 11, 7);
    if (cursorRow != 0 || (gPitMenuBlinkCounter & 4) == 0) {
        DrawTextAt(gPitMenuRowLabelTexts[0], 6, 9);
        DrawTextAt(gPitMenuTireOptionTexts[gPitServiceSelections[0]], 13, 9);
    } else
        DrawTextAt(gText_BlankRowPitMenu, 6, 9);
    if (cursorRow != 1 || (gPitMenuBlinkCounter & 4) == 0) {
        DrawTextAt(gPitMenuRowLabelTexts[1], 6, 10);
        DrawTextAt(gPitMenuFuelOptionTexts[gPitServiceSelections[1]], 13, 10);
    } else
        DrawTextAt(gText_BlankRow28, 6, 10);
    if (cursorRow != 2 || (gPitMenuBlinkCounter & 4) == 0) {
        DrawTextAt(gPitMenuRowLabelTexts[2], 6, 11);
        DrawTextAt(gPitMenuRepairOptionTexts[gPitServiceSelections[2]], 13, 11);
    } else
        DrawTextAt(gText_BlankRow28, 6, 11);
    if (cursorRow != 3 || (gPitMenuBlinkCounter & 4) == 0)
        DrawTextAt(gPitMenuRowLabelTexts[3], 13, 12);
    else
        DrawTextAt(gText_BlankRowPitMenu, 10, 12);
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
    if (gPitMenuCursorRow == 3 && (gKeysPressed & 1)) {
        gPitMenuActive = 0;
        gPitServiceEnabled = 1;
        if (gPitServiceSelections[0] == 3 && gPitServiceSelections[1] == 2 && gPitServiceSelections[2] == 1)
            gPitServiceEnabled = 0;
        ClearPitMenu();
    }
}
