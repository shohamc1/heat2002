#ifndef CGB_AUDIO_H
#define CGB_AUDIO_H

// Software PSG, after sa2's include/platform/shared/audio/cgb_audio.h
// (issue 5 step 6). The hosted build has no sound hardware, so the CGB
// half of the driver keeps working by driving this emulator through the
// same REG_NR* registers the GBA code writes: src/sound/cgb_sound.c's
// PORTABLE hooks (cgb_set_sweep/envelope/length/wavram, cgb_trigger_note)
// feed it, and cgb_audio_generate renders one frame of the four channels
// per SoundMain into the buffer m4aSoundVSync mixes over the direct
// sound half.

#include "gba/m4a_internal.h"

struct AudioCGB {
    u16 ch1Freq;
    u8 ch1SweepCounter;
    u8 ch1SweepCounterI;
    bool8 ch1SweepDir;
    u8 ch1SweepShift;
    u8 Vol[4];
    u8 VolI[4];
    u16 Len[4]; /* the hardware length counter: up to 64, 256 on the wave channel */
    bool8 LenOn[4];
    u8 EnvCounter[4];
    u8 EnvCounterI[4];
    bool8 EnvDir[4];
    bool8 DAC[4];
    fixed8_24 WAVRAM[32];
    u16 ch4LFSR[2];
    fixed8_24 outBuffer[PCM_DMA_BUF_SIZE * 2];
};

void cgb_audio_init(u32 rate);
void cgb_set_sweep(u8 sweep);
void cgb_set_wavram(void);
void cgb_toggle_length(u8 channel, bool8 state);
void cgb_set_length(u8 channel, u8 length);
void cgb_set_envelope(u8 channel, u8 envelope);
void cgb_trigger_note(u8 channel);
void cgb_audio_generate(u16 samplesPerFrame);
fixed8_24 *cgb_get_buffer(void);

#endif
