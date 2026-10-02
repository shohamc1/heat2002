TARGET  := nascar-heat
BUILD   := build

AS      := arm-none-eabi-as
LD      := arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy
CC1     := tools/agbcc/old_agbcc
# Expands INCBIN_U8/U16/U32 in C after cpp (include/global.h).
PREPROC := tools/bin/preproc
# binutils ships no arm-none-eabi-cpp; agbcc does the compiling, so any C
# preprocessor works here. -undef/-nostdinc keep the host's macros and headers
# out of a build that must reproduce a 2002 ROM.
CPP     := cc -E -x c

ASFLAGS := -mcpu=arm7tdmi -mthumb-interwork
CFLAGS  := -O2 -mthumb-interwork -fhex-asm -Wimplicit -Wparentheses
CPPFLAGS := -I include -I tools/agbcc/include -iquote include -nostdinc -undef

# The platform layer is hosted-only: the GBA build never compiles it
# (its files include host headers and the SDL front end).
C_SRCS   := $(shell find src -name '*.c' ! -path 'src/platform/*')
DATA_SRCS := $(wildcard data/*.s data/sound/*.s)
# Bodies of ASM_FUNC functions (include/global.h), included from C.
ASM_INCS := $(shell find asm -name '*.inc' 2>/dev/null | grep -v '^asm/macros/')

# ---------------------------------------------------------------------------
# Hosted build (issue 5): PLATFORM=sdl compiles the main program as a
# native 64-bit program with an SDL platform layer, after SAT-R/sa2. Any
# other PLATFORM value also builds hosted. The GBA target above and below
# is untouched and stays byte-exact.
# ---------------------------------------------------------------------------
PLATFORM ?= gba
ifeq ($(PLATFORM),gba)
PORTABLE := 0
else
PORTABLE := 1
endif

ifeq ($(PORTABLE),1)
# The build machine's OS (keys the ASan null-front-end switch) and the
# sanitizer switch, both read throughout this block.
UNAME_S := $(shell uname -s)
ASAN ?= 0
# The hosted toolchain. Each can be overridden on the command line to
# cross-compile; a Windows build uses MinGW-w64:
#   make PLATFORM=sdl CC_H=x86_64-w64-mingw32-gcc CXX_H=x86_64-w64-mingw32-g++ \
#        AS_H=x86_64-w64-mingw32-as LD_H=x86_64-w64-mingw32-ld \
#        SDL2_CONFIG=/path/to/x86_64-w64-mingw32/bin/sdl2-config
# The tools the build runs itself (preproc, mid2agb, aif2pcm) always use
# the build machine's cc and c++.
CC_H := cc
CXX_H := c++
AS_H := as
# The host linker, for the -r pass that normalizes the data objects'
# symbol tables (gas Mach-O objects with .equ aliases leave an indirect
# symbol table ld64 refuses).
LD_H := ld
SDL2_CONFIG := sdl2-config
# The hosted sources preprocess with the target compiler too: its
# predefined macros (pointer and long widths, OS) must match the compile.
CPP_H = $(CC_H) -E -x c
ACPP_H = $(CC_H) -E -P -x assembler-with-cpp
# The OS the port is built for, from the compiler's target triple (it
# differs from UNAME_S when cross-compiling).
PORT_TARGET := $(shell $(CC_H) -dumpmachine 2>/dev/null)
PORT_WINDOWS := $(if $(findstring mingw,$(PORT_TARGET)),1)
# The hosted build writes only under build/$(PLATFORM)/, never build/.
# The sanitizer build (ASAN=1) and a Windows cross-build get their own
# trees beside it, so the binaries and object sets coexist.
PORT_BUILD := build/$(PLATFORM)$(if $(PORT_WINDOWS),-windows)$(if $(filter 1,$(ASAN)),-asan)
# -Wshorten-64-to-32 is clang-only; gcc (CI's Linux hosts) rejects it as
# an unrecognized option, so probe the compiler once and leave it out
# where it is not accepted.
WARN_SHORTEN_64_TO_32 := $(shell $(CC_H) -Wshorten-64-to-32 -fsyntax-only -x c /dev/null >/dev/null 2>&1 && echo -Wshorten-64-to-32)
CPPFLAGS_H := -I include -DPLATFORM_$(shell echo $(PLATFORM) | tr '[:lower:]' '[:upper:]')=1 \
	-DPLATFORM_GBA=0 -DPORTABLE=1 $(shell $(SDL2_CONFIG) --cflags 2>/dev/null)
# A GCC 2.95-era codebase meeting a modern host compiler: the old dialect
# is accepted, and the code reads the same memory through several types
# and relies on signed wraparound, as agbcc allowed.
CFLAGS_H := -O2 -std=gnu89 -fno-strict-aliasing -fwrapv \
	-Wno-implicit-function-declaration -Wno-pointer-sign -Wno-return-mismatch \
	-Wno-incompatible-pointer-types $(WARN_SHORTEN_64_TO_32)

# Sanitizer build of the port (issue 5 step 9): `make PLATFORM=sdl ASAN=1`
# compiles every hosted object (game code, platform layer, renderer) and
# links with -fsanitize=address,undefined, so the soak runs trip host-side
# UB (OOB, uninit, bad shifts) the GBA build silently tolerates.
# On macOS this needs the null front end instead of the SDL one (see
# src/platform/null_front/null_front.c): Homebrew's sdl2 is the
# sdl2-compat layer, whose dylib initializer dlopens SDL3 -- under ASan
# that dlopen fails and the layer pops a modal NSAlert no automated run
# dismisses. A plain build and a UBSan-only build of the same SDL program
# run fine; only ASan+SDL does not (verified 2026-10-01, SDL 2.32.72).
# Elsewhere (Linux) the SDL front end stays.
ifeq ($(ASAN),1)
# -fsanitize-recover=address: a soak collects every report in one run
# (with ASAN_OPTIONS=halt_on_error=0) instead of stopping at the first.
SAN_FLAGS := -fsanitize=address,undefined -fno-omit-frame-pointer -g \
	-fsanitize-recover=address
CFLAGS_H += $(SAN_FLAGS)
ifeq ($(UNAME_S),Darwin)
PORT_FRONT_C := src/platform/null_front/null_front.c
else
PORT_FRONT_C := src/platform/pret_sdl/sdl2.c
endif
else
SAN_FLAGS :=
PORT_FRONT_C := src/platform/pret_sdl/sdl2.c
endif

# The port builds the main program's own objects: every build/src line the
# .text section of ldscript.ld places (which leaves the high module, the
# island, the runtime libraries and crt0 out), minus the dead files, whose
# functions nothing reaches. The data fragments the same section places
# come along: the assets still build from baserom.gba (or zero-fill in CI)
# exactly as the GBA build's do.
# NB: the sed programs below must not contain a bare closing paren, which
# would end this $(shell ...) reference for make; none of the object paths
# carries a dot before its .o suffix.
# .text_tail follows the EWRAM images and holds the rest of the main
# program's ROM data (race data and the trailing rom_083F* fragments).
PORT_SECTIONS := '/^    \.text : ALIGN/,/^    }$$/p;/^    \.text_tail /,/^    }$$/p;/^    \.bss_[A-Za-z0-9_]* 0x/,/^    }$$/p;/^    \.iwram_[A-Za-z0-9_]* 0x/,/^    }$$/p'
PORT_C_SRCS := $(shell sed -n $(PORT_SECTIONS) ldscript.ld \
	| sed -n 's|^ *build/src/\([^. ]*\)\.o.*|src/\1.c|p' | grep -v '^src/dead/' | sort -u)
PORT_DATA_SRCS := $(shell sed -n $(PORT_SECTIONS) ldscript.ld \
	| sed -n 's|^ *build/data/\([^. ]*\)\.o.*|data/\1.s|p' | sort -u)
PORT_C_OBJS := $(PORT_C_SRCS:src/%.c=$(PORT_BUILD)/src/%.o)
PORT_DATA_OBJS := $(PORT_DATA_SRCS:data/%.s=$(PORT_BUILD)/data/%.o)

# The platform layer (issue 5 step 5): the SDL front end, the shared
# hosted hardware (memory arrays, DMA, the C BIOS calls and interrupt
# dispatcher), the software renderer, and the stubs that complete the
# link until steps 6-8 replace them. C sources build with the same
# hosted rule as the game objects; the renderer is C++. ext/gbagfx is
# not compiled standalone: libagbsyscall.c #includes it, as sa2's build
# does. Exactly one front end links: PORT_FRONT_C (the ASAN block above)
# -- the other front-end folders stay out of the glob.
PORT_PLATFORM_C_SRCS := $(filter-out $(PORT_C_SRCS) src/platform/ext/% \
	src/platform/pret_sdl/% src/platform/null_front/%,$(wildcard src/platform/*.c) \
	$(wildcard src/platform/*/*.c) $(wildcard src/platform/*/*/*.c)) $(PORT_FRONT_C)
PORT_PLATFORM_OBJS := $(PORT_PLATFORM_C_SRCS:src/%.c=$(PORT_BUILD)/src/%.o) \
	$(PORT_BUILD)/src/platform/shared/video/gpsp_renderer.cc.o
PORT_EXE := $(PORT_BUILD)/$(TARGET).sdl$(if $(PORT_WINDOWS),.exe)
endif

# Runtime library: newlib objects built from the vendored source with the
# flags of tools/agbcc/libc/Makefile (no interwork, -fno-builtin), in ROM
# order. ldscript.ld places each one whole, plus its .rodata, .data and .bss.
NEWLIB_DIR  := tools/agbcc/libc
NEWLIB_OBJS := $(addprefix $(BUILD)/lib/newlib/,$(addsuffix .o, \
	stdio/sprintf stdio/vfprintf stdio/wsetup stdlib/dtoa stdio/fflush \
	stdio/findfp stdlib/freer stdio/fvwrite stdio/fwalk locale/locale stdio/makebuf \
	stdlib/mallocr stdlib/mbtowc_r string/memchr string/memcpy \
	string/memmove string/memset stdlib/mlock stdlib/mprec math/s_isinf \
	math/s_isnan reent/sbrkr stdio/stdio string/strcmp string/strlen \
	arm/syscalls reent/writer stdlib/callocr reent/closer errno/errno reent/fstatr \
	arm/libcfunc reent/lseekr reent/readr reent/impure))

# Nintendo's BIOS-call library, one object per syscall, from
# lib/libagbsyscall.s (pokeemerald's). Each separately linked module carries
# its own copy: the main program's keeps the SDK names; the high 0x0834
# module's and the multiboot island's keep their luvdis names, since one link
# cannot hold three CpuSets.
AGBSYSCALL_OBJS := $(addprefix $(BUILD)/lib/agbsyscall/,$(addsuffix .o, \
	CpuFastSet CpuSet IntrWait LZ77UnCompVram MultiBoot RLUnCompVram \
	RegisterRamReset VBlankIntrWait))
AGBSYSCALL_COPIES := sub_08344B60:CpuFastSet sub_08344B64:CpuSet \
	sub_08344B68:IntrWait sub_08344B70:RLUnCompVram sub_08344B74:VBlankIntrWait \
	sub_083647F8:CpuFastSet sub_083647FC:CpuSet sub_08364800:LZ77UnCompVram \
	sub_08364804:RegisterRamReset sub_08364808:VBlankIntrWait
AGBSYSCALL_COPY_OBJS := $(foreach c,$(AGBSYSCALL_COPIES),$(BUILD)/lib/agbsyscall/$(firstword $(subst :, ,$(c))).o)
syscall_of = $(lastword $(subst :, ,$(filter $(1):%,$(AGBSYSCALL_COPIES))))

# The MP2K sound driver's hand-written assembly (lib/m4a_1.s, this ROM's
# revision of pokeemerald's m4a_1.s). The main program and the high 0x0834
# module each link a copy. The high copy's globals take their luvdis address
# names, and its externs point at the high module's own m4a.c twins and data.
M4A_OBJS := $(BUILD)/lib/m4a/m4a_1.o $(BUILD)/lib/m4a/m4a_1_high.o
M4A_HIGH_BASE := 0x08339B78
M4A_HIGH_EXTERNS := Clear64byte=ModuleClear64byte ClearChain=ModuleClearChain \
	FadeOutBody=ModuleFadeOutBody MidiKeyToFreq=ModuleMidiKeyToFreq TrkVolPitSet=ModuleTrkVolPitSet \
	gClockTable=gModule_ClockTable gMPlayJumpTableTemplate=gUnk_0200C668

# libgcc, built from tools/agbcc/libgcc as its own Makefile builds it: the
# division helpers and _call_via_rX are the hand-written lib1thumb.asm, the
# rest is libgcc2.c and the generated fp-bit.c/dp-bit.c at -O2 with no
# interwork. The main program links nine objects. The high 0x0834 module
# links its own copy of seven, renamed to their luvdis names: functions to
# sub_<address>, the _call_via_rN stubs to _<address>, and each __div0
# reference to the high copy's.
LIBGCC_DIR := tools/agbcc/libgcc
LIBGCC1_OBJS := $(addprefix $(BUILD)/lib/libgcc/,$(addsuffix .o, \
	_call_via_rX _divsi3 _dvmd_tls _modsi3 _udivsi3 _umodsi3))
LIBGCC2_OBJS := $(addprefix $(BUILD)/lib/libgcc/,_muldi3.o _negdi2.o _lshrdi3.o)
LIBGCC_FP_OBJS := $(BUILD)/lib/libgcc/dp-bit.o $(BUILD)/lib/libgcc/fp-bit.o
LIBGCC_HIGH := _call_via_rX:08344B7C _divsi3:08344BB8 _dvmd_tls:08344C4C \
	_modsi3:08344C50 _muldi3:08344D20 _negdi2:08344D90 _umodsi3:08344DA8
LIBGCC_HIGH_OBJS := $(foreach c,$(LIBGCC_HIGH),$(BUILD)/lib/libgcc/high/$(firstword $(subst :, ,$(c))).o)
libgcc_high_base = $(lastword $(subst :, ,$(filter $(1):%,$(LIBGCC_HIGH))))
# The multiboot island links a third copy of _call_via_rX, named the same way.
LIBGCC_ISLAND_OBJS := $(BUILD)/lib/libgcc/island/_call_via_rX.o
LIBGCC_OBJS := $(LIBGCC1_OBJS) $(LIBGCC2_OBJS) $(LIBGCC_FP_OBJS) $(LIBGCC_HIGH_OBJS) \
	$(LIBGCC_ISLAND_OBJS)

# Nintendo SDK start routine and interrupt dispatcher (lib/crt0.s), linked
# by the main program and by the high 0x0834 module. The high copy takes its
# luvdis names and points at the module's AgbMain and interrupt table. The
# multiboot island has its own variant (lib/crt0_island.s).
CRT0_OBJS := $(BUILD)/lib/rom_header.o $(BUILD)/lib/crt0.o $(BUILD)/lib/crt0_high.o \
	$(BUILD)/lib/crt0_island.o
CRT0_HIGH_SYMS := Init=sub_08339780 IntrMain=sub_083397C4 \
	AgbMain=ModuleAgbMain gIntrTable=gModule_IntrTable

# Nintendo SDK libraries written in C: MultiBoot (lib/multiboot.c,
# pokeemerald's) and the EEPROM_V120 save library (lib/eeprom.c). Each keeps
# the flags the SDK built it with. The SDK built its save libraries at -O1,
# as pokeemerald's Makefile does for agb_flash; at -O2 seven of the EEPROM
# library's nine functions differ.
LIB_C_OBJS := $(BUILD)/lib/multiboot.o $(BUILD)/lib/eeprom.o
$(BUILD)/lib/eeprom.o: CFLAGS := $(subst -O2,-O1,$(CFLAGS))
$(BUILD)/src/link/SioTransferIntr.o: CFLAGS := $(subst -O2,-O1,$(CFLAGS))
$(BUILD)/src/link/IslandSioTransferIntr.o: CFLAGS := $(subst -O2,-O1,$(CFLAGS))

OBJS     := $(C_SRCS:%.c=$(BUILD)/%.o) $(DATA_SRCS:%.s=$(BUILD)/%.o) \
	$(NEWLIB_OBJS) $(AGBSYSCALL_OBJS) $(AGBSYSCALL_COPY_OBJS) $(M4A_OBJS) $(LIB_C_OBJS) $(LIBGCC_OBJS) $(CRT0_OBJS)

.PHONY: all check check-code test clean disasm tools convert pointers shift-test sdl port-objects run
ifeq ($(PORTABLE),1)
all: port-objects
else
all: $(TARGET).gba
endif

# Each C file is preprocessed, run through preproc (which expands INCBIN_*
# calls into array initialisers), compiled by agbcc, then assembled. preproc
# writes to a file rather than a pipe, so a failure stops the build. The .s
# intermediate is kept -- it's what you diff against the target asm when a
# function doesn't match.
#
# gas rounds every .text section's end up to its alignment (4, from the
# `.align 2, 0` agbcc emits before each function and literal pool) using NOP
# filler (46c0); -no-pad-sections does not stop it. The ROM has no NOPs -- the
# gap between functions is zero bytes. An explicit trailing `.align 2, 0`
# makes gas fill that gap with zeros instead, matching the ROM. Same trick on
# the asm fragments below: a fragment cut at a 2-mod-4 boundary would
# otherwise get the same NOP. The align goes in .text, never .rodata: a
# src/data/ file's arrays sit back to back with the data around them, so its
# .rodata keeps the alignment of its widest array and gets no end padding.
#
# The high 0x0833/0x0834 module was linked with its own libgcc copy, so its
# `/` and `%` libcalls land on sub_08344BB8 and friends, not the low copies
# that symbols.ld aliases. Every caller at or above ModuleSampleFreqSet uses the
# high copies and no lower caller does (checked against the ROM's bl
# targets), so objects that ldscript.ld places in the EWRAM images get their
# libcall symbols renamed after assembly, whatever their file is called. A
# src/sub_083[3-9]*.c file counts too, so it matches before it's placed.
# A call through a function pointer goes through a _call_via_rN stub, so
# those names take the high copy's addresses too.
# Writing the call as `/` instead of a bare sub_08344BB8 call matters: a
# libcall carries a hard-r0 return that an ordinary call does not, and that
# changes register allocation.
HIGH_LIBGCC_OBJS := $(sort $(patsubst src/%.c,$(BUILD)/src/%.o,$(wildcard src/sub_083[3-9]*.c)) \
	$(shell sed -n '/^    \.high_module /,/^    \.text_tail /s|^ *\(build/src/[^.]*\.o\).*|\1|p' ldscript.ld))
HIGH_LIBGCC_REDEFINES := --redefine-sym __divsi3=sub_08344BB8 \
	--redefine-sym __modsi3=sub_08344C50 --redefine-sym __umodsi3=sub_08344DA8 \
	--redefine-sym __muldi3=sub_08344D20 --redefine-sym __negdi2=sub_08344D90 \
	--redefine-sym _call_via_r0=_08344B7C --redefine-sym _call_via_r1=_08344B80 \
	--redefine-sym _call_via_r2=_08344B84 --redefine-sym _call_via_r3=_08344B88 \
	--redefine-sym _call_via_r4=_08344B8C --redefine-sym _call_via_r5=_08344B90 \
	--redefine-sym _call_via_r6=_08344B94 --redefine-sym _call_via_r7=_08344B98 \
	--redefine-sym _call_via_r8=_08344B9C --redefine-sym _call_via_r9=_08344BA0 \
	--redefine-sym _call_via_sl=_08344BA4 --redefine-sym _call_via_fp=_08344BA8 \
	--redefine-sym _call_via_ip=_08344BAC --redefine-sym _call_via_sp=_08344BB0 \
	--redefine-sym _call_via_lr=_08344BB4
# ponytail: every C object depends on every .inc; per-file deps (scaninc)
# if that rebuild gets slow.
$(BUILD)/src/%.o: src/%.c $(wildcard include/*.h src/data/*.h) $(ASM_INCS) Makefile $(PREPROC)
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $< -o $(BUILD)/src/$*.i
	$(PREPROC) $(TARGET) $(BUILD)/src/$*.i > $(BUILD)/src/$*.pp.i
	$(CC1) $(CFLAGS) $(BUILD)/src/$*.pp.i -o $(BUILD)/src/$*.s
	printf '\t.text\n\t.align 2, 0\n' >> $(BUILD)/src/$*.s
	$(AS) $(ASFLAGS) -I include -o $@ $(BUILD)/src/$*.s
	$(if $(filter $(HIGH_LIBGCC_OBJS),$@),$(OBJCOPY) $(HIGH_LIBGCC_REDEFINES) $@)

NEWLIB_CPPFLAGS := -I tools/agbcc/ginclude -I $(NEWLIB_DIR)/include -nostdinc -undef \
	-DABORT_PROVIDED -DHAVE_GETTIMEOFDAY -D__thumb__ -DARM_RDI_MONITOR \
	-D__GNUC__ -DINTERNAL_NEWLIB -D__USER_LABEL_PREFIX__=
NEWLIB_CFLAGS := -O2 -fno-builtin
# mallocr.c yields one object per -DDEFINE_* entry point.
NEWLIB_MALLOC_OBJS := $(addprefix $(BUILD)/lib/newlib/stdlib/,mallocr.o freer.o callocr.o)
$(BUILD)/lib/newlib/stdlib/mallocr.o: NEWLIB_DEFS := -DDEFINE_MALLOC
$(BUILD)/lib/newlib/stdlib/freer.o: NEWLIB_DEFS := -DDEFINE_FREE
$(BUILD)/lib/newlib/stdlib/callocr.o: NEWLIB_DEFS := -DDEFINE_CALLOC
$(BUILD)/lib/newlib/stdlib/mbtowc_r.o: NEWLIB_CFLAGS += -fshort-enums

define newlib_compile
@mkdir -p $(@D)
$(CPP) $(NEWLIB_CPPFLAGS) $(NEWLIB_DEFS) $< -o $(@:.o=.i)
$(CC1) $(NEWLIB_CFLAGS) $(@:.o=.i) -o $(@:.o=.s)
printf '.text\n\t.align\t2, 0\n' >> $(@:.o=.s)
$(AS) -mcpu=arm7tdmi -o $@ $(@:.o=.s)
endef

$(filter-out $(NEWLIB_MALLOC_OBJS),$(NEWLIB_OBJS)): $(BUILD)/lib/newlib/%.o: $(NEWLIB_DIR)/%.c Makefile
	$(newlib_compile)
$(NEWLIB_MALLOC_OBJS): $(NEWLIB_DIR)/stdlib/mallocr.c Makefile
	$(newlib_compile)

$(AGBSYSCALL_OBJS): $(BUILD)/lib/agbsyscall/%.o: lib/libagbsyscall.s lib/function.inc Makefile
	@mkdir -p $(@D)
	$(AS) -mcpu=arm7tdmi -I lib --defsym L_$*=1 -o $@ $<
$(AGBSYSCALL_COPY_OBJS): $(BUILD)/lib/agbsyscall/%.o: lib/libagbsyscall.s lib/function.inc Makefile
	@mkdir -p $(@D)
	$(AS) -mcpu=arm7tdmi -I lib --defsym L_$(call syscall_of,$*)=1 -o $@ $<
	$(OBJCOPY) --redefine-sym $(call syscall_of,$*)=$* $@

$(LIBGCC1_OBJS): $(BUILD)/lib/libgcc/%.o: $(LIBGCC_DIR)/lib1thumb.asm Makefile
	@mkdir -p $(@D)
	cc -E -undef -nostdinc -DL$* -x assembler-with-cpp -o $(@:.o=.s) $<
	printf '.text\n\t.align\t2, 0\n' >> $(@:.o=.s)
	$(AS) -mcpu=arm7tdmi -o $@ $(@:.o=.s)

define libgcc_compile
@mkdir -p $(@D)
$(CPP) -undef -I tools/agbcc/ginclude -I $(LIBGCC_DIR) -nostdinc $(1) $< -o $(@:.o=.i)
$(CC1) -O2 $(@:.o=.i) -o $(@:.o=.s)
printf '.text\n\t.align\t2, 0\n' >> $(@:.o=.s)
$(AS) -mcpu=arm7tdmi -o $@ $(@:.o=.s)
endef
$(LIBGCC2_OBJS): $(BUILD)/lib/libgcc/%.o: $(LIBGCC_DIR)/libgcc2.c $(LIBGCC_DIR)/longlong.h Makefile
	$(call libgcc_compile,-DL$*)
$(LIBGCC_FP_OBJS): %.o: %.c
	$(call libgcc_compile,)
$(BUILD)/lib/libgcc/fp-bit.c: $(LIBGCC_DIR)/fp-bit-base.c Makefile
	@mkdir -p $(@D)
	printf '#define FLOAT\n#define FLOAT_BIT_ORDER_MISMATCH\n' | cat - $< > $@
$(BUILD)/lib/libgcc/dp-bit.c: $(LIBGCC_DIR)/fp-bit-base.c Makefile
	@mkdir -p $(@D)
	printf '#define FLOAT_BIT_ORDER_MISMATCH\n#define FLOAT_WORD_ORDER_MISMATCH\n' | cat - $< > $@

$(LIBGCC_HIGH_OBJS): $(BUILD)/lib/libgcc/high/%.o: $(BUILD)/lib/libgcc/%.o Makefile
	@mkdir -p $(@D)
	arm-none-eabi-nm $< | while read a b c; do \
		if [ "$$a" = U ]; then [ "$$b" != __div0 ] || echo "__div0 sub_08344C4C"; \
		elif [ "$$b" = T ]; then case $$c in _call_via_*) p=_;; *) p=sub_;; esac; \
			printf '%s %s%08X\n' $$c $$p $$((0x$$a + 0x$(call libgcc_high_base,$*))); fi; \
	done > $@.syms
	$(OBJCOPY) --redefine-syms=$@.syms $< $@

$(LIBGCC_ISLAND_OBJS): $(BUILD)/lib/libgcc/island/%.o: $(BUILD)/lib/libgcc/%.o Makefile
	@mkdir -p $(@D)
	arm-none-eabi-nm $< | while read a b c; do [ "$$b" != T ] || \
		printf '%s _%08X\n' $$c $$((0x$$a + 0x08364810)); done > $@.syms
	$(OBJCOPY) --redefine-syms=$@.syms $< $@

$(LIB_C_OBJS): $(BUILD)/lib/%.o: lib/%.c $(wildcard include/*.h include/gba/*.h) Makefile
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $< -o $(@:.o=.i)
	$(CC1) $(CFLAGS) $(@:.o=.i) -o $(@:.o=.s)
	printf '.text\n\t.align\t2, 0\n' >> $(@:.o=.s)
	$(AS) $(ASFLAGS) -o $@ $(@:.o=.s)

$(BUILD)/lib/rom_header.o $(BUILD)/lib/crt0.o $(BUILD)/lib/crt0_island.o: $(BUILD)/lib/%.o: lib/%.s lib/function.inc Makefile
	@mkdir -p $(@D)
	$(AS) -mcpu=arm7tdmi -I lib -o $@ $<
$(BUILD)/lib/crt0_high.o: $(BUILD)/lib/crt0.o Makefile
	$(OBJCOPY) $(foreach s,$(CRT0_HIGH_SYMS),--redefine-sym $(s)) $< $@

$(BUILD)/lib/m4a/m4a_1.o: lib/m4a_1.s lib/function.inc lib/m4a_constants.inc Makefile
	@mkdir -p $(@D)
	$(AS) -mcpu=arm7tdmi -I lib -o $@ $<
$(BUILD)/lib/m4a/m4a_1_high.o: $(BUILD)/lib/m4a/m4a_1.o Makefile
	arm-none-eabi-nm $< | while read v t n; do if [ "$$t" = T ]; then \
		printf '%s sub_%08X\n' $$n $$((0x$$v + $(M4A_HIGH_BASE))); fi; done > $@.syms
	$(OBJCOPY) --redefine-syms=$@.syms \
		$(foreach e,$(M4A_HIGH_EXTERNS),--redefine-sym $(e)) $< $@

# Data assets: scripts/assets.py copies each file that assets/*.json lists
# out of baserom.gba, and the asm pulls them in with .incbin. A background
# or tile sheet builds from its editable .png and a palette from its
# editable .pal the way a song builds from its .mid, so the stamp depends
# on those files: editing one rebuilds its blobs into the ROM.
ASSETS_JSON := $(wildcard assets/*.json)
# The scripts extract and blank run: assets.py and the two it imports or calls.
ASSET_SCRIPTS := scripts/assets.py scripts/track_geometry.py scripts/gen_atan2.py
ifneq ($(wildcard baserom.gba),)
ASSET_EDITABLE := $(shell python3 scripts/assets.py list)
ASSET_TRACKS := $(filter assets/tracks/%,$(ASSET_EDITABLE))
ASSET_PNGS := $(filter-out $(ASSET_TRACKS),$(filter %.png,$(ASSET_EDITABLE)))
ASSET_PALS := $(filter-out $(ASSET_TRACKS),$(filter %.pal,$(ASSET_EDITABLE)))
ASSET_STAMP := $(BUILD)/assets/.extracted
$(ASSET_STAMP): baserom.gba $(ASSET_SCRIPTS) $(ASSETS_JSON) $(ASSET_PNGS) $(ASSET_PALS) \
		$(ASSET_TRACKS)
	python3 scripts/assets.py extract
	touch $@

# check-code's reference: the retail ROM with every asset range zeroed.
# Derived from baserom.gba alone, never from the build, and remade whenever
# the asset list changes. Commit it with the assets/*.json change.
$(TARGET).code.sha1: baserom.gba scripts/assets.py $(ASSETS_JSON)
	@mkdir -p $(BUILD)
	python3 scripts/assets.py mask baserom.gba $(BUILD)/baserom.code.gba
	printf '%s  $(BUILD)/$(TARGET).code.gba\n' \
		"$$(shasum < $(BUILD)/baserom.code.gba | cut -d' ' -f1)" > $@

# The pictures and palette files, like the songs: named explicitly
# so make never deletes them as intermediate files, and order-only so one
# that exists is never out of date. `unpack` writes each from baserom.gba
# only when it's missing, so your edits survive every build; delete one to
# get the ROM's. A track's editable files unpack the same way, as a
# folder: the .tmx, the two tile sheets, and the metatile and surface
# tables (the tileset .pngs beside them are previews the build redraws).
$(ASSET_PNGS) $(ASSET_TRACKS): | baserom.gba
	python3 scripts/assets.py unpack $@
$(ASSET_PALS): | baserom.gba
	python3 scripts/assets.py unpack $@
else
# No baserom.gba (CI): every asset is zero fill of its listed size, so the
# code still links at its real addresses. Only check-code can pass.
ASSET_STAMP := $(BUILD)/assets/.blank
$(ASSET_STAMP): $(ASSET_SCRIPTS) $(ASSETS_JSON)
	python3 scripts/assets.py blank
	touch $@
endif

# src/data/ defines ROM data in C with INCBIN_*, which reads the same files.
$(filter $(BUILD)/src/data/%,$(OBJS)): $(ASSET_STAMP)

# Asset conversion tools, built from zeldaret/tmc's sources (tools/tmc).
# A build with baserom.gba needs agb2mid, mid2agb and aif2pcm for the sound
# (below). Only `make convert` needs gbagfx, which needs libpng.
TMC_SRC := tools/tmc/tools/src
ASSET_TOOLS := tools/bin/agb2mid tools/bin/mid2agb tools/bin/aif2pcm tools/bin/gbagfx
tools: $(ASSET_TOOLS)

tools/bin/agb2mid: $(wildcard $(TMC_SRC)/agb2mid/*)
	@mkdir -p $(@D)
	c++ -std=c++17 -O2 -w -I $(TMC_SRC)/agb2mid -o $@ $(TMC_SRC)/agb2mid/*.cpp
tools/bin/mid2agb: $(wildcard $(TMC_SRC)/mid2agb/*)
	@mkdir -p $(@D)
	c++ -std=c++17 -O2 -w -I $(TMC_SRC)/mid2agb -o $@ $(TMC_SRC)/mid2agb/*.cpp
tools/bin/aif2pcm: $(wildcard $(TMC_SRC)/aif2pcm/*)
	@mkdir -p $(@D)
	cc -O2 -w -o $@ $(TMC_SRC)/aif2pcm/*.c -lm
tools/bin/gbagfx: $(wildcard $(TMC_SRC)/gbagfx/*)
	@mkdir -p $(@D)
	cc -O2 -w $(shell pkg-config --cflags libpng) -o $@ $(TMC_SRC)/gbagfx/*.c $(shell pkg-config --libs libpng)

# preproc expands INCBIN_* in C, as in pokeemerald. Every C file goes
# through it.
$(PREPROC): $(wildcard $(TMC_SRC)/preproc/*)
	@mkdir -p $(@D)
	c++ -std=c++17 -O2 -w -o $@ $(TMC_SRC)/preproc/*.cpp

# gbafix writes the cartridge header fields that lib/rom_header.s leaves
# empty. Every build needs it, not only `make convert`.
tools/bin/gbafix: $(TMC_SRC)/gbafix/gbafix.c
	@mkdir -p $(@D)
	cc -O2 -w -o $@ $<

# Sound: every song and sample builds from its editable file under assets/
# (gitignored), as zeldaret/tmc's asset_processor does. `assets.py unpack`
# writes each .mid or .aif from baserom.gba only when it's missing, so your
# edits survive every build; delete one to get the ROM's back. A song goes
# through mid2agb into assembly that data/sound/sounds.s includes in place,
# so its pointers resolve where it links; a sample goes through aif2pcm into
# data/sound/direct_sound_samples.s. Without baserom.gba (CI) there's
# nothing to unpack: `assets.py blank` writes both as zero fill, and none of
# these tools are needed.
ifneq ($(wildcard baserom.gba),)
SOUND_EDITABLE := $(shell python3 scripts/assets.py list)
SOUND_SONGS    := $(filter %.mid,$(SOUND_EDITABLE))
SOUND_SAMPLES  := $(filter %.aif,$(SOUND_EDITABLE))
$(BUILD)/data/sound/sounds.o: $(SOUND_SONGS:%.mid=$(BUILD)/%.s)
$(BUILD)/data/sound/direct_sound_samples.o: $(SOUND_SAMPLES:%.aif=$(BUILD)/%.bin)

# The stamp rebuilds them after a build without baserom.gba zero-filled them.
$(BUILD)/assets/sound/songs/%.s: assets/sound/songs/%.mid tools/bin/mid2agb \
		$(ASSET_STAMP)
	@mkdir -p $(@D)
	python3 scripts/assets.py song $< $@
$(BUILD)/assets/sound/samples/%.bin: assets/sound/samples/%.aif tools/bin/aif2pcm \
		$(ASSET_STAMP)
	@mkdir -p $(@D)
	tools/bin/aif2pcm $< $@

# Named explicitly, so make never deletes them as intermediate files, and
# order-only, so one that exists is never out of date.
$(SOUND_SONGS): | baserom.gba tools/bin/agb2mid
	python3 scripts/assets.py unpack $@
$(SOUND_SAMPLES): | baserom.gba tools/bin/aif2pcm
	python3 scripts/assets.py unpack $@
endif

# Turn the extracted graphics into editable .png files next to their .bin,
# and check that each one converts back exactly.
convert: baserom.gba $(ASSET_TOOLS) $(ASSET_STAMP)
	python3 scripts/assets.py convert

# The data fragments carry #if PLATFORM_GBA guards (asm/macros/*.inc) so the
# hosted build can assemble them too, so every one runs through preproc
# (which inlines the .include files into one flat stream) and cpp (which
# resolves the guards and strips its own line markers) before gas. The
# object bytes are unchanged: the GBA branch of each guard is exactly what
# the fragment said before the guards existed (verified per file by
# assembling both ways and comparing the objects).
ACPP := cc -E -P -x assembler-with-cpp
PORT_ASM_DEPS := Makefile $(PREPROC) $(wildcard asm/macros/*.inc)
$(BUILD)/data/%.o: data/%.s $(PORT_ASM_DEPS) $(ASSET_STAMP)
	@mkdir -p $(@D)
	$(PREPROC) $(TARGET) $< "" > $(BUILD)/data/$*.pp.s
	printf '\t.align 2, 0\n' >> $(BUILD)/data/$*.pp.s
	$(ACPP) -undef -nostdinc -DPLATFORM_GBA=1 $(BUILD)/data/$*.pp.s -o $(BUILD)/data/$*.cpp.s
	$(AS) $(ASFLAGS) -I include -o $@ $(BUILD)/data/$*.cpp.s

# --no-check-sections: the multiboot island's run addresses overlap the
# main program's EWRAM .bss. The overlap is real, since the island runs on a
# different GBA; make check catches any overlap that isn't.
$(TARGET).elf: ldscript.ld symbols.ld $(OBJS)
	$(LD) --no-check-sections -T ldscript.ld -T symbols.ld -o $@ $(OBJS)

# The same link with --emit-relocs, so scripts/pointers.py can tell a word
# the linker computed from one written as a raw number.
$(BUILD)/$(TARGET).relocs.elf: ldscript.ld symbols.ld $(OBJS)
	@$(LD) --no-check-sections --emit-relocs -T ldscript.ld -T symbols.ld -o $@ $(OBJS)

pointers: $(TARGET).gba $(BUILD)/$(TARGET).relocs.elf
	python3 scripts/pointers.py

# The cartridge is 4 MB, zero-filled past the last section.
TITLE      := NASCAR HEAT
GAME_CODE  := ANHE
MAKER_CODE := 70
REVISION   := 0
ROM_END    := 0x08400000

define make_gba
$(OBJCOPY) -O binary --pad-to $(ROM_END) $< $@
tools/bin/gbafix $@ -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(REVISION) --silent
endef

$(TARGET).gba: $(TARGET).elf tools/bin/gbafix
	$(make_gba)

# The shift test: the same objects linked with SHIFT bytes of padding after
# crt0, so almost every function and data table moves. scripts/shift_test.py
# boots both ROMs in mGBA and checks they load the same assets and draw the
# same screens. It needs mGBA (set MGBA if it isn't found).
SHIFT := 0x104
$(BUILD)/shift/ldscript.ld: ldscript.ld Makefile
	@mkdir -p $(@D)
	awk '{ print } /^ *build\/lib\/crt0\.o\(\.text\);$$/ { print "        . += $(SHIFT);" }' $< > $@
	grep -q '+= $(SHIFT);' $@
$(BUILD)/shift/$(TARGET).elf: $(BUILD)/shift/ldscript.ld symbols.ld $(OBJS)
	$(LD) --no-check-sections -T $< -T symbols.ld -o $@ $(OBJS)
$(BUILD)/shift/$(TARGET).gba: $(BUILD)/shift/$(TARGET).elf tools/bin/gbafix
	$(make_gba)
shift-test: $(TARGET).gba $(BUILD)/shift/$(TARGET).gba
	python3 scripts/shift_test.py $(TARGET).elf $(TARGET).gba \
		$(BUILD)/shift/$(TARGET).elf $(BUILD)/shift/$(TARGET).gba

# The only thing that matters: does it reproduce the ROM?
check: $(TARGET).gba check-code
	@shasum -c $(TARGET).sha1 && echo "MATCH" || (echo "MISMATCH"; exit 1)

# Every byte outside the extracted assets: the code and the data still in
# asm/. This is all CI can verify, since it never has baserom.gba.
check-code: $(TARGET).gba $(TARGET).code.sha1
	python3 scripts/externs.py --check
	python3 scripts/assets.py mask $< $(BUILD)/$(TARGET).code.gba
	@shasum -c $(TARGET).code.sha1 && echo "CODE MATCH" || (echo "CODE MISMATCH"; exit 1)

# Tool selftests. These check the verification scripts themselves -- a broken
# matcher that reports MATCH is worse than no matcher.
test:
	python3 scripts/match.py --selftest
	python3 scripts/progress.py --selftest
	python3 scripts/test_progress.py
	python3 scripts/closure.py --selftest
	python3 scripts/seed_functions.py --selftest
	python3 scripts/strings.py --selftest
	python3 scripts/permute.py --selftest
	python3 scripts/pointers.py --selftest
	python3 scripts/shift_test.py --selftest
	python3 scripts/test_alignment.py
	python3 scripts/test_extract_guard.py

# Regenerate a full-ROM reference disassembly. Written OUTSIDE asm/: once
# extraction starts, asm/ is split into fragments with functions removed, and
# overwriting asm/rom.s with the whole ROM would duplicate every symbol.
# Only needed when function discovery changes; the committed asm is the
# working copy.
disasm: nascar.cfg
	@mkdir -p $(BUILD)
	.venv/bin/luvdis disasm baserom.gba -c nascar.cfg -o $(BUILD)/rom_reference.s
	@echo "wrote $(BUILD)/rom_reference.s (asm/ untouched)"

nascar.cfg: baserom.gba scripts/seed_functions.py
	python3 scripts/seed_functions.py baserom.gba $@

# ---------------------------------------------------------------------------
# Hosted-build rules. Same shape as the GBA ones above: preproc expands
# INCBIN_* after cpp, and the data fragments run preproc (inlining the
# .include files) and cpp (resolving the #if PLATFORM_GBA guards) before
# the host assembler. mPtr fields then widen to the host's pointer width.
# ---------------------------------------------------------------------------
ifeq ($(PORTABLE),1)

all: $(PORT_EXE)

$(PORT_BUILD)/src/%.o: src/%.c $(wildcard include/*.h include/gba/*.h src/data/*.h) \
	$(wildcard include/platform/*.h include/platform/shared/*.h include/platform/shared/video/*.h \
	include/platform/shared/audio/*.h include/platform/ext/gbagfx/*.h) Makefile $(PREPROC)
	@mkdir -p $(@D)
	$(CPP_H) $(CPPFLAGS_H) $< -o $(PORT_BUILD)/src/$*.i
	$(PREPROC) $(TARGET) $(PORT_BUILD)/src/$*.i > $(PORT_BUILD)/src/$*.pp.i
	$(CC_H) $(CFLAGS_H) -c $(PORT_BUILD)/src/$*.pp.i -o $@

# The platform layer includes host headers (stdio.h, SDL.h), which the
# split cpp/compile pipeline leaves spelling C99 keywords the -std=gnu89
# compile then can't parse. It is new code, not 2.95-era source, so it
# builds as C11; its declarations-in-for loops are legal there too.
# $(SAN_FLAGS) rides along so ASAN=1 instruments this code too.
$(PORT_BUILD)/src/platform/%.o: CFLAGS_H := -O2 -std=gnu11 -fno-strict-aliasing -fwrapv \
	-Wno-implicit-function-declaration -Wno-pointer-sign -Wno-return-mismatch \
	-Wno-incompatible-pointer-types $(WARN_SHORTEN_64_TO_32) $(SAN_FLAGS)

# libagbsyscall.c #includes the gbagfx LZ77 and RL decoders, so an edit
# to either must rebuild it.
$(PORT_BUILD)/src/platform/libagbsyscall.o: $(wildcard src/platform/ext/gbagfx/*.c)

# The renderer is the platform layer's one C++ source (GPL-2.0+, after
# sa2); it takes the same defines as the C objects, and the sanitizer
# flags with them (ASAN=1).
$(PORT_BUILD)/src/platform/shared/video/gpsp_renderer.cc.o: src/platform/shared/video/gpsp_renderer.cc \
		$(wildcard include/platform/*.h include/platform/*/*.h include/platform/*/*/*.h) Makefile
	@mkdir -p $(@D)
	$(CXX_H) -std=c++11 -O2 -fno-strict-aliasing $(CPPFLAGS_H) $(SAN_FLAGS) -Wno-c99-designator -c $< -o $@

# The hosted songs build with the vendored mPtr mid2agb (tools/mid2agb,
# issue 5 step 4) into the port's own directory: same events as the GBA
# ones, pointer-width fields. The rule sits outside the baserom.gba guard
# so both paths produce $(PORT_BUILD)/songs/%.s: with the ROM each song
# builds from its editable .mid; without it (CI) the zero-fill stubs that
# assets.py blank writes (which carry the global labels the song table,
# src/sound/tables.c, names) copy over, as the GBA build's do.
PORT_SONG_MIDS := $(shell python3 scripts/assets.py list | grep '\.mid$$')
ifneq ($(wildcard baserom.gba),)
$(PORT_BUILD)/songs/%.s: assets/sound/songs/%.mid tools/mid2agb/mid2agb $(ASSET_STAMP)
	@mkdir -p $(@D)
	python3 scripts/assets.py song-p $< $@
else
# The stubs are a side effect of the blank stamp (assets.py blank writes
# the whole tree in one run), so the per-file prerequisite make can see
# is the stamp itself, exactly as the INCBIN reads in the port's src/data
# objects depend on it; the file name rides in $*.
$(PORT_BUILD)/songs/%.s: $(ASSET_STAMP)
	@mkdir -p $(@D)
	cp $(BUILD)/assets/sound/songs/$*.s $@
endif

tools/mid2agb/mid2agb: $(wildcard tools/mid2agb/*.cpp tools/mid2agb/*.h)
	$(MAKE) -C tools/mid2agb

# Each data fragment is staged under the port build first, with the song
# includes repointed at the port's mPtr songs: preproc inlines .include
# files itself, so the path swap has to reach it (the old rule sed'd
# preproc's output, which was too late -- the GBA songs were already
# inlined, 4-byte pointers and all). asm/macros/portable.inc's hosted
# section macros balign the staged data to the pointer width, which
# ld64 requires of the mPtr fields. The final staging rewrites .align to
# .p2align: Darwin's as reads .align as a power of two, but GNU as on
# ELF x86-64 (CI's Linux) reads it as a byte count, which misaligns the
# mPtr fields; .p2align is a power of two everywhere. On Darwin the two
# spellings assemble to identical bytes (verified: same section bytes,
# same label offsets), so the hosted build is unchanged.
$(PORT_BUILD)/data/%.o: data/%.s $(PORT_ASM_DEPS) $(ASSET_STAMP)
	@mkdir -p $(@D)
	sed 's|build/assets/sound/songs/|$(PORT_BUILD)/songs/|' $< > $(PORT_BUILD)/data/$*.src.s
	$(PREPROC) $(TARGET) $(PORT_BUILD)/data/$*.src.s "" > $(PORT_BUILD)/data/$*.pp.s
	printf '\t.balign 4\n' >> $(PORT_BUILD)/data/$*.pp.s
	$(ACPP_H) -DPLATFORM_GBA=0 -DPORTABLE=1 $(PORT_BUILD)/data/$*.pp.s -o $(PORT_BUILD)/data/$*.cpp.s
	sed -e 's/\.align  *\([0-9][0-9]*\) *, */.p2align \1,/' \
	    -e 's/\.align  *\([0-9][0-9]*\) *$$/.p2align \1/' \
	    $(PORT_BUILD)/data/$*.cpp.s > $(PORT_BUILD)/data/$*.p2.s
	$(AS_H) -o $(@:.o=.raw.o) $(PORT_BUILD)/data/$*.p2.s
	$(LD_H) -r $(@:.o=.raw.o) -o $@ && rm -f $(@:.o=.raw.o)

$(filter $(PORT_BUILD)/src/data/%,$(PORT_C_OBJS)): $(ASSET_STAMP)
ifeq ($(PORTABLE),1)
$(PORT_BUILD)/data/sound/sounds.o: $(PORT_SONG_MIDS:assets/sound/songs/%.mid=$(PORT_BUILD)/songs/%.s)
# The samples incbin the GBA build's converted .bin files (the hosted
# build has no copies of its own), so it needs the same dependency as
# the GBA object: a fresh checkout builds them first, and an edited .aif
# rebuilds the object.
ifneq ($(wildcard baserom.gba),)
$(PORT_BUILD)/data/sound/direct_sound_samples.o: $(SOUND_SAMPLES:%.aif=$(BUILD)/%.bin)
endif
endif

port-objects: $(PORT_C_OBJS) $(PORT_DATA_OBJS)

# The link (issue 5 step 5): every hosted object plus the platform
# layer, linked by c++ so the renderer's C++ runtime comes along. Sound
# is stubbed this step; the mixer is step 6. On macOS, ld64's chained
# fixups refuse the songs' inline PATT pointers, mPtr fields the m4a
# command stream packs at odd offsets (unaligned reads are fine on the
# host); -no_fixup_chains falls back to classic relocations for them.
# UNAME_S is set in the ASAN block above; $(SAN_FLAGS) links the
# sanitizer runtimes in when ASAN=1.
ifneq ($(findstring apple,$(PORT_TARGET)),)
PORT_LDFLAGS := -Wl,-no_fixup_chains
else
PORT_LDFLAGS :=
endif
PORT_LDFLAGS += $(SAN_FLAGS)
# Windows: link the GCC and C++ runtimes statically, so the .exe needs
# only SDL2.dll, which the link copies beside it.
ifneq ($(PORT_WINDOWS),)
PORT_LDFLAGS += -static-libgcc -static-libstdc++
endif
$(PORT_EXE): $(PORT_C_OBJS) $(PORT_DATA_OBJS) $(PORT_PLATFORM_OBJS)
	$(CXX_H) -o $@ $(PORT_C_OBJS) $(PORT_DATA_OBJS) $(PORT_PLATFORM_OBJS) \
		$(if $(filter src/platform/pret_sdl/%,$(PORT_FRONT_C)),$(shell $(SDL2_CONFIG) --libs)) \
		-lm $(PORT_LDFLAGS)
	$(if $(PORT_WINDOWS),cp "$(shell $(SDL2_CONFIG) --prefix)/bin/SDL2.dll" $(@D)/)

run: $(PORT_EXE)
	$(PORT_EXE)

endif # PORTABLE

# Convenience, as sa2's: `make sdl` re-invokes make with PLATFORM=sdl.
sdl:
	@$(MAKE) PLATFORM=sdl

clean:
	rm -rf $(BUILD) $(TARGET).elf $(TARGET).gba
