#include "global.h"
#include "gba/io_reg.h"
#include "variables.h"

struct CommRegs
{
    u8 mode;    /* +0 */
    u8 state;   /* +1 */
    u8 retry;   /* +2 */
    u8 flag;    /* +3 */
    u32 data;   /* +4 */
    s32 count;  /* +8 */
    u32 fC;     /* +0xC */
    u32 crc;    /* +0x10 */
    s32 index;  /* +0x14 */
};


u32 sub_08364550(u32 *a1)
{
    switch (gUnk_03000C00.state)
    {
    case 0:
        if ((*(volatile u32 *)&gUnk_03000C00 & 0x00FF00FF) != 0)
            gUnk_03000C00.state = 1;
        break;
    case 1:
        if (gUnk_03000C00.mode == 1)
        {
            if (gUnk_03000C00.retry <= 5)
                break;
        }
        else
        {
            REG_SIOCNT = SIO_32BIT_MODE;
        }
        REG_SIODATA32 = 0;
        REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
        {
            register u32 mode __asm__("r4") = gUnk_03000C00.mode;

            if (mode == 1)
            {
                REG_SIOCNT |= SIO_START;
                REG_TM3CNT = 0x00C0F318;
                REG_IME = 0;
                REG_IE |= INTR_FLAG_TIMER3;
                REG_IME = mode;
            }
            else
            {
                REG_SIOCNT |= SIO_INTR_ENABLE | SIO_START;
                REG_IME = 0;
                REG_IE |= INTR_FLAG_SERIAL;
                REG_IME = 1;
            }
        }
        gUnk_03000C00.retry = 0;
        gUnk_03000C00.state = 2;
        break;
    case 2:
        {
            register s32 count __asm__("r6") = gUnk_03000C00.count;
            register s32 chunk __asm__("r4") = count;

            if (count > 0x2000)
                chunk = 0x2000;
            else if (count < 0)
                chunk = 0;
            if (a1 != 0)
                *a1 = chunk;
            if (gUnk_03000C00.mode != 1)
            {
                if (gUnk_03000C00.index < chunk)
                {
                    register s32 *w __asm__("r3") = (s32 *)&gUnk_03000C00;
                    u32 *data = (u32 *)gUnk_03000C00.data;
                    {
                        s32 i;

                        do
                        {
                            i = w[5];
                            w[4] = w[4] + data[i];
                            i++;
                            w[5] = i;
                        } while (i < chunk);
                    }
                }
                if (count > 0x2000)
                {
                    u32 t = gUnk_03000C00.fC + gUnk_03000C00.crc;
                    gUnk_03000C00.fC = t;
                    if (t == -1)
                        gUnk_03000C00.flag = 1;
                }
            }
            if (count > 0x2000 || gUnk_03000C00.retry == 0x8C)
                gUnk_03000C00.state = 3;
        }
        break;
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
        if (gUnk_03000C00.mode != 0)
            REG_TM3CNT = 0;
        REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
        if (gUnk_03000C00.mode != 0)
        {
            gUnk_03000C00.retry = 0;
            gUnk_03000C00.state = 4;
            break;
        }
        return 1;
    case 4:
        if (gUnk_03000C00.retry <= 2)
            break;
        return 1;
    }
    gUnk_03000C00.retry = gUnk_03000C00.retry + 1;
    return 0;
}
