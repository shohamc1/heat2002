ENTRY(rom_entry)
SECTIONS
{
    . = 0x08000000;
    rom_entry = .;
    .text : ALIGN(4)
    {
        build/asm/rom.o(.text*);
        *(.text*);
    }
    /DISCARD/ : { *(*); }
}
