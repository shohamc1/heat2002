
#include "global.h"
#include "variables.h"

extern u16 *gUnk_02039264;
u8 ModuleGetTrackTileType(s32 x, s32 y)
{
  int cellValue;
  int subIdx;
  s32 cellX;
  s32 cellY;
  u32 inX;
  u32 inY;
  u16 *map;
  do
  {
    cellX = (x - 1) >> 2;
    cellY = (y - 1) >> 2;
    inX = (x - 1) & 3;
    inY = (y - 1) & 3;
    ;
  }
  while (0);
  cellValue = (gUnk_02039264 + (gModule_TrackMapWidth[0] * cellY))[cellX];
  subIdx = inX + (inY * 4);
  return (gUnk_0203929C + (cellValue * 0x10))[subIdx];
}
