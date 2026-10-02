@ Hosted-build assembly macros, after SAT-R/sa2's asm/macros/portable.inc.
@
@ The data rule in the Makefile runs every data/*.s through preproc (which
@ inlines each .include) and then cpp, so these #if lines are resolved by
@ the C preprocessor before the assembler sees them. They are keyed on
@ -DPLATFORM_GBA only, never on the host compiler's own architecture
@ macros: the GBA build preprocesses with the host cc too, and its cpp
@ must always take the GBA branch.
@
@ One flat cpp stream: preproc inlines every .include, so a plain cpp
@ include guard makes a second inclusion (music_voice.inc after the data
@ file's own preamble include) expand to nothing.
#ifndef ASM_MACROS_PORTABLE_INC
#define ASM_MACROS_PORTABLE_INC

.macro mSectionRodata
#if defined(__APPLE__)
    .section __DATA,__data
    .balign 8
#else
@ Linux PIE rejects absolute relocations in .rodata, so the generated
@ songs' pointer fields land in the linker-relocated writable-once data.
    .section .data.rel.ro
    .balign 8
#endif
.endm

@ The data fragments' GBA form lives in .text; the hosted build needs a
@ writable section, since its mPtr pointers carry relocations.
@ The hosted branches balign to the pointer width: a section entered at
@ offset 0 records no alignment from a later .balign, and ld64 refuses
@ mPtr pointers that straddle an 8-byte line.
.macro mSectionData
#if defined(__APPLE__)
    .section __DATA,__data
    .balign 8
#else
    .section .data
    .balign 8
#endif
.endm

@ Word-align a song header or track pointer field: the GBA keeps tmc
@ mid2agb's zero-filling 4-byte align (tools/mid2agb's songs must
@ assemble identically to tools/tmc's on the GBA), hosts align to the
@ pointer width. NB: not mAlignPtr, whose GBA branch must emit nothing.
.macro mAlignWord
#if PLATFORM_GBA
    .align 2, 0
#elif defined(__APPLE__)
    .align 3
#else
    .balign 8
#endif
.endm

@ The C spelling of an asm label: underscore platforms prefix it (after
@ sa2's asm/macros/c_decl.inc, inlined here so generated songs need no
@ second include).
#if defined(__APPLE__) && !PLATFORM_GBA
#ifndef C_DECL
#define C_DECL(label) _##label
#endif
#else
#ifndef C_DECL
#define C_DECL(label) label
#endif
#endif

@ Export \name under the C spelling too on underscore platforms, so C
@ can reference an asm-defined label: cSym leaves Linux alone and adds
@ `_\name = \name` on macOS.
.macro cSym name
#if defined(__APPLE__) && !PLATFORM_GBA
    .globl _\name
    .set _\name, \name
#endif
.endm

@ A pointer field: 4 bytes on the GBA, the host's pointer width otherwise.
.macro mPtr value
#if PLATFORM_GBA
    .4byte \value
#else
    .quad \value
#endif
.endm

@ A GOTO or PATT target in a song's command stream. The fields sit
@ at odd offsets, so the hosted build stores the target as an offset from
@ the field, which needs no relocation; ply_goto adds it back.
.macro mRelPtr value
#if PLATFORM_GBA
    .4byte \value
#else
    .quad \value - .
#endif
.endm

@ Align to the pointer width, hosted builds only. The GBA branch must emit
@ nothing: tools/tmc's voice macros pack their pointer fields unaligned,
@ and any padding would move every later byte of the voice groups.
.macro mAlignPtr
#if PLATFORM_GBA
#elif defined(__APPLE__)
    .align 3
#else
    .balign 8
#endif
.endm

#endif
@ ASM_MACROS_PORTABLE_INC
