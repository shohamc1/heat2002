#ifndef GUARD_M4A_H
#define GUARD_M4A_H

// Sound engine public API. The engine itself is in lib/m4a.
#include "gba/m4a_internal.h"

void m4aSoundInit(void);
void m4aSoundVSync(void);
void m4aSongNumStart(u16 idx);
void m4aMPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u32 fadeOutDelay);

// Sound driver constants and jump tables, in symbols.ld. gMaxLines and
// the player counts are defined at their constant's value; each engine
// copy owns one jump table (main program / high module).
#if PLATFORM_GBA
extern u8 gMaxLines;
extern u8 gNumMusicPlayersLow[];
extern u8 gNumMusicPlayersHigh[];
#else
/* The same fake addresses as macros, so a hosted link needs no linker
   script line: every use decays or takes the address of the symbol and
   casts it to an integer, which the pointer values reproduce exactly
   (0, 5 and 4). gMaxLines is a scalar whose only use is &gMaxLines, so
   it must expand to an lvalue; the player counts are only ever decayed. */
#define gMaxLines           (*(u8 *)0)
#define gNumMusicPlayersLow ((uintptr_t)5)
#define gNumMusicPlayersHigh ((uintptr_t)4)
#endif
extern MPlayFunc gMPlayJumpTable[];
extern MPlayFunc gModule_MPlayJumpTable[];

#endif
