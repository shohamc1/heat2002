#include "global.h"
#include "data.h"
#include "variables.h"

extern u16 *gUnk_08364B08;         /* ROM word holding a u16* */
extern u16 gUnk_08334DCC[];

void sub_08006214(void)
{
    u16 *dst;
    u8 i;
    u8 j;

    dst = gUnk_08364B08 + 0x1D4;
    i = 0;
    do {
        j = 0;
        do {
            *dst++ = gUnk_08335A8C[gUnk_08334DCC[(i + 8) * 68 + j + 0x33]] | 0xE000;
            j++;
        } while (j != 10);
        dst += 0x16;
        i++;
    } while (i != 6);
    dst = gUnk_08364B08 + 0x1D4;
    if (gUnk_0202EEB0 == 0) {
        i = 0;
        do {
            j = 0;
            do {
                *dst++ = 0x47;
                j++;
            } while (j != 4);
            dst += 0x1C;
            i++;
        } while (i != 6);
    }
}
