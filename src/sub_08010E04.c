#include "global.h"

extern u8 gUnk_0829F2AC[];

struct Tbl8 {
    u32 p;
    u32 unk;
};

extern struct Tbl8 gUnk_083FDB98[];
extern u32 gUnk_083FDEF4[];
extern u32 *gUnk_083FDF74[];
extern u32 *gUnk_083FDFEC[];

void sub_08016E10(u32 src, u32 dest, u32 control);
void sub_08016E28(u32 a, u32 b);
void sub_08010194(u32 a, u32 b, u32 c);
void sub_080063BC(u8 *p, u32 a1, u32 a2, u8 a3);
void sub_080065A8(void);
u32 sub_08016558(u16 idx);
void sub_08006950(u32 a, u32 b, u32 c);

u8 sub_08010E04(u8 a)
{
    u8 unused[0xC];

    sub_08016558(0x9C);
    sub_080065A8();
    sub_080063BC(gUnk_0829F2AC, 0, 6, 0);
    sub_08006950(gUnk_083FDB98[a].p, 6, 1);
    sub_08016E10(gUnk_083FDEF4[a], 0x05000200, 0x80 << 1);
    sub_08016E28(*gUnk_083FDF74[a], 0x06010000);
    sub_08016E28(*gUnk_083FDFEC[a], 0x06011000);
    sub_08010194(0x38, 0x40, 0);
    sub_08010194(0x78, 0x40, 0x80);
}
