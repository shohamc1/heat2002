#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H

// Shared RAM globals that several files declare and no module owns yet,
// sorted by address. Stage 1 catch-all of docs/extern-headers-plan.md;
// the addresses stay in symbols.ld.

// Main program

extern s32 gUnk_02000460;
extern s32 gUnk_02000464;
extern s32 gUnk_02000468;
extern s32 gUnk_0200046C;
extern s32 gUnk_02000470;
extern s32 gUnk_02000474;
extern s32 gUnk_02000478;
extern s32 gUnk_0200047C;
extern s32 gUnk_02000480;
extern s32 gUnk_02000484;
extern s32 gUnk_02000488;
extern u32 gUnk_02000580[];
extern u32 gUnk_02000590[];
extern u16 gKeysPressed; /* 0x020005CC */
extern u16 gUnk_02000DD0; /* 0x02000DD0 */
extern u8 gUnk_02001F20[]; /* 0x02001F20 */
extern u8 gUnk_02001FA0[]; /* 0x02001FA0 */
extern u8 gUnk_02001FE0[]; /* 0x02001FE0 */
extern u8 gUnk_02002030[]; /* 0x02002030 */
extern u8 gNumCars[]; /* 0x02002090 */
extern u8 gUnk_02002098; /* 0x02002098 */
extern u16 gUnk_020020A0[];
extern u8 gUnk_020020A8; /* 0x020020A8 */
extern u8 gNumLinkPlayers[]; /* 0x020020AC */
extern u8 gUnk_020020B4;
extern u8 gUnk_020020BC;
extern u8 gUnk_020020C0; /* 0x020020C0 */
extern u8 gUnk_020020C4; /* 0x020020C4 */
extern u8 gTrackId; /* 0x020020CC */
extern u32 gUnk_020020D4; /* 0x020020D4 */
extern u8 gIsLinkRace; /* 0x020020DC */
extern u8 gIsDemo; /* 0x020020E0 */
extern u8 gUnk_020020EC; /* 0x020020EC */
extern u8 gUnk_020020F0; /* 0x020020F0 */
extern u16 gUnk_02002124;
extern u8 gUnk_0200215C[]; /* 0x0200215C */
extern u16 gUnk_0200216C;
extern u16 gUnk_02002170; /* 0x02002170 */
extern u8 gNumLaps;
extern u8 gUnk_020021BC; /* 0x020021BC */
extern u8 gUnk_020021C4; /* 0x020021C4 */
extern u8 gUnk_020021E0; /* 0x020021E0 */
extern u32 gUnk_02002200[];
extern u8 gUnk_02002218;
extern u32 gUnk_0200BC2C;
extern u32 gUnk_0200BC30;
extern u16 gUnk_0200BC34;
extern u32 gUnk_0200BC48;
extern u32 gUnk_0200BC4C;
extern s16 gUnk_0200C3E8[];
extern u8 gUnk_0200D07C[];
extern u8 gUnk_0200D118[];
extern u16 gUnk_0201F590[];
extern u16 gUnk_0201F9D0[];
extern u16 gUnk_02021D04[];
extern u16 gUnk_02022254[];
extern u32 gUnk_02022DE0;
extern u16 gUnk_02022DE4;
extern u32 gUnk_02022DE8;
extern u32 gUnk_02022DEC[];
extern u32 gUnk_02022DF8;
extern u8 gUnk_02022E14; /* 0x02022E14 */
extern u16 gUnk_02022E18;
extern u8 gUnk_02024824;
extern u32 gUnk_02024828;
extern u32 gUnk_02024C30;
extern u8 gUnk_02024C40[];
extern u8 gUnk_02025150;
extern u8 gUnk_02025154;
extern u16 gUnk_02025160[];
extern u16 gUnk_020251F0;
extern u16 gUnk_020251FC[];
extern u16 gUnk_02025200[];
extern u16 gUnk_02025218[];
extern u16 gUnk_02025220; /* 0x02025220 */
extern u16 gUnk_02025224; /* 0x02025224 */
extern u16 gUnk_0202522C;
extern u8 *gUnk_02025230;
extern u8 gUnk_02025238;
extern u8 gUnk_0202523C;
extern u8 gUnk_02025240;
extern u8 gUnk_02025244;
extern u8 gUnk_02025248; /* 0x02025248 */
extern u16 gUnk_02025258;
extern u16 gUnk_02025260; /* 0x02025260 */
extern u8 gUnk_02025370;
extern u16 gUnk_02025380[];
extern u16 gUnk_02025398;
extern u8 gUnk_0202539C;
extern u16 gUnk_020253A0[];
extern u32 gUnk_020253B8;
extern u16 gUnk_020253BC;
extern u8 gUnk_020253C4;
extern u8 gUnk_020253C8;
extern u16 gUnk_020253CC[];
extern u8 gUnk_020253D4;
extern u8 gUnk_020253E0[];
extern u8 gUnk_02025ED0[];
extern u32 *gUnk_02026E1C[];
extern u8 gUnk_0202713E[];
extern u8 gUnk_0202714A[];
extern u8 gUnk_02027154[];
extern u32 *gUnk_0202772C[];
extern u32 gUnk_0202A3F0[];
extern u8 gUnk_0202A514;
extern s32 gUnk_0202A518;
extern u8 gUnk_0202A51C;
extern s32 gUnk_0202A528;
extern u8 gUnk_0202A53C;
extern s32 gUnk_0202A54C;
extern u8 gUnk_0202CAD0;
extern u8 gUnk_0202CAD4;
extern u8 gUnk_0202CAE8;
extern u8 gUnk_0202CAF0;
extern s32 gUnk_0202CB0C;
extern u8 gUnk_0202CB18;
extern u32 gUnk_0202CB40[];
extern u8 gUnk_0202CBC0[];
extern u8 gUnk_0202CBC4;
extern u8 gUnk_0202CBC8[];
extern u8 gUnk_0202CBD0;
extern s32 gUnk_0202CBD4;
extern u8 gUnk_0202CBDC;
extern u8 gUnk_0202CBE0;
extern s32 gUnk_0202CBF0;
extern u32 gUnk_0202CC00[];
extern u32 gUnk_0202CC04; /* 0x0202CC04 */
extern u32 gUnk_0202CC08[];
extern u8 gUnk_0202CC10[]; /* 0x0202CC10 */
extern u32 gUnk_0202CC1C[];
extern u8 gUnk_0202CC28;
extern u8 gUnk_0202CC2C;
extern s32 gUnk_0202CD24;
extern u8 gUnk_0202CDA8[];
extern s16 gUnk_0202E930;
extern s16 gUnk_0202E948;
extern u8 gUnk_0202ED70;
extern u16 gUnk_0202ED78[];
extern u8 gUnk_0202ED80[];
extern u32 gUnk_0202ED84;
extern u8 gUnk_0202EDB0;
extern u8 gUnk_0202EDC8[];
extern u8 gUnk_0202EDD0;
extern u8 gUnk_0202EDD8;
extern u8 gUnk_0202EEB0;
extern u8 gUnk_0202EEB4;
extern u8 gUnk_0202EEC0[];
extern u8 gUnk_0202EEC8;
extern u8 gUnk_0202EED0;
extern u8 gUnk_0202EED8;
extern u8 gUnk_0202EEE4;
extern u8 gUnk_0202EEF4;
extern u8 gOptions[]; /* 0x0202EF00 */
extern u8 gUnk_0202EF08[];
extern u8 gUnk_0202EF10;
extern u8 gUnk_0202EF20[];
extern u8 gUnk_0202EF78[];
extern u8 gUnk_0202EF80[];
extern u8 gLinkPlayerId[]; /* 0x0202EF90 */
extern u8 gUnk_0202EFB0;
extern u8 gUnk_0202F024;
extern u8 gUnk_0202F030;
extern u8 gUnk_0202F034;
extern u16 gUnk_0202F040[];
extern u8 gUnk_0202F050[];
extern u16 gUnk_0202F170[];
extern u8 gUnk_0202F1B8[];
extern u16 gUnk_03007FF8;
extern u32 gUnk_03007FFC;

// High module (links at its EWRAM run address)

extern s32 gUnk_020375A0;
extern s32 gUnk_020375A4;
extern s32 gUnk_020375A8;
extern s32 gUnk_020375AC;
extern s32 gUnk_020375B0;
extern s32 gUnk_020375B4;
extern s32 gUnk_020375B8;
extern s32 gUnk_020375BC;
extern s32 gUnk_020375C0;
extern s32 gUnk_020375C4;
extern s32 gUnk_020375C8;
extern u32 gUnk_020375D0;
extern u32 gUnk_020375E0[];
extern u16 gUnk_02037618; /* 0x02037618 */
extern u16 gUnk_0203761C; /* 0x0203761C */
extern u16 gUnk_02037E20; /* 0x02037E20 */
extern u8 gUnk_020390A0[];
extern u16 gUnk_020390B0[];
extern u8 gUnk_020390B8;
extern u8 gUnk_020390BC[];
extern u8 gUnk_020390C4;
extern u8 gUnk_020390CC;
extern u8 gUnk_020390D4;
extern u8 gUnk_020390DC;
extern u32 gUnk_020390E4; /* 0x020390E4 */
extern u8 gUnk_020390EC;
extern u8 gUnk_020390F0[];
extern u8 gUnk_020390FC;
extern u8 gUnk_02039100;
extern u16 gUnk_02039134;
extern u8 gUnk_0203916C[];
extern u16 gUnk_0203917C;
extern u16 gUnk_02039180;
extern u8 gUnk_02039194;
extern u8 gUnk_020391D4;
extern u8 gUnk_020391F0;
extern u32 gUnk_02039220[];
extern u8 gUnk_02039234[];
extern u32 gUnk_02039240;
extern u32 gUnk_02039244;
extern u16 gUnk_02039248;
extern u32 gUnk_0203925C;
extern u32 gUnk_02039260;
extern u32 gUnk_02039290;
extern u16 gUnk_02039294;
extern u32 gUnk_02039298;
extern u16 gUnk_020392A4;
extern u32 gUnk_020392A8;
extern u8 gUnk_020392C0; /* 0x020392C0 */
extern u8 gUnk_020392C4;
extern u16 gUnk_020392C8;
extern u8 gUnk_0203ACD4;
extern u32 gUnk_0203B0E0;
extern u8 gUnk_0203B600;
extern u8 gUnk_0203B604;
extern u16 gUnk_0203B610[];
extern u16 gUnk_0203B6A8[]; /* 0x0203B6A8 */
extern u16 gUnk_0203B6B0[];
extern u16 gUnk_0203B6C8[]; /* 0x0203B6C8 */
extern u16 gUnk_0203B6D0[]; /* 0x0203B6D0 */
extern u16 gUnk_0203B6D4[]; /* 0x0203B6D4 */
extern u16 gUnk_0203B6DC;
extern u8 gUnk_0203B6E8; /* 0x0203B6E8 */
extern u8 gUnk_0203B6F0; /* 0x0203B6F0 */
extern u16 gUnk_0203B6FC;
extern u16 gUnk_0203B704[]; /* 0x0203B704 */
extern u16 gUnk_0203B810[];
extern u16 gUnk_0203B828;
extern u16 gUnk_0203B830[];
extern u16 gUnk_0203B848;
extern u8 gUnk_0203B850[];
extern u16 gUnk_0203B858[]; /* 0x0203B858 */
extern u8 gUnk_0203B864;
extern u8 gUnk_0203B868[];
extern u8 gUnk_0203C340[];
extern u32 gUnk_0203C380;
extern u32 gUnk_0203D4DC;
extern u8 gUnk_0203D4E0;
extern s32 gUnk_0203D4E4;
extern u8 gUnk_0203D4E8;
extern s32 gUnk_0203D4F4;
extern s32 gUnk_0203D51C;
extern u8 gUnk_0203DCF4;
extern u32 gUnk_0203DD04;
extern u8 gUnk_0203DD10;
extern s32 gUnk_0203DD2C;
extern u8 gUnk_0203DD38;
extern u32 gUnk_0203DD60[];
extern u8 gUnk_0203DDE4;
extern u8 gUnk_0203DDE8[];
extern s32 gUnk_0203DDF4;
extern u8 gUnk_0203DDFC;
extern s32 gUnk_0203DE10;
extern u32 gUnk_0203DE20[];
extern u32 gUnk_0203DE24;
extern u32 gUnk_0203DE28[];
extern u8 gUnk_0203DE30[]; /* 0x0203DE30 */
extern u32 gUnk_0203DE3C[];
extern s32 gUnk_0203DF44;
extern u8 gUnk_0203DFB0;
extern u16 gUnk_0203DFB8[];
extern u8 gUnk_0203E004;
extern u8 gUnk_0203E0E0;
extern u8 gUnk_0203E104;
extern u8 gUnk_0203E120[];
extern u8 gUnk_0203E140[];
extern u8 gUnk_0203E1B0;
extern u8 gUnk_0203E1C0[];
extern u8 gUnk_0203E1E0[];

#endif
