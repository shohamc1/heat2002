#include "global.h"

/* Unmatched draft. See docs/learnings/sub_08003330.md. */

extern u8 gUnk_020020AC;    /* 0x020020AC */
extern u16 gUnk_020020A0[]; /* 0x020020A0 */
extern u16 gUnk_02002178[]; /* 0x02002178 */
extern u16 gUnk_0200216C;   /* 0x0200216C */
extern u16 gUnk_02002170;   /* 0x02002170 */
extern volatile u16 gUnk_0202ED78;   /* 0x0202ED78 */
extern u16 gUnk_0202EF40[]; /* 0x0202EF40 */
extern u8 gUnk_0202EF90;    /* 0x0202EF90 */
extern u16 gUnk_03007FF8;   /* 0x03007FF8 */

extern u16 sub_080031C8(u16 keys);
extern u32 sub_080032E4(u16 a, u8 b);
extern u32 sub_08003314(u16 a);
extern u32 sub_08003238(u16 a);
extern void sub_0800F818(u16 data);

u8 sub_08003330(void)
{
    u16 buf[4];
    volatile s32 i;
    u8 unused[12];
    u32 flag;
    u32 retries;
    u16 cmd;
    u32 changed;
    u32 cm;
    u32 pm;
    u32 flags;
    cmd = ~*(volatile u16 *)0x04000130;
    cmd = sub_080031C8(cmd);
    for (i = 0; i < gUnk_020020AC; i++)
    {
        gUnk_0202EF40[4 * i] = 0;
        gUnk_02002178[i] = 0;
    }
    changed = 0;
    flag = 0;
    retries = 0;
    cm = 0x7F;
    flags = cmd & cm;
    pm = 0x0F;
    flags |= (cmd & pm) << 7;

    for (;;)
    {
        if (retries > gUnk_020020AC)
        {
            gUnk_0200216C = 0;
            gUnk_02002170 = 0;
            return 1;
        }

        goto send;
timeout:
        gUnk_0200216C = 0;
        retries = (u8)(retries + 1);
        continue;
send:
        if (changed == 0)
        {
            gUnk_0202ED78 = gUnk_02002170 << 0xB | flags | 0xFFFF8000;
        }
        else
        {
            gUnk_0202ED78 = gUnk_02002170 << 0xB | flags | 0x4000;
        }

        sub_0800F818(gUnk_0202ED78);

        if (gUnk_03007FF8 & 0x80)
        {
            gUnk_03007FF8 = *(volatile u16 *)&gUnk_03007FF8 & 0xFF7F;
            goto ready;
        }
wait:
        if (gUnk_0200216C > 0x64)
            goto timeout;
        if (!(gUnk_03007FF8 & 0x80))
            goto wait;

        gUnk_03007FF8 = *(volatile u16 *)&gUnk_03007FF8 & 0xFF7F;
ready:

        if (gUnk_0202EF90 == 0)
        {
            for (i = 0; i <= 0x257; i++)
                ;
        }

        for (i = 0; i < gUnk_020020AC; i++)
            buf[i] = gUnk_0202EF40[4 * i];

        if (changed == 0)
        {
            u8 count;

            count = 0;
            for (i = 0; i < gUnk_020020AC; i++)
            {
                if ((buf[i] & pm) == ((buf[i] >> 7) & 0xF)
                    && buf[i] != 0xFFFF && buf[i] != 0
                    && ((buf[i] >> 14) == 2 || (buf[i] >> 14) == 1)
                    && (u8)sub_080032E4((buf[i] >> 0xB) & 7, 0)
                    && (u8)sub_08003314(buf[i] & cm))
                    count++;
            }
            if (count == gUnk_020020AC)
            {
                changed = 1;
                for (i = 0; i < gUnk_020020AC; i++)
                    gUnk_02002178[i] = buf[i];
            }
        }
        else
        {
            u8 count;

            count = 0;
            for (i = 0; i < gUnk_020020AC; i++)
            {
                if ((buf[i] & pm) == ((buf[i] >> 7) & pm)
                    && buf[i] != 0xFFFF && buf[i] != 0
                    && (u8)sub_08003314(buf[i] & cm))
                {
                    if ((buf[i] >> 14) == 1
                        && (u8)sub_080032E4((buf[i] >> 0xB) & 7, 0))
                        count++;
                    else if ((buf[i] >> 14) == 2)
                    {
                        if ((u8)sub_080032E4((buf[i] >> 0xB) & 7, 1))
                        {
                            count++;
                            buf[i] = gUnk_02002178[i];
                        }
                    }
                }
            }
            if (count == gUnk_020020AC)
            {
                for (i = 0; i < gUnk_020020AC; i++)
                {
                    u16 keys = sub_08003238(buf[i] & cm);
                    gUnk_020020A0[i] = keys;
                }
                flag = 1;
            }
        }

        if (flag != 0)
            break;
    }

    gUnk_02002170 = (gUnk_02002170 + 1) & 7;
    return 0;
}
