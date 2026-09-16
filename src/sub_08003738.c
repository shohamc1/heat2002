#include "global.h"
#include "gba/io_reg.h"

extern u16 gKeysPressed;
extern u8 gUnk_020020DC;
extern u8 gUnk_020020CC;
extern u8 gUnk_02002184;
extern u8 gUnk_0202CD90[];
extern u8 gUnk_0806C688[];
extern u8 sub_0800E200(void);
extern void sub_08000380(void);
extern void sub_0800048C(void);
extern void sub_080003F8(u32 a);
extern void sub_08001170(void);
extern void sub_0800184C(void);
extern void sub_08000370(void);
extern void sub_0800420C(u32 a, u32 b);
extern void sub_08000458(void);
extern void sub_08011B08(void);
extern u8 sub_0800295C(u32 a, u32 b, void *c);
extern u32 sub_08016558(u32 a);
extern void sub_08006418(u32 a, u32 b, u32 c);
extern void sub_08010074(void);
extern void sub_080112E0(void);
extern void sub_080053B8(void);
u8 sub_08003738(void)
{
    s32 i;
    if (sub_0800E200() == 1)
        return 1;
    sub_08000380();
    REG_IE = 0;
    REG_IME = 1;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    sub_0800048C();
    sub_080003F8(0x0800306D);
    REG_IE = INTR_FLAG_GAMEPAK | INTR_FLAG_VBLANK;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    sub_08001170();
    sub_0800184C();
    sub_08000370();
    sub_0800420C(0, 0x0A);
    i = 0;
    do {
        sub_08000458();
        i++;
    } while (i != 0x32);
loop:
    gUnk_020020DC = 1;
    sub_08011B08();
    gUnk_020020DC = 1;
    gUnk_020020CC = 7;
    gUnk_02002184 = 3;
    if (sub_0800295C(0, 4, gUnk_0202CD90) != 0) {
        sub_08006418(sub_08016558(0x75), 0x0A, 1);
        sub_08006418((u32)gUnk_0806C688, 0x0C, 1);
        sub_08010074();
wait1:
        sub_0800048C();
        if ((gKeysPressed & 8) == 0)
            goto wait1;
wait2:
        sub_0800048C();
        if (gKeysPressed & 8)
            goto wait2;
        sub_0800420C(0, 0x32);
    } else {
        sub_080112E0();
        sub_080053B8();
        goto loop;
    }
}
