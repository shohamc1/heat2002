#include "global.h"
#include "gba/compat.h"

extern u32 gUnk_083FDEF4[];
extern u32 *gUnk_083FDF74[];
extern u32 *gUnk_083FDFEC[];

extern s32 sub_08010B38(u8 id);
extern u32 sub_08016558(u32 idx);
extern void sub_080065A8(void);
extern void sub_08010AA4(u8 idx);
extern void RLUnCompVram(u32 a, u32 b);
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
    CpuCopy16(gUnk_083FDEF4[0], OBJ_PLTT, OBJ_PLTT_SIZE);
    if (buf[1] == 0xFF) {
        RLUnCompVram(*gUnk_083FDF74[buf[0]], OBJ_VRAM0);
        RLUnCompVram(*gUnk_083FDFEC[buf[0]], OBJ_VRAM0 + 0x1000);
        sub_08010194(0x38, 0x30, 0);
        sub_08010194(0x78, 0x30, 0x80);
    } else {
        RLUnCompVram(*gUnk_083FDF74[buf[0]], OBJ_VRAM0);
        RLUnCompVram(*gUnk_083FDFEC[buf[0]], OBJ_VRAM0 + 0x1000);
        RLUnCompVram(*gUnk_083FDF74[buf[1]], OBJ_VRAM0 + 0x2000);
        RLUnCompVram(*gUnk_083FDFEC[buf[1]], OBJ_VRAM0 + 0x3000);
        sub_08010194(0x60, 0x30, 0x80 << 1);
        sub_08010194(0xA0, 0x30, 0xC0 << 1);
        sub_08010194(0x10, 0x30, 0);
        sub_08010194(0x50, 0x30, 0x80);
    }
}
