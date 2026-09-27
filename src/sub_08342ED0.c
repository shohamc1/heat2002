#include "global.h"
#include "car.h"

void sub_08342F4C(void);

void *sub_0833FF44(void);
void sub_0833FF94(u32 a);

void sub_08342ED0(u8 a1, u8 a2)
{
    u32 *p;
    u32 e;
    u32 t;
    u32 q;
    u32 v1;
    u32 v2;

    p = (u32 *)sub_0833FF44();
    if (p != 0) {
        e = (u32)gModule_Cars + a1 * 400;
        p[6] = 0;
        *(u8 *)((u32)p + 0x34) = a1;
        p[7] = a2;
        p[8] = 2;
        t = a2 * 4;
        q = e + 0xC4;
        q += t;
        v1 = *(u32 *)q;
        p[0] = v1;
        p[1] = 0;
        q = e + 0xD4;
        q += t;
        v2 = *(u32 *)q;
        p[2] = v2;
        q = e + 0xA4;
        q += t;
        p[10] = v1 - *(u32 *)q;
        q = e + 0xB4;
        q += t;
        p[12] = v2 - *(u32 *)q;
        p[3] = (u32)sub_08342F4C;
        sub_0833FF94((u32)p);
    }
}
