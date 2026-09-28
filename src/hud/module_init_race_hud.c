#include "global.h"
#include "variables.h"

void ModuleDrawHudLabels(void)
{
  u16 *dst;
  u8 row;
  u8 col;
  u32 rowStride;
  u32 glyphOff;
  dst = (u16 *) (*(u8 **)&gModule_TextLayerMapPtr + 0x3A8);
  for (row = 0; row != 6; row++)
  {
    rowStride = (row + 8) * 68;
    for (col = 0; col != 10; col++)
    {
      glyphOff = 2 * (((row + 8) * 68) + col + 0x33);
      *dst = gModule_FontTileEntries[*(u16 *)((u8 *)gUnk_02021594 + glyphOff)] | 0xE000;
      dst++;
    }

    dst += 22;
  }

  dst = (u16 *) (*(u8 **)&gModule_TextLayerMapPtr + 0x3A8);
  if (gModule_DamagePitsEnabled == 0)
  {
    for (row = 0; row != 6; row++)
    {
      for (col = 0; col != 4; col++)
      {
        *dst = 0x47;
        dst++;
      }

      dst += 28;
    }

  }
}
