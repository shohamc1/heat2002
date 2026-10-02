#include "global.h"
#include "functions.h"
#include "variables.h"
#include "gba/io_reg.h"
#include "gba/syscall.h"

void IslandSioTransferInit(u32 send, void *chunk)
{
    register u32 one PIN(r8);
    register struct CommRegs *g PIN(r4);
    u32 sum;
    u32 fill;
    u32 *p;
    u32 count;

    sum = 0;
    REG_IME = 0;
    REG_IE &= 0xFF3F;
    one = 1;
    REG_IME = 1;
    fill = 0;
    g = &gIsland_SioTransfer;
    sub_083647FC(&fill, g, CPU_SET_32BIT | CPU_SET_SRC_FIXED | sizeof(struct CommRegs) / 4);
    *(volatile u32 *)REG_ADDR_SIOCNT = 0x2003;
    g->data = chunk;
    g->count = -1;
    if (send != 0) {
        REG_TM3CNT = 0;
        g->mode = one;
        p = chunk;
        count = 0x8000 / 4;
        do {
            sum += *p++;
            count--;
        } while (count != 0);
        g->checksum = ~sum;
        REG_SIOCNT = 0x1000;
        REG_SIOCNT = 0x1001;
    }
}

u32 IslandSioTransferUpdate(u32 *chunkSize)
{
    switch (gIsland_SioTransfer.state) {
        case 0:
            if ((*(volatile u32 *)&gIsland_SioTransfer & 0x00FF00FF) != 0)
                gIsland_SioTransfer.state = 1;
            break;
        case 1:
            if (gIsland_SioTransfer.mode == 1) {
                if (gIsland_SioTransfer.retry <= 5)
                    break;
            } else {
                REG_SIOCNT = SIO_32BIT_MODE;
            }
            REG_SIODATA32 = 0;
            REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
            {
                register u32 mode PIN(r4) = gIsland_SioTransfer.mode;

                if (mode == 1) {
                    REG_SIOCNT |= SIO_START;
                    REG_TM3CNT = ((TIMER_INTR_ENABLE | TIMER_ENABLE) << 16) | 0xF318;
                    REG_IME = 0;
                    REG_IE |= INTR_FLAG_TIMER3;
                    REG_IME = mode;
                } else {
                    REG_SIOCNT |= SIO_INTR_ENABLE | SIO_START;
                    REG_IME = 0;
                    REG_IE |= INTR_FLAG_SERIAL;
                    REG_IME = 1;
                }
            }
            gIsland_SioTransfer.retry = 0;
            gIsland_SioTransfer.state = 2;
            break;
        case 2: {
            register s32 count PIN(r6) = gIsland_SioTransfer.count;
            register s32 chunk PIN(r4) = count;

            if (count > 0x2000)
                chunk = 0x2000;
            else if (count < 0)
                chunk = 0;
            if (chunkSize != 0)
                *chunkSize = chunk;
            if (gIsland_SioTransfer.mode != 1) {
                if (gIsland_SioTransfer.index < chunk) {
                    register struct CommRegs *w PIN(r3) = &gIsland_SioTransfer;
                    u32 *data = gIsland_SioTransfer.data;
                    {
                        s32 i;

                        do {
                            i = w->index;
                            w->crc = w->crc + data[i];
                            i++;
                            w->index = i;
                        } while (i < chunk);
                    }
                }
                if (count > 0x2000) {
                    u32 t = gIsland_SioTransfer.checksum + gIsland_SioTransfer.crc;
                    gIsland_SioTransfer.checksum = t;
                    if (t == -1)
                        gIsland_SioTransfer.flag = 1;
                }
            }
            if (count > 0x2000 || gIsland_SioTransfer.retry == 140)
                gIsland_SioTransfer.state = 3;
        } break;
        case 3:
            REG_IME = 0;
            {
                volatile u16 *ie = &REG_IE;
                volatile u32 *p;

                *ie &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
                REG_IME = 1;
                REG_SIOCNT = SIO_32BIT_MODE;
                *(volatile u32 *)REG_ADDR_SIOCNT = SIO_MULTI_MODE;
                *(volatile u32 *)REG_ADDR_SIOCNT = SIO_MULTI_MODE | SIO_115200_BPS;
                p = (volatile u32 *)((u32)ie - 0xE0);
                *(volatile long long *)p = 0;
            }
            if (gIsland_SioTransfer.mode != 0)
                REG_TM3CNT = 0;
            REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
            if (gIsland_SioTransfer.mode != 0) {
                gIsland_SioTransfer.retry = 0;
                gIsland_SioTransfer.state = 4;
                break;
            }
            return 1;
        case 4:
            if (gIsland_SioTransfer.retry <= 2)
                break;
            return 1;
    }
    gIsland_SioTransfer.retry = gIsland_SioTransfer.retry + 1;
    return 0;
}
