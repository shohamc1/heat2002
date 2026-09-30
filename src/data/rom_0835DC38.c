#include "global.h"
#include "structs.h"

/* The track-data blob labels data/rom_08345BF8.s defines (EWRAM names):
 * the u16 ones fill this record's pointer fields, the u32-word ones its
 * raw word fields (cast at the use). */
extern u16 gUnk_0201044C[];
extern u16 gUnk_02013FAC[];
extern u16 gUnk_0200D378[];
extern u32 gUnk_0201242C[];
extern u32 gUnk_02018DA0[];
extern u32 gUnk_02017080[];
extern u32 gUnk_02013DAC[];

/* no variables.h: it declares gModule_TextLayerMapPtr without const and
   gModule_TrackData as non-const struct Track, which the readers' bytes
   need; this file needs nothing else from it. */

/* High module (link slave) fixed HUD and track data (ROM
 * 0x0835DC38-0x0835DCA0, EWRAM 0x02025158-0x020251C0). */

/* The text layer's BG map base in VRAM, the twin of the main program's
 * gTextLayerMapPtr (src/data/rom_08364AC8.c): the module's HUD draws
 * through this pointer. Its users declare it as u16 *x, u32 x. */
const u32 gModule_TextLayerMapPtr[1] = { 0x600E000 };

/* The one track the link race runs (struct Track, structs.h): track 7,
 * the championship's link-only layout. The main program's twelve-record
 * gTrackData (src/data/rom_08364AC8.c) says what each field is; this
 * record's blobs live in the module's track data around 0x0834A000,
 * labelled by their EWRAM addresses in data/rom_08345BF8.s. */
const struct Track gModule_TrackData[1] = {
    { (u32)gUnk_0201242C,
      (u32)gUnk_02018DA0,
      (u32)gUnk_02018DA0,
      gUnk_0201044C,
      gUnk_02017080,
      (u32)gUnk_02017080,
      (u32)gUnk_02013DAC,
      0x0,
      gUnk_0200D378,
      gUnk_02013FAC,
      (u32)gUnk_02013FAC,
      0x7d,
      0x64,
      0x7d,
      0x64,
      0x0,
      0x0,
      0x0,
      0x0,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      0x0,
      0x0,
      0x0,
      { 0, 0 } },
};

/* gUnk_0201242C (0x0834AEAC), gUnk_02018DA0 (0x08351820),
 * gUnk_02017080 (0x0834FB00), gUnk_02013DAC (0x0834C82C) and
 * gUnk_02013FAC (0x0834CA2C): the track's BG tile sheets, metatiles,
 * palette and BG2 map, in data/rom_08345BF8.s's slices of the module's
 * track-data blobs. gUnk_0201044C (0x08348ECC) and gUnk_0200D378
 * (0x08345DF8) are in this record's own fragment's tyre-data blob. */
