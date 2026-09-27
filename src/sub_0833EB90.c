#include "global.h"
#include "variables.h"
#include "car.h"


void sub_0833E1F4(void);
void sub_0833DDB8(u16 *dest, s32 a, s32 b, s32 c);
void sub_0833E528(u32 a1);
void sub_0833E714(s32 arg);
void sub_0833E7FC(s32 a, s32 b);
void sub_0833E5EC(s32 arg);
void sub_0833E94C(struct Car *p);
void sub_0833E59C(struct Car *p);
void sub_0833E5E8(struct Car *p);
void sub_0833D9EC(struct Car *p);

void sub_0833EB90(void)
{
    struct Car *car;
    u16 *dest;
    s32 v;

    if (gUnk_020390EC != 0)
        car = &gModule_Cars[gUnk_0203E1B0];
    else
        car = &gModule_Cars[0];
    sub_0833E1F4();
    dest = (u16 *)(gUnk_020251B8[0] + 0x4C6);
    sub_0833DDB8(dest, gUnk_0203B6C8[0], gUnk_0203B6A8[0], gUnk_0203B858[0]);
    if (gUnk_0203916C[0] == 0x0E || gUnk_0203916C[0] == 0x02) {
        dest = (u16 *)(gUnk_020251B8[0] + 0x486);
        if (gUnk_0203E1E0[0] != 0)
            sub_0833DDB8(dest,
                         gUnk_0203B810[gUnk_020390DC],
                         gUnk_0203B6B0[gUnk_020390DC],
                         gUnk_0203B830[gUnk_020390DC]);
    }
    v = -car->speed >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    sub_0833E528(v);
    if (gUnk_0203916C[0] != 2 && gUnk_0203916C[0] != 0x0E) {
        sub_0833E714(car->racePosition + 1);
        if (car->unk18E != 0 || (u8)(gUnk_0203916C[0] - 3) <= 1)
            sub_0833E7FC((*(s8 *)&car->lap) + 1, gUnk_02039194);
        else
            sub_0833E7FC(999, gUnk_02039194);
        sub_0833E5EC((*(u32 *)&car->fuel) << 8);
        sub_0833E94C(car);
        sub_0833E59C(car);
        sub_0833E5E8(car);
    }
    sub_0833D9EC(car);
}
