#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

/* Matching reconstruction: accept the menu's address argument, unused here. */
void SetupChallenge(u8 a, u8 *unused)
{
    u8 i;

    for (i = 0; i != 24; i++) {
        gCars[i].finished = 0;
        gCars[i].finishTime = 0;
    }

    switch (a) {
        case 0:
            (*(u8 *)&gNumCars) = 1;
            gCars[0].driverId = 0;
            AssignRandomDrivers();
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            FinishAllCars(0);
            SortCarsByTime();
            gNumLaps = 1;
            (*(struct Car **)&gCarOrder) = gCars;
            break;
        case 1:
            (*(u8 *)&gNumCars) = 1;
            gCars[0].driverId = 0;
            AssignRandomDrivers();
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            FinishAllCars(0);
            SortCarsByTime();
            gNumLaps = 5;
            (*(struct Car **)&gCarOrder) = gCars;
            break;
        case 2:
            (*(u8 *)&gNumCars) = 24;
            gCars[0].driverId = 0;
            AssignRandomDrivers();
            for (i = 1; i != 24; i++) {
                gCars[i].finishTime = i;
                gCars[i].finished = 1;
            }
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            SortCarsByTime();
            gNumLaps = 10;
            break;
        case 3:
            (*(u8 *)&gNumCars) = 24;
            gCars[0].driverId = 0;
            AssignRandomDrivers();
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            for (i = 1; i != 24; i++) {
                gCars[i].finishTime = i + 500;
                gCars[i].finished = 1;
            }
            SortCarsByTime();
            gNumLaps = 50;
            gPlayerPittedFlag = 0;
            break;
        case 4:
            gCars[0].driverId = 0;
            AssignRandomDrivers();
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            FinishAllCars(0);
            SortCarsByTime();
            gNumLaps = 2;
            (*(u8 *)&gNumCars) = 1;
            (*(struct Car **)&gCarOrder) = gCars;
            break;
        case 5:
            (*(u8 *)&gNumCars) = 24;
            gCars[0].driverId = 11;
            AssignRandomDrivers();
            for (i = 1; i != 24; i++) {
                gCars[i].finishTime = i * 2;
                gCars[i].finished = 1;
            }
            gCars[0].finishTime = 8;
            gCars[0].finished = 1;
            SortCarsByTime();
            gNumLaps = 10;
            break;
        case 6:
            (*(u8 *)&gNumCars) = 24;
            gCars[0].driverId = 4;
            AssignRandomDrivers();
            for (i = 1; i != 15; i++) {
                gCars[i].finishTime = i;
                gCars[i].finished = 1;
            }
            gCars[0].finishTime = 15;
            gCars[0].finished = 1;
            for (i = 15; i != 24; i++) {
                gCars[i].finishTime = i + 2;
                gCars[i].finished = 1;
            }
            SortCarsByTime();
            gNumLaps = 50;
            break;
        case 7:
            (*(u8 *)&gNumCars) = 1;
            gCars[0].driverId = 8;
            AssignRandomDrivers();
            for (i = 0; i != 24; i++)
                gCars[i].finished = 0;
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            FinishAllCars(0);
            SortCarsByTime();
            gNumLaps = 5;
            (*(struct Car **)&gCarOrder) = gCars;
            break;
        case 8:
            (*(u8 *)&gNumCars) = 1;
            gCars[0].driverId = 0;
            AssignRandomDrivers();
            for (i = 0; i != 24; i++)
                gCars[i].finished = 0;
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            FinishAllCars(0);
            SortCarsByTime();
            gNumLaps = 3;
            (*(struct Car **)&gCarOrder) = gCars;
            break;
        case 9:
            (*(u8 *)&gNumCars) = 1;
            gCars[0].driverId = 9;
            AssignRandomDrivers();
            for (i = 0; i != 24; i++)
                gCars[i].finished = 0;
            gCars[0].finishTime = 0;
            gCars[0].finished = 1;
            FinishAllCars(0);
            SortCarsByTime();
            gNumLaps = 3;
            gChallengeBestValue = 0;
            (*(struct Car **)&gCarOrder) = gCars;
            for (i = 0; i != 32; i++)
                gWaypointSpeedSamples[i] = 0;
            break;
        case 10:
            (*(u8 *)&gNumCars) = 24;
            gCars[0].driverId = 5;
            AssignRandomDrivers();
            for (i = 1; i != 24; i++) {
                gCars[i].finishTime = i;
                gCars[i].finished = 1;
            }
            gCars[0].finishTime = 100;
            gCars[0].finished = 1;
            SortCarsByTime();
            gNumLaps = 25;
            break;
        case 11:
            (*(u8 *)&gNumCars) = 24;
            gCars[0].driverId = 0;
            AssignRandomDrivers();
            for (i = 1; i != 24; i++) {
                gCars[i].finishTime = i * 5;
                gCars[i].finished = 1;
            }
            gCars[0].finishTime = 27;
            gCars[0].finished = 1;
            SortCarsByTime();
            gNumLaps = 20;
            break;
        case 12:
            (*(u8 *)&gNumCars) = 6;
            gCars[0].driverId = 0;
            AssignRandomDrivers();
            for (i = 1; i != 4; i++) {
                gCars[i].finishTime = i;
                gCars[i].finished = 1;
            }
            gCars[0].finishTime = 4;
            gCars[0].finished = 1;
            for (i = 4; i != 24; i++) {
                gCars[i].finishTime = i + 10;
                gCars[i].finished = 1;
            }
            SortCarsByTime();
            gNumLaps = 100;
            break;
        case 13:
            (*(u8 *)&gNumCars) = 24;
            for (i = 0; i != 24; i++)
                gCars[i].driverId = 99;
            gCars[0].driverId = 1;
            gCars[1].driverId = 0;
            gCars[2].driverId = 8;
            FillUnassignedDrivers();
            gCars[0].finishTime = 100;
            gCars[0].finished = 1;
            gCars[1].finishTime = 99;
            gCars[1].finished = 1;
            gCars[2].finishTime = 98;
            gCars[2].finished = 1;
            for (i = 3; i != 24; i++) {
                gCars[i].finishTime = i + 100;
                gCars[i].finished = 1;
            }
            SortCarsByTime();
            gNumLaps = 20;
            break;
        case 14:
            (*(u8 *)&gNumCars) = 24;
            gCars[0].driverId = 1;
            AssignRandomDrivers();
            for (i = 1; i != 3; i++) {
                gCars[i].finishTime = i;
                gCars[i].finished = 1;
            }
            gCars[0].finishTime = 3;
            gCars[0].finished = 1;
            for (i = 3; i != 24; i++) {
                gCars[i].finishTime = i + 1;
                gCars[i].finished = 1;
            }
            SortCarsByTime();
            gNumLaps = 20;
            break;
        case 15:
            (*(u8 *)&gNumCars) = 24;
            gCars[0].driverId = 4;
            AssignRandomDrivers();
            for (i = 1; i != 24; i++) {
                gCars[i].finishTime = i;
                gCars[i].finished = 1;
            }
            gCars[0].finishTime = 100;
            gCars[0].finished = 1;
            SortCarsByTime();
            gNumLaps = 40;
            break;
    }
    gChallengeResult = 0;
}
