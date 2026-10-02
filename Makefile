.DEFAULT_GOAL := all

# Project and GBA toolchain
TARGET  := nascar-heat
BUILD   := build

AS      := arm-none-eabi-as
LD      := arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy
CC1     := tools/agbcc/old_agbcc
# Expands INCBIN_U8/U16/U32 in C after cpp (include/global.h).
PREPROC := tools/bin/preproc
# Use the host preprocessor; -undef/-nostdinc exclude host macros and headers.
CPP     := cc -E -x c

ASFLAGS := -mcpu=arm7tdmi -mthumb-interwork
CFLAGS  := -O2 -mthumb-interwork -fhex-asm -Wimplicit -Wparentheses
CPPFLAGS := -I include -I tools/agbcc/include -iquote include -nostdinc -undef

# Exclude the desktop platform layer from the GBA build.
C_SRCS   := $(shell find src -name '*.c' ! -path 'src/platform/*')
DATA_SRCS := $(wildcard data/*.s data/sound/*.s)
# Bodies of ASM_FUNC functions (include/global.h), included from C.
ASM_INCS := $(shell find asm -name '*.inc' 2>/dev/null | grep -v '^asm/macros/')

# Build selection: gba (default) or sdl.
PLATFORM ?= gba
ifeq ($(PLATFORM),gba)
PORTABLE := 0
else
PORTABLE := 1
endif

# GBA runtime libraries

# newlib uses its original flags and explicit linker placement.
NEWLIB_DIR  := tools/agbcc/libc
NEWLIB_OBJS := $(addprefix $(BUILD)/lib/newlib/,$(addsuffix .o, \
	stdio/sprintf stdio/vfprintf stdio/wsetup stdlib/dtoa stdio/fflush \
	stdio/findfp stdlib/freer stdio/fvwrite stdio/fwalk locale/locale stdio/makebuf \
	stdlib/mallocr stdlib/mbtowc_r string/memchr string/memcpy \
	string/memmove string/memset stdlib/mlock stdlib/mprec math/s_isinf \
	math/s_isnan reent/sbrkr stdio/stdio string/strcmp string/strlen \
	arm/syscalls reent/writer stdlib/callocr reent/closer errno/errno reent/fstatr \
	arm/libcfunc reent/lseekr reent/readr reent/impure))

# BIOS calls have separate copies for the main program and EWRAM images.
AGBSYSCALL_OBJS := $(addprefix $(BUILD)/lib/agbsyscall/,$(addsuffix .o, \
	CpuFastSet CpuSet IntrWait LZ77UnCompVram MultiBoot RLUnCompVram \
	RegisterRamReset VBlankIntrWait))
AGBSYSCALL_COPIES := sub_08344B60:CpuFastSet sub_08344B64:CpuSet \
	sub_08344B68:IntrWait sub_08344B70:RLUnCompVram sub_08344B74:VBlankIntrWait \
	sub_083647F8:CpuFastSet sub_083647FC:CpuSet sub_08364800:LZ77UnCompVram \
	sub_08364804:RegisterRamReset sub_08364808:VBlankIntrWait
AGBSYSCALL_COPY_OBJS := $(foreach c,$(AGBSYSCALL_COPIES),$(BUILD)/lib/agbsyscall/$(firstword $(subst :, ,$(c))).o)
syscall_of = $(lastword $(subst :, ,$(filter $(1):%,$(AGBSYSCALL_COPIES))))

# The high-module sound engine uses renamed functions and globals.
M4A_OBJS := $(BUILD)/lib/m4a/m4a_1.o $(BUILD)/lib/m4a/m4a_1_high.o
M4A_HIGH_BASE := 0x08339B78
M4A_HIGH_EXTERNS := Clear64byte=ModuleClear64byte ClearChain=ModuleClearChain \
	FadeOutBody=ModuleFadeOutBody MidiKeyToFreq=ModuleMidiKeyToFreq TrkVolPitSet=ModuleTrkVolPitSet \
	gClockTable=gModule_ClockTable gMPlayJumpTableTemplate=gUnk_0200C668

# libgcc keeps its original flags. Module copies use distinct symbol names.
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

# Each GBA image has its own startup code and interrupt dispatcher.
CRT0_OBJS := $(BUILD)/lib/rom_header.o $(BUILD)/lib/crt0.o $(BUILD)/lib/crt0_high.o \
	$(BUILD)/lib/crt0_island.o
CRT0_HIGH_SYMS := Init=sub_08339780 IntrMain=sub_083397C4 \
	AgbMain=ModuleAgbMain gIntrTable=gModule_IntrTable

# Preserve the SDK and serial-interrupt optimization levels for matching.
LIB_C_OBJS := $(BUILD)/lib/multiboot.o $(BUILD)/lib/eeprom.o
$(BUILD)/lib/eeprom.o: CFLAGS := $(subst -O2,-O1,$(CFLAGS))
$(BUILD)/src/link/SioTransferIntr.o: CFLAGS := $(subst -O2,-O1,$(CFLAGS))
$(BUILD)/src/link/IslandSioTransferIntr.o: CFLAGS := $(subst -O2,-O1,$(CFLAGS))

OBJS     := $(C_SRCS:%.c=$(BUILD)/%.o) $(DATA_SRCS:%.s=$(BUILD)/%.o) \
	$(NEWLIB_OBJS) $(AGBSYSCALL_OBJS) $(AGBSYSCALL_COPY_OBJS) $(M4A_OBJS) $(LIB_C_OBJS) $(LIBGCC_OBJS) $(CRT0_OBJS)

.PHONY: all check check-code test clean disasm tools convert pointers shift-test sdl port-objects run
ifeq ($(PORTABLE),0)
all: $(TARGET).gba
endif

# GBA C: cpp -> INCBIN expansion -> agbcc -> assembler.
# Keep intermediates for instruction diffs. Explicit zero alignment prevents
# gas from adding NOP padding. Switch to .text so .rodata is not padded.
# EWRAM code must call its own libgcc copy; rename those references after
# assembly. Unplaced high-module drafts use their address-based filenames.
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

# Assets and editable source files
# The stamp tracks graphics, palettes, and track edits. Songs and samples
# have separate conversion rules below.
ASSETS_JSON := $(wildcard assets/*.json)
# The scripts extract and blank run: assets.py and the two it imports or calls.
ASSET_SCRIPTS := scripts/assets.py scripts/track_geometry.py scripts/gen_atan2.py
ASSET_EDITABLE := $(shell python3 scripts/assets.py list)
SOUND_SONGS := $(filter %.mid,$(ASSET_EDITABLE))
SOUND_SAMPLES := $(filter %.aif,$(ASSET_EDITABLE))
ifneq ($(wildcard baserom.gba),)
ASSET_TRACKS := $(filter assets/tracks/%,$(ASSET_EDITABLE))
ASSET_PNGS := $(filter-out $(ASSET_TRACKS),$(filter %.png,$(ASSET_EDITABLE)))
ASSET_PALS := $(filter-out $(ASSET_TRACKS),$(filter %.pal,$(ASSET_EDITABLE)))
ASSET_STAMP := $(BUILD)/assets/.extracted
$(ASSET_STAMP): baserom.gba $(ASSET_SCRIPTS) $(ASSETS_JSON) $(ASSET_PNGS) $(ASSET_PALS) \
		$(ASSET_TRACKS)
	python3 scripts/assets.py extract
	touch $@

# Derive the code hash from the retail ROM, never the build.
# Commit it with asset-manifest changes.
$(TARGET).code.sha1: baserom.gba scripts/assets.py $(ASSETS_JSON)
	@mkdir -p $(BUILD)
	python3 scripts/assets.py mask baserom.gba $(BUILD)/baserom.code.gba
	printf '%s  $(BUILD)/$(TARGET).code.gba\n' \
		"$$(shasum < $(BUILD)/baserom.code.gba | cut -d' ' -f1)" > $@

# Explicit targets preserve editable files. Order-only ROM dependencies
# unpack missing files without replacing user edits.
$(ASSET_PNGS) $(ASSET_TRACKS) $(ASSET_PALS): | baserom.gba
	python3 scripts/assets.py unpack $@
else
# CI uses zero-filled assets. Only check-code can pass without a ROM.
ASSET_STAMP := $(BUILD)/assets/.blank
$(ASSET_STAMP): $(ASSET_SCRIPTS) $(ASSETS_JSON)
	python3 scripts/assets.py blank
	touch $@
endif

# src/data/ defines ROM data in C with INCBIN_*, which reads the same files.
$(filter $(BUILD)/src/data/%,$(OBJS)): $(ASSET_STAMP)

# Asset tools from zeldaret/tmc. Only gbagfx requires libpng.
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

# preproc expands INCBIN_* in C.
$(PREPROC): $(wildcard $(TMC_SRC)/preproc/*)
	@mkdir -p $(@D)
	c++ -std=c++17 -O2 -w -o $@ $(TMC_SRC)/preproc/*.cpp

# gbafix fills the cartridge header after linking.
tools/bin/gbafix: $(TMC_SRC)/gbafix/gbafix.c
	@mkdir -p $(@D)
	cc -O2 -w -o $@ $<

# Build sound from editable MIDI and AIFF files. Without a ROM, the
# asset stamp supplies zero-filled stubs instead.
ifneq ($(wildcard baserom.gba),)
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

# Preprocess shared assembly to select GBA macros and expand includes.
ACPP := cc -E -P -x assembler-with-cpp
PORT_ASM_DEPS := Makefile $(PREPROC) $(wildcard asm/macros/*.inc)
$(BUILD)/data/%.o: data/%.s $(PORT_ASM_DEPS) $(ASSET_STAMP)
	@mkdir -p $(@D)
	$(PREPROC) $(TARGET) $< "" > $(BUILD)/data/$*.pp.s
	printf '\t.align 2, 0\n' >> $(BUILD)/data/$*.pp.s
	$(ACPP) -undef -nostdinc -DPLATFORM_GBA=1 $(BUILD)/data/$*.pp.s -o $(BUILD)/data/$*.cpp.s
	$(AS) $(ASFLAGS) -I include -o $@ $(BUILD)/data/$*.cpp.s

# GBA linking and ROM output

# The island runs on another GBA and legitimately overlaps main RAM.
# Keep --no-check-sections; make check verifies the resulting ROM.
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

# Link a shifted copy to test pointer relocation. Requires mGBA.
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

# Verification
check: $(TARGET).gba check-code
	@shasum -c $(TARGET).sha1 && echo "MATCH" || (echo "MISMATCH"; exit 1)

# Verify all bytes outside extracted asset ranges; works without a ROM.
check-code: $(TARGET).gba $(TARGET).code.sha1
	python3 scripts/externs.py --check
	python3 scripts/assets.py mask $< $(BUILD)/$(TARGET).code.gba
	@shasum -c $(TARGET).code.sha1 && echo "CODE MATCH" || (echo "CODE MISMATCH"; exit 1)

# Test the build and verification tools.
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

# Generate reference disassembly under build/, never over source files.
disasm: $(BUILD)/nascar.cfg
	@mkdir -p $(BUILD)
	.venv/bin/luvdis disasm baserom.gba -c $(BUILD)/nascar.cfg -o $(BUILD)/rom_reference.s
	@echo "wrote $(BUILD)/rom_reference.s"

$(BUILD)/nascar.cfg: baserom.gba scripts/seed_functions.py
	@mkdir -p $(@D)
	python3 scripts/seed_functions.py baserom.gba $@

ifeq ($(PORTABLE),1)
# SDL configuration
# Host OS selects the sanitizer front end; the compiler triple selects
# output format and cross-compilation settings.
UNAME_S := $(shell uname -s)
ASAN ?= 0
# Override these for cross-compilation. Asset tools use the host cc/c++.
CC_H := cc
CXX_H := c++
AS_H := as
# The relocatable link normalizes Mach-O assembly symbol tables.
LD_H := ld
SDL2_CONFIG := sdl2-config
# Preprocess with the target compiler so type widths match compilation.
CPP_H = $(CC_H) -E -x c
ACPP_H = $(CC_H) -E -P -x assembler-with-cpp
# Detect Windows from the target compiler, not the build machine.
PORT_TARGET := $(shell $(CC_H) -dumpmachine 2>/dev/null)
PORT_WINDOWS := $(if $(findstring mingw,$(PORT_TARGET)),1)
# Keep native, Windows, and sanitizer objects in separate build trees.
PORT_BUILD := build/$(PLATFORM)$(if $(PORT_WINDOWS),-windows)$(if $(filter 1,$(ASAN)),-asan)
# Probe compiler-specific warning flags.
WARN_SHORTEN_64_TO_32 := $(shell $(CC_H) -Wshorten-64-to-32 -fsyntax-only -x c /dev/null >/dev/null 2>&1 && echo -Wshorten-64-to-32)
# C89 callbacks use several signatures; suppress the clang warning.
NO_WARN_NON_PROTOTYPE := $(shell $(CC_H) -Wdeprecated-non-prototype -fsyntax-only -x c /dev/null >/dev/null 2>&1 && echo -Wno-deprecated-non-prototype)
CPPFLAGS_H := -I include -DPLATFORM_$(shell echo $(PLATFORM) | tr '[:lower:]' '[:upper:]')=1 \
	-DPLATFORM_GBA=0 -DPORTABLE=1 $(shell $(SDL2_CONFIG) --cflags 2>/dev/null)
# Preserve C89 syntax, type-punning, and signed wraparound.
CFLAGS_H := -O2 -std=gnu89 -fno-strict-aliasing -fwrapv \
	-Wno-implicit-function-declaration -Wno-pointer-sign -Wno-return-mismatch \
	-Wno-incompatible-pointer-types $(WARN_SHORTEN_64_TO_32) $(NO_WARN_NON_PROTOTYPE)

# macOS ASan uses the null front end: SDL2 compatibility libraries can
# fail during SDL3 loading under ASan. Other hosts keep the SDL front end.
ifeq ($(ASAN),1)
# Recovery lets a soak collect multiple errors with halt_on_error=0.
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

# Select main-program objects from linker sections; exclude EWRAM images
# and dead code. Include .text_tail and main RAM sections for shared data.
# Avoid bare closing parentheses in these $(shell ...) expressions.
PORT_SECTIONS := '/^    \.text : ALIGN/,/^    }$$/p;/^    \.text_tail /,/^    }$$/p;/^    \.bss_[A-Za-z0-9_]* 0x/,/^    }$$/p;/^    \.iwram_[A-Za-z0-9_]* 0x/,/^    }$$/p'
PORT_C_SRCS := $(shell sed -n $(PORT_SECTIONS) ldscript.ld \
	| sed -n 's|^ *build/src/\([^. ]*\)\.o.*|src/\1.c|p' | grep -v '^src/dead/' | sort -u)
PORT_DATA_SRCS := $(shell sed -n $(PORT_SECTIONS) ldscript.ld \
	| sed -n 's|^ *build/data/\([^. ]*\)\.o.*|data/\1.s|p' | sort -u)
PORT_C_OBJS := $(PORT_C_SRCS:src/%.c=$(PORT_BUILD)/src/%.o)
PORT_DATA_OBJS := $(PORT_DATA_SRCS:data/%.s=$(PORT_BUILD)/data/%.o)

# Build shared platform code plus one front end. libagbsyscall.c includes
# the gbagfx sources directly; the renderer is the only C++ source.
PORT_PLATFORM_C_SRCS := $(filter-out $(PORT_C_SRCS) src/platform/ext/% \
	src/platform/pret_sdl/% src/platform/null_front/%,$(wildcard src/platform/*.c) \
	$(wildcard src/platform/*/*.c) $(wildcard src/platform/*/*/*.c)) $(PORT_FRONT_C)
PORT_PLATFORM_OBJS := $(PORT_PLATFORM_C_SRCS:src/%.c=$(PORT_BUILD)/src/%.o) \
	$(PORT_BUILD)/src/platform/shared/video/gpsp_renderer.cc.o
PORT_EXE := $(PORT_BUILD)/$(TARGET).sdl$(if $(PORT_WINDOWS),.exe)

# SDL compilation and linking

all: $(PORT_EXE)

$(PORT_BUILD)/src/%.o: src/%.c $(wildcard include/*.h include/gba/*.h src/data/*.h) \
	$(wildcard include/platform/*.h include/platform/shared/*.h include/platform/shared/video/*.h \
	include/platform/shared/audio/*.h include/platform/ext/gbagfx/*.h) Makefile $(PREPROC)
	@mkdir -p $(@D)
	$(CPP_H) $(CPPFLAGS_H) $< -o $(PORT_BUILD)/src/$*.i
	$(PREPROC) $(TARGET) $(PORT_BUILD)/src/$*.i > $(PORT_BUILD)/src/$*.pp.i
	$(CC_H) $(CFLAGS_H) -c $(PORT_BUILD)/src/$*.pp.i -o $@

# Platform code and host headers require C11. Game code stays C89.
$(PORT_BUILD)/src/platform/%.o: CFLAGS_H := -O2 -std=gnu11 -fno-strict-aliasing -fwrapv \
	-Wno-implicit-function-declaration -Wno-pointer-sign -Wno-return-mismatch \
	-Wno-incompatible-pointer-types $(WARN_SHORTEN_64_TO_32) $(SAN_FLAGS)

# Track the decoder sources included directly by libagbsyscall.c.
$(PORT_BUILD)/src/platform/libagbsyscall.o: $(wildcard src/platform/ext/gbagfx/*.c)

# The C++ renderer uses the same platform defines and sanitizer flags.
$(PORT_BUILD)/src/platform/shared/video/gpsp_renderer.cc.o: src/platform/shared/video/gpsp_renderer.cc \
		$(wildcard include/platform/*.h include/platform/*/*.h include/platform/*/*/*.h) Makefile
	@mkdir -p $(@D)
	$(CXX_H) -std=c++11 -O2 -fno-strict-aliasing $(CPPFLAGS_H) $(SAN_FLAGS) -Wno-c99-designator -c $< -o $@

# Hosted songs use pointer-width fields. Without a ROM, copy the stubs
# produced by the shared asset stamp.
ifneq ($(wildcard baserom.gba),)
$(PORT_BUILD)/songs/%.s: assets/sound/songs/%.mid tools/mid2agb/mid2agb $(ASSET_STAMP)
	@mkdir -p $(@D)
	python3 scripts/assets.py song-p $< $@
else
# The stamp creates all song stubs in one pass.
$(PORT_BUILD)/songs/%.s: $(ASSET_STAMP)
	@mkdir -p $(@D)
	cp $(BUILD)/assets/sound/songs/$*.s $@
endif

tools/mid2agb/mid2agb: $(wildcard tools/mid2agb/*.cpp tools/mid2agb/*.h)
	$(MAKE) -C tools/mid2agb

# Rewrite song paths before preproc expands includes. Use .p2align so
# Darwin and GNU assemblers agree on alignment. The relocatable link
# normalizes the data objects before the final native link.
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
$(PORT_BUILD)/data/sound/sounds.o: $(SOUND_SONGS:assets/sound/songs/%.mid=$(PORT_BUILD)/songs/%.s)
# Reuse converted samples and rebuild when their AIFF files change.
ifneq ($(wildcard baserom.gba),)
$(PORT_BUILD)/data/sound/direct_sound_samples.o: $(SOUND_SAMPLES:%.aif=$(BUILD)/%.bin)
endif

port-objects: $(PORT_C_OBJS) $(PORT_DATA_OBJS)

# Link with C++ for the renderer runtime.
PORT_LDFLAGS := $(SAN_FLAGS)
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

# Convenience targets
sdl:
	@$(MAKE) PLATFORM=sdl

clean:
	rm -rf $(BUILD) $(TARGET).elf $(TARGET).gba
