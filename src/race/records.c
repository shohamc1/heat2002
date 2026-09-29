#include "global.h"
#include "variables.h"
void SetTrackRecord(u32 a, u32 b, u32 c);
void AddTrackRecordTasks(void);

void SetTrackRecord(u32 a, u32 b, u32 c)
{
    if ((u8)(gGameMode[0] - 3) <= 1)
        return;
    gTrackRecordMs[gTrackId] = c;
    gTrackRecordSec[gTrackId] = b;
    gTrackRecordMin[gTrackId] = a;
}

void CheckTrackRecord(u16 a1, u16 a2, u16 a3)
{
    if (a1 * 60000 + a2 * 1000 + a3 <=
        gTrackRecordMin[gTrackId] * 60000 + gTrackRecordSec[gTrackId] * 1000 + gTrackRecordMs[gTrackId]) {
        if (gGameMode[0] == 3 || gGameMode[0] == 4)
            return;
        SetTrackRecord(a1, a2, a3);
        gNewTrackRecord = 1;
        AddTrackRecordTasks();
    }
}
