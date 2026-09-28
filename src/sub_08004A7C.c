#include "global.h"
#include "variables.h"

extern u32 gUnk_02025270[];
extern u8 gText_FormatA[];
extern u8 gText_FormatG[];

void sub_08017594(u32 *a, u8 *b, u8 c, u32 d);
void sub_08004A50(u32 *a, u32 b, u32 c, u32 d);

void sub_08004A7C(u8 sel)
{
    u32 *base;
    u8 i;
    u32 *p;

    do {
        i = 0;
        base = gUnk_02025270;
        p = gUnk_0202A540;
        do {
            sub_08017594(base, gText_FormatA, i, p[i]);
            sub_08004A50(base, 0x10, (i * 10) + 40, sel == i);
            i = i + 1;
        } while (i != 5);
        i = 0;
        base = gUnk_02025270;
        do {
            sub_08017594(base, gText_FormatG, i, gUnk_0202CB20[i]);
            sub_08004A50(base, 0x78, (i * 10) + 40, sel == (i + 5));
            i = i + 1;
        } while (i != 5);
    } while (0);
}
