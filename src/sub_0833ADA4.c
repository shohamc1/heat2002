#include "global.h"
#include "gba/io_reg.h"

extern u32 gUnk_03007FF0;

struct Snd {
    u32 magic;
    u8 unk4;
    u8 f5;
    u8 f6;
    u8 f7;
    u8 pad[0x48];
    u8 chan[12][0x40];
};

void sub_0833AE90(void);
void sub_0833AD00(u32 a);

void sub_0833ADA4(u32 cmd)
{
    struct Snd *s = (struct Snd *)gUnk_03007FF0;
    u32 t;
    u8 *p;

    if (s->magic != 0x68736D53)
        return;
    s->magic = s->magic + 1;
    t = cmd & 0xFF;
    if (t != 0) {
        t &= 0x7F;
        s->f5 = t;
    }
    t = cmd & 0xF00;
    if (t != 0) {
        s->f6 = t >> 8;
        for (t = 12, p = &s->chan[0][0]; t != 0; t--, p += 0x40)
            *p = 0;
    }
    t = cmd & 0xF000;
    if (t != 0)
        s->f7 = t >> 12;
    t = cmd & 0xB00000;
    if (t != 0) {
        t = (t & 0x300000) >> 14;
        REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | t;
    }
    t = cmd & 0xF0000;
    if (t != 0) {
        sub_0833AE90();
        sub_0833AD00(t);
    }
    s->magic = 0x68736D53;
}
