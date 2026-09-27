#include "global.h"
#include "variables.h"
#include "car.h"

extern s32 gUnk_0202521C;

void sub_0800A474(struct Car *p);

void sub_0800A478(struct Car *p)
{
    p->damage = 0;
    p->unk7C = 2;
    p->unk80 = 1;
    p->unk160 = 0;
    p->unkA2 = 0;
    sub_0800A474(p);
    if (p == gCars && gUnk_0200215C[0] == 0)
    {
        gUnk_0202521C += 5;
        if (gUnk_0202521C > 0x63)
            gUnk_0202521C = 0x63;
    }
}
