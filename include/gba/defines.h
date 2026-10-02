#ifndef GUARD_GBA_DEFINES
#define GUARD_GBA_DEFINES

#include "config.h"

#define TRUE  1
#define FALSE 0

#if PLATFORM_GBA
#define IWRAM_DATA __attribute__((section("iwram_data")))
#define EWRAM_DATA __attribute__((section("ewram_data")))
/* Second and third EWRAM sections for files that own several separate
   RAM runs (run rule): ldscript.ld places each numbered section at its
   own run's address. */
#define EWRAM_DATA2 __attribute__((section("ewram_data2")))
#define EWRAM_DATA3 __attribute__((section("ewram_data3")))
/* The high module's and the multiboot island's RAM: the variables each
   image keeps outside its own bytes (its .bss). ldscript.ld places the
   sections as NOLOAD at each run's address; the port never compiles
   module or island files, but the macros must not break a hosted
   compile either. Numbered sections mirror EWRAM_DATA2/3 (run rule). */
#define MODULE_EWRAM_DATA __attribute__((section("module_ewram_data")))
#define MODULE_EWRAM_DATA2 __attribute__((section("module_ewram_data2")))
#define MODULE_EWRAM_DATA3 __attribute__((section("module_ewram_data3")))
#define ISLAND_DATA __attribute__((section("island_data")))
#else
// The hosted linker has no placement script: both macros are plain
// globals there, and the C definitions carry no initialiser difference.
#define IWRAM_DATA
#define EWRAM_DATA
#define EWRAM_DATA2
#define EWRAM_DATA3
#define MODULE_EWRAM_DATA
#define MODULE_EWRAM_DATA2
#define MODULE_EWRAM_DATA3
#define ISLAND_DATA
#endif

#define ALIGNED(n) __attribute__((aligned(n)))

#if PLATFORM_GBA
#define SOUND_INFO_PTR (*(struct SoundInfo **)0x3007FF0)
#define INTR_CHECK     (*(u16 *)0x3007FF8)
#define INTR_VECTOR    (*(void **)0x03007FFC)
#else
// The hosted build keeps the BIOS interface but backs it with real
// variables (defined in the platform layer).
extern struct SoundInfo *SOUND_INFO_PTR;
extern vu16 INTR_CHECK;
extern void (*INTR_VECTOR)(void);
#endif

#if PLATFORM_GBA

#define EWRAM_START 0x02000000
#define EWRAM_END   (EWRAM_START + 0x40000)
#define IWRAM_START 0x03000000
#define IWRAM_END   (IWRAM_START + 0x8000)

#define PLTT      0x5000000
#define PLTT_SIZE 0x400

#define BG_PLTT      PLTT
#define BG_PLTT_SIZE 0x200

#define OBJ_PLTT      (PLTT + 0x200)
#define OBJ_PLTT_SIZE 0x200

#define VRAM      0x6000000
#define VRAM_SIZE 0x18000

#define BG_VRAM           VRAM
#define BG_VRAM_SIZE      0x10000
#define BG_CHAR_ADDR(n)   (void *)(BG_VRAM + (0x4000 * (n)))
#define BG_SCREEN_SIZE    0x800
#define BG_SCREEN_ADDR(n) (void *)(BG_VRAM + (BG_SCREEN_SIZE * (n)))

// text-mode BG
#define OBJ_VRAM0      (void *)(VRAM + 0x10000)
#define OBJ_VRAM0_SIZE 0x8000

// bitmap-mode BG
#define OBJ_VRAM1      (void *)(VRAM + 0x14000)
#define OBJ_VRAM1_SIZE 0x4000

#define OAM      0x7000000
#define OAM_SIZE 0x400

#else

// The same memory map as host arrays (defined in the platform layer), so
// BG_CHAR_ADDR and friends stay address arithmetic, just pointer-sized.
extern ALIGNED(8) u8 EWRAM_START[0x40000];
extern ALIGNED(8) u8 IWRAM_START[0x8000];

#define EWRAM_END   (EWRAM_START + 0x40000)
#define IWRAM_END   (IWRAM_START + 0x8000)

extern ALIGNED(8) u8 PLTT[0x400];
#define PLTT_SIZE 0x400

#define BG_PLTT      PLTT
#define BG_PLTT_SIZE 0x200

#define OBJ_PLTT      (PLTT + 0x200)
#define OBJ_PLTT_SIZE 0x200

extern ALIGNED(8) u8 VRAM[0x18000];
#define VRAM_SIZE 0x18000

#define BG_VRAM           VRAM
#define BG_VRAM_SIZE      0x10000
#define BG_CHAR_ADDR(n)   (BG_VRAM + (0x4000 * (n)))
#define BG_SCREEN_SIZE    0x800
#define BG_SCREEN_ADDR(n) (BG_VRAM + (BG_SCREEN_SIZE * (n)))

// text-mode BG
#define OBJ_VRAM0      (VRAM + 0x10000)
#define OBJ_VRAM0_SIZE 0x8000

// bitmap-mode BG
#define OBJ_VRAM1      (VRAM + 0x14000)
#define OBJ_VRAM1_SIZE 0x4000

extern ALIGNED(8) u8 OAM[0x400];
#define OAM_SIZE 0x400

#endif // PLATFORM_GBA

#define DISPLAY_WIDTH  240
#define DISPLAY_HEIGHT 160

// Dimensions of a tile in pixels
#define TILE_WIDTH  8
#define TILE_HEIGHT 8

// Size of a tile in bytes, given its bit depth
#define TILE_SIZE_4BPP 32
#define TILE_SIZE_8BPP 64

#define PLTT_SIZEOF(n) ((n) * sizeof(u16))
#define PLTT_SIZE_4BPP PLTT_SIZEOF(16)

#define RGB(r, g, b) ((r) | ((g) << 5) | ((b) << 10))

#define RGB_BLACK RGB(0, 0, 0)
#define RGB_WHITE RGB(31, 31, 31)

#define WIN_RANGE(a, b) (((a) << 8) + (b))

#endif // GUARD_GBA_DEFINES
