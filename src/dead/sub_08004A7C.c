#include "global.h"
#include "variables.h"
#include "functions.h"

extern u32 gUnk_02025270[];
/* Dead code reads these tables as u32; live code uses u16 (variables.h). */
extern u32 gDeadTuneA[] asm("gUnk_0202A540");
extern u32 gDeadTuneG[] asm("gUnk_0202CB20");
extern u8 gText_FormatA[];
extern u8 gText_FormatG[];

void sub_08017594(u32 *a, u8 *b, u8 c, u32 d);
void sub_08004A50(u32 *a, u32 b, u32 c, u32 d);

void sub_08004A7C(u8 sel)
{
    u32 *base;
    u8 i;
    u32 *p;

    do {
        i = 0;
        base = gUnk_02025270;
        p = gDeadTuneA;
        do {
            sub_08017594(base, gText_FormatA, i, p[i]);
            sub_08004A50(base, 0x10, (i * 10) + 40, sel == i);
            i = i + 1;
        } while (i != 5);
        i = 0;
        base = gUnk_02025270;
        do {
            sub_08017594(base, gText_FormatG, i, gDeadTuneG[i]);
            sub_08004A50(base, 0x78, (i * 10) + 40, sel == (i + 5));
            i = i + 1;
        } while (i != 5);
    } while (0);
}

extern s32 gTuneMenuSteps[];
extern s32 gTuneMenuMinValues[];
extern s32 gTuneMenuMaxValues[];


void sub_08004B1C(u8 arg)
{
    s32 val;
    u32 sel = arg;
    u32 *p;
    u32 idx;
    u32 j;

    if (sel <= 4) {
        val = gDeadTuneA[idx];
        p = gDeadTuneG;
    } else {
        val = gDeadTuneG[idx - 5];
        p = gDeadTuneG;
    }
    if (gKeysPressed & 0x20) {
        val = val - gTuneMenuSteps[sel];
        if (val < gTuneMenuMinValues[sel])
            val = gTuneMenuMinValues[sel];
    }
    if (gKeysPressed & 0x10) {
        val = val + gTuneMenuSteps[sel];
        if (val > gTuneMenuMaxValues[sel])
            val = gTuneMenuMaxValues[sel];
    }
    if (sel <= 4)
        gDeadTuneA[idx] = val;
    else
        *(p + (j = idx - 5)) = val;
    ComputeGearRatioReciprocals((u16 *)p,gUnk_0202CB00);
}

void sub_08004BCC(void)
{
    u8 v;
    u16 start;

    if (gKeysPressed & 4) {
        v = 0;
        UpdateSprites();
loop:
        ReadKeys();
        start = gKeysPressed & 4;
        if (start == 0) {
            v = MenuMoveVertical(gKeysPressed, v, 0, 9);
            sub_08004B1C(v);
            AgeGfxCaches();
            ClearOamBuffer();
            sub_08004A7C(v);
            UpdateSprites();
            gVBlankWorkDone = start;
            gUnk_02025370++;
            WaitForVBlank();
            goto loop;
        }
    }
}
