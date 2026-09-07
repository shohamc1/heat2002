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

.PHONY: all check clean disasm
all: $(TARGET).gba

# Each C file is preprocessed, run through agbcc, then assembled. The .s
# intermediate is kept -- it's what you diff against the target asm when a
# function doesn't match.
$(BUILD)/src/%.o: src/%.c
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $< -o $(BUILD)/src/$*.i
	$(CC1) $(CFLAGS) $(BUILD)/src/$*.i -o $(BUILD)/src/$*.s
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

# Regenerate asm/rom.s from the base ROM. Only needed when function discovery
# changes -- the committed asm is the working copy.
disasm: nascar.cfg
	.venv/bin/luvdis disasm baserom.gba -c nascar.cfg -o asm/rom.s

nascar.cfg: baserom.gba scripts/seed_functions.py
	python3 scripts/seed_functions.py baserom.gba $@

clean:
	rm -rf $(BUILD) $(TARGET).elf $(TARGET).gba
