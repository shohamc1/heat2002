#include "global.h"

extern const u8 gText_GameType[];

u32 sub_08012384(u32 r0, u32 r1, u32 r2);

u8 sub_08014584(void)
{
    return sub_08012384((u32)gText_GameType, 0x54, 0x4C);
}

extern const u8 gText_MpTeamSelect[];


u8 sub_0801459C(void)
{
    return sub_08012384((u32)gText_MpTeamSelect, 0x40, 0x4C);
}

extern const u8 gText_MpDriverSelect[];


u8 sub_080145B4(void)
{
    return sub_08012384((u32)gText_MpDriverSelect, 0x38, 0x4C);
}

extern const u8 gText_MpTrackSelect[];


u8 sub_080145CC(void)
{
    return sub_08012384((u32)gText_MpTrackSelect, 0x3C, 0x4C);
}

extern const u8 gText_MpOkWaitingScreen[];


u8 sub_080145E4(void)
{
    return sub_08012384((u32)gText_MpOkWaitingScreen, 0x20, 0x4C);
}

extern const u8 gText_RaceSummary[];


u8 sub_080145FC(void)
{
    return sub_08012384((u32)gText_RaceSummary, 0x48, 0x4C);
}
