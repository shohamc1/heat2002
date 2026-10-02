#include "global.h"
#include "gba/m4a_internal.h"
#include "m4a.h"
#include "variables.h"

/* This file owns the high module's two sound EWRAM runs (issue 5 step 3,
   run rule; MODULE_EWRAM_DATA like the main program's EWRAM_DATA files):
   the music-player jump table with the clear-call pointers beside it
   (0x02038DE0-0x02038E70), and the module's MusicPlayerInfo players plus
   the two table rows behind them (0x02038F70-0x020390A0). The module's
   SoundInfo and CGB channels are not RAM variables of its own: the image
   bytes the chunk transfer copies carry them, and ModuleSoundInit takes
   their addresses as arguments. Between the two runs lies the module's
   unnamed 0x100-byte CgbChans block (0x02038E70-0x02038F70), which no
   identified symbol covers. ldscript.ld's .module_ewram_data_sound and
   .module_ewram_data_sound_2 place the two sections. */

MODULE_EWRAM_DATA MPlayFunc gModule_MPlayJumpTable[0x22] = {0};
/* ClearChain/Clear64byte call through these (src/sound/module_m4a_clear.c). */
MODULE_EWRAM_DATA u32 gUnk_02038E68 = 0;
MODULE_EWRAM_DATA u32 gUnk_02038E6C = 0;

MODULE_EWRAM_DATA2 struct MusicPlayerInfo gModule_BgMusicPlayer = {0};
MODULE_EWRAM_DATA2 struct MusicPlayerInfo gModule_EngineSoundPlayer = {0};
MODULE_EWRAM_DATA2 struct MusicPlayerInfo gUnk_02038FF0 = {0};
static MODULE_EWRAM_DATA2 u8 sound_gap8FF30[0x10] = {0};
MODULE_EWRAM_DATA2 struct MusicPlayerInfo gUnk_02039040 = {0};
static MODULE_EWRAM_DATA2 u8 sound_gap90380[0x20] = {0};
