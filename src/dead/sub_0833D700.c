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

u32 sub_0833D700(u32 a, u32 b, s32 c, u16 d)
{
    struct VertexCmd *p;

    if ((s8)gUnk_0203B600 < 0)
        return 0;
    if (gUnk_0203B604 > 0x1E)
        return 0;
    p = (struct VertexCmd *)gModule_SecondOamSortCursor;
    p->field0 = (gUnk_0203B604 << 25) | a;
    p->field4 = b;
    p->field8 = c;
    p->fieldA = c;
    p->fieldC = d;
    gModule_SecondOamSortCursor = (u32)(p + 1);
    gUnk_0203B600 = gUnk_0203B600 + 1;
    gUnk_0203B604 = gUnk_0203B604 + 1;
    return 1;
}
