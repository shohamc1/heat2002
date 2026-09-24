#include "global.h"

struct EntityB1A4
{
  u8 pad0[0x18];
  s32 unk18;
};
extern u8 gUnk_02022E14;
extern u8 gOptions[];
extern u8 gIsDemo;
extern u32 gUnk_083FF5B0[];
extern u8 gUnk_08330AD4[];
extern u8 gUnk_0200215C;
extern u8 gUnk_020020C4;
void m4aSongNumStart(u16 idx);
u32 *sub_0800754C(u32 a);
u8 RequestObjPalette(u32 a);
u32 AddOamEntry(u32 a, u32 b);
void RemoveTask(struct EntityB1A4 *e);
void FreeTask(struct EntityB1A4 *e);
void WaitForVBlank(void);
void sub_0800B1A4(struct EntityB1A4 *e)
{
  u32 *spr;
  u32 idx;
  u32 attr;
  u32 t;
  int new_var;
  u32 x;
  u32 arg1;
  if (gUnk_02022E14 == 0)
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
      spr = sub_0800754C(gUnk_083FF5B0[idx]);
      if (spr != 0)
      {
        attr = x << 0x10;
        attr = attr | new_var;
        attr = attr | (0x80 << 0x18);
        t = (RequestObjPalette((u32) gUnk_08330AD4) << 12) | 0x400;
        arg1 = spr[4] | t;
        AddOamEntry(attr, arg1);
      }
    }
    if (e->unk18 > 0x2D)
    {
      if (gUnk_0200215C == 9)
      {
        gUnk_0200215C = 6;
      }
      if (gUnk_0200215C == 0x0D)
      {
        gUnk_0200215C = 0x0C;
      }
      if (gUnk_0200215C == 0x0E)
      {
        gUnk_0200215C = 2;
      }
      if (gUnk_0200215C == 0x0F)
      {
        gUnk_0200215C = 0x10;
      }
      if (gUnk_0200215C == 0x11)
      {
        gUnk_0200215C = 5;
      }
      gUnk_020020C4 = 1;
    }
    e->unk18 = e->unk18 + 1;
    if (e->unk18 == 0x7A)
    {
      RemoveTask(e);
      FreeTask(e);
    }
    if (gUnk_020020C4 == 0)
    {
      WaitForVBlank();
    }
  }
}
