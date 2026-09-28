#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u16 gUnk_02026DC4[];
extern u16 gUnk_02026DDC[];

void sub_083425C4(struct Car *p, u8 idx);
u8 ModuleCarNeedsPit(struct Car *p);
u8 ModuleFindFreePitStall(u8 a);
void ModuleEnterPit(struct Car *p, u8 a);

void sub_083426C8(void)
{
    struct Car *p;
    u8 count;
    s32 i;
    u16 *t;
    u8 v;

    ModuleReadKeys();
    p = gModule_Cars;
    count = gModule_NumCars[0];
    if (gModule_IsLinkRace != 0 || gModule_GameMode[0] == 4)
        count = gModule_NumLinkPlayers[0];
    if (gModule_GameMode[0] == 2)
        count = 1;
    gUnk_0203D4E8++;
    for (i = 0; i != count; i++) {
        sub_083425C4(p, i);
        if (p->prevProgress <= gUnk_02026DC4[gModule_TrackId]
            && (*(u32 *)&p->progress & 0xFFFF) >= gUnk_02026DC4[gModule_TrackId] && ModuleCarNeedsPit(p) != 0
            && p != gModule_Cars) {
            v = gModule_DamagePitsEnabled;
            if (v != 0) {
                v = ModuleFindFreePitStall(v);
                if (v != 0x63)
                    ModuleEnterPit(p, ModuleFindFreePitStall(v));
            }
        }
        if (p != gModule_Cars && p->pitState != 0) {
            if (p->prevProgress <= gUnk_02026DDC[gModule_TrackId]
                && (*(u32 *)&p->progress & 0xFFFF) >= gUnk_02026DDC[gModule_TrackId])
                p->pitCollidable = 0;
        }
        p++;
    }
}
