#include "global.h"
#include "gba/io_reg.h"

struct SndWork
{
    u32 magic;
    u8 filler4[0xC - 0x04];
    u8 unk0C;
    u8 filler0D[0x1C - 0x0D];
    u32 unk1C;
    u8 filler20[0x28 - 0x20];
    u32 unk28;
    u32 unk2C;
    u32 unk30;
};

struct Tail
{
    u8 filler0[0x01];
    u8 unk1;
    u8 filler2[0x1C - 0x02];
    u8 unk1C;
};

struct SndWork2
{
    u8 filler0[0x01];
    u8 unk1;
    u8 filler2[0x1C - 0x02];
    u8 unk1C;
    u8 filler1D[0x41 - 0x1D];
    u8 unk41;
    u8 filler42[0x5C - 0x42];
    u8 unk5C;
    u8 filler5D[0x81 - 0x5D];
    u8 unk81;
    u8 filler82[0x9C - 0x82];
    u8 unk9C;
    u8 filler9D[0xC0 - 0x9D];
    struct Tail tail;
};


extern struct SndWork *gUnk_03007FF0;
extern u32 gUnk_02038DE0[];
extern u8 gUnk_00000000;
extern u8 gUnk_02002F81;
extern u8 gUnk_02001CE5;
extern u8 gUnk_02001CF9;
extern u8 gUnk_020030D9;
extern u8 gUnk_02001C7D;
extern u8 gUnk_02002281;
extern u8 gUnk_02001A09;
extern u8 gUnk_02002635;
extern u8 gUnk_020026B5;
extern u8 gUnk_020028C9;
extern u8 gUnk_02002811;
extern u8 gUnk_02002769;

extern void sub_08344B64(u32 a, u32 b, u32 c);

void sub_0833AAB8(struct SndWork2 *a1)
{
    u32 sp[1];
    u32 v;
    struct SndWork *p;

    REG_SOUNDCNT_X = 0x8F;
    REG_SOUNDCNT_L = 0x77;
    REG_NR12 = 0x08;
    REG_NR22 = 0x08;
    REG_NR42 = 0x08;
    REG_NR14 = 0x80;
    REG_NR24 = 0x80;
    REG_NR44 = 0x80;
    REG_NR30 = 0x00;
    REG_SOUNDCNT_L = 0xFF77;
    p = gUnk_03007FF0;
    v = p->magic;
    if (v == 0x68736D53)
    {
        p->magic = v + 1;
        gUnk_02038DE0[8] = (u32)&gUnk_02002F81;
        gUnk_02038DE0[0x11] = (u32)&gUnk_02001CE5;
        gUnk_02038DE0[0x13] = (u32)&gUnk_02001CF9;
        gUnk_02038DE0[0x1C] = (u32)&gUnk_020030D9;
        gUnk_02038DE0[0x1D] = (u32)&gUnk_02001C7D;
        gUnk_02038DE0[0x1E] = (u32)&gUnk_02002281;
        gUnk_02038DE0[0x1F] = (u32)&gUnk_02001A09;
        gUnk_02038DE0[0x20] = (u32)&gUnk_02002635;
        gUnk_02038DE0[0x21] = (u32)&gUnk_020026B5;
        p->unk1C = (u32)a1;
        p->unk28 = (u32)&gUnk_020028C9;
        p->unk2C = (u32)&gUnk_02002811;
        p->unk30 = (u32)&gUnk_02002769;
        p->unk0C = (u8)(u32)&gUnk_00000000;
        sp[0] = 0;
        sub_08344B64((u32)sp, (u32)a1, 0x05000040);
        a1->unk1 = 1;
        a1->unk1C = 0x11;
        a1->unk41 = 2;
        a1->unk5C = 0x22;
        a1->unk81 = 3;
        a1->unk9C = 0x44;
        {
            struct Tail *t = &a1->tail;

            t->unk1 = 4;
            t->unk1C = 0x88;
        }
        p->magic = v;
    }
}
