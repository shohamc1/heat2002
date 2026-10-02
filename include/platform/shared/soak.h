#ifndef GUARD_PLATFORM_SHARED_SOAK_H
#define GUARD_PLATFORM_SHARED_SOAK_H

// Scripted-input soak harness. Host-only: nothing here
// is ever compiled into the GBA build.
//
// The front end calls Soak_Advance() once per emulated frame (per
// VBlankIntrWait) and writes the returned mask into REG_KEYINPUT the way
// sdl2.c does for keyboard state (bits set = pressed). Without any of
// the env variables below the mask is 0 and FRAME_LIMIT is disabled, so
// the harness is inert in normal play.

#include "config.h"
#include "global.h"

u16 Soak_Advance(void);

#endif // GUARD_PLATFORM_SHARED_SOAK_H
