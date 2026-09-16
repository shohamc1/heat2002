#include "global.h"
#include "gba/io_reg.h"

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

extern struct CommRegs gUnk_0202CDD0;

u32 sub_0800E460(u32 *a1)
{
    switch (gUnk_0202CDD0.state)
    {
    case 0:
        if ((*(volatile u32 *)&gUnk_0202CDD0 & 0x00FF00FF) != 0)
            gUnk_0202CDD0.state = 1;
        break;
    case 1:
        if (gUnk_0202CDD0.mode == 1)
        {
            if (gUnk_0202CDD0.retry <= 5)
                break;
        }
        else
        {
            REG_SIOCNT = 0x80 << 5;
        }
        REG_SIODATA32 = 0;
        REG_IF = 0xC0;
        {
            register u32 mode __asm__("r4") = gUnk_0202CDD0.mode;

            if (mode == 1)
            {
                REG_SIOCNT |= 0x80;
                REG_TM3CNT = 0x00C0F318;
                REG_IME = 0;
                REG_IE |= 0x40;
                REG_IME = mode;
            }
            else
            {
                REG_SIOCNT |= 0x81 << 7;
                REG_IME = 0;
                REG_IE |= 0x80;
                REG_IME = 1;
            }
        }
        gUnk_0202CDD0.retry = 0;
        gUnk_0202CDD0.state = 2;
        break;
    case 2:
        {
            register s32 count __asm__("r6") = gUnk_0202CDD0.count;
            register s32 chunk __asm__("r4") = count;

            if (count > 0x2000)
                chunk = 0x2000;
            else if (count < 0)
                chunk = 0;
            if (a1 != 0)
                *a1 = chunk;
            if (gUnk_0202CDD0.mode != 1)
            {
                if (gUnk_0202CDD0.index < chunk)
                {
                    register s32 *w __asm__("r3") = (s32 *)&gUnk_0202CDD0;
                    u32 *data = (u32 *)gUnk_0202CDD0.data;
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
                    u32 t = gUnk_0202CDD0.fC + gUnk_0202CDD0.crc;
                    gUnk_0202CDD0.fC = t;
                    if (t == -1)
                        gUnk_0202CDD0.flag = 1;
                }
            }
            if (count > 0x2000 || gUnk_0202CDD0.retry == 0x8C)
                gUnk_0202CDD0.state = 3;
        }
        break;
    case 3:
        REG_IME = 0;
        {
            volatile u16 *ie = (volatile u16 *)0x04000200;
            volatile u32 *p;

            *ie &= 0xFF3F;
            REG_IME = 1;
            REG_SIOCNT = 0x80 << 5;
            *(volatile u32 *)0x04000128 = 0x80 << 6;
            *(volatile u32 *)0x04000128 = (0x80 << 6) + 3;
            p = (volatile u32 *)((u32)ie - 0xE0);
            *(volatile long long *)p = 0;
        }
        if (gUnk_0202CDD0.mode != 0)
            REG_TM3CNT = 0;
        REG_IF = 0xC0;
        if (gUnk_0202CDD0.mode != 0)
        {
            gUnk_0202CDD0.retry = 0;
            gUnk_0202CDD0.state = 4;
            break;
        }
        return 1;
    case 4:
        if (gUnk_0202CDD0.retry <= 2)
            break;
        return 1;
    }
    gUnk_0202CDD0.retry = gUnk_0202CDD0.retry + 1;
    return 0;
}
