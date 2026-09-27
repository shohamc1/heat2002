#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u16 gUnk_02026DC4[];
extern u16 gUnk_02026DDC[];

void sub_083425C4(struct Car *p, u8 idx);
u8 sub_08340028(struct Car *p);
u8 sub_08340004(u8 a);
void sub_08341280(struct Car *p, u8 a);

void sub_083426C8(void)
{
    struct Car *p;
    u8 count;
    s32 i;
    u16 *t;
    u8 v;

    sub_08339B4C();
    p = gModule_Cars;
    count = gUnk_020390A0[0];
    if (gUnk_020390EC != 0 || gUnk_0203916C[0] == 4)
        count = gUnk_020390BC[0];
    if (gUnk_0203916C[0] == 2)
        count = 1;
    gUnk_0203D4E8++;
    for (i = 0; i != count; i++) {
        sub_083425C4(p, i);
        if (p->unk18C <= gUnk_02026DC4[gUnk_020390DC]
            && (*(u32 *)&p->progress & 0xFFFF) >= gUnk_02026DC4[gUnk_020390DC] && sub_08340028(p) != 0
            && p != gModule_Cars) {
            v = gUnk_0203E0E0;
            if (v != 0) {
                v = sub_08340004(v);
                if (v != 0x63)
                    sub_08341280(p, sub_08340004(v));
            }
        }
        if (p != gModule_Cars && p->pitState != 0) {
            if (p->unk18C <= gUnk_02026DDC[gUnk_020390DC]
                && (*(u32 *)&p->progress & 0xFFFF) >= gUnk_02026DDC[gUnk_020390DC])
                p->unk18F = 0;
        }
        p++;
    }
}
