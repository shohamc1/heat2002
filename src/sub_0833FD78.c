#include "global.h"
#include "variables.h"


u8 sub_0833FD78(u32 a)
{
    u32 *p;
    u32 i;

    p = gUnk_0203C270;
    for (i = 0; i != 0x10; i++, p += 3) {
        if (p[1] == a) {
            *(u8 *)p = 1;
            *((u8 *)p + 1) = 1;
            return i;
        }
    }
    p = gUnk_0203C270;
    for (i = 0; i != 0x10; i++, p += 3) {
        if (*(u8 *)p == 0) {
            *(u8 *)p = 1;
            *((u8 *)p + 1) = 1;
            p[1] = a;
            return i;
        }
    }
    return 0;
}
