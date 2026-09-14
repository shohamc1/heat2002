#include "global.h"

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
extern u32 gUnk_02001D90[];
extern u8 gUnk_00000000;
extern u8 gUnk_08002341;
extern u8 gUnk_080010A5;
extern u8 gUnk_080010B9;
extern u8 gUnk_08002499;
extern u8 gUnk_0800103D;
extern u8 gUnk_08001C89;
extern u8 gUnk_08001BD1;
extern u8 gUnk_08001B29;

extern void sub_08001640(u32 a);
extern void sub_08000DC8(void);
extern void sub_080019F4(void);
extern void sub_08001A74(void);

void sub_08016E10(u32 a, u32 b, u32 c);

void sub_080013F8(struct SndWork2 *a1)
{
    u32 sp[1];
    u32 v;
    struct SndWork *p;

    *(volatile u16 *)0x04000084 = 0x8F;
    *(volatile u16 *)0x04000080 = 0x77;
    *(volatile u8 *)0x04000063 = 0x08;
    *(volatile u8 *)0x04000069 = 0x08;
    *(volatile u8 *)0x04000079 = 0x08;
    *(volatile u8 *)0x04000065 = 0x80;
    *(volatile u8 *)0x0400006D = 0x80;
    *(volatile u8 *)0x0400007D = 0x80;
    *(volatile u8 *)0x04000070 = 0x00;
    *(volatile u16 *)0x04000080 = 0xFF77;
    p = gUnk_03007FF0;
    v = p->magic;
    if (v == 0x68736D53)
    {
        p->magic = v + 1;
        gUnk_02001D90[8] = (u32)&gUnk_08002341;
        gUnk_02001D90[0x11] = (u32)&gUnk_080010A5;
        gUnk_02001D90[0x13] = (u32)&gUnk_080010B9;
        gUnk_02001D90[0x1C] = (u32)&gUnk_08002499;
        gUnk_02001D90[0x1D] = (u32)&gUnk_0800103D;
        gUnk_02001D90[0x1E] = (u32)sub_08001640;
        gUnk_02001D90[0x1F] = (u32)sub_08000DC8;
        gUnk_02001D90[0x20] = (u32)sub_080019F4;
        gUnk_02001D90[0x21] = (u32)sub_08001A74;
        p->unk1C = (u32)a1;
        p->unk28 = (u32)&gUnk_08001C89;
        p->unk2C = (u32)&gUnk_08001BD1;
        p->unk30 = (u32)&gUnk_08001B29;
        p->unk0C = (u8)(u32)&gUnk_00000000;
        sp[0] = 0;
        sub_08016E10((u32)sp, (u32)a1, 0x05000040);
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
