#include "global.h"

extern u8 gUnk_0202EF00[];
extern u8 gUnk_0202F1B8[];

void sub_08010074(void);
void sub_080165E0(u16 a, u16 b);
void sub_080100B0(void);

void sub_080169CC(void)
{
    u8 *src;
    u32 i;

    sub_08010074();
    sub_080165E0(0xBC * 2, 8);
    src = gUnk_0202F1B8;
    for (i = 0; i != 6; i++) {
        gUnk_0202EF00[i] = *src++;
    }
    sub_080100B0();
}
