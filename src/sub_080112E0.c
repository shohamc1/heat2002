#include "global.h"

extern u8 gUnk_020020AC;
extern u32 gUnk_0202EFC0[];
extern u8 gUnk_0202A550[][0x190];

void sub_080112E0(void)
{
    u8 i;
    u32 swapped;
    register u8 *countTemp asm("r2");
    register u8 *count asm("r10");
    register u32 *base asm("r9");

    i = 0;
    countTemp = &gUnk_020020AC;
    count = countTemp;
    base = gUnk_0202EFC0;
    {
        register u8 n asm("r1") = *countTemp;
        if (i != n) {
            register u32 *dst asm("r4") = base;
            register u8 current asm("r0");
            do {
                register u32 *slot asm("r0") = (u32 *)(((u32)i << 2) + (u32)dst);
                *slot = (u32)&gUnk_0202A550[i][0];
                i++;
                current = *countTemp;
            } while (i != current);
        }
    }

    do {
        register u32 *p asm("r6") = base;
        i = 0;
        swapped = 0;
        {
            register u8 *guard asm("r1") = count;
            if (*guard != 1) {
                register u32 half asm("r2") = 0xB6;
                register u32 off asm("ip");
                register u8 *innerCount asm("r8");
                register u8 *loopCount asm("r2");
                asm volatile("" : "+r"(half));
                off = half << 1;
                innerCount = count;
                do {
                    u32 a = p[0];
                    u32 b = p[1];
                    if (*(u32 *)(a + off) > *(u32 *)(b + off)) {
                        p[0] = b;
                        p[1] = a;
                        swapped = 1;
                    }
                    p++;
                    i++;
                    loopCount = innerCount;
                } while (i != (u32)*loopCount - 1);
            }
        }
    } while (swapped);
}
