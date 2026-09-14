#include "global.h"

extern u32 gUnk_083FDEF4[];
extern u32 *gUnk_083FDF74[];
extern u32 *gUnk_083FDFEC[];

extern s32 sub_08010B38(u8 id);
extern u32 sub_08016558(u32 idx);
extern void sub_080065A8(void);
extern void sub_08010AA4(u8 idx);
extern void sub_08016E10(u32 src, u32 dest, u32 control);
extern void sub_08016E28(u32 a, u32 b);
extern void sub_08010194(u32 a, u32 b, u32 c);

u32 sub_08010BA8(u8 param)
{
    u8 unused[0xC];
    u8 buf[2];
    s32 ret;

    ret = sub_08010B38(param);
    buf[0] = ret;
    buf[1] = (ret & 0xFF00) >> 8;
    sub_08016558(0x70);
    sub_080065A8();
    sub_08010AA4(param);
    sub_08016E10(gUnk_083FDEF4[0], 0x05000200, 0x80 << 1);
    if (buf[1] == 0xFF) {
        sub_08016E28(*gUnk_083FDF74[buf[0]], 0x06010000);
        sub_08016E28(*gUnk_083FDFEC[buf[0]], 0x06011000);
        sub_08010194(0x38, 0x30, 0);
        sub_08010194(0x78, 0x30, 0x80);
    } else {
        sub_08016E28(*gUnk_083FDF74[buf[0]], 0x06010000);
        sub_08016E28(*gUnk_083FDFEC[buf[0]], 0x06011000);
        sub_08016E28(*gUnk_083FDF74[buf[1]], 0x06012000);
        sub_08016E28(*gUnk_083FDFEC[buf[1]], 0x06013000);
        sub_08010194(0x60, 0x30, 0x80 << 1);
        sub_08010194(0xA0, 0x30, 0xC0 << 1);
        sub_08010194(0x10, 0x30, 0);
        sub_08010194(0x50, 0x30, 0x80);
    }
}
