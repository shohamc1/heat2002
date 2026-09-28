#ifndef GUARD_STRUCTS_H
#define GUARD_STRUCTS_H

// structs that belong to no module yet — stage 1 catch-all of
// docs/extern-headers-plan.md

// struct Track: the merged view of the 0x64-byte per-track record that
// gTrackData (ROM) and gModule_TrackData (the high module's EWRAM copy of
// it) are arrays of. Three src/ files declared it locally
// (sub_08003890.c, sub_08003928.c, sub_0833CD2C.c); the two full views
// were identical and the third (unk00/unk04 only) is a prefix of them, so
// this is their union with no conflicts. The 100-byte stride is the one
// sub_0833CCD4.c's byte-pointer arithmetic uses (`off = idx * 100`).
// Another local `struct Track` tag shares the name but not the layout
// and stays local: the 0x18-byte track segment record (`struct TrackSeg`
// in sub_08006A34.c, sub_0833F468.c, sub_0800A4D4.c, sub_08341F64.c —
// gTrackSegs/gModule_TrackSegs point at those). Its stride differs, so
// it can never fold into this struct. This header defines the struct before declaring any array of
// it ("Declaration order matters for struct arrays",
// docs/extern-headers-plan.md).
struct Track {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u16 *unk0C;
    /* 0x10 */ u16 *unk10;
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u16 *unk20;
    /* 0x24 */ u16 *unk24;
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u32 unk2C;
    /* 0x30 */ u32 unk30;
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u32 unk38;
    /* 0x3C */ u32 unk3C;
    /* 0x40 */ u32 unk40;
    /* 0x44 */ u16 *unk44;
    /* 0x48 */ u32 unk48;
    /* 0x4C */ u8 pad4C[0x5C - 0x4C];
    /* 0x5C */ u16 unk5C;
    /* 0x5E */ u16 unk5E;
    /* 0x60 */ u16 unk60;
    /* 0x62 */ u8 pad62[0x64 - 0x62];
};

typedef char TrackSizeCheck[sizeof(struct Track) == 0x64 ? 1 : -1];

// The ROM's track table at 0x08364B0C; every user agrees on this type.
extern struct Track gTrackData[];


// The m4a song/player tables (defined identically in sub_08001208.c and
// sub_0833A8C8.c before the merge; the arrays are in data.h/variables.h).
struct Unk0801DA90 { u32 unk0; u32 unk4; u32 unk8; };
struct Unk0801DACC { u32 unk0; u16 unk4; };


// One row of the credits scroller's script table, gCreditTexts
// (0x083FE114, 182 entries): the row's text and the flag sub_08016330
// passes as DrawTextCenteredHighlight's third argument (0 on role rows
// such as "LEAD PROGRAMMER", 1 on name and blank rows).
struct CreditLine {
    /* 0x00 */ const u8 *text;
    /* 0x04 */ u8 highlight;
    /* 0x05 */ u8 pad[3];
};


// One driver's row of gTireGripDefaults (0x083677A8, 31 rows): the
// four tire-grip corners SetTireGrip loads into gTireGripSlow/Fast and
// gFrontTireGripSlow/Fast, and the slip-limit base it loads into
// gTireSlipLimitBase.
struct TireGripSetup {
    /* 0x00 */ u32 rearGripSlow;
    /* 0x04 */ u32 rearGripFast;
    /* 0x08 */ u32 frontGripSlow;
    /* 0x0C */ u32 frontGripFast;
    /* 0x10 */ u32 slipLimitBase;
};


// One track's record in gTrackStartGrids (race_setup.c, 12 rows): where
// BuildStartingGrid (race/grid.c) starts placing the 24 starting-grid
// slots — origin, per-row step, the offset from a slot to its teammate's
// slot, and the direction value stored with every slot.
struct TrackGrid {
    /* 0x00 */ s32 originX;
    /* 0x04 */ s32 originY;
    /* 0x08 */ s32 rowStepX;
    /* 0x0C */ s32 rowStepY;
    /* 0x10 */ s32 pairOffsetX;
    /* 0x14 */ s32 pairOffsetY;
    /* 0x18 */ s32 direction;
};

// The window gTrackAiFinishTimeRanges (0x083FECB8, 12 rows, one per
// track) bounds sub_08016CB0's RandomInRange roll of each AI driver's
// finish time.
struct AiFinishTimeRange {
    /* 0x00 */ u32 min;
    /* 0x04 */ u32 max;
};

// One driver's row of gDriverRoster (rom_083FD91C.c, 30 entries): the
// driver's name and the team id. Rows come in teammate pairs that share
// the id; sub_08010B38 returns both rows matching one, and
// sub_0800F120 maps an id to its first row.
struct DriverRosterEntry {
    /* 0x00 */ const u8 *name;
    /* 0x04 */ u8 teamId;
    /* 0x05 */ u8 pad[3];
};

#endif // GUARD_STRUCTS_H
