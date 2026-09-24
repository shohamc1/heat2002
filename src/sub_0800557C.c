#include "global.h"

extern u16 gUnk_02025224; /* 0x02025224 */
extern u16 gUnk_02025220; /* 0x02025220 */
extern u16 gUnk_02025260; /* 0x02025260 */

void ResetRaceTimer(void)
{
    gUnk_02025224 = 0;
    gUnk_02025220 = 0;
    gUnk_02025260 = 0;
}
