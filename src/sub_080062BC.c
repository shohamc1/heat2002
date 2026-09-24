#include "global.h"
#include "gba/compat.h"

extern u8 gIsDemo;
void UpdateRaceHud(void);
extern u8 gUnk_0806C784[];

u32 AllocTask(void);
void AddTask(u32 a);
void sub_08006214(void);
void sub_0800649C(u32 r0, u32 r1, u32 r2);
void sub_080055B0(void);

void InitRaceHud(void)
{
    u32 *r;
    u32 src;
    u32 dst;

    if (gIsDemo != 0)
        return;
    r = (u32 *)AllocTask();
    if (r != 0) {
        r[3] = (u32)UpdateRaceHud;
        AddTask((u32)r);
    }
    sub_08006214();
    sub_0800649C((u32)gUnk_0806C784, 0, 0x13);
    src = 0x08331FC8;
    dst = (u32)OBJ_VRAM1 + 0x2280;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    src += 0xC0 << 1;
    dst += 0x80 << 3;
    CpuCopy16(src, dst, 0x180);
    sub_080055B0();
}
