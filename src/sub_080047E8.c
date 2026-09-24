/*
 * NEAR-MISS (348/348 bytes, one 6-insn hunk @ 0x08004808-0x08004814).
 * 2026-09-21 session findings (fresh characterization of the residual):
 *  - The root cause is a CSE SWAP of the two zero pseudos, NOT sinking.
 *    At expand the structure is already perfect: c=cmd (mov r1,sp),
 *    z=0 (pos 2), w=0 (pos 3), 0x68, strh [c], mov r0,sp, strh [r0,#2] --
 *    exactly the target IF the strh consumes w and the two strb's consume z.
 *  - `cmd[1] = w` (array spelling) expands as an RMW `(cmd[1] & 0) | w`
 *    (store_bit_field path on the address-taken local array). First cse
 *    folds it to the const-0 TABLE LOOKUP, which rewrites the strh's
 *    operand to z (the FIRST SI zero) and rewrites the strb's
 *    subreg:QI(z) operands to the RMW's HI zero temp. Net: uses swap,
 *    w's def (now feeding the strb's across the calls) homed r10 LATE.
 *  - The pointer spelling `*(u16 *)((u8 *)cmd + 2) = w;` KILLS the RMW
 *    (clean subreg store, fresh sp copy preserved) but cse STILL swaps:
 *    {SI/HI lookups -> first-assigned zero, QI lookups -> second}. Under
 *    that rule {strh <- first, strb's <- second} is forced, while the
 *    target needs {strh <- second-materialized, strb's <- first}.
 *  - Tried and failed: u16 w / u32 w (same swap), swapped assignment
 *    order w=0;z=0 (identical bytes), chained `gUnk_0202523C =
 *    gUnk_020253C8 = z` (also reorders the strb pair), fresh permuter
 *    run 50k iters on the pointer spelling (floor 60, no improvement).
 *  - Untried leads: make one zero a mode cse tables separately (a
 *    QImode-native pseudo -- no known agbcc C spelling), or make z's def
 *    non-constant at cse time without extra insns.
 * Current form = the pointer-cast spelling with z-then-w order.
 */

#include "global.h"

extern u16 gUnk_020251F0;
extern u32 gUnk_083FF79C[];
extern u8 gUnk_0202523C;
extern u8 gUnk_020253C8;
extern u8 gUnk_083393C0[];
u32 *sub_0800754C(u32 a);
u8 RequestObjPalette(u32 a);
u32 AddOamEntry(u32 a, u32 b);

void sub_080047E8(u8 a, u16 b)
{
    u16 cmd[2];
    u32 *res;
    u32 attr;
    u32 arg1;
    u8 x;
    u8 y;
    register u8 z asm("r10");
    u16 w;
    u16 *c;
    if (b != 0)
    {
        gUnk_020251F0 = b;
        c = cmd;
        z = 0;
        w = 0;
        c[0] = 0x68;
        *(u16 *)((u8 *)cmd + 2) = w;
        res = sub_0800754C(gUnk_083FF79C[a & 7]);
        x = (a & 8) >> 3;
        y = (a & 0x10) >> 4;
        if (res == 0)
        {
            return;
        }
        gUnk_020251F0 = b;
        attr = ((cmd[1] & 0xFF) | ((cmd[0] & 0x1FF) << 16)) | 0x80000000;
        arg1 = res[4] | (RequestObjPalette((u32) gUnk_083393C0) << 12);
        attr |= 0x04000100;
        gUnk_0202523C = z;
        gUnk_020253C8 = z;
        if (x != 0)
        {
            gUnk_0202523C = 1;
        }
        if (y != 0)
        {
            gUnk_020253C8 = 1;
        }
        AddOamEntry(attr, arg1);
    }
    else
    {
        cmd[0] = 0x68;
        cmd[1] = b;
        res = sub_0800754C(gUnk_083FF79C[a & 7]);
        x = (a & 8) >> 3;
        y = (a & 0x10) >> 4;
        if (res == 0)
        {
            return;
        }
        attr = ((cmd[1] & 0xFF) | ((cmd[0] & 0x1FF) << 16)) | 0x80000000;
        arg1 = res[4] | (RequestObjPalette((u32) gUnk_083393C0) << 12);
        if (x != 0)
        {
            attr |= 0x10000000;
        }
        if (y != 0)
        {
            attr |= 0x20000000;
        }
        AddOamEntry(attr, arg1);
    }
}
