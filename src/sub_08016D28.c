#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
struct Unk0202A550 {
    u8 filler0[0x4C];
    s8 lap;
    u8 filler4D[0x50 - 0x4D];
    u32 progress;
    u8 filler54[0x7D - 0x54];
    u8 unk7D;
    u8 filler7E[0x104 - 0x7E];
    u16 finishMin;
    u16 finishSec;
    u16 finishMs;
    u8 filler10A[0x16C - 0x10A];
    u32 unk16C;
    u8 filler170[400 - 0x170];
};
extern struct Unk0202A550 gCars[];
void sub_08016D28(u8 a)
{
    struct Unk0202A550 *p;
    s32 i;
    s32 v;
    u32 w;
    u32 u;
    u32 x;
    if (a != 0) {
        p = gCars;
        i = 0;
        do {
            if (p->unk7D != 0)
                p->unk16C = p->finishMin * 60000 + p->finishSec * 1000 + p->finishMs;
            i++;
            p++;
        } while (i != 0x18);
    }
    v = gCars[0].lap * gUnk_083FED18[gTrackId];
    w = gCars[0].unk16C;
    u = sub_08017230(w, v);
    p = gCars;
    i = 0;
    do {
        if (p->unk7D == 0) {
            x = u * (v - sub_08016D08(p->progress, gTrackId)) + w;
            p->unk16C = x;
            p->unk7D = 1;
        }
        i++;
        p++;
    } while (i != 0x18);
}
