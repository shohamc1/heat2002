#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "m4a.h"

void m4aSoundVSyncOff(void);

void sub_080053B8(void)
{
    AgeGfxCaches();
    ClearOamBuffer();
    while (1)
    {
        u16 r;
        *(u16 *)0x02002124 = 0;
        if (ExchangeLinkInput() != 0)
        {
            /* DrawTextCentered: this file's old local prototype differs from
               functions.h; call through the old signature (solved-walls 31). */
            ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x75), 0x0A, 1);
            m4aMPlayStop((struct MusicPlayerInfo *)0x02001F20);
            m4aMPlayStop((struct MusicPlayerInfo *)0x02001F60);
            m4aSoundVSyncOff();
            while (1)
            {
                u32 r0 = *(u8 *)(EWRAM_START + 0x2EF90);
                if (r0 == 0)
                    r0 = REG_KEYINPUT;
                ((void (*)(u32))VBlankIntrWait)(r0);
            }
        }
        if (*(u8 *)(EWRAM_START + 0x2EF90) != 0)
            ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x58), 0x0E, 1);
        else
            ((void (*)(u32, u32, u32))DrawTextCentered)(GetString(0x0F), 0x0E, 1);
        r = ReadLinkMenuKeys();
        if (r & 8)
        {
            FadeToColor(0, 0x32);
            return;
        }
    }
}
