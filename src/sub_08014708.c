#include "global.h"
#include "functions.h"
#include "data.h"
#include "variables.h"

extern const u8 *const gChallengeNameTexts[];
extern u8 gText_ChallengeStatusBeat[];
extern u8 gText_ChallengeStatusNA[];
extern u8 gText_ChallengeStatusOpen[];
extern const u8 *const gChallengeGoalTexts[];

void sub_08014708(u8 a, u8 b)
{
    u8 y;
    u8 i;
    u8 base;
    s8 sv;

    sub_08006734(gUnk_083FDE18[0]);
    GetString(a + 0xAE);
    ((void (*)(void))DrawBigText)();
    base = (u8)(a * 4);
    y = 3;
    i = 0;
    do {
        DrawText(gChallengeNameTexts[base + i], 0, y, i == (b & 3));
        if (gChallengeStatus[base + i] == 1) {
            u8 *s = gText_ChallengeStatusBeat;
            DrawText(s, 0x16, y, i == (b & 3));
        }
        if (gChallengeStatus[base + i] == 2) {
            u8 *s = gText_ChallengeStatusBeat;
            DrawText(s, 0x16, y, i == (b & 3));
        }
        sv = ((s8 *)gChallengeStatus)[base + i];
        if (sv == 3) {
            u8 *s = gText_ChallengeStatusBeat;
            DrawText(s, 0x16, y, i == (sv & b));
        }
        if (((s8 *)gChallengeStatus)[base + i] == -1) {
            u8 *s = gText_ChallengeStatusNA;
            DrawText(s, 0x16, y, i == (b & 3));
        }
        if ((s8)gChallengeStatus[base + i] == 0) {
            u8 *s = gText_ChallengeStatusOpen;
            DrawText(s, 0x16, y, i == (b & 3));
        }
        y++;
        i++;
    } while (i != 4);
    y = 8;
    base = (u8)(b * 5) * 2;
    i = base;
    while (i != base + 10) {
        DrawText(gChallengeGoalTexts[i], 0, y, 1);
        y++;
        i++;
    }
}
