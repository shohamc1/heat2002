#include "global.h"
extern u8 gUnk_0202F050[];
extern u8 gUnk_0202EF80[];
extern u8 gUnk_0202EF08[];
extern u8 gUnk_0202EF60[];
extern u8 gUnk_0202EEC0[];
extern u8 gUnk_0202EDC8[];
extern u8 gUnk_0202ED80[];
extern void sub_08010074(void);
extern void sub_080165E0(u32 a, u32 b);
extern void sub_080100B0(void);
void sub_08016888(void)
{
    u8 *p;
    s32 i;
    sub_08010074();
    sub_080165E0(0x10, 0x30);
    p = gUnk_0202F050;
    i = 0;
    do { gUnk_0202EF80[i] = *p++; i++; } while (i != 0x0A);
    i = 0;
    do { gUnk_0202EF08[i] = *p++; i++; } while (i != 0x04);
    i = 0;
    do { gUnk_0202EF60[i] = *p++; i++; } while (i != 0x10);
    i = 0;
    do { gUnk_0202EEC0[i] = *p++; i++; } while (i != 0x08);
    i = 0;
    do { gUnk_0202EDC8[i] = *p++; i++; } while (i != 0x04);
    i = 0;
    do { gUnk_0202ED80[i] = *p++; i++; } while (i != 0x04);
    sub_080100B0();
}
