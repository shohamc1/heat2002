#include "global.h"
#include "functions.h"
#include "gba/syscall.h"
#include "variables.h"

extern s32 gObjPalBytesCopiedThisFrame;
extern s32 gObjPalBytesPeak;

void UploadPendingGfx(void)
{
    u8 buf[0x200];
    u8 *p;
    u32 i;
    s32 src;
    s32 len;
    s32 *q;

    gObjPalBytesCopiedThisFrame = 0;

    p = (u8 *)gObjTileCache64;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            RLUnCompVram(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 4);

    p = (u8 *)gObjTileCache16;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            RLUnCompVram(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x18);

    p = (u8 *)gObjTileCache2;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            RLUnCompVram((const void *)src, buf);
            CpuSet(buf, (void *)len, 0x20);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x20);

    p = (u8 *)gObjTileCache8;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            RLUnCompVram(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x14);

    p = (u8 *)gObjTileCache4;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            RLUnCompVram(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x10);

    p = (u8 *)gObjTileCache1;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            if (p[4] == 1)
                CpuSet(src, len, 0x10);
            else
                RLUnCompVram(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x20);

    p = (u8 *)gObjPaletteCache;
    i = 0;
    q = &gObjPalBytesCopiedThisFrame;
    do {
        if (p[1] != 0) {
            src = *(s32 *)(p + 4);
            len = *(s32 *)(p + 8);
            CpuSet(src, len, 0x10);
            p[1] = 0;
            *q += 0x20;
        }
        i++;
        p += 0xC;
    } while (i != 0x10);

    if (gObjPalBytesCopiedThisFrame > gObjPalBytesPeak)
        gObjPalBytesPeak = gObjPalBytesCopiedThisFrame;
}
