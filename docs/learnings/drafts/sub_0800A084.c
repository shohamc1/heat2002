/*
 * PARKED (wave 4): rebuild diverges from the ROM (object 588 bytes; first
 * diff at 0x0800A09A -- branch/pool offsets drift, code is 2 bytes shorter
 * than target through this region). Dead-agent mid-edit state, same class
 * as sub_0800C430. Also needs a hand-cut when fixed: extract.py refuses
 * because jump-table .byte rows sit inside the block.
 */
#include "global.h"

struct Car {
    u8 pad00[0x2C];
    s32 unk2C;
    u8 pad30[0x3E - 0x30];
    u8 unk3E;
    u16 unk40;
    u8 pad42[0x7C - 0x42];
    u8 unk7C;
    u8 unk7D;
    u8 pad7E[0x9C - 0x7E];
    s32 unk9C;
    u8 padA0[2];
    u16 unkA2;
    u8 padA4[0xE4 - 0xA4];
    u32 unkE4;
    u32 unkE8;
    u32 unkEC;
    u8 padF0[0x13C - 0xF0];
    u32 unk13C;
    u8 pad140[0x14C - 0x140];
    u32 unk14C;
    u8 pad150[0x175 - 0x150];
    u8 unk175;
    u8 pad176[0x190 - 0x176];
};

extern struct Car gUnk_0202A550[];
extern u8 gUnk_0202EEB0;
extern u8 gUnk_0202A51C;
extern u8 gUnk_020020A8;
extern u8 gUnk_020021E0;
extern u8 gUnk_020020DC;

s32 sub_0800A034(u8 *a, s32 b);
void sub_0800A5BC(struct Car *p);

void sub_0800A084(struct Car *p, s32 a)
{
    u8 unused[40];
    register s32 r8a asm("r8");
    register u16 *pa asm("r12");
    u8 *pi;
    register u32 *pt asm("r9");
    u16 *pw;
    s32 r7;
    s32 r3;

    r8a = a;
    r7 = 0;
    if (r8a & 1) {
        if (gUnk_0202EEB0 != 0 && p->unk175 == 0) {
            p->unk9C -= 10;
            if (p->unk9C < 0)
                p->unk9C = 0;
        }
        pa = &p->unkA2;
        *pa = 0x100;
        if (p == gUnk_0202A550 && p->unk9C == 0 && (gUnk_0202A51C & 8) != 0)
            *pa = p->unk9C;
        if (gUnk_020020A8 != 0) {
            pi = &p->unk3E;
            pt = &p->unkE4;
            r7 += (*pa * ((u16 *)*pt)[*pi]) >> 6;
        } else {
            pi = &p->unk3E;
            pt = &p->unkE4;
            r7 += (*pa * ((u16 *)*pt)[*pi]) >> 8;
        }
        if (p->unk2C > 0)
            r7 += (*pa * ((u16 *)*pt)[*pi]) >> 5;
        pw = &p->unk40;
    } else {
        if (p->unk2C > 0) {
            p->unk14C = (-p->unk2C) >> 2;
            pi = &p->unk3E;
        } else if (p->unkA2 != 0) {
            p->unkA2 = p->unkA2 - 0x20;
            if (p->unkA2 > 0x8000)
                p->unkA2 = 0;
            r7 = (p->unkA2 * ((u16 *)p->unkE4)[p->unk3E]) >> 8;
            pi = &p->unk3E;
        } else {
            r7 = -(p->unk40 * 4) >> 16;
            pi = &p->unk3E;
        }
        pw = &p->unk40;
    }
    if (r8a & 2) {
        r7 += -(*pw * 6) >> 8;
        p->unk14C += 0x18000;
        if (p->unk2C > 0) {
            if (gUnk_020021E0 != 0 || (gUnk_020020DC != 0 && p->unk7D != 0))
                sub_0800A5BC(p);
            else if (p->unk2C > 0x3E800)
                p->unk14C = 0x3E800 - p->unk2C;
        }
    }
    if (p->unk2C < 0) {
        if (*pw + r7 > 0x32C8)
            r7 = 0x32C8 - *pw;
        if (*pw + r7 < 0)
            r7 = -*pw;
        *pw = *pw + r7;
    } else {
        *pw = 0;
    }
    if (p->unk2C > 0) {
        r3 = 0;
    } else {
        r3 = (s16)sub_0800A034((u8 *)p, p->unk2C);
    }
    p->unk13C = -(-((u16 *)p->unkE8)[*pi] * r7) >> 8;
    if (p->unk2C > 0) {
        *pi = 0;
        *pw = 0;
    } else {
        *pw = (-((u16 *)p->unkEC)[r3] * p->unk2C) >> 8;
        *pi = r3;
    }
}
