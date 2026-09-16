/*
 * sub_0800E008 quarantine notes (2026-09-14, retry wave)
 * Best build: 540/532 bytes (this file, natural allocation, no pins).
 * SOLVED since last quarantine:
 *  - Prologue now saves r8 AND r9 (mov r7,r9; mov r6,r8; push {r6,r7}):
 *    fell out naturally once ALL asm() pins were REMOVED. GCC 2.95's
 *    local register variables do not model conflicts; every pin in the
 *    old draft collided (shift's r7 clobbered by idx4, r8 pin silently
 *    dropped when RHS is a computation -- pins only survive when the
 *    initializer is a CONSTANT, see matched src/sub_080040E0.c i=0xF0).
 *  - Loop counters: i must be u16 with `i = i + 1;` (add-then-truncate:
 *    adds r0,r4,#1; lsls r0,#16; lsrs r4,r0,#16). The old `u32 i;
 *    i = (u16)i + 1;` truncated first (lsls/lsrs before the add).
 * Remaining diffs (all in the retry-loop web):
 *  1. Setup register rotation. Target: idx4(idx*4)=r8 (hoisted before
 *     everything: lsls r3,r5,#2; mov r8,r3), shift=r7, nxt=r6.
 *     Ours: shift=r8, nxt=r7, idx4=r6 (natural allocation).
 *     qty priority = floor_log2(nrefs)*nrefs*size/live_len: idx4 has the
 *     shortest life (def e062->use e0ca) so it wins r6 in ours; target
 *     has it LAST (r8) => in the target idx4's qty must have LOWER
 *     priority (longer life or REG_EQUIV demotion: local-alloc.c:852
 *     doubles REG_LIVE_LENGTH for equiv-bearing pseudos).
 *  2. idx=nxt narrow: target uses a scratch (lsls r0,r6,#24;
 *     lsrs r5,r0,#24), ours truncates in place (lsls r5,r7,#24;
 *     lsrs r5,r5,#24).
 *  3. Retry block layout: target `beq _exit` forward + update inline;
 *     ours `bne update` backward + exit fallthrough; also our loop head
 *     sits at the v-computation with `mov r6,sp` re-entry (+4 insns
 *     total = the 8-byte delta).
 * Verified levers that DO NOT work: pinning idx4 to r8 (silently ignored
 * when RHS is idx*4 with the 0x96 branch present; without that branch the
 * whole setup folds to constants and the pin fires -- bisected);
 * pinning all four setup vars (uservar collisions, miscompiles);
 * comma-expression or reordered setup statements (emission order is
 * allocation-driven, not statement-driven); extra idx4 read (folded).
 */
#include "global.h"

extern void sub_08016E1C(u32 a1, u32 a2);
extern void sub_08016E0C(u32 a1, u32 a2, u32 a3);
extern void sub_08016E30(void);
extern void sub_0800DE9C(u32 a1, u32 a2);
extern void sub_0800DE60(u32 a1, u32 a2);
extern void sub_08006950(u8 *a1, u32 a2, u32 a3);
extern void sub_0800E3C4(u32 a1, u32 a2);
extern u32 sub_0800E460(u32 *a1);
extern void sub_0800DFCC(void);

extern u8 gUnk_080000B2;
extern u32 gUnk_080000AC;
extern u32 gUnk_0807C9E8;
extern u32 gUnk_02000590[];
extern u32 gUnk_083FDA50[];
extern u32 gUnk_0807C9CC[];
extern u8 gUnk_0807C9F0[];
extern u8 gUnk_0807CA08[];
extern u8 gUnk_0807CA20[];
extern u8 gUnk_0807CA34[];
extern u8 gUnk_0807CB58[];
extern u32 gUnk_0202E960[];

u32 sub_0800E008(void)
{
    u32 nm[2];
    u8 idx;
    u16 i;
    u32 idx4;
    u32 shift;
    u32 *pn;
    u32 nxt;

    nm[1] = 0;
    idx = 0;
    *(volatile u16 *)0x04000200 = 1;
    if (gUnk_080000B2 == 0x96 && gUnk_080000AC == gUnk_0807C9E8)
        *(volatile u16 *)0x04000200 |= 0x80 << 6;
    *(volatile u16 *)0x04000004 = 8;
    *(volatile u16 *)0x04000208 = 1;
    gUnk_02000590[1] = 0x0800DFC1;
    gUnk_02000590[0] = 0x0800E641;
    *(volatile u16 *)0x04000000 &= 0xEFFF;
    i = 0;
    idx4 = idx * 4;
    shift = idx << 15;
    pn = &nm[1];
    nxt = idx + 1;
    do {
        sub_08016E1C(gUnk_083FDA50[i], 0x06010000 + i * 0x200);
        i = i + 1;
    } while (i <= 2);
    *(volatile u32 *)0x040000D4 = (u32)gUnk_0807CB58;
    *(volatile u32 *)0x040000D8 = 0x05000200;
    *(volatile u32 *)0x040000DC = 0x84000028;
    *(volatile u32 *)0x040000DC;
    nm[0] = 0xA0;
    *(volatile u32 *)0x040000D4 = (u32)&nm[0];
    *(volatile u32 *)0x040000D8 = (u32)gUnk_0202E960;
    *(volatile u32 *)0x040000DC = 0x85000100;
    *(volatile u32 *)0x040000DC;
    sub_08016E0C((u32)gUnk_0202E960, 0x07000000, 0x100);
    *(volatile u16 *)0x04000000 |= 0x82 << 5;
    sub_0800E3C4(1, gUnk_0807C9CC[idx]);
    i = 0;
    do {
        sub_08006950(gUnk_0807C9F0, i + 8, 1);
        i = i + 1;
    } while (i <= 3);
    do {
        u8 v = (u8)((shift + nm[1] * 4) >> 10);

        sub_0800DE9C(v, 100);
        sub_0800DE60(v, 100);
        sub_08006950(gUnk_0807CA08, 8, 1);
        sub_08006950(gUnk_0807CA20, 9, 1);
        sub_08006950(gUnk_0807CA34, 10, 1);
        if (sub_0800E460(pn) != 0)
        {
            idx = nxt;
            if (idx == 7)
                break;
            sub_0800E3C4(1, gUnk_0807C9CC[idx]);
            nm[1] = 0;
            shift = idx << 15;
            nxt = idx + 1;
        }
        sub_08016E0C((u32)gUnk_0202E960, 0x07000000, 0x100);
        sub_08016E30();
    } while (1);
    nm[0] = 0xA0;
    *(volatile u32 *)0x040000D4 = (u32)&nm[0];
    *(volatile u32 *)0x040000D8 = (u32)gUnk_0202E960;
    *(volatile u32 *)0x040000DC = 0x85000100;
    *(volatile u32 *)0x040000DC;
    sub_08016E0C((u32)gUnk_0202E960, 0x07000000, 0x100);
    sub_0800DFCC();
    return 0;
}
