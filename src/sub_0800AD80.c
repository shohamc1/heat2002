#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u16 gPitEntryProgressPoints[];
extern u16 gPitExitProgressPoints[];

void UpdateCar(struct Car *p, u8 idx);
u8 CarNeedsPit(struct Car *p);
u8 FindFreePitStall(u8 a);
void EnterPit(struct Car *p, u8 a);

void UpdateAllCars(void)
{
    struct Car *p;
    u8 count;
    s32 i;
    u16 *t;
    u8 v;

    ReadKeys();
    p = gCars;
    count = gNumCars[0];
    if (gIsLinkRace != 0 || gGameMode[0] == 4)
        count = gNumLinkPlayers[0];
    if (gGameMode[0] == 2)
        count = 1;
    gFuelOutStutterCounter++;
    for (i = 0; i != count; i++) {
        UpdateCar(p, i);
        if (p->prevProgress <= gPitEntryProgressPoints[gTrackId]
            && ((*(u32 *)&p->progress) & 0xFFFF) >= gPitEntryProgressPoints[gTrackId] && CarNeedsPit(p) != 0
            && p != gCars) {
            v = gDamagePitsEnabled;
            if (v != 0) {
                v = FindFreePitStall(v);
                if (v != 0x63)
                    EnterPit(p, FindFreePitStall(v));
            }
        }
        if (p != gCars && p->pitState != 0) {
            if (p->prevProgress <= gPitExitProgressPoints[gTrackId]
                && ((*(u32 *)&p->progress) & 0xFFFF) >= gPitExitProgressPoints[gTrackId])
                p->pitCollidable = 0;
        }
        p++;
    }
}
