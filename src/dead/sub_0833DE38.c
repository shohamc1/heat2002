#include "global.h"

void sub_0833DE38(s32 a, u16 *b, u16 *c, u16 *d)
{
    u16 minutes = a / 60000;
    s32 rem = a - minutes * 60000;
    u16 seconds = rem / 1000;

    *d = rem - seconds * 1000;
    *c = seconds;
    *b = minutes;
}
