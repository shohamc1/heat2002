#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"


void m4aSoundVSyncOff(void);
void sub_0800524C(void);
void sub_080051E4(void);

u8 sub_08005280(void)
{
    u8 unused[0x200];
    u8 done;
    u16 r;
    u32 v;

    gLinkMenuPlayerIndex = 0xFF;
    sub_08004DB4();
    if (gLinkMenuKeysPressed & 8) {
        StopAllSongs();
        {
            volatile u8 *p = &gVBlankWorkDone;

            while (1) {
                gVBlankCounter = 0;
                if (ExchangeLinkInput() != 0) {
                    m4aSoundVSyncOff();
                    done = 0;
                    do {
                        v = gLinkPlayerId[0];
                        if (v == 0)
                            return 0x27;
                        /* VBlankIntrWait: this file's old local prototype differs from
                           functions.h; call through the old signature (solved-walls 31). */
                        ((void (*)(u32))VBlankIntrWait)(v);
                    } while (done == 0);
                }
                sub_08004DB4();
                r = gLinkMenuKeysPressed & 8;
                if (r != 0) {
                    sub_0800524C();
                    return 1;
                }
                sub_080051E4();
                gFrameCounter++;
                *p = r;
poll:
                if (*p == 0)
                    goto poll;
        }
    }
    }
    return 0;
}
