#include "global.h"
#include "functions.h"
#include "variables.h"
#include "car.h"

extern u8 gChallengeEndDelay;


void sub_08008D8C(void)
{
    u8 x;
    s32 v;

    if (gGameMode[0] == 0x10) {
        UpdateChallengeTimer();
        switch (gChallengeIndex) {
        case 0:
            x = gChallengePhase;
            switch (x) {
            case 0:
                if (IsProgressPointCrossed(0xDC)) {
                    gChallengePhase = 1;
                    ResetChallengeTimer();
                }
                break;
            case 1:
                if (IsProgressPointCrossed(0x15E)) {
                    /* IsChallengeTimeWithin: this file's old prototype returns u8; the matched definition returns u32 */
                    if (((u8 (*)(u32))IsChallengeTimeWithin)(0x2328))
                        gChallengeResult = x;
                    EndRace();
                    gChallengePhase = 0;
                }
                DrawChallengeTimer();
                break;
            }
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            break;
        case 4:
            x = gChallengePhase;
            switch (x) {
            case 0:
                if (IsProgressPointCrossed(0x55)) {
                    gChallengePhase = 1;
                    ResetChallengeTimer();
                }
                break;
            case 1:
                if (IsProgressPointCrossed(0x96)) {
                    if (((u8 (*)(u32))IsChallengeTimeWithin)(0xFA0))
                        gChallengeResult = x;
                    EndRace();
                    gChallengePhase = 0;
                }
                DrawChallengeTimer();
                break;
            }
            break;
        case 9:
            v = GetAverageWaypointSpeed();
            if (v < 0)
                v = 0;
            if (v > (*(s32 *)&gChallengeBestValue))
                (*(s32 *)&gChallengeBestValue) = v;
            if ((*(s32 *)&gChallengeBestValue) > 0x76) {
                gChallengeResult = 1;
                EndRace();
            }
            if ((*(s32 *)&gChallengeBestValue) > 0x79) {
                if (gChallengeEndDelay & 8)
                    DrawChallengeSpeed((*(s32 *)&gChallengeBestValue));
                else
                    ClearChallengeSpeed();
                gChallengeEndDelay++;
                if (gChallengeEndDelay > 0x40)
                    EndRace();
            } else if ((*(s32 *)&gChallengeBestValue) != 0) {
                DrawChallengeSpeed(v);
            }
            break;
        }
        gUnk_0202CB14 = gCars[0].progress & 0xFFFF;
    }
}
