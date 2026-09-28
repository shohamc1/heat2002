#include "global.h"
#include "functions.h"
#include "data.h"

extern u8 gUnk_0202EEFC;
extern u16 gUnk_083FDE5E[];
void LoadMainMenuBackdrop(void);
void DrawMainMenuItems(u8 a);


void DrawMainMenuItems(u8 selected)
{
    u8 *d;
    u32 i;
    u16 *textIds;
    u32 row;

    d = &gUnk_0202EEFC;
    /* DummyMainMenuHook: this file's old prototype returns u8; the matched
       definition returns void; call through a function pointer. */
    *d = ((u8 (*)(void))DummyMainMenuHook)();
    DummyUiFontLoad(gUiFontTable[0]);
    GetString(0x59);
    ((void (*)(void))DrawBigText)();
    i = 0;
    row = 5;
    textIds = gUnk_083FDE5E;
    do {
        DrawTextCenteredHighlight(GetString(*textIds), row, selected == i);
        row += 2;
        textIds++;
        i++;
    } while (i != 7);
}


void DrawMainMenu(u8 selected)
{
    LoadMainMenuBackdrop();
    DrawMainMenuItems(selected);
}

