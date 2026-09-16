#include "global.h"

struct Seq {
    u8 pad0[8];
    u8 unk8;
    u8 pad9[0x2C - 9];
    u8 *unk2C;
    u8 pad30[4];
    u32 unk34;
};

struct SeqChan {
    u8 unk0;
    u8 pad1[0xB - 1];
    s8 unkB;
    u8 padC;
    u8 unkD;
    u8 padE[0x50 - 0xE];
};

void sub_0833B81C(struct Seq *s, u16 a1, u16 a2)
{
    struct SeqChan *c;
    u32 mask;
    s32 i;

    if (s->unk34 != 0x68736D53)
        return;
    s->unk34 = s->unk34 + 1;
    for (i = s->unk8, c = (struct SeqChan *)s->unk2C, mask = 1; i > 0; i--, c++, mask = mask << 1) {
        if ((a1 & mask) != 0 && (c->unk0 & 0x80) != 0) {
            c->unkB = (s16)a2 >> 8;
            c->unkD = a2;
            c->unk0 = c->unk0 | 0x0C;
        }
    }
    s->unk34 = 0x68736D53;
}
