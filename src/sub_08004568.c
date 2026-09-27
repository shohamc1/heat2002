#include "global.h"
#include "variables.h"


struct VertexCmd {
    u32 field0;
    u32 field4;
    u16 field8;
    u16 fieldA;
    u16 fieldC;
    u16 fieldE;
};

u32 sub_08004568(u32 a, u32 b, s32 c, u16 d)
{
    struct VertexCmd *p;

    if ((s8)gUnk_02025150 < 0)
        return 0;
    if (gUnk_02025154 > 0x1E)
        return 0;
    p = (struct VertexCmd *)gUnk_02024C30;
    p->field0 = (gUnk_02025154 << 25) | a;
    p->field4 = b;
    p->field8 = -c;
    p->fieldA = c;
    p->fieldC = d;
    gUnk_02024C30 = (u32)(p + 1);
    gUnk_02025150 = gUnk_02025150 + 1;
    gUnk_02025154 = gUnk_02025154 + 1;
    return 1;
}
