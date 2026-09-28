#include "global.h"
#include "variables.h"
#include "data.h"

struct VtxBC4C {
    u16 x, y;
};

s32 sub_0800BC4C(struct VtxBC4C *verts, u8 *idx)
{
    struct TrackSeg *s = gTrackSegTables[gTrackId];
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
        a = s->f0;
        b = s->f4;
        c = s->f8;
        d = s->fC;
        if (s->unk10 == 1)
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
