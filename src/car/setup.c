#include "global.h"
#include "gba/defines.h"
#include "functions.h"
#include "car.h"
#include "variables.h"
#include "data.h"

extern u16 gTuneDefaultGearPower[];
extern u16 gTuneDefaultGearRatio[];

/* The file's three u16 gear tables (gUnk_0202A540, gUnk_0202CB00 and
   gUnk_0202CB20: the five gear values InitTuneSettings copies, the
   reciprocals ComputeGearRatioReciprocals writes, and the third table)
   moved to src/car/globals.c, the owner of the 0x0202A510-0x0202CBE0
   EWRAM run they sit in; they are declared in variables.h. */

void ComputeGearRatioReciprocals(u16 *src, u16 *dest)
{
    u8 i = 0;

    do {
#if PORTABLE
        u16 *out = &dest[i];
        *out = sub_08017230(0x10000, src[i]);
#else
        u16 *out = (u16 *)(2 * i + (u32)dest);
        *out = sub_08017230(0x10000, *(u16 *)(2 * i + (u32)src));
#endif
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
    *(vu8 *)&gGameMode; /* deliberate volatile read: keeps the load in the output */
    car->gearPowerTable = gAiDriverGearPowerTable;
    car->gearRatioTable = gAiDriverGearRatioTable;
    car->rpmPerSpeedTable = gAiDriverRpmPerSpeedTable;
}
