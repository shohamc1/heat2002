#include "global.h"

extern u32 gUnk_0203B0E0; /* 0x0203B0E0: current queue write pointer */
extern u8 gUnk_0203B600;  /* 0x0203B600: queue entry counter */
extern u8 gUnk_0203B604;  /* 0x0203B604: queued item counter */

struct VertexCmd {
    u32 field0;
    u32 field4;
    u16 field8;
    u16 fieldA;
    u16 fieldC;
    u16 fieldE;
};

u32 sub_0833D764(u32 a, u32 b, s32 c, u16 d)
{
    struct VertexCmd *p;

    if ((s8)gUnk_0203B600 < 0)
        return 0;
    if (gUnk_0203B604 > 0x1E)
        return 0;
    p = (struct VertexCmd *)gUnk_0203B0E0;
    p->field0 = (gUnk_0203B604 << 25) | a;
    p->field4 = b;
    p->field8 = -c;
    p->fieldA = c;
    p->fieldC = d;
    gUnk_0203B0E0 = (u32)(p + 1);
    gUnk_0203B600 = gUnk_0203B600 + 1;
    gUnk_0203B604 = gUnk_0203B604 + 1;
    return 1;
}
