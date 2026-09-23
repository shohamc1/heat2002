/*
 * sub_08003330: SIO handshake with retry, the low twin of sub_0833C874
 * (same source, renamed globals). Levers that made it match:
 * - the masks are literals and the packet expression sits inside the loop,
 *   so loop.c hoists 0x7F, 0xF and the packet into r9, r8 and r5.
 * - separate counters per branch (n, n2) and a non-volatile send word keep
 *   gcse's reaching registers low enough in priority to spill.
 * - only the flag clear and the timer read are volatile: the ROM re-reads
 *   them, but not the flag test.
 */
#include "global.h"

extern u8 gUnk_020020AC;
extern u16 gUnk_0202EF40[][4];
extern u16 gUnk_02002178[];
extern u16 gUnk_0200216C;
extern u16 gUnk_02002170;
extern u16 gUnk_0202ED78;
extern u16 gUnk_03007FF8;
extern u8 gUnk_0202EF90;
extern u16 gUnk_020020A0[];

u16 sub_080031C8(u16 keys);
u8 sub_080032E4(u16 seq, u8 next);
u8 sub_08003314(u16 id);
u16 sub_08003238(u16 id);
void sub_0800F818(u16 data);

s32 sub_08003330(void)
{
    u16 recv[4];
    volatile s32 i;
    u8 unused[12];
    s32 done;
    u16 keys;
    u8 retry;
    u32 phase;
    u8 n;
    u8 n2;

    keys = ~*(u16 *)0x04000130;
    keys = sub_080031C8(keys);
    for (i = 0; i < gUnk_020020AC; i++) {
        gUnk_0202EF40[i][0] = 0;
        gUnk_02002178[i] = 0;
    }
    phase = 0;
    done = 0;
    retry = 0;
    do {
top:
        if (retry > gUnk_020020AC) {
            gUnk_0200216C = 0;
            gUnk_02002170 = 0;
            return 1;
        }
        goto send;

timeout:
        gUnk_0200216C = 0;
        retry++;
        goto top;

send:
        if (phase == 0)
            gUnk_0202ED78 = (gUnk_02002170 << 11) | ((keys & 0x7F) | ((keys & 0xF) << 7)) | 0x8000;
        else
            gUnk_0202ED78 = (gUnk_02002170 << 11) | ((keys & 0x7F) | ((keys & 0xF) << 7)) | 0x4000;
        sub_0800F818(gUnk_0202ED78);
        for (;;) {
            if (gUnk_03007FF8 & 0x80) {
                *(volatile u16 *)&gUnk_03007FF8 &= 0xFF7F;
                break;
            }
            if (*(volatile u16 *)&gUnk_0200216C > 100)
                goto timeout;
        }
        if (gUnk_0202EF90 == 0) {
            for (i = 0; i <= 0x257; i++)
                ;
        }
        for (i = 0; i < gUnk_020020AC; i++)
            recv[i] = gUnk_0202EF40[i][0];
        if (phase == 0) {
            n = 0;
            for (i = phase; i < gUnk_020020AC; i++) {
                if ((recv[i] & 0xF) == ((recv[i] >> 7) & 0xF)
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
        } else {
            n2 = 0;
            for (i = 0; i < gUnk_020020AC; i++) {
                if ((recv[i] & 0xF) == ((recv[i] >> 7) & 0xF)
                    && recv[i] != 0xFFFF
                    && recv[i] != 0
                    && sub_08003314(recv[i] & 0x7F)) {
                    if ((recv[i] >> 14) == 1 && sub_080032E4((recv[i] >> 11) & 7, 0))
                        n2++;
                    else if ((recv[i] >> 14) == 2 && sub_080032E4((recv[i] >> 11) & 7, 1)) {
                        n2++;
                        recv[i] = gUnk_02002178[i];
                    }
                }
            }
            if (n2 == gUnk_020020AC) {
                for (i = 0; i < gUnk_020020AC; i++)
                    gUnk_020020A0[i] = sub_08003238(recv[i] & 0x7F);
                done = 1;
            }
        }
    } while (done == 0);
    gUnk_02002170 = (gUnk_02002170 + 1) & 7;
    return 0;
}
