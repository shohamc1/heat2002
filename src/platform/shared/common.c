#include "config.h"
#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "variables.h"

// Hosted stand-ins for the GBA's memory blocks, after sa2's
// src/platform/shared/common.c. include/gba/defines.h declares them as
// extern arrays with the sizes and spellings game code uses; this file
// is the one definition. The I/O block is REG_BASE so every REG_ADDR_*
// in io_reg.h stays plain address arithmetic on the host too.

ALIGNED(256) u8 REG_BASE[IO_SIZE] = { 0 };
ALIGNED(256) u8 EWRAM_START[0x40000] = { 0 };
ALIGNED(256) u8 IWRAM_START[0x8000] = { 0 };
ALIGNED(256) u8 PLTT[0x400] = { 0 };
ALIGNED(256) u8 VRAM[0x18000] = { 0 };
ALIGNED(256) u8 OAM[0x400] = { 0 };

vu16 INTR_CHECK = 0;

/* The BIOS interface variables at the top of IWRAM (gba/defines.h).
   SOUND_INFO_PTR starts at gSoundInfo rather than NULL: the game calls
   m4aSoundVSyncOff (through SaveProgress, on a fresh save) before any
   m4aSoundInit, and where the GBA reads stack garbage off the IRQ stack
   and the ident check quietly fails, NULL would fault. SoundInit stores
   the real value over this soon after. */
struct SoundInfo *SOUND_INFO_PTR = &gSoundInfo;

void IntrMain(void);

IntrFunc INTR_VECTOR = IntrMain;

/* C replacement for crt0's hand-written ARM dispatcher (lib/crt0.s):
   walk REG_IE & REG_IF in the ROM's own priority order -- serial and
   timer 3 first together, then VBlank, VCount, HBlank, the four DMAs,
   keypad, game pak -- ack the winning flag in REG_IF and call the
   gIntrTable slot it belongs to. The task instructs keeping sa2's
   IntrMain shape; the slot order here follows this ROM's crt0, whose
   gIntrTable layout the game's handlers are installed for (slot 1 is
   VBlank either way, and the renderer fires VCount into slot 2 and
   HBlank into slot 3, the reverse of sa2's table). */
void IntrMain(void)
{
#define CHECK_INTR(res, input, flags)  \
    {                                  \
        res = input & flags;           \
        if (res) {                     \
            goto found_instr;          \
        }                              \
        index++;                       \
    }

    u16 flags = REG_IE & REG_IF;
    u16 flag;

    u32 index = 0;
    CHECK_INTR(flag, flags, (INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL));
    CHECK_INTR(flag, flags, INTR_FLAG_VBLANK);
    CHECK_INTR(flag, flags, INTR_FLAG_VCOUNT);
    CHECK_INTR(flag, flags, INTR_FLAG_HBLANK);
    CHECK_INTR(flag, flags, INTR_FLAG_DMA0);
    CHECK_INTR(flag, flags, INTR_FLAG_DMA1);
    CHECK_INTR(flag, flags, INTR_FLAG_DMA2);
    CHECK_INTR(flag, flags, INTR_FLAG_DMA3);
    CHECK_INTR(flag, flags, INTR_FLAG_KEYPAD);
    CHECK_INTR(flag, flags, INTR_FLAG_GAMEPAK);
    return;

found_instr:
    REG_IF = flag;

    gIntrTable[index]();

#undef CHECK_INTR
}
