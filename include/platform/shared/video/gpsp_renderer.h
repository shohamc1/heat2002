#ifndef GUARD_PLATFORM_SHARED_VIDEO_GPSP_RENDERER_H
#define GUARD_PLATFORM_SHARED_VIDEO_GPSP_RENDERER_H

// Software renderer entry points, after sa2's
// include/platform/shared/video/gpsp_renderer.h.
//
// The .cc also needs a handful of register spellings that sa2 keeps in
// its gba/io_reg.h and gba/defines.h but this project's headers spell
// differently (or not at all). They are collected here instead of editing
// include/gba/, so the GBA build's headers stay untouched.

#include "config.h"
#include "global.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/types.h"

extern void gpsp_draw_frame(uint16_t *framebuf);
extern void gpsp_draw_vram_view(uint16_t *framebuf);

// Window registers: one u16 each, left/top edge in the high byte.
typedef u16 winreg_t;
#define WIN_GET_LOWER(win_reg)  (((win_reg) & 0xFF00) >> 8)
#define WIN_GET_HIGHER(win_reg) (((win_reg) & 0x00FF) >> 0)

// OAM entry spacing: 8 bytes per sprite, affine parameter sets every
// four entries (16 bytes), sa2's spelling.
#define OAM_DATA_SIZE_AFFINE    8
#define OAM_DATA_SIZE_NO_AFFINE 6
#define OAM_DATA_COUNT_AFFINE    (OAM_DATA_SIZE_AFFINE / sizeof(u16))
#define OAM_DATA_COUNT_NO_AFFINE (OAM_DATA_SIZE_NO_AFFINE / sizeof(u16))

// Register address macros sa2's renderer spells with a per-layer index.
#define REG_ADDR_BGxCNT(n)  (REG_ADDR_BG0CNT + (n) * sizeof(u16))
#define REG_ADDR_WINxH(n)   (REG_ADDR_WIN0H + (n) * sizeof(winreg_t))
#define REG_ADDR_WINxV(n)   (REG_ADDR_WIN0V + (n) * sizeof(winreg_t))
#define REG_ADDR_BGxHOFS(n) (REG_ADDR_BG0HOFS + ((n) * 2) * sizeof(u16))
#define REG_ADDR_BGxVOFS(n) (REG_ADDR_BG0VOFS + ((n) * 2) * sizeof(u16))
#define REG_ADDR_BGxPA(n)   (REG_ADDR_BG2PA + ((n) - 2) * 8 * sizeof(u16))
#define REG_ADDR_BGxPB(n)   (REG_ADDR_BG2PB + ((n) - 2) * 8 * sizeof(u16))
#define REG_ADDR_BGxPC(n)   (REG_ADDR_BG2PC + ((n) - 2) * 8 * sizeof(u16))
#define REG_ADDR_BGxPD(n)   (REG_ADDR_BG2PD + ((n) - 2) * 8 * sizeof(u16))

// gIntrTable slot numbers, in this ROM's crt0 dispatch order
// (lib/crt0.s IntrMain; sa2's table swaps VCount/HBlank and lists the
// timers, this ROM's dispatcher does not).
#define INTR_INDEX_SIO     0
#define INTR_INDEX_VBLANK  1
#define INTR_INDEX_VCOUNT  2
#define INTR_INDEX_HBLANK  3
#define INTR_INDEX_DMA0    4
#define INTR_INDEX_DMA1    5
#define INTR_INDEX_DMA2    6
#define INTR_INDEX_DMA3    7
#define INTR_INDEX_KEYPAD  8
#define INTR_INDEX_GAMEPAK 9

// BGCNT screen-base field as a mask (include/gba/io_reg.h only spells
// the value form).
#define BGCNT_SCREENBASE_MASK 0x1F00

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#endif // GUARD_PLATFORM_SHARED_VIDEO_GPSP_RENDERER_H
