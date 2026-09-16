#include "global.h"

void sub_08001150(u32 r0, u16 v)
{
    u32 r2 = r0;
    u32 t = *(u32 *)(r2 + 0x34);
    u32 c = 0x80 << 1;

    if (t == 0x68736D53)
    {
        *(u16 *)(r2 + 0x26) = v;
        *(u16 *)(r2 + 0x24) = v;
        *(u16 *)(r2 + 0x28) = c;
        /* Load-bearing: the dead store is eliminated but its use keeps t
         * alive across the branch, moving the tag pseudo from local-alloc
         * into global-alloc (v->r1, tag->r3, ptr->r2). */
        *(u32 *)(r2 + 0x34) = t;
    }
}
