#include "global.h"

struct Ent43110 {
  s32 f00;
  s32 f04;
  s32 f08;
  u8 pad0C[0x28 - 0x0C];
  s32 f28;
  s32 f2C;
  s32 f30;
};

s32 sub_08343948(struct Ent43110 *ent);

void sub_08343110(struct Ent43110 *e)
{
  sub_08343948(e);
  e->f00 = e->f00 + e->f28;
  e->f04 = e->f04 + e->f2C;
  e->f08 = e->f08 + e->f30;
}
