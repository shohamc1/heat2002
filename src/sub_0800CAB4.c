#include "global.h"
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
