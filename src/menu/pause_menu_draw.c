#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"

extern u8 gText_P1Paused[];
extern u8 gText_P2Paused[];
extern u8 gText_P3Paused[];
extern u8 gText_P4Paused[];
extern u8 gText_Paused[];
extern u8 gText_BlankRowPauseConfirm[];

void DrawPauseMenu(u8 cursor)
{
    u8 sel = cursor;

    if (gIsLinkRace != 0) {
        switch (gLinkMenuPlayerIndex) {
            case 0:
                DrawTextCentered(gText_P1Paused, 6, 1);
                break;
            case 1:
                DrawTextCentered(gText_P2Paused, 6, 1);
                break;
            case 2:
                DrawTextCentered(gText_P3Paused, 6, 1);
                break;
            case 3:
                DrawTextCentered(gText_P4Paused, 6, 1);
                break;
        }
    } else {
        DrawTextCentered(gText_Paused, 6, 1);
    }
    if (sel == 1 || (gMenuBlinkCounter & 8)) {
        DrawTextCentered(GetString(0x81), 8, 1);
    } else {
        DrawTextCentered(gText_BlankRowPauseMenu, 8, 1);
    }
    if (sel == 0 || (gMenuBlinkCounter & 8)) {
        DrawTextCentered(GetString(0x80), 0xA, 1);
    } else {
        DrawTextCentered(gText_BlankRowPauseMenu, 0xA, 1);
    }
}

void DrawPauseConfirmMenu(u8 cursor)
{
    u8 sel = cursor;

    if (sel != 3) {
        DrawTextCentered(GetString(0x66), 6, 1);
    } else {
        DrawTextCentered(gText_BlankRowPauseConfirm, 6, 1);
    }
    if (sel == 1 || (gMenuBlinkCounter & 8)) {
        DrawTextCentered(GetString(0x68), 8, 1);
    } else {
        DrawTextCentered(gText_BlankRowPauseMenu, 8, 1);
    }
    if (sel == 0 || (gMenuBlinkCounter & 8)) {
        DrawTextCentered(GetString(0x67), 0xA, 1);
    } else {
        DrawTextCentered(gText_BlankRowPauseMenu, 0xA, 1);
    }
}
