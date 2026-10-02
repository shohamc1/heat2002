#ifndef GUARD_PLATFORM_PLATFORM_H
#define GUARD_PLATFORM_PLATFORM_H

// After sa2's include/platform/platform.h. The platform API the hosted
// build offers beyond the gba/ headers.

#include "config.h"
#include "global.h"

// The GBA's refresh rate (59.7275 Hz, not 60). The front end paces
// frames at it, and the mixer produces a fixed number of samples per
// frame, so the audio device runs at the rate those two imply
// (804 * 59.7275 = 48,021 Hz; SDL resamples to the hardware's rate).
// Production then matches playback, so the queue neither starves nor
// grows. A fixed per-frame count keeps the mixer's ring buffer and
// reverb, which index earlier frames by fixed offsets, intact.
#define PLATFORM_FRAME_RATE 59.7275
#define PLATFORM_AUDIO_SAMPLES_PER_FRAME 804
#define PLATFORM_AUDIO_RATE ((int)(PLATFORM_AUDIO_SAMPLES_PER_FRAME * PLATFORM_FRAME_RATE + 0.5))

extern void Platform_QueueAudio(const s16 *data, u32 numBytes);

// The file-backed EEPROM (step 7, src/platform/shared/save.c): the save
// image the port loads in main() before AgbMain and writes back after
// every program. FALSE means no file (or a short one); the caller then
// stores the erased image ReadSaveFile left in the buffer, so the file
// exists from the first run on.
bool8 ReadSaveFile(void);
bool8 StoreSaveFile(void);

// Each front end's way to tell the player a save write failed. The game
// itself can't: like the cartridge, it ignores the EEPROM verify result
// and shows "SAVE OK" regardless.
void Platform_ReportSaveError(const char *message);

#endif // GUARD_PLATFORM_PLATFORM_H
