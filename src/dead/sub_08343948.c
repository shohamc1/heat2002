#include "global.h"
#include "variables.h"
struct Seg
{
  s32 f00;
  s32 f04;
  s32 f08;
  s32 f0C;
  s32 f10;
  s32 f14;
};
struct Box
{
  s32 f00;
  s32 f04;
  s32 f08;
  s32 f0C;
};
struct Hit
{
  s32 f00;
  s32 f04;
  s32 f08;
  u8 f0C;
  u8 f0D;
  u8 f0E;
  u8 f0F;
  s32 f10;
};
struct Ent
{
  s32 f00;
  s32 f04;
  s32 f08;
  u8 pad0C[0x28 - 0x0C];
  s32 f28;
  u8 pad2C[0x30 - 0x2C];
  s32 f30;
};
long long sub_08344D20(long long a, long long b);
u16 *ModuleGetWallListAt(s32 a, s32 b);
u8 sub_083437A0(struct Seg *a, struct Box *b, struct Box *c, struct Hit *d, u16 *e);
s32 sub_08343948(struct Ent *ent)
{
  struct Seg seg;
  struct Box bounds;
  s32 new_var;
  struct Hit out;
  u16 *walls;
  s32 mx2;
  s32 mz2;
  s32 mx;
  s32 mz;
  s32 mx3;
  s32 mz3;
  s32 new_var2;
  s32 dot;
  long long q1;
  long long q2;
  if (gModule_GameMode == 7)
  {
    goto miss;
  }
  seg.f00 = ent->f00 >> 16;
  seg.f04 = ent->f08 >> 16;
  new_var = ent->f28;
  seg.f08 = (ent->f00 + ent->f28) >> 16;
  seg.f0C = (ent->f08 + ent->f30) >> 16;
  seg.f10 = new_var >> 8;
  seg.f14 = ent->f30 >> 8;
  mx = seg.f08;
  if (seg.f00 < mx)
  {
    mx = seg.f00;
  }
  bounds.f00 = mx;
  mz = seg.f0C;
  if (seg.f04 < mz)
  {
    mz = seg.f04;
  }
  bounds.f08 = mz;
  mx2 = seg.f00;
  mx = seg.f08;
  mx3 = mx;
  if (mx2 > mx3)
  {
    mx3 = mx2;
  }
  bounds.f04 = mx3;
  mz2 = seg.f04;
  mz = seg.f0C;
  mz3 = mz;
  if (mz2 > mz3)
  {
 do { mz3 = mz2; } while (0);
  }
  bounds.f0C = mz3;
  walls = ModuleGetWallListAt(seg.f00, seg.f04);
  if (sub_083437A0(&seg, &bounds, &bounds, &out, walls) == 0)
  {
    miss:
    return 0;

  }
  dot = (seg.f10 * out.f04) + (seg.f14 * out.f08);
  new_var2 = out.f08;
  q1 = sub_08344D20(out.f04, dot) >> 21;
  q2 = sub_08344D20(new_var2, dot) >> 21;
  q1 = (q1 * 3) >> 2;
  q2 = (q2 * 3) >> 2;
  ent->f28 -= q1;
  ent->f30 -= q2;
  return dot;
}
