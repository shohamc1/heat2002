#include "global.h"

struct UnkCar {
    /* 0x000 */ u8 filler000[0x164];
    /* 0x164 */ u16 unk164;
    /* 0x166 */ u8 filler166[0x168 - 0x166];
    /* 0x168 */ u8 unk168;
    /* 0x169 */ u8 filler169[400 - 0x169];
};

extern struct UnkCar gUnk_0203D520[];
extern u8 gUnk_02026DF4[];

void sub_083415B0(u8 idx);
u32 sub_08340168(u32 ptr);

void sub_0834018C(struct UnkCar *a1, u32 a2)
{
    u8 i;
    u8 flag;
    s32 t;

    sub_083415B0((u8)a2);
    t = sub_08340168((u32)a1);
    a1->unk164 = a1->unk164 + gUnk_02026DF4[(u8)t];
    if (a1->unk168 != 0)
        a1->unk164 += 5;
    flag = 1;
    for (i = 0; i != 5; i++) {
        if (a1 == &gUnk_0203D520[i])
            continue;
        if (gUnk_0203D520[i].unk168 <= a1->unk168)
            continue;
        flag = 0;
    }
    if (flag != 0)
        a1->unk164 += 10;
}
