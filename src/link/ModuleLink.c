#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"

extern u32 gUnk_0203DFF4;
extern u8 gModule_DetectedPlayers;

void ModuleSetLinkSerialIntr(void);
void ModuleInitMultiplayerSio(void);
void sub_08344B74(void);
void sub_08344B68(u32 a, u32 b);
void ModuleSioSendWord(u16 a);

void ModuleResetLinkState(void)
{
    u32 *linkStatePtr;
    u16 *timeoutPtr;
    u8 *playerSlotsPtr;
    register u8 mask asm("r3");
    u8 i;
    u8 j;

    *(volatile u16 *)0x04000134 = 0;
    *(volatile u16 *)0x04000128 = 0;
    i = 0;
    linkStatePtr = &gUnk_0203DFF4;
    timeoutPtr = &gUnk_0203917C;
    playerSlotsPtr = gUnk_0203E1C0;
    mask = 0xFF;
    do
    {
        playerSlotsPtr[i * 4 + 0] |= mask;
        playerSlotsPtr[i * 4 + 1] |= mask;
        playerSlotsPtr[i * 4 + 2] |= mask;
        i++;
    } while (i != 4);
    *linkStatePtr = 0;
    *timeoutPtr = 0;
    ModuleSetLinkSerialIntr();
    ModuleInitMultiplayerSio();
    *(volatile u16 *)0x04000200 |= 0x80;
    if ((*(u8 *)0x04000128 & 0x30) == 0)
        *(volatile u16 *)0x04000200 |= 0x40;
    i = 0;
    do
    {
        gModule_LinkTxBuffer[i] = 0;
        j = 0;
        do
        {
            *(u16 *)((u8 *)gModule_LinkRecvWords + j * 2 + i * 8) = 0;
            j++;
        } while (j <= 3);
        i++;
    } while (i <= 3);
}

void ModuleLinkHandshake(void)
{
    u8 *lang;
    u8 i;
    u16 v;
    vu16 *tx;

    ModuleResetLinkState();
    i = 0;
    /* Through a pointer: a store to a volatile array element by name
       compiles to a read-modify-write. */
    tx = gModule_LinkTxBuffer;
    do {
        if ((*(u8 *)REG_ADDR_SIOCNT & 0x30) == 0)
            sub_08344B74();
        else
            sub_08344B68(1, INTR_FLAG_SERIAL);
        ModuleReadKeys();
        /* lang is a variable so its pseudo predates the SIOCNT address
           temp: they tie on allocation priority, and the older one gets
           r6. */
        tx[0] = ((u16)((((*(vu32 *)REG_ADDR_SIOCNT << 26) >> 30) + 1) << 12)
                 | 0x100)
              | ((*(lang = &gModule_Language) + 1) & 0xFF);
        ModuleSioSendWord(tx[0]);
        gUnk_0203E1C0[2] |= 0xFF;
        gUnk_0203E1C0[6] |= 0xFF;
        gUnk_0203E1C0[10] |= 0xFF;
        gUnk_0203E1C0[14] |= 0xFF;
        gModule_DetectedPlayers = 0;
        v = gModule_LinkRecvWords[0];
        if ((v >> 12) == 1) {
            gUnk_0203E1C0[2] = 1;
            gModule_DetectedPlayers = 1;
            if (*(u8 *)REG_ADDR_SIOCNT & 0x30)
                *lang = v - 1;
            if ((gModule_LinkRecvWords[4] >> 12) == 2) {
                gUnk_0203E1C0[6] = 1;
                gModule_DetectedPlayers = 2;
                if ((gModule_LinkRecvWords[8] >> 12) == 3) {
                    gUnk_0203E1C0[10] = 1;
                    gModule_DetectedPlayers = 3;
                    if ((gModule_LinkRecvWords[12] >> 12) == 4) {
                        gUnk_0203E1C0[14] = 1;
                        gModule_DetectedPlayers = 4;
                    }
                }
            }
        }
        gModule_LinkPlayerId = (*(vu32 *)REG_ADDR_SIOCNT << 26) >> 30;
        *(u8 *)&gModule_NumLinkPlayers = gModule_DetectedPlayers;
        if (*(u8 *)&gModule_NumLinkPlayers <= 1)
            i--;
        gModule_LinkRecvWords[0] = 0;
        gModule_LinkRecvWords[4] = 0;
        gModule_LinkRecvWords[8] = 0;
        gModule_LinkRecvWords[12] = 0;
        i++;
    } while (i != 5);
}
