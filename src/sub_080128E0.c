#include "global.h"

struct Unk0202A550
{
    u8 filler0[0x7D];
    u8 unk7D;
    u8 filler7E[0x16C - 0x7E];
    u32 unk16C;
    u8 filler170[400 - 0x170];
};

extern u8 gUnk_02002184;
extern u32 gUnk_0202ED84;
extern u32 gUnk_083FDD48[];
extern u8 gUnk_0202EDD8;
extern u8 gUnk_020020CC;
extern u8 gUnk_083FDD34[];
extern u8 gUnk_0202EEE4;
extern struct Unk0202A550 gUnk_0202A550[];
extern u8 gUnk_0202CDA8[];
extern u8 gUnk_0202EF00[];

extern void sub_08008A20(void);
extern void sub_08016D28(u8 a);
extern void sub_0800F3C0(void);
extern void sub_08011168(u8 a, u8 b);
extern u8 sub_0800295C(u8 a, u8 b, void *c);
extern void sub_08001208(u16 a);
extern void sub_08015304(void);
extern void sub_08012874(u8 a);

u8 sub_080128E0(void)
{
    gUnk_02002184 = 2;
    gUnk_0202ED84 = gUnk_083FDD48[gUnk_0202EDD8];
    gUnk_020020CC = gUnk_083FDD34[gUnk_0202EDD8];
    gUnk_0202EEE4 = 0;
    gUnk_0202A550[0].unk16C = 0;
    gUnk_0202A550[0].unk7D = 1;
    sub_08008A20();
    sub_08016D28(1);
    sub_0800F3C0();
    sub_08011168(0, gUnk_020020CC);
    sub_0800295C(0, 0x0D, gUnk_0202CDA8);
    if (gUnk_0202EF00[2] != 0)
        sub_08001208(3);
    sub_08015304();
    sub_08012874(gUnk_0202EEE4);
    return gUnk_0202EEE4;
}
