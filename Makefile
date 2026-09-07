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
CFLAGS  := -O2 -mthumb-interwork -fhex-asm -Wimplicit -Wparentheses
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
# The awk strips agbcc's leading `.align 2, 0` (word-align the function
# start) down to `.align 1, 0` before assembling. That directive is a no-op
# for content -- a function is always first in its own object, so offset 0
# is already word-aligned -- but gas records it as the section's alignment
# and then silently rounds the section's *end* up to match, padding with
# NOP. Invisible in one monolithic asm/rom.s (one section, padded once at
# EOF if at all); real now that a decompiled function is its own object
# sandwiched between two asm fragments at an exact address -- the phantom
# NOPs land inside the ROM instead of whatever byte was really there. Only
# the FIRST `.align 2, 0` is touched (a real literal pool's own alignment
# stays put), which is why one function per src/*.c file is a hard
# requirement, not just a convention: a second function in the same file
# reintroduces the alignment gas re-pads against, and the fix silently stops
# applying to it. (sed's `-i` flag differs between BSD and GNU and one of
# them always breaks; awk's redirect-to-temp-then-rename has no such split.)
$(BUILD)/src/%.o: src/%.c
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $< -o $(BUILD)/src/$*.i
	$(CC1) $(CFLAGS) $(BUILD)/src/$*.i -o $(BUILD)/src/$*.s
	awk '!done && /\.align[[:space:]]+2, 0/ { sub(/\.align[[:space:]]+2, 0/, ".align 1, 0"); done=1 } { print }' \
		$(BUILD)/src/$*.s > $(BUILD)/src/$*.s.tmp && mv $(BUILD)/src/$*.s.tmp $(BUILD)/src/$*.s
	$(AS) $(ASFLAGS) -I include -o $@ $(BUILD)/src/$*.s

$(BUILD)/asm/%.o: asm/%.s
	@mkdir -p $(@D)
	$(AS) $(ASFLAGS) -I include -o $@ $<

$(TARGET).elf: ldscript.ld $(OBJS)
	$(LD) -T ldscript.ld -o $@ $(OBJS)

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

# Regenerate asm/rom.s from the base ROM. Only needed when function discovery
# changes -- the committed asm is the working copy.
disasm: nascar.cfg
	.venv/bin/luvdis disasm baserom.gba -c nascar.cfg -o asm/rom.s

nascar.cfg: baserom.gba scripts/seed_functions.py
	python3 scripts/seed_functions.py baserom.gba $@

clean:
	rm -rf $(BUILD) $(TARGET).elf $(TARGET).gba
