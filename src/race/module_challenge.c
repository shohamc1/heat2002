#include "global.h"
#include "car.h"
#include "variables.h"

#include "functions.h"
extern u8 gModule_Timer[];
extern u8 gModule_MPH[];
extern const u8 gModule_BlankRow8[];
extern const u8 gModule_BlankRow12_2[];
extern u8 gUnk_0203DD08;
extern s32 gUnk_0203DDF8;
extern u8 gUnk_0203DD30;

u8 ModuleIsProgressPointCrossed(s32 point)
{
    if ((*(s32 *)&gUnk_0203DD34) > point)
        return 0;
    if ((gModule_Cars[0].progress & 0xFFFF) < (u32)point)
        return 0;
    return 1;
}

u32 ModuleIsChallengeTimeWithin(s32 limitMs)
{
    if ((*(s32 *)&gUnk_0203DCFC) * 1000 + (*(s32 *)&gUnk_0203D500) <= limitMs)
        return 1;
    return 0;
}

void ModuleDrawChallengeTimer(void)
{
    u16 *dest;
    u32 *sec;
    u32 *ms;
    u16 *tilemap;

    tilemap = *(u16 **)&gModule_TextLayerMapPtr;
    dest = tilemap + 0x128;
    ModuleDrawText(gModule_Timer, 8, 8);
    /* ModuleDrawBigDigit: this file's old prototype took
       (u16 *, u32); the matched definition narrows idx
       to u8; call through the old one. */
    ((void (*)(u16 *, u32))ModuleDrawBigDigit)(dest, 0);
    dest = tilemap + 0x12A;
    ((void (*)(u16 *, u32))ModuleDrawBigDigit)(dest, gUnk_0203DD04);
    dest = tilemap + 0x12D;
    sec = &gUnk_0203DCFC;
    ((void (*)(u16 *, u32))ModuleDrawBigDigit)(dest, sub_08344BB8(*sec, 0xA));
    dest = tilemap + 0x12F;
    ((void (*)(u16 *, u32))ModuleDrawBigDigit)(dest, sub_08344C50(*sec, 0xA));
    dest = tilemap + 0x132;
    ms = &gUnk_0203D500;
    sec = ms;
    ((void (*)(u16 *, u32))ModuleDrawBigDigit)(dest, sub_08344C50(sub_08344BB8(*sec, 0x64), 0xA));
    dest = tilemap + 0x134;
    ((void (*)(u16 *, u32))ModuleDrawBigDigit)(dest, sub_08344C50(sub_08344BB8(*sec, 0xA), 0xA));
}

void ModuleDrawChallengeSpeed(u32 mph)
{
    u16 *tilemap;
    u16 *dest;

    tilemap = (u16 *)*(u32 *)&gModule_TextLayerMapPtr;
    dest = tilemap + 0x1CA;
    /* ModuleDrawBigDigit: this file's old prototype took
       (u16 *, u32); the matched definition narrows idx
       to u8; call through the old one. */
    ((void (*)(u16 *, u32))ModuleDrawBigDigit)(dest, sub_08344C50(sub_08344BB8(mph, 0x64), 0x0A));
    dest = tilemap + 0x1CC;
    ((void (*)(u16 *, u32))ModuleDrawBigDigit)(dest, sub_08344C50(sub_08344BB8(mph, 0x0A), 0x0A));
    dest = tilemap + 0x1CE;
    ((void (*)(u16 *, u32))ModuleDrawBigDigit)(dest, sub_08344C50(mph, 0x0A));
    ModuleDrawText(gModule_MPH, 0x10, 0x0F);
}

void ModuleClearChallengeSpeed(void)
{
    ModuleDrawText(gModule_BlankRow8, 10, 14);
    ModuleDrawText(gModule_BlankRow12_2, 10, 15);
}

void ModuleUpdateChallengeTimer(void)
{
    u32 val = gUnk_0203D500 + 40;

    gUnk_0203D500 = val;
    if ((s32)val <= 999)
        return;
    gUnk_0203D500 -= 1000;
    val = ++(*(s32 *)&gUnk_0203DCFC);
    if ((s32)val > 59) {
        (*(s32 *)&gUnk_0203DCFC) = val - 60;
        gUnk_0203DD04++;
    }
}

void ModuleResetChallengeTimer(void)
{
    gUnk_0203D500 = 0;
    gUnk_0203DCFC = 0;
    gUnk_0203DD04 = 0;
}

u32 ModuleGetAverageWaypointSpeed(void)
{
    u32 sum = 0;
    u8 i = 0;
    u32 sample;
    u32 result;

    do {
        sample = gUnk_0203DD60[i];
        sum += sample;
        if (sample == 0) {
            result = 0;
            goto end;
        }
        i++;
    } while (i != 0x0D);
    result = sub_08344BB8(sum, 0x0D) - 1;
end:
    return result;
}

void ModuleClearWaypointSpeedSamples(void)
{
    u32 i;
    for (i = 0; i != 13; i = (u8)(i + 1))
        gUnk_0203DD60[i] = 0;
}

void ModuleUpdateChallenge(void)
{
    u8 phase;
    s32 speed;

    if (gModule_GameMode[0] == 0x10) {
        ModuleUpdateChallengeTimer();
        switch (gUnk_0203DFB0) {
            case 0:
                phase = gUnk_0203DD08;
                switch (phase) {
                    case 0:
                        if (ModuleIsProgressPointCrossed(0xDC)) {
                            gUnk_0203DD08 = 1;
                            ModuleResetChallengeTimer();
                        }
                        break;
                    case 1:
                        if (ModuleIsProgressPointCrossed(0x15E)) {
                            /* ModuleIsChallengeTimeWithin: this file's old prototype returns u8;
                               the matched definition returns u32 */
                            if (((u8 (*)(u32))ModuleIsChallengeTimeWithin)(0x2328))
                                gUnk_0203E104 = phase;
                            ModuleEndRace();
                            gUnk_0203DD08 = 0;
                        }
                        ModuleDrawChallengeTimer();
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
                phase = gUnk_0203DD08;
                switch (phase) {
                    case 0:
                        if (ModuleIsProgressPointCrossed(0x55)) {
                            gUnk_0203DD08 = 1;
                            ModuleResetChallengeTimer();
                        }
                        break;
                    case 1:
                        if (ModuleIsProgressPointCrossed(0x96)) {
                            if (((u8 (*)(u32))ModuleIsChallengeTimeWithin)(0xFA0))
                                gUnk_0203E104 = phase;
                            ModuleEndRace();
                            gUnk_0203DD08 = 0;
                        }
                        ModuleDrawChallengeTimer();
                        break;
                }
                break;
            case 9:
                speed = ModuleGetAverageWaypointSpeed();
                if (speed < 0)
                    speed = 0;
                if (speed > gUnk_0203DDF8)
                    gUnk_0203DDF8 = speed;
                if (gUnk_0203DDF8 > 0x76) {
                    gUnk_0203E104 = 1;
                    ModuleEndRace();
                }
                if (gUnk_0203DDF8 > 0x79) {
                    if (gUnk_0203DD30 & 8)
                        ModuleDrawChallengeSpeed(gUnk_0203DDF8);
                    else
                        ModuleClearChallengeSpeed();
                    gUnk_0203DD30++;
                    if (gUnk_0203DD30 > 0x40)
                        ModuleEndRace();
                } else if (gUnk_0203DDF8 != 0) {
                    ModuleDrawChallengeSpeed(speed);
                }
                break;
        }
        gUnk_0203DD34 = gModule_Cars[0].progress & 0xFFFF;
    }
}
