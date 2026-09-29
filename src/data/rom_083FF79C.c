#include "global.h"
#include "data.h"

/* 0x083FF79C-0x083FF7BC: the eight track-cue icon gfx lists drawn by
 * the HUD corner callout (DrawTrackCueIcon, indexed by gTrackCueId). */

extern const u8 gUnk_08338810[];
extern const u8 gUnk_08338980[];
extern const u8 gUnk_08338AFC[];
extern const u8 gUnk_08338C6C[];
extern const u8 gUnk_08338DF0[];
extern const u8 gUnk_08338F5C[];
extern const u8 gUnk_083390C8[];
extern const u8 gUnk_0833923C[];

const u8 *const gTrackCueIconGfxList[] = { gUnk_08338810, gUnk_08338980, gUnk_08338AFC, gUnk_08338C6C,
                                           gUnk_08338DF0, gUnk_08338F5C, gUnk_083390C8, gUnk_0833923C };
