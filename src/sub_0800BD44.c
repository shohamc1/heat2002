#include "global.h"

struct UnkStruct0800BD44_Entry {
    u8 f0;
    u8 f1;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 pad[0xC];
};

struct UnkStruct0800BD44_Ctl {
    u8 pad[0x4C];
    u8 f4C;
    u8 f4D;
    u8 f4E;
};

s32 sub_0800BC4C(u16 *p, struct UnkStruct0800BD44_Entry *e);

void sub_0800BD44(s32 a, u16 *b, struct UnkStruct0800BD44_Entry *c, struct UnkStruct0800BD44_Ctl *d)
{
    struct UnkStruct0800BD44_Entry *e;
    s32 res;

    e = c;
    if (e->f6 < a) {
        do {
            e = e + 1;
        } while (e->f6 < a);
    }
loop:
    res = sub_0800BC4C(b, e);
    if (res != -1)
        goto done;
    e = e + 1;
    if (e->f1 == 0xFF) {
        d->f4C = d->f4C + 1;
        e = c;
    }
    goto loop;
done:
    d->f4D = res;
    d->f4E = 0xF;
}
