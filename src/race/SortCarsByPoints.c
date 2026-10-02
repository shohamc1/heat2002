#include "global.h"
#include "functions.h"
#include "car.h"
#include "variables.h"

void SortCarsByPoints(void)
{
    u8 i;
    u8 swapped;
    struct Car **p;
    struct Car *a;
    struct Car *b;
    u32 off;

    i = 0;
    do {
        (gCarOrder)[i] = &gCars[i];
        i++;
    } while (i != 24);
outer:
    swapped = 0;
    p = gCarOrder;
    i = 0;
    off = OFFSETOF(struct Car, points);
    do {
        a = p[0];
        b = p[1];
        if (*(u16 *)((u8 *)a + off) < *(u16 *)((u8 *)b + off)) {
            p[0] = b;
            p[1] = a;
            swapped = 1;
        }
        p++;
        i++;
    } while (i != 23);
    if (swapped != 0)
        goto outer;
}
