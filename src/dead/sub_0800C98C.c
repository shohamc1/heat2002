#include "global.h"

extern s32 gUnk_083CA0B8;
extern s32 gUnk_083CA0B4;

struct Unk0800C98C {
    s32 unk00;
    s32 unk04;
    s32 unk08;
};

void sub_0800C98C(struct Unk0800C98C *v)
{
    long long p1;
    s32 p2;
    s32 *xp;
    s32 t1;

    v->unk08 = (v->unk08 << 20) >> 20;
    p1 = (-(((long long)gUnk_083CA0B8) * (((long long)v->unk00) - v->unk04))) >> 8;
    p2 = (-(((long long)gUnk_083CA0B4) * v->unk08)) >> 8;
    t1 = (s32)p1;
    t1 += (s32)p2;
    t1 >>= 1;
    v->unk08 = ((v->unk08 + t1) << 20) >> 20;
    xp = &v->unk00;
    v->unk00 = (*xp) + v->unk08;
}

extern s32 gUnk_083CA0C0;
extern s32 gUnk_083CA0BC;

struct Unk0800CA20 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
};

void sub_0800CA20(struct Unk0800CA20 *v)
{
    long long p1;
    s32 p2;
    s32 *xp;
    s32 t1;

    v->unk08 = (v->unk08 << 20) >> 20;
    p1 = (-(((long long)gUnk_083CA0C0) * (((long long)v->unk00) - v->unk04))) >> 8;
    p2 = (-(((long long)gUnk_083CA0BC) * v->unk08)) >> 8;
    t1 = (s32)p1;
    t1 += (s32)p2;
    t1 >>= 1;
    v->unk08 = ((v->unk08 + t1) << 20) >> 20;
    xp = &v->unk00;
    v->unk00 = (*xp) + v->unk08;
}

u32 sub_0800CAB4(u32 n)
{
  u32 t;
  u32 i;
  u32 lo;
  u32 hi;
  u32 one;
  u32 bit;
  u32 tt;
  if (n <= 1)
  {
    return n;
  }
  i = 0;
  t = n >> 1;
  for (; (lo = t) != 0; i++, t >>= 1)
  {
    ;
  }

  i = i >> 1;
  lo = 1 << i;
  hi = lo << i;
  i = i - 1;
  if (i == (-1))
  {
    return lo;
  }
  one = 1;
  do
  {
    bit = one << i;
    tt = bit << i;
    t = hi + (lo << (i + 1));
    t = t + tt;
    if (t <= n)
    {
      lo = lo + bit;
      hi = t;
    }
    i = i - 1;
  }
  while (i != (-1));
  return lo;
}
