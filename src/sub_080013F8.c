#include "global.h"
#include "gba/compat.h"
#include "gba/m4a_internal.h"

/* MPlayExtender */

extern struct SoundInfo *gUnk_03007FF0;
extern MPlayFunc gUnk_02001D90[];
extern u8 gMaxLines;
void sub_08002340(void);
void ply_lfos(void);
void ply_mod(void);
void sub_08002498(void);
void ply_endtie(void);
void sub_08001C88(void);
void sub_08001BD0(void);
void sub_08001B28(void);

extern void sub_08001640(u32 a);
extern void sub_080019F4(void);
extern void sub_08001A74(void);

void sub_080013F8(struct CgbChannel *cgbChans)
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
        gUnk_02001D90[8] = (MPlayFunc)sub_08002340;
        gUnk_02001D90[0x11] = (MPlayFunc)ply_lfos;
        gUnk_02001D90[0x13] = (MPlayFunc)ply_mod;
        gUnk_02001D90[0x1C] = (MPlayFunc)sub_08002498;
        gUnk_02001D90[0x1D] = (MPlayFunc)ply_endtie;
        gUnk_02001D90[0x1E] = (MPlayFunc)sub_08001640;
        gUnk_02001D90[0x1F] = (MPlayFunc)TrackStop;
        gUnk_02001D90[0x20] = (MPlayFunc)sub_080019F4;
        gUnk_02001D90[0x21] = (MPlayFunc)sub_08001A74;
        soundInfo->cgbChans = cgbChans;
        soundInfo->CgbSound = (CgbSoundFunc)sub_08001C88;
        soundInfo->CgbOscOff = (CgbOscOffFunc)sub_08001BD0;
        soundInfo->MidiKeyToCgbFreq = (MidiKeyToCgbFreqFunc)sub_08001B28;
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
