#ifndef GUARD_STRUCTS_H
#define GUARD_STRUCTS_H

// structs that belong to no module yet — stage 1 catch-all of
// docs/extern-headers-plan.md

// struct Track: the merged view of the 0x64-byte per-track record that
// gTrackData (ROM) and gModule_TrackData (the high module's EWRAM copy of
// it) are arrays of. Three src/ files declared it locally
// (sub_08003890.c, sub_08003928.c, ModuleLoadTrack.c); the two full views
// were identical and the third (unk00/unk04 only) is a prefix of them, so
// this is their union with no conflicts. The 100-byte stride is the one
// ModuleLoadTrackTiles.c's byte-pointer arithmetic uses (`off = idx * 100`).
// The 0x18-byte track segment record used to share the `struct Track`
// tag name in four local definitions; it now lives below as
// `struct TrackSeg`. Its stride differs from struct Track's, so the
// two can never fold together. This header defines the struct before declaring any array of
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
extern const struct Track gTrackData[];


// One waypoint quad of a track's segment list: the 0x18-byte record
// gTrackSegs points at after LoadTrackSegs loads the row from
// gTrackSegTables (race_setup.c, one row per track). ModuleUpdateLapProgress and
// race/UpdateLapProgress.c read unk10 (the segment kind) against the
// quad's corners; FindWaypointCrossing crosses the quad with a vertex pair.
// Its old local tags (this struct, plus the coarser `struct SegBC4C`
// prefix view) were merged here unchanged.
struct TrackSeg {
    /* 0x00 */ s32 f0;
    /* 0x04 */ s32 f4;
    /* 0x08 */ s32 f8;
    /* 0x0C */ s32 fC;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u8 pad12[2];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[3];
};


// The m4a song/player tables (defined identically in sub_08001208.c and
// ModuleM4aSongNumStart.c before the merge; the arrays are in data.h/variables.h).
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
// track) bounds RandomizeAiFinishTimes's RandomInRange roll of each AI driver's
// finish time.
struct AiFinishTimeRange {
    /* 0x00 */ u32 min;
    /* 0x04 */ u32 max;
};

// One driver's row of gDriverRoster (rom_083FD91C.c, 30 entries): the
// driver's name and the team id. Rows come in teammate pairs that share
// the id; FindTeamDriverPair returns both rows matching one, and
// FindDriverByTeam maps an id to its first row.
struct DriverRosterEntry {
    /* 0x00 */ const u8 *name;
    /* 0x04 */ u8 teamId;
    /* 0x05 */ u8 pad[3];
};

// The four RL-compressed graphic layers of one track's select-screen
// preview map (OBJ banks 0-3), and one row of gTrackSelectEntries
// (rom_083FD91C.c, 12 rows): the menu's length/number/name strings,
// the preview graphic, and its palette. DrawTrackSelect reads a row.
struct TrackPreviewGfx {
    /* 0x00 */ const u8 *unk0;
    /* 0x04 */ const u8 *unk4;
    /* 0x08 */ const u8 *unk8;
    /* 0x0C */ const u8 *unkC;
};

struct TrackSelectEntry {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ const u8 *lenText;
    /* 0x08 */ const u8 *numText;
    /* 0x0C */ const u8 *nameText;
    /* 0x10 */ const struct TrackPreviewGfx *previewGfx;
    /* 0x14 */ const u8 *previewPalette;
};

#endif // GUARD_STRUCTS_H

