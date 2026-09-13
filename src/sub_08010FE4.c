#include "global.h"

struct Inner
{
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
};

struct Big
{
    u8 pad[0xC];
    u32 fieldC;
    struct Inner *inner;
    u32 field14;
};

extern struct Big gUnk_083FDA78[];
extern u8 gUnk_0202EED8;

extern void sub_08016558(u16 idx);
void sub_080065A8(void);
void sub_080063BC(u8 *p, u32 a1, u32 a2, u8 a3);
void sub_08006950(u32 a, u32 b, u32 c);
extern void sub_08016E10(u32 src, u32 dest, u32 control);
void sub_08016E28(u32 a, u32 b);
void sub_08010194(u32 a, u32 b, u32 c);
void sub_0801027C(u32 tile, u32 pal, u32 c);

u8 sub_08010FE4(u8 a, u8 b)
{
    u8 unused[0x34];
    u8 *p;

    if (b != 0) {
        sub_08016558(0xA1);
        sub_080065A8();
    }
    p = (u8 *)0x0829F2AC;
    sub_080063BC(p, 0, 4, 0);
    sub_080063BC(p, 0, 5, 0);
    if (a != 3) {
        sub_08006950(gUnk_083FDA78[a].fieldC, 4, 1);
    } else {
        sub_08006950(0x0829F2CC, 4, 1);
        sub_08006950(0x0829F2D8, 5, 1);
    }
    sub_08016E10(gUnk_083FDA78[a].field14, 0x05000200, 0x80 << 1);
    sub_08016E10(0x0830E670, 0x050003E0, 0x10);
    sub_08016E28(gUnk_083FDA78[a].inner->f0, 0x06010000);
    sub_08016E28(gUnk_083FDA78[a].inner->f4, 0x06011000);
    sub_08016E28(gUnk_083FDA78[a].inner->f8, 0x06012000);
    sub_08016E28(gUnk_083FDA78[a].inner->fC, 0x06013000);
    sub_08010194(0x38, 0x20, 0);
    sub_08010194(0x78, 0x20, 0x80);
    sub_08010194(0x38, 0x60, 0x80 << 1);
    sub_08010194(0x78, 0x60, 0xC0 << 1);
    if (b != 0 && (gUnk_0202EED8 & 4) != 0) {
        sub_08016E28(0x0830E618, 0x06014000);
        sub_08016E28(0x0830E690, 0x06015000);
        if (a != 0)
            sub_0801027C(0x10, 0x48, 0x80 << 2);
        if (a != 0xB)
            sub_0801027C(0xD0, 0x48, 0xA0 << 2);
    }
    gUnk_0202EED8++;
}
