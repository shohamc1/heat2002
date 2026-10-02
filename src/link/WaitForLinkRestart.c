#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

void WaitForLinkRestart(void)
{
    AgeGfxCaches();
    ClearOamBuffer();
    while (1) {
        u16 keys;
        *(u16 *)&gVBlankCounter = 0;
        if (ExchangeLinkInput() != 0) {
            DrawTextCentered(GetString(117), 10, 1);
            m4aMPlayStop(&gBgMusicPlayer);
            m4aMPlayStop(&gEngineSoundPlayer);
            m4aSoundVSyncOff();
            while (1) {
                u32 playerId = gLinkPlayerId;
                if (playerId == 0)
                    playerId = REG_KEYINPUT;
                ((void (*)(u32))VBlankIntrWait)(playerId);
            }
        }
        if (gLinkPlayerId != 0)
            DrawTextCentered(GetString(88), 14, 1);
        else
            DrawTextCentered(GetString(15), 14, 1);
        keys = ReadLinkMenuKeys();
        if (keys & 8) {
            FadeToColor(0, 50);
            return;
        }
    }
}
