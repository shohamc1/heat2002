#include "global.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

struct EntityB1A4
{
  u8 pad0[0x18];
  s32 unk18;
};
void sub_0800B1A4(struct EntityB1A4 *e)
{
  u32 *spr;
  u32 idx;
  u32 attr;
  u32 t;
  int new_var;
  u32 x;
  u32 arg1;
  if (gFadeActive == 0)
  {
    if (((e->unk18 == 0) || (e->unk18 == 0x14)) || (e->unk18 == 0x28))
    {
      if ((gOptions[3] != 0) && (gIsDemo == 0))
      {
        m4aSongNumStart(0x17);
      }
    }
    new_var = 0x40;
    x = 0x68;
    if (e->unk18 == 0x3C)
    {
      if ((gOptions[3] != 0) && (gIsDemo == 0))
      {
        m4aSongNumStart(0x15);
      }
    }
    idx = (u8) (((u8) (e->unk18 - 0x3C)) % 0x17);
    if (e->unk18 > 0x3C)
    {
      spr = RequestObjTiles16(gSplashSpriteFrames[idx]);
      if (spr != 0)
      {
        attr = x << 0x10;
        attr = attr | new_var;
        attr = attr | (0x80 << 0x18);
        t = (RequestObjPalette((u32) gSplashSpritePalette) << 12) | 0x400;
        arg1 = spr[4] | t;
        AddOamEntry(attr, arg1);
      }
    }
    if (e->unk18 > 0x2D)
    {
      if (gGameMode == 9)
      {
        gGameMode = 6;
      }
      if (gGameMode == 0x0D)
      {
        gGameMode = 0x0C;
      }
      if (gGameMode == 0x0E)
      {
        gGameMode = 2;
      }
      if (gGameMode == 0x0F)
      {
        gGameMode = 0x10;
      }
      if (gGameMode == 0x11)
      {
        gGameMode = 5;
      }
      gRaceStarted = 1;
    }
    e->unk18 = e->unk18 + 1;
    if (e->unk18 == 0x7A)
    {
      RemoveTask((u32)e);
      FreeTask((u32)e);
    }
    if (gRaceStarted == 0)
    {
      WaitForVBlank();
    }
  }
}
