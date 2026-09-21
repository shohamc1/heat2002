/*
 * NEAR-MISS (316/316 bytes, ~154 diff lines, all register allocation):
 * the winning combination so far is [volatile u16 *snd local] + [int
 * new_var for the gUnk_0202EEF4 = 0 store] + [one u32 v reused in the
 * t1-block condition (v & 0x30), which agbcc re-reads as a byte from
 * 0x04000128 -- its volatile-pseudo quirk].  Residual: target holds the
 * 0x04000128 address in r7 across the body (we reload it), EDD0 in r6 vs
 * our r7/r8, EF40 in r4 vs our r5, EEF4 in r5 vs our r6.  The permuter
 * (130k iters) could not close the register permutation.
 */


#include "global.h"
extern volatile u16 gUnk_0202ED78;
extern u8 gUnk_0202EDD0;
extern u8 gUnk_0202EFA0[];
extern u8 gUnk_0202EEF4;
extern u16 gUnk_0202EF40[];
extern u8 gUnk_0202EF90;
extern u8 gUnk_020020AC;
void sub_08011A50(void);
void sub_08016E30(void);
void sub_08016E14(u32 a, u32 b);
void sub_0800048C(void);
void sub_0800F818(u16 a);
void sub_08011B08(void)
{
  u8 ctr;
  volatile u16 *snd;
  u32 v;
  u16 val;
  int new_var;
  u8 m;
  u32 t1;
  u32 t2;
  u32 t3;
  u32 t4;
  sub_08011A50();
  ctr = 0;
  new_var = 0;
  snd = &gUnk_0202ED78;
  m = 0xFF;
  do
  {
    if ((*(volatile u8 *)0x04000128 & 0x30) == 0)
    {
      sub_08016E30();
    }
    else
    {
      sub_08016E14(1, 0x80);
    }
    sub_0800048C();
    v = *((volatile u32 *) 0x04000128);
    val = ((((v << 26) >> 30) + 1) << 12) | (0x80 << 1);
    val |= m & (gUnk_0202EDD0 + 1);
    *snd = val;
    sub_0800F818(*snd);
    gUnk_0202EFA0[2] |= m;
    gUnk_0202EFA0[6] |= m;
    gUnk_0202EFA0[10] |= m;
    gUnk_0202EFA0[14] |= m;
    gUnk_0202EEF4 = new_var;
    t1 = gUnk_0202EF40[0] >> 12;
    if (t1 == 1)
    {
      gUnk_0202EFA0[2] = t1;
      gUnk_0202EEF4 = t1;
      if ((v & 0x30) != 0)
      {
        gUnk_0202EDD0 = gUnk_0202EF40[0] - 1;
      }
      t2 = gUnk_0202EF40[4] >> 12;
      if (t2 == 2)
      {
        gUnk_0202EFA0[6] = t1;
        gUnk_0202EEF4 = t2;
        t3 = gUnk_0202EF40[8] >> 12;
        if (t3 == 3)
        {
          gUnk_0202EFA0[10] = t1;
          gUnk_0202EEF4 = t3;
          t4 = gUnk_0202EF40[12] >> 12;
          if (t4 == 4)
          {
            gUnk_0202EFA0[14] = t1;
            gUnk_0202EEF4 = t4;
          }
        }
      }
    }
    gUnk_0202EF90 = ((*((volatile u32 *) 0x04000128)) << 26) >> 30;
    gUnk_020020AC = gUnk_0202EEF4;
    if (((u8) gUnk_0202EEF4) <= 1)
    {
      ctr--;
    }
    gUnk_0202EF40[0] = 0;
    gUnk_0202EF40[4] = 0;
    gUnk_0202EF40[8] = 0;
    gUnk_0202EF40[12] = 0;
    ctr++;
  }
  while (ctr != 5);
}
