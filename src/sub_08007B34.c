#include "global.h"

struct UnkCar {
    /* 0x000 */ u8 filler000[0x164];
    /* 0x164 */ u16 unk164;
    /* 0x166 */ u8 filler166[0x168 - 0x166];
    /* 0x168 */ u8 unk168;
    /* 0x169 */ u8 filler169[400 - 0x169];
};

extern struct UnkCar gUnk_0202A550[];
extern u8 gUnk_08367620[];

void sub_08009B20(u8 idx);
u32 sub_08007B10(u32 ptr);

void sub_08007B34(struct UnkCar *a1, u32 a2)
{
    u8 i;
    u8 flag;
    s32 t;

    sub_08009B20((u8)a2);
    t = sub_08007B10((u32)a1);
    a1->unk164 = a1->unk164 + gUnk_08367620[(u8)t];
    if (a1->unk168 != 0)
        a1->unk164 += 5;
    flag = 1;
    for (i = 0; i != 24; i++) {
        if (a1 == &gUnk_0202A550[i])
            continue;
        if (gUnk_0202A550[i].unk168 <= a1->unk168)
            continue;
        flag = 0;
    }
    if (flag != 0)
        a1->unk164 += 10;
}
