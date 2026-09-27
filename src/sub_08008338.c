#include "global.h"
#include "functions.h"
extern u16 gUnk_0202A540[];
extern u16 gUnk_0202CB20[];
extern u16 gUnk_0202CB00[];
extern u16 gUnk_08367B82[];
extern u16 gUnk_08367B8C[];
void sub_08008338(void)
{
    u16 *dst;
    u16 *src;
    u8 i = 0;
    do {
        gUnk_0202A540[i] = gUnk_08367B82[i];
        gUnk_0202CB20[i] = gUnk_08367B8C[i];
        i++;
    } while (i != 5);
    dst = gUnk_0202CB20;
    src = gUnk_0202CB00;
    sub_0800830C(dst, src);
}
