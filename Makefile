TARGET  := nascar-heat
BUILD   := build

AS      := arm-none-eabi-as
LD      := arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy
CC1     := tools/agbcc/old_agbcc
# binutils ships no arm-none-eabi-cpp; agbcc does the compiling, so any C
# preprocessor works here. -undef/-nostdinc keep the host's macros and headers
# out of a build that must reproduce a 2002 ROM.
CPP     := cc -E -x c

ASFLAGS := -mcpu=arm7tdmi -mthumb-interwork
CFLAGS  := -O2 -mthumb-interwork -fhex-asm -Wimplicit -Wparentheses
CPPFLAGS := -I include -I tools/agbcc/include -iquote include -nostdinc -undef

C_SRCS   := $(wildcard src/*.c)
ASM_SRCS := $(wildcard asm/*.s)
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
M4A_HIGH_EXTERNS := Clear64byte=sub_0833ABF4 ClearChain=sub_0833ABE0 \
	FadeOutBody=sub_0833B0B4 MidiKeyToFreq=sub_0833A78C TrkVolPitSet=sub_0833B134 \
	gClockTable=gUnk_0200C8DC gMPlayJumpTableTemplate=gUnk_0200C668

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
LIBGCC_OBJS := $(LIBGCC1_OBJS) $(LIBGCC2_OBJS) $(LIBGCC_FP_OBJS) $(LIBGCC_HIGH_OBJS)

# Nintendo SDK libraries written in C: MultiBoot (lib/multiboot.c,
# pokeemerald's) and the EEPROM_V120 save library (lib/eeprom.c). Each keeps
# the flags the SDK built it with. The SDK built its save libraries at -O1,
# as pokeemerald's Makefile does for agb_flash; at -O2 seven of the EEPROM
# library's nine functions differ.
LIB_C_OBJS := $(BUILD)/lib/multiboot.o $(BUILD)/lib/eeprom.o
$(BUILD)/lib/eeprom.o: CFLAGS := $(subst -O2,-O1,$(CFLAGS))

OBJS     := $(C_SRCS:%.c=$(BUILD)/%.o) $(ASM_SRCS:%.s=$(BUILD)/%.o) \
	$(NEWLIB_OBJS) $(AGBSYSCALL_OBJS) $(AGBSYSCALL_COPY_OBJS) $(M4A_OBJS) $(LIB_C_OBJS) $(LIBGCC_OBJS)

.PHONY: all check check-code test clean disasm tools convert
all: $(TARGET).gba

# Each C file is preprocessed, run through agbcc, then assembled. The .s
# intermediate is kept -- it's what you diff against the target asm when a
# function doesn't match.
#
# gas rounds every .text section's end up to its alignment (4, from the
# `.align 2, 0` agbcc emits before each function and literal pool) using NOP
# filler (46c0); -no-pad-sections does not stop it. The ROM has no NOPs -- the
# gap between functions is zero bytes. An explicit trailing `.align 2, 0`
# makes gas fill that gap with zeros instead, matching the ROM. Same trick on
# the asm fragments below: a fragment cut at a 2-mod-4 boundary would
# otherwise get the same NOP.
#
# The high 0x0833/0x0834 module was linked with its own libgcc copy, so its
# `/` and `%` libcalls land on sub_08344BB8 and friends, not the low copies
# that symbols.ld aliases. Every caller at or above sub_0833AD00 uses the
# high copies and no lower caller does (checked against the ROM's bl
# targets), so objects from src/sub_083[3-9]*.c get their libcall symbols
# renamed after assembly. Writing the call as `/` instead of a bare
# sub_08344BB8 call matters: a libcall carries a hard-r0 return that an
# ordinary call does not, and that changes register allocation.
HIGH_LIBGCC_OBJS := $(patsubst src/%.c,$(BUILD)/src/%.o,$(wildcard src/sub_083[3-9]*.c))
HIGH_LIBGCC_REDEFINES := --redefine-sym __divsi3=sub_08344BB8 \
	--redefine-sym __modsi3=sub_08344C50 --redefine-sym __umodsi3=sub_08344DA8 \
	--redefine-sym __muldi3=sub_08344D20
$(BUILD)/src/%.o: src/%.c $(wildcard include/*.h) Makefile
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $< -o $(BUILD)/src/$*.i
	$(CC1) $(CFLAGS) $(BUILD)/src/$*.i -o $(BUILD)/src/$*.s
	printf '\t.align 2, 0\n' >> $(BUILD)/src/$*.s
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

$(LIB_C_OBJS): $(BUILD)/lib/%.o: lib/%.c $(wildcard include/*.h include/gba/*.h) Makefile
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $< -o $(@:.o=.i)
	$(CC1) $(CFLAGS) $(@:.o=.i) -o $(@:.o=.s)
	printf '.text\n\t.align\t2, 0\n' >> $(@:.o=.s)
	$(AS) $(ASFLAGS) -o $@ $(@:.o=.s)

$(BUILD)/lib/m4a/m4a_1.o: lib/m4a_1.s lib/function.inc lib/m4a_constants.inc Makefile
	@mkdir -p $(@D)
	$(AS) -mcpu=arm7tdmi -I lib -o $@ $<
$(BUILD)/lib/m4a/m4a_1_high.o: $(BUILD)/lib/m4a/m4a_1.o Makefile
	arm-none-eabi-nm $< | while read v t n; do if [ "$$t" = T ]; then \
		printf '%s sub_%08X\n' $$n $$((0x$$v + $(M4A_HIGH_BASE))); fi; done > $@.syms
	$(OBJCOPY) --redefine-syms=$@.syms \
		$(foreach e,$(M4A_HIGH_EXTERNS),--redefine-sym $(e)) $< $@

# Data assets: scripts/assets.py copies each file that assets/*.json lists
# out of baserom.gba, and the asm pulls them in with .incbin.
ASSETS_JSON := $(wildcard assets/*.json)
ifneq ($(wildcard baserom.gba),)
ASSET_STAMP := $(BUILD)/assets/.extracted
$(ASSET_STAMP): baserom.gba scripts/assets.py $(ASSETS_JSON)
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
else
# No baserom.gba (CI): every asset is zero fill of its listed size, so the
# code still links at its real addresses. Only check-code can pass.
ASSET_STAMP := $(BUILD)/assets/.blank
$(ASSET_STAMP): scripts/assets.py $(ASSETS_JSON)
	python3 scripts/assets.py blank
	touch $@
endif

# Asset conversion tools, built from zeldaret/tmc's sources (tools/tmc).
# Only `make convert` needs them; `make check` doesn't. gbagfx needs libpng.
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

# Turn the extracted assets into editable files (songs to .mid, samples to
# .aif) next to their .bin, and check that each one converts back exactly.
convert: baserom.gba $(ASSET_TOOLS) $(ASSET_STAMP)
	python3 scripts/assets.py convert

$(BUILD)/asm/%.o: asm/%.s Makefile $(ASSET_STAMP)
	@mkdir -p $(@D)
	cat $< > $(BUILD)/asm/$*.s
	printf '\t.align 2, 0\n' >> $(BUILD)/asm/$*.s
	$(AS) $(ASFLAGS) -I include -o $@ $(BUILD)/asm/$*.s

# --no-check-sections: the multiboot island's run addresses overlap the
# main program's EWRAM .bss. The overlap is real, since the island runs on a
# different GBA; make check catches any overlap that isn't.
$(TARGET).elf: ldscript.ld symbols.ld $(OBJS)
	$(LD) --no-check-sections -T ldscript.ld -T symbols.ld -o $@ $(OBJS)

$(TARGET).gba: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# The only thing that matters: does it reproduce the ROM?
check: $(TARGET).gba check-code
	@shasum -c $(TARGET).sha1 && echo "MATCH" || (echo "MISMATCH"; exit 1)

# Every byte outside the extracted assets: the code and the data still in
# asm/. This is all CI can verify, since it never has baserom.gba.
check-code: $(TARGET).gba $(TARGET).code.sha1
	python3 scripts/assets.py mask $< $(BUILD)/$(TARGET).code.gba
	@shasum -c $(TARGET).code.sha1 && echo "CODE MATCH" || (echo "CODE MISMATCH"; exit 1)

# Tool selftests. These check the verification scripts themselves -- a broken
# matcher that reports MATCH is worse than no matcher.
test:
	python3 scripts/match.py --selftest
	python3 scripts/progress.py --selftest
	python3 scripts/closure.py --selftest
	python3 scripts/seed_functions.py --selftest
	python3 scripts/strings.py --selftest
	python3 scripts/permute.py --selftest
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

clean:
	rm -rf $(BUILD) $(TARGET).elf $(TARGET).gba
