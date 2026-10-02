// The MP2K sound driver's assembly half (lib/m4a_1.s) as C, for the
// hosted build only (issue 5 step 6), after sa2's
// src/platform/shared/audio/m4a_sound_mixer.c. The GBA build keeps the
// hand-written asm; nothing here compiles into it.
//
// sa2's mixer drives their newer driver revision. This ROM runs one
// revision older (ID 0x68736D53, the same as sa2's), and lib/m4a_1.s's
// header lists the five differences from pokeemerald's asm. The two
// that touch this file, both taken from our asm rather than sa2's C:
//   - MPlayMain does not re-check MUSICPLAYER_STATUS_PAUSE after
//     FadeOutBody (sa2's MP2KPlayerMain checks twice).
//   - GenerateAudio's unresampled path is taken for TONEDATA_TYPE_FIX
//     (type & 8), which is what SoundMainRAM's `tst r0, #8` tests, not
//     sa2's TONEDATA_TYPE_CGB (type & 7).
// Everything else maps one-to-one: sa2's SoundMixerState/MixerSource/
// MP2KTrack/MP2KPlayerState field names onto our SoundInfo/
// SoundChannel+CgbChannel/MusicPlayerTrack/MusicPlayerInfo spellings
// (ident/pseudoEchoVolume/keyM/modM class renames; the channel arrays
// are two structs here, not one union, so the CGB-specific fields go
// through a struct CgbChannel * cast -- the two layouts share every
// field this file reads, on the host's 8-byte pointers as on the GBA's
// 4-byte ones).
//
// sa2's event_goto/patt/rept read an absolute pointer from the stream.
// This tree's hosted songs store an offset from the field instead
// (mRelPtr), so the unaligned fields need no load-time relocation.

#include <stddef.h>
#include <string.h>

#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/compat.h"
#include "gba/m4a_internal.h"
#include "platform/platform.h"
#include "platform/shared/audio/cgb_audio.h"

static void SampleMixer(struct SoundInfo *mixer, u32 scanlineLimit, s32 samplesPerFrame, fixed8_24 *pcmBuffer,
                        u8 dmaCounter, u16 maxBufSize);
static int TickEnvelope(struct SoundChannel *chan, struct WaveData *wav);
static void GenerateAudio(struct SoundInfo *mixer, struct SoundChannel *chan, struct WaveData *wav, fixed8_24 *pcmBuffer,
                          s32 samplesPerFrame, float sampleRateReciprocal);
static void ChnVolSetAsm(struct SoundChannel *chan, struct MusicPlayerTrack *track);
static void ClearModM(struct MusicPlayerTrack *track);

/* The tempo units each VBlank tick is worth (src/data/rom_0801D018.c);
   MPlayMain's wait dispatch reads it like lib/m4a_1.s's lt_gClockTable. */
extern const u8 gClockTable[];
/* src/sound/MidiKeyToFreq.c, the C half's pitch-to-rate lookup. */
s32 MidiKeyToFreq(struct WaveData *wav, u8 key, u32 fineAdjust);

#define VCOUNT_VBLANK   160
#define TOTAL_SCANLINES 228

#ifndef __has_builtin
#define __has_builtin(x) defined(__GNUC__)
#endif

#if ((-1 >> 1) == -1) && __has_builtin(__builtin_ctz)
#define FLOOR_DIV_POW2(a, b) ((a) >> __builtin_ctz(b))
#else
#define FLOOR_DIV_POW2(a, b) ((a) > 0 ? (a) / (b) : (((a) + 1 - (b)) / (b)))
#endif

static s16 audioBuffer[PCM_DMA_BUF_SIZE];

void SoundMain(void)
{
    struct SoundInfo *mixer = SOUND_INFO_PTR;

    if (mixer->ident != ID_NUMBER) {
        return;
    }
    mixer->ident++;

    u32 maxScanlines = mixer->maxLines;
    if (mixer->maxLines != 0) {
        u32 vcount = REG_VCOUNT;
        maxScanlines += vcount;
        if (vcount < VCOUNT_VBLANK) {
            maxScanlines += TOTAL_SCANLINES;
        }
    }

    if (mixer->MPlayMainHead != NULL) {
        mixer->MPlayMainHead(mixer->musicPlayerHead);
    }

    mixer->CgbSound();

    s32 samplesPerFrame = mixer->pcmSamplesPerVBlank;
    fixed8_24 *pcmBuffer = mixer->pcmBuffer;
    s32 dmaCounter = mixer->pcmDmaCounter;

    if (dmaCounter > 1) {
        pcmBuffer += samplesPerFrame * (mixer->pcmDmaPeriod - (dmaCounter - 1)) * 2;
    }

    SampleMixer(mixer, maxScanlines, samplesPerFrame, pcmBuffer, dmaCounter, PCM_DMA_BUF_SIZE);
    cgb_audio_generate(samplesPerFrame);
}

static void SampleMixer(struct SoundInfo *mixer, u32 scanlineLimit, s32 samplesPerFrame, fixed8_24 *pcmBuffer,
                        u8 dmaCounter, u16 maxBufSize)
{
    s32 reverb = mixer->reverb;
    if (reverb) {
        // The vanilla reverb effect outputs a mono sound from four sources:
        //  - L/R channels as they were mixer->pcmDmaPeriod frames ago
        //  - L/R channels as they were (mixer->pcmDmaPeriod - 1) frames ago
        fixed8_24 *tmp1 = pcmBuffer;
        fixed8_24 *tmp2;
        if (dmaCounter == 2) {
            tmp2 = mixer->pcmBuffer;
        } else {
            tmp2 = pcmBuffer + samplesPerFrame * 2;
        }
        u16 i = 0;
        do {
            fixed8_24 s = tmp1[0] + tmp1[1] + tmp2[0] + tmp2[1];
            // Signed and 64-bit: four summed 8.24 samples times a reverb
            // level up to 127 can exceed 32 bits, and an unsigned product
            // would shift negative samples into large positive ones.
            s = (fixed8_24)(((long long)s * reverb) >> 9);
            tmp1[0] = tmp1[1] = s;
            tmp1 += 2;
            tmp2 += 2;
        } while (++i < samplesPerFrame);
    } else {
        for (int i = 0; i < samplesPerFrame; i++) {
            fixed8_24 *dst = &pcmBuffer[i * 2];
            dst[1] = dst[0] = 0;
        }
    }

    float sampleRateReciprocal = mixer->sampleRateReciprocal;
    /* This ROM's mode word (m4aSoundInit's 0x0097EA00) asks for fourteen
       direct-sound channels, two past the twelve the struct holds; on the
       GBA the engine then walks into pcmBuffer's zeros, but a host
       pointer read from mixed samples would fault. Clamp to the array. */
    s32 numChans = mixer->maxChans;
    if (numChans > MAX_DIRECTSOUND_CHANNELS) {
        numChans = MAX_DIRECTSOUND_CHANNELS;
    }
    struct SoundChannel *chan = mixer->chans;

    for (int i = 0; i < numChans; i++, chan++) {
        struct WaveData *wav = chan->wav;

        if (scanlineLimit != 0) {
            u16 vcount = REG_VCOUNT;
            if (vcount < VCOUNT_VBLANK) {
                vcount += TOTAL_SCANLINES;
            }
            if (vcount >= scanlineLimit) {
                goto returnEarly;
            }
        }

        if (TickEnvelope(chan, wav)) {
            GenerateAudio(mixer, chan, wav, pcmBuffer, samplesPerFrame, sampleRateReciprocal);
        }
    }
returnEarly:
    mixer->ident = ID_NUMBER;
}

// The pseudo-echo tail lib/m4a_1.s enters when release or a zero sustain
// runs the envelope down: the volume jumps to pseudoEchoVolume and holds
// for pseudoEchoLength frames; a zero echo volume ends the note.
static int StartPseudoEcho(struct SoundChannel *chan)
{
    u8 echoVol = chan->pseudoEchoVolume;

    if (echoVol == 0) {
        chan->statusFlags = 0;
        return FALSE;
    }
    chan->envelopeVolume = echoVol;
    chan->statusFlags |= SOUND_CHANNEL_SF_IEC;
    return TRUE;
}

// Returns TRUE if channel is still active after moving envelope forward a frame
static int TickEnvelope(struct SoundChannel *chan, struct WaveData *wav)
{
    // MP2K envelope shape
    //                                                                 |
    // (linear)^                                                       |
    // Attack / \Decay (exponential)                                   |
    //       /   \_                                                    |
    //      /      '.,        Sustain                                  |
    //     /          '.______________                                 |
    //    /                           '-.       Echo (linear)          |
    //   /                 Release (exp) ''--..|\                      |
    //  /                                        \                     |

    u8 status = chan->statusFlags;
    if ((status & SOUND_CHANNEL_SF_ON) == 0) {
        return FALSE;
    }

    u8 env = 0;
    if ((status & SOUND_CHANNEL_SF_START) == 0) {
        env = chan->envelopeVolume;

        if (status & SOUND_CHANNEL_SF_IEC) {
            // Note-wise echo: lib/m4a_1.s decrements the length and keeps
            // going only while the old value was above 1 (subs; bhi), so a
            // length of 0 ends the note rather than wrapping to 255.
            u8 len = chan->pseudoEchoLength;

            chan->pseudoEchoLength = len - 1;
            if (len > 1)
                return TRUE;
            chan->statusFlags = 0;
            return FALSE;
        } else if (status & SOUND_CHANNEL_SF_STOP) {
            // Release
            chan->envelopeVolume = env * chan->release / 256U;
            if (chan->envelopeVolume > chan->pseudoEchoVolume)
                return TRUE;
            return StartPseudoEcho(chan);
        }

        switch (status & SOUND_CHANNEL_SF_ENV) {
            u16 newEnv;
            case 2:
                // Decay
                chan->envelopeVolume = env * chan->decay / 256U;

                u8 sustain = chan->sustain;
                if (chan->envelopeVolume <= sustain && sustain == 0) {
                    return StartPseudoEcho(chan);
                } else if (chan->envelopeVolume <= sustain) {
                    chan->envelopeVolume = sustain;
                    --chan->statusFlags;
                }
                break;
            case 3:
            attack:
                newEnv = env + chan->attack;
                // lib/m4a_1.s: cmp 0xFF; bcc -- reaching 255 ends the attack.
                if (newEnv >= 0xFF) {
                    chan->envelopeVolume = 0xFF;
                    --chan->statusFlags;
                } else {
                    chan->envelopeVolume = newEnv;
                }
                break;
            case 1: // Sustain
            default:
                break;
        }

        return TRUE;
    } else if (status & SOUND_CHANNEL_SF_STOP) {
        // Init and stop cancel each other out
        chan->statusFlags = 0;
        return FALSE;
    } else {
        // Init channel
        chan->statusFlags = SOUND_CHANNEL_SF_ENV_ATTACK;
        chan->currentPointer = wav->data;
        chan->count = wav->size;
        chan->fw = 0;
        chan->envelopeVolume = 0;
        if ((wav->status >> 8) & 0xC0) {
            chan->statusFlags |= SOUND_CHANNEL_SF_LOOP;
        }
        goto attack;
    }
}

static void GenerateAudio(struct SoundInfo *mixer, struct SoundChannel *chan, struct WaveData *wav, fixed8_24 *pcmBuffer,
                          s32 samplesPerFrame, float sampleRateReciprocal)
{
    u8 v = chan->envelopeVolume * (mixer->masterVolume + 1) / 16U;
    chan->envelopeVolumeRight = chan->rightVolume * v / 256U;
    chan->envelopeVolumeLeft = chan->leftVolume * v / 256U;

    s32 loopLen = 0;
    s8 *loopStart;
    if (chan->statusFlags & SOUND_CHANNEL_SF_LOOP) {
        loopStart = wav->data + wav->loopStart;
        loopLen = wav->size - wav->loopStart;
    }
    s32 samplesLeftInWav = chan->count;
    s8 *current = chan->currentPointer;

    fixed8_24 envR = chan->envelopeVolumeRight << 9; // (* 32768)
    fixed8_24 envL = chan->envelopeVolumeLeft << 9;

    /* lib/m4a_1.s's SoundMainRAM picks this path with `tst r0, #8`
       (TONEDATA_TYPE_FIX: samples played at the mix rate), not sa2's
       TONEDATA_TYPE_CGB mask. */
    if (chan->type & TONEDATA_TYPE_FIX) {
        for (s32 i = 0; i < samplesPerFrame; i++, pcmBuffer += 2) {
            s8 c = *(current++);

            // Creates a value between -32768 and 32768
            // So shift by 9 to make this between -1 and 1
            // in 8.24
            pcmBuffer[1] += (c * envR);
            pcmBuffer[0] += (c * envL);
            if (--samplesLeftInWav == 0) {
                samplesLeftInWav = loopLen;
                if (loopLen != 0) {
                    current = loopStart;
                } else {
                    chan->statusFlags = 0;
                    return;
                }
            }
        }

        chan->count = samplesLeftInWav;
        chan->currentPointer = current;
    } else {
        fixed8_24 finePos = chan->fw;
        fixed8_24 romSamplesPerOutputSample = float_to_fp8_24(chan->frequency * sampleRateReciprocal);

        s16 b = current[0];
        s16 m = current[1] - b;
        current += 1;

        for (s32 i = 0; i < samplesPerFrame; i++, pcmBuffer += 2) {
            // Use linear interpolation to calculate a value between the current sample in the wav
            // and the next sample. Also cancel out the 9.23 stuff
            s32 sample = (s32)fp8_24_to_u32((long long)finePos * m) + b;

            pcmBuffer[1] += (sample * envR);
            pcmBuffer[0] += (sample * envL);

            finePos += romSamplesPerOutputSample;
            u32 newCoarsePos = fp8_24_to_u32(finePos);
            if (newCoarsePos != 0) {
                finePos = fp8_24_fractional_part(finePos);
                samplesLeftInWav -= newCoarsePos;
                if (samplesLeftInWav <= 0) {
                    if (loopLen != 0) {
                        current = loopStart;
                        newCoarsePos = -samplesLeftInWav;
                        samplesLeftInWav += loopLen;
                        while (samplesLeftInWav <= 0) {
                            newCoarsePos -= loopLen;
                            samplesLeftInWav += loopLen;
                        }
                        b = current[newCoarsePos];
                        m = current[newCoarsePos + 1] - b;
                        current += newCoarsePos + 1;
                    } else {
                        chan->statusFlags = 0;
                        return;
                    }
                } else {
                    b = current[newCoarsePos - 1];
                    m = current[newCoarsePos] - b;
                    current += newCoarsePos;
                }
            }
        }

        chan->fw = finePos;
        chan->count = samplesLeftInWav;
        chan->currentPointer = current - 1;
    }
}

void SoundMainBTM(void *ptr) { CpuFill32(0, ptr, offsetof(struct MusicPlayerTrack, cmdPtr)); }

// Removes chan from the doubly-linked list of channels associated with chan->track.
void RealClearChain(struct SoundChannel *chan)
{
    struct MusicPlayerTrack *track = chan->track;
    if (chan->track == NULL) {
        return;
    }
    struct SoundChannel *next = chan->nextChannelPointer;
    struct SoundChannel *prev = chan->prevChannelPointer;

    if (prev != NULL) {
        prev->nextChannelPointer = next;
    } else {
        track->chan = next;
    }

    if (next != NULL) {
        next->prevChannelPointer = prev;
    }

    chan->track = NULL;
}

static u8 ConsumeTrackByte(struct MusicPlayerTrack *track) { return *track->cmdPtr++; }

void MPlayJumpTableCopy(MPlayFunc *mplayJumpTable)
{
    /* The ROM template (data/rom_0801CF88.s) that lib/m4a_1.s's
       MPlayJumpTableCopy copies word by word: 0x24 entries. The label
       is asm-defined, so it carries no host C prefix. */
    extern const MPlayFunc gMPlayJumpTableTemplate[0x24] __asm__("gMPlayJumpTableTemplate");
    int i;

    for (i = 0; i < 0x24; i++)
        mplayJumpTable[i] = gMPlayJumpTableTemplate[i];
}

// Ends the current track. (Fine as in the Italian musical word, not English)
void ply_fine(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    struct SoundChannel *chan;
    for (chan = track->chan; chan != NULL; chan = chan->nextChannelPointer) {
        if (chan->statusFlags & SOUND_CHANNEL_SF_ON) {
            chan->statusFlags |= SOUND_CHANNEL_SF_STOP;
        }
        ClearChain(chan);
    }
    track->flags = 0;
}

// Sets the track's cmdPtr to the specified address. The stream stores it
// as an offset from the field (mRelPtr, asm/macros/portable.inc).
void ply_goto(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    u8 *cmdPtr = track->cmdPtr;
    intptr_t offset;

    memcpy(&offset, cmdPtr, sizeof(offset));
    track->cmdPtr = cmdPtr + offset;
}

// Sets the track's cmdPtr to the specified address after backing up its current position.
void ply_patt(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    u8 level = track->patternLevel;
    if (level < 3) {
        track->patternStack[level] = track->cmdPtr + sizeof(u8 *);
        track->patternLevel++;
        ply_goto(unused, track);
    } else {
        // Stop playing this track, as an indication to the music programmer that they need to quit
        // nesting patterns so darn much.
        ply_fine(unused, track);
    }
}

// Marks the end of the current pattern, if there is one, by resetting the pattern to the
// most recently saved value.
void ply_pend(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    if (track->patternLevel != 0) {
        u8 index = --track->patternLevel;
        track->cmdPtr = track->patternStack[index];
    }
}

// Loops back until a REPT event has been reached the specified number of times
void ply_rept(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    if (*track->cmdPtr == 0) {
        // "Repeat 0 times" == loop forever
        track->cmdPtr++;
        ply_goto(unused, track);
    } else {
        u8 repeatCount = ++track->repN;
        if (repeatCount < ConsumeTrackByte(track)) {
            ply_goto(unused, track);
        } else {
            track->repN = 0;
            /* ConsumeTrackByte already stepped past the count byte;
               m4a_1.s adds 5 from the byte BEFORE it (orig+1+4). */
            track->cmdPtr += sizeof(u8 *);
        }
    }
}

// Sets the note priority for new notes in this track.
void ply_prio(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track) { track->priority = ConsumeTrackByte(track); }

// Sets the BPM of all tracks to the specified tempo (in beats per half-minute, because 255 as a max tempo
// kinda sucks but 510 is plenty).
void ply_tempo(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u16 bpm = ConsumeTrackByte(track);
    bpm *= 2;
    mplayInfo->tempoD = bpm;
    mplayInfo->tempoI = (bpm * mplayInfo->tempoU) >> 8;
}

void ply_keysh(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->keyShift = ConsumeTrackByte(track);
    track->flags |= MPT_FLG_PITCHG;
}

void ply_voice(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u8 voice = *(track->cmdPtr++);
    track->tone = mplayInfo->tone[voice];
}

void ply_vol(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->vol = ConsumeTrackByte(track);
    track->flags |= MPT_FLG_VOLCHG;
}

void ply_pan(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->pan = ConsumeTrackByte(track) - 0x40;
    track->flags |= MPT_FLG_VOLCHG;
}

void ply_bend(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->bend = ConsumeTrackByte(track) - 0x40;
    track->flags |= MPT_FLG_PITCHG;
}

void ply_bendr(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->bendRange = ConsumeTrackByte(track);
    track->flags |= MPT_FLG_PITCHG;
}

void ply_lfodl(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track) { track->lfoDelay = ConsumeTrackByte(track); }

void ply_modt(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    u8 type = ConsumeTrackByte(track);
    if (type != track->modT) {
        track->modT = type;
        track->flags |= MPT_FLG_VOLCHG | MPT_FLG_PITCHG;
    }
}

void ply_tune(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tune = ConsumeTrackByte(track) - 0x40;
    track->flags |= MPT_FLG_PITCHG;
}

void ply_port(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    vu8 *offset = (vu8 *)(REG_ADDR_NR10 + *(track->cmdPtr++));
    *offset = ConsumeTrackByte(track);
}

// lib/m4a_1.s's clear_modM; the C half's ClearModM (sub_08002238) sits
// in src/dead/, which the port does not build.
static void ClearModM(struct MusicPlayerTrack *track)
{
    track->modM = 0;
    track->lfoSpeedC = 0;

    if (track->modT == 0)
        track->flags |= MPT_FLG_PITCHG;
    else
        track->flags |= MPT_FLG_VOLCHG;
}

void ply_lfos(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->lfoSpeed = *(track->cmdPtr++);
    if (track->lfoSpeed == 0) {
        ClearModM(track);
    }
}

void ply_mod(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->mod = *(track->cmdPtr++);
    if (track->mod == 0) {
        ClearModM(track);
    }
}

void ply_endtie(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    u8 key = *track->cmdPtr;
    if (key < 0x80) {
        track->key = key;
        track->cmdPtr++;
    } else {
        key = track->key;
    }

    struct SoundChannel *chan = track->chan;
    while (chan != NULL) {
        if ((chan->statusFlags & (SOUND_CHANNEL_SF_START | SOUND_CHANNEL_SF_ENV))
            && (chan->statusFlags & SOUND_CHANNEL_SF_STOP) == 0
            && chan->midiKey == key) {
            chan->statusFlags |= SOUND_CHANNEL_SF_STOP;
            return;
        }
        chan = chan->nextChannelPointer;
    }
}

void MPlayMain(struct MusicPlayerInfo *mplayInfo)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    u32 i;
    struct MusicPlayerTrack *track;

    if (mplayInfo->ident != ID_NUMBER) {
        return;
    }
    mplayInfo->ident = mplayInfo->ident + 1;

    if (mplayInfo->MPlayMainNext != NULL) {
        mplayInfo->MPlayMainNext(mplayInfo->musicPlayerNext);
    }

    if (mplayInfo->status & MUSICPLAYER_STATUS_PAUSE) {
        goto returnEarly;
    }
    FadeOutBody(mplayInfo);
    /* This ROM's revision does not re-check MUSICPLAYER_STATUS_PAUSE
       after FadeOutBody (lib/m4a_1.s difference 4). */

    mplayInfo->tempoC += mplayInfo->tempoI;
    while (mplayInfo->tempoC >= 150) {
        u16 trackBits = 0;

        for (i = 0; i < mplayInfo->trackCount; i++) {
            struct SoundChannel *chan;
            track = mplayInfo->tracks + i;
            if ((track->flags & MPT_FLG_EXIST) == 0) {
                continue;
            }
            trackBits |= (1 << i);

            chan = track->chan;
            while (chan != NULL) {
                if ((chan->statusFlags & SOUND_CHANNEL_SF_ON) == 0) {
                    ClearChain(chan);
                } else if (chan->gateTime != 0 && --chan->gateTime == 0) {
                    chan->statusFlags |= SOUND_CHANNEL_SF_STOP;
                }
                chan = chan->nextChannelPointer;
            }

            if (track->flags & MPT_FLG_START) {
                Clear64byte(track);
                track->flags = MPT_FLG_EXIST;
                track->bendRange = 2;
                track->volX = 64;
                track->lfoSpeed = 22;
                track->tone.type = 1;
            }

            while (track->wait == 0) {
                u8 event = *track->cmdPtr;
                if (event < 0x80) {
                    event = track->runningStatus;
                } else {
                    track->cmdPtr++;
                    if (event >= 0xBD) {
                        track->runningStatus = event;
                    }
                }

                if (event >= 0xCF) {
                    soundInfo->plynote(event - 0xCF, mplayInfo, track);
                } else if (event > 0xB0) {
                    void (*eventFunc)(struct MusicPlayerInfo *, struct MusicPlayerTrack *);

                    mplayInfo->cmd = event - 0xB1;
                    eventFunc = (void (*)(struct MusicPlayerInfo *, struct MusicPlayerTrack *))soundInfo->MPlayJumpTable[mplayInfo->cmd];
                    eventFunc(mplayInfo, track);

                    if (track->flags == 0) {
                        goto nextTrack;
                    }
                } else {
                    track->wait = gClockTable[event - 0x80];
                }
            }

            track->wait--;

            if (track->lfoSpeed != 0 && track->mod != 0) {
                if (track->lfoDelayC != 0) {
                    track->lfoDelayC--;
                    goto nextTrack;
                }

                track->lfoSpeedC += track->lfoSpeed;

                s8 r;
                if (track->lfoSpeedC >= 0x40 && track->lfoSpeedC < 0xC0) {
                    r = 128 - track->lfoSpeedC;
                } else if (track->lfoSpeedC >= 0xC0) {
                    // Unsigned -> signed casts where the value is out of range are implementation defined.
                    // Why not add a few extra lines to make behavior the same for literally everyone?
                    r = track->lfoSpeedC - 256;
                } else {
                    r = track->lfoSpeedC;
                }
                r = FLOOR_DIV_POW2(track->mod * r, 64);

                if (r != (s8)track->modM) {
                    track->modM = r;
                    if (track->modT == 0) {
                        track->flags |= MPT_FLG_PITCHG;
                    } else {
                        track->flags |= MPT_FLG_VOLCHG;
                    }
                }
            }

        nextTrack:;
        }

        mplayInfo->clock++;
        if (trackBits == 0) {
            mplayInfo->status = MUSICPLAYER_STATUS_PAUSE;
            goto returnEarly;
        }
        mplayInfo->status = trackBits;
        mplayInfo->tempoC -= 150;
    }

    for (i = 0; i < mplayInfo->trackCount; i++) {
        struct SoundChannel *chan;

        track = mplayInfo->tracks + i;

        if ((track->flags & MPT_FLG_EXIST) == 0 || (track->flags & 0xF) == 0) {
            continue;
        }
        TrkVolPitSet(mplayInfo, track);
        for (chan = track->chan; chan != NULL; chan = chan->nextChannelPointer) {
            u8 cgbType;
            if ((chan->statusFlags & SOUND_CHANNEL_SF_ON) == 0) {
                ClearChain(chan);
                continue;
            }
            cgbType = chan->type & TONEDATA_TYPE_CGB;
            if (track->flags & MPT_FLG_VOLCHG) {
                ChnVolSetAsm(chan, track);
                if (cgbType != 0) {
                    ((struct CgbChannel *)chan)->modify |= CGB_CHANNEL_MO_VOL;
                }
            }
            if (track->flags & MPT_FLG_PITCHG) {
                s32 key = (s32)chan->key + (s32)(s8)track->keyM;
                if (key < 0) {
                    key = 0;
                }
                if (cgbType != 0) {
                    struct CgbChannel *cgbChan = (struct CgbChannel *)chan;

                    cgbChan->frequency = soundInfo->MidiKeyToCgbFreq(cgbType, key, track->pitM);
                    cgbChan->modify |= CGB_CHANNEL_MO_PIT;
                } else {
                    chan->frequency = MidiKeyToFreq(chan->wav, key, track->pitM);
                }
            }
        }
        track->flags &= 0xF0;
    }
returnEarly:;
    mplayInfo->ident = ID_NUMBER;
}

void TrackStop(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;

    if (track->flags & MPT_FLG_EXIST) {
        struct SoundChannel *chan;
        for (chan = track->chan; chan != NULL; chan = chan->nextChannelPointer) {
            if (chan->statusFlags != 0) {
                u8 cgbType = chan->type & TONEDATA_TYPE_CGB;
                if (cgbType != 0) {
                    soundInfo->CgbOscOff(cgbType);
                }
                chan->statusFlags = 0;
            }
            chan->track = NULL;
        }
        track->chan = NULL;
    }
}

static void ChnVolSetAsm(struct SoundChannel *chan, struct MusicPlayerTrack *track)
{
    s8 forcedPan = chan->rhythmPan;
    u32 rightVolume = (u8)(forcedPan + 128) * chan->velocity * track->volMR / 128 / 128;
    if (rightVolume > 0xFF) {
        rightVolume = 0xFF;
    }
    chan->rightVolume = rightVolume;

    u32 leftVolume = (u8)(127 - forcedPan) * chan->velocity * track->volML / 128 / 128;
    if (leftVolume > 0xFF) {
        leftVolume = 0xFF;
    }
    chan->leftVolume = leftVolume;
}

void ply_note(u32 clock, struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    struct SoundInfo *soundInfo = SOUND_INFO_PTR;
    struct ToneData *tone;
    struct SoundChannel *chan;
    u8 key;
    u8 type;
    u16 priority;
    u8 cgbType;
    s8 forcedPan = 0;

    // A note can be anywhere from 1 to 4 bytes long. First is always the note length...
    track->gateTime = gClockTable[clock];
    if (*track->cmdPtr < 0x80) {
        // Then the note name...
        track->key = *(track->cmdPtr++);
        if (*track->cmdPtr < 0x80) {
            // Then the velocity...
            track->velocity = *(track->cmdPtr++);
            if (*track->cmdPtr < 0x80) {
                // Then a number to add ticks to get exotic or more precise note lengths without TIE.
                track->gateTime += *(track->cmdPtr++);
            }
        }
    }

    tone = &track->tone;
    key = track->key;
    type = tone->type;

    if (type & (TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL)) {
        u8 voicegroupIndex;
        if (type & TONEDATA_TYPE_SPL) {
            voicegroupIndex = tone->keySplitTable[track->key];
        } else {
            voicegroupIndex = track->key;
        }

        tone = tone->keySplitGroup + voicegroupIndex;
        if (tone->type & (TONEDATA_TYPE_RHY | TONEDATA_TYPE_SPL)) {
            return;
        }
        if (type & TONEDATA_TYPE_RHY) {
            if (tone->pan_sweep & 0x80) {
                forcedPan = ((s8)(tone->pan_sweep & 0x7F) - 0x40) * 2;
            }
            key = tone->key;
        }
    }

    priority = mplayInfo->priority + track->priority;
    if (priority > 0xFF) {
        priority = 0xFF;
    }

    cgbType = tone->type & TONEDATA_TYPE_CGB;

    /* A direct-sound voice with no wav is the ROM's own junk: the drum
       track's rhythm group overlays the jump-table template's words
       (voicegroups.s), so the notes it fires carry table bytes where a
       WaveData pointer belongs. On the GBA every address is readable and
       the note resolves to open-bus samples; the hosted dummy group gives
       these voices wav == NULL, and anything else that small would fault.
       Skip the note before a channel is chosen, so no channel that was
       playing is left active with a NULL wav. */
    if (cgbType == 0 && tone->wav == NULL) {
        track->flags &= ~0xF;
        return;
    }

    if (cgbType != 0) {
        struct CgbChannel *cgbChan;
        if (soundInfo->cgbChans == NULL) {
            return;
        }
        // There's only one CgbChannel of a given type, so we don't need to loop to find it.
        cgbChan = soundInfo->cgbChans + cgbType - 1;
        chan = (struct SoundChannel *)cgbChan;

        // If this channel is running and not stopped,
        if ((chan->statusFlags & SOUND_CHANNEL_SF_ON) && (chan->statusFlags & SOUND_CHANNEL_SF_STOP) == 0) {
            // then make sure this note is higher priority (or same priority but from a later track).
            if (chan->priority > priority || (chan->priority == priority && (uintptr_t)chan->track < (uintptr_t)track)) {
                return;
            }
        }
    } else {
        u16 p = priority;
        struct MusicPlayerTrack *t = track;
        u8 foundStoppingChannel = FALSE;
        chan = NULL;
        /* See SampleMixer: the mode word's fourteen channels exceed the
           array, so the search stops at MAX_DIRECTSOUND_CHANNELS. */
        u8 numChans = soundInfo->maxChans;
        struct SoundChannel *currChan = soundInfo->chans;
        if (numChans > MAX_DIRECTSOUND_CHANNELS) {
            numChans = MAX_DIRECTSOUND_CHANNELS;
        }

        for (u8 i = 0; i < numChans; i++, currChan++) {
            if ((currChan->statusFlags & SOUND_CHANNEL_SF_ON) == 0) {
                // Hey, we found a completely inactive channel! Let's use that.
                chan = currChan;
                break;
            }

            if ((currChan->statusFlags & SOUND_CHANNEL_SF_STOP) && !foundStoppingChannel) {
                // In the absence of a completely finalized channel, we can take over one that's about to
                // finalize. That's a tier above any channel that's currently playing a note.
                foundStoppingChannel = TRUE;
                p = currChan->priority;
                t = currChan->track;
                chan = currChan;
            } else if ((currChan->statusFlags & SOUND_CHANNEL_SF_STOP && foundStoppingChannel)
                       || ((currChan->statusFlags & SOUND_CHANNEL_SF_STOP) == 0 && !foundStoppingChannel)) {
                // The channel we're checking is on the same tier, so check the priority and track order
                if (currChan->priority < p) {
                    p = currChan->priority;
                    t = currChan->track;
                    chan = currChan;
                } else if (currChan->priority == p && (uintptr_t)currChan->track > (uintptr_t)t) {
                    t = currChan->track;
                    chan = currChan;
                } else if (currChan->priority == p && currChan->track == t) {
                    chan = currChan;
                }
            }
        }
    }

    if (chan == NULL) {
        return;
    }

    ClearChain(chan);

    chan->prevChannelPointer = NULL;
    chan->nextChannelPointer = (struct SoundChannel *)track->chan;
    if (track->chan != NULL) {
        track->chan->prevChannelPointer = chan;
    }
    track->chan = chan;
    chan->track = track;

    track->lfoDelayC = track->lfoDelay;
    if (track->lfoDelay != 0) {
        ClearModM(track);
    }
    TrkVolPitSet(mplayInfo, track);

    /* The GBA asm sets gateTime, midiKey, velocity and priority with one
       word store from the track and the echo pair with one halfword
       store; field by field is the same bytes. */
    chan->gateTime = track->gateTime;
    chan->midiKey = track->key;
    chan->velocity = track->velocity;
    chan->priority = priority;
    chan->key = key;
    chan->rhythmPan = forcedPan;
    chan->type = tone->type;
    chan->wav = tone->wav;
    /* Hosted square and noise voices carry their duty/period in
       ToneData.duty with wav NULL (m4a_internal.h); CgbSound reads it
       back through wavePointer, so route it through that slot. Wave
       voices (channel 3) keep the real WaveData pointer above. */
    if (cgbType == 1 || cgbType == 2 || cgbType == 4) {
        chan->wav = (struct WaveData *)(uintptr_t)tone->duty;
    }
    chan->attack = tone->attack;
    chan->decay = tone->decay;
    chan->sustain = tone->sustain;
    chan->release = tone->release;
    chan->pseudoEchoVolume = track->pseudoEchoVolume;
    chan->pseudoEchoLength = track->pseudoEchoLength;
    ChnVolSetAsm(chan, track);

    // Avoid promoting keyM to u8 by splitting the addition into a separate statement
    s16 transposedKey = chan->key;
    transposedKey += (s8)track->keyM;
    if (transposedKey < 0) {
        transposedKey = 0;
    }

    if (cgbType != 0) {
        struct CgbChannel *cgbChan = (struct CgbChannel *)chan;

        cgbChan->length = tone->length;
        if (tone->pan_sweep & 0x80 || (tone->pan_sweep & 0x70) == 0) {
            cgbChan->sweep = 8;
        } else {
            cgbChan->sweep = tone->pan_sweep;
        }

        cgbChan->frequency = soundInfo->MidiKeyToCgbFreq(cgbType, transposedKey, track->pitM);
    } else {
        chan->frequency = MidiKeyToFreq(chan->wav, transposedKey, track->pitM);
    }

    chan->statusFlags = SOUND_CHANNEL_SF_START;
    track->flags &= ~0xF;
}

void m4aSoundVSync(void)
{
    struct SoundInfo *mixer = SOUND_INFO_PTR;
    if (mixer->ident - ID_NUMBER <= 1) {
        s32 samplesPerFrame = mixer->pcmSamplesPerVBlank * 2;
        fixed8_24 *m4aBuffer = mixer->pcmBuffer;
        fixed8_24 *cgbBuffer = cgb_get_buffer();
        s32 dmaCounter = mixer->pcmDmaCounter;

        if (dmaCounter > 1) {
            m4aBuffer += samplesPerFrame * (mixer->pcmDmaPeriod - (dmaCounter - 1));
        }

        for (u32 i = 0; i < samplesPerFrame; i++) {
            // Sample is fixed 8.24 with a value of -1 to 1
            // but when we add we divide by 8 to add some headroom
            // and make the mix a much more managable volume
            fixed8_24 sample = (m4aBuffer[i] + cgbBuffer[i]) >> 3;

            // 1 in 8.24 format is 1 << 24
            // 32768 is size expected for s16 audio
            // 32768 = 1 << 15
            // 24 - 15 = 9
            /* twelve full-scale channels overflow s16 even after the
               >>3 headroom; clamp so wraparound cannot invert peaks */
            sample >>= 9;
            if (sample > 32767)
                sample = 32767;
            else if (sample < -32768)
                sample = -32768;
            audioBuffer[i] = sample;
        }

        Platform_QueueAudio(audioBuffer, samplesPerFrame * sizeof(s16));
        if ((s8)(--mixer->pcmDmaCounter) <= 0)
            mixer->pcmDmaCounter = mixer->pcmDmaPeriod;
    }
}
