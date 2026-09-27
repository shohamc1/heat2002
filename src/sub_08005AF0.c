#include "global.h"
#include "data.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

extern u8 gUnk_02025228;
extern u8 gUnk_083387A8[];
extern u32 gUnk_08364B08[];
extern s32 gUnk_0200209C;
extern u8 gUnk_08334DCC[];


void sub_08005AF0(s32 arg)
{
    u16 buf[2];
    u32 ptr;
    u32 v;
    u32 r1v;
    u16 *dest;
    u32 off;

    if (gUnk_0202EEB0 == 0)
        return;
    gUnk_02025228++;
    buf[0] = 0xAA;
    buf[1] = 0x89;
    ptr = sub_08007630((u32)gUnk_083387A8);
    if (ptr != 0) {
        v = buf[1] & 0xFF;
        v |= (buf[0] & 0x1FF) << 16;
        v |= 0x40000000;
        r1v = *(u32 *)(ptr + 0x10) | (((u32)RequestObjPalette((u32)gUnk_08338788) << 24) >> 12);
        AddOamEntry(v | 0x02000100, r1v);
    }
    gUnk_02025398 = ((arg >> 16) + 0xBE) & 0xFF;
    dest = (u16 *)(gUnk_08364B08[0] + 0x4EE);
    if (arg <= 0x31FF && (gUnk_0200209C & 0x10) != 0) {
        off = 0x5B2;
        *dest = 0xE000 | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
        if (gOptions[3] != 0) {
            if (gIsDemo == 0)
                m4aSongNumStart(0x1B);
        }
    } else {
        off = 0x5B4;
        *dest = 0xE000 | gUnk_08335A8C[*(u16 *)&gUnk_08334DCC[off]];
    }
}
