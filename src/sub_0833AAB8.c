#include "global.h"
#define GBA_CPUSET sub_08344B64
#include "gba/compat.h"
#include "gba/m4a_internal.h"
#include "functions.h"
#include "m4a.h"
#include "variables.h"

/* MPlayExtender (high copy) */

void sub_0833BA00(void);
void sub_0833A764(void);
void sub_0833A778(void);
void sub_0833BB58(void);
void sub_0833A6FC(void);
void sub_0833AD00(void);
void sub_0833A488(void);
void sub_0833B0B4(void);
void sub_0833B134(void);
void sub_0833B348(void);
void sub_0833B1E8(void);

void sub_0833AAB8(struct CgbChannel *cgbChans)
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
    soundInfo = SOUND_INFO_PTR;
    ident = soundInfo->ident;
    if (ident == ID_NUMBER)
    {
        soundInfo->ident = ident + 1;
        gUnk_02038DE0[8] = (MPlayFunc)sub_0833BA00;
        gUnk_02038DE0[0x11] = (MPlayFunc)sub_0833A764;
        gUnk_02038DE0[0x13] = (MPlayFunc)sub_0833A778;
        gUnk_02038DE0[0x1C] = (MPlayFunc)sub_0833BB58;
        gUnk_02038DE0[0x1D] = (MPlayFunc)sub_0833A6FC;
        gUnk_02038DE0[0x1E] = (MPlayFunc)sub_0833AD00;
        gUnk_02038DE0[0x1F] = (MPlayFunc)sub_0833A488;
        gUnk_02038DE0[0x20] = (MPlayFunc)sub_0833B0B4;
        gUnk_02038DE0[0x21] = (MPlayFunc)sub_0833B134;
        soundInfo->cgbChans = cgbChans;
        soundInfo->CgbSound = (CgbSoundFunc)sub_0833B348;
        soundInfo->CgbOscOff = (CgbOscOffFunc)sub_0833B290;
        soundInfo->MidiKeyToCgbFreq = (MidiKeyToCgbFreqFunc)sub_0833B1E8;
        soundInfo->maxLines = (u8)(u32)&gMaxLines;
        CpuFill32(0, (u32)cgbChans, 0x100);
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
