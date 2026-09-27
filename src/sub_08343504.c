
#include "global.h"
#include "variables.h"

struct WallRec;
struct Pt;
extern u32 gUnk_0203DE68;
extern u8 gUnk_0202AED4[];
void sub_08343504(u32 i)
{
  u32 four;
  u32 eight;
  u8 *new_var;
  u32 twelve;
  u8 *new_var2;
  u32 sixteen;
  u8 **new_var3;
  new_var3 = &new_var2;
  if (1)
  {
    four = 4;
    eight = 8;
    twelve = 0xC;
    sixteen = 0x10;
    gUnk_0203DE60 = (struct WallRec *)*((u32 *) ((i * 20) + ((new_var2 = gUnk_0202AED4) + four)));
    new_var = new_var2;
    gUnk_0203DE64 = (struct Pt *)*((u32 *) ((*new_var3) + ((i * 2) * 10)));
    gUnk_0203DE68 = *((u32 *) ((i * 20) + (new_var2 + eight)));
  }
  gUnk_0203DE8C = (u16 *)*((u32 *) ((i * 20) + ((*new_var3) + twelve)));
  gUnk_0203DE88 = (u16 *)*((u32 *) ((i * 20) + (new_var + sixteen)));
}
