#include "global.h"

extern u32 gUnk_083FDE18;
extern void sub_08006734(u32 a);
extern u32 sub_08016558(u16 idx);
extern void sub_080065A8(void);
extern void sub_08006950(u32 a, u32 b, u32 c);

void sub_08014614(u32 a)
{
    u8 i;

    sub_08006734(gUnk_083FDE18);
    sub_08016558(0xA4);
    sub_080065A8();
    i = 0;
    do {
        sub_08006950(sub_08016558(i + 0xA5), i * 2 + 6, a == i);
        i++;
    } while (i != 4);
}
