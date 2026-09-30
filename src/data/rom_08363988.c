#include "global.h"
#include "collision_normals.h"

/* High module (link slave) collision response normals (ROM
 * 0x08363988-0x083639A8, EWRAM 0x0202AF08-0x0202AF28), byte-identical
 * to the main program's gCarCollisionNormals (src/data/rom_083FD91C.c,
 * which says what they are for): the ROM holds them twice, once per
 * GBA. collision_normals.h shares the initialisers, so one edit changes
 * both copies. module_collide.c reads them through its own view
 * (struct CollisionNormal x[]). */

const s32 gModule_CarCollisionNormals[8] = CAR_COLLISION_NORMALS;
