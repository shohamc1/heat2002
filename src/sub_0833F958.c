#include "global.h"

struct Unk0833F958
{
    u8 field_00;
    u8 field_01;
    u32 field_04;
};

void sub_0833F958(struct Unk0833F958 *r0)
{
    r0->field_04 = 0xFFFF;
    r0->field_00 = 0;
    r0->field_01 = 0;
}
