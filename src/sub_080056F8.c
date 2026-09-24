#include "global.h"
extern u8 gUnk_020020C4;
extern u8 gUnk_020021E0;
extern u8 gUnk_0200215C;
extern u16 gUnk_020253CC;
extern u16 gUnk_02025224;
extern u8 gNumLinkPlayers;
extern u32 gUnk_0202A6BC[];
extern u16 gUnk_020251FC;
extern u16 gUnk_02025218;
extern u16 gUnk_02025220;
extern u16 gUnk_02025260;
void UpdateRaceTimers(void)
{
  u16 *p2;
  u16 *p1;
  u8 i;
  u8 v8;
 do { if (gUnk_020020C4 == 0) { return; } if (gUnk_020021E0 != 0) { return; } v8 = gUnk_0200215C - 3; p1 = &gUnk_020253CC; p2 = &gUnk_02025224; if (v8 <= 2) { for (i = 0; i != gNumLinkPlayers; i++) { gUnk_0202A6BC[i * 100] = gUnk_0202A6BC[i * 100] + 1; } } *p1 += 40; } while (0);
  if ((*p1) > 999)
  {
    *p1 -= 1000;
    gUnk_020251FC = gUnk_020251FC + 1;
    if (gUnk_020251FC > 59)
    {
      gUnk_020251FC = gUnk_020251FC - 60;
      gUnk_02025218 = gUnk_02025218 + 1;
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
