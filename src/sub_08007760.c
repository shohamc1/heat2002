#include "global.h"

extern u8 gUnk_02025DB0[];
extern u8 gUnk_02025400[];
extern u8 gUnk_020255E0[];
extern u8 gUnk_02025AE0[];
extern u8 gUnk_02025C70[];
extern u8 gUnk_02025860[];
extern u8 gUnk_02025E00[];
extern s32 gUnk_02025EC4;
extern s32 gUnk_02025EC0;

void sub_08016E28(u32 a, u32 b);
void sub_08016E10(u32 src, u32 dest, u32 control);

void sub_08007760(void)
{
    u8 buf[0x200];
    u8 *p;
    u32 i;
    s32 src;
    s32 len;
    s32 *q;

    gUnk_02025EC4 = 0;

    p = gUnk_02025DB0;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            sub_08016E28(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 4);

    p = gUnk_02025400;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            sub_08016E28(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x18);

    p = gUnk_020255E0;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            sub_08016E28(src, (u32)buf);
            sub_08016E10((u32)buf, len, 0x20);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x20);

    p = gUnk_02025AE0;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            sub_08016E28(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x14);

    p = gUnk_02025C70;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            sub_08016E28(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x10);

    p = gUnk_02025860;
    i = 0;
    do {
        if (p[4] != 0) {
            src = *(s32 *)(p + 8);
            len = *(s32 *)(p + 0xC);
            if (p[4] == 1)
                sub_08016E10(src, len, 0x10);
            else
                sub_08016E28(src, len);
            p[4] = 0;
        }
        i++;
        p += 0x14;
    } while (i != 0x20);

    p = gUnk_02025E00;
    i = 0;
    q = &gUnk_02025EC4;
    do {
        if (p[1] != 0) {
            src = *(s32 *)(p + 4);
            len = *(s32 *)(p + 8);
            sub_08016E10(src, len, 0x10);
            p[1] = 0;
            *q += 0x20;
        }
        i++;
        p += 0xC;
    } while (i != 0x10);

    if (gUnk_02025EC4 > gUnk_02025EC0)
        gUnk_02025EC0 = gUnk_02025EC4;
}
