/*
sub_08000958 (22 b code, 26 b ROM extent) + sub_08000972 (22 b code + shared
pool _08000988) — QUARANTINED: not reachable from agbcc C. Hand-written
assembly in the retail source (see also identical sibling pair
sub_0833A018/sub_0833A032 in asm/rom_08339B78.s, same bytes except the pool
constant 0x0200C668 — one hand-asm macro instantiated twice).

TARGET (ROM 0x08000958..0x0800098C):
    sub_08000958:
        mov  r12, lr
        movs r1, #0x24
        ldr  r2, _08000988          @ =0x0801CF88
    _0800095E:
        ldr  r3, [r2]
        bl   sub_08000972
        stm  r0!, {r3}
        adds r2, #0x04
        subs r1, #0x01
        bgt  _0800095E
        bx   r12
        .byte 0x00, 0x00, 0x13, 0x78   @ pad + 2 stray data bytes (kept in asm)
    sub_08000972:                     @ non-word-aligned entry (0x...72)
        push {r0}
        lsrs r0, r2, #0x19
        bne  _08000984                @ branch on lsr flags directly
        ldr  r0, _08000988
        cmp  r2, r0
        bcc  _08000982
        lsrs r0, r2, #0x0E
        beq  _08000984                @ branch on lsr flags directly
    _08000982:
        movs r3, #0x00
    _08000984:
        pop  {r0}
        bx   lr
    _08000988: .4byte 0x0801CF88      @ pool shared by BOTH halves

Semantic: copy 0x24 words from 0x0801CF88 to dest, zeroing each word whose
SOURCE ADDRESS satisfies (addr < 0x02000000 && (addr < 0x0801CF88 ||
addr >= 0x4000)) — dead condition for these addresses, i.e. dev code.

WHY NO C CAN MATCH (three independent blockers, all in tools/agbcc source):

1. Caller prologue `mov r12, lr` ... `bx r12` around a `bl`.
   tools/agbcc/gcc/thumb.c thumb_function_prologue (line ~830):
       if (live_regs_mask || !leaf_function_p() || far_jump_used_p())
           live_regs_mask |= 1 << 14;      /* always pushes lr for calls */
   Any function containing a CALL is non-leaf, so lr is pushed; IP_REGISTER
   (r12) appears in the compiler ONLY in the >12-byte struct-return epilogue
   (thumb.c:660-686, `mov r12, r3`), never as a prologue lr save.

2. Loop state lives in r0/r1/r2/r3 ACROSS the bl. All four are call-used;
   reload must move any live value to r4-r7 (or stack) around a call.
   Empirical: the 4-arg split below compiles the caller to
       push {r4,r5,r6,r7,lr}; add r7,r0; ldr r6,pool; mov r5,#0x24;
       ldr r4,[r6]; add r0,r7; add r1,r5; add r2,r6; add r3,r4; bl;
       stm r7!,{r4}; ...   — register shuffles the ROM does not have.

3. Callee returns its result in r3 and preserves/pushes incoming r0.
   The `u32 f(a,b,c,d)` form below reproduces the whole condition body
   (pool order, bcc/beq targets, movs r3,#0) but ends
       add r0, r3, #0; bx lr      (AAPCS return in r0)
   vs ROM's `pop {r0}; bx lr` which restores the CALLER's r0 and leaves the
   zeroed value in r3 — a hand-rolled custom convention. Single `push {r0}`
   prologues are unreachable too: thumb.c's pretend-args path pushes
   rN..r3 (4 - size/4 regs, i.e. {r3} or {r0,r1,r2,r3}), and live_regs_mask
   never contains a call-used reg; reload spills via str [sp,#off], never
   single-reg push/pop.

Minor extra divergences (moot given 1-3): ROM branches directly on the lsr
flags (`lsrs r0,r2,#0x19; bne`), agbcc always emits `lsr; cmp r0,#0; bne`
when the shifted value is a compare operand.

SHAPES SWEPT (old_agbcc -O2 -mthumb-interwork):
- two-function split, caller passing (dest, count, src, *src) as r0-r3 args,
  callee (u32 a,b,c,d) zeroing its 4th arg / returning conditionally-zeroed d
  (condition body byte-matches except epilogue, see 3)
- callee forms: void 4-arg, value-return 4-arg, u32* out-param
- single merged function (condition inlines; no bl, no split — closest loop
  core: ldr r1,[r2]; ...; stm r4!,{r1}; adds r2,#4; subs r3,#1; bgt)
- 16-byte struct return (Quad{a,b,c,d}): GCC 2.95 thumb returns structs via
  hidden memory pointer (push {r4,r5,lr}; add sp,#-0x10; ldmia/stmia copy),
  not in r0-r3 — refuted
- merged call shapes with address-first local (parked.md idiom): irrelevant,
  the caller's bl itself is unreachable

CONCLUSION: leave both halves in asm (guide step 6a: decompile the pair
together or neither). The stray `.byte 0x00,0x00,0x13,0x78` between the
halves and the shared pool stay with the asm fragment. Only caller is
sub_08001548-family code at asm/rom_08001548.s:119 (dest 0x02001D90,
'Smsh' struct init — demo/replay subsystem).
*/

#if 0
#include "global.h"

extern u32 gUnk_0801CF88[];

/* Closest reachable callee: condition body matches; epilogue differs
   (add r0,r3,#0; bx lr  vs  pop {r0}; bx lr) and caller cannot keep
   r0-r3 live across the call. */
u32 sub_08000972(u32 a, u32 b, u32 c, u32 d)
{
    if ((c >> 25) == 0 && (c < (u32)gUnk_0801CF88 || (c >> 14) != 0))
        d = 0;
    return d;
}

void sub_08000958(u32 *dest)
{
    s32 n;
    u32 *src = gUnk_0801CF88;
    u32 v;

    for (n = 0x24; n > 0; n--) {
        v = *src;
        sub_08000972((u32)dest, n, (u32)src, v);
        *dest++ = v;
        src++;
    }
}
#endif
