#include "global.h"
#include "data.h"

struct Ent {
    s32 posX;
    u8 pad04[4];
    s32 posZ;
    s32 velX;
    u8 pad10[4];
    s32 velZ;
    u8 pad18[0x28 - 0x18];
    s32 f28;
    s32 speed;
    s32 f30;
    u16 heading;
    u16 f36;
    u16 f38;
    u8 pad3A[2];
    u16 yawRate;
    u8 gear;
    u8 pad3F;
    u16 rpm;
    u8 pad42[0x4C - 0x42];
    u8 lap;
    u8 waypoint;
    u8 subStep;
    u8 pad4F;
    s32 progress;
    u8 pad54;
    u8 f55;
    u8 pad56[0x58 - 0x56];
    s32 f58;
    u8 pad5C[0x7C - 0x5C];
    u8 f7C;
    u8 f7D;
    u8 pad7E[0x84 - 0x7E];
    u8 f84;
    u8 pad85[0x88 - 0x85];
    s32 damage;
    s32 tireWear0;
    s32 tireWear1;
    s32 tireWear2;
    s32 tireWear3;
    s32 fuel;
    u8 padA0[0xA2 - 0xA0];
    u16 fA2;
    u8 padA4[0xE4 - 0xA4];
    s32 fE4;
    s32 fE8;
    s32 fEC;
    u8 padF0[0x110 - 0xF0];
    u8 f110;
    u8 pad111[0x128 - 0x111];
    u32 f128;
    u8 pad12C[0x134 - 0x12C];
    s32 f134;
    s32 f138;
    s32 f13C;
    s32 forceX;
    s32 forceZ;
    s32 torque;
    s32 drag;
    u8 racePosition;
    u8 pad151[0x158 - 0x151];
    s32 f158;
    s32 f15C;
    u16 f160;
    u8 driverId;
    u8 pad163[3];
    u8 f166;
    u8 f167;
    u8 f168;
    u8 pad169[3];
    s32 f16C;
    u8 f170;
    u8 f171;
    u8 f172;
    u8 f173;
    u8 f174;
    u8 pitState;
    u8 draftTimer;
    u8 pad177[0x17C - 0x177];
    s32 f17C;
    u8 f180;
    u8 pad181[0x184 - 0x181];
    s32 pitProgress;
    u8 pad188[0x18E - 0x188];
    u8 f18E;
};

extern u8 gUnk_0200215C[];
extern u8 gIsLinkRace;
extern u8 gUnk_0202CAD0;
extern u8 gUnk_0202A51C;
extern u32 gUnk_020253B8;
extern u8 gUnk_0202ED70;
extern struct Ent gCars[];
extern u8 gUnk_0202CBC8[];
extern u32 *gUnk_08367730[];
extern u32 gUnk_08367FBC[];
extern u32 gUnk_08368034[];
extern u32 gUnk_083680AC[];
extern u8 gUnk_08367BFA[];
extern u8 gUnk_08367C06[];

void sub_0800C0E8(u32 a, u8 b);
void sub_0800C984(u32 *p, u32 v);

void InitCar(u8 a, struct Ent *car, s32 b, s32 c, u32 d)
{
    u8 i;

    if (gUnk_0200215C[0] == 4)
        car->driverId = 0;
    car->f18E = 0;
    car->pitState = 0;
    gUnk_0202CAD0 = 0;
    car->f180 = 0;
    car->draftTimer = 0;
    car->f17C = gUnk_020253B8;
    car->f168 = 0;
    gUnk_0202A51C = 0;
    car->f166 = 1;
    car->f167 = 0;
    car->posX = b;
    car->posZ = c;
    car->heading = d;
    car->speed = 0;
    car->f28 = 0;
    car->rpm = 0;
    car->gear = 0;
    car->f55 = 0;
    car->waypoint = 0;
    car->f174 = 0;
    if (gUnk_0200215C[0] == 4) {
        car->f58 = gUnk_08367730[a * 3];
    } else {
        car->f58 = gUnk_08367730[car->driverId];
    }
    car->f7C = 0;
    car->f84 = 1;
    car->f30 = 0;
    car->damage = 0;
    car->fA2 = 0;
    car->tireWear0 = 0;
    car->tireWear1 = 0;
    car->tireWear2 = 0;
    car->tireWear3 = 0;
    car->fuel = 0xB400;
    if (gUnk_0200215C[0] == 0xF && gUnk_0202ED70 == 3 && car == gCars)
        car->fuel = 0x5000;
    if (gUnk_0200215C[0] != 4)
        sub_0800C0E8((u32)car, a);
    if (gUnk_0200215C[0] != 5 && gUnk_0200215C[0] != 0x11)
        car->f16C = 0;
    car->f170 = 0;
    car->f171 = 0;
    car->f172 = 0;
    sub_0800C984(&car->f128, d);
    car->f134 = 0;
    car->f138 = -1;
    car->f173 = 0;
    car->f171 = 0;
    i = 0;
    do {
        gUnk_0202CBC8[i] = 0;
        i++;
    } while (i != 8);
    /* One store per arm: jump2 merges the stores into one strb behind a new
       label, and jumps to a label created in that pass never cross-jump,
       so the equal-valued arms stay separate as in the ROM. */
    if (gUnk_0200215C[0] == 0xF) {
        switch (gUnk_0202ED70) {
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
    if ((u8)(gUnk_0200215C[0] - 3) > 1)
        car->lap--;
    car->progress = 0;
    car->f15C = 0x12C;
    car->velX = 0;
    car->velZ = 0;
    car->f110 = 0;
    car->forceX = 0;
    car->forceZ = 0;
    car->f13C = 0;
    car->torque = 0;
    car->drag = 0;
    car->racePosition = 0x63;
    car->fE4 = gUnk_08367FBC[car->driverId];
    car->fE8 = gUnk_08368034[car->driverId];
    car->fEC = gUnk_083680AC[car->driverId];
    if (gIsLinkRace == 0 && a != 0 && gUnk_0200215C[0] != 2) {
        car->fE4 = (s32)gUnk_08367BFA;
        car->fE8 = (s32)gUnk_08367C06;
        car->fEC = (s32)gUnk_08367C10;
        car->fE4 = gUnk_08367FBC[0];
        car->fE8 = gUnk_08368034[0];
        car->fEC = gUnk_083680AC[0];
    }
    car->f158 = 0;
    car->f7D = 0;
    car->f36 = d;
    car->f38 = 0;
    car->f160 = 0;
    car->subStep = 0;
    car->yawRate = 0;
}
