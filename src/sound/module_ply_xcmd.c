#include "global.h"
#include "functions.h"
#include "gba/m4a_internal.h"
#include "m4a.h"

/* ply_memacc, high-module copy. cond_true calls through the high module's
 * _call_via_r2 stub (0x08344B84): _08344B84(a, b, target) leaves a in r0,
 * b in r1 and jumps to r2. The switch jump table words hold EWRAM link
 * addresses (module linked to run from 0x02000000), so under match.py's
 * ROM-address link the 18 table words plus the pool word that feeds
 * ldr r1 cannot match; everything else is byte-identical. */
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

void _08344B84(struct MusicPlayerInfo *mplayInfo,
               struct MusicPlayerTrack *track, MPlayFunc target);
/* ply_xcmd, high-module copy. Its xcmd table lives at 0x0200C910 and the
 * indirect call goes through the high module's _call_via_r2 stub at
 * 0x08344B84: calling _08344B84(a, b, target) leaves a in r0, b in r1 and
 * jumps to the address in r2. */
extern MPlayFunc gUnk_0200C910[];

/* ply_xxx (high copy). The high module links its own libgcc copy, so the
   indirect call routes through _08344B84, its _call_via_r2, not the low
   copy's _call_via_r2 (same pattern as ModuleClearChain with _08344B80). */
/* ply_xwave, high-module copy. */
/* ply_xtype (high copy) */
/* ply_xatta (high copy) */
/* ply_xdeca (high copy) */
/* ply_xsust (high copy) */
/* ply_xrele (high copy) */
/* ply_xiecv (high copy) */
/* ply_xiecl (high copy) */
/* ply_xleng (high copy) */
/* ply_xswee (high copy) */
void ModulePlyMemacc(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
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
    _08344B84(mplayInfo, track, *&gModule_MPlayJumpTable[1]);
    return;

cond_false:
    track->cmdPtr += 4;
}

void ModulePlyXcmd(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 n = *track->cmdPtr;
    track->cmdPtr++;

    _08344B84(mplayInfo, track, gUnk_0200C910[n]);
}

void ModulePlyXxx(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{ _08344B84(mplayInfo, track, gModule_MPlayJumpTable[0]); }

void ModulePlyXwave(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    u32 wav;

    READ_XCMD_BYTE(wav, 0)
    READ_XCMD_BYTE(wav, 1)
    READ_XCMD_BYTE(wav, 2)
    READ_XCMD_BYTE(wav, 3)

    track->tone.wav = (struct WaveData *)wav;
    track->cmdPtr += 4;
}

void ModulePlyXtype(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.type = *track->cmdPtr;
    track->cmdPtr++;
}

void ModulePlyXatta(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track)
{
    track->tone.attack = *track->cmdPtr;
    track->cmdPtr++;
}

void ModulePlyXdeca(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tone.decay = *track->cmdPtr;
    track->cmdPtr++;
}

void ModulePlyXsust(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tone.sustain = *track->cmdPtr;
    track->cmdPtr++;
}

void ModulePlyXrele(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tone.release = *track->cmdPtr;
    track->cmdPtr++;
}

void ModulePlyXiecv(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->pseudoEchoVolume = *track->cmdPtr;
    track->cmdPtr++;
}

void ModulePlyXiecl(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->pseudoEchoLength = *track->cmdPtr;
    track->cmdPtr++;
}

void ModulePlyXleng(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tone.length = *track->cmdPtr;
    track->cmdPtr++;
}

void ModulePlyXswee(struct MusicPlayerInfo *unused, struct MusicPlayerTrack *track)
{
    track->tone.pan_sweep = *track->cmdPtr;
    track->cmdPtr++;
}

void ModuleDummyCgbSound(void)
{}
