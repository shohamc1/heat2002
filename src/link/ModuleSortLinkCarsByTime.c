#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

void ModuleSortLinkCarsByTime(void)
{
    u8 i;
    u32 swapped;
    register u8 *countTemp PIN(r2);
    register u8 *count PIN(r10);
    register struct Car **base PIN(r9);

    i = 0;
    countTemp = &gModule_NumLinkPlayers[0];
    count = countTemp;
    base = gModule_CarOrder;
    {
        register u8 n PIN(r1) = *countTemp;
        if (i != n) {
            register struct Car **dst PIN(r4) = base;
            register u8 current PIN(r0);
            do {
                register struct Car **slot PIN(r0) = (struct Car **)(((u32)i << 2) + (u32)dst);
                *slot = &gModule_Cars[i];
                i++;
                current = *countTemp;
            } while (i != current);
        }
    }

    do {
        register struct Car **p PIN(r6) = base;
        i = 0;
        swapped = 0;
        {
            register u8 *guard PIN(r1) = count;
            if (*guard != 1) {
                register u32 half PIN(r2) = 0xB6;
                register u32 off PIN(ip);
                register u8 *innerCount PIN(r8);
                register u8 *loopCount PIN(r2);
                asm volatile("" : "+r"(half));
                off = half << 1; /* offsetof(struct Car, finishTime) */
                innerCount = count;
                do {
                    struct Car *a = p[0];
                    struct Car *b = p[1];
                    if (*(u32 *)((u8 *)a + off) > *(u32 *)((u8 *)b + off)) {
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
