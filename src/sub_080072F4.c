#include "global.h"

struct Unk080072F4 {
    u8 a;
    u8 b;
    u16 c;
    u32 d;
};

void sub_080072F4(struct Unk080072F4 *p)
{
    p->d = 0xFFFF;
    p->a = 0;
    p->b = 0;
}
