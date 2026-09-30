#include "global.h"
#include "variables.h"
#include "functions.h"
#include "car.h"

extern u32 gModule_DriverRoster[][2];

void sub_08344684(void)
{
}

void sub_08344688(void)
{
}

u32 sub_0834468C(u8 r0)
{
    return gModule_DriverRoster[r0][0];
}

struct Unk083FDB98 {
    u32 a;
    u8 b;
};


u8 sub_0834469C(u8 id)
{
    u8 i;

    for (i = 0; i != 0x1E; i++) {
        if (((struct Unk083FDB98 *)gModule_DriverRoster)[i].b == id)
            return i;
    }
    return 0;
}

void sub_083446C8(u8 param)
{
    u8 v;
    register u8 w asm("r3");

    v = param;
    w = v;
    if (v == 0) {
        gUnk_0203E140[0] = 1;
        gUnk_0203E140[1] = 1;
        gUnk_0203E140[2] = 1;
        gUnk_0203E140[3] = 1;
        gUnk_0203E140[4] = 1;
        gUnk_0203E140[5] = 1;
        gUnk_0203E140[6] = 1;
    }
    if (v == 1) {
        gUnk_0203E140[7] = v;
        gUnk_0203E140[8] = v;
        gUnk_0203E140[9] = v;
        gUnk_0203E140[10] = v;
        gUnk_0203E140[11] = v;
    }
    if (w == 2) {
        gUnk_0203E140[12] = 1;
        gUnk_0203E140[13] = 1;
        gUnk_0203E140[14] = 1;
        gUnk_0203E140[15] = 1;
        gUnk_0203E140[16] = 1;
    }
}

u32 sub_0834470C(void)
{
    u8 i;

    for (i = 0; i != 0x11; i++) {
        if (gUnk_0203E140[i] != 0)
            return 1;
    }
    return 0;
}

void sub_08344730(void)
{
}

void sub_08344734(void)
{
}

extern u32 gModule_CareerDecision[];
extern u32 gModule_StayOnThisTeam[];
extern u32 gModule_ChooseANewTeam[];

void ModuleDrawBigText(u32 a);
void sub_0833F3C0(u32 a, u32 b, u32 c);

void sub_08344738(u8 a)
{
    u32 p;

    ModuleDrawBigText(gModule_CareerDecision);
    p = (u32)gModule_StayOnThisTeam;
    sub_0833F3C0(p, 8, a == 0);
    p = (u32)gModule_ChooseANewTeam;
    sub_0833F3C0(p, 0xA, a == 1);
}

void sub_08344778(void)
{
}

extern u8 gModule_ChampionshipRequiredFinish[];
extern u8 gModule_ChampionshipTeamTiers[];
u8 sub_0834477C(u8 a, u8 b)
{
    u8 i;
    if (b >= gModule_ChampionshipRequiredFinish[a] - 1) {
        sub_08344730();
        gUnk_0203E140[a] = 0;
        return 1;
    }
    i = 0;
    do {
        if (b < gModule_ChampionshipRequiredFinish[i])
            gUnk_0203E140[i] = 1;
        i++;
    } while (i != 0x11);
    sub_08344734();
    sub_083446C8(gModule_ChampionshipTeamTiers[a]);
    return 0;
}

void sub_083447E8(void)
{
    u32 *dest = (u32 *)*(u32 *)&gModule_TextLayerMapPtr[0];
    u32 r1 = 0;
    u32 val = 0;
    u32 r2 = 0xA0 << 1;

    do
    {
        *dest = val;
        dest++;
        r1++;
    } while (r1 != r2);
}

void sub_08344804(void)
{
    u8 i;
    struct Car **p;
    struct Car *a;
    struct Car *b;
    u32 swapped;

    i = 0;
    do
    {
        ((struct Unk0202A550 **)gUnk_02039200)[i] = &gModule_Cars[i];
        i++;
    } while (i != 0x5);
    /* A goto keeps the field-offset setup inside each sort pass. */
outer:
    {
        swapped = 0;
        p = (struct Unk0202A550 **)gUnk_02039200;
        i = 0;
        do
        {
            a = p[0];
            b = p[1];
            if (a->finishTime > b->finishTime)
            {
                p[0] = b;
                p[1] = a;
                swapped = 1;
            }
            p++;
            i++;
        } while (i != 0x4);
    }
    if (swapped != 0) goto outer;
}
