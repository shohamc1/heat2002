#include "global.h"
#include "functions.h"

extern u8 gUnk_0203C220[];
extern u8 gUnk_0203B870[];
extern u8 gUnk_0203BA50[];
extern u8 gUnk_0203BF50[];
extern u8 gUnk_0203C0E0[];
extern u8 gUnk_0203BCD0[];
extern u8 gUnk_0203C270[];
extern s32 gUnk_0203C334;
extern s32 gUnk_0203C330;

void sub_08344B70(u32 a, u32 b);

void sub_0833FDC4(void)
{
    u8 buf[0x200];
    u8 *p;
    u32 i;
    s32 src;
    s32 len;
    s32 *q;

    gUnk_0203C334 = 0;

    p = gUnk_0203C220;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            sub_08344B70(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 4);

    p = gUnk_0203B870;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            sub_08344B70(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x18);

    p = gUnk_0203BA50;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            sub_08344B70(src, (u32)buf);
            sub_08344B64((u32)buf, len, 0x20);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x20);

    p = gUnk_0203BF50;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            sub_08344B70(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x14);

    p = gUnk_0203C0E0;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            sub_08344B70(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x10);

    p = gUnk_0203BCD0;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            if (p[4] == 1)
                sub_08344B64(src, len, 0x10);
            else
                sub_08344B70(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x20);

    p = gUnk_0203C270;
    i = 0;
    q = &gUnk_0203C334;
    do {
        if (p[1] != 0) {
            src = *(s32 *)(p + 4);
            len = *(s32 *)(p + 8);
            sub_08344B64(src, len, 0x10);
            p[1] = 0;
            *q += 0x20;
        }
        i++;
        p += 0xC;
    } while (i != 0x10);

    if (gUnk_0203C334 > gUnk_0203C330)
        gUnk_0203C330 = gUnk_0203C334;
}
