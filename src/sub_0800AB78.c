#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"


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
        if (gRaceEndState == 0 && car->finished == 0)
            UpdateCarPhysics(car, gPlayerKeys[idx], idx);
        else
            UpdateCarPhysics(car, 2, idx);
        sub_0800A628(car);
    } else if (idx == 0) {
        if (car->pitState != 0) {
            UpdatePitStop(car, 0);
            UpdateCarPhysics(car, car->aiInput, 0);
        } else if (gGameMode[0] == 9 || gGameMode[0] == 0xD || gGameMode[0] == 0xE
                || gGameMode[0] == 0xF || gGameMode[0] == 0x11) {
            UpdateAiDriver((struct Unk0800C534 *)car, idx);
            UpdateCarPhysics(car, car->aiInput, idx);
        } else {
            /* One shared sub_0800A628 call, as in the gIsLinkRace branch:
               a call that ends a block before a label gets a USE insn from
               flow, which keeps jump2 from cross-jumping the call itself. */
            if (gRaceEndState == 0)
                UpdateCarPhysics(car, gKeysHeld, 0);
            else
                UpdateCarPhysics(car, 2, 0);
            sub_0800A628(car);
        }
    } else {
        if (gGameMode[0] == 9 || gGameMode[0] == 0xD || gGameMode[0] == 0xE
                || gGameMode[0] == 0xF || gGameMode[0] == 0x11)
            goto common;
        if (gGameMode[0] != 4) {
            if (gRaceEndState == 0) {
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

    if (car->damage > 0x11940 && car->carState != 1 && ((*(u32 *)&gFrameCounter) & 0x3F) == 0)
        sub_0800B8A8(car);

    if (gIsLinkRace != 0) {
        if (idx == gLinkPlayerId[0]) {
            UpdateRacePosition(idx);
            if (gCars[idx].racePosition != 0 && gCars[idx].racePosition != 0x63)
                gCars[idx].ledLapFlag = 0;
        }
    } else if (idx == 0) {
        UpdateRacePosition(0);
        if (gCars[0].racePosition != 0 && gCars[0].racePosition != 0x63)
            gCars[0].ledLapFlag = idx;
    }
    car->tickCount++;
}
