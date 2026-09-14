/*
 * PARKED (wave 4): rebuild diverges from the ROM (object 462 bytes vs the
 * real 452-byte function; first diff at 0x0800E20A, frame/pool offsets
 * drift from there). Dead-agent mid-edit state, same class as
 * sub_0800C430. Needs re-derivation from the asm before extracting.
 */
#include "global.h"

extern u16 gKeysPressed;
extern u8 gUnk_0807CA60[];
extern u8 gUnk_0833338C[];
extern u8 gUnk_08363EE8[];
extern u8 gUnk_08364AC8[];

extern void sub_08016E10(u32 src, u32 dest, u32 control);
extern void sub_08016E30(void);
extern u32 sub_08016558(u32 idx);
extern void sub_08006950(u8 *p, u32 a1, u8 a2);
extern void sub_08011C9C(u8 a, u16 *dst);
extern void sub_08004238(u32 a, u32 b);
extern void sub_0800DFCC(void);
extern void sub_0800048C(void);
extern void sub_0800EA64(void *a1);
extern void sub_0800EEFC(u8 *a1, u32 a2, void *a3, u32 a4, u32 a5);
extern u32 sub_0800EAA0(void *a1);
extern u32 sub_0800EFC0(u8 *ptr);
extern void sub_0800E008(void);

u32 sub_0800E200(void)
{
    u8 work[0x24C];
    u32 len;
    u8 flag[4];
    register u32 icon __asm__("r9");
    register u8 *start __asm__("r10");
    register u8 *a __asm__("r7");
    register u8 one __asm__("r8");
    register u32 x __asm__("r4");
    register u32 y __asm__("r5");
    register u32 i __asm__("r6");

    *(u32 *)flag = 0;
    icon = 0;
    *(volatile u16 *)0x0400000E = 0x1C0C;
    {
        u8 *src = gUnk_0833338C;
        sub_08016E10((u32)src, 0x0600C000, 0x80 << 5);
    }
    {
        u8 *buf = work + 0x4C;
        sub_08011C9C(4, (u16 *)buf);
        sub_0800DFCC();
        sub_08004238((u32)buf, 0x0F);
    }
    start = gUnk_08363EE8;
    len = (u32)gUnk_08364AC8 - (u32)start;
    *(u32 *)(work + 0x28) = (u32)start;
    work[0x4B] = flag[0];
    sub_0800EA64(work);
loop:
    {
        sub_08016E30();
        sub_08006950((u8 *)sub_08016558(0x53), 8, 1);
        i = 1;
        a = work;
        one = i;
        y = 9;
        x = 0x54;
        do {
            if (((a[0x1D] >> i) & one) == 0)
                goto show0;
            __asm__ volatile ("" : : : "r2");
            if (((a[0x1E] >> i) & one) != 0)
                goto show1;
show0:
            sub_08006950((u8 *)sub_08016558(x), y, 0);
            goto pnext;
show1:
            sub_08006950((u8 *)sub_08016558(x), y, 1);
pnext:
            ;
            y = y + 1;
            x = x + 1;
            i = i + 1;
        } while (i <= 3);
        if (work[0x1E] & 0x0E)
        {
            if (work[0x18] == 0)
                icon = 0x0F;
            else if (work[0x18] != 0xD1)
                icon = 0;
            if (work[0x18] > 0xDF)
                icon = 0x58;
        }
        else
        {
            icon = 0;
        }
        if (icon != 0)
        {
            sub_08006950((u8 *)sub_08016558(icon), 0x0E, 1);
        }
        else
        {
            sub_08006950(gUnk_0807CA60, 0x0E, 1);
        }
        sub_0800048C();
        if (gKeysPressed & 8)
        {
            if (work[0x18] == 0 && work[0x1E] != 0)
            {
                sub_0800EEFC(work, 1, start + 0xC0, len - 0xC0, 4);
                *(u32 *)flag = 1;
            }
        }
        if (sub_0800EAA0(work) != 0 && *(u32 *)flag == 1)
            return 1;
        if (sub_0800EFC0(work) != 0)
        {
            sub_0800DFCC();
            sub_0800E008();
            return 0;
        }
        if ((gKeysPressed & 2) == 0 || *(u32 *)flag == 1)
            goto loop;
    }
    return 1;
}
