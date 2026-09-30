#include "global.h"
#include "sin_table.h"

/* no variables.h: it declares gModule_SinTable without const, which its
   readers' bytes need; this file needs nothing else from it. */

/* High module (link slave) m4a data (ROM 0x08344E68-0x08345178, EWRAM
 * 0x0200C3E8-0x0200C668). gModule_SinTable is the game's sine lookup,
 * byte-identical to the main program's gSinTable (src/data/rom_0801CD08.c,
 * which says what it is for): the ROM holds it twice, once per GBA.
 * sin_table.h shares the initialisers, so one edit changes both copies.
 * The car physics reads it by heading (module_tire_forces.c,
 * module_update.c, module_collide.c, module_contact.c). */

const s16 gModule_SinTable[320] = SIN_TABLE;

/* The m4a command dispatch table, the template MPlayJumpTableCopy copies
 * into gModule_MPlayJumpTable at init: one handler per music-player
 * command byte (lib/m4a_1.s's high copy reads it through the Makefile's
 * gMPlayJumpTableTemplate rename). The twin of the low copy's
 * gMPlayJumpTableTemplate in data/rom_0801CF88.s, which names what each
 * slot is; the sub_ handlers here are the high copy's ply_* and its
 * SampleFreqSet/TrackStop/RealClearChain/SoundMainBTM. */
void sub_08339FE8(void);
void sub_0833A058(void);
void sub_0833A078(void);
void sub_0833A094(void);
void sub_0833A0A8(void);
void sub_0833A0D8(void);
void sub_0833A0E4(void);
void sub_0833A0F8(void);
void sub_0833A10C(void);
void sub_0833A13C(void);
void sub_0833A150(void);
void sub_0833A164(void);
void sub_0833A178(void);
void sub_0833A764(void);
void sub_0833A18C(void);
void sub_0833A778(void);
void sub_0833A198(void);
void sub_0833A1B0(void);
void sub_0833A1C4(void);
void sub_0833A6FC(void);
void ModuleSampleFreqSet(void);
void sub_0833A488(void);
void ModuleFadeOutBody(void);
void ModuleTrkVolPitSet(void);
void sub_08339FC8(void);
void sub_08339FB0(void);

const u32 gUnk_0200C668[36] = {
    (u32)sub_08339FE8, (u32)sub_0833A058, (u32)sub_0833A078, (u32)sub_0833A094,
    (u32)sub_0833A0A8, (u32)sub_08339FE8, (u32)sub_08339FE8, (u32)sub_08339FE8,
    (u32)sub_08339FE8, (u32)sub_0833A0D8, (u32)sub_0833A0E4, (u32)sub_0833A0F8,
    (u32)sub_0833A10C, (u32)sub_0833A13C, (u32)sub_0833A150, (u32)sub_0833A164,
    (u32)sub_0833A178, (u32)sub_0833A764, (u32)sub_0833A18C, (u32)sub_0833A778,
    (u32)sub_0833A198, (u32)sub_08339FE8, (u32)sub_08339FE8, (u32)sub_0833A1B0,
    (u32)sub_08339FE8, (u32)sub_08339FE8, (u32)sub_08339FE8, (u32)sub_0833A1C4,
    (u32)sub_08339FE8, (u32)sub_0833A6FC, (u32)ModuleSampleFreqSet, (u32)sub_0833A488,
    (u32)ModuleFadeOutBody, (u32)ModuleTrkVolPitSet, (u32)sub_08339FC8, (u32)sub_08339FB0
};
