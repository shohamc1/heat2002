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
#include "functions.h"
#include "variables.h"
extern const u8 *const gTrackCueIconGfxList[];
extern u8 gTrackCueIconPalette[];
extern u32 gUnk_0836524C[];
extern u16 gUnk_020251F8;
extern u16 gUnk_02025254;
void DrawTrackCueIcon(u8 a, u16 b);


void DrawTrackCueIcon(u8 cueId, u16 angle)
{
    u16 cmd[2];
    u32 *tileEntry;
    u32 attr;
    u32 attr2;
    u8 hFlip;
    u8 vFlip;
    register u8 zero asm("r10");
    u16 zero2;
    u16 *cmdPtr;
    if (angle != 0)
    {
        gUnk_020251F0 = angle;
        cmdPtr = cmd;
        zero = 0;
        zero2 = 0;
        cmdPtr[0] = 0x68;
        *(u16 *)((u8 *)cmd + 2) = zero2;
        tileEntry = sub_0800754C(gTrackCueIconGfxList[cueId & 7]);
        hFlip = (cueId & 8) >> 3;
        vFlip = (cueId & 0x10) >> 4;
        if (tileEntry == 0)
        {
            return;
        }
        gUnk_020251F0 = angle;
        attr = ((cmd[1] & 0xFF) | ((cmd[0] & 0x1FF) << 16)) | 0x80000000;
        attr2 = tileEntry[4] | (RequestObjPalette((u32) gTrackCueIconPalette) << 12);
        attr |= 0x04000100;
        gUnk_0202523C = zero;
        gUnk_020253C8 = zero;
        if (hFlip != 0)
        {
            gUnk_0202523C = 1;
        }
        if (vFlip != 0)
        {
            gUnk_020253C8 = 1;
        }
        AddOamEntry(attr, attr2);
    }
    else
    {
        cmd[0] = 0x68;
        cmd[1] = angle;
        tileEntry = sub_0800754C(gTrackCueIconGfxList[cueId & 7]);
        hFlip = (cueId & 8) >> 3;
        vFlip = (cueId & 0x10) >> 4;
        if (tileEntry == 0)
        {
            return;
        }
        attr = ((cmd[1] & 0xFF) | ((cmd[0] & 0x1FF) << 16)) | 0x80000000;
        attr2 = tileEntry[4] | (RequestObjPalette((u32) gTrackCueIconPalette) << 12);
        if (hFlip != 0)
        {
            attr |= 0x10000000;
        }
        if (vFlip != 0)
        {
            attr |= 0x20000000;
        }
        AddOamEntry(attr, attr2);
    }
}


void LoadTrackCues(u8 trackIdx)
{
    gUnk_02025244 = 1;
    gTrackCueList = gUnk_0836524C[trackIdx];
    (*(s8 *)&gTrackCueId) = -1;
    if (gTrackCueList == 0)
        gUnk_02025244 = gTrackCueList;
}


void UpdateTrackCues(u32 car)
{
    u8 pad[0x28];
    u8 *cueRecord;
    u32 progress;
    u32 cueEnd;

    if (gUnk_02025244 == 0)
        return;
    cueRecord = *(u8 **)(car + 0x17C);
    progress = *(u32 *)(car + 0x50) & 0xFFFF;
    cueEnd = gUnk_02025254;
    if (progress <= cueEnd || cueEnd == 0) {
        if (*(s8 *)&gTrackCueId != -1 && gRaceEndState == 0)
            DrawTrackCueIcon(gTrackCueId, gUnk_020251F8);
    }
    progress = *(u32 *)(car + 0x50) & 0xFFFF;
    if (progress >= *(u16 *)cueRecord) {
        do {
            gTrackCueId = cueRecord[2];
            gUnk_020251F8 = *(u16 *)(cueRecord + 4);
            gUnk_02025254 = *(u16 *)(cueRecord + 6);
            cueRecord += 8;
            *(u32 *)(car + 0x17C) = cueRecord;
        } while (progress >= *(u16 *)cueRecord);
    }
}

