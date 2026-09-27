#include "global.h"
#include "functions.h"

extern u8 gUnk_020253C4;
extern u16 gUnk_02025258;
extern u8 gUnk_020020C0;
extern u16 gUnk_02002124;
extern u8 gLinkPlayerId;
extern s32 gUnk_0200209C;

void sub_080017D0(void);
void sub_0800524C(void);
void sub_080051E4(void);

u8 sub_08005280(void)
{
    u8 unused[0x200];
    u8 done;
    u16 r;
    u32 v;

    gUnk_020253C4 = 0xFF;
    sub_08004DB4();
    if (gUnk_02025258 & 8) {
        StopAllSongs();
        {
            volatile u8 *p = &gUnk_020020C0;

            while (1) {
                gUnk_02002124 = 0;
                if (ExchangeLinkInput() != 0) {
                    sub_080017D0();
                    done = 0;
                    do {
                        v = gLinkPlayerId;
                        if (v == 0)
                            return 0x27;
                        /* VBlankIntrWait: this file's old local prototype differs from
                           functions.h; call through the old signature (solved-walls 31). */
                        ((void (*)(u32))VBlankIntrWait)(v);
                    } while (done == 0);
                }
                sub_08004DB4();
                r = gUnk_02025258 & 8;
                if (r != 0) {
                    sub_0800524C();
                    return 1;
                }
                sub_080051E4();
                gUnk_0200209C++;
                *p = r;
poll:
                if (*p == 0)
                    goto poll;
        }
    }
    }
    return 0;
}
