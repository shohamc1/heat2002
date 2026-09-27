#ifndef GUARD_CAR_H
#define GUARD_CAR_H

// struct Car: the merged view of the 0x190-byte per-car record. Every src/
// file that reads the car array declares its own local struct today (Car,
// Unk0202A550, UnkCar, Ent, Drv, Car08005FA8, ... -- 69 definitions); this
// is their union: one field per offset any file names, padXX for the bytes
// none does. Type and name at each offset follow the majority of the local
// views (ties broken to the corpus majority sign, s32); build/car_map.txt
// maps every local field to the canonical one for the rewrite stage.

struct Car {
    /* 0x00 */ s32 posX;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 posZ;
    /* 0x0C */ s32 velX;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ s32 velZ;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 speed;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ u16 heading;
    /* 0x36 */ u16 unk36;
    /* 0x38 */ u16 unk38;
    /* 0x3A */ u16 unk3A;
    /* 0x3C */ u16 yawRate;
    /* 0x3E */ u8 gear;
    /* 0x3F */ u8 pad3F[0x40 - 0x3F];
    /* 0x40 */ u16 rpm;
    /* 0x42 */ u8 pad42[0x48 - 0x42];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ u8 lap;
    /* 0x4D */ u8 waypoint;
    /* 0x4E */ u8 subStep;
    /* 0x4F */ u8 pad4F[0x50 - 0x4F];
    /* 0x50 */ s32 progress;
    /* 0x54 */ u8 pad54[0x55 - 0x54];
    /* 0x55 */ u8 unk55;
    /* 0x56 */ u8 pad56[0x58 - 0x56];
    /* 0x58 */ s32 unk58;
    /* 0x5C */ u8 pad5C[0x7C - 0x5C];
    /* 0x7C */ u8 unk7C;
    /* 0x7D */ u8 unk7D;
    /* 0x7E */ u8 pad7E[0x80 - 0x7E];
    /* 0x80 */ u32 unk80;
    /* 0x84 */ u8 unk84;
    /* 0x85 */ u8 pad85[0x88 - 0x85];
    /* 0x88 */ s32 damage;
    /* 0x8C */ s32 tireWear0;
    /* 0x90 */ s32 tireWear1;
    /* 0x94 */ s32 tireWear2;
    /* 0x98 */ s32 tireWear3;
    /* 0x9C */ s32 fuel;
    /* 0xA0 */ u16 aiInput;
    /* 0xA2 */ u16 unkA2;
    /* 0xA4 */ s32 unkA4[4];
    /* 0xB4 */ s32 unkB4[4];
    /* 0xC4 */ s32 unkC4[4];
    /* 0xD4 */ s32 unkD4[4];
    /* 0xE4 */ u16 *unkE4;
    /* 0xE8 */ u16 *unkE8;
    /* 0xEC */ u16 *unkEC;
    /* 0xF0 */ s32 unkF0;
    /* 0xF4 */ s32 unkF4;
    /* 0xF8 */ s32 unkF8;
    /* 0xFC */ u8 padFC[0x104 - 0xFC];
    /* 0x104 */ u16 finishMin;
    /* 0x106 */ u16 finishSec;
    /* 0x108 */ u16 finishMs;
    /* 0x10A */ u8 pad10A[0x110 - 0x10A];
    /* 0x110 */ u8 unk110;
    /* 0x111 */ u8 pad111[0x128 - 0x111];
    /* 0x128 */ s32 unk128;
    /* 0x12C */ s32 unk12C;
    /* 0x130 */ s32 unk130;
    /* 0x134 */ s32 unk134;
    /* 0x138 */ s32 unk138;
    /* 0x13C */ s32 unk13C;
    /* 0x140 */ s32 forceX;
    /* 0x144 */ s32 forceZ;
    /* 0x148 */ s32 torque;
    /* 0x14C */ s32 drag;
    /* 0x150 */ u8 racePosition;
    /* 0x151 */ u8 pad151[0x154 - 0x151];
    /* 0x154 */ s32 unk154;
    /* 0x158 */ s32 unk158;
    /* 0x15C */ s32 unk15C;
    /* 0x160 */ u16 unk160;
    /* 0x162 */ u8 driverId;
    /* 0x163 */ u8 pad163[0x164 - 0x163];
    /* 0x164 */ u16 points;
    /* 0x166 */ u8 unk166;
    /* 0x167 */ u8 unk167;
    /* 0x168 */ u8 unk168;
    /* 0x169 */ u8 pad169[0x16C - 0x169];
    /* 0x16C */ u32 unk16C;
    /* 0x170 */ u8 unk170;
    /* 0x171 */ u8 unk171;
    /* 0x172 */ u8 unk172;
    /* 0x173 */ u8 unk173;
    /* 0x174 */ u8 unk174;
    /* 0x175 */ u8 pitState;
    /* 0x176 */ u8 draftTimer;
    /* 0x177 */ u8 pad177[0x178 - 0x177];
    /* 0x178 */ u32 unk178;
    /* 0x17C */ s32 unk17C;
    /* 0x180 */ u8 unk180;
    /* 0x181 */ u8 pitStall;
    /* 0x182 */ u16 unk182;
    /* 0x184 */ s32 pitProgress;
    /* 0x188 */ s32 pitDuration;
    /* 0x18C */ u16 unk18C;
    /* 0x18E */ u8 unk18E;
    /* 0x18F */ u8 unk18F;
};

typedef char CarSizeCheck[sizeof(struct Car) == 0x190 ? 1 : -1];

// gCars: the main program's cars at 0x0202A550 (stride 0x190).
extern struct Car gCars[];

// gModule_Cars: the high module's cars, gUnk_0203D520 on the other GBA
// (renamed separately; a different machine, not an alias of gCars).
extern struct Car gModule_Cars[];

#endif // GUARD_CAR_H
