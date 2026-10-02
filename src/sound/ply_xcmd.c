#include "global.h"
#include "functions.h"
#include "gba/m4a_internal.h"
#include "m4a.h"

/* ply_memacc. The whole function is one switch on the first operand byte;
 * luvdis left the jump table and every case body as .byte rows inside the
 * block, so its true extent runs to 0x08002496. This ROM's revision keeps
 * memAccArea at MusicPlayerInfo+0x18 (the header's gap[8] before it). */
#define MEMACC_COND_JUMP(cond) \
    if (cond)                  \
        goto cond_true;        \
    else                       \
        goto cond_false;
#define READ_XCMD_BYTE(var, n)         \
    {                                  \
        u32 byte = track->cmdPtr[(n)]; \
        byte <<= n * 8;                \
        (var) &= ~(0xFF << (n * 8));   \
        (var) |= byte;                 \
    }

/* ply_xcmd */
extern MPlayFunc gUnk_0801D230[];

/* ply_xxx */
/* ply_xwave */
/* ply_xtype */
/* ply_xatta */
/* ply_xdeca */
/* ply_xsust */
/* ply_xrele */
/* ply_xiecv */
/* ply_xiecl */
/* ply_xleng */
/* ply_xswee */
void ply_memacc(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 op;
    u8 *addr;
    u8 data;

    op = *track->cmdPtr;
    track->cmdPtr++;

    addr = mplayInfo->memAccArea + *track->cmdPtr;
    track->cmdPtr++;

    data = *track->cmdPtr;
    track->cmdPtr++;

    switch (op) {
        case 0:
            *addr = data;
            return;
        case 1:
            *addr += data;
            return;
        case 2:
            *addr -= data;
            return;
        case 3:
            *addr = mplayInfo->memAccArea[data];
            return;
        case 4:
            *addr += mplayInfo->memAccArea[data];
            return;
        case 5:
            *addr -= mplayInfo->memAccArea[data];
            return;
        case 6:
            MEMACC_COND_JUMP(*addr == data)
            return;
        case 7:
            MEMACC_COND_JUMP(*addr != data)
            return;
        case 8:
            MEMACC_COND_JUMP(*addr > data)
            return;
        case 9:
            MEMACC_COND_JUMP(*addr >= data)
            return;
        case 10:
            MEMACC_COND_JUMP(*addr <= data)
            return;
        case 11:
            MEMACC_COND_JUMP(*addr < data)
            return;
        case 12:
            MEMACC_COND_JUMP(*addr == mplayInfo->memAccArea[data])
            return;
        case 13:
            MEMACC_COND_JUMP(*addr != mplayInfo->memAccArea[data])
            return;
        case 14:
            MEMACC_COND_JUMP(*addr > mplayInfo->memAccArea[data])
            return;
        case 15:
            MEMACC_COND_JUMP(*addr >= mplayInfo->memAccArea[data])
            return;
        case 16:
            MEMACC_COND_JUMP(*addr <= mplayInfo->memAccArea[data])
            return;
        case 17:
            MEMACC_COND_JUMP(*addr < mplayInfo->memAccArea[data])
            return;
        default:
            return;
    }

cond_true:
    ((MPlayFunc)(*&gMPlayJumpTable[1]))(mplayInfo, track);
    return;

cond_false:
    /* Skip the jump target: a pointer, pointer-wide in the hosted song
       data (mPtr). */
    track->cmdPtr += sizeof(u8 *);
}

void ply_xcmd(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 n = *track->cmdPtr;
    track->cmdPtr++;

    gUnk_0801D230[n](mplayInfo, track);
}

void ply_xxx(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{ gMPlayJumpTable[0](mplayInfo, track); }

void ply_xwave(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
#if PORTABLE
    /* The hosted song streams store the wav pointer at the host's
       pointer width (mPtr), so read it as bytes of a pointer rather
       than the GBA's four. */
    union {
        struct WaveData *a;
        u8 d[sizeof(uintptr_t)];
    } u;
    u32 i;

    for (i = 0; i < sizeof(uintptr_t); i++)
        u.d[i] = *(track->cmdPtr + i);
    track->tone.wav = u.a;
    track->cmdPtr += sizeof(uintptr_t);
#else
    u32 wav;

    READ_XCMD_BYTE(wav, 0)
    READ_XCMD_BYTE(wav, 1)
    READ_XCMD_BYTE(wav, 2)
    READ_XCMD_BYTE(wav, 3)

    track->tone.wav = (struct WaveData *)ADDR_WORD(wav);
    track->cmdPtr += 4;
#endif
}

void ply_xtype(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.type = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xatta(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.attack = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xdeca(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tone.decay = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xsust(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tone.sustain = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xrele(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tone.release = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xiecv(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->pseudoEchoVolume = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xiecl(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->pseudoEchoLength = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xleng(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tone.length = *track->cmdPtr;
    track->cmdPtr++;
}

void ply_xswee(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tone.pan_sweep = *track->cmdPtr;
    track->cmdPtr++;
}

void DummyCgbSound(void)
{}
