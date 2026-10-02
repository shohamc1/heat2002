#include "global.h"
#include "gba/defines.h"
#include "variables.h"

/* This file owns the multiboot island's one contiguous IWRAM run
   0x03000000-0x03000C18 (issue 5 step 3, run rule; ISLAND_DATA): the
   0x800-byte interrupt dispatcher buffer IslandAgbMain copies
   sub_083640B0 into, the 0x400-byte OAM staging buffer behind it, and
   the 0x18-byte comm register block the island's serial IRQ handler
   drives (struct CommRegs, structs.h). The island runs
   on the other GBA, so its IWRAM is its own; ldscript.ld's .island_data
   places the section at 0x03000000 as NOLOAD. */

ISLAND_DATA u8 gIsland_IntrMainBuffer[0x800] = {0};
ISLAND_DATA u32 gIsland_OamBuffer[0x100] = {0};
ISLAND_DATA struct CommRegs gIsland_SioTransfer = {0};
