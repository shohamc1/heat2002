#include "global.h"
#include "gba/io_reg.h"

extern void sub_0800EA64(void *a1);
extern s32 sub_0800EE8C(void *a1, u16 a2);
extern void sub_0800EED8(void *a1);
extern u32 sub_0800EFC0(u8 *ptr);
extern u32 sub_0800EFD0(u8 *a1);
extern void sub_0800F0D4(void);
extern u32 sub_08016E20(void *a1);
extern u16 gUnk_0200048C[];

s32 sub_0800EAA0(u8 *a)
{
    u8 *p4a;
    u8 *p49;
    u8 *p19;
    u8 *p;
    u16 *q;
    s32 keys;
    s32 v;
    s32 t;
    s32 i;
    s32 j;
    s32 mask;
    s32 ok;
    s32 sum;
    s32 x;
    s32 c1;
    s32 r;

    if (sub_0800EFC0(a) != 0)
        return 0;
    p4a = a;
    p4a += 0x4A;
    if (*p4a > 0xF)
    {
        *p4a = *p4a - 1;
        return 0;
    }
retry48:
    p = a;
    p += 0x48;
    if (*p != 0)
    {
        *p = 0;
        v = *(volatile u16 *)0x04000128 & 0xFC;
        if (v != 8)
        {
            sub_0800EA64(a);
            return 8 ^ v;
        }
    }
    if (a[0x18] > 0xDF)
    {
        r = sub_0800EFD0(a);
        if (r != 0)
            return r;
        if (a[0x4B] == 1 && a[0x18] > 0xE1 && sub_0800EFC0(a) == 0)
        {
            sub_0800F0D4();
            goto retry48;
        }
        if (sub_0800EFC0(a) != 0)
            return 0;
        if (*(u16 *)(a + 0x16) == 0)
        {
            sub_0800EA64(a);
            return 0x71;
        }
        *(u16 *)(a + 0x16) = *(u16 *)(a + 0x16) - 1;
        return 0;
    }

    switch (a[0x18])
    {
    case 2:
        i = 3;
        p49 = a + 0x49;
        do
        {
            v = *p49;
            t = (v >> i) & 1;
            j = i - 1;
            if (t != 0)
            {
                if ((s32)((volatile u16 *)0x04000120)[i] != (s32)gUnk_0200048C[j])
                {
                    v ^= 1 << i;
                    *p49 = v;
                }
            }
            i = j;
        }
        while (i != 0);
        goto all_ok;
    case 0:
        mask = 0xE;
        i = 3;
        keys = a[0x1E];
        v = ((volatile u16 *)0x04000120)[3];
        if (v == 0xFFFF)
        {
            q = (u16 *)0x04000126;
            do
            {
                mask >>= 1;
                q--;
                i--;
            }
            while (i != 0 && *q == v);
        }
        mask &= 0xE;
        a[0x1D] = mask;
        i = 3;
        v = ((volatile u16 *)0x04000120)[3];
        while (1)
        {
            if ((keys >> i) & 1)
            {
                if (v != ((1 << i) | 0x7200))
                {
                    mask = 0;
                    break;
                }
            }
            i--;
            if (i == 0)
                break;
            v = ((volatile u16 *)0x04000120)[i];
        }
        a[0x1E] = mask & keys;
        if (mask == 0)
            *p4a = 0xF;
        if (*p4a != 0)
            *p4a = *p4a - 1;
        else if (a[0x1D] != a[0x1E])
        {
            sub_0800EED8(a);
            goto case1;
        }
        return sub_0800EE8C(a, a[0x1E] | 0x6200);
    case1:
    case 1:
        a[0x49] = 0;
        i = 3;
        do
        {
            x = ((volatile u16 *)0x04000120)[i];
            t = x >> 8;
            j = i - 1;
            if (t == 0x72)
            {
                gUnk_0200048C[j] = x;
                if ((x & 0xFF) == (1 << i))
                    a[0x49] = x | a[0x49];
            }
            i = j;
        }
        while (i != 0);
        p49 = a + 0x49;
        if (a[0x1D] != a[0x49])
            return sub_0800EE8C(a, a[0x1E] | 0x6200);
        a[0x18] = 2;
        return sub_0800EE8C(a, a[0x49] | 0x6100);
    case 0xD0:
        ok = 1;
        i = 3;
        p49 = a + 0x49;
        p19 = a + 0x19;
        do
        {
            x = ((volatile u16 *)0x04000120)[i];
            j = i - 1;
            p19[j] = x;
            t = a[0x49] >> i;
            if ((t & 1) != 0)
            {
                if ((u32)((x >> 8) - 0x72) <= 1)
                {
                    if (x != (s32)gUnk_0200048C[j])
                        ok = 0;
                }
                else
                {
                    sub_0800EA64(a);
                    return 0x60;
                }
            }
            i = j;
        }
        while (i != 0);
        if (ok != 0)
        {
            a[0x18] = 0xD1;
            sum = 0x11;
            i = 3;
            p = p19 + 2;
            do
            {
                sum += *p;
                p--;
                i--;
            }
            while (i != 0);
            a[0x14] = sum;
            return sub_0800EE8C(a, (sum & 0xFF) | 0x6400);
        }
        return sub_0800EE8C(a, a[0x1C] | 0x6300);
    case 0xD1:
        i = 3;
        p49 = a + 0x49;
        v = a[0x49];
        q = (u16 *)0x04000126;
        do
        {
            x = *q;
            if ((v >> i) & 1)
            {
                if (x >> 8 != 0x73)
                {
                    sub_0800EA64(a);
                    return 0x60;
                }
            }
            q--;
            i--;
        }
        while (i != 0);
        if (sub_08016E20(a) != 0)
        {
            sub_0800EA64(a);
            *p4a = 0x1E;
            return 0x70;
        }
        a[0x18] = 0xE0;
        a[0x16] = 0x190;
        return 0;
    default:
        i = 3;
        p49 = a + 0x49;
        do
        {
            v = *p49;
            t = (v >> i) & 1;
            if (t != 0)
            {
                x = ((volatile u16 *)0x04000120)[i];
                c1 = x >> 8;
                if (c1 != 0x62 - (a[0x18] >> 1)
                    || (x & 0xFF) != (1 << i))
                {
                    v ^= 1 << i;
                    *p49 = v;
                }
            }
            i--;
        }
        while (i != 0);
        if (a[0x18] == 0xC4)
        {
            a[0x1E] = *p49 & 0xE;
            a[0x18] = i;
            return sub_0800EE8C(a, a[0x1E] | 0x6200);
        }
all_ok:
        if (*p49 == 0)
        {
            sub_0800EA64(a);
            return 0x50;
        }
        a[0x18] = a[0x18] + 2;
        if (a[0x18] == 0xC4)
            return sub_0800EE8C(a, a[0x1E] | 0x6200);
        p = *(u8 **)(a + 0x28);
        p += a[0x18];
        r = sub_0800EE8C(a, (p[-3] << 8) | p[-4]);
        if (r != 0)
            return r;
        if (a[0x4B] != 1)
            return 0;
        sub_0800F0D4();
        goto retry48;
    }
}
