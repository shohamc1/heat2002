#include "global.h"
#define GBA_CPUSET sub_08344B64
#include "gba/compat.h"
#include "gba/m4a_internal.h"

/* MPlayExtender (high copy) */

extern struct SoundInfo *gUnk_03007FF0;
extern MPlayFunc gUnk_02038DE0[];
extern u8 gMaxLines;
extern u8 gUnk_02002F81;
extern u8 gUnk_02001CE5;
extern u8 gUnk_02001CF9;
extern u8 gUnk_020030D9;
extern u8 gUnk_02001C7D;
extern u8 gUnk_02002281;
extern u8 gUnk_02001A09;
extern u8 gUnk_02002635;
extern u8 gUnk_020026B5;
extern u8 gUnk_020028C9;
extern u8 gUnk_02002811;
extern u8 gUnk_02002769;

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
        gUnk_02038DE0[8] = (MPlayFunc)&gUnk_02002F81;
        gUnk_02038DE0[0x11] = (MPlayFunc)&gUnk_02001CE5;
        gUnk_02038DE0[0x13] = (MPlayFunc)&gUnk_02001CF9;
        gUnk_02038DE0[0x1C] = (MPlayFunc)&gUnk_020030D9;
        gUnk_02038DE0[0x1D] = (MPlayFunc)&gUnk_02001C7D;
        gUnk_02038DE0[0x1E] = (MPlayFunc)&gUnk_02002281;
        gUnk_02038DE0[0x1F] = (MPlayFunc)&gUnk_02001A09;
        gUnk_02038DE0[0x20] = (MPlayFunc)&gUnk_02002635;
        gUnk_02038DE0[0x21] = (MPlayFunc)&gUnk_020026B5;
        soundInfo->cgbChans = cgbChans;
        soundInfo->CgbSound = (CgbSoundFunc)&gUnk_020028C9;
        soundInfo->CgbOscOff = (CgbOscOffFunc)&gUnk_02002811;
        soundInfo->MidiKeyToCgbFreq = (MidiKeyToCgbFreqFunc)&gUnk_02002769;
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
