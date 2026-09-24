#include "global.h"

extern u32 gUnk_0829EF08[];
extern u32 gUnk_0829EF18[];
extern u32 gUnk_0829EF2C[];

void MessageBox(u32 a, u32 b, u32 c);

void sub_0800F1D0(void)
{
    MessageBox((u32)gUnk_0829EF08, (u32)gUnk_0829EF18, (u32)gUnk_0829EF2C);
}
