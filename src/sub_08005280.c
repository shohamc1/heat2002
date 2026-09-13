#include "global.h"

extern u8 gUnk_020253C4;
extern u16 gUnk_02025258;
extern volatile u8 gUnk_020020C0;
extern u16 gUnk_02002124;
extern u8 gUnk_0202EF90;
extern s32 gUnk_0200209C;

void sub_08004DB4(void);
void sub_08010094(void);
u32 sub_08003330(void);
void sub_080017D0(void);
void sub_08016E30(u32 a);
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
        sub_08010094();
        {
            volatile u8 *p = &gUnk_020020C0;

            while (1) {
                gUnk_02002124 = 0;
                if (sub_08003330() != 0) {
                    sub_080017D0();
                    done = 0;
                    do {
                        v = gUnk_0202EF90;
                        if (v == 0)
                            return 0x27;
                        sub_08016E30(v);
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
