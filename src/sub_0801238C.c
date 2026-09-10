#include "global.h"
extern u8 gUnk_0202EF00[];
extern u8 gUnk_0202EF80[];
extern u8 gUnk_0202EF08[];
extern u8 gUnk_0202EF60[];
void sub_0801238C(void)
{
    u8 i;
    gUnk_0202EF00[0] = 0;
    gUnk_0202EF00[1] = 1;
    gUnk_0202EF00[2] = 1;
    gUnk_0202EF00[3] = 1;
    gUnk_0202EF00[5] = 1;
    gUnk_0202EF00[4] = 0;
    i = 0;
    do {
        gUnk_0202EF80[i] = 1;
        i++;
    } while (i != 0x0A);
    gUnk_0202EF08[0] = 1;
    gUnk_0202EF08[1] = 0;
    gUnk_0202EF08[2] = 0;
    gUnk_0202EF08[3] = 0;
    gUnk_0202EF08[4] = 0;
    i = 0;
    do {
        gUnk_0202EF60[i] |= 0xFF;
        i++;
    } while (i != 0x10);
    gUnk_0202EF80[5] = 0;
    gUnk_0202EF80[3] = 1;
}
