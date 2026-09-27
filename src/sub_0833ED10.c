#include "global.h"
#include "variables.h"

void sub_0833ED10(void)
{
  u16 *dest;
  u8 i;
  u8 j;
  u32 stride;
  u32 off;
  dest = (u16 *) (*(u8 **)&gModule_TextLayerMapPtr + 0x3A8);
  for (i = 0; i != 6; i++)
  {
    stride = (i + 8) * 68;
    for (j = 0; j != 10; j++)
    {
      off = 2 * (((i + 8) * 68) + j + 0x33);
      *dest = gModule_FontTileEntries[*(u16 *)((u8 *)gUnk_02021594 + off)] | 0xE000;
      dest++;
    }

    dest += 22;
  }

  dest = (u16 *) (*(u8 **)&gModule_TextLayerMapPtr + 0x3A8);
  if (gModule_DamagePitsEnabled == 0)
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
