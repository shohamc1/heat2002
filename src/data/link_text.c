#include "global.h"
#include "data.h"

/* Wheel names, the multiboot chunk table and link-cable warning text (0x0807C97C-0x0807CA7C). */

const u8 gText_Rearright[12] = "REARRIGHT";
const u8 gText_Rearleft[12] = "REARLEFT";
const u8 gText_Frontright[12] = "FRONTRIGHT";
const u8 gText_Frontleft[12] = "FRONTLEFT";
const u8 gText_Right[8] = "RIGHT";
const u8 gText_Left[8] = "LEFT";
const u8 gText_Front[8] = "FRONT";
const u8 gText_Back[8] = "BACK";
extern const u8 gHighModuleRom[];

// The high module's 32 KB chunks, as SendMultibootPayload sends them.
const u8 *const gHighModuleChunks[] = { gHighModuleRom,           gHighModuleRom + 0x8000,  gHighModuleRom + 0x10000,
                                        gHighModuleRom + 0x18000, gHighModuleRom + 0x20000, gHighModuleRom + 0x28000,
                                        gHighModuleRom + 0x30000 };
// Its users declare it as u32 x (SendMultibootPayload compares the ROM
// header's game code against it; "AGBJ" little-endian).
const u32 gGameCodeAgbj[2] = { 0x4A424741, 0 };
const u8 gText_BlankRow24_2[] = "                       ";
const u8 gText_DoNotRemoveGameBoy[] = "DO NOT REMOVE GAME BOY&";
const u8 gText_AdvanceGameLink[20] = "ADVANCE GAME LINK&";
const u8 gText_CableOrTurnPowerOff[] = "CABLE OR TURN POWER OFF.\000\000\000\000               ";
const u8 gText_BlankRow28_2[28] = "                          ";
