#include "global.h"
#include "functions.h"
#include "variables.h"

u16 ModuleReadLinkMenuKeys(void)
{
    u16 keys;
    u16 playerIdx;
    u32 numPlayers;
    u16 *pressedPtr;
    u16 *prevPtr;
    u16 *playerKeys;
    u32 startKey;
    u32 numPlayersCopy;
    register u8 *menuPlayerPtr PIN(r4) = &gUnk_0203B850;

    if (*menuPlayerPtr == 0xFF) {
        keys = 0;
        playerIdx = 0;
        numPlayers = gModule_NumLinkPlayers[0];
        pressedPtr = &gUnk_0203B6FC;
        prevPtr = &gUnk_0203B848;
        if (keys != numPlayers) {
            playerKeys = gUnk_020390B0;
            startKey = 8;
            numPlayersCopy = numPlayers;
            do {
                if (playerKeys[playerIdx] & startKey) {
                    *menuPlayerPtr = playerIdx;
                    keys = playerKeys[playerIdx];
                }
                playerIdx++;
            } while (playerIdx != numPlayersCopy);
        }
        *pressedPtr = keys & ~*prevPtr;
        *prevPtr = keys;
        return *pressedPtr;
    }
    keys = gUnk_020390B0[*menuPlayerPtr];
    gUnk_0203B6FC = keys & ~gUnk_0203B848;
    gUnk_0203B848 = keys;
    return gUnk_0203B6FC;
}
