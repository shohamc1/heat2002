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
# RAM-module objects link into their standalone image only (see the
# build/ram rule below); the main ROM embeds the image as data. They must
# not reach the main link, or the trailing *(.text*) catch-all places them
# twice over.
RAM_MODULE_OBJS := build/src/sub_08364550.o build/src/sub_08340EFC.o
OBJS     := $(filter-out $(RAM_MODULE_OBJS),$(C_SRCS:%.c=$(BUILD)/%.o) $(ASM_SRCS:%.s=$(BUILD)/%.o))

.PHONY: all check test clean disasm
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

$(BUILD)/asm/%.o: asm/%.s Makefile
	@mkdir -p $(@D)
	cat $< > $(BUILD)/asm/$*.s
	printf '\t.align 2, 0\n' >> $(BUILD)/asm/$*.s
	$(AS) $(ASFLAGS) -I include -o $@ $(BUILD)/asm/$*.s

# All symbols.ld expression RHS names (libgcc aliases, call-via tables)
# resolved for standalone blob links; their values derive from their names.
RAM_DEFSYMS := $(shell awk -F' = ' '/ = /{split($$2,a,";"); split(a[1],b," +"); print b[1]}' symbols.ld | sort -u | awk '/^(sub_|_)[0-9A-Fa-f]{8}$$/{n=$$0; sub(/^(sub_|_)/,"",n); printf "--defsym %s=0x%s ", $$0, n}')

# Blob-only alias stubs (never in the main link; they would collide with
# the real matched functions).
build/ram/aliases_0834.o: ram/aliases_0834.s Makefile
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# RAM-module images: functions whose retail build linked at an EWRAM base
# (match.py's RAM_LINK_OVERRIDES). Compiled to C objects like everything
# else, but linked into a standalone image at the module's EWRAM base and
# embedded into the ROM as data at the function's ROM address -- the same
# way the retail build shipped the module.
RAM_MODULES := sub_08364550

build/ram/sub_08364550.bin: build/src/sub_08364550.o symbols.ld Makefile
	@mkdir -p $(dir $@)
	$(LD) -Ttext=0x02000668 -e 0x02000668 --defsym gUnk_03000C00=0x03000C00 -o $@.elf $<
	$(OBJCOPY) -O binary --only-section=.text $@.elf $@

build/ram/sub_08340EFC.bin: build/src/sub_08340EFC.o build/ram/aliases_0834.o symbols.ld Makefile
	@mkdir -p $(dir $@)
	$(LD) -Ttext=0x0200847C -e 0x0200847C -T symbols.ld $(RAM_DEFSYMS) -o $@.elf $< build/ram/aliases_0834.o
	$(OBJCOPY) -O binary --only-section=.text $@.elf $@

build/asm/ram_08364550.o: build/ram/sub_08364550.bin
build/asm/ram_08340EFC.o: build/ram/sub_08340EFC.bin

$(TARGET).elf: ldscript.ld symbols.ld $(OBJS)
	$(LD) -T ldscript.ld -T symbols.ld -o $@ $(OBJS)

$(TARGET).gba: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

# The only thing that matters: does it reproduce the ROM?
check: $(TARGET).gba
	@shasum -c $(TARGET).sha1 && echo "MATCH" || (echo "MISMATCH"; exit 1)

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
