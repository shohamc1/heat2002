#ifndef GUARD_GBA_M4A_INTERNAL_H
#define GUARD_GBA_M4A_INTERNAL_H

// Internal layout of the MP2K/m4a sound engine that this ROM runs, in both
// its low copy (near 0x08000260) and its high copy (near 0x08339920). See
// docs/m4a-map.md for which decompiled sub_* file is which engine function,
// and docs/learnings/parked.md's "m4a engine is duplicated" section for
// background on the two copies.
//
// Every field offset below was checked against the raw offset casts the
// engine's decompiled files already use (SoundInit, MPlayExtender,
// MPlayOpen, MPlayStart, m4aSoundMode, m4aSoundVSyncOn/Off,
// m4aMPlayStop, m4aMPlayPitchControl, ClearChain, Clear64byte, in both
// copies), not assumed from an upstream header. They matched exactly.
//
// This ROM's engine ident is 0x68736D53 ('Smsh'), the same ID_NUMBER used
// while the struct layouts below were checked, so no field was reordered
// or repadded to fit this ROM.

#include "gba/defines.h"
#include "gba/io_reg.h"

// ASCII encoding of 'Smsh' in reverse.
#define ID_NUMBER 0x68736D53

#define SOUND_MODE_REVERB_VAL   0x0000007F
#define SOUND_MODE_REVERB_SET   0x00000080
#define SOUND_MODE_MAXCHN       0x00000F00
#define SOUND_MODE_MAXCHN_SHIFT 8
#define SOUND_MODE_MASVOL       0x0000F000
#define SOUND_MODE_MASVOL_SHIFT 12
#define SOUND_MODE_FREQ_13379   0x00040000
#define SOUND_MODE_FREQ         0x000F0000
#define SOUND_MODE_FREQ_SHIFT   16
#define SOUND_MODE_DA_BIT       0x00B00000
#define SOUND_MODE_DA_BIT_SHIFT 20

// ToneData.type's flag bits (lib/m4a_constants.inc's TONEDATA_TYPE_*).
#define TONEDATA_TYPE_CGB 0x07 // compatible sound, channel number 1-4
#define TONEDATA_TYPE_FIX 0x08 // fixed frequency (samples at the mix rate)
#define TONEDATA_TYPE_SPL 0x40 // key split
#define TONEDATA_TYPE_RHY 0x80 // rhythm

// A channel is live when any of these is set (lib/m4a_1.s's SoundMain
// tests statusFlags against exactly this mask before ticking a channel).
#define SOUND_CHANNEL_SF_ON (SOUND_CHANNEL_SF_START | SOUND_CHANNEL_SF_STOP | SOUND_CHANNEL_SF_IEC | SOUND_CHANNEL_SF_ENV)

// The hosted mixer's fixed-point sample type:
// 8 integer bits, 24 fractional, [-1, 1) full scale. The macros are the
// only float-touching spots the port's mixer needs. fp8_24_to_u32 must
// shift BEFORE any narrowing: GenerateAudio feeds it an s64 product that
// can be negative, whose floor the arithmetic shift gives directly.
typedef s32 fixed8_24;
#define float_to_fp8_24(value)        ((fixed8_24)((value) * 16777216.0f))
#define u32_to_fp8_24(value)          ((value) << 24)
#define fp8_24_to_u32(value)          ((value) >> 24)
#define fp8_24_fractional_part(value) ((value) & 0xFFFFFF)

struct WaveData
{
    u16 type;
    u16 status;
    u32 freq;
    u32 loopStart;
    u32 size; // number of samples
    s8 data[1]; // samples
};

// GBA: one 12-byte voice-group record, the exact layout the engine's
// hand-written asm reads (lib/m4a_constants.inc's o_ToneData_* fields)
// and asm/macros/music_voice.inc emits. A keysplit record overlays its
// two pointers on wav and attack (o_MusicPlayerTrack_ToneData_
// keySplitTable == ..._attack in lib/m4a_constants.inc), and a square or
// noise voice carries its duty cycle or period in wav's first byte.
//
// Hosted: the same record as asm/macros/music_voice.inc
// emits it there, a uniform 24 bytes so a voice group is a plain array:
// type/key/length/pan_sweep at 0-3, the duty/period byte at 4 (where the
// GBA record keeps it, as wav's first byte), pad to 8, then a union whose
// two shapes share the pointer slots -- directsound/wave reads wav at 8
// with the envelope at 16-19, keysplit reads its group pointer at 8 and
// its key-table pointer at 16 (the same attack alias the GBA layout
// uses). Anonymous unions and anonymous struct members are GNU
// extensions, which -std=gnu89 accepts.
//
// Square and noise voices set wav = NULL and carry their duty/period in
// duty alone; the CGB paths that read a duty through CgbChannel's
// wavePointer (CgbSound's NRx1/NR43 writes) get it because the hosted
// ply_note copies tone->duty into that slot for channels 1, 2 and 4
// (src/platform/shared/audio/m4a_sound_mixer.c). Only wave voices
// (channel 3) keep a real WaveData pointer there.
#if PORTABLE
struct ToneData
{
    /* 0x00 */ u8 type;
    /* 0x01 */ u8 key;
    /* 0x02 */ u8 length; // sound length (compatible sound)
    /* 0x03 */ u8 pan_sweep; // pan or sweep (compatible sound ch. 1)
    /* 0x04 */ u8 duty; // square duty / noise period (GBA: wav byte 0)
    /* 0x05 */ u8 pad05[3];
    /* 0x08 */ union
    {
        struct
        {
            struct WaveData *wav;
            /* 0x10 */ u8 attack;
            u8 decay;
            u8 sustain;
            u8 release;
            u8 tail[4]; // pad to the 24-byte stride
        };
        struct
        {
            struct ToneData *keySplitGroup;
            u8 *keySplitTable;
        };
    };
};
#else
struct ToneData
{
    u8 type;
    u8 key;
    u8 length; // sound length (compatible sound)
    u8 pan_sweep; // pan or sweep (compatible sound ch. 1)
    struct WaveData *wav;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};
#endif

#define SOUND_CHANNEL_SF_START       0x80
#define SOUND_CHANNEL_SF_STOP        0x40
#define SOUND_CHANNEL_SF_LOOP        0x10
#define SOUND_CHANNEL_SF_IEC         0x04
#define SOUND_CHANNEL_SF_ENV         0x03
#define SOUND_CHANNEL_SF_ENV_ATTACK  0x03
#define SOUND_CHANNEL_SF_ENV_DECAY   0x02
#define SOUND_CHANNEL_SF_ENV_SUSTAIN 0x01
#define SOUND_CHANNEL_SF_ENV_RELEASE 0x00

#define CGB_CHANNEL_MO_PIT  0x02
#define CGB_CHANNEL_MO_VOL  0x01

#define CGB_NRx2_ENV_DIR_DEC 0x00
#define CGB_NRx2_ENV_DIR_INC 0x08

struct MusicPlayerTrack;

// Confirmed against MPlayExtender: type is at offset 0x1 and panMask is at
// offset 0x1C for all four channels it initialises (0x00, 0x40, 0x80, 0xC0
// apart), and CpuFill32 zeroes exactly sizeof(struct CgbChannel) * 4
// (0x100) bytes starting at this struct's array.
struct CgbChannel
{
    u8 statusFlags;
    u8 type;
    u8 rightVolume;
    u8 leftVolume;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 key;
    u8 envelopeVolume;
    u8 envelopeGoal;
    u8 envelopeCounter;
    u8 pseudoEchoVolume;
    u8 pseudoEchoLength;
    u8 dummy1;
    u8 dummy2;
    u8 gateTime;
    u8 midiKey;
    u8 velocity;
    u8 priority;
    u8 rhythmPan;
    u8 dummy3[3];
    u8 dummy5;
    u8 sustainGoal;
    u8 n4;
    u8 pan;
    u8 panMask;
    u8 modify;
    u8 length;
    u8 sweep;
    u32 frequency;
    u32 *wavePointer;
    u32 *currentPointer;
    struct MusicPlayerTrack *track;
    void *prevChannelPointer;
    void *nextChannelPointer;
    u8 dummy4[8];
};

struct SoundChannel
{
    u8 statusFlags;
    u8 type;
    u8 rightVolume;
    u8 leftVolume;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 key;
    u8 envelopeVolume;
    u8 envelopeVolumeRight;
    u8 envelopeVolumeLeft;
    u8 pseudoEchoVolume;
    u8 pseudoEchoLength;
    u8 dummy1;
    u8 dummy2;
    u8 gateTime;
    u8 midiKey;
    u8 velocity;
    u8 priority;
    u8 rhythmPan;
    u8 dummy3[3];
    u32 count;
    u32 fw;
    u32 frequency;
    struct WaveData *wav;
    s8 *currentPointer;
    struct MusicPlayerTrack *track;
    void *prevChannelPointer;
    void *nextChannelPointer;
    u32 dummy4;
    u16 xpi;
    u16 xpc;
};

#define MAX_DIRECTSOUND_CHANNELS 12
// Size of the Direct Sound buffer, in samples per channel. The GBA keeps
// the hardware rate's 1584; the hosted mixer
// mixes 804-sample frames and sizes the ring for six of them, so the
// hosted build uses sa2's 4907. m4aSoundVSyncOn's and SoundInit's DMA
// register arithmetic is the only other reader, and those writes are
// inert on the host.
#if PORTABLE
#define PCM_DMA_BUF_SIZE 4907
#else
#define PCM_DMA_BUF_SIZE 1584
#endif

struct MusicPlayerInfo;

typedef void (*MPlayFunc)();
typedef void (*PlyNoteFunc)(u32, struct MusicPlayerInfo *, struct MusicPlayerTrack *);
typedef void (*CgbSoundFunc)(void);
typedef void (*CgbOscOffFunc)(u8);
typedef u32 (*MidiKeyToCgbFreqFunc)(u8, u8, u8);
typedef void (*ExtVolPitFunc)(void);
typedef void (*MPlayMainFunc)(struct MusicPlayerInfo *);

// Confirmed field by field against SoundInit (maxChans@6, masterVolume@7,
// CgbSound@0x28, CgbOscOff@0x2C, MidiKeyToCgbFreq@0x30, MPlayJumpTable@0x34,
// plynote@0x38, ExtVolPit@0x3C), MPlayOpen/MPlayStart (MPlayMainHead@0x20,
// musicPlayerHead@0x24), and m4aSoundVSyncOn/Off (ident@0, pcmDmaCounter@4,
// pcmBuffer@0x350, sized 0xC60 = PCM_DMA_BUF_SIZE * 2).
struct SoundInfo
{
    u32 ident;
    vu8 pcmDmaCounter;
    u8 reverb;
    u8 maxChans;
    u8 masterVolume;
    u8 freq;
    u8 mode;
    u8 c15;
    u8 pcmDmaPeriod;
    u8 maxLines;
    u8 gap[3];
    s32 pcmSamplesPerVBlank;
    s32 pcmFreq;
    s32 divFreq;
#if PORTABLE
    // The hosted mixer's resampling step, 1/sampleRate as a float (the
    // GBA's integer approximation of it is divFreq above, which the host
    // never reads). Set by SampleFreqSet's hosted branch.
    float sampleRateReciprocal;
#endif
    struct CgbChannel *cgbChans;
    MPlayMainFunc MPlayMainHead;
    struct MusicPlayerInfo *musicPlayerHead;
    CgbSoundFunc CgbSound;
    CgbOscOffFunc CgbOscOff;
    MidiKeyToCgbFreqFunc MidiKeyToCgbFreq;
    MPlayFunc *MPlayJumpTable;
    PlyNoteFunc plynote;
    ExtVolPitFunc ExtVolPit;
    u8 gap2[16];
    struct SoundChannel chans[MAX_DIRECTSOUND_CHANNELS];
#if PORTABLE
    // The hosted mixer accumulates fixed-point samples here (after sa2),
    // where the GBA buffers signed bytes for the FIFO DMAs.
    fixed8_24 pcmBuffer[PCM_DMA_BUF_SIZE * 2];
#else
    s8 ALIGNED(4) pcmBuffer[PCM_DMA_BUF_SIZE * 2];
#endif
};

// Confirmed against MPlayStart: trackCount@0, blockCount@1, priority@2,
// tone@4, part[]@8 (part[i] is read as songHeader->part[i] for the i-th
// track's initial command pointer).
struct SongHeader
{
    u8 trackCount;
    u8 blockCount;
    u8 priority;
    u8 reverb;
    struct ToneData *tone;
    u8 *part[1];
};

#define MPT_FLG_VOLSET 0x01
#define MPT_FLG_VOLCHG 0x03
#define MPT_FLG_PITSET 0x04
#define MPT_FLG_PITCHG 0x0C
#define MPT_FLG_START  0x40
#define MPT_FLG_EXIST  0x80

// Confirmed against MPlayStart/m4aMPlayPitchControl: flags@0 (0xC0 =
// MPT_FLG_EXIST|MPT_FLG_START set on start; |= 0x0C = MPT_FLG_PITCHG on
// pitch control), chan@0x20, cmdPtr@0x40, and against
// m4aMPlayPitchControl for keyShiftX@0xB and pitX@0xD.
struct MusicPlayerTrack
{
    u8 flags;
    u8 wait;
    u8 patternLevel;
    u8 repN;
    u8 gateTime;
    u8 key;
    u8 velocity;
    u8 runningStatus;
    u8 keyM;
    u8 pitM;
    s8 keyShift;
    s8 keyShiftX;
    s8 tune;
    u8 pitX;
    s8 bend;
    u8 bendRange;
    u8 volMR;
    u8 volML;
    u8 vol;
    u8 volX;
    s8 pan;
    s8 panX;
    s8 modM;
    u8 mod;
    u8 modT;
    u8 lfoSpeed;
    u8 lfoSpeedC;
    u8 lfoDelay;
    u8 lfoDelayC;
    u8 priority;
    u8 pseudoEchoVolume;
    u8 pseudoEchoLength;
    struct SoundChannel *chan;
    struct ToneData tone;
    u8 gap[10];
    u16 timer;
    u32 unk_3C;
    u8 *cmdPtr;
    u8 *patternStack[3];
};

#define MUSICPLAYER_STATUS_TRACK 0x0000ffff
#define MUSICPLAYER_STATUS_PAUSE 0x80000000

#define MAX_MUSICPLAYER_TRACKS 16

#define TEMPORARY_FADE  0x0001
#define FADE_IN         0x0002
#define FADE_VOL_MAX    64
#define FADE_VOL_SHIFT  2

// Confirmed against MPlayOpen/MPlayStart: status@4, trackCount@8, tracks@0x2C,
// MPlayMainNext@0x38, musicPlayerNext@0x3C, ident@0x34, tempoD@0x1C,
// tempoU@0x1E, tempoI@0x20, tempoC@0x22, fadeOI@0x24. fadeOC@0x26 and
// fadeOV@0x28 are confirmed against a fade-control setter (see
// docs/m4a-map.md for which sub_* — this ROM's revision doesn't set the
// TEMPORARY_FADE/FADE_IN status bits pret's split FadeIn/FadeOutTemporarily
// do, so the exact upstream match is not certain there).
struct MusicPlayerInfo
{
    struct SongHeader *songHeader;
    u32 status;
    u8 trackCount;
    u8 priority;
    u8 cmd;
    u8 unk_B;
    u32 clock;
    u8 gap[8];
    u8 *memAccArea;
    u16 tempoD;
    u16 tempoU;
    u16 tempoI;
    u16 tempoC;
    u16 fadeOI;
    u16 fadeOC;
    u16 fadeOV;
    struct MusicPlayerTrack *tracks;
    struct ToneData *tone;
    u32 ident;
    MPlayMainFunc MPlayMainNext;
    struct MusicPlayerInfo *musicPlayerNext;
};

void SoundInit(struct SoundInfo *soundInfo);
void MPlayExtender(struct CgbChannel *cgbChans);
void SampleFreqSet(u32 freq);
void m4aSoundMode(u32 mode);
void m4aSoundVSyncOn(void);
void m4aSoundVSyncOff(void);
void MPlayOpen(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *tracks, u32 trackCount);
void MPlayStart(struct MusicPlayerInfo *mplayInfo, struct SongHeader *songHeader);
void m4aMPlayStop(struct MusicPlayerInfo *mplayInfo);
void m4aMPlayPitchControl(struct MusicPlayerInfo *mplayInfo, u16 trackBits, s16 pitch);
void ClearChain(void *x);
void Clear64byte(void *x);
void TrackStop(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void FadeOutBody(struct MusicPlayerInfo *mplayInfo);
void TrkVolPitSet(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void MPlayJumpTableCopy(MPlayFunc *mplayJumpTable);

#endif // GUARD_GBA_M4A_INTERNAL_H
