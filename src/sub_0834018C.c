#include "global.h"
#include "car.h"

extern u8 gUnk_02026DF4[];

void sub_083415B0(u8 idx);
u32 sub_08340168(u32 ptr);

void sub_0834018C(struct Car *a1, u32 a2)
{
    u8 i;
    u8 flag;
    s32 t;

    sub_083415B0((u8)a2);
    t = sub_08340168((u32)a1);
    a1->points = a1->points + gUnk_02026DF4[(u8)t];
    if (a1->unk168 != 0)
        a1->points += 5;
    flag = 1;
    for (i = 0; i != 5; i++) {
        if (a1 == &gModule_Cars[i])
            continue;
        if (gModule_Cars[i].unk168 <= a1->unk168)
            continue;
        flag = 0;
    }
    if (flag != 0)
        a1->points += 10;
}
