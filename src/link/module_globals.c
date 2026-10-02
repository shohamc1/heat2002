#include "global.h"
#include "gba/defines.h"
#include "variables.h"

/* This file owns the high module's last EWRAM run 0x0203E0E0-0x0203E200
   (issue 5 step 3, run rule): the race-end and challenge flags, the
   link-race state (detected players, the 0x50-byte receive-word buffer,
   the player id), the options block and the two closing link buffers.
   The dead-only gUnk_0203E140 is defined here (variables.h declares it;
   src/dead/sub_08344684.c sets its 17 flag bytes), no symbols.ld line
   left; behind gUnk_0203E1E0 the module's identified EWRAM ends, 0xE00
   bytes before the top of the 256 KB bank. ldscript.ld's
   .module_ewram_data_link places the section at 0x0203E0E0. */

MODULE_EWRAM_DATA u8 gModule_DamagePitsEnabled = 0;
static MODULE_EWRAM_DATA u8 link_gapE0E1[0x17] = {0};
MODULE_EWRAM_DATA u8 gUnk_0203E0F8 = 0;
static MODULE_EWRAM_DATA u8 link_gapE0F9[0xB] = {0};
MODULE_EWRAM_DATA u8 gUnk_0203E104 = 0;
static MODULE_EWRAM_DATA u8 link_gapE105[0xB] = {0};
MODULE_EWRAM_DATA u8 gModule_DetectedPlayers = 0;
static MODULE_EWRAM_DATA u8 link_gapE111[0xF] = {0};
MODULE_EWRAM_DATA u8 gModule_Options[0x20] = {0};
MODULE_EWRAM_DATA u8 gUnk_0203E140[0x20] = {0};
MODULE_EWRAM_DATA u16 gModule_LinkRecvWords[0x28] = {0};
MODULE_EWRAM_DATA u8 gModule_LinkPlayerId = 0;
static MODULE_EWRAM_DATA u8 link_gapE1B1[0xF] = {0};
MODULE_EWRAM_DATA u8 gUnk_0203E1C0[0x20] = {0};
MODULE_EWRAM_DATA u8 gUnk_0203E1E0[0x20] = {0};
