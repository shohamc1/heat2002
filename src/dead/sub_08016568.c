#include "global.h"
#include "variables.h"

extern const u8 *const gUnk_083FECAC[];

/* Dead code: no bl or pointer in the ROM reaches this function. Any
 * index past 0 reads beyond gUnk_083FECAC's one entry. */
const u8 *sub_08016568(u16 a0, u8 a1) {
    return gUnk_083FECAC[a0 * 70 + gLinkSyncByte * 14 + a1];
}
