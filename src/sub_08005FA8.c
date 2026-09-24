#include "global.h"

struct Car08005FA8 {
    u8 pad00[0x2C];
    s32 unk2C;
    u8 pad30[0x9C - 0x30];
    s32 unk9C;
    u8 padA0[0x190 - 0xA0];
};

extern u32 gUnk_08364B08[];
extern u16 gUnk_02025218;
extern u16 gUnk_020251FC;
extern u16 gUnk_020253CC;
extern u8 gUnk_0202F030;
extern u16 gUnk_02025380[];
extern u8 gUnk_020020CC;
extern u16 gUnk_02025200[];
extern u16 gUnk_020253A0[];
extern u8 gUnk_020020DC;
extern u8 gUnk_0202EF90;
extern struct Car08005FA8 gUnk_0202A550[];

void sub_080056F8(void);
void sub_08005338(u32 a, u16 b, u16 c, u16 d);
void sub_08005A2C(u32 a);
void sub_08005AF0(s32 a);
void sub_08005E50(void *a);
void sub_08005AA0(void *a);
void sub_08005AEC(void *a);
void sub_08004980(void *a);

void sub_08005FA8(void)
{
    u32 base;
    u32 obj;
    struct Car08005FA8 *car;
    s32 v;

    sub_080056F8();
    base = gUnk_08364B08[0];
    obj = base + 0x448;
    sub_08005338(obj, gUnk_02025218, gUnk_020251FC, gUnk_020253CC);
    obj = base + 0x488;
    if (gUnk_0202F030 != 0)
        sub_08005338(obj, gUnk_02025380[gUnk_020020CC], gUnk_02025200[gUnk_020020CC], gUnk_020253A0[gUnk_020020CC]);
    if (gUnk_020020DC != 0)
        car = &gUnk_0202A550[gUnk_0202EF90];
    else
        car = gUnk_0202A550;
    v = -car->unk2C >> 13;
    v = v * 3 / 2;
    if (v < 0)
        v = 0;
    sub_08005A2C(v);
    sub_08005AF0(car->unk9C << 8);
    sub_08005E50(car);
    sub_08005AA0(car);
    sub_08005AEC(car);
    sub_08004980(car);
}
