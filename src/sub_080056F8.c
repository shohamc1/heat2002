#include "global.h"
#include "variables.h"
extern u32 gUnk_0202A6BC[];
void UpdateRaceTimers(void)
{
  u16 *p2;
  u16 *p1;
  u8 i;
  u8 v8;
 do { if (gUnk_020020C4 == 0) { return; } if (gUnk_020021E0 != 0) { return; } v8 = gUnk_0200215C[0] - 3; p1 = &gUnk_020253CC[0]; p2 = &gUnk_02025224; if (v8 <= 2) { for (i = 0; i != gNumLinkPlayers[0]; i++) { gUnk_0202A6BC[i * 100] = gUnk_0202A6BC[i * 100] + 1; } } *p1 += 40; } while (0);
  if ((*p1) > 999)
  {
    *p1 -= 1000;
    gUnk_020251FC[0] = gUnk_020251FC[0] + 1;
    if (gUnk_020251FC[0] > 59)
    {
      gUnk_020251FC[0] = gUnk_020251FC[0] - 60;
      gUnk_02025218[0] = gUnk_02025218[0] + 1;
    }
  }
  *p2 += 40;
  if ((*p2) > 999)
  {
    *p2 -= 1000;
    gUnk_02025220 = gUnk_02025220 + 1;
    if (gUnk_02025220 > 59)
    {
      gUnk_02025220 = gUnk_02025220 - 60;
      gUnk_02025260 = gUnk_02025260 + 1;
    }
  }
}
