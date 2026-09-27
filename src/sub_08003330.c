/*
 * ExchangeLinkInput: SIO handshake with retry, the low twin of sub_0833C874
 * (same source, renamed globals). Levers that made it match:
 * - the masks are literals and the packet expression sits inside the loop,
 *   so loop.c hoists 0x7F, 0xF and the packet into r9, r8 and r5.
 * - separate counters per branch (n, n2) and a non-volatile send word keep
 *   gcse's reaching registers low enough in priority to spill.
 * - only the flag clear and the timer read are volatile: the ROM re-reads
 *   them, but not the flag test.
 */
#include "global.h"
#include "functions.h"
#include "variables.h"

extern u16 gUnk_02002178[];

u16 PackLinkKeys(u16 keys);
u8 sub_080032E4(u16 seq, u8 next);
u8 sub_08003314(u16 id);
u16 UnpackLinkKeys(u16 id);

s32 ExchangeLinkInput(void)
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
    keys = PackLinkKeys(keys);
    for (i = 0; i < gNumLinkPlayers[0]; i++) {
        *(u16 *)((u8 *)gUnk_0202EF40 + i * 8) = 0;
        *(u16 *)((u8 *)gUnk_02002178 + i * 2) = 0;
    }
    phase = 0;
    done = 0;
    retry = 0;
    do {
top:
        if (retry > gNumLinkPlayers[0]) {
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
            gUnk_0202ED78[0] = (gUnk_02002170 << 11) | ((keys & 0x7F) | ((keys & 0xF) << 7)) | 0x8000;
        else
            gUnk_0202ED78[0] = (gUnk_02002170 << 11) | ((keys & 0x7F) | ((keys & 0xF) << 7)) | 0x4000;
        SioSendWord(gUnk_0202ED78[0]);
        for (;;) {
            if (gUnk_03007FF8 & 0x80) {
                *(volatile u16 *)&gUnk_03007FF8 &= 0xFF7F;
                break;
            }
            if (*(volatile u16 *)&gUnk_0200216C > 100)
                goto timeout;
        }
        if (gLinkPlayerId[0] == 0) {
            for (i = 0; i <= 0x257; i++)
                ;
        }
        for (i = 0; i < gNumLinkPlayers[0]; i++)
            recv[i] = *(u16 *)((u8 *)gUnk_0202EF40 + i * 8);
        if (phase == 0) {
            n = 0;
            for (i = phase; i < gNumLinkPlayers[0]; i++) {
                if ((recv[i] & 0xF) == ((recv[i] >> 7) & 0xF)
                    && recv[i] != 0xFFFF
                    && recv[i] != 0
                    && ((recv[i] >> 14) == 2 || (recv[i] >> 14) == 1)
                    && sub_080032E4((recv[i] >> 11) & 7, 0)
                    && sub_08003314(recv[i] & 0x7F))
                    n++;
            }
            if (n == gNumLinkPlayers[0]) {
                phase = 1;
                for (i = 0; i < gNumLinkPlayers[0]; i++)
                    gUnk_02002178[i] = recv[i];
            }
        } else {
            n2 = 0;
            for (i = 0; i < gNumLinkPlayers[0]; i++) {
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
            if (n2 == gNumLinkPlayers[0]) {
                for (i = 0; i < gNumLinkPlayers[0]; i++)
                    gUnk_020020A0[i] = UnpackLinkKeys(recv[i] & 0x7F);
                done = 1;
            }
        }
    } while (done == 0);
    gUnk_02002170 = (gUnk_02002170 + 1) & 7;
    return 0;
}
