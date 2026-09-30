#ifndef CHAMPIONSHIP_TABLES_H
#define CHAMPIONSHIP_TABLES_H

/* The options-menu and championship tables the ROM holds twice, byte for
 * byte: the main program's copies in src/data/rom_083FD91C.c
 * (0x083FDA4C-0x083FDE78) and the high module's at 0x083639A8-0x08363C70
 * (src/data/rom_083639A8.c), each linked into its own image. One macro
 * per table, so one edit changes both GBAs. The tables' names, comments
 * and readers live in those files. The pointer tables between them point
 * at each image's own strings, so only their numbers are shared. */

#define UNK_083FDA4C { 10000 }
#define OPTIONS_MENU_MIN_VALUES { 0, 0, 0, 0, 0, 0, 0 }
#define OPTIONS_MENU_MAX_VALUES { 1, 6, 1, 1, 1, 1, 0 }
#define LAPS_PER_OPTION { 5, 10, 15, 20, 30, 50, 100, 0, 0, 0 }

#define CHAMPIONSHIP_TEAM_TIERS { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2 }
#define CHAMPIONSHIP_REQUIRED_FINISH { 5, 5, 5, 5, 5, 5, 5, 10, 10, 10, 10, 10, 20, 20, 20, 20, 20, 0, 0 }
#define CHAMPIONSHIP_TRACK_IDS { 0 }
#define CHAMPIONSHIP_QUALIFY_LAP_TIME_TARGETS \
{ \
    33000, 37000, 33000, 37000, 33000, 37000, 33000, 37000, 33000, \
    37000, 33000, 37000, 33000, 37000, 33000, 37000, 33000, \
}
#define UNK_083FDE14 { 4, 7, 8, 9 }
/* The season schedule, without braces: both copies hold these 33 bytes,
 * and the main program's appends a zero the module's lacks (there the
 * next table starts instead). */
#define CHAMPIONSHIP_TRACK_ORDER \
    0, 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 0, 5, 1, 2, 6, 10, \
    3, 11, 8, 6, 0, 1, 8, 10, 1, 10, 3, 1, 4, 2, 9, 3
#define UNK_083FDE72 { 2, 1, 0, 3, 0, 0 }

#endif
