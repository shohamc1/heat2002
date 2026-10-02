#ifndef GLOBAL_H
#define GLOBAL_H

#include "config.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef u8 bool8;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

typedef void (*IntrFunc)(void);

/* A graphics-source address handed to the OBJ tile caches. */
typedef const void *GfxSrc;

/* The integer width a ROM-era address takes: u32 on the GBA, where a
   pointer is one word, uintptr_t on a hosted build whose pointers are
   wider. Cast through it only where the value must stay an integer
   (hardware register writes, byte-offset address arithmetic the asm
   depends on); carry pointers as pointers everywhere else. */
#if PORTABLE
#define ADDR_WORD(x) ((uintptr_t)(x))
#else
#define ADDR_WORD(x) ((u32)(x))
#endif

// A member's byte offset, as an integer constant: agbcc has no
// __builtin_offsetof, and the hosted build's widened pointers move most
// struct Car members, so code that walks a member by byte offset must not
// hard-code the GBA value.
#if PORTABLE
#define OFFSETOF(type, member) ((u32)__builtin_offsetof(type, member))
#else
#define OFFSETOF(type, member) ((u32) & ((type *)0)->member)
#endif

#define TRUE 1
#define FALSE 0
// The GBA build's cpp runs with -undef, so the host's <stddef.h> never
// reaches it; a hosted build links against SDL and libc headers, whose
// NULL this must not clash with.
#ifndef NULL
#define NULL ((void *)0)
#endif

// Absolute value, testing < 0 first; the >= 0-first form (SA2's ABS)
// compiles to a different branch order.
#define ABS2(x) ((x) < 0 ? -(x) : (x))

// INCBIN_U8("build/assets/...") and its siblings expand to the file's contents
// as an array initialiser, as in pokeemerald. The build's cpp runs with
// -undef, so these stay undefined there and tools/bin/preproc expands each
// call after cpp. This stub only keeps an IDE's parser quiet; a real hosted
// build preprocesses the same way, so it expands them too.
#if !PORTABLE && (defined(__APPLE__) || defined(__CYGWIN__) || defined(__clang__))
#define INCBIN(...) {0}
#define INCBIN_U8   INCBIN
#define INCBIN_U16  INCBIN
#define INCBIN_U32  INCBIN
#define INCBIN_S8   INCBIN
#define INCBIN_S16  INCBIN
#define INCBIN_S32  INCBIN
#endif // IDE support

#define NAKED __attribute__((naked))

// A register pin: `register u32 a0 PIN(r0) = 0;` names the register on the
// GBA (where agbcc honours asm("rN") and the bytes depend on it) and
// becomes a plain local in a hosted build, whose compiler has no such
// registers.
#if PLATFORM_GBA
#define PIN(reg) asm(#reg)
#else
#define PIN(reg)
#endif

// A function still in asm, kept in its C file so the file can be partly
// decompiled, as in tmc. `path` is an asm/non_matching/ .inc file holding
// the luvdis block's body without its func_start/func_end lines or its
// name label. progress.py counts the function as unmatched.
#define ASM_FUNC(path, decl) \
    NAKED decl \
    { \
        asm(".syntax unified\n.include \"" path "\"\n.syntax divided"); \
    }

#endif
