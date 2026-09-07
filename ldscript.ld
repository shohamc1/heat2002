ENTRY(rom_entry)
SECTIONS
{
    . = 0x08000000;
    rom_entry = .;
    .text : ALIGN(4)
    {
        build/asm/rom.o(.text*);
        build/src/sub_0800048C.o(.text*);
        build/asm/rom_080004B8.o(.text*);
        build/src/sub_08006734.o(.text*);
        build/asm/rom_08006738.o(.text*);
        build/src/sub_08016558.o(.text*);
        build/asm/rom_08016568.o(.text*);
        /* Catch-all, not the primary placement mechanism: every object above
           is listed explicitly and must stay in address order. This exists
           so a *forgotten* listing (a new src/*.c or asm/*.s add without a
           matching line above) still links -- landing past the real ROM's
           end, where it grows the output and breaks the SHA1 loudly --
           instead of silently vanishing into /DISCARD/ with `make check`
           still printing MATCH. */
        *(.text*);
    }
    /DISCARD/ : { *(*); }
}
