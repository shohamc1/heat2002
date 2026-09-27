#include "global.h"
#include "functions.h"

extern u8 gUnk_0203B850;
extern u16 gUnk_0203B6FC;
extern u32 gUnk_02038F70[];
extern u32 gUnk_02038FB0[];
extern u32 gUnk_02038FF0[];
extern u32 gUnk_02039040[];
extern u16 gUnk_02039134;
extern u32 gUnk_0200CF1C[];
extern u32 gUnk_0200CF34[];
extern u8 gUnk_0203E1B0;
extern u32 gUnk_020390AC;
extern volatile u8 gUnk_020390D0;

void sub_0833DA34(void);
u32 sub_0833C874(void);
void sub_0833EE88(u32 *a, u32 b, u32 c);
void sub_0833AE90(void);
void sub_08344B74(void);
void sub_0833DC7C(void);
void sub_0833DC14(void);

u8 sub_0833DCB0(void)
{
    volatile u8 buf[512];
    u32 done;
    u16 v;

    gUnk_0203B850 = 0xFF;
    sub_0833DA34();
    if (gUnk_0203B6FC & 8) {
        sub_0833B074((struct MusicPlayerInfo *)gUnk_02038F70);
        sub_0833B074((struct MusicPlayerInfo *)gUnk_02038FB0);
        sub_0833B074((struct MusicPlayerInfo *)gUnk_02038FF0);
        sub_0833B074((struct MusicPlayerInfo *)gUnk_02039040);
        for (;;) {
            gUnk_02039134 = 0;
            if (sub_0833C874() != 0) {
                sub_0833EE88(sub_0833BD94(0), 0xA, 1);
                sub_0833EE88(gUnk_0200CF1C, 0xC, 1);
                sub_0833EE88(gUnk_0200CF34, 0xD, 1);
                sub_0833AE90();
                done = 0;
                do {
                    if (gUnk_0203E1B0 == 0)
                        return 0x27;
                    sub_08344B74();
                } while (done == 0);
            }
            sub_0833DA34();
            v = gUnk_0203B6FC & 8;
            if (v != 0) {
                sub_0833DC7C();
                return 1;
            }
            sub_0833DC14();
            gUnk_020390AC = gUnk_020390AC + 1;
            gUnk_020390D0 = v;
          spin:
            if (gUnk_020390D0 == 0)
                goto spin;
        }
    }
    return 0;
}
