#include "global.h"
#include "gba/compat.h"
#include "gba/m4a_internal.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"
#if PORTABLE
#include "platform/shared/audio/cgb_audio.h"
#endif

/* MPlayExtender */

void ply_lfos(void);
void ply_mod(void);
void ply_endtie(void);

void MPlayExtender(struct CgbChannel *cgbChans)
{
    u32 ident;
    struct SoundInfo *soundInfo;

    REG_SOUNDCNT_X = (SOUND_MASTER_ENABLE | SOUND_1_ON | SOUND_2_ON | SOUND_3_ON | SOUND_4_ON);
    REG_SOUNDCNT_L = 0x77;
    REG_NR12 = 0x08;
    REG_NR22 = 0x08;
    REG_NR42 = 0x08;
    REG_NR14 = 0x80;
    REG_NR24 = 0x80;
    REG_NR44 = 0x80;
    REG_NR30 = 0x00;
    REG_SOUNDCNT_L = 0xFF77;
#if PORTABLE
    /* The software PSG's copy of the four osc-offs above (after sa2):
       envelope 8 with a trigger is what CgbOscOff does on the host. */
    {
        u8 i;
        for (i = 0; i < 4; i++) {
            cgb_set_envelope(i, 8);
            cgb_trigger_note(i);
        }
    }
#endif
    soundInfo = SOUND_INFO_PTR;
    ident = soundInfo->ident;
    if (ident == ID_NUMBER) {
        soundInfo->ident = ident + 1;
        gMPlayJumpTable[8] = (MPlayFunc)ply_memacc;
        gMPlayJumpTable[0x11] = (MPlayFunc)ply_lfos;
        gMPlayJumpTable[0x13] = (MPlayFunc)ply_mod;
        gMPlayJumpTable[0x1C] = (MPlayFunc)ply_xcmd;
        gMPlayJumpTable[0x1D] = (MPlayFunc)ply_endtie;
        gMPlayJumpTable[0x1E] = (MPlayFunc)SampleFreqSet;
        gMPlayJumpTable[0x1F] = (MPlayFunc)TrackStop;
        gMPlayJumpTable[0x20] = (MPlayFunc)FadeOutBody;
        gMPlayJumpTable[0x21] = (MPlayFunc)TrkVolPitSet;
        soundInfo->cgbChans = cgbChans;
        soundInfo->CgbSound = (CgbSoundFunc)CgbSound;
        soundInfo->CgbOscOff = (CgbOscOffFunc)CgbOscOff;
        soundInfo->MidiKeyToCgbFreq = (MidiKeyToCgbFreqFunc)MidiKeyToCgbFreq;
#if PORTABLE
        soundInfo->maxLines = (u8)(uintptr_t)&gMaxLines;
#else
        soundInfo->maxLines = (u8)(u32)&gMaxLines;
#endif
        CpuFill32(0, cgbChans, 0x100);
        cgbChans[0].type = 1;
        cgbChans[0].panMask = 0x11;
        cgbChans[1].type = 2;
        cgbChans[1].panMask = 0x22;
        cgbChans[2].type = 3;
        cgbChans[2].panMask = 0x44;
        cgbChans[3].type = 4;
        cgbChans[3].panMask = 0x88;
        soundInfo->ident = ident;
    }
}
