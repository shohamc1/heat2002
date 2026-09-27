#include "global.h"
#include "variables.h"
#include "car.h"


extern u8 gUnk_0203DCF0;
extern u32 gUnk_02027500[];
extern u32 gUnk_02027578[];
extern u32 gUnk_020275F0[];

void sub_083432EC(u32 *p, u32 v);

void sub_08341288(u8 a, struct Car *car, s32 b, s32 c, u32 d)
{
    u8 i;

    if (gUnk_0203916C[0] == 4)
        car->driverId = 0;
    car->unk18E = 0;
    car->pitState = 0;
    gUnk_0203DCF0 = 0;
    car->unk180 = 0;
    car->draftTimer = 0;
    car->unk168 = 0;
    gUnk_0203D4E8 = 0;
    car->unk166 = 1;
    car->unk167 = 0;
    car->posX = b;
    car->posZ = c;
    car->heading = d;
    car->speed = 0;
    car->unk28 = 0;
    car->rpm = 0;
    car->gear = 0;
    car->unk55 = 0;
    car->waypoint = 0;
    car->unk174 = 0;
    car->unk58 = gUnk_02026E1C[a * 3];
    car->unk7C = 0;
    car->unk84 = 1;
    car->unk30 = 0;
    car->damage = 0;
    car->unkA2 = 0;
    car->tireWear0 = 0;
    car->tireWear1 = 0;
    car->tireWear2 = 0;
    car->tireWear3 = 0;
    car->fuel = 0xB400;
    if (gUnk_0203916C[0] == 0xF && gUnk_0203DFB0 == 3 && car == gModule_Cars)
        car->fuel = 0x5000;
    if (gUnk_0203916C[0] != 5 && gUnk_0203916C[0] != 0x11)
        car->unk16C = 0;
    car->unk170 = 0;
    car->unk171 = 0;
    car->unk172 = 0;
    sub_083432EC((u32 *)&car->unk128, d);
    car->unk134 = 0;
    car->unk138 = -1;
    car->unk173 = 0;
    car->unk171 = 0;
    i = 0;
    do {
        gUnk_0203DDE8[i] = 0;
        i++;
    } while (i != 8);
    /* One store per arm: jump2 merges the stores into one strb behind a new
       label, and jumps to a label created in that pass never cross-jump,
       so the equal-valued arms stay separate as in the ROM. */
    if (gUnk_0203916C[0] == 0xF) {
        switch (gUnk_0203DFB0) {
        case 0:
            car->lap = 1;
            break;
        case 1:
            car->lap = 4;
            break;
        case 2:
            car->lap = 5;
            break;
        case 3:
            car->lap = 0x28;
            break;
        case 6:
            car->lap = 0x28;
            break;
        case 10:
            car->lap = 0xF;
            break;
        case 11:
            car->lap = 0xF;
            break;
        case 12:
            car->lap = 0x55;
            break;
        case 13:
            car->lap = 0x12;
            break;
        case 14:
            car->lap = 5;
            break;
        case 15:
            car->lap = 0x14;
            break;
        default:
            car->lap = 0;
            break;
        }
    } else {
        car->lap = 0;
    }
    if ((u8)(gUnk_0203916C[0] - 3) > 1)
        car->lap--;
    car->progress = 0;
    car->unk15C = 0x12C;
    car->velX = 0;
    car->velZ = 0;
    car->unk110 = 0;
    car->forceX = 0;
    car->forceZ = 0;
    car->unk13C = 0;
    car->torque = 0;
    car->drag = 0;
    car->racePosition = 0x63;
    (*(s32 *)&car->unkE4) = gUnk_02027500[car->driverId];
    (*(s32 *)&car->unkE8) = gUnk_02027578[car->driverId];
    (*(s32 *)&car->unkEC) = gUnk_020275F0[car->driverId];
    if (gUnk_020390EC == 0 && a != 0 && gUnk_0203916C[0] != 2) {
        (*(s32 *)&car->unkE4) = (s32)gUnk_0202713E;
        (*(s32 *)&car->unkE8) = (s32)gUnk_0202714A;
        (*(s32 *)&car->unkEC) = (s32)gUnk_02027154;
        (*(s32 *)&car->unkE4) = gUnk_02027500[0];
        (*(s32 *)&car->unkE8) = gUnk_02027578[0];
        (*(s32 *)&car->unkEC) = gUnk_020275F0[0];
    }
    car->unk158 = 0;
    car->unk7D = 0;
    car->unk36 = d;
    car->unk38 = 0;
    car->unk160 = 0;
    car->subStep = 0;
    car->yawRate = 0;
}
