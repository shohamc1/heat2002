#ifndef GUARD_GBA_COMPAT_H
#define GUARD_GBA_COMPAT_H

#include "defines.h"
#include "io_reg.h"
#include "syscall.h"

void sub_08016E0C(u32 src, u32 dest, u32 mode);
void sub_08016E10(u32 src, u32 dest, u32 control);
void sub_08016E28(u32 src, u32 dest);
void sub_08344B64(u32 src, u32 dest, u32 control);

#ifndef GBA_CPUSET
#define GBA_CPUSET sub_08016E10
#endif
#ifndef GBA_RLUNCOMPVRAM
#define GBA_RLUNCOMPVRAM sub_08016E28
#endif
#ifndef GBA_CPUFASTSET
#define GBA_CPUFASTSET sub_08016E0C
#endif

#define CpuSet GBA_CPUSET
#define RLUnCompVram GBA_RLUNCOMPVRAM
#define CpuFastSet GBA_CPUFASTSET

#include "macro.h"

#endif // GUARD_GBA_COMPAT_H
