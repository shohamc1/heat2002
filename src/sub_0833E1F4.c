
#include "global.h"
extern u8 gUnk_020390D4;
extern u8 gUnk_020391F0;
extern u8 gUnk_0203916C;
extern u16 gUnk_0203B858;
extern u16 gUnk_0203B6D4;
extern u8 gUnk_020390BC;
extern u32 gUnk_0203D68C[];
extern u16 gUnk_0203B6A8;
extern u16 gUnk_0203B6C8;
extern u16 gUnk_0203B6D0;
extern u16 gUnk_0203B704;
void sub_0833E1F4(void)
{
  u16 *p2;
  u16 *p1;
  u8 i;
  u8 v8;
 do { if (gUnk_020390D4 == 0) { return; } if (gUnk_020391F0 != 0) { return; } v8 = gUnk_0203916C - 3; p1 = &gUnk_0203B858; p2 = &gUnk_0203B6D4; if (v8 <= 2) { for (i = 0; i != gUnk_020390BC; i++) { gUnk_0203D68C[i * 100] = gUnk_0203D68C[i * 100] + 1; } } *p1 += 40; } while (0);
  if ((*p1) > 999)
  {
    *p1 -= 1000;
    gUnk_0203B6A8 = gUnk_0203B6A8 + 1;
    if (gUnk_0203B6A8 > 59)
    {
      gUnk_0203B6A8 = gUnk_0203B6A8 - 60;
      gUnk_0203B6C8 = gUnk_0203B6C8 + 1;
    }
  }
  *p2 += 40;
  if ((*p2) > 999)
  {
    *p2 -= 1000;
    gUnk_0203B6D0 = gUnk_0203B6D0 + 1;
    if (gUnk_0203B6D0 > 59)
    {
      gUnk_0203B6D0 = gUnk_0203B6D0 - 60;
      gUnk_0203B704 = gUnk_0203B704 + 1;
    }
  }
}
