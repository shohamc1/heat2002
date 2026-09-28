#include "global.h"
#include "data.h"
#include "functions.h"
#include "car.h"

struct EntityB658
{
  u8 pad00[0x08];
  s32 unk08;
  u8 pad0C[0x18 - 0x0C];
  s32 unk18;
  s32 unk1C;
  u8 pad20[0x34 - 0x20];
  u8 unk34;
};
extern const u8 *const gDraftStreakFrames[];
extern u8 gDraftStreakPalette[];
u32 WorldToScreen(s32 x, s32 y, s32 *out);
u32 *RequestObjTiles1Compressed(u32 a);
void sub_0800B658(struct EntityB658 *e)
{
  struct Car *car;
  s32 pos[2];
  s32 v0;
  s32 v1;
  s32 angle;
  s32 sin;
  s32 cos;
  s32 rel;
  s32 dx;
  s32 dy;
  u32 *spr;
  u32 attr;
  u32 t;
  u32 arg1;
  s32 old;
  car = &gCars[e->unk34];
  v0 = car->nextCornerX[e->unk1C + 2];
  v1 = car->nextCornerZ[e->unk1C + 2];
  angle = car->heading >> 8;
  sin = gSinTable[angle];
  cos = gSinTable[angle + 0x40];
  rel = (dy = e->unk08 + 0xFFF60000);
  dx = (-(rel * sin)) >> 8;
  dy = (dy * cos) >> 8;
  v0 = v0 + dx;
  v1 = v1 + dy;
  if ((WorldToScreen(v0, v1, pos) << 0x18) != 0)
  {
    old = pos[0];
    pos[0] = old - 4;
    pos[1] = pos[1] - 6;
    if (((((u32) (old + 0x1B)) <= 0x10E) && (pos[1] <= 0x9F)) && (pos[1] > (-0x20)))
    {
      spr = RequestObjTiles1Compressed(gDraftStreakFrames[e->unk18 & 0xF]);
      if (spr != 0)
      {
        attr = (pos[1] & 0xFF) | ((pos[0] & 0x1FF) << 0x10);
        t = (RequestObjPalette((u32) gDraftStreakPalette) << 12) | 0x800;
        arg1 = spr[4] | t;
        AddOamEntry(attr, arg1);
      }
    }
  }
  e->unk18 = e->unk18 + 1;
  e->unk08 = e->unk08 + 0x10000;
  if (e->unk18 == 0x10)
  {
    RemoveTask((u32)e);
    FreeTask((u32)e);
  }
}
