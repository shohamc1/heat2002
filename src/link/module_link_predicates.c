#include "global.h"
#include "gba/defines.h"
#include "variables.h"

/*
 * ModuleExchangeLinkInput: SIO handshake with retry. Levers that made it match:
 * - the masks are literals and the packet expression sits inside the loop,
 *   so loop.c hoists 0x7F, 0xF and the packet into r9, r8 and r5.
 * - separate counters per branch (n, n2) and a non-volatile send word keep
 *   gcse's reaching registers low enough in priority to spill.
 * - only the flag clear and the timer read are volatile: the ROM re-reads
 *   them, but not the flag test.
 */
extern u16 gUnk_02039188[];
u16 ModulePackLinkKeys(u16 keys);
u8 ModuleIsLinkSeqNumExpected(u16 seq, u8 next);
u32 ModuleIsValidLinkKeys(u32 keys);
u16 ModuleUnpackLinkKeys(u16 id);
void ModuleSioSendWord(u16 data);

u8 ModuleIsLinkSeqNumExpected(u16 seq, u8 next)
{
    u16 recvSeq = seq;

    if (next == 0) {
        if (recvSeq != gModule_LinkTxSeqNum)
            return 0;
    } else {
        if (recvSeq != ((gModule_LinkTxSeqNum + 1) & 7))
            return 0;
    }
    return 1;
}

u32 ModuleIsValidLinkKeys(u32 keys)
{
    u32 tmp = keys << 16;
    if (((tmp >> 21) & 3) == 3)
        return 0;
    if (((tmp >> 19) & 3) == 3)
        return 0;
    return 1;
}

s32 ModuleExchangeLinkInput(void)
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
    keys = ModulePackLinkKeys(keys);
    for (i = 0; i < gModule_NumLinkPlayers[0]; i++) {
        *(u16 *)((u8 *)gModule_LinkRecvWords + i * 8) = 0;
        *(u16 *)((u8 *)gUnk_02039188 + i * 2) = 0;
    }
    phase = 0;
    done = 0;
    retry = 0;
    do {
    top:
        if (retry > gModule_NumLinkPlayers[0]) {
            gUnk_0203917C = 0;
            gModule_LinkTxSeqNum = 0;
            return 1;
        }
        goto send;

    timeout:
        gUnk_0203917C = 0;
        retry++;
        goto top;

    send:
        if (phase == 0)
            gModule_LinkTxBuffer[0] = (gModule_LinkTxSeqNum << 11) | ((keys & 0x7F) | ((keys & 0xF) << 7)) | 0x8000;
        else
            gModule_LinkTxBuffer[0] = (gModule_LinkTxSeqNum << 11) | ((keys & 0x7F) | ((keys & 0xF) << 7)) | 0x4000;
        ModuleSioSendWord(gModule_LinkTxBuffer[0]);
        for (;;) {
            if (gIntrCheck & 0x80) {
                *(volatile u16 *)&gIntrCheck &= 0xFF7F;
                break;
            }
            if (*(volatile u16 *)&gUnk_0203917C > 100)
                goto timeout;
        }
        if (gModule_LinkPlayerId == 0) {
            for (i = 0; i <= 0x257; i++)
                ;
        }
        for (i = 0; i < gModule_NumLinkPlayers[0]; i++)
            recv[i] = *(u16 *)((u8 *)gModule_LinkRecvWords + i * 8);
        if (phase == 0) {
            n = 0;
            for (i = phase; i < gModule_NumLinkPlayers[0]; i++) {
                if ((recv[i] & 0xF) == ((recv[i] >> 7) & 0xF) && recv[i] != 0xFFFF && recv[i] != 0 &&
                    ((recv[i] >> 14) == 2 || (recv[i] >> 14) == 1) &&
                    ModuleIsLinkSeqNumExpected((recv[i] >> 11) & 7, 0) &&
                    ((u8 (*)(u16))ModuleIsValidLinkKeys)(recv[i] & 0x7F))
                    n++;
            }
            if (n == gModule_NumLinkPlayers[0]) {
                phase = 1;
                for (i = 0; i < gModule_NumLinkPlayers[0]; i++)
                    gUnk_02039188[i] = recv[i];
            }
        } else {
            n2 = 0;
            for (i = 0; i < gModule_NumLinkPlayers[0]; i++) {
                if ((recv[i] & 0xF) == ((recv[i] >> 7) & 0xF) && recv[i] != 0xFFFF && recv[i] != 0 &&
                    ((u8 (*)(u16))ModuleIsValidLinkKeys)(recv[i] & 0x7F)) {
                    if ((recv[i] >> 14) == 1 && ModuleIsLinkSeqNumExpected((recv[i] >> 11) & 7, 0))
                        n2++;
                    else if ((recv[i] >> 14) == 2 && ModuleIsLinkSeqNumExpected((recv[i] >> 11) & 7, 1)) {
                        n2++;
                        recv[i] = gUnk_02039188[i];
                    }
                }
            }
            if (n2 == gModule_NumLinkPlayers[0]) {
                for (i = 0; i < gModule_NumLinkPlayers[0]; i++)
                    gUnk_020390B0[i] = ModuleUnpackLinkKeys(recv[i] & 0x7F);
                done = 1;
            }
        }
    } while (done == 0);
    gModule_LinkTxSeqNum = (gModule_LinkTxSeqNum + 1) & 7;
    return 0;
}
