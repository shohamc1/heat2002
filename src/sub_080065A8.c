
#include "global.h"
#include "data.h"
extern u32 gUnk_08364B08[];
extern u8 *gUnk_08365340;
void sub_080065A8(u8 *s)
{
  u16 *dest;
  u8 *p;
  u8 *q;
  s32 len;
  u8 i;
  u16 color;
  u32 idx;
  u8 t;
  u16 *e;
  u32 c;
  dest = (u16 *) (gUnk_08364B08[0] + 0x40);
  do
  {
    color = 0xF0 << 8;
  }
  while (0);
  i = 0;
  q = s;
  len = 0;
  while ((*q) != 0)
  {
    q++;
    len++;
  }

  for (; i < ((0x1E - len) / 2); i++, dest++)
  {
    c = (*gUnk_08365340) - 0x20;
    t = c;
    idx = (((t >> 5) << 22) + 0x600000u) >> 16;
    e = &gUnk_08332DC8[idx + (t & 0x1F)];
    dest[0] = color | gUnk_08333208[e[0]];
    dest[0x20] = color | gUnk_08333208[e[0x20]];
  }

  c = *s;
  p = s + 1;
  if (c != 0)
  {
    do
    {
      t = c - 0x20;
      idx = (((t >> 5) << 22) + 0x600000u) >> 16;
      e = &gUnk_08332DC8[idx + (t & 0x1F)];
      dest[0] = color | gUnk_08333208[e[0]];
      dest[0x20] = color | gUnk_08333208[e[0x20]];
      dest++;
      i++;
      c = *p;
      p++;
    }
    while (c != 0);
  }
  for (; i < 0x20; i++, dest++)
  {
    t = (*gUnk_08365340) - 0x20;
    idx = (((t >> 5) << 22) + 0x600000u) >> 16;
    e = &gUnk_08332DC8[idx + (t & 0x1F)];
    dest[0] = color | gUnk_08333208[e[0]];
    dest[0x20] = color | gUnk_08333208[e[0x20]];
  }

}
