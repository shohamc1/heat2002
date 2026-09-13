#include "global.h"

/* DRAFT: closest shape; remaining diff documented in header.
   Target homes the 0xFFFF loop invariant in ip with a per-iteration
   `mov r7, ip` reload copy, and the second volatile *src load lands
   in r7 feeding `lsls r0, r7, #5`. All C shapes tried (constant local,
   volatile re-read with/without t local, register asm("r12") hint)
   either home the constant in a low reg directly (r7) or get ip but
   reload through r0 with a single load. */

struct unk_07304
{
    u32 f0;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u32 f8;
    u32 fC;
    u32 f10;
};

void sub_08007304(u32 count, volatile u16 *src, struct unk_07304 *e)
{
    u32 i;
    u32 t;

    for (i = 0; i != count; i++, e++, src++)
    {
        u32 f = 0xFFFF;

        e->f8 = f;
        e->f0 = 0;
        e->f4 = 0;
        e->f10 = *src;
        t = *src;
        e->fC = 0x06010000 + (t << 5);
        e->f6 = 0;
    }
}
