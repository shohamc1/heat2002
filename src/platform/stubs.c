// Link completion for the hosted build: the symbols the port's objects
// reference that the GBA link satisfied elsewhere. Each group names the
// step that replaces it.
//
// Nothing here is compiled into the GBA build.
//
// The MP2K sound driver's assembly half (lib/m4a_1.s) is NOT stubbed
// anymore: step 6 vendored it as C under src/platform/shared/audio/
// (m4a_sound_mixer.c, the mixer and event handlers, plus cgb_audio.c,
// the software PSG the hosted CgbSound drives).

#include "config.h"
#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/m4a_internal.h"
#include "functions.h"
#include "variables.h"

// ---------------------------------------------------------------------------
// libgcc division helpers. On the GBA, ldscript.ld aliases these
// addresses to __divsi3 and __modsi3; the game calls them by name.
// ---------------------------------------------------------------------------

// The GBA's division helpers (tools/agbcc/libgcc/lib1thumb.asm __divsi3,
// __udivsi3, __modsi3, __umodsi3) branch to Ldiv0 on a zero divisor,
// which calls __div0 and returns 0 ("about as wrong as it could be").
// FinishAllCars divides by a zero refDistance while MainMenuLoop
// initialises (lap 0 x lap length), so the port's helpers answer 0 the
// same way instead of trapping the host's division.

s32 sub_08017230(s32 a, s32 b)
{
    if (b == 0)
        return 0;
    return a / b;
}

s32 sub_080172C8(s32 a, s32 b)
{
    if (b == 0)
        return 0;
    return a % b;
}

s32 umul3232H32(s32 a, s32 b)
{
    return (s32)((((uint64_t)(u32)a) * ((uint64_t)(u32)b)) >> 32);
}

// ---------------------------------------------------------------------------
// Functions whose only definitions live in src/dead/ (nothing in the
// ROM reaches them there, but the port's live callers do). The bodies
// are the dead files' logic; the files themselves stay out of the port.
// ---------------------------------------------------------------------------

/* sub_08001134: MPlayContinue (src/dead/sub_08001130.c). */
void sub_08001134(struct MusicPlayerInfo *mplayInfo)
{
    u32 ident = mplayInfo->ident;

    if (ident == ID_NUMBER) {
        mplayInfo->status &= ~MUSICPLAYER_STATUS_PAUSE;
        mplayInfo->ident = ident;
    }
}

/* LoadFadePalette (src/dead/LoadFadePalette.c): unpack 256 colours into
   the fade state gPaletteFadeColors keeps as 16.16 channel words. The dead
   file walks pointers with (u32) casts; the port's pointers are wider,
   so this is the same walk by index. */
void LoadFadePalette(u16 *p)
{
    u32 *dst = gPaletteFadeColors;
    int i;

    /* p[i], not p++ and p[i]: the old loop advanced p twice per colour
       (once in the increment, once in the index) and so read only every
       other one. */
    for (i = 0; i < 0x100; i++) {
        u32 v = p[i];

        dst[0] = (v & 0x1F) << 16;
        dst[1] = ((v >> 5) & 0x1F) << 16;
        dst[2] = ((v >> 10) & 0x1F) << 16;
        dst += 3;
    }
}

// ---------------------------------------------------------------------------
// Nintendo's MultiBoot library (lib/multiboot.c), which the GBA link
// places by address and the port does not compile. The game's single-pak
// path calls it through the luvdis names ldscript.ld aliases them to;
// under PORTABLE that path fails closed before any call (step 8,
// SendMultibootIsland in src/link/multiboot.c), so these stay inert.
//
// The EEPROM library's luvdis names (sub_08016E38 and siblings) used to
// be stubbed here; step 7 replaced them with the file-backed store in
// src/platform/shared/save.c.
// ---------------------------------------------------------------------------

void sub_0800EA64(void *a1)
{
    (void)a1;
}

u32 sub_0800EAA0(void *a1)
{
    (void)a1;
    return 0;
}

void sub_0800EEFC(u8 *a1, const u8 *a2, s32 a3, u32 a4, u32 a5)
{
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
}

u32 sub_0800EFC0(u8 *ptr)
{
    (void)ptr;
    return 0;
}

// ---------------------------------------------------------------------------
// ROM addresses the link scripts define and the port has no ROM for.
// Zero keeps every "is this the retail cart / is the module loaded"
// check the link and serial code makes answered the same way a missing
// link partner answers it. Step 8's fail-closed SendMultibootIsland
// (src/link/multiboot.c) leaves every reader of these -- the ROM-header
// check, the high-module chunk walk, the island-length arithmetic --
// below an unconditional return, so nothing dereferences them; the
// arrays keep their ROM-range sizes only so the chunk table's pointers
// (src/data/link_text.c) stay plain address arithmetic.
// ---------------------------------------------------------------------------

/* The cartridge header's magic byte and game code, at 0x080000A0 and
   0x080000AC on the GBA. */
const u8 RomHeaderMagic = 0;
const u32 RomHeaderGameCode = 0;

/* The EWRAM images' load addresses (ldscript.ld):
   gHighModuleRom = LOADADDR(.high_module), gUnk_08363EE8 =
   LOADADDR(.island). ROM-range sized so the chunk table's pointers into
   gHighModuleRom stay plain address arithmetic; nothing reads either
   array under PORTABLE (the single-pak path returns before the chunk
   walk and the island-length subtraction, step 8). ALIGNED sets the
   alignment ld64 would otherwise derive from the size, which exceeds
   what a segment allows. */
ALIGNED(4) const u8 gHighModuleRom[0x08363EE8 - 0x08339780];
ALIGNED(4) u8 gUnk_08363EE8[0x08364AC8 - 0x08363EE8];
