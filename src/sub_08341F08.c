#include "global.h"
#include "variables.h"
#include "car.h"

extern s32 gUnk_0203B6CC;

void sub_08341F04(struct Car *p);

void sub_08341F08(struct Car *p)
{
    (*(u32 *)&p->damage) = 0;
    p->unk7C = 2;
    p->unk80 = 1;
    p->unk160 = 0;
    p->unkA2 = 0;
    sub_08341F04(p);
    if (p == gModule_Cars && gUnk_0203916C[0] == 0)
    {
        gUnk_0203B6CC += 5;
        if (gUnk_0203B6CC > 0x63)
            gUnk_0203B6CC = 0x63;
    }
}
