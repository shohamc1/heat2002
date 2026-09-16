#ifndef GUARD_GBA_TYPES_H
#define GUARD_GBA_TYPES_H

// Relies on this project's own u8/u16/u32 typedefs from global.h, which
// every translation unit already includes before any gba/*.h header.

struct BgCnt
{
    u16 priority:2;
    u16 charBaseBlock:2;
    u16 dsCharBaseBlock:2;
    u16 mosaic:1;
    u16 palettes:1;
    u16 screenBaseBlock:5;
    u16 areaOverflowMode:1;
    u16 screenSize:2;
};

struct OamData
{
    /*0x00*/ u32 y:8;
    /*0x01*/ u32 affineMode:2;  // 0x1, 0x2 -> 0x4
             u32 objMode:2;     // 0x4, 0x8 -> 0xC
             u32 mosaic:1;      // 0x10
             u32 bpp:1;         // 0x20
             u32 shape:2;       // 0x40, 0x80 -> 0xC0

    /*0x02*/ u32 x:9;
             u32 matrixNum:5;   // bits 3/4 are h-flip/v-flip if not in affine mode
             u32 size:2;        // 0x4000, 0x8000 -> 0xC000

    /*0x04*/ u16 tileNum:10;    // 0x3FF
             u16 priority:2;    // 0x400, 0x800 -> 0xC00
             u16 paletteNum:4;
    /*0x06*/ u16 affineParam;
};

// The RGB555 layout of one BG/OBJ palette entry, overlaid on the raw u16
// GBA color format, so a raw u16 and its r/g/b components are always in
// sync.
union Color
{
    struct
    {
        u16 r:5;
        u16 g:5;
        u16 b:5;
        u16 unused:1;
    } rgb;
    u16 raw;
};

#endif // GUARD_GBA_TYPES_H
