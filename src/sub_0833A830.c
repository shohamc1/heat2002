#include "global.h"

/* The cancelling offset preserves the initial base-to-p copy.
   Assigning off = 4 inside the loop keeps base + 4 out of the preheader. */

struct Unk0801DA90
{
    u32 unk0;
    u32 unk4;
    u8 unk8;
    u8 filler9[3];
};

extern struct Unk0801DA90 gUnk_0200CA74[];

extern u8 gUnk_0200118D[];
extern u8 gUnk_00000004[];

extern void sub_08344B64(u32 a, u32 b, u32 c);
extern void sub_0833AC08(void *a);
extern void sub_0833AAB8(void *a);
extern void sub_0833ADA4(u32 a);
extern void sub_0833AF48(u32 a, u32 b, u32 c);

void sub_0833A830(void)
{
    u32 x;
    struct Unk0801DA90 *p;
    u32 n;
    u32 i;
    u32 base;
    u16 cnt;
    u32 off;

    sub_08344B64((u32)gUnk_0200118D & ~1, 0x03007000, 0x04000100);
    sub_0833AC08((void *)0x02037E30);
    sub_0833AAB8((void *)0x02038E70);
    sub_0833ADA4(0x0097D800);
    cnt = (u16)(u32)gUnk_00000004;
    if (cnt != 0)
    {
        base = (u32)gUnk_0200CA74;
        off = cnt;
        p = (struct Unk0801DA90 *)(base + off - cnt);
        i = 0;
        n = cnt;
    loop:
        off = 4;
        x = p->unk0;
        sub_0833AF48(x, *(u32 *)(i + (base + off)), p->unk8);
        *(u32 *)(x + 0x18) = 0x02039030;
        p++;
        i += 12;
        n--;
        if (n != 0)
            goto loop;
    }
}
