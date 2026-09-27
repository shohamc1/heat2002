#include "global.h"
#include "variables.h"

extern u8 gUnk_0203B6D8;
extern u8 gUnk_02024F70[];

u32 sub_0833FC94(u32 r0);
u32 sub_0833FD78(u32 r0);
void sub_0833D6A0(u32 r0, u32 r1);
void sub_0833A8C8(u32 r0);

void sub_0833E5EC(s32 arg)
{
    u16 buf[2];
    u32 ptr;
    u32 v;
    u32 r1v;
    u16 *dest;
    u32 off;

    if (gModule_DamagePitsEnabled == 0)
        return;
    gUnk_0203B6D8++;
    buf[0] = 0xAA;
    buf[1] = 0x89;
    ptr = sub_0833FC94((u32)gUnk_02024F70);
    if (ptr != 0) {
        v = buf[1] & 0xFF;
        v |= (buf[0] & 0x1FF) << 16;
        v |= 0x40000000;
        r1v = *(u32 *)(ptr + 0x10) | (((u32)sub_0833FD78((u32)gUnk_02024F50) << 24) >> 12);
        sub_0833D6A0(v | 0x02000100, r1v);
    }
    gUnk_0203B828 = ((arg >> 16) + 0xBE) & 0xFF;
    dest = (u16 *)(gModule_TextLayerMapPtr[0] + 0x4EE);
    if (arg <= 0x31FF && ((*(u32 *)&gModule_FrameCounter) & 0x10) != 0) {
        off = 0x5B2;
        *dest = 0xE000 | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[off]];
        if (gModule_Options[3] != 0) {
            if (gModule_IsDemo[0] == 0)
                sub_0833A8C8(0x1B);
        }
    } else {
        off = 0x5B4;
        *dest = 0xE000 | gModule_FontTileEntries[*(u16 *)&gUnk_02021594[off]];
    }
}
