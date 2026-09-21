#include "global.h"

extern u8 *gUnk_020251B8;
extern u8 gUnk_0203E0E0;
extern u16 gUnk_02022254[];
extern u16 gUnk_02021594[];
void sub_0833ED10(void)
{
  u16 *dest;
  u8 i;
  u8 j;
  u32 stride;
  dest = (u16 *) (gUnk_020251B8 + 0x3A8);
  for (i = 0; i != 6; i++)
  {
    stride = (i + 8) * 68;
    for (j = 0; j != 10; j++)
    {
      *dest = gUnk_02022254[gUnk_02021594[(((i + 8) * 68) + j) + 0x33]] | 0xE000;
      dest++;
    }

    dest += 22;
  }

  dest = (u16 *) (gUnk_020251B8 + 0x3A8);
  if (gUnk_0203E0E0 == 0)
  {
    for (i = 0; i != 6; i++)
    {
      for (j = 0; j != 4; j++)
      {
        *dest = 0x47;
        dest++;
      }

      dest += 28;
    }

  }
}
