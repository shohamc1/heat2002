
#include "global.h"
#include "variables.h"
extern u32 gUnk_0203D68C[];
void sub_0833E1F4(void)
{
  u16 *p2;
  u16 *p1;
  u8 i;
  u8 v8;
 do { if (gUnk_020390D4 == 0) { return; } if (gUnk_020391F0 != 0) { return; } v8 = gUnk_0203916C[0] - 3; p1 = &gUnk_0203B858[0]; p2 = &gUnk_0203B6D4[0]; if (v8 <= 2) { for (i = 0; i != gUnk_020390BC[0]; i++) { gUnk_0203D68C[i * 100] = gUnk_0203D68C[i * 100] + 1; } } *p1 += 40; } while (0);
  if ((*p1) > 999)
  {
    *p1 -= 1000;
    gUnk_0203B6A8[0] = gUnk_0203B6A8[0] + 1;
    if (gUnk_0203B6A8[0] > 59)
    {
      gUnk_0203B6A8[0] = gUnk_0203B6A8[0] - 60;
      gUnk_0203B6C8[0] = gUnk_0203B6C8[0] + 1;
    }
  }
  *p2 += 40;
  if ((*p2) > 999)
  {
    *p2 -= 1000;
    gUnk_0203B6D0[0] = gUnk_0203B6D0[0] + 1;
    if (gUnk_0203B6D0[0] > 59)
    {
      gUnk_0203B6D0[0] = gUnk_0203B6D0[0] - 60;
      gUnk_0203B704[0] = gUnk_0203B704[0] + 1;
    }
  }
}
