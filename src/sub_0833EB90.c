#include "global.h"

struct UnkCar3EB90 {
    /* 0x000 */ u8 filler00[0x2C];
    /* 0x02C */ s32 unk2C;
    /* 0x030 */ u8 filler30[0x4C - 0x30];
    /* 0x04C */ s8 unk4C;
    /* 0x04D */ u8 filler4D[0x9C - 0x4D];
    /* 0x09C */ u32 unk9C;
    /* 0x0A0 */ u8 fillerA0[0x150 - 0x0A0];
    /* 0x150 */ u8 unk150;
    /* 0x151 */ u8 filler151[0x18E - 0x151];
    /* 0x18E */ u8 unk18E;
    /* 0x18F */ u8 filler18F[400 - 0x18F];
};

extern u8 gUnk_020390EC;
extern u8 gUnk_0203E1B0;
extern struct UnkCar3EB90 gUnk_0203D520[];
extern u32 gUnk_020251B8[];
extern u16 gUnk_0203B6C8[];
extern u16 gUnk_0203B6A8[];
extern u16 gUnk_0203B858[];
extern u8 gUnk_0203916C[];
extern u8 gUnk_0203E1E0[];
extern u16 gUnk_0203B810[];
extern u8 gUnk_020390DC;
extern u16 gUnk_0203B6B0[];
extern u16 gUnk_0203B830[];
extern u8 gUnk_02039194;

void sub_0833E1F4(void);
void sub_0833DDB8(u16 *dest, s32 a, s32 b, s32 c);
void sub_0833E528(u32 a1);
void sub_0833E714(s32 arg);
void sub_0833E7FC(s32 a, s32 b);
void sub_0833E5EC(s32 arg);
void sub_0833E94C(struct UnkCar3EB90 *p);
void sub_0833E59C(struct UnkCar3EB90 *p);
void sub_0833E5E8(struct UnkCar3EB90 *p);
void sub_0833D9EC(struct UnkCar3EB90 *p);

void sub_0833EB90(void)
{
    struct UnkCar3EB90 *car;
    u16 *dest;
    s32 v;

    if (gUnk_020390EC != 0)
        car = &gUnk_0203D520[gUnk_0203E1B0];
    else
        car = &gUnk_0203D520[0];
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
    v = -car->unk2C >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    sub_0833E528(v);
    if (gUnk_0203916C[0] != 2 && gUnk_0203916C[0] != 0x0E) {
        sub_0833E714(car->unk150 + 1);
        if (car->unk18E != 0 || (u8)(gUnk_0203916C[0] - 3) <= 1)
            sub_0833E7FC(car->unk4C + 1, gUnk_02039194);
        else
            sub_0833E7FC(999, gUnk_02039194);
        sub_0833E5EC(car->unk9C << 8);
        sub_0833E94C(car);
        sub_0833E59C(car);
        sub_0833E5E8(car);
    }
    sub_0833D9EC(car);
}
