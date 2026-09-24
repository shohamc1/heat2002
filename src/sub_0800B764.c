#include "global.h"

struct UnkCarB764 {
    /* 0x000 */ u8 pad0[0xA4];
    /* 0x0A4 */ u32 unkA4[4];
    /* 0x0B4 */ u32 unkB4[4];
    /* 0x0C4 */ u32 unkC4[4];
    /* 0x0D4 */ u32 unkD4[4];
    /* 0x0E4 */ u8 pad1[400 - 0xE4];
};

extern struct UnkCarB764 gCars[];   /* 0x0202A550 */
extern u8 gCallback_0800B7E1[];             /* Thumb entry: 0x0800B7E0 | 1 */

u32 AllocTask(void);
void AddTask(u32 a);

void sub_0800B764(u8 a, u8 b)
{
    u32 r;
    u32 v1, v2;
    struct UnkCarB764 *car;

    r = AllocTask();
    if (r != 0) {
        car = &gCars[a];
        *(u32 *)(r + 0x18) = 0;
        *(u8 *)(r + 0x34) = a;
        *(u32 *)(r + 0x1C) = b;
        *(u32 *)(r + 0x20) = 2;
        v1 = car->unkC4[b];
        *(u32 *)(r + 0x00) = v1;
        *(u32 *)(r + 0x04) = 0;
        v2 = car->unkD4[b];
        *(u32 *)(r + 0x08) = v2;
        *(u32 *)(r + 0x28) = v1 - car->unkA4[b];
        *(u32 *)(r + 0x30) = v2 - car->unkB4[b];
        *(u32 *)(r + 0x0C) = (u32)gCallback_0800B7E1;
        AddTask(r);
    }
}
