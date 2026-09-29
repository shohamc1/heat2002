#include "global.h"
#include "variables.h"

struct Unk08343DF8
{
    s32 unk00;
    u8 pad04[4];
    s32 unk08;
    s32 unk0C;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[0x34 - 0x18];
    u16 unk34;
    u8 pad36[0x3C - 0x36];
    s16 unk3C;
};

void ModuleBuildCarCollFrame(struct Unk08343DF8 *car, s32 *frame)
{
    s32 x, z;
    s32 v;

    v = -(car->unk34 >> 8) & 0xFF;
    frame[0] = gModule_SinTable[v];
    frame[1] = gModule_SinTable[v + 0x40];
    x = car->unk00;
    frame[4] = x >> 8;
    z = car->unk08;
    frame[5] = z >> 8;
    v = car->unk34 + car->unk3C;
    v = -(v >> 8) & 0xFF;
    frame[2] = gModule_SinTable[v];
    frame[3] = gModule_SinTable[v + 0x40];
    frame[6] = (x + car->unk0C) >> 8;
    frame[7] = (z + car->unk14) >> 8;
}

void ModuleKeepNearestCarContact(s32 arg0, u8 arg1, u32 arg2, u8 arg3, u32 *arg4, u8 *arg5, u32 arg6, s32 arg7)
{
    if (arg7 < gUnk_0203DF44) {
        arg4[0] = arg0;
        arg4[1] = arg2;
        ((u8 *)arg4)[8] = arg1;
        ((u8 *)arg4)[9] = arg3;
        arg4[3] = arg6;
        *arg5 = 1;
        gUnk_0203DF44 = arg7;
    }
}
