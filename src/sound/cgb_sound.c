#include "global.h"
#include "gba/m4a_internal.h"
#include "functions.h"

/* MidiKeyToCgbFreq. Tables: gCgbScaleTable = gCgbScaleTable (u8),
 * gCgbFreqTable = gCgbFreqTable (s16), gNoiseTable = gNoiseTable (u8). */
extern const u8 gCgbScaleTable[];
extern const s16 gCgbFreqTable[];
extern const u8 gNoiseTable[];
/* CgbSound, an older m4a revision than pokeemerald's and tmc's: no NR52
 * channel-status check, no pseudo-echo envelope write, and
 * envelopeStepTimeAndDir is a u8 kept across channels. */
extern const u8 gCgb3Vol[];

u32 MidiKeyToCgbFreq(u8 chanNum, u8 key, u8 fineAdjust)
{
    if (chanNum == 4) {
        if (key <= 20) {
            key = 0;
        } else {
            key -= 21;
            if (key > 59)
                key = 59;
        }

        return gNoiseTable[key];
    } else {
        s32 val1;
        s32 val2;

        if (key <= 35) {
            fineAdjust = 0;
            key = 0;
        } else {
            key -= 36;
            if (key > 130) {
                key = 130;
                fineAdjust = 255;
            }
        }

        val1 = gCgbScaleTable[key];
        val1 = gCgbFreqTable[val1 & 0xF] >> (val1 >> 4);

        val2 = gCgbScaleTable[key + 1];
        val2 = gCgbFreqTable[val2 & 0xF] >> (val2 >> 4);

        return val1 + ((fineAdjust * (val2 - val1)) >> 8) + 2048;
    }
}

void CgbOscOff(u8 chanNum)
{
    switch (chanNum) {
        case 1:
            REG_NR12 = 8;
            REG_NR14 = 0x80;
            break;
        case 2:
            REG_NR22 = 8;
            REG_NR24 = 0x80;
            break;
        case 3:
            REG_NR30 = 0;
            break;
        default:
            REG_NR42 = 8;
            REG_NR44 = 0x80;
            break;
    }
}

void CgbModVol(struct CgbChannel *chan)
{
    u32 vol;

    if (chan->rightVolume >= chan->leftVolume) {
        if ((chan->rightVolume >> 1) >= chan->leftVolume) {
            chan->pan = 0x0F;
            goto clip;
        }
    } else {
        if ((chan->leftVolume >> 1) >= chan->rightVolume) {
            chan->pan = 0xF0;
            goto clip;
        }
    }
    chan->pan = 0xFF;
    vol = chan->rightVolume + chan->leftVolume;
    vol >>= 4;
    chan->envelopeGoal = vol;
    goto tail;

clip:
    vol = chan->rightVolume + chan->leftVolume;
    vol >>= 4;
    chan->envelopeGoal = vol;
    if (vol > 0xF)
        chan->envelopeGoal = 0xF;

tail:
    chan->sustainGoal = (s8)(((chan->envelopeGoal * chan->sustain) + 0xF) >> 4);
    chan->pan = chan->pan & chan->panMask;
}

void CgbSound(void)
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
    u8 envelopeStepTimeAndDir;

    // Most comparisons that cast to s8 perform 'and' by 0xFF.
    int mask = 0xff;

    if (soundInfo->c15)
        soundInfo->c15--;
    else
        soundInfo->c15 = 14;

    for (ch = 1, channels = soundInfo->cgbChans; ch <= 4; ch++, channels++) {
        if (!(channels->statusFlags &
              (SOUND_CHANNEL_SF_START | SOUND_CHANNEL_SF_STOP | SOUND_CHANNEL_SF_IEC | SOUND_CHANNEL_SF_ENV)))
            continue;

        switch (ch) {
            case 1:
                nrx0ptr = (vu8 *)REG_ADDR_NR10;
                nrx1ptr = (vu8 *)REG_ADDR_NR11;
                nrx2ptr = (vu8 *)REG_ADDR_NR12;
                nrx3ptr = (vu8 *)REG_ADDR_NR13;
                nrx4ptr = (vu8 *)REG_ADDR_NR14;
                break;
            case 2:
                nrx0ptr = (vu8 *)(REG_ADDR_NR10 + 1);
                nrx1ptr = (vu8 *)REG_ADDR_NR21;
                nrx2ptr = (vu8 *)REG_ADDR_NR22;
                nrx3ptr = (vu8 *)REG_ADDR_NR23;
                nrx4ptr = (vu8 *)REG_ADDR_NR24;
                break;
            case 3:
                nrx0ptr = (vu8 *)REG_ADDR_NR30;
                nrx1ptr = (vu8 *)REG_ADDR_NR31;
                nrx2ptr = (vu8 *)REG_ADDR_NR32;
                nrx3ptr = (vu8 *)REG_ADDR_NR33;
                nrx4ptr = (vu8 *)REG_ADDR_NR34;
                break;
            default:
                nrx0ptr = (vu8 *)(REG_ADDR_NR30 + 1);
                nrx1ptr = (vu8 *)REG_ADDR_NR41;
                nrx2ptr = (vu8 *)REG_ADDR_NR42;
                nrx3ptr = (vu8 *)REG_ADDR_NR43;
                nrx4ptr = (vu8 *)REG_ADDR_NR44;
                break;
        }

        prevC15 = soundInfo->c15;

        if (channels->statusFlags & SOUND_CHANNEL_SF_START) {
            if (!(channels->statusFlags & SOUND_CHANNEL_SF_STOP)) {
                channels->statusFlags = 3; // attack
                channels->modify = CGB_CHANNEL_MO_PIT | CGB_CHANNEL_MO_VOL;
                CgbModVol(channels);
                switch (ch) {
                    case 1:
                        *nrx0ptr = channels->sweep;
                        // fallthrough
                    case 2:
                        *nrx1ptr = ((u32)channels->wavePointer << 6) + channels->length;
                        goto init_env_step_time_dir;
                    case 3:
                        if (channels->wavePointer != channels->currentPointer) {
                            *nrx0ptr = 0x40;
                            REG_WAVE_RAM0 = channels->wavePointer[0];
                            REG_WAVE_RAM1 = channels->wavePointer[1];
                            REG_WAVE_RAM2 = channels->wavePointer[2];
                            REG_WAVE_RAM3 = channels->wavePointer[3];
                            channels->currentPointer = channels->wavePointer;
                        }
                        *nrx0ptr = 0;
                        *nrx1ptr = channels->length;
                        if (channels->length)
                            channels->n4 = 0xC0;
                        else
                            channels->n4 = 0x80;
                        break;
                    default:
                        *nrx1ptr = channels->length;
                        *nrx3ptr = (u32)channels->wavePointer << 3;
                    init_env_step_time_dir:
                        envelopeStepTimeAndDir = channels->attack + CGB_NRx2_ENV_DIR_INC;
                        if (channels->length)
                            channels->n4 = 0x40;
                        else
                            channels->n4 = 0x00;
                        break;
                }
                channels->envelopeCounter = channels->attack;
                if ((u8)(channels->attack & mask)) {
                    channels->envelopeVolume = 0;
                    goto envelope_step_complete;
                } else {
                    goto envelope_decay_start;
                }
            } else {
                goto oscillator_off;
            }
        } else if (channels->statusFlags & SOUND_CHANNEL_SF_IEC) {
            channels->pseudoEchoLength--;
            if ((s8)(channels->pseudoEchoLength & mask) <= 0) {
            oscillator_off:
                CgbOscOff(ch);
                channels->statusFlags = 0;
                goto channel_complete;
            }
            goto envelope_complete;
        } else if ((channels->statusFlags & SOUND_CHANNEL_SF_STOP) && (channels->statusFlags & SOUND_CHANNEL_SF_ENV)) {
            channels->statusFlags &= ~SOUND_CHANNEL_SF_ENV;
            channels->envelopeCounter = channels->release;
            if ((u8)(channels->release & mask)) {
                channels->modify |= CGB_CHANNEL_MO_VOL;
                if (ch != 3)
                    envelopeStepTimeAndDir = channels->release;
                goto envelope_step_complete;
            } else {
                goto envelope_pseudoecho_start;
            }
        } else {
        envelope_step_repeat:
            if (channels->envelopeCounter == 0) {
                if (ch == 3)
                    channels->modify |= CGB_CHANNEL_MO_VOL;

                CgbModVol(channels);
                if ((channels->statusFlags & SOUND_CHANNEL_SF_ENV) == 0) // release
                {
                    channels->envelopeVolume--;
                    if ((s8)(channels->envelopeVolume & mask) <= 0) {
                    envelope_pseudoecho_start:
                        channels->envelopeVolume = ((channels->envelopeGoal * channels->pseudoEchoVolume) + 0xFF) >> 8;
                        if (channels->envelopeVolume) {
                            channels->statusFlags |= SOUND_CHANNEL_SF_IEC;
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            goto envelope_complete;
                        } else {
                            goto oscillator_off;
                        }
                    } else {
                        channels->envelopeCounter = channels->release;
                    }
                } else if ((channels->statusFlags & SOUND_CHANNEL_SF_ENV) == 1) // sustain
                {
                envelope_sustain:
                    channels->envelopeVolume = channels->sustainGoal;
                    channels->envelopeCounter = 7;
                } else if ((channels->statusFlags & SOUND_CHANNEL_SF_ENV) == 2) // decay
                {
                    channels->envelopeVolume--;
                    if ((s8)(channels->envelopeVolume & mask) <= (s8)channels->sustainGoal) {
                    envelope_sustain_start:
                        if (channels->sustain == 0) {
                            channels->statusFlags &= ~SOUND_CHANNEL_SF_ENV;
                            goto envelope_pseudoecho_start;
                        } else {
                            channels->statusFlags--;
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            if (ch != 3)
                                envelopeStepTimeAndDir = CGB_NRx2_ENV_DIR_INC;
                            goto envelope_sustain;
                        }
                    } else {
                        channels->envelopeCounter = channels->decay;
                    }
                } else {
                    channels->envelopeVolume++;
                    if ((u8)(channels->envelopeVolume & mask) >= channels->envelopeGoal) {
                    envelope_decay_start:
                        channels->statusFlags--;
                        channels->envelopeCounter = channels->decay;
                        if ((u8)(channels->envelopeCounter & mask)) {
                            channels->modify |= CGB_CHANNEL_MO_VOL;
                            channels->envelopeVolume = channels->envelopeGoal;
                            if (ch != 3)
                                envelopeStepTimeAndDir = channels->decay;
                        } else {
                            goto envelope_sustain_start;
                        }
                    } else {
                        channels->envelopeCounter = channels->attack;
                    }
                }
            }
        }

    envelope_step_complete:
        channels->envelopeCounter--;
        if (prevC15 == 0) {
            prevC15--;
            goto envelope_step_repeat;
        }

    envelope_complete:
        if (channels->modify & CGB_CHANNEL_MO_PIT) {
            if (ch < 4 && (channels->type & 8)) {
                int dac_pwm_rate = REG_SOUNDBIAS_H;
                if (dac_pwm_rate < 0x40)
                    channels->frequency = (channels->frequency + 2) & 0x7fc;
                else if (dac_pwm_rate < 0x80)
                    channels->frequency = (channels->frequency + 1) & 0x7fe;
            }

            if (ch != 4)
                *nrx3ptr = channels->frequency;
            else
                *nrx3ptr = (*nrx3ptr & 0x08) | channels->frequency;
            channels->n4 = (channels->n4 & 0xC0) + *((u8 *)&channels->frequency + 1);
            *nrx4ptr = (s8)(channels->n4 & mask);
        }

        if (channels->modify & CGB_CHANNEL_MO_VOL) {
            REG_NR51 = (REG_NR51 & ~channels->panMask) | channels->pan;
            if (ch == 3) {
                *nrx2ptr = gCgb3Vol[channels->envelopeVolume];
                if (channels->n4 & 0x80) {
                    *nrx0ptr = 0x80;
                    *nrx4ptr = channels->n4;
                    channels->n4 &= ~0x80;
                }
            } else {
                *nrx2ptr = (envelopeStepTimeAndDir & 0xf) + (channels->envelopeVolume << 4);
                *nrx4ptr = channels->n4 | 0x80;
                if (ch == 1 && !(*nrx0ptr & 0x08))
                    *nrx4ptr = channels->n4 | 0x80;
            }
        }

    channel_complete:
        channels->modify = 0;
    }
}
