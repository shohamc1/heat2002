#ifndef GUARD_GBA_COMPAT_H
#define GUARD_GBA_COMPAT_H

#include "config.h"
#include "defines.h"
#include "io_reg.h"
#include "syscall.h"

#if !PORTABLE
// libagbsyscall's ROM objects, called by their luvdis names so the link
// places them at their original addresses. Pointer parameters: the
// arguments are addresses either way, and the hosted build passes real
// pointers through the same prototypes (verified byte-identical by
// make check).
void sub_08016E0C(const void *src, void *dest, u32 mode);
void sub_08016E10(const void *src, void *dest, u32 control);
void sub_08016E28(const void *src, void *dest);
void sub_08344B64(const void *src, void *dest, u32 control);

#ifndef GBA_CPUSET
#define GBA_CPUSET sub_08016E10
#endif
#ifndef GBA_RLUNCOMPVRAM
#define GBA_RLUNCOMPVRAM sub_08016E28
#endif
#ifndef GBA_CPUFASTSET
#define GBA_CPUFASTSET sub_08016E0C
#endif

// The casts take the integer addresses the game passes (VRAM, PLTT,
// IWRAM_START + n) without a warning; they emit no code.
#define CpuSet(src, dest, control) \
    GBA_CPUSET((const void *)(src), (void *)(dest), control)
#define RLUnCompVram(src, dest) \
    GBA_RLUNCOMPVRAM((const void *)(src), (void *)(dest))
#define CpuFastSet(src, dest, mode) \
    GBA_CPUFASTSET((const void *)(src), (void *)(dest), mode)
#else
// The port ships C versions of the BIOS calls the game uses
// (src/platform/libagbsyscall.c, after sa2), which syscall.h
// above already declares: CpuSet, CpuFastSet, RLUnCompVram and the rest
// keep their own names.
#endif

#include "macro.h"

#endif // GUARD_GBA_COMPAT_H
