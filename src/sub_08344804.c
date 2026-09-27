#include "global.h"
#include "car.h"
#include "variables.h"


void sub_08344804(void)
{
    u8 i;
    struct Car **p;
    struct Car *a;
    struct Car *b;
    u32 swapped;

    i = 0;
    do
    {
        ((struct Unk0202A550 **)gUnk_02039200)[i] = &gModule_Cars[i];
        i++;
    } while (i != 0x5);
    /* A goto keeps the field-offset setup inside each sort pass. */
outer:
    {
        swapped = 0;
        p = (struct Unk0202A550 **)gUnk_02039200;
        i = 0;
        do
        {
            a = p[0];
            b = p[1];
            if (a->unk16C > b->unk16C)
            {
                p[0] = b;
                p[1] = a;
                swapped = 1;
            }
            p++;
            i++;
        } while (i != 0x4);
    }
    if (swapped != 0) goto outer;
}
