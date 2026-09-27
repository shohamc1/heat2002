#include "global.h"

struct Car0833EAA4 {
    u8 pad00[0x2C];
    s32 unk2C;
    u8 pad30[0x9C - 0x30];
    s32 unk9C;
    u8 padA0[0x190 - 0xA0];
};

extern u32 gUnk_020251B8[];
extern u16 gUnk_0203B6C8[];
extern u16 gUnk_0203B6A8[];
extern u16 gUnk_0203B858[];
extern u8 gUnk_0203E1E0[];
extern u16 gUnk_0203B810[];
extern u8 gUnk_020390DC;
extern u16 gUnk_0203B6B0[];
extern u16 gUnk_0203B830[];
extern u8 gUnk_020390EC;
extern u8 gUnk_0203E1B0;
extern struct Car0833EAA4 gUnk_0203D520[];

void sub_0833E1F4(void);
void sub_0833DDB8(u32 a, u16 b, u16 c, u16 d);
void sub_0833E528(u32 a);
void sub_0833E5EC(s32 a);
void sub_0833E94C(void *a);
void sub_0833E59C(void *a);
void sub_0833E5E8(void *a);
void sub_0833D9EC(void *a);

void sub_0833EAA4(void)
{
    u32 base;
    u32 obj;
    struct Car0833EAA4 *car;
    s32 v;

    sub_0833E1F4();
    base = gUnk_020251B8[0];
    obj = base + 0x448;
    sub_0833DDB8(obj, gUnk_0203B6C8[0], gUnk_0203B6A8[0], gUnk_0203B858[0]);
    obj = base + 0x488;
    if (gUnk_0203E1E0[0] != 0)
        sub_0833DDB8(obj, gUnk_0203B810[gUnk_020390DC], gUnk_0203B6B0[gUnk_020390DC], gUnk_0203B830[gUnk_020390DC]);
    if (gUnk_020390EC != 0)
        car = &gUnk_0203D520[gUnk_0203E1B0];
    else
        car = gUnk_0203D520;
    v = -car->unk2C >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    sub_0833E528(v);
    sub_0833E5EC(car->unk9C << 8);
    sub_0833E94C(car);
    sub_0833E59C(car);
    sub_0833E5E8(car);
    sub_0833D9EC(car);
}
