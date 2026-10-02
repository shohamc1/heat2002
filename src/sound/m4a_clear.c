#include "global.h"

#if PORTABLE
/* The hosted channel pointers are pointer-wide, so the trampoline takes
   them as pointers (the GBA's u32 is the pointer width there).
   The two targets are the tail of gMPlayJumpTable (src/system/globals.c):
   the ROM's MPlayJumpTableCopy installs RealClearChain and SoundMainBTM
   (the 0x40-byte clear) by copying the template's 0x24 entries over the
   0x22-entry table and the two pointer words that follow it, so hosted
   the names alias those entries instead of separate variables. m4a.h
   declares the table; the GBA branch keeps this file's old includes
   (its ClearChain takes the GBA's u32 spelling, which m4a_internal.h's
   prototype would clash with). */
#include "m4a.h"
#define gUnk_02001E18 (*(void (**)(void *))(gMPlayJumpTable + 0x22))
#define gUnk_02001E1C (*(void (**)(void *))(gMPlayJumpTable + 0x23))

void ClearChain(void *x)
{ gUnk_02001E18(x); }

void Clear64byte(void *x)
{ gUnk_02001E1C(x); }
#else
extern void (*gUnk_02001E18)(u32);
extern void (*gUnk_02001E1C)(void *);

void ClearChain(u32 x)
{ gUnk_02001E18(x); }

void Clear64byte(void *x)
{ gUnk_02001E1C(x); }
#endif
