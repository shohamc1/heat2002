
#include "global.h"
#include "variables.h"

extern u16 *gUnk_02039264;
extern u8 *gUnk_0203929C;
u8 sub_08343464(s32 x, s32 y)
{
  int new_var2;
  int new_var;
  s32 tx;
  s32 ty;
  u32 sx;
  u32 sy;
  u16 *map;
  do
  {
    tx = (x - 1) >> 2;
    ty = (y - 1) >> 2;
    sx = (x - 1) & 3;
    sy = (y - 1) & 3;
    ;
  }
  while (0);
  new_var2 = (gUnk_02039264 + (gUnk_02039220[0] * ty))[tx];
  new_var = sx + (sy * 4);
  return (gUnk_0203929C + (new_var2 * 0x10))[new_var];
}
