#include "global.h"
#include "functions.h"
#include "variables.h"

struct Car {
    u8 pad00[0x7C];
    u8 unk7C;
    u8 unk7D;
    u8 pad7E[0x88 - 0x7E];
    s32 damage;
    u8 pad8C[0xA0 - 0x8C];
    u16 aiInput;
    u8 padA2[0x150 - 0xA2];
    u8 racePosition;
    u8 pad151[0x15C - 0x151];
    s32 unk15C;
    u8 pad160[0x166 - 0x160];
    u8 unk166;
    u8 pad167[0x175 - 0x167];
    u8 pitState;
    u8 pad176[0x190 - 0x176];
};

extern u16 gKeysHeld;
extern u32 gUnk_0200209C;
extern struct Car gCars[];

void UpdatePitStop(struct Car *a, u8 b);
void UpdateRacePosition(u8 a);
void sub_0800A628(struct Car *a);
void sub_0800B8A8(struct Car *a);
void UpdateCarPhysics(struct Car *a, u16 b, u8 c);

void UpdateCar(struct Car *car, u8 idx)
{
    u16 *p;
    u32 v;

    v = gIsLinkRace;
    if (v != 0) {
        if (gUnk_020021E0 == 0 && car->unk7D == 0)
            UpdateCarPhysics(car, gUnk_020020A0[idx], idx);
        else
            UpdateCarPhysics(car, 2, idx);
        sub_0800A628(car);
    } else if (idx == 0) {
        if (car->pitState != 0) {
            UpdatePitStop(car, 0);
            UpdateCarPhysics(car, car->aiInput, 0);
        } else if (gUnk_0200215C[0] == 9 || gUnk_0200215C[0] == 0xD || gUnk_0200215C[0] == 0xE
                || gUnk_0200215C[0] == 0xF || gUnk_0200215C[0] == 0x11) {
            UpdateAiDriver((struct Unk0800C534 *)car, idx);
            UpdateCarPhysics(car, car->aiInput, idx);
        } else {
            /* One shared sub_0800A628 call, as in the gIsLinkRace branch:
               a call that ends a block before a label gets a USE insn from
               flow, which keeps jump2 from cross-jumping the call itself. */
            if (gUnk_020021E0 == 0)
                UpdateCarPhysics(car, gKeysHeld, 0);
            else
                UpdateCarPhysics(car, 2, 0);
            sub_0800A628(car);
        }
    } else {
        if (gUnk_0200215C[0] == 9 || gUnk_0200215C[0] == 0xD || gUnk_0200215C[0] == 0xE
                || gUnk_0200215C[0] == 0xF || gUnk_0200215C[0] == 0x11)
            goto common;
        if (gUnk_0200215C[0] != 4) {
            if (gUnk_020021E0 == 0) {
                if (car->pitState != 0) {
                    UpdatePitStop(car, idx);
                } else {
common:
                    UpdateAiDriver((struct Unk0800C534 *)car, idx);
                }
                p = &car->aiInput;
            } else {
                car->aiInput = 2;
                p = &car->aiInput;
            }
        } else {
            car->aiInput = v;
            p = &car->aiInput;
        }
        sub_0800A628(car);
        UpdateCarPhysics(car, *p, idx);
    }

    if (car->damage > 0x11940 && car->unk7C != 1 && (gUnk_0200209C & 0x3F) == 0)
        sub_0800B8A8(car);

    if (gIsLinkRace != 0) {
        if (idx == gLinkPlayerId[0]) {
            UpdateRacePosition(idx);
            if (gCars[idx].racePosition != 0 && gCars[idx].racePosition != 0x63)
                gCars[idx].unk166 = 0;
        }
    } else if (idx == 0) {
        UpdateRacePosition(0);
        if (gCars[0].racePosition != 0 && gCars[0].racePosition != 0x63)
            gCars[0].unk166 = idx;
    }
    car->unk15C++;
}
