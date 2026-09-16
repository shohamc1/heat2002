#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/m4a_internal.h"

/* m4aSoundMode */

void sub_080017D0(void);
void sub_08001640(u32 a);

void sub_080016E4(u32 mode)
{
    struct SoundInfo *soundInfo = (struct SoundInfo *)SOUND_INFO_PTR;
    u32 temp;
    u8 *p;

    if (soundInfo->ident != ID_NUMBER)
        return;
    soundInfo->ident = soundInfo->ident + 1;
    temp = mode & 0xFF;
    if (temp != 0) {
        temp &= 0x7F;
        soundInfo->reverb = temp;
    }
    temp = mode & 0xF00;
    if (temp != 0) {
        soundInfo->maxChans = temp >> 8;
        for (temp = MAX_DIRECTSOUND_CHANNELS, p = &soundInfo->chans[0].statusFlags; temp != 0; temp--, p += sizeof(struct SoundChannel))
            *p = 0;
    }
    temp = mode & 0xF000;
    if (temp != 0)
        soundInfo->masterVolume = temp >> 12;
    temp = mode & 0xB00000;
    if (temp != 0) {
        temp = (temp & 0x300000) >> 14;
        REG_SOUNDBIAS_H = (REG_SOUNDBIAS_H & 0x3F) | temp;
    }
    temp = mode & 0xF0000;
    if (temp != 0) {
        sub_080017D0();
        sub_08001640(temp);
    }
    soundInfo->ident = ID_NUMBER;
}
