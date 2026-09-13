/*
 * sub_0800F0BC -- BLOCKED (24 bytes @ 0x0800F0BC)
 *
 * Target:
 *   mov  r2, pc            ; 0x467A  -- REACHABLE (see below)
 *   lsrs r2, r2, #0x18     ; 0x0E12
 *   movs r1, #0x0C         ; 0x210C
 *   cmp  r2, #0x02
 *   beq  _0800F0CE
 *   movs r1, #0x0D
 *   cmp  r2, #0x08
 *   beq  _0800F0CE
 *   movs r1, #0x04
 * _0800F0CE:
 *   subs r0, r0, r1        ; 0x1A40  -- UNREACHABLE
 *   bgt  _0800F0CE
 *   bx  lr
 *
 * Blocker: the delay loop feeds the branch from the SUBS flags directly
 * (`subs r0,r0,r1; bgt` with no `cmp r0,#0`). agbcc's thumb machine
 * description cannot do this: no arithmetic insn sets cc0 (tstsi is
 * "cmp %0,#0"; there is no *subsi_compare0 / *andsi_compare0), and a scan
 * of all 257 matched objects finds zero `and|sub` immediately followed by
 * a conditional branch -- every site has the explicit `cmp`. `do..while`,
 * `while ((n-=d)>0)`, and `for(;;){...if(n<=0)break;}` all emit sub+cmp+bgt
 * (verified 2026-09-13). Same wall class as the 112 `ands+bcc` sites in
 * the ROM (none matched either).
 *
 * The `mov r2, pc` idiom IS reachable and is worth remembering:
 *
 *     register u32 pcv asm("r15");   /* register-asm local, precedent in
 *                                     * matched src/sub_0801177C.c */
 *     bank = pcv >> 24;              -> mov r2, pc ; lsr rX, r2, #0x18
 *
 * (a plain `pcv` read compiles to `add r0, r0, pc`-style uses; taking
 * `pcv >> 24` into a local gives the mov+lsr pair). With that, this C:
 *
 *     void sub_0800F0BC(s32 n)
 *     {
 *         register u32 pcv asm("r15");
 *         u32 bank, d;
 *         bank = pcv >> 24;
 *         d = 0x0C;
 *         if (bank != 2) { d = 0x0D; if (bank != 8) d = 4; }
 *         do { n -= d; } while (n > 0);
 *     }
 *
 * compiles to the target except `lsr r1,r2` vs `lsrs r2,r2` (bank stays in
 * its own pseudo) and the missing-cmp loop above. The 2-instruction gap is
 * the whole function's blocker; likely hand-written asm in the original.
 */
