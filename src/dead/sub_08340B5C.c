#include "global.h"
#include "functions.h"
#include "car.h"

s32 sub_08340B5C(s32 a, s32 b)
{
    s32 sign = 0;
    s32 offs = 0;

    if (a < 0)
    {
        a = -a;
        sign = 1;
        offs = 0x80;
    }
    if (b < 0)
    {
        b = -b;
        sign ^= 1;
    }
    {
        s32 r = (b << 6) / (a + b);

        if (sign != 0)
            r = -r;
        return offs + r;
    }
}

void sub_08340B90(void)
{
    u32 i;
    u8 v;
    u8 dup;
    u8 j;

    for (i = 1; i != 0x5; i++)
        gModule_Cars[i].driverId = 99;
    i = 1;
    for (;;)
    {
        v = 0x1F & sub_0833BCBC();
        if (v > 0x1D)
            continue;
        dup = 0;
        j = 0;
        do
        {
            if (v == gModule_Cars[j].driverId)
                dup = 1;
            j++;
        } while (j != 0x5);
        if (dup != 0)
            continue;
        gModule_Cars[i].driverId = v;
        i++;
        if (i == 0x5)
            break;
    }
}

void sub_08340C20(void)
{
    u8 v;
    u32 i;
    u8 dup;
    u8 j;

    for (i = 1; i != 0x5; i++)
    {
        if (gModule_Cars[i].driverId != 99)
            continue;
        for (;;)
        {
            v = 0x1F & sub_0833BCBC();
            if (v > 0x1D)
                continue;
            dup = 0;
            j = 0;
            do
            {
                if (v == gModule_Cars[j].driverId)
                    dup = 1;
                j++;
            } while (j != 0x5);
            if (dup != 0)
                continue;
            break;
        }
        gModule_Cars[i].driverId = v;
    }
}
