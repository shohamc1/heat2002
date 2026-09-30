#ifndef GLOBAL_H
#define GLOBAL_H

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

#define TRUE 1
#define FALSE 0
#define NULL ((void *)0)

// Absolute value, testing < 0 first; the >= 0-first form (SA2's ABS)
// compiles to a different branch order.
#define ABS2(x) ((x) < 0 ? -(x) : (x))

// INCBIN_U8("build/assets/...") and its siblings expand to the file's contents
// as an array initialiser, as in pokeemerald. The build's cpp runs with
// -undef, so these stay undefined there and tools/bin/preproc expands each
// call after cpp. This stub only keeps an IDE's parser quiet.
#if defined(__APPLE__) || defined(__CYGWIN__) || defined(__clang__)
#define INCBIN(...) {0}
#define INCBIN_U8   INCBIN
#define INCBIN_U16  INCBIN
#define INCBIN_U32  INCBIN
#define INCBIN_S8   INCBIN
#define INCBIN_S16  INCBIN
#define INCBIN_S32  INCBIN
#endif // IDE support

#define NAKED __attribute__((naked))

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
