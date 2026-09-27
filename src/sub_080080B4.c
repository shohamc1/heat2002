#include "global.h"
#include "functions.h"
#include "variables.h"



void sub_080080B4(void)
{
    sub_08007F44(gPitMenuCursorRow);
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
        sub_08007EF8();
    }
}
