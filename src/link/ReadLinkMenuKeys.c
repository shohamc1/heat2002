#include "global.h"
#include "variables.h"


u16 ReadLinkMenuKeys(void)
{
    u16 keys;
    u16 playerIdx;
    u32 numPlayers;
    u16 *pressedPtr;
    u16 *prevPtr;
    u16 *playerKeys;
    u32 startKey;
    u32 numPlayersCopy;
    register u8 *menuPlayerPtr asm("r4") = &gLinkMenuPlayerIndex;

    if (*menuPlayerPtr == 0xFF) {
        keys = 0;
        playerIdx = 0;
        numPlayers = gNumLinkPlayers[0];
        pressedPtr = &gLinkMenuKeysPressed;
        prevPtr = &gLinkMenuKeysPrev;
        if (keys != numPlayers) {
            playerKeys = gPlayerKeys;
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
    } else {
        keys = gPlayerKeys[*menuPlayerPtr];
        gLinkMenuKeysPressed = keys & ~gLinkMenuKeysPrev;
        gLinkMenuKeysPrev = keys;
        return gLinkMenuKeysPressed;
    }
}
