#include "global.h"
extern u16 gUnk_0202A540[];
extern u16 gUnk_0202CB20[];
extern u16 gUnk_0202CB00[];
extern u16 gUnk_08367B82[];
extern u16 gUnk_08367B8C[];
extern void sub_0800830C(u16 *a, u16 *b);
void sub_08008338(void)
{
    u8 i = 0;
    do {
        gUnk_0202A540[i] = gUnk_08367B82[i];
        gUnk_0202CB20[i] = gUnk_08367B8C[i];
        i++;
    } while (i != 5);
    sub_0800830C(gUnk_0202CB20, gUnk_0202CB00);
}
