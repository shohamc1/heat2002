#include "global.h"

extern s32 sub_0800EE8C(void *a1, u16 a2);
extern void sub_0800EA64(void *a1);

u32 sub_0800EFD0(u8 *a1)
{
    u32 i;
    u8 keys;
    u32 v;

    switch (a1[0x18])
    {
    case 0xE0:
e0:
        {
            u16 z = 0;
            a1[0x18] = 0xE1;
            *(u32 *)(a1 + 4) = z;
            *(u32 *)(a1 + 0) = 0x80 << 13;
            return sub_0800EE8C(a1, z);
        }
    default:
        i = 3;
        keys = a1[0x1E];
        {
            u32 one = 1;
            volatile u16 *p = (volatile u16 *)0x04000126;
            do {
                v = *p;
                if (((keys >> i) & one) != 0 && v != *(u32 *)(a1 + 4))
                    goto e0;
                p = p - 1;
                i = i - 1;
            } while (i != 0);
        }
        a1[0x18] = a1[0x18] + 1;
        {
            u32 w = *(u32 *)(a1 + 0);
            *(u32 *)(a1 + 4) = *(u16 *)(a1 + 0);
            if (w == 0)
            {
                u8 *ptr = *(u8 **)(a1 + 0x28);
                u32 t = ptr[0xAC] | (ptr[0xAD] << 8);
                *(u32 *)(a1 + 4) = t;
                *(u32 *)(a1 + 0) = t << 5;
            }
        }
        *(u32 *)(a1 + 0) = *(u32 *)(a1 + 0) >> 5;
send:
        return sub_0800EE8C(a1, *(volatile u16 *)(a1 + 0));
    case 0xE7:
    case 0xE8:
        i = 3;
        keys = a1[0x1E];
        do {
            v = ((volatile u16 *)0x04000120)[i];
            if (((keys >> i) & 1) != 0 && v != *(u32 *)(a1 + 4))
            {
                sub_0800EA64(a1);
                return 0x71;
            }
            i = i - 1;
        } while (i != 0);
        a1[0x18] = a1[0x18] + 1;
        if (a1[0x18] == 0xE9)
            return 0;
        {
            u8 *ptr = *(u8 **)(a1 + 0x28);
            u32 t = ptr[0xAE] | (ptr[0xAF] << 8);
            *(u32 *)(a1 + 0) = t;
            *(u32 *)(a1 + 4) = t;
        }
        goto send;
    }
    return 0;
}
