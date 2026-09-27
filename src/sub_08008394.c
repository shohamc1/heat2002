#include "global.h"
#include "data.h"
#include "variables.h"


void sub_08008394(u32 a)
{
    *(vu8 *)&gGameMode[0]; /* deliberate volatile read: keeps the load in the output */
    *(u32 *)(a + 0xE4) = (u32)gUnk_08367BFA;
    *(u32 *)(a + 0xE8) = (u32)gUnk_08367C06;
    *(u32 *)(a + 0xEC) = (u32)gUnk_08367C10;
}
