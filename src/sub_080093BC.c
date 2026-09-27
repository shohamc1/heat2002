#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

extern u8 gUnk_0806C918[];
extern u8 gUnk_0806C924[];
extern u8 gUnk_0806C934[];
extern u32 gUnk_08368124[];
extern u32 gUnk_08368134[];
extern s32 gUnk_0202A520;
extern s32 gUnk_0202CAE0;


void UpdatePitStop(struct Car *a1, u8 a2)
{
    u32 v;
    s32 *p;

    if (gUnk_0202CAD0 != 0 && a1 == gCars)
        sub_080080B4();
    if (a1 == gCars && gUnk_0202EEB0 == 0)
        /* DrawTextCentered: the ROM callers pass a third argument the matched definition drops; call
           through a function pointer with the old prototype. */
        ((void (*)(u8 *, u32, u32))DrawTextCentered)(gUnk_0806C918, 10, 1);
    switch (a1->pitState) {
    case 0:
        break;
    case 1:
    case 2:
    case 3:
        UpdateAiDriver((struct Unk0800C534 *)a1, a2);
        break;
    case 4:
        if (gUnk_0202CAD0 == 0 && gUnk_0202A53C == 0)
            a1->pitState = 5;
        else if (gUnk_0202EEB0 != 0)
            StopCar((struct Unk0A5BC *)a1);
        else
            a1->pitState = 5;
        if (gUnk_0202CAD0 != 0 && a1 == gCars) {
            StopCar((struct Unk0A5BC *)a1);
            break;
        }
        a1->pitProgress = 0;
        a1->pitDuration = 0x6400;
        a1->pitState = 5;
        if (a1 != gCars)
            break;
        a1->pitDuration = gUnk_08368124[gUnk_0202CBC0[0]];
        if (gUnk_0202CBC0[1] == 2)
            gUnk_0202A520 = 0;
        if (gUnk_0202CBC0[1] == 1) {
            if (a1->fuel > 0x8200)
                gUnk_0202A520 = 0xB400 - a1->fuel;
            else
                gUnk_0202A520 = 0x3200;
        }
        if (gUnk_0202CBC0[1] == 0)
            gUnk_0202A520 = 0xB400 - a1->fuel;
        p = &a1->pitDuration;
        *p += gUnk_0202A520;
        *p += gUnk_08368134[gUnk_0202CBC0[2]];
        gUnk_0202CAE0 = 0x6400 / (*p >> 8);
        *p = 0x6400;
        break;
    case 5:
        if (gUnk_0202EEB0 != 0)
            StopCar((struct Unk0A5BC *)a1);
        if (a1->pitProgress < a1->pitDuration
            && (a1 != gCars || gUnk_0202A53C != 0)
            && gUnk_0202EEB0 != 0)
            goto l_big;
        if (a1 == gCars) {
            sub_080091F8();
            a1->unk182 = 1;
        } else {
            a1->unk182 = 1;
        }
        a1->pitState = 6;
        break;
l_big:
        if (a1 == gCars) {
            if (gUnk_0202A53C != 0) {
                if (gOptions[3] != 0) {
                    if (gIsDemo == 0 && gUnk_020021E0 == 0
                        && (Random8() & 15) > 13) {
                        v = Random8() & 3;
                        if (v == 0)
                            m4aSongNumStart(25);
                        if (v == 1)
                            m4aSongNumStart(26);
                        if (v == 2)
                            m4aSongNumStart(24);
                        if (v == 3)
                            m4aSongNumStart(24);
                    }
                }
                sub_0800920C((a1->pitProgress >> 8) % 100);
            }
        }
        if (a1 != gCars)
            a1->pitProgress += 0x100;
        else
            a1->pitProgress += gUnk_0202CAE0;
        if (a1 == gCars) {
            if (gUnk_0202A53C == 0)
                break;
            if (gUnk_0202A520 > 0) {
                gUnk_0202A520 -= 0x100;
                a1->fuel += 0x100;
            }
            if (gUnk_0202CBC0[0] != 3) {
                a1->tireWear0 = 0;
                a1->tireWear1 = 0;
                a1->tireWear2 = 0;
                a1->tireWear3 = 0;
            }
            if (gUnk_0202CBC0[2] == 0)
                a1->damage = 0;
        } else {
            a1->fuel = 0xB400;
            a1->tireWear0 = 0;
            a1->tireWear1 = 0;
            a1->tireWear2 = 0;
            a1->tireWear3 = 0;
            a1->damage = 0;
        }
        break;
    case 6:
        v = a1->unk182;
        if (v == 0) {
            a1->pitState = v;
            if (a1 != gCars) {
                sub_0800BE00(a1, a1->unk178);
                a1->unk18F = 1;
            }
            gUnk_0202CBC8[a1->pitStall] = v;
            if (a1 == gCars)
                sub_0800649C(gUnk_0806C924, 9, 10);
        } else {
            UpdateAiDriver((struct Unk0800C534 *)a1, a2);
            if (a1 == gCars && gUnk_0202EEB0 != 0)
                sub_0800649C(gUnk_0806C934, 10, 10);
        }
        break;
    }
}
