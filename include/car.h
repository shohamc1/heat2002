#ifndef GUARD_CAR_H
#define GUARD_CAR_H

// struct Car: the merged view of the 0x190-byte per-car record (the union of
// the local struct views the 52+ gCars/gModule_Cars users used to declare;
// build/car_map.txt maps every local field to the canonical one). Fields
// named below are evidence-backed from matched C and the reference asm
// (agents' analysis 2026-09-28); unkXX fields have no reader anywhere in
// the reachable code, and padXX regions are never touched at any width.

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
    /* 0x36 */ u16 respawnHeading;
    /* 0x38 */ u16 respawnWaypoint;
    /* 0x3A */ u16 unk3A;
    /* 0x3C */ u16 yawRate;
    /* 0x3E */ u8 gear;
    /* 0x3F */ u8 pad3F[0x40 - 0x3F];
    /* 0x40 */ u16 rpm;
    /* 0x42 */ u8 pad42[0x48 - 0x42];
    /* 0x48 */ s32 impactSpeed;
    /* 0x4C */ u8 lap;
    /* 0x4D */ u8 waypoint;
    /* 0x4E */ u8 subStep;
    /* 0x4F */ u8 pad4F[0x50 - 0x4F];
    /* 0x50 */ s32 progress;
    /* 0x54 */ u8 pad54[0x55 - 0x54];
    /* 0x55 */ u8 hitCooldown;
    /* 0x56 */ u8 pad56[0x58 - 0x56];
    /* 0x58 */ s32 driverPalette; /* cached gDriverPalettes[driverId] palette pointer; write-only (no reader in shipped code) */
    /* 0x5C */ u8 pad5C[0x7C - 0x5C];
    /* 0x7C */ u8 carState; /* only 0 (init) and 2 (wreck reset) ever written; 1, 1-3 and 5-7 are tested but never set in matched code */
    /* 0x7D */ u8 finished; /* 0 while racing; 1 once the car's result is recorded */
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
    /* 0xA2 */ u16 throttleLevel; /* 0..0x100 ramp */
    /* 0xA4 */ s32 cornerX[4];
    /* 0xB4 */ s32 cornerZ[4];
    /* 0xC4 */ s32 nextCornerX[4];
    /* 0xD4 */ s32 nextCornerZ[4];
    /* 0xE4 */ u16 *gearPowerTable; /* per-driver gDriverGearPowerTables[driverId] */
    /* 0xE8 */ u16 *gearRatioTable; /* per-driver gDriverGearRatioTables[driverId] */
    /* 0xEC */ u16 *rpmPerSpeedTable; /* per-driver gDriverRpmPerSpeedTables[driverId] */
    /* 0xF0 */ s32 lanePosition; /* row index (>>8) into the wall tables below */
    /* 0xF4 */ s32 lanePoints; /* u16 (x,y) pairs, gLanePointTables[row+gTrackId*12] */
    /* 0xF8 */ s32 laneSegments; /* 20-byte records, gLaneSegmentTables[row+gTrackId*12] */
    /* 0xFC */ u32 laneCellLists; /* base of 0xFF-terminated lane-segment index lists (held as a pointer) */
    /* 0x100 */ u32 laneCellGrid; /* u16[48*48] grid of offsets into laneCellLists (held as a pointer) */
    /* 0x104 */ u16 finishMin;
    /* 0x106 */ u16 finishSec;
    /* 0x108 */ u16 finishMs;
    /* 0x10A */ u8 pad10A[0x110 - 0x10A];
    /* 0x110 */ u8 unk110;
    /* 0x111 */ u8 pad111[0x128 - 0x111];
    /* 0x128 */ s32 unk128;
    /* 0x12C */ s32 steerHeading;
    /* 0x130 */ s32 unk130;
    /* 0x134 */ s32 unk134;
    /* 0x138 */ s32 unk138;
    /* 0x13C */ s32 engineForce;
    /* 0x140 */ s32 forceX;
    /* 0x144 */ s32 forceZ;
    /* 0x148 */ s32 torque;
    /* 0x14C */ s32 drag;
    /* 0x150 */ u8 racePosition;
    /* 0x151 */ u8 pad151[0x154 - 0x151];
    /* 0x154 */ s32 laneLength;
    /* 0x158 */ s32 unk158;
    /* 0x15C */ s32 tickCount; /* init 300, ++ every UpdateCar */
    /* 0x160 */ u16 zoneGripFlag; /* 0x32 near a zone entity; halves camera sway */
    /* 0x162 */ u8 driverId;
    /* 0x163 */ u8 pad163[0x164 - 0x163];
    /* 0x164 */ u16 points;
    /* 0x166 */ u8 ledLapFlag; /* 1 until racePosition is a valid mid-pack value; lapping marker */
    /* 0x167 */ u8 lapLedTimer; /* 0x1E countdown after being lapped */
    /* 0x168 */ u8 lapsLed; /* bonus points: +5 if nonzero, +10 when no other car led strictly more laps (ties get it) */
    /* 0x169 */ u8 pad169[0x16C - 0x169];
    /* 0x16C */ u32 finishTime; /* ms result/sort key: race finish time, best lap in mode 5, or random AI qualifying time */
    /* 0x170 */ u8 onApron; /* tile 2/3; mild drag */
    /* 0x171 */ u8 onGrass; /* tile 4/5; strong drag */
    /* 0x172 */ u8 behindBgFlag; /* adjacent tile bit 0 */
    /* 0x173 */ u8 wasOnGrass; /* previous-frame onGrass */
    /* 0x174 */ u8 firstStepCrossed; /* car has begun moving */
    /* 0x175 */ u8 pitState;
    /* 0x176 */ u8 draftTimer;
    /* 0x177 */ u8 pad177[0x178 - 0x177];
    /* 0x178 */ u32 prePitLane; /* sub_0800BE00 arg to warp back after pit */
    /* 0x17C */ s32 trackCueCursor; /* gTrackCueList pointer walked by the 8-byte track-cue records (held as a pointer) */
    /* 0x180 */ u8 torqueDampTimer; /* nonzero: 16x torque while decrementing; armed outside the direct call graph */
    /* 0x181 */ u8 pitStall;
    /* 0x182 */ u16 pitExitPending;
    /* 0x184 */ s32 pitProgress;
    /* 0x188 */ s32 pitDuration;
    /* 0x18C */ u16 prevProgress;
    /* 0x18E */ u8 lapStartedFlag;
    /* 0x18F */ u8 pitCollidable;
};

typedef char CarSizeCheck[sizeof(struct Car) == 0x190 ? 1 : -1];

// gCars: the main program's cars at 0x0202A550 (stride 0x190).
extern struct Car gCars[];

// gModule_Cars: the high module's cars, gUnk_0203D520 on the other GBA
// (renamed separately; a different machine, not an alias of gCars).
extern struct Car gModule_Cars[];

#endif // GUARD_CAR_H
