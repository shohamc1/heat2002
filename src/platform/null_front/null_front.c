// Null front end: the SDL-free hosted main loop, used
// when the port is built with ASAN=1 on macOS. Homebrew's sdl2 there is
// sdl2-compat, whose dylib initializer dlopens SDL3; under the AddressSanizer
// runtime that dlopen fails and the layer pops a modal NSAlert (dllinit ->
// error_dialog) that no automated run ever dismisses -- plain and
// UBSan-only builds of the same SDL program run fine, so the sanitizer
// build links this front end instead of src/platform/pret_sdl/sdl2.c and
// keeps the window-less soak running.
//
// It provides what the rest of the port references (VBlankIntrWait,
// Platform_QueueAudio) plus main(). The frame body matches sdl2.c's
// headless path with one addition: gpsp_draw_frame still renders every
// frame into gameImage, so the soak exercises the software renderer even
// without a window. Input comes from the soak harness
// (include/platform/shared/soak.h), the only input source a null front
// end has. Nothing here is compiled into the GBA build.

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "functions.h"
#include "variables.h"
#include "platform/platform.h"
#include "platform/shared/dma.h"
#include "platform/shared/input.h"
#include "platform/shared/soak.h"
#include "platform/shared/video/gpsp_renderer.h"

ALIGNED(256) u16 gameImage[DISPLAY_WIDTH * DISPLAY_HEIGHT];

void DoSoftReset(void) {};

void VBlankIntrWait(void)
{
#define HANDLE_VBLANK_INTRS()                                                    \
    ({                                                                           \
        REG_DISPSTAT |= INTR_FLAG_VBLANK;                                        \
        RunDMAs(DMA_VBLANK);                                                     \
        if (REG_DISPSTAT & DISPSTAT_VBLANK_INTR)                                 \
            gIntrTable[INTR_INDEX_VBLANK]();                                     \
        REG_DISPSTAT &= ~INTR_FLAG_VBLANK;                                       \
    })

    REG_KEYINPUT = KEYS_MASK ^ Soak_Advance();
    gpsp_draw_frame(gameImage);
    REG_VCOUNT = DISPLAY_HEIGHT + 1;
    HANDLE_VBLANK_INTRS();

#undef HANDLE_VBLANK_INTRS
}

/* The SDL front end queues the mixer's frame into the audio device; with
   no device there is nothing to do (m4aSoundVSync still mixes into its
   own buffer, so the mixer code stays soaked). */
void Platform_QueueAudio(const s16 *data, u32 bytesCount)
{
    (void)data;
    (void)bytesCount;
}

void Platform_ReportSaveError(const char *message) { fprintf(stderr, "error: %s\n", message); }

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    REG_KEYINPUT = 0x3FF;

    // The save file, as sdl2.c's main(): load the EEPROM image before the
    // game can reach it, and create the file on the first run so it exists
    // in its erased state, as a blank cartridge would read.
    if (!ReadSaveFile())
        StoreSaveFile();

    AgbMain();
    return 1;
}
