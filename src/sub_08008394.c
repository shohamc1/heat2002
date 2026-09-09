#include "global.h"

extern volatile u8 gUnk_0200215C[];
extern u8 gUnk_08367BFA[];
extern u8 gUnk_08367C06[];
extern u8 gUnk_08367C10[];

void sub_08008394(u32 a)
{
    gUnk_0200215C[0];
    *(u32 *)(a + 0xE4) = (u32)gUnk_08367BFA;
    *(u32 *)(a + 0xE8) = (u32)gUnk_08367C06;
    *(u32 *)(a + 0xEC) = (u32)gUnk_08367C10;
}
