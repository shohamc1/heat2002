#include "global.h"

extern u8 gUnk_0203916C[];
extern u8 gUnk_0202713E[];
extern u8 gUnk_0202714A[];
extern u8 gUnk_02027154[];

void sub_08340504(u32 a)
{
    *(vu8 *)&gUnk_0203916C[0]; /* deliberate volatile read: keeps the load in the output */
    *(u32 *)(a + 0xE4) = (u32)gUnk_0202713E;
    *(u32 *)(a + 0xE8) = (u32)gUnk_0202714A;
    *(u32 *)(a + 0xEC) = (u32)gUnk_02027154;
}
