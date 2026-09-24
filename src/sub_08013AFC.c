#include "global.h"

struct Unk0202A550 {
    u8 filler0[0x164];
    u16 points;
    u8 filler166[400 - 0x166];
};

extern struct Unk0202A550 *gCarOrder[];
extern struct Unk0202A550 gCars[];

void SortCarsByPoints(void)
{
    u8 i;
    u8 swapped;
    struct Unk0202A550 **p;
    struct Unk0202A550 *a;
    struct Unk0202A550 *b;
    u32 off;

    i = 0;
    do {
        gCarOrder[i] = &gCars[i];
        i++;
    } while (i != 0x18);
outer:
    swapped = 0;
    p = gCarOrder;
    i = 0;
    off = 0x164;
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
    } while (i != 0x17);
    if (swapped != 0)
        goto outer;
}
