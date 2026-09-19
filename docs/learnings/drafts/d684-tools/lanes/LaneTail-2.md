# LaneTail-2 report — post-loop `if (flag != 0)` block (aligned indices ~574-960)

Baseline `v0.c`: **size 2010, hunks 6, sdiff 1059** (`cc` remats at 579/595/618; target has one, at 579, into r4).
No variant beat it. **Best file: `/tmp/LaneTail-2/v0.c`** (byte-identical to the repo baseline; 42 variants scored, each with its own `--workdir`).

| variant | source change (from baseline) | size | hunks | sdiff |
|---|---|---|---|---|
| h2_c_before_a | read `(*cc).c`/`w` before `(*cc).a`/`u` | 2010 | 8 | 1254 |
| h5_ccd_late | delete `ccd = (*cc).d;` | 2030 | 19 | 8765 |
| h8b_k1_ccd_dot | `(&gUnk_083FDA2C[ccd])->f0` -> `gUnk_083FDA2C[ccd].f0` | 2010 | 6 | 1139 |
| k1_revert | back to `d1=(s32)&u->unk55; v55=*(u8*)d1;` | 2006 | 8 | 1220 |
| k2_swap | `d1=k2; v55=*(u8*)k2;` swapped | 2006 | 8 | 1220 |
| k3_carrier | `k2` -> `k3` carrier | 2010 | 8 | 1268 |
| d1_no_dowhile | drop `do{}while(0)` on `hit2->unk88 -= d0>>14` | 2010 | 6 | 1084 |
| t1_tail_order | `hit2->unk55 = v55;` before `*(u8*)d1 = v55;` | 2010 | 6 | 1069 |
| g1_q0_spell | `-(d0*m0)/256` -> `(d0*m0)/-256` | 2010 | 10 | 1459 |
| p_swap_sin | swap the two `gUnk_0801CD08[]` loads | 2014 | 9 | 1468 |
| p_k1_early2 | hoist `ccd`+`k1` above `ang` | 2030 | 68 | 29849 |
| p_g_carrier_d1 | `d1=-g;` early then `d0=d1;` (remat 618 gone -> ccrem 580,596) | 2002 | 11 | 1979 |
| m1_1000_late | delete `d0 *= 1000;` | 2002 | 8 | 1983 |
| m7_cond_swap | swap `a1==gUnk_0202A550 \|\| gUnk_020020DC!=0` operands | 2010 | 8 | 1758 |
| m10_g_carrier | `k3=(*cc).g;` early then `d0=-k3;` (remat 618 gone -> 580,597) | 2010 | 10 | 1712 |
| m13_zero_local_d1 | `d1=0;` then store unk140 through `d1` | 2010 | 14 | 2473 |
| n2_glob_g | `d0 = -(&gUnk_0202CC90)->g;` | 2010 | 6 | 1099 |
| n1_glob_d | `ccd = (&gUnk_0202CC90)->d;` | 2038 | 21 | 9328 |
| n3/n4_glob_dg | direct-global for both `.d` and `.g` | 2030 | 20 | 8818 |
| h1_u_direct | `u0=(*cc).a; u=(s32)u0;` -> `u=(s32)(*cc).a;` | 2010 | 6 | 1059 (tie) |

Byte-identical/inert (2010/6/1059): `h3_w_direct`, `h6_ccd_early`, `h7_arrow_all` (`cc->a/c/d/g`),
`h8_k0_ccd`, `h10_neg_spell`, `k4_byte_ptr`, `k5_plain`, `z2_addr_of`, `p_d_early_k0late`,
`m2_hit2_first`, `m3_d1_cast`, `m4_ang_cast`, `m5_unk34_u8`, `m8_u0_cast`, `m9_ccd_u8`,
`m11_dowhile_braces`, `m12_u_local_ptr`, `m14_140_arrow_u0`.

## What I learned
The two 100-point hunks (extra `cc` remats at 595/618) are reload scratch-register choices, and no source
spelling moves them. `cc` is a compile-time constant (`ldr rN,=0x0202CC90`), so each use is a constant
remat whose register comes from `allocate_reload_reg`'s round-robin over the function-wide `spill_regs[]`
(reload1.c:5410-5545); ours lands in r6, which the sin-table `ldrsh r6,[r0,r3]` kills at 589, so
`find_equiv_reg` inheritance fails twice later, while the target's r4 survives and serves all four reads.
Source order in this block is oddly *rigid*: moving `ccd = (*cc).d;` up is a complete no-op (identical
object bytes), yet deleting it (h5) or hoisting its consumer (p_k1_early2) explodes to 2000-3000 sdiff —
RTL order is pinned by the address-computation chains, not by statement order. Two shapes do kill one
extra remat (`p_g_carrier_d1` ccrem {580,596}, even reaching size 2002; `m10_g_carrier` {580,597}), but
only via a carrier that reorders the block, costing 8-11 hunks and ~900-1000 sdiff: no (sdiff, hunks)
gain. The per-chain spill set is out of reach from here — it is a monotonically growing function-wide
union (`finish_spills`, reload1.c:3825-3830), and pins, compiler patches and rotation shifts were already
refuted in earlier passes; the only remaining lever is elsewhere in the function (stop r4 being
live/forbidden at 579, or change r6's round-robin slot), which is outside this lane.
