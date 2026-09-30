#ifndef COLLISION_NORMALS_H
#define COLLISION_NORMALS_H

/* The collision response normals the ROM holds twice, byte for byte: the
 * main program's copy at 0x083FDA2C (src/data/rom_083FD91C.c) and the
 * high module's at 0x08363988 (src/data/rom_08363988.c), each linked
 * into its own image. One macro, so one edit changes both GBAs. The
 * tables' names, comments and readers live in those two files. */

/* One (x, z) pair per contact direction, in 20.12 fixed point
 * (4096 = 1). */
#define CAR_COLLISION_NORMALS \
{ 0, 4096, 0, -4096, -4096, 0, 4096, 0 }

#endif
