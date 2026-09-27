#include "global.h"
#include "functions.h"
#include "variables.h"

struct Car {
    u8 pad00[0x50];
    u32 progress;
    u8 pad54[0x175 - 0x54];
    u8 pitState;
    u8 pad176[0x18C - 0x176];
    u16 unk18C;
    u8 pad18E[0x18F - 0x18E];
    u8 unk18F;
};

extern struct Car gCars[];
extern u16 gUnk_083675F0[];
extern u16 gUnk_08367608[];

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
    if (gIsLinkRace != 0 || gUnk_0200215C[0] == 4)
        count = gNumLinkPlayers[0];
    if (gUnk_0200215C[0] == 2)
        count = 1;
    gUnk_0202A51C++;
    for (i = 0; i != count; i++) {
        UpdateCar(p, i);
        if (p->unk18C <= gUnk_083675F0[gTrackId]
            && (p->progress & 0xFFFF) >= gUnk_083675F0[gTrackId] && CarNeedsPit(p) != 0
            && p != gCars) {
            v = gUnk_0202EEB0;
            if (v != 0) {
                v = FindFreePitStall(v);
                if (v != 0x63)
                    EnterPit(p, FindFreePitStall(v));
            }
        }
        if (p != gCars && p->pitState != 0) {
            if (p->unk18C <= gUnk_08367608[gTrackId]
                && (p->progress & 0xFFFF) >= gUnk_08367608[gTrackId])
                p->unk18F = 0;
        }
        p++;
    }
}
