#include "global.h"

struct VtxBC4C {
    u16 x, y;
};

struct SegBC4C {
    /* 0x00 */ s32 f00;
    /* 0x04 */ s32 f04;
    /* 0x08 */ s32 f08;
    /* 0x0C */ s32 f0C;
    /* 0x10 */ u16 f10;
    /* 0x12 */ u8 pad[0x18 - 0x12];
};

extern struct SegBC4C *gUnk_083671C0[];   /* 0x083671C0 */
extern u8 gUnk_020020CC;                  /* 0x020020CC */

s32 sub_0800BC4C(struct VtxBC4C *verts, u8 *idx)
{
    struct SegBC4C *s = gUnk_083671C0[gUnk_020020CC];
    s32 t[6];
    s32 x1, y1, x2, y2;
    s32 flag;
    s32 i;
    s32 a, b, c, d, cross, v;

    t[0] = verts[idx[0]].x;
    t[1] = verts[idx[0]].y;
    t[2] = verts[idx[1]].x;
    t[3] = verts[idx[1]].y;
    x1 = t[0];
    y1 = t[1];
    x2 = t[2];
    y2 = t[3];
    flag = 0;
    i = 0;
    do {
        a = s->f00;
        b = s->f04;
        c = s->f08;
        d = s->f0C;
        if (s->f10 == 1)
            flag = 1;
        cross = (x2 - x1) * (d - b) - (y2 - y1) * (c - a);
        if (cross == 0)
            goto next;
        v = ((y1 - b) * (c - a) - (x1 - a) * (d - b)) << 8;
        if ((u32)(v / cross) > 256)
            goto next;
        v = ((x2 - x1) * (y1 - b) - (y2 - y1) * (x1 - a)) << 8;
        if ((u32)(v / cross) > 256)
            goto next;
        return i;
next:
        s++;
        i++;
    } while (flag == 0);
    return -1;
}
