#ifndef GUARD_M4A_H
#define GUARD_M4A_H

// Sound engine public API. The engine itself is in lib/m4a.
#include "gba/m4a_internal.h"

void m4aSoundInit(void);
void m4aSongNumStart(u16 idx);
void m4aMPlayFadeOut(u32 arg0, u32 arg1);

// Sound driver constants and jump tables, in symbols.ld. gMaxLines and
// the player counts are defined at their constant's value; each engine
// copy owns one jump table (main program / high module).
extern u8 gMaxLines;
extern u8 gNumMusicPlayersLow[];
extern u8 gNumMusicPlayersHigh[];
extern MPlayFunc gMPlayJumpTable[];
extern MPlayFunc gModule_MPlayJumpTable[];

#endif
