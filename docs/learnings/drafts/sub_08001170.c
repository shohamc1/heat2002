#include "global.h"

/* NOTE: near-miss, not yet byte-identical.  Two deltas remain against ROM:
   the ROM keeps the table base in r8 and computes (base + 4) + i inside the
   loop, while agbcc here folds the +4 into the load offset; and p/n land in
   the opposite pair of callee-saved registers. */

extern u8 gUnk_0800054D[];
extern u8 gUnk_00000005[];
extern u8 gUnk_02000DE0[];
extern u8 gUnk_02001E20[];
extern u8 gUnk_02002020[];

struct Unk0801DA90
{
    u32 unk0;
    u32 unk4;
    u8 unk8;
    u8 filler9[3];
};

extern struct Unk0801DA90 gUnk_0801DA90[];

extern void sub_08016E10(u32 a, u32 b, u32 c);
extern void sub_08001548(void *a);
extern void sub_080013F8(void *a);
extern void sub_080016E4(u32 a);
extern void sub_08001888(u32 a, u32 b, u32 c);

void sub_08001170(void)
{
    u32 x;
    struct Unk0801DA90 *p;
    u32 n;
    u32 i;
    u32 base;
    u16 cnt;

    sub_08016E10((u32)gUnk_0800054D & ~1, 0x03007000, 0x04000100);
    sub_08001548(gUnk_02000DE0);
    sub_080013F8(gUnk_02001E20);
    sub_080016E4(0x0097EA00);
    cnt = (u16)(u32)gUnk_00000005;
    if (cnt != 0)
    {
        base = (u32)gUnk_0801DA90;
        p = (struct Unk0801DA90 *)base;
        i = 0;
        n = cnt;
    loop:
        x = p->unk0;
        sub_08001888(x, *(u32 *)(base + 4 + i), p->unk8);
        *(u32 *)(x + 0x18) = (u32)gUnk_02002020;
        p++;
        i += 12;
        n--;
        if (n != 0)
            goto loop;
    }
}
