#include "global.h"
#include "variables.h"

extern u8 *gUnk_083FE080[];

s8 sub_0801319C(void)
{
    u8 i;
    u8 *e;

    i = 0;
    do {
        e = gUnk_083FE080[i];
        if (e[0] == gUnk_0202EF78[0]
            && e[1] == gUnk_0202EF78[1]
            && e[2] == gUnk_0202EF78[2]
            && e[3] == gUnk_0202EF78[3]
            && e[4] == gUnk_0202EF78[4])
            return i;
        i++;
    } while (i != 5);
    return -1;
}
