#include "global.h"
#include "functions.h"
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
    do {
        (gCarOrder)[i] = &gCars[i];
        i++;
    } while (i != 24);
    /* A goto keeps the field-offset setup inside each sort pass. */
outer:
    {
        swapped = 0;
        p = gCarOrder;
        i = 0;
        do {
            a = p[0];
            b = p[1];
            if (a->finishTime > b->finishTime) {
                p[0] = b;
                p[1] = a;
                swapped = 1;
            }
            p++;
            i++;
        } while (i != 23);
    }
    if (swapped != 0)
        goto outer;
}
