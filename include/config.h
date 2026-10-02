#ifndef GUARD_CONFIG_H
#define GUARD_CONFIG_H

// One definition point for the platform switches, after sa2's config.h.
// The GBA build passes no -D flags and gets the defaults. A hosted build
// (make PLATFORM=sdl) passes -DPLATFORM_SDL=1 -DPLATFORM_GBA=0
// -DPORTABLE=1, which the Makefile derives from PLATFORM; the asm data
// pipeline passes the same -DPLATFORM_GBA to cpp.
//
// Headers must never key portability on the host compiler's own
// architecture macros: the GBA build preprocesses with the host cc too.

#ifndef PLATFORM_SDL
#define PLATFORM_SDL 0
#endif

#ifndef PORTABLE
#if PLATFORM_SDL
#define PORTABLE 1
#else
#define PORTABLE 0
#endif
#endif

#if PORTABLE
#define PLATFORM_GBA 0
#include <stdint.h> // uintptr_t for pointer-width lvalues
#else
#define PLATFORM_GBA 1
#endif

#endif // GUARD_CONFIG_H
