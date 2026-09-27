#include "global.h"
#include "functions.h"

struct Car {
    u8 pad00[0x50];
    u32 unk50;
    u8 pad54[0x175 - 0x54];
    u8 unk175;
    u8 pad176[0x18C - 0x176];
    u16 unk18C;
    u8 pad18E[0x18F - 0x18E];
    u8 unk18F;
};

extern struct Car gUnk_0203D520[];
extern u8 gUnk_020390A0[];
extern u8 gUnk_020390EC;
extern u8 gUnk_0203916C[];
extern u8 gUnk_020390BC[];
extern u8 gUnk_0203D4E8;
extern u8 gUnk_0203E0E0;
extern u16 gUnk_02026DC4[];
extern u16 gUnk_02026DDC[];
extern u8 gUnk_020390DC;

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
    p = gUnk_0203D520;
    count = gUnk_020390A0[0];
    if (gUnk_020390EC != 0 || gUnk_0203916C[0] == 4)
        count = gUnk_020390BC[0];
    if (gUnk_0203916C[0] == 2)
        count = 1;
    gUnk_0203D4E8++;
    for (i = 0; i != count; i++) {
        sub_083425C4(p, i);
        if (p->unk18C <= gUnk_02026DC4[gUnk_020390DC]
            && (p->unk50 & 0xFFFF) >= gUnk_02026DC4[gUnk_020390DC] && sub_08340028(p) != 0
            && p != gUnk_0203D520) {
            v = gUnk_0203E0E0;
            if (v != 0) {
                v = sub_08340004(v);
                if (v != 0x63)
                    sub_08341280(p, sub_08340004(v));
            }
        }
        if (p != gUnk_0203D520 && p->unk175 != 0) {
            if (p->unk18C <= gUnk_02026DDC[gUnk_020390DC]
                && (p->unk50 & 0xFFFF) >= gUnk_02026DDC[gUnk_020390DC])
                p->unk18F = 0;
        }
        p++;
    }
}
