#include "global.h"

void sub_080012D4(u16 a);
void sub_080017D0(void);

void sub_08010074(void)
{
    u8 r4;
    for (r4 = 0; r4 != 0x64; r4 = (u8)(r4 + 1))
        sub_080012D4(r4);
    sub_080017D0();
}
