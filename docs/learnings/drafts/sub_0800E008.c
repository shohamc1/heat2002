#include "global.h"

struct S { u32 v0; u32 frame; };

extern u8 gUnk_080000B2;
extern u32 gUnk_080000AC;
extern u32 gUnk_0807C9E8;
extern u32 gUnk_02000590[];
extern u32 gUnk_083FDA50[];
extern u8 gUnk_0807C9CC[];
extern u8 gUnk_0807C9F0[];
extern u8 gUnk_0807CA08[];
extern u8 gUnk_0807CA20[];
extern u8 gUnk_0807CA34[];
extern u8 gUnk_0807CB58[];
extern s16 gUnk_0202E960[];

void sub_08016E1C(u32 a, u32 b);
void sub_08016E0C(u32 src, u32 dest, u32 mode);
void sub_08016E30(void);
void sub_08006950(u8 *p, u32 a1, u8 a2);
void sub_0800E3C4(u32 a1, u32 a2);
void sub_0800DE9C(u16 x, u16 y);
void sub_0800DE60(u32 id, u32 c);
u32 sub_0800E460(u32 *a1);
void sub_0800DFCC(void);

u32 sub_0800E008(void)
{
    struct S s;
    u32 *pf;
    volatile u32 *dma;
    u32 v;
    u32 off;
    u32 next;
    u8 idx;
    u8 t;
    u16 i;

    s.frame = 0;
    idx = 0;
    *(volatile u16 *)0x04000200 = 1;
    if (gUnk_080000B2 == 0x96 && gUnk_080000AC == gUnk_0807C9E8)
        *(volatile u16 *)0x04000200 |= 0x2000;
    *(volatile u16 *)0x04000004 = 8;
    *(volatile u16 *)0x04000208 = 1;
    gUnk_02000590[1] = 0x0800DFC1;
    gUnk_02000590[0] = 0x0800E641;
    *(volatile u16 *)0x04000000 &= 0xEFFF;
    i = 0;
    off = idx * 4;
    v = idx << 15;
    pf = &s.frame;
    next = idx + 1;
    do {
        sub_08016E1C(gUnk_083FDA50[i], 0x06010000 + i * 0x200);
        i++;
    } while (i <= 2);
    dma = (volatile u32 *)0x040000D4;
    dma[0] = (u32)gUnk_0807CB58;
    dma[1] = 0x05000200;
    dma[2] = 0x84000028;
    (void)dma[2];
    s.v0 = 0xA0;
    dma[0] = (u32)&s.v0;
    dma[1] = (u32)gUnk_0202E960;
    dma[2] = 0x85000100;
    (void)dma[2];
    sub_08016E0C((u32)gUnk_0202E960, 0x07000000, 0x100);
    *(volatile u16 *)0x04000000 |= 0x1040;
    sub_0800E3C4(1, *(u32 *)(gUnk_0807C9CC + off));
    i = 0;
    do {
        sub_08006950(gUnk_0807C9F0, i + 8, 1);
        i++;
    } while (i <= 3);
    for (;;) {
        t = (u8)((v + s.frame * 4) >> 10);
        sub_0800DE9C(t, 0x64);
        sub_0800DE60(t, 0x64);
        sub_08006950(gUnk_0807CA08, 8, 1);
        sub_08006950(gUnk_0807CA20, 9, 1);
        sub_08006950(gUnk_0807CA34, 0xA, 1);
        if (sub_0800E460(pf) != 0) {
            idx = next;
            if (idx == 7)
                break;
            sub_0800E3C4(1, *(u32 *)(gUnk_0807C9CC + idx * 4));
            s.frame = 0;
            v = idx << 15;
            next = idx + 1;
        }
        sub_08016E0C((u32)gUnk_0202E960, 0x07000000, 0x100);
        sub_08016E30();
    }
    s.v0 = 0xA0;
    dma = (volatile u32 *)0x040000D4;
    dma[0] = (u32)&s.v0;
    dma[1] = (u32)gUnk_0202E960;
    dma[2] = 0x85000100;
    (void)dma[2];
    sub_08016E0C((u32)gUnk_0202E960, 0x07000000, 0x100);
    sub_0800DFCC();
    return 0;
}
