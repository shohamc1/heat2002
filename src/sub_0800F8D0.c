#include "global.h"

struct UnkCar {
    /* 0x000 */ u8 filler000[0x7D];
    /* 0x07D */ u8 unk7D;
    /* 0x07E */ u8 filler07E[0x162 - 0x7E];
    /* 0x162 */ u8 driverId;
    /* 0x163 */ u8 filler163[0x16C - 0x163];
    /* 0x16C */ u32 unk16C;
    /* 0x170 */ u8 filler170[400 - 0x170];
};

extern u8 gNumCars;              /* 0x02002090 */
extern u8 gNumLaps;              /* 0x02002184 */
extern struct UnkCar gCars[]; /* 0x0202A550 */
extern u32 gUnk_0202CB40[];           /* 0x0202CB40 */
extern u8 gUnk_0202CBD0;              /* 0x0202CBD0 */
extern u32 gUnk_0202CBD8;             /* 0x0202CBD8 */
extern u8 gUnk_0202EEE4;              /* 0x0202EEE4 */
extern struct UnkCar *gCarOrder;  /* 0x0202EFC0 */

extern void AssignRandomDrivers(void);
extern void FillUnassignedDrivers(void);
extern void SortCarsByTime(void);
extern void sub_08016D28(u8 a);

/* Matching reconstruction: accept the menu's address argument, unused here. */
void SetupChallenge(u8 a, u8 *unused)
{
    u8 i;

    for (i = 0; i != 24; i++) {
        gCars[i].unk7D = 0;
        gCars[i].unk16C = 0;
    }

    switch (a) {
    case 0:
        gNumCars = 1;
        gCars[0].driverId = 0;
        AssignRandomDrivers();
        gCars[0].unk16C = 0;
        gCars[0].unk7D = 1;
        sub_08016D28(0);
        SortCarsByTime();
        gNumLaps = 1;
        gCarOrder = gCars;
        break;
    case 1:
        gNumCars = 1;
        gCars[0].driverId = 0;
        AssignRandomDrivers();
        gCars[0].unk16C = 0;
        gCars[0].unk7D = 1;
        sub_08016D28(0);
        SortCarsByTime();
        gNumLaps = 5;
        gCarOrder = gCars;
        break;
    case 2:
        gNumCars = 24;
        gCars[0].driverId = 0;
        AssignRandomDrivers();
        for (i = 1; i != 24; i++) {
            gCars[i].unk16C = i;
            gCars[i].unk7D = 1;
        }
        gCars[0].unk16C = 0;
        gCars[0].unk7D = 1;
        SortCarsByTime();
        gNumLaps = 10;
        break;
    case 3:
        gNumCars = 24;
        gCars[0].driverId = 0;
        AssignRandomDrivers();
        gCars[0].unk16C = 0;
        gCars[0].unk7D = 1;
        for (i = 1; i != 24; i++) {
            gCars[i].unk16C = i + 500;
            gCars[i].unk7D = 1;
        }
        SortCarsByTime();
        gNumLaps = 50;
        gUnk_0202CBD0 = 0;
        break;
    case 4:
        gCars[0].driverId = 0;
        AssignRandomDrivers();
        gCars[0].unk16C = 0;
        gCars[0].unk7D = 1;
        sub_08016D28(0);
        SortCarsByTime();
        gNumLaps = 2;
        gNumCars = 1;
        gCarOrder = gCars;
        break;
    case 5:
        gNumCars = 24;
        gCars[0].driverId = 11;
        AssignRandomDrivers();
        for (i = 1; i != 24; i++) {
            gCars[i].unk16C = i * 2;
            gCars[i].unk7D = 1;
        }
        gCars[0].unk16C = 8;
        gCars[0].unk7D = 1;
        SortCarsByTime();
        gNumLaps = 10;
        break;
    case 6:
        gNumCars = 24;
        gCars[0].driverId = 4;
        AssignRandomDrivers();
        for (i = 1; i != 15; i++) {
            gCars[i].unk16C = i;
            gCars[i].unk7D = 1;
        }
        gCars[0].unk16C = 15;
        gCars[0].unk7D = 1;
        for (i = 15; i != 24; i++) {
            gCars[i].unk16C = i + 2;
            gCars[i].unk7D = 1;
        }
        SortCarsByTime();
        gNumLaps = 50;
        break;
    case 7:
        gNumCars = 1;
        gCars[0].driverId = 8;
        AssignRandomDrivers();
        for (i = 0; i != 24; i++)
            gCars[i].unk7D = 0;
        gCars[0].unk16C = 0;
        gCars[0].unk7D = 1;
        sub_08016D28(0);
        SortCarsByTime();
        gNumLaps = 5;
        gCarOrder = gCars;
        break;
    case 8:
        gNumCars = 1;
        gCars[0].driverId = 0;
        AssignRandomDrivers();
        for (i = 0; i != 24; i++)
            gCars[i].unk7D = 0;
        gCars[0].unk16C = 0;
        gCars[0].unk7D = 1;
        sub_08016D28(0);
        SortCarsByTime();
        gNumLaps = 3;
        gCarOrder = gCars;
        break;
    case 9:
        gNumCars = 1;
        gCars[0].driverId = 9;
        AssignRandomDrivers();
        for (i = 0; i != 24; i++)
            gCars[i].unk7D = 0;
        gCars[0].unk16C = 0;
        gCars[0].unk7D = 1;
        sub_08016D28(0);
        SortCarsByTime();
        gNumLaps = 3;
        gUnk_0202CBD8 = 0;
        gCarOrder = gCars;
        for (i = 0; i != 32; i++)
            gUnk_0202CB40[i] = 0;
        break;
    case 10:
        gNumCars = 24;
        gCars[0].driverId = 5;
        AssignRandomDrivers();
        for (i = 1; i != 24; i++) {
            gCars[i].unk16C = i;
            gCars[i].unk7D = 1;
        }
        gCars[0].unk16C = 100;
        gCars[0].unk7D = 1;
        SortCarsByTime();
        gNumLaps = 25;
        break;
    case 11:
        gNumCars = 24;
        gCars[0].driverId = 0;
        AssignRandomDrivers();
        for (i = 1; i != 24; i++) {
            gCars[i].unk16C = i * 5;
            gCars[i].unk7D = 1;
        }
        gCars[0].unk16C = 27;
        gCars[0].unk7D = 1;
        SortCarsByTime();
        gNumLaps = 20;
        break;
    case 12:
        gNumCars = 6;
        gCars[0].driverId = 0;
        AssignRandomDrivers();
        for (i = 1; i != 4; i++) {
            gCars[i].unk16C = i;
            gCars[i].unk7D = 1;
        }
        gCars[0].unk16C = 4;
        gCars[0].unk7D = 1;
        for (i = 4; i != 24; i++) {
            gCars[i].unk16C = i + 10;
            gCars[i].unk7D = 1;
        }
        SortCarsByTime();
        gNumLaps = 100;
        break;
    case 13:
        gNumCars = 24;
        for (i = 0; i != 24; i++)
            gCars[i].driverId = 99;
        gCars[0].driverId = 1;
        gCars[1].driverId = 0;
        gCars[2].driverId = 8;
        FillUnassignedDrivers();
        gCars[0].unk16C = 100;
        gCars[0].unk7D = 1;
        gCars[1].unk16C = 99;
        gCars[1].unk7D = 1;
        gCars[2].unk16C = 98;
        gCars[2].unk7D = 1;
        for (i = 3; i != 24; i++) {
            gCars[i].unk16C = i + 100;
            gCars[i].unk7D = 1;
        }
        SortCarsByTime();
        gNumLaps = 20;
        break;
    case 14:
        gNumCars = 24;
        gCars[0].driverId = 1;
        AssignRandomDrivers();
        for (i = 1; i != 3; i++) {
            gCars[i].unk16C = i;
            gCars[i].unk7D = 1;
        }
        gCars[0].unk16C = 3;
        gCars[0].unk7D = 1;
        for (i = 3; i != 24; i++) {
            gCars[i].unk16C = i + 1;
            gCars[i].unk7D = 1;
        }
        SortCarsByTime();
        gNumLaps = 20;
        break;
    case 15:
        gNumCars = 24;
        gCars[0].driverId = 4;
        AssignRandomDrivers();
        for (i = 1; i != 24; i++) {
            gCars[i].unk16C = i;
            gCars[i].unk7D = 1;
        }
        gCars[0].unk16C = 100;
        gCars[0].unk7D = 1;
        SortCarsByTime();
        gNumLaps = 40;
        break;
    }
    gUnk_0202EEE4 = 0;
}
