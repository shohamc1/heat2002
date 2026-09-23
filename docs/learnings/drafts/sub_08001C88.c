#include "global.h"
#include "gba/m4a_internal.h"

/* CgbSound (older m4a revision than pokeemerald's): the envelope-state
 * encoding is inverted (attack=3, decay=2, sustain=1, release=0), there is
 * no NR52 channel-status check next to SF_IEC, and the pseudo-echo path
 * leaves envelopeStepTimeAndDir alone. */

extern const u8 gUnk_0801D1EC[];

extern void sub_08001C20(struct CgbChannel *);
extern void sub_08001BD0(u8);

void sub_08001C88(void)
{
    s32 ch;
    struct CgbChannel *channels;
    s32 prevC15;
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    vu8 *nrx0ptr;
    vu8 *nrx1ptr;
    vu8 *nrx2ptr;
    vu8 *nrx3ptr;
    vu8 *nrx4ptr;
    s32 envelopeStepTimeAndDir;
    s32 mask = 0xff;
    register u32 sf_start asm("r10");

    if (soundInfo->c15)
        soundInfo->c15--;
    else
        soundInfo->c15 = 14;

    for (ch = 1, channels = soundInfo->cgbChans; ch <= 4; channels++, ch++)
    {
        u8 sf = channels->statusFlags;

        if (!(0xC7 & sf))
            continue;

        switch (ch)
        {
            case 1:
                nrx0ptr = (vu8 *)REG_ADDR_NR10;
                nrx1ptr = (vu8 *)REG_ADDR_NR11;
                nrx2ptr = (vu8 *)REG_ADDR_NR12;
                nrx3ptr = (vu8 *)REG_ADDR_NR13;
                nrx4ptr = (vu8 *)REG_ADDR_NR14;
                break;
            case 2:
                nrx0ptr = (vu8 *)REG_ADDR_NR10 + 1;
                nrx1ptr = (vu8 *)REG_ADDR_NR21;
                nrx2ptr = (vu8 *)REG_ADDR_NR22;
                nrx3ptr = (vu8 *)REG_ADDR_NR23;
                nrx4ptr = nrx2ptr + 4;
                break;
            case 3:
                nrx0ptr = (vu8 *)REG_ADDR_NR30;
                nrx1ptr = (vu8 *)REG_ADDR_NR31;
                nrx2ptr = (vu8 *)REG_ADDR_NR32;
                nrx3ptr = (vu8 *)REG_ADDR_NR33;
                nrx4ptr = (vu8 *)REG_ADDR_NR34;
                break;
            default:
                nrx0ptr = (vu8 *)REG_ADDR_NR30 + 1;
                nrx1ptr = (vu8 *)REG_ADDR_NR41;
                nrx2ptr = (vu8 *)REG_ADDR_NR42;
                nrx3ptr = (vu8 *)REG_ADDR_NR43;
                nrx4ptr = nrx2ptr + 4;
                break;
        }

        prevC15 = soundInfo->c15;

        {
            sf_start = 0x80;
            if (sf_start & sf)
            {
                if (!(0x40 & sf))
                {
                    channels->statusFlags = 3;
                    channels->modify = 3;
                    sub_08001C20(channels);
                    switch (ch)
                    {
                        case 1:
                            *nrx0ptr = channels->sweep;
                            // fallthrough
                        case 2:
                            *nrx1ptr = ((u32)channels->wavePointer << 6) + channels->length;
                            goto init_env_step_time_dir;
                        case 3:
                            if (channels->wavePointer != channels->currentPointer)
                            {
                                *nrx0ptr = 0x40;
                                REG_WAVE_RAM0 = ((u32 *)channels->wavePointer)[0];
                                REG_WAVE_RAM1 = ((u32 *)channels->wavePointer)[1];
                                REG_WAVE_RAM2 = ((u32 *)channels->wavePointer)[2];
                                REG_WAVE_RAM3 = ((u32 *)channels->wavePointer)[3];
                                channels->currentPointer = channels->wavePointer;
                            }
                            *nrx0ptr = 0;
                            *nrx1ptr = channels->length;
                            if (channels->length)
                                channels->n4 = 0xC0;
                            else
                                channels->n4 = sf_start;
                            break;
                        default:
                            *nrx1ptr = channels->length;
                            *nrx3ptr = (u32)channels->wavePointer << 3;
                        init_env_step_time_dir:
                            envelopeStepTimeAndDir = (u8)(channels->attack + 8);
                            if (channels->length)
                                channels->n4 = 0x40;
                            else
                                channels->n4 = 0x00;
                            break;
                    }
                    channels->envelopeCounter = channels->attack;
                    if ((u8)(channels->attack & mask))
                    {
                        channels->envelopeVolume = 0;
                        goto envelope_step_complete;
                    }
                    else
                    {
                        goto envelope_decay_start;
                    }
                }
                else
                {
                    goto oscillator_off;
                }
            }
            else if (0x04 & sf)
            {
                channels->pseudoEchoLength--;
                if ((s8)(channels->pseudoEchoLength & mask) <= 0)
                {
                oscillator_off:
                    sub_08001BD0(ch);
                    channels->statusFlags = 0;
                    goto channel_complete;
                }
                goto envelope_complete;
            }
            else if ((0x40 & sf) && (channels->statusFlags & 3))
            {
                channels->statusFlags = ~3 & sf;
                channels->envelopeCounter = channels->release;
                if ((u8)(channels->release & mask))
                {
                    channels->modify |= 1;
                    if (ch != 3)
                        envelopeStepTimeAndDir = channels->release;
                    goto envelope_step_complete;
                }
                else
                {
                    goto envelope_pseudoecho_start;
                }
            }
            else
            {
            envelope_step_repeat:
                if (channels->envelopeCounter == 0)
                {
                    if (ch == 3)
                        channels->modify |= 1;

                    sub_08001C20(channels);
                    if ((channels->statusFlags & 3) == 0)
                    {
                        channels->envelopeVolume--;
                        if ((s8)(channels->envelopeVolume & mask) > 0)
                        {
                            channels->envelopeCounter = channels->release;
                        }
                        else
                        {
                        envelope_pseudoecho_start:
                            channels->envelopeVolume = ((channels->pseudoEchoVolume * channels->envelopeGoal) + 0xFF) >> 8;
                            if (channels->envelopeVolume)
                            {
                                channels->statusFlags |= 4;
                                channels->modify |= 1;
                                goto envelope_complete;
                            }
                            else
                            {
                                goto oscillator_off;
                            }
                        }
                    }
                    else if ((channels->statusFlags & 3) == 1)
                    {
                    envelope_sustain:
                        channels->envelopeVolume = channels->sustainGoal;
                        channels->envelopeCounter = 7;
                    }
                    else if ((channels->statusFlags & 3) == 2)
                    {
                        channels->envelopeVolume--;
                        if ((s8)(channels->envelopeVolume & mask) <= (s8)channels->sustainGoal)
                        {
                        envelope_sustain_start:
                            if (channels->sustain == 0)
                            {
                                channels->statusFlags &= ~3;
                                goto envelope_pseudoecho_start;
                            }
                            else
                            {
                                channels->statusFlags--;
                                channels->modify |= 1;
                                if (ch != 3)
                                    envelopeStepTimeAndDir = 8;
                                goto envelope_sustain;
                            }
                        }
                        else
                        {
                            channels->envelopeCounter = channels->decay;
                        }
                    }
                    else
                    {
                        channels->envelopeVolume++;
                        if ((u8)(channels->envelopeVolume & mask) >= channels->envelopeGoal)
                        {
                        envelope_decay_start:
                            channels->statusFlags--;
                            channels->envelopeCounter = channels->decay;
                            if ((u8)(channels->envelopeCounter & mask))
                            {
                                channels->modify |= 1;
                                channels->envelopeVolume = channels->envelopeGoal;
                                if (ch != 3)
                                    envelopeStepTimeAndDir = channels->decay;
                            }
                            else
                            {
                                goto envelope_sustain_start;
                            }
                        }
                        else
                        {
                            channels->envelopeCounter = channels->attack;
                        }
                    }
                }
            }
        }

    envelope_step_complete:
        channels->envelopeCounter--;
        if (prevC15 == 0)
        {
            prevC15--;
            goto envelope_step_repeat;
        }

    envelope_complete:
        if (channels->modify & 2)
        {
            if (ch < 4 && (channels->type & 8))
            {
                s32 dac_pwm_rate = REG_SOUNDBIAS_H;
                if (dac_pwm_rate < 0x40)
                    channels->frequency = (channels->frequency + 2) & 0x7fc;
                else if (dac_pwm_rate < 0x80)
                    channels->frequency = (channels->frequency + 1) & 0x7fe;
            }

            if (ch != 4)
                *nrx3ptr = channels->frequency;
            else
                *nrx3ptr = (*nrx3ptr & 0x08) | channels->frequency;
            channels->n4 = (channels->n4 & 0xC0) + ((u8 *)&channels->frequency)[1];
            *nrx4ptr = (s8)(channels->n4 & mask);
        }

        if (channels->modify & 1)
        {
            REG_NR51 = (REG_NR51 & ~channels->panMask) | channels->pan;
            if (ch == 3)
            {
                *nrx2ptr = gUnk_0801D1EC[channels->envelopeVolume];
                if (channels->n4 & 0x80)
                {
                    *nrx0ptr = 0x80;
                    *nrx4ptr = channels->n4;
                    channels->n4 &= ~0x80;
                }
            }
            else
            {
                envelopeStepTimeAndDir &= 0xf;
                *nrx2ptr = (channels->envelopeVolume << 4) + envelopeStepTimeAndDir;
                *nrx4ptr = channels->n4 | 0x80;
                if (ch == 1 && !(*nrx0ptr & 0x08))
                    *nrx4ptr = channels->n4 | 0x80;
            }
        }

    channel_complete:
        channels->modify = 0;
    }
}
