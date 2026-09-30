#include "global.h"
#include "gba/compat.h"
#include "variables.h"
#include "gba/io_reg.h"

struct CommRegs
{
    u8 mode;      /* +0 */
    u8 state;     /* +1 */
    u8 retry;     /* +2 */
    u8 flag;      /* +3 */
    u32 *data;    /* +4 */
    s32 count;    /* +8 */
    u32 checksum; /* +0xC */
    u32 crc;      /* +0x10 */
    s32 index;    /* +0x14 */
};

void SioTransferInit(u32 a1, const u8 *a2)
{
    u32 sum = 0;
    register u32 one __asm__("r8");
    u32 fill;
    register u32 *g __asm__("r4");

    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    one = 1;
    REG_IME = 1;
    fill = 0;
    g = (u32 *)&gSioTransfer;
    CpuSet((u32)&fill, (u32)g, CPU_SET_32BIT | CPU_SET_SRC_FIXED | 6);
    *(volatile u32 *)REG_ADDR_SIOCNT = SIO_MULTI_MODE | SIO_115200_BPS;
    g[1] = (u32)a2;
    g[2] = -1;
    if (a1 != 0) {
        REG_TM3CNT = 0;
        *(u8 *)g = one;
        {
            u32 *p = (u32 *)a2;
            u32 count = 0x80 << 6;
            do {
                sum += *p++;
                count = count - 1;
            } while (count > 0);
        }
        g[3] = ~sum;
        REG_SIOCNT = SIO_32BIT_MODE;
        REG_SIOCNT = SIO_32BIT_MODE + 1;
    }
}

u32 SioTransferUpdate(u32 *a1)
{
    switch (gSioTransfer.state) {
        case 0:
            if ((*(volatile u32 *)&gSioTransfer & 0x00FF00FF) != 0)
                gSioTransfer.state = 1;
            break;
        case 1:
            if (gSioTransfer.mode == 1) {
                if (gSioTransfer.retry <= 5)
                    break;
            } else {
                REG_SIOCNT = SIO_32BIT_MODE;
            }
            REG_SIODATA32 = 0;
            REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
            {
                register u32 mode __asm__("r4") = gSioTransfer.mode;

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
            gSioTransfer.retry = 0;
            gSioTransfer.state = 2;
            break;
        case 2: {
            register s32 count __asm__("r6") = gSioTransfer.count;
            register s32 chunk __asm__("r4") = count;

            if (count > 0x2000)
                chunk = 0x2000;
            else if (count < 0)
                chunk = 0;
            if (a1 != 0)
                *a1 = chunk;
            if (gSioTransfer.mode != 1) {
                if (gSioTransfer.index < chunk) {
                    register s32 *w __asm__("r3") = (s32 *)&gSioTransfer;
                    u32 *data = gSioTransfer.data;
                    {
                        s32 i;

                        do {
                            i = w[5];
                            w[4] = w[4] + data[i];
                            i++;
                            w[5] = i;
                        } while (i < chunk);
                    }
                }
                if (count > 0x2000) {
                    u32 t = gSioTransfer.checksum + gSioTransfer.crc;
                    gSioTransfer.checksum = t;
                    if (t == -1)
                        gSioTransfer.flag = 1;
                }
            }
            if (count > 0x2000 || gSioTransfer.retry == 0x8C)
                gSioTransfer.state = 3;
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
            if (gSioTransfer.mode != 0)
                REG_TM3CNT = 0;
            REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
            if (gSioTransfer.mode != 0) {
                gSioTransfer.retry = 0;
                gSioTransfer.state = 4;
                break;
            }
            return 1;
        case 4:
            if (gSioTransfer.retry <= 2)
                break;
            return 1;
    }
    gSioTransfer.retry = gSioTransfer.retry + 1;
    return 0;
}
