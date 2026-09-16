#include "global.h"

struct SndWork
{
    u32 magic;
    u8 filler4[2];
    u8 unk6;
    u8 unk7;
    u8 filler8[0x28 - 0x08];
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
};

extern struct SndWork *gUnk_03007FF0;
extern u32 gUnk_02001D90[];

void sub_08000958(u32 a);
void sub_08001640(u32 a);
void sub_08016E10(u32 a, u32 b, u32 c);

void sub_08001548(struct SndWork *a1)
{
    u32 sp[1];

    a1->magic = 0;
    if (*(volatile u32 *)0x040000C4 & 0x02000000)
        *(volatile u32 *)0x040000C4 = 0x84400004;
    if (*(volatile u32 *)0x040000D0 & 0x02000000)
        *(volatile u32 *)0x040000D0 = 0x84400004;
    *(volatile u16 *)0x040000C6 = 0x400;
    *(volatile u16 *)0x040000D2 = 0x400;
    *(volatile u16 *)0x04000084 = 0x8F;
    *(volatile u16 *)0x04000082 = 0xA90E;
    *(volatile u8 *)0x04000089 = (*(volatile u8 *)0x04000089 & 0x3F) | 0x40;
    *(volatile u32 *)0x040000BC = (u32)a1 + 0x350;
    *(volatile u32 *)0x040000C0 = 0x040000A0;
    *(volatile u32 *)0x040000C8 = (u32)a1 + 0x980;
    *(volatile u32 *)0x040000CC = 0x040000A4;
    gUnk_03007FF0 = a1;
    sp[0] = 0;
    sub_08016E10((u32)sp, (u32)a1, 0x050003EC);
    a1->unk6 = 8;
    a1->unk7 = 0xF;
    a1->unk38 = 0x08000E3D;
    a1->unk28 = 0x080025B9;
    a1->unk2C = 0x080025B9;
    a1->unk30 = 0x080025B9;
    a1->unk3C = 0x080025B9;
    {
        u32 *t = gUnk_02001D90;

        sub_08000958((u32)t);
        a1->unk34 = (u32)t;
    }
    sub_08001640(0x40000);
    a1->magic = 0x68736D53;
}
