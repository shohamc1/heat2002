/*
 * sub_08344A20 — NEAR-MISS UPDATE 2026-09-22 (session 2): 312/316 bytes,
 * 151/151 instructions, structure COMPLETE. Port of the sub_08011B08
 * session-2 shape: pins ctr=r8, e004=r6, e110=r5; m UNPINNED; NO v local;
 * KEYINPUT via direct volatile casts (shared addr pseudo); head test
 * non-volatile; t1..t4 direct `gUnk_0203E160[N] >> 12` mentions (E160
 * addr cse-shared, homed r4); `*e004 = (s32)gUnk_0203E160[0] - 1` keeps
 * the u16 subtract on the live halfword reg. ONE remaining delta class:
 * the {m, keyaddr} r7/r9 SWAP (target: keyaddr=r7 direct ldr + `ldrb
 * [r7]` byte re-read + m=r9 with FIVE per-use `mov r0,r9` copies; ours:
 * m=r7 direct + keyaddr=r9 ldr/stash + 2 coalesced copies). Pinning m=r9
 * gives the stash but COALESCES the copies (reload inheritance) — 304B.
 * Same wall as sub_08011B08; see that draft's header for the probes.
 */
#include "global.h"
extern volatile u16 gUnk_0203DFB8;
extern u8 gUnk_0203E004;
extern u8 gUnk_0203E1C0[];
extern u8 gUnk_0203E110;
extern u16 gUnk_0203E160[];
extern u8 gUnk_0203E1B0;
extern u8 gUnk_020390BC;
void sub_08344968(void);
void sub_08344B74(void);
void sub_08344B68(u32 a, u32 b);
void sub_08339B4C(void);
void sub_083448B0(u16 a);
void sub_08344A20(void)
{
  register u8 ctr asm("r8");
  volatile u16 *snd;
  register u8 *e004 asm("r6");
  register u8 *e110 asm("r5");
  register u8 m asm("r9");
  u16 val;
  int new_var;
  u32 t1;
  u32 t2;
  u32 t3;
  u32 t4;
  sub_08344968();
  ctr = 0;
  new_var = 0;
  snd = &gUnk_0203DFB8;
  m = 0xFF;
  do
  {
    if ((*(u8 *)0x04000128 & 0x30) == 0)
    {
      sub_08344B74();
    }
    else
    {
      sub_08344B68(1, 0x80);
    }
    sub_08339B4C();
    val = ((((*((volatile u32 *) 0x04000128) << 26) >> 30) + 1) << 12) | (0x80 << 1);
    e004 = &gUnk_0203E004;
    val |= m & (*e004 + 1);
    *snd = val;
    sub_083448B0(*snd);
    gUnk_0203E1C0[2] |= m;
    gUnk_0203E1C0[6] |= m;
    gUnk_0203E1C0[10] |= m;
    gUnk_0203E1C0[14] |= m;
    e110 = &gUnk_0203E110;
    *e110 = new_var;
    t1 = gUnk_0203E160[0] >> 12;
    if (t1 == 1)
    {
      gUnk_0203E1C0[2] = t1;
      *e110 = t1;
      if ((*(volatile u8 *) 0x04000128 & 0x30) != 0)
      {
        *e004 = (s32)gUnk_0203E160[0] - 1;
      }
      t2 = gUnk_0203E160[4] >> 12;
      if (t2 == 2)
      {
        gUnk_0203E1C0[6] = t1;
        *e110 = t2;
        t3 = gUnk_0203E160[8] >> 12;
        if (t3 == 3)
        {
          gUnk_0203E1C0[10] = t1;
          *e110 = t3;
          t4 = gUnk_0203E160[12] >> 12;
          if (t4 == 4)
          {
            gUnk_0203E1C0[14] = t1;
            *e110 = t4;
          }
        }
      }
    }
    gUnk_0203E1B0 = ((*((volatile u32 *) 0x04000128)) << 26) >> 30;
    gUnk_020390BC = *e110;
    if (((u8) *e110) <= 1)
    {
      ctr--;
    }
    gUnk_0203E160[0] = 0;
    gUnk_0203E160[4] = 0;
    gUnk_0203E160[8] = 0;
    gUnk_0203E160[12] = 0;
    ctr++;
  }
  while (ctr != 5);
}
