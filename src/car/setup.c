#include "global.h"
#include "functions.h"
#include "car.h"
#include "variables.h"
#include "data.h"

extern u16 gTuneDefaultGearPower[];
extern u16 gTuneDefaultGearRatio[];

void ComputeGearRatioReciprocals(u16 *src, u16 *dest)
{
    u8 i = 0;

    do {
        u16 *out = (u16 *)(2 * i + (u32)dest);
        *out = sub_08017230(0x10000, *(u16 *)(2 * i + (u32)src));
        i++;
    } while (i != 5);
}

void InitTuneSettings(void)
{
    u16 *ratios;
    u16 *reciprocals;
    u8 i = 0;
    do {
        gUnk_0202A540[i] = gTuneDefaultGearPower[i];
        gUnk_0202CB20[i] = gTuneDefaultGearRatio[i];
        i++;
    } while (i != 5);
    ratios = gUnk_0202CB20;
    reciprocals = gUnk_0202CB00;
    ComputeGearRatioReciprocals(ratios, reciprocals);
}

void SetAiDriverGearTables(struct Car *car)
{
    *(vu8 *)&gGameMode[0]; /* deliberate volatile read: keeps the load in the output */
    car->gearPowerTable = gAiDriverGearPowerTable;
    car->gearRatioTable = gAiDriverGearRatioTable;
    car->rpmPerSpeedTable = gAiDriverRpmPerSpeedTable;
}
