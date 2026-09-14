/*
 * sub_0800A628 — QUARANTINED 2026-09-14 wave 6 (fresh-verified: rm .o; make
 * .o; match.py = MISMATCH, 220/220 bytes, 30 diff lines, ALL in ONE cluster
 * around the g2 j-chain 0x800a66a-0x800a686 plus one scratch at 0x800a6a6).
 *
 * MAJOR PROGRESS this wave (structure + g1 + g3 + tail now byte-exact):
 *   - g3 solved: p = &gUnk[i]; sin1 = gUnk[i + 0x40]; cos1 = *p;
 *     if (sin2 * sin1 + cos1 * cos2 < 0)
 *     gives ROM's exact order: addr-sin(r1), addr-cos(4-insn from i),
 *     load-cos->r5, load-sin->r4, and the var-reuse makes sin1/cos1
 *     GLOBALS with cos1's total live 1 insn shorter -> cos1=r4, sin1=r5
 *     in BOTH groups (g1 asrs r5/r4 + g3 loads r5/r4 match ROM).
 *   - pins that WORK (callee-saved, no chain shape damage):
 *       register s32 m asm("r1");   (muls r0,r1 x4, t2/j/t4 fall to r2,
 *                                    zeros to r1, t1 to r3 - all ROM)
 *       register s32 sin2 asm("r8");  (mov r8,r0 after asrs chain in r0)
 *       register s32 *q asm("r6");    (movs r6,#150 chain, str r0,[r6])
 *     table stays natural r7.
 *   - g1 byte-exact incl. zeros r1/r1, t1=r3, t2=r2, m ldr r1, sin1=r5,
 *     cos1=r4; sum1 mov r0,r8 / muls r0,r5 / adds r1,r4 / muls r1,r3 exact.
 *   - tail: 0x2800 adds, str r0,[r6], a+300 recompute ldrh/str all exact.
 *
 * Remaining diff (g2 j-chain, r0<->r2 web):
 *   ROM:  ldr r0,[r6]; asrs r2,r0,#10; movs r0,#0x3f; ands r2,r0;
 *         lsls r2,#2; lsls r0,r2,#1; adds r3,r0,r7; movs r0,#0;
 *         ldrsh r3,[r3,r0]; adds r0,r2,#0 (COPY j); adds r0,#64; ...
 *   ours: asrs r0,r0 (IN PLACE - v's qty TIED with j at the asrs),
 *         const63/j2/addr3/t3 all shifted r0<->r2, mov r8,r2 copy for t3,
 *         add r0,r0,#0x40 in place (ROM copies j first = 4 insns).
 *   Root causes (verified via -dl dumps):
 *   1. local-alloc combine_regs ties the *q-load pseudo v into j's qty at
 *      the asrs (v dies there, j fresh) -> whole chain homes r0. ROM has
 *      v=r0, j=r2: NO tie AND r0 blocked (death/birth boundary). Pinning
 *      v asm("r0") gives j a copy-SUGGESTION r0 (same result); pinning j
 *      asm("r2") moves the ldr into r2 (reload forces src=dest reg for
 *      the pinned dest). v+j both pinned gives asrs r2,r0 but un-does
 *      the sin1/cos1/cos2 homes (cascades ~20 new diff lines).
 *   2. t4's address: ours adds r0,r0,#0x40 in place on j's home (j dead
 *      at its last use); ROM copies j (adds r0,r2,#0) then adds #0x40 -
 *      expand protects a var that is still live; j must have a pending
 *      use at that point in the original RTL order.
 *   3. 0x800a6a6: mov r0,r9 vs ROM mov r1,r9 (rot copy scratch, cascade).
 *
 * Swept this wave: g3 expression forms (fresh pseudos - breaks sin1/cos1
 * homes via local tie), g3 pointer forms (p=&gUnk[i] + swapped slots = THE
 * fix), m/sin2/q/table pins (m/sin2/q work, table-pin breaks gUnk[i+0x40]
 * addressing), v pin r0, j pin r2, v+j pins, t3 pin r3 (breaks prologue),
 * 2-var j splits (pri ties worse), mask/shift spellings.
 * Next lever ideas: find a source shape where the *q load's pseudo is
 * global or dies twice (kills the asrs tie); make j+0x40 expansion see j
 * still live (compute the j*2 index AFTER t4's address in the tree).
 */
#include "global.h"

extern s16 gUnk_0801CD08[]; /* 0x0801CD08 */

void sub_0800A628(s32 *a)
{
    register u32 rot asm("r9");
    u32 i;
    register s32 m asm("r1");
    s32 t1;
    s32 t2;
    s32 sin1;
    s32 cos1;
    u32 j;
    s32 t3;
    s32 t4;
    register s32 sin2 asm("r8");
    s32 cos2;
    s32 val;
    register s32 *q asm("r6");
    s16 *p;

    rot = (((u16 *)a)[0x1A] >> 10) << 16;
    i = rot >> 14;
    t1 = gUnk_0801CD08[i];
    t2 = gUnk_0801CD08[i + 0x40];
    m = -256;
    sin1 = -(t1 * m) >> 8;
    cos1 = (t2 * m) >> 8;
    q = &a[0x4B];
    j = (*q >> 10) & 0x3F;
    j = j << 2;
    t3 = gUnk_0801CD08[j];
    t4 = gUnk_0801CD08[j + 0x40];
    sin2 = -(t3 * m) >> 8;
    cos2 = (t4 * m) >> 8;
    if ((sin2 * sin1 + cos1 * cos2) >> 8 > 0x8D)
        return;
    i = rot >> 14;
    p = &gUnk_0801CD08[i];
    sin1 = gUnk_0801CD08[i + 0x40];
    cos1 = *p;
    if (sin2 * sin1 + cos1 * cos2 < 0)
        val = ((u16 *)a)[0x1A] - 0x2800;
    else
        val = ((u16 *)a)[0x1A] + 0x2800;
    *q = val;
    a[0x4B] = *(u16 *)&a[0x4B];
}
