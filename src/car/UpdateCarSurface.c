#include "global.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#include "car.h"

void EnterPit(u8 *a, u8 b);
u8 GetTrackTileType(s32 x, s32 y);

void UpdateCarSurface(struct Car *car)
{
    u8 pad[0x28];
    s32 playerIdx;
    s32 tileX, tileY;
    s32 posX, posZ;
    s32 x, y;
    u8 tileType;
    u8 pitTileCount;
    u8 muteGrassSound;

    car->onApron = 0;
    car->wasOnGrass = car->onGrass;
    car->onGrass = 0;
    car->behindBgFlag = 0;
    if (gGameMode[0] == 4)
        return;
    if (gTrackId == 7)
        return;
    playerIdx = 0;
    if (gIsLinkRace != 0)
        playerIdx = gLinkPlayerId[0];
    posX = car->posX;
    posZ = car->posZ;
    tileX = posX >> 19;
    tileY = posZ >> 19;
    tileY += 2;
    tileX += 1;
    car->onApron = 0;
    car->onGrass = 0;
    car->behindBgFlag = 0;
    pitTileCount = 0;
    for (y = tileY - 1; y != tileY + 2; y++) {
        for (x = tileX - 1; x != tileX + 2; x++) {
            tileType = GetTrackTileType(x, y);
            if (tileType & 1)
                car->behindBgFlag = 1;
            if ((tileType == 2 || tileType == 3) && x == tileX && y == tileY)
                car->onApron = 1;
            if ((tileType == 4 || tileType == 5) && x == tileX && y == tileY)
                car->onGrass = 1;
            if (tileType == 6)
                pitTileCount++;
            if ((tileType == 8 || tileType == 9) && car->pitState == 6)
                car->pitExitPending = 0;
        }
    }
    if (pitTileCount > 4 ||
        (pitTileCount != 0 && (gTrackId == 3 || gTrackId == 5 || gTrackId == 8 || gTrackId == 0xB || gTrackId == 2))) {
        if (gIsLinkRace == 0 && car == gCars)
            EnterPit((u8 *)car, 0);
    }
    muteGrassSound = 0;
    if ((u8)(gGameMode[0] - 0xF) <= 1 && gChallengeIndex == 0xC)
        muteGrassSound = 1;
    if (car == &gCars[playerIdx]) {
        if (car->onGrass != 0 && car->wasOnGrass == 0 && muteGrassSound == 0 && gOptions[3] != 0 && gIsDemo == 0 &&
            gRaceEndState == 0)
            m4aSongNumStart(0x1C);
    }
    if (car == &gCars[playerIdx]) {
        if (car->onGrass != 0 && (Random8() & 0x1F) == 0 && gOptions[3] != 0 && gIsDemo == 0 && gRaceEndState == 0 &&
            muteGrassSound == 0)
            m4aSongNumStart(0x1D);
    }
    if (car == &gCars[playerIdx]) {
        if ((*(u32 *)&car->onApron & 0xFF00FF00) == 0x01000000) {
            m4aMPlayStop((struct MusicPlayerInfo *)((s32)gUnk_02001FA0));
            m4aMPlayStop((struct MusicPlayerInfo *)((s32)gUnk_02002030));
            m4aMPlayStop((struct MusicPlayerInfo *)((s32)gUnk_02001FE0));
        }
    }
    if (gGameMode[0] == 0x10 && gChallengeIndex == 0xC)
        car->onGrass = 0;
}
