#ifndef GUARD_PLATFORM_SHARED_INPUT_H
#define GUARD_PLATFORM_SHARED_INPUT_H

// After sa2's include/platform/shared/input.h. The win32 XInput half is
// dropped (sa2's src/platform/shared/input.c compiled it); this port
// reads keyboard state that src/platform/pret_sdl/sdl2.c keeps.

#include "config.h"
#include "global.h"

typedef u32 SharedKeys;

#define KEY_SPEEDUP   (1 << 16)
#define SPEEDUP_SCALE 5.0f

#endif // GUARD_PLATFORM_SHARED_INPUT_H
