#include "global.h"

struct UnkStruct080044DC {
    u32 unk0;
    u32 unk4;
    u16 unk8;
};

extern struct UnkStruct080044DC *gUnk_02024820; /* 0x02024820 */
extern u8 gUnk_02024824;                        /* 0x02024824 */

u32 sub_080044DC(u32 arg0, u32 arg1, u32 arg2)
{
    struct UnkStruct080044DC *r3 = gUnk_02024820;
    u32 r;

    r3->unk0 = arg0;
    r3->unk4 = arg1;
    r3->unk8 = arg2;
    gUnk_02024820 = r3 + 1;
    r = gUnk_02024824 + 1;
    gUnk_02024824 = r;
    return r;
}
