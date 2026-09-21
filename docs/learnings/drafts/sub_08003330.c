#include "global.h"

extern u8 gUnk_020020AC;
extern u16 gUnk_020020A0[];
extern u16 gUnk_0200216C;
extern u16 gUnk_02002170;
extern u16 gUnk_02002178[];
extern u16 gUnk_03007FF8;
extern volatile u16 gUnk_0202ED78;
extern u8 gUnk_0202EF90;
extern u16 gUnk_0202EF40[4][4];

u16 sub_080031C8(u16 keys);
u8 sub_080032E4(u16 a, u8 b);
u8 sub_08003314(u16 a);
u16 sub_08003238(u16 a);
void sub_0800F818(u16 data);

s32 sub_08003330(void)
{
    volatile u16 recv[4];
    volatile s32 i;
    u8 unused[12];
    s32 done;
    u8 retry;
    u32 phase;
    u8 n;
    u16 pkt;
    u16 menuKeys;

    menuKeys = sub_080031C8((u16)~*(volatile u16 *)0x04000130);
    for (i = 0; i < gUnk_020020AC; i++) {
        gUnk_0202EF40[i][0] = 0;
        gUnk_02002178[i] = 0;
    }
    phase = 0;
    done = 0;
    retry = 0;
    pkt = (menuKeys & 0x7F) | ((menuKeys & 0xF) << 7);
retry_it:
    do {
        if (retry > gUnk_020020AC) {
            gUnk_0200216C = 0;
            gUnk_02002170 = 0;
            return 1;
        }
        if (phase == 0) {
            u32 t = (gUnk_02002170 << 11) | pkt | 0xFFFF8000;
            gUnk_0202ED78 = t;
        } else {
            u32 t = (gUnk_02002170 << 11) | pkt | 0x4000;
            gUnk_0202ED78 = t;
        }
        sub_0800F818(gUnk_0202ED78);
        while ((gUnk_03007FF8 & 0x80) == 0) {
            if (gUnk_0200216C > 0x64) {
                gUnk_0200216C = 0;
                retry++;
                goto retry_it;
            }
        }
        gUnk_03007FF8 &= 0xFF7F;
        if (gUnk_0202EF90 == 0) {
            for (i = gUnk_0202EF90; i <= 0x257; i++)
                ;
        }
        for (i = 0; i < gUnk_020020AC; i++)
            recv[i] = gUnk_0202EF40[i][0];
        if (phase != 0) {
            n = 0;
            for (i = 0; i < gUnk_020020AC; i++) {
                if (((recv[i] >> 7) & 0xF) == (recv[i] & 0xF)
                    && recv[i] != 0xFFFF
                    && recv[i] != 0
                    && sub_08003314(recv[i] & 0x7F)) {
                    if ((recv[i] >> 14) == 1 && sub_080032E4((recv[i] >> 11) & 7, 0))
                        n++;
                    else if ((recv[i] >> 14) == 2 && sub_080032E4((recv[i] >> 11) & 7, 1)) {
                        n++;
                        recv[i] = gUnk_02002178[i];
                    }
                }
            }
            if (n == gUnk_020020AC) {
                for (i = 0; i < gUnk_020020AC; i++)
                    gUnk_020020A0[i] = sub_08003238(recv[i] & 0x7F);
                done = 1;
            }
        } else {
            n = 0;
            for (i = phase; i < gUnk_020020AC; i++) {
                if (((recv[i] >> 7) & 0xF) == (recv[i] & 0xF)
                    && recv[i] != 0xFFFF
                    && recv[i] != 0
                    && ((recv[i] >> 14) == 2 || (recv[i] >> 14) == 1)
                    && sub_080032E4((recv[i] >> 11) & 7, 0)
                    && sub_08003314(recv[i] & 0x7F))
                    n++;
            }
            if (n == gUnk_020020AC) {
                phase = 1;
                for (i = 0; i < gUnk_020020AC; i++)
                    gUnk_02002178[i] = recv[i];
            }
        }
    } while (done == 0);
    gUnk_02002170 = (gUnk_02002170 + 1) & 7;
    return 0;
}
