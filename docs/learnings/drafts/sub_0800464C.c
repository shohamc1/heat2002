#include "global.h"

extern u32 gUnk_02024820;
extern u8 gUnk_02024824;
extern u32 gUnk_02024828;
extern u16 gUnk_02025160[];
extern u8 gUnk_02024C40[];

u32 sub_080045EC(void);

void sub_0800464C(void)
{
    u32 i;
    u32 p;
    u32 e;

    for (i = gUnk_02024824; i != 0x3F; i++) {
        p = gUnk_02024820;
        *(u16 *)(p + 8) = 0;
        *(s32 *)(p + 4) = -1;
        gUnk_02024820 = p + 0xC;
    }
    sub_080045EC();
    for (i = 0; i != gUnk_02024824; i++) {
        e = (u32)gUnk_02024C40 + gUnk_02025160[i] * 12;
        if (*(s32 *)(e + 4) != -1) {
            p = gUnk_02024828;
            *(u32 *)(p) = *(u32 *)(e);
            *(u32 *)(p + 4) = *(s32 *)(e + 4);
            gUnk_02024828 = p + 8;
        }
    }
}
