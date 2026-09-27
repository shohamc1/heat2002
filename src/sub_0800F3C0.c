#include "global.h"
#include "car.h"
#include "variables.h"


void SortCarsByTime(void)
{
    u8 i;
    struct Car **p;
    struct Car *a;
    struct Car *b;
    u32 swapped;

    i = 0;
    do
    {
        ((struct Car **)gCarOrder)[i] = &gCars[i];
        i++;
    } while (i != 0x18);
    /* A goto keeps the field-offset setup inside each sort pass. */
outer:
    {
        swapped = 0;
        p = (struct Car **)gCarOrder;
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
        } while (i != 0x17);
    }
    if (swapped != 0) goto outer;
}
