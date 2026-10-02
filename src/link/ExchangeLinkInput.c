/*
 * ExchangeLinkInput: SIO handshake with retry, the low twin of ModuleExchangeLinkInput
 * (same source, renamed globals). Levers that made it match:
 * - the masks are literals and the packet expression sits inside the loop,
 *   so loop.c hoists 0x7F, 0xF and the packet into r9, r8 and r5.
 * - separate counters per branch (n, n2) and a non-volatile send word keep
 *   gcse's reaching registers low enough in priority to spill.
 * - only the flag clear and the timer read are volatile: the ROM re-reads
 *   them, but not the flag test.
 */
#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

u8 IsLinkSeqNumExpected(u16 seq, u8 next);

/* This file's EWRAM variables below 0x02022E20 (gNumLinkPlayers,
   gLinkVBlankTimeout, gLinkTxSeqNum and gLinkPhase0RecvWords) moved to
   src/system/globals.c, the 0x02000DE0-0x02022E20 run's owner; the first
   three are declared in variables.h. Only this file reads
   gLinkPhase0RecvWords. gLinkSendWords (0x0202ED78) moved to
   src/save/save.c, the owner of the 0x0202ED70-0x0202F1C0 run it sits in,
   and is declared in variables.h. */
extern u16 gLinkPhase0RecvWords[6];               /* 0x02002178 */
#if PLATFORM_GBA
/* The BIOS interrupt-check flag the serial ISR sets, in IWRAM: it takes
   ldscript.ld's .iwram_ExchangeLinkInput output section. The hosted build
   has no such definition -- variables.h maps the name onto the platform's
   INTR_CHECK variable instead (gba/defines.h). */
IWRAM_DATA u16 gIntrCheck = 0;
#endif

u8 IsLinkSeqNumExpected(u16 seq, u8 next)
{
    if (next == 0) {
        if (seq != gLinkTxSeqNum)
            return 0;
    } else {
        if (seq != ((gLinkTxSeqNum + 1) & 7))
            return 0;
    }
    return 1;
}

u8 IsValidLinkKeys(u16 keys)
{
    if ((keys >> 5 & 3) == 3)
        return 0;
    if ((keys >> 3 & 3) == 3)
        return 0;
    return 1;
}

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

    keys = ~REG_KEYINPUT;
    keys = PackLinkKeys(keys);
    for (i = 0; i < gNumLinkPlayers[0]; i++) {
        *(u16 *)((u8 *)gLinkRecvWords + i * 8) = 0;
        *(u16 *)((u8 *)gLinkPhase0RecvWords + i * 2) = 0;
    }
    phase = 0;
    done = 0;
    retry = 0;
    do {
    top:
        if (retry > gNumLinkPlayers[0]) {
            gLinkVBlankTimeout = 0;
            gLinkTxSeqNum = 0;
            return 1;
        }
        goto send;

    timeout:
        gLinkVBlankTimeout = 0;
        retry++;
        goto top;

    send:
        if (phase == 0)
            gLinkSendWords[0] = (gLinkTxSeqNum << 11) | ((keys & 0x7F) | ((keys & 0xF) << 7)) | 0x8000;
        else
            gLinkSendWords[0] = (gLinkTxSeqNum << 11) | ((keys & 0x7F) | ((keys & 0xF) << 7)) | 0x4000;
        SioSendWord(gLinkSendWords[0]);
        for (;;) {
            if (gIntrCheck & 0x80) {
                *(volatile u16 *)&gIntrCheck &= 0xFF7F;
                break;
            }
            if (*(volatile u16 *)&gLinkVBlankTimeout > 100)
                goto timeout;
        }
        if (gLinkPlayerId == 0) {
            for (i = 0; i <= 599; i++)
                ;
        }
        for (i = 0; i < gNumLinkPlayers[0]; i++)
            recv[i] = *(u16 *)((u8 *)gLinkRecvWords + i * 8);
        if (phase == 0) {
            n = 0;
            for (i = phase; i < gNumLinkPlayers[0]; i++) {
                if ((recv[i] & 0xF) == ((recv[i] >> 7) & 0xF) && recv[i] != 0xFFFF && recv[i] != 0 &&
                    ((recv[i] >> 14) == 2 || (recv[i] >> 14) == 1) && IsLinkSeqNumExpected((recv[i] >> 11) & 7, 0) &&
                    IsValidLinkKeys(recv[i] & 0x7F))
                    n++;
            }
            if (n == gNumLinkPlayers[0]) {
                phase = 1;
                for (i = 0; i < gNumLinkPlayers[0]; i++)
                    gLinkPhase0RecvWords[i] = recv[i];
            }
        } else {
            n2 = 0;
            for (i = 0; i < gNumLinkPlayers[0]; i++) {
                if ((recv[i] & 0xF) == ((recv[i] >> 7) & 0xF) && recv[i] != 0xFFFF && recv[i] != 0 &&
                    IsValidLinkKeys(recv[i] & 0x7F)) {
                    if ((recv[i] >> 14) == 1 && IsLinkSeqNumExpected((recv[i] >> 11) & 7, 0))
                        n2++;
                    else if ((recv[i] >> 14) == 2 && IsLinkSeqNumExpected((recv[i] >> 11) & 7, 1)) {
                        n2++;
                        recv[i] = gLinkPhase0RecvWords[i];
                    }
                }
            }
            if (n2 == gNumLinkPlayers[0]) {
                for (i = 0; i < gNumLinkPlayers[0]; i++)
                    gPlayerKeys[i] = UnpackLinkKeys(recv[i] & 0x7F);
                done = 1;
            }
        }
    } while (done == 0);
    gLinkTxSeqNum = (gLinkTxSeqNum + 1) & 7;
    return 0;
}
