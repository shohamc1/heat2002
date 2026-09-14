#include "global.h"

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

extern struct Car gUnk_0202A550[];
extern u8 gUnk_02002090;
extern u8 gUnk_020020DC;
extern u8 gUnk_0200215C;
extern u8 gUnk_020020AC;
extern u8 gUnk_0202A51C;
extern u8 gUnk_020020CC;
extern u8 gUnk_0202EEB0;
extern u16 gUnk_083675F0[];
extern u16 gUnk_08367608[];

void sub_0800048C(void);
void sub_0800AB78(struct Car *p, u8 idx);
u8 sub_080079D0(struct Car *p);
u8 sub_080079AC(u8 a);
void sub_0800930C(struct Car *p, u8 a);

void sub_0800AD80(void)
{
    struct Car *p;
    u8 count;
    s32 i;
    u16 *t;
    u8 v;

    sub_0800048C();
    p = gUnk_0202A550;
    count = gUnk_02002090;
    if (gUnk_020020DC != 0 || gUnk_0200215C == 4)
        count = gUnk_020020AC;
    if (gUnk_0200215C == 2)
        count = 1;
    gUnk_0202A51C++;
    for (i = 0; i != count; i++) {
        sub_0800AB78(p, i);
        if (p->unk18C <= gUnk_083675F0[gUnk_020020CC]
            && (p->unk50 & 0xFFFF) >= gUnk_083675F0[gUnk_020020CC] && sub_080079D0(p) != 0
            && p != gUnk_0202A550) {
            v = gUnk_0202EEB0;
            if (v != 0) {
                v = sub_080079AC(v);
                if (v != 0x63)
                    sub_0800930C(p, sub_080079AC(v));
            }
        }
        if (p != gUnk_0202A550 && p->unk175 != 0) {
            if (p->unk18C <= gUnk_08367608[gUnk_020020CC]
                && (p->unk50 & 0xFFFF) >= gUnk_08367608[gUnk_020020CC])
                p->unk18F = 0;
        }
        p++;
    }
}
