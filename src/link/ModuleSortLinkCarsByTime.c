#include "global.h"
#include "variables.h"
#include "car.h"


void ModuleSortLinkCarsByTime(void)
{
    u8 i;
    u32 swapped;
    register u8 *countTemp asm("r2");
    register u8 *count asm("r10");
    register u32 *base asm("r9");

    i = 0;
    countTemp = &gModule_NumLinkPlayers[0];
    count = countTemp;
    base = gUnk_02039200;
    {
        register u8 n asm("r1") = *countTemp;
        if (i != n) {
            register u32 *dst asm("r4") = base;
            register u8 current asm("r0");
            do {
                register u32 *slot asm("r0") = (u32 *)(((u32)i << 2) + (u32)dst);
                    *slot = (u32)&((u8 (*)[0x190])gModule_Cars)[i][0];
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
                    u32 carA = p[0];
                    u32 carB = p[1];
                    if (*(u32 *)(carA + off) > *(u32 *)(carB + off)) {
                        p[0] = carB;
                        p[1] = carA;
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
