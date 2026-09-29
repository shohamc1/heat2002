#include "global.h"
#include "variables.h"
#include "car.h"

void SortLinkCarsByTime(void)
{
    u8 i;
    u32 swapped;
    register u8 *countTemp asm("r2");
    register u8 *count asm("r10");
    register struct Car **base asm("r9");

    i = 0;
    countTemp = &gNumLinkPlayers[0];
    count = countTemp;
    base = gCarOrder;
    {
        register u8 n asm("r1") = *countTemp;
        if (i != n) {
            register struct Car **dst asm("r4") = base;
            register u8 current asm("r0");
            do {
                register struct Car **slot asm("r0") = (struct Car **)(((u32)i << 2) + (u32)dst);
                *slot = (struct Car *)&((u8(*)[0x190])gCars)[i][0];
                i++;
                current = *countTemp;
            } while (i != current);
        }
    }

    do {
        register struct Car **p asm("r6") = base;
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
                    struct Car *a = p[0];
                    struct Car *b = p[1];
                    if (*(u32 *)((u32)a + off) > *(u32 *)((u32)b + off)) {
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
