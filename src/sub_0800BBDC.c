#include "global.h"

struct Unk0800BBDCEntry {
    /* 0x00 */ u8 kind;
    /* 0x01 */ u8 pad1[5];
    /* 0x06 */ u16 w6;
    /* 0x08 */ u8 pad8[12];
}; /* size 0x14 */

struct Unk0800BBDC {
    /* 0x000 */ u8 pad[0x154];
    /* 0x154 */ u32 f154;
};

void sub_0800BBDC(u32 a0, struct Unk0800BBDCEntry *list, struct Unk0800BBDC *dst)
{
    while (list->kind != 0xFF)
        list++;
    list--;
    dst->f154 = list->w6;
}
