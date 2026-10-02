#ifndef GUARD_STRUCTS_H
#define GUARD_STRUCTS_H

#include "config.h"

// gTrackData and gModule_TrackData contain 0x64-byte track records.
// ModuleLoadTrackTiles uses this 100-byte stride in its byte-pointer arithmetic.
// Define each struct before declaring an array of it to preserve code generation.
struct Track
{
    /* 0x00 */ const u8 *bg3Tiles; /* 4bpp tiles copied to char block 2 (BG3) */
    /* 0x04 */ const u8 *bg2Tiles; /* 4bpp tiles copied to char block 0 (BG2) */
    /* 0x08 */ const u8 *unk08;    /* bg2Tiles again in the module's record, 0 in the ROM's */
    /* 0x0C */ u16 *bg3Metatiles; /* 32 bytes per metatile, 4x4 tilemap entries */
    /* 0x10 */ u16 *bg2Metatiles;
    /* 0x14 */ const u16 *unk14;  /* bg2Metatiles again in the module's record, 0 in the ROM's */
    /* 0x18 */ const u8 *palette; /* 256-colour palette, 0x200 bytes */
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u16 *bg3Map; /* RLE-compressed u16 map of metatile indices */
    /* 0x24 */ u16 *bg2Map;
    /* 0x28 */ const u16 *unk28; /* bg2Map's value again on tracks 3-11, 0 on 0-2 */
    /* 0x2C */ u32 mapWidth; /* the gBgMapWidth stride of both layers */
    /* 0x30 */ u32 mapHeight;
    /* 0x34 */ u32 mapWidth2; /* the second pair; equal to mapWidth on */
    /* 0x38 */ u32 mapHeight2; /* every track (LoadTrack -> gBgMapWidth2) */
    /* 0x3C */ u32 unk3C;
    /* 0x40 */ u32 unk40;
    /* 0x44 */ u16 *cellMap;           /* RLE-compressed u16 collision cell map */
    /* 0x48 */ const u8 *surfaceTable; /* 16 bytes per cell value: surface code per 4x4 sub-position */
    /* 0x4C */ u8 pad4C[0x5C - 0x4C];
    /* 0x5C */ u16 bg3MapLen; /* RLE source halfword counts, one per */
    /* 0x5E */ u16 bg2MapLen; /* stream: the ROM blob is 2*len bytes, */
    /* 0x60 */ u16 cellMapLen; /* plus the slot's dead tail bytes */
    /* 0x62 */ u8 pad62[0x64 - 0x62];
};

// The 0x64 layout holds on the GBA; the hosted build widens the pointer
// members, so the check is GBA-only.
#if PLATFORM_GBA
typedef char TrackSizeCheck[sizeof(struct Track) == 0x64 ? 1 : -1];
#endif

// The ROM's track table at 0x08364B0C; every user agrees on this type.
extern const struct Track gTrackData[];

// One waypoint quad of a track's segment list: the 0x18-byte record
// gTrackSegs points at after LoadTrackSegs loads the row from
// gTrackSegTables (race_setup.c, one row per track). ModuleUpdateLapProgress and
// race/UpdateLapProgress.c read kind (the segment kind) against the
// quad's corners; FindWaypointCrossing crosses the quad with a vertex pair.
struct TrackSeg
{
    /* 0x00 */ s32 corner1X; /* one edge of the waypoint quad; the quad spans */
    /* 0x04 */ s32 corner1Z; /* consecutive records */
    /* 0x08 */ s32 corner2X;
    /* 0x0C */ s32 corner2Z;
    /* 0x10 */ u16 kind; /* 1 = start/finish wrap; 1-2 gate the lap block */
    /* 0x12 */ u8 pad12[2];
    /* 0x14 */ u8 countdownSeconds; /* feeds SetCountdownSeconds */
    /* 0x15 */ u8 pad15[3];
};

// One 0x14-byte record of a lane's segment table (gLaneSegmentTables);
// its points index the lane's u16 (x, z) pair list (gLanePointTables).
struct LaneSeg
{
    /* 0x00 */ u8 pointA;
    /* 0x01 */ u8 pointB;    /* 0xFF ends the table */
    /* 0x02 */ u8 projScale; /* scales the dot product into the 16.16 segment parameter */
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u16 startDist;
    /* 0x06 */ u16 endDist;
    /* 0x08 */ s32 invLen; /* 65536 / isqrt(len2): 16.16 of the length */
    /* 0x0C */ s32 scaleX;
    /* 0x10 */ s32 scaleZ;
};

// A point on a lane, in world units (GetLanePositionAtDistance's output).
struct LanePos
{
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 z;
};

// A track's wall geometry, read by LoadTrackWalls and TestCornersVsWalls.
struct Pt
{
    s32 x;
    s32 y;
};
// One wall segment between two gWallVertices entries (0x20 bytes).
struct WallRec
{
    u16 vertex0;      /* index into gWallVertices */
    u16 vertex1;      /* 0x02 */
    s32 normalX;      /* 0x04: 1.15 unit normal of the wall segment */
    s32 normalZ;      /* 0x08 */
    s32 minX;         /* 0x0C: segment AABB */
    s32 maxX;         /* 0x10 */
    s32 minZ;         /* 0x14 */
    s32 maxZ;         /* 0x18 */
    u8 steerAngle;    /* 0x1C: post-hit steer heading, gSinTable index */
    u8 steerAngleOpp; /* 0x1D: +0x80, used when heading opposes it */
    u8 edgeAngle;     /* 0x1E: steerAngle + 0x40, the wall's own heading */
};
// One row of gTrackWallTables, per track.
struct TrackWalls
{
    /* 0x00 */ struct Pt *vertices;
    /* 0x04 */ struct WallRec *walls;
    /* 0x08 */ u32 wallCount;
    /* 0x0C */ u16 *cellLists; /* 0xFFFF-terminated wall-index lists */
    /* 0x10 */ u16 *cellGrid;  /* u16[48*48] grid of offsets into cellLists */
};

// Car-vs-wall sweep test (CollideCarWithWalls, TestCornersVsWalls and their
// high-module twins). One car corner's motion this frame, 16.16 world units.
struct CornerSweep
{
    /* 0x00 */ s32 x;      /* cornerX */
    /* 0x04 */ s32 z;      /* cornerZ */
    /* 0x08 */ s32 nextX;  /* nextCornerX */
    /* 0x0C */ s32 nextZ;  /* nextCornerZ */
    /* 0x10 */ s32 deltaX; /* nextX - x */
    /* 0x14 */ s32 deltaZ;
};

// A corner sweep's bounding box, in world units.
struct SweepBox
{
    /* 0x00 */ s32 minX;
    /* 0x04 */ s32 maxX;
    /* 0x08 */ s32 minZ;
    /* 0x0C */ s32 maxZ;
};

// The nearest wall hit TestCornersVsWalls reports.
struct WallHit
{
    /* 0x00 */ u8 pad00[4];
    /* 0x04 */ s32 normalX; /* wall normal, slightly amplified */
    /* 0x08 */ s32 normalZ;
    /* 0x0C */ u8 cornerIndex; /* which car corner hit */
    /* 0x0D */ u8 steerAngle;
    /* 0x0E */ u8 steerAngleOpp;
    /* 0x0F */ u8 unk0F;
    /* 0x10 */ s32 unk10; /* winning wall index (write-only) */
};

// The nearest car-vs-car contact CollideCars has found this frame
// (gCarCollContact): KeepNearestCarContact replaces it whenever a closer
// hit turns up.
struct CarContact
{
    /* 0x00 */ struct Car *carA;
    /* 0x04 */ struct Car *carB;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 normalIndex; /* row of gCarCollisionNormals */
    /* 0x0C */ s32 closingSpeed;
};

// One side of the car's collision box, as a unit normal in the car's
// frame (gCarCollisionNormals).
struct CollisionNormal
{
    /* 0x00 */ s32 normalX; /* 20.12 fixed point */
    /* 0x04 */ s32 normalZ;
};

// One entry of the depth-sorted sprite queue (gDepthSortedSprites, and
// gModule_DepthSortedSprites in the high module): an OAM entry's attributes
// and its sort depth. FlushSortedSprites copies the entries to the OAM
// entry queue nearest-last.
struct DepthSortedSprite
{
    /* 0x00 */ u32 attr01;
    /* 0x04 */ u32 attr2; /* 0xFFFFFFFF: an unused slot */
    /* 0x08 */ u16 depth;
    /* 0x0A */ u16 pad0A;
};

// The serial transfer state the link-cable interrupt handler steps
// (gSioTransfer, and gIsland_SioTransfer on the multiboot island).
struct CommRegs
{
    /* 0x00 */ u8 mode;
    /* 0x01 */ u8 state;
    /* 0x02 */ u8 retry;
    /* 0x03 */ u8 flag;
    /* 0x04 */ u32 *data; /* the 32 KB chunk sent or received */
    /* 0x08 */ s32 count;
    /* 0x0C */ u32 checksum;
    /* 0x10 */ u32 crc;
    /* 0x14 */ s32 index;
};

// The m4a song/player tables (defined identically in sub_08001208.c and
// ModuleM4aSongNumStart.c before the merge; the arrays are in data.h/variables.h).
// Tags and member names are pret/pokeemerald's (include/gba/m4a_internal.h):
// struct MusicPlayer and struct Song, which this revision of the header
// predates — that is why they live here.
struct MusicPlayerInfo;
struct MusicPlayerTrack;
struct SongHeader;
struct MusicPlayer
{
    struct MusicPlayerInfo *info;
    struct MusicPlayerTrack *track;
    u8 numTracks; /* 0x08 */
    u16 unk_A;    /* 0x0A */
};
struct Song
{
    struct SongHeader *header; /* 0x00 */
    u16 ms;                    /* 0x04: music-player index */
    u16 me;                    /* 0x06: unread; the ROM rows repeat ms here */
};

// One row of the credits scroller's script table, gCreditTexts
// (0x083FE114, 182 entries): the row's text and the flag sub_08016330
// passes as DrawTextCenteredHighlight's third argument (0 on role rows
// such as "LEAD PROGRAMMER", 1 on name and blank rows).
struct CreditLine
{
    /* 0x00 */ const u8 *text;
    /* 0x04 */ u8 highlight;
    /* 0x05 */ u8 pad[3];
};

// One driver's row of gTireGripDefaults (0x083677A8, 31 rows): the
// four tire-grip corners SetTireGrip loads into gTireGripSlow/Fast and
// gFrontTireGripSlow/Fast, and the slip-limit base it loads into
// gTireSlipLimitBase.
struct TireGripSetup
{
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
struct TrackGrid
{
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
struct AiFinishTimeRange
{
    /* 0x00 */ u32 min;
    /* 0x04 */ u32 max;
};

// One driver's row of gDriverRoster (championship_data.c, 30 entries): the
// driver's name and the team id. Rows come in teammate pairs that share
// the id; FindTeamDriverPair returns both rows matching one, and
// FindDriverByTeam maps an id to its first row.
struct DriverRosterEntry
{
    /* 0x00 */ const u8 *name;
    /* 0x04 */ u8 teamId;
    /* 0x05 */ u8 pad[3];
};

// The four RL-compressed graphic layers of one track's select-screen
// preview map (OBJ banks 0-3), and one row of gTrackSelectEntries
// (championship_data.c, 12 rows): the menu's length/number/name strings,
// the preview graphic, and its palette. DrawTrackSelect reads a row.
struct TrackPreviewGfx
{
    /* 0x00 */ const u8 *topLeftGfx;  /* RL streams for the 2x2 preview's */
    /* 0x04 */ const u8 *topRightGfx; /* four 64x64 sprites */
    /* 0x08 */ const u8 *bottomLeftGfx;
    /* 0x0C */ const u8 *bottomRightGfx;
};

struct TrackSelectEntry
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ const u8 *lenText;
    /* 0x08 */ const u8 *numText;
    /* 0x0C */ const u8 *nameText;
    /* 0x10 */ const struct TrackPreviewGfx *previewGfx;
    /* 0x14 */ const u8 *previewPalette;
};

// The 0x44-byte task slot that AllocTask hands out: 256 of them in gTasks,
// and 64 in the high module's gModule_Tasks. RunTasks walks the prev/next
// list and calls callback with the slot. callback is unprototyped so each
// body can take the slot as its own view (DraftStreak, SkidSmoke and
// DamageSmoke in src/car/particles.c). timer counts calls in every body
// that reads it; the other words are per-task data.
struct Task
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ void (*callback)();
    /* 0x10 */ struct Task *prev;
    /* 0x14 */ struct Task *next;
    /* 0x18 */ s32 timer; /* signed: LinkRaceStartSplashTask compares it with ble */
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ u32 unk30;
    /* 0x34 */ u8 unk34;
    /* 0x35 */ u8 pad35[0x3C - 0x35];
    /* 0x3C */ u32 slotIndex; /* index into gTaskSlotUsed */
    /* 0x40 */ u8 pad40[4];
};

// The particle tasks' views of a struct Task slot (src/car/particles.c and
// its high-module twin). prev and next are pointer-wide, so their pad
// widens on a hosted build.
struct DraftStreak
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ s32 axialDist; /* 16.16 distance along the car's heading axis */
    /* 0x0C */ void (*callback)();
    /* 0x10 */ u8 pad10[2 * sizeof(void *)]; /* prev, next */
    /* 0x18 */ s32 timer;
    /* 0x1C */ s32 cornerIdx;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u8 pad24[0x10];
    /* 0x34 */ u8 carIdx;
};

struct SkidSmoke
{
    /* 0x00 */ s32 posX;
    /* 0x04 */ s32 rise;
    /* 0x08 */ s32 posZ;
    /* 0x0C */ void (*callback)();
    /* 0x10 */ u8 pad10[2 * sizeof(void *)]; /* prev, next */
    /* 0x18 */ s32 timer;
    /* 0x1C */ s32 cornerIdx;
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ s32 velX;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ s32 velZ;
    /* 0x34 */ u8 carIdx;
};

struct DamageSmoke
{
    /* 0x00 */ s32 posX;
    /* 0x04 */ s32 rise;
    /* 0x08 */ s32 posZ;
    /* 0x0C */ void (*callback)();
    /* 0x10 */ u8 pad10[2 * sizeof(void *)]; /* prev, next */
    /* 0x18 */ s32 timer;
    /* 0x1C */ s32 riseRate;
    /* 0x20 */ u8 pad20[8];
    /* 0x28 */ s32 velX;
    /* 0x2C */ u8 pad2C[4];
    /* 0x30 */ s32 velZ;
};

// An address carried in the OBJ gfx/palette caches. The ROM stores these
// as 32-bit words; the hosted build needs them pointer-wide so the cached
// source and destination addresses survive (same device as io_reg.h's
// uintptr_t DMA registers). Under !PORTABLE this is exactly u32, so the
// module's and the main program's views stay identical.
#if PORTABLE
typedef uintptr_t GfxAddr;
#else
typedef u32 GfxAddr;
#endif

// One slot of an OBJ tile cache (gObjTileCache1 to gObjTileCache64, by
// tile count). RequestObjTiles* hands a slot out for a graphics pointer,
// UploadPendingGfx copies it to vramDest, and AgeGfxCaches frees it when
// age reaches zero.
struct ObjTileCacheEntry
{
    /* 0x00 */ u32 age;    /* set to 1 on each request, counted down each frame */
    /* 0x04 */ u8 pending; /* 1: copy to VRAM, 3: RL-decompress (1-tile cache) */
    /* 0x05 */ u8 unk05;   /* RequestObjTiles64's flag argument */
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
    /* 0x08 */ GfxAddr gfx; /* source graphics; 0xFFFF when the slot is free */
    /* 0x0C */ GfxAddr vramDest;
    /* 0x10 */ u32 tileIndex; /* OAM attr2 base: tile number, OR'd with palette/priority at each use */
};

// One slot of gObjPaletteCache: an OBJ palette bank and what it holds.
struct ObjPaletteCacheEntry
{
    /* 0x00 */ u8 age;
    /* 0x01 */ u8 pending;
    /* 0x02 */ u8 pad02[2];
    /* 0x04 */ GfxAddr palette; /* source palette; 0xFFFF when the slot is free */
    /* 0x08 */ GfxAddr palDest;
};

#endif // GUARD_STRUCTS_H
