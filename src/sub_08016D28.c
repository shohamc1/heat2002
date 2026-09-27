#include "global.h"
#include "data.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

/* car.h types 0x4C as u8 lap, but this function's load is a signed ldrsb
   (its old local view typed the field s8). Reach it through this view so
   the offset stays inside the MEM like a plain component access. */
struct CarLapS8 {
    u8 pad[0x4C];
    s8 lap;
};

void sub_08016D28(u8 a)
{
    struct Car *p;
    s32 i;
    s32 v;
    u32 w;
    u32 u;
    u32 x;
    if (a != 0) {
        p = gCars;
        i = 0;
        do {
            if (p->finished != 0)
                p->finishTime = p->finishMin * 60000 + p->finishSec * 1000 + p->finishMs;
            i++;
            p++;
        } while (i != 0x18);
    }
    v = ((struct CarLapS8 *)gCars)->lap * gTrackLapLengths[gTrackId];
    w = gCars[0].finishTime;
    u = sub_08017230(w, v);
    p = gCars;
    i = 0;
    do {
        if (p->finished == 0) {
            x = u * (v - sub_08016D08(p->progress, gTrackId)) + w;
            p->finishTime = x;
            p->finished = 1;
        }
        i++;
        p++;
    } while (i != 0x18);
}
