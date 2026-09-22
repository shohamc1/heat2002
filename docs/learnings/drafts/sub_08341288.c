/*
 * sub_08341288 — NEAR-MISS (session 4, 2026-09-22): 804/804 bytes,
 * 395/401 instructions, TWO hunks; both root-caused to RELOAD/REMAT
 * micro-behavior, not source shape (~20 spellings tried, all invariant):
 *
 * Q-BLOCK (0x083414fa): target {addr=r1, q=r0}; ours {addr=r0, q=r1}.
 * First-cse RTL with this source: [q=99 (687), const 336 (692),
 * addr=car+336 (693), strb (696)]. q's pseudo carries REG_EQUAL(const
 * 99) -> reload rematerializes it AT THE STRB (deleting the early def),
 * and find_reloads processes the MEM's address reload (operand 0)
 * before the value (operand 1), so addr takes r0 and the remat'd q
 * gets r1. Target keeps q in r0 across BOTH uses (strb + q+255 RMW)
 * = no remat = local-alloc homed it; no agbcc C shape found that keeps
 * a 2-use const pseudo un-remat'd (asm pins cascade, +12B).
 *
 * TAIL (0x08341568): the *p4e zero must materialize BEFORE the a5
 * sp-chain. Post-cse RTL: any early source-level zero (z4e def insn
 * 807, before the a5 stmt) is deleted and the store's operand is
 * rewritten to the LATER HI zero (insn 814, the 0x38 store's) — the
 * cse const-0 mode-table cross-wiring (same family as sub_080047E8,
 * which was solved with an asm pin; pins here cascade).
 *
 * Permuter machinery for RAM-linked functions is FIXED this session
 * (EWRAM-base link both sides + case-body oracle repair, commit
 * 1d7bc94). Base floors at STRUCT_FLOOR=1000 (the tail is a true
 * reordering); 2800 iterations found nothing — the fixes need
 * def-early/store-late splits that are not statement permutations.
 */
#include "global.h"

extern u8 gUnk_0203916C;
extern u8 gUnk_0203DCF0;
extern u8 gUnk_0203D4E8;
extern u8 gUnk_0203DFB0;
extern u8 gUnk_0203D520[];
extern u8 gUnk_0203DDE8[];
extern u8 gUnk_020390EC;
extern u32 gUnk_02026E1C[][3];
extern u32 gUnk_02027500[];
extern u32 gUnk_02027578[];
extern u32 gUnk_020275F0[];
extern u8 gUnk_0202713E[];
extern u8 gUnk_0202714A[];
extern u8 gUnk_02027154[];

extern void sub_083432EC(u8 *, s32);

void sub_08341288(u8 idx, u8 *car, s32 a3, s32 a4, s32 a5)
{
    s32 t;
    s32 w;
    u16 h;
    u8 i;
    u8 *p4c;
    u8 *pe4;
    u8 *pe8;
    u8 *pec;
    u8 *p7d;
    u8 *p4e;
    s32 z4e;

    if (gUnk_0203916C == 4)
        *(u8 *)(car + 0x162) = 0;
    *(u8 *)(car + 0x18E) = (t = 0);
    *(u8 *)(car + 0x175) = t;
    gUnk_0203DCF0 = t;
    *(u8 *)(car + 0x180) = t;
    *(u8 *)(car + 0x176) = t;
    *(u8 *)(car + 0x168) = t;
    gUnk_0203D4E8 = t;
    *(u8 *)(car + 0x166) = 1;
    *(u8 *)(car + 0x167) = t;
    *(s32 *)(car + 0x00) = a3;
    *(s32 *)(car + 0x08) = a4;
    *(u16 *)(car + 0x34) = (h = (u16)t, a5);
    *(s32 *)(car + 0x2C) = t;
    *(s32 *)(car + 0x28) = t;
    *(u16 *)(car + 0x40) = h;
    *(u8 *)(car + 0x3E) = h;
    *(u8 *)(car + 0x55) = h;
    *(u8 *)(car + 0x4D) = h;
    *(u8 *)(car + 0x174) = h;
    *(s32 *)(car + 0x58) = gUnk_02026E1C[idx][0];
    *(u8 *)(car + 0x7C) = h;
    *(u8 *)(car + 0x84) = 1;
    *(s32 *)(car + 0x30) = t;
    *(s32 *)(car + 0x88) = t;
    *(u16 *)(car + 0xA2) = t;
    *(s32 *)(car + 0x8C) = t;
    *(s32 *)(car + 0x90) = t;
    *(s32 *)(car + 0x94) = t;
    *(s32 *)(car + 0x98) = t;
    *(s32 *)(car + 0x9C) = 0xB400;
    if (gUnk_0203916C == 15 && gUnk_0203DFB0 == 3 && car == gUnk_0203D520)
        *(s32 *)(car + 0x9C) = 0x5000;
    if (gUnk_0203916C != 5 && gUnk_0203916C != 17)
        *(s32 *)(car + 0x16C) = 0;
    *(u8 *)(car + 0x170) = (w = 0);
    *(u8 *)(car + 0x171) = w;
    *(u8 *)(car + 0x172) = w;
    sub_083432EC(car + 0x128, a5);
    *(s32 *)(car + 0x134) = w;
    *(s32 *)(car + 0x138) = -1;
    *(u8 *)(car + 0x173) = w;
    *(u8 *)(car + 0x171) = w;

    i = 0;
    p4c = car + 0x4C;
    pe4 = car + 0xE4;
    pe8 = car + 0xE8;
    pec = car + 0xEC;
    p7d = car + 0x7D;
    p4e = car + 0x4E;

    do {
        gUnk_0203DDE8[i] = 0;
        i++;
    } while (i != 8);

    if (gUnk_0203916C == 15) {
        switch (gUnk_0203DFB0) {
        case 0:
            *p4c = 1;
            break;
        case 1:
            *p4c = 4;
            break;
        case 2:
            *p4c = 5;
            break;
        case 3:
            *p4c = 0x28;
            break;
        case 6:
            *p4c = 0x28;
            break;
        case 10:
            *p4c = 0xF;
            break;
        case 11:
            *p4c = 0xF;
            break;
        case 12:
            *p4c = 0x55;
            break;
        case 13:
            *p4c = 0x12;
            break;
        case 14:
            *p4c = 5;
            break;
        case 15:
            *p4c = 0x14;
            break;
        default:
            *p4c = 0;
            break;
        }
    } else {
        *p4c = 0;
    }
    if ((u8)(gUnk_0203916C - 3) > 1)
        *p4c = *p4c - 1;

    *(s32 *)(car + 0x50) = 0;
    *(s32 *)(car + 0x15C) = 0x12C;
    *(s32 *)(car + 0x0C) = 0;
    *(s32 *)(car + 0x14) = 0;
    *(u8 *)(car + 0x110) = 0;
    *(s32 *)(car + 0x140) = 0;
    *(s32 *)(car + 0x144) = 0;
    *(s32 *)(car + 0x13C) = 0;
    *(s32 *)(car + 0x148) = 0;
    *(s32 *)(car + 0x14C) = 0;
    {
        s32 q;
        q = 0x63;
        *(u8 *)(car + 0x150) = q;
        *(s32 *)(pe4) = gUnk_02027500[car[q = q + 255]];
        *(s32 *)(pe8) = gUnk_02027578[car[q]];
        *(s32 *)(pec) = gUnk_020275F0[car[q]];
    }

    if (gUnk_020390EC == 0 && idx != 0 && gUnk_0203916C != 2) {
        *(s32 *)(pe4) = (s32)gUnk_0202713E;
        *(s32 *)(pe8) = (s32)gUnk_0202714A;
        *(s32 *)(pec) = (s32)gUnk_02027154;
        *(s32 *)(pe4) = gUnk_02027500[0];
        *(s32 *)(pe8) = gUnk_02027578[0];
        *(s32 *)(pec) = gUnk_020275F0[0];
    }

    *(s32 *)(car + 0x158) = 0;
    *p7d = 0;
    z4e = 0;
    *(u16 *)(car + 0x36) = a5;
    *(u16 *)(car + 0x38) = 0;
    *(u16 *)(car + 0x160) = 0;
    *p4e = z4e;
    *(u16 *)(car + 0x3C) = 0;
}

