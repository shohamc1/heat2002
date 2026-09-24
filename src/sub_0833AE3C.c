#include "global.h"
#include "gba/m4a_internal.h"

void _08344B80(u32 arg0, u32 arg1);

/* SoundClear, high 0x0833 module copy: same code as sub_0800177C, except
 * the indirect CgbOscOff call goes through the module's own _call_via_r1
 * stub at 0x08344B80 (ch carries the u8-narrowed channel, arg1 the target). */

void sub_0833AE3C(void)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    s32 i;
    void *chan;

    if (soundInfo->ident != ID_NUMBER)
        return;

    soundInfo->ident++;

    i = MAX_DIRECTSOUND_CHANNELS;
    chan = &soundInfo->chans[0];

    while (i > 0)
    {
        ((struct SoundChannel *)chan)->statusFlags = 0;
        i--;
        chan = (void *)((s32)chan + sizeof(struct SoundChannel));
    }

    chan = soundInfo->cgbChans;

    if (chan)
    {
        i = 1;

        while (i <= 4)
        {
            u32 ch = (u8)i;
            _08344B80(ch, (u32)soundInfo->CgbOscOff);
            ((struct CgbChannel *)chan)->statusFlags = 0;
            i++;
            chan = (void *)((s32)chan + sizeof(struct CgbChannel));
        }
    }

    soundInfo->ident = ID_NUMBER;
}
