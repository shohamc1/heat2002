#include "global.h"
#include "variables.h"

void LoadFadePalette(u16 *r4)
{
    u32 r6 = 0;
    u32 r5 = 0x1F;
    u32 *r3 = gUnk_02022E20;
    u32 r7 = 0x80 << 1;

    do
    {
        u32 v = *r4;

        r4 = (u16 *)((u32)r4 + 2);
        {
            u32 r1 = v;
            u32 r2 = v;

            v &= r5;
            r1 = (s32)r1 >> 5;
            r1 &= r5;
            r2 = (s32)r2 >> 10;
            r2 &= r5;
            r3[0] = v << 16;
            r3[1] = r1 << 16;
            r3[2] = r2 << 16;
        }
        r3 = (u32 *)((u32)r3 + 12);
        r6++;
    } while (r6 != r7);
}

void sub_08003DF4(u16 src[], s32 dst[])
{
    s32 a, b, c;
    int i;
    s32 *d;
    u16 *s;

    d = dst;
    s = src;
    i = 0;
    do {
        a = *s++;
        b = a;
        c = a;
        a &= 0x1F;
        b >>= 5;
        b &= 0x1F;
        c >>= 10;
        c &= 0x1F;
        *d++ = a << 16;
        *d++ = b << 16;
        *d++ = c << 16;
        i++;
    } while (i != 0x10);
}

void sub_08003E28(s32 src[], u16 dst[])
{
    s32 a, b, c;
    int i;

    i = 0;
    do {
        a = *src++;
        b = *src++;
        c = *src++;
        a >>= 16;
        b >>= 16;
        c >>= 16;
        a &= 0x1F;
        b &= 0x1F;
        c &= 0x1F;
        *dst++ = a | (b << 5) | (c << 10);
        i++;
    } while (i != 0x10);
}

struct E3E5C {
    s32 f00;
    s16 f04;
    s16 f06;
    s16 f08;
    s16 f0A;
};

void sub_08003E5C(struct E3E5C *e, u16 *out)
{
    s32 *p;
    s32 a;
    s32 b;
    s32 c;

    p = &e->f00;
    a = *p++ >> 16;
    b = e->f06;
    c = ((s16 *)p)[3];
    a &= 0x1F;
    b &= 0x1F;
    c &= 0x1F;
    *out = a | (b << 5) | (c << 10);
}

void sub_08003E84(s32 *src, u32 pal, s32 *dst)
{
    u16 *pk = (u16 *)pal;
    s32 i = 0;
    s32 m = 0x1F;
    do {
        s32 v = *pk++;
        s32 q = v;
        s32 g;
        v &= m;
        g = q >> 5;
        g &= m;
        q = q >> 10;
        q &= m;
        v <<= 16;
        g <<= 16;
        q <<= 16;
        *dst++ = (v - *src++) / 16;
        *dst++ = (g - *src++) / 16;
        *dst++ = (q - *src++) / 16;
        i++;
    } while (i != 16);
}

void sub_08003EF0(u32 *dst, u32 *src)
{
    u32 i;

    i = 0;
    do {
        *dst++ += *src++;
        i++;
    } while (i != 0x30);
}

void sub_08003F0C(u16 *r4)
{
    u32 r6 = 0;
    u32 r5 = 0x1F;
    u32 *r3 = gUnk_02022E20;
    u32 r7 = 0x80 << 1;

    do
    {
        u32 v = *r4;

        r4 = (u16 *)((u32)r4 + 2);
        {
            u32 r1 = v;
            u32 r2 = v;

            v &= r5;
            r1 = (s32)r1 >> 5;
            r1 &= r5;
            r2 = (s32)r2 >> 10;
            r2 &= r5;
            r3[0] = v << 16;
            r3[1] = r1 << 16;
            r3[2] = r2 << 16;
        }
        r3 = (u32 *)((u32)r3 + 12);
        r6++;
    } while (r6 != r7);
}
