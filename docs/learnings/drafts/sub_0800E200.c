/*
 * sub_0800E200 — QUARANTINED wave 5d (2026-09-15, agent died mid-experiment;
 * this state compiles — the wave-7 `fp'/u32-flag rewrite left a stale
 * `start' use at its line 86 and did not compile). Fresh verification
 * (rm .o; make .o; match.py): MISMATCH, 452 bytes, 350 diff lines (175/175)
 * starting in the prologue: add sp literal pool 152 (target) vs 148 (ours)
 * and a missing `str r0,[sp,#596]' — the frame is 4 bytes short, so fix
 * frame size/layout first; everything downstream shifts with it.
 */

/*
 * sub_0800E200 quarantine notes (2026-09-14, retry wave)
 * Best build: 452/452 bytes (this file) -- EXACT target size, ~4 insns
 * of placement residue. Major fixes since last quarantine:
 *  - flag is a `u8 flag;` local written via `*(u32 *)&flag = 0/1;`
 *    (word stores, str [sp,#imm]) and read as plain `flag` (byte load
 *    through a materialized base). u8 flag[4] array or u32 flag with
 *    plain/cast accesses both fail differently (base-reg lives or the
 *    value is forwarded into a register).
 *  - `one` must be u32 (u8 added (r8<<24)>>24 renarrowing per use).
 *    It is pinned r8 with CONST init 1 (= i at init) -- const-init
 *    pins DO fire; computed-init pins are silently dropped.
 *  - loop counter i is SIGNED (`cmp r6,#3; ble`, not bls); x=r4,y=r5,
 *    i=r6 pins (const inits) give the target mapping; icon pin r9.
 *  - start naturally lands sl once icon takes r9.
 *  - EEFC call args are (work, start+0xC0, len-0xC0, 4, 1) -- the old
 *    draft had the 1 in the wrong position.
 *  - tail restructured to `if (EFC0 == 0) { if (keys&2 && flag != 1)
 *    return 1; } else { DFCC; E008; return 0; } goto loop;` -- gives
 *    the target block order (DFCC fallthrough, keys block after).
 * Remaining diffs (4 classes):
 *  1. slot swap: ours len@0x254 flag@0x250, target len@0x250 flag@0x254
 *     (u8 flag packs differently; decl order (work,len,flag) tried).
 *  2. flag word-store: ours materializes `add r5,sp,#592` at the top and
 *     keeps it live to the byte-read; target stores str [sp,#596]
 *     directly and materializes the base only at the ldrb. (Every
 *     `*(u32 *)&x` form tested forces a base; the target's sp-direct
 *     word stores suggest the original flag access path avoided the
 *     INDIRECT_REF force the way plain locals do.)
 *  3. second bit test: target re-copies r8 per use (`mov r2,r8` then
 *     `mov r1,r8`); ours CSEs one copy. The old draft's
 *     `__asm__ volatile ("" : : : "r2")` clobber between the two tests
 *     forced the double copy -- RESTORE IT if iterating (it was removed
 *     during this sweep; re-add inside the first test's fallthrough).
 *  4. minor arg-reg choices at the EEFC call (movs r4,#1 vs movs r0,#1)
 *     -- follows from 1+2.
 */
#include "global.h"

extern u16 gKeysPressed;
extern u8 gUnk_0807CA60[];
extern u8 gUnk_0833338C[];
extern u8 gUnk_08363EE8[];
extern u8 gUnk_08364AC8[];

extern void sub_08016E10(u32 src, u32 dest, u32 control);
extern void sub_08016E30(void);
extern u32 sub_08016558(u32 idx);
extern void sub_08006950(u8 *p, u32 a1, u8 a2);
extern void sub_08011C9C(u8 a, u16 *dst);
extern void sub_08004238(u32 a, u32 b);
extern void sub_0800DFCC(void);
extern void sub_0800048C(void);
extern void sub_0800EA64(void *a1);
extern void sub_0800EEFC(u8 *a1, u32 a2, void *a3, u32 a4, u32 a5);
extern u32 sub_0800EAA0(void *a1);
extern u32 sub_0800EFC0(u8 *ptr);
extern void sub_0800E008(void);

u32 sub_0800E200(void)
{
    u8 work[0x24C];
    u32 flag;
    u32 len;
    register u32 icon __asm__("r9");
    u8 *start;
    u8 *a;
    register u32 one __asm__("r8");
    register u32 x __asm__("r4");
    register u32 y __asm__("r5");
    register s32 i __asm__("r6");

    *(u32 *)&flag = 0;
    icon = 0;
    *(volatile u16 *)0x0400000E = 0x1C0C;
    {
        u8 *src = gUnk_0833338C;
        sub_08016E10((u32)src, 0x0600C000, 0x80 << 5);
    }
    {
        u8 *buf = work + 0x4C;
        sub_08011C9C(4, (u16 *)buf);
        sub_0800DFCC();
        sub_08004238((u32)buf, 0x0F);
    }
    start = gUnk_08363EE8;
    len = (u32)gUnk_08364AC8 - (u32)start;
    *(u32 *)(work + 0x28) = (u32)start;
    work[0x4B] = *(volatile u8 *)&flag;
    sub_0800EA64(work);
loop:
    {
        sub_08016E30();
        sub_08006950((u8 *)sub_08016558(0x53), 8, 1);
        i = 1;
        a = work;
        one = i;
        y = 9;
        x = 0x54;
        do {
            __asm__ volatile ("" : : : "r1");
            if (((a[0x1D] >> i) & one) == 0)
                goto show0;
            if (((a[0x1E] >> i) & one) != 0)
                goto show1;
show0:
            sub_08006950((u8 *)sub_08016558(x), y, 0);
            goto pnext;
show1:
            sub_08006950((u8 *)sub_08016558(x), y, 1);
pnext:
            ;
            y = y + 1;
            x = x + 1;
            i = i + 1;
        } while (i <= 3);
        if (work[0x1E] & 0x0E)
        {
            if (work[0x18] == 0)
                icon = 0x0F;
            else if (work[0x18] != 0xD1)
                icon = 0;
            if (work[0x18] > 0xDF)
                icon = 0x58;
        }
        else
        {
            icon = 0;
        }
        if (icon != 0)
        {
            sub_08006950((u8 *)sub_08016558(icon), 0x0E, 1);
        }
        else
        {
            sub_08006950(gUnk_0807CA60, 0x0E, 1);
        }
        sub_0800048C();
        if (gKeysPressed & 8)
        {
            if (work[0x18] == 0 && work[0x1E] != 0)
            {
                sub_0800EEFC(work, start + 0xC0, len - 0xC0, 4, 1);
                *(u32 *)&flag = 1;
            }
        }
        if (sub_0800EAA0(work) != 0 && flag == 1)
            return 1;
        if (sub_0800EFC0(work) == 0)
        {
            if ((gKeysPressed & 2) != 0 && flag != 1)
                return 1;
        }
        else
        {
            sub_0800DFCC();
            sub_0800E008();
            return 0;
        }
        goto loop;
    }
    return 1;
}
