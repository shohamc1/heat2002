TARGET  := nascar-heat
BUILD   := build

AS      := arm-none-eabi-as
LD      := arm-none-eabi-ld
OBJCOPY := arm-none-eabi-objcopy
CC1     := tools/agbcc/agbcc
# binutils ships no arm-none-eabi-cpp; agbcc does the compiling, so any C
# preprocessor works here. -undef/-nostdinc keep the host's macros and headers
# out of a build that must reproduce a 2002 ROM.
CPP     := cc -E -x c

ASFLAGS := -mcpu=arm7tdmi -mthumb-interwork
CFLAGS  := -O2 -mthumb-interwork -fhex-asm -fprologue-bugfix -Wimplicit -Wparentheses
CPPFLAGS := -I include -I tools/agbcc/include -iquote include -nostdinc -undef

C_SRCS   := $(wildcard src/*.c)
ASM_SRCS := $(wildcard asm/*.s)
OBJS     := $(C_SRCS:%.c=$(BUILD)/%.o) $(ASM_SRCS:%.s=$(BUILD)/%.o)

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
$(BUILD)/src/%.o: src/%.c $(wildcard include/*.h) Makefile
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $< -o $(BUILD)/src/$*.i
	$(CC1) $(CFLAGS) $(BUILD)/src/$*.i -o $(BUILD)/src/$*.s
	printf '\t.align 2, 0\n' >> $(BUILD)/src/$*.s
	$(AS) $(ASFLAGS) -I include -o $@ $(BUILD)/src/$*.s

$(BUILD)/asm/%.o: asm/%.s Makefile
	@mkdir -p $(@D)
	cat $< > $(BUILD)/asm/$*.s
	printf '\t.align 2, 0\n' >> $(BUILD)/asm/$*.s
	$(AS) $(ASFLAGS) -I include -o $@ $(BUILD)/asm/$*.s

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
	python3 scripts/seed_functions.py --selftest
	python3 scripts/strings.py --selftest
	python3 scripts/test_alignment.py

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
