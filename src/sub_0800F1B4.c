#include "global.h"

extern const u8 gUnk_0829EED8[];
extern const u8 gUnk_0829EEE4[];
extern const u8 gUnk_0829EEF8[];

void MessageBox(u32, u32, u32);

void sub_0800F1B4(void)
{
    MessageBox((u32)gUnk_0829EED8, (u32)gUnk_0829EEE4, (u32)gUnk_0829EEF8);
}
