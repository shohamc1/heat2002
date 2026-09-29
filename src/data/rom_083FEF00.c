#include "global.h"
#include "data.h"

/* 0x083FEF00-0x083FEF08: two single-word gfx pointers. gChampionshipTrophyGfx
 * is RL-uncompressed into OBJ VRAM for the championship podium screen
 * (DrawTrophyScreen); gLineMarkerSpriteGfxTable is the 32x32 sprite sub_080069D8 stamps
 * 16 times along a line (sub_0800C21C). */

extern const u8 gUnk_0830E70C[];
extern const u8 gUnk_0831C850[];

const u32 gChampionshipTrophyGfx = (u32)gUnk_0830E70C;
const u8 *const gLineMarkerSpriteGfxTable[] = { gUnk_0831C850 };
