#include "global.h"
#include "variables.h"
#include "gba/io_reg.h"

struct CommRegs
{
    u8 mode;   /* +0 */
    u8 state;  /* +1 */
    u8 retry;  /* +2 */
    u8 flag;   /* +3 */
    u32 data;  /* +4 */
    s32 count; /* +8 */
    u32 checksum;    /* +0xC */
    u32 crc;   /* +0x10 */
    s32 index; /* +0x14 */
};

void sub_083647FC(const void *src, void *dest, u32 control);

void IslandSioTransferInit(u32 send, u32 chunk)
{
    register u32 one asm("r8");
    register u32 *g asm("r4");
    u32 sum;
    u32 fill;
    u32 *p;
    u32 count;

    sum = 0;
    *(volatile u16 *)0x04000208 = 0;
    *(volatile u16 *)0x04000200 &= 0xFF3F;
    one = 1;
    *(volatile u16 *)0x04000208 = 1;
    fill = 0;
    g = (u32 *)&gIsland_SioTransfer;
    sub_083647FC(&fill, g, 0x05000006);
    *(volatile u32 *)0x04000128 = 0x2003;
    g[1] = chunk;
    g[2] = -1;
    if (send != 0) {
        *(volatile u32 *)0x0400010C = 0;
        *(u8 *)g = one;
        p = (u32 *)chunk;
        count = 0x2000;
        do {
            sum += *p++;
            count--;
        } while (count != 0);
        g[3] = ~sum;
        *(volatile u16 *)0x04000128 = 0x1000;
        *(volatile u16 *)0x04000128 = 0x1001;
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
                register u32 mode __asm__("r4") = gIsland_SioTransfer.mode;

                if (mode == 1) {
                    REG_SIOCNT |= SIO_START;
                    REG_TM3CNT = 0x00C0F318;
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
            register s32 count __asm__("r6") = gIsland_SioTransfer.count;
            register s32 chunk __asm__("r4") = count;

            if (count > 0x2000)
                chunk = 0x2000;
            else if (count < 0)
                chunk = 0;
            if (chunkSize != 0)
                *chunkSize = chunk;
            if (gIsland_SioTransfer.mode != 1) {
                if (gIsland_SioTransfer.index < chunk) {
                    register s32 *w __asm__("r3") = (s32 *)&gIsland_SioTransfer;
                    u32 *data = (u32 *)gIsland_SioTransfer.data;
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
                    u32 t = gIsland_SioTransfer.checksum + gIsland_SioTransfer.crc;
                    gIsland_SioTransfer.checksum = t;
                    if (t == -1)
                        gIsland_SioTransfer.flag = 1;
                }
            }
            if (count > 0x2000 || gIsland_SioTransfer.retry == 0x8C)
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
                *(volatile u32 *)REG_ADDR_SIOCNT = 0x80 << 6;
                *(volatile u32 *)REG_ADDR_SIOCNT = (0x80 << 6) + 3;
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
