#ifndef APPROACH_CONSTANTS_H
#define APPROACH_CONSTANTS_H

/* The second-order approach constants the ROM holds twice, byte for
 * byte: the main program's gUnk_083CA0B4-gUnk_083CA0C0
 * (src/data/rom_083C9574.c, which says what they are) and the high
 * module's at 0x08360280 (src/data/rom_08360100.c), each linked into
 * its own image. One edit changes both GBAs. */

#define APPROACH_STIFFNESS_A 0xF0
#define APPROACH_DAMPING_A 0x20
#define APPROACH_STIFFNESS_B 0xF8
#define APPROACH_DAMPING_B 0x80

#endif
