#include "global.h"

struct UnkCar {
    /* 0x000 */ u8 filler000[0x7D];
    /* 0x07D */ u8 unk7D;
    /* 0x07E */ u8 filler07E[0x162 - 0x7E];
    /* 0x162 */ u8 unk162;
    /* 0x163 */ u8 filler163[0x16C - 0x163];
    /* 0x16C */ u32 unk16C;
    /* 0x170 */ u8 filler170[400 - 0x170];
};

extern u8 gUnk_02002090;              /* 0x02002090 */
extern u8 gUnk_02002184;              /* 0x02002184 */
extern struct UnkCar gUnk_0202A550[]; /* 0x0202A550 */
extern u32 gUnk_0202CB40[];           /* 0x0202CB40 */
extern u8 gUnk_0202CBD0;              /* 0x0202CBD0 */
extern u32 gUnk_0202CBD8;             /* 0x0202CBD8 */
extern u8 gUnk_0202EEE4;              /* 0x0202EEE4 */
extern struct UnkCar *gUnk_0202EFC0;  /* 0x0202EFC0 */

extern void sub_08008A20(void);
extern void sub_08008AB0(void);
extern void sub_0800F3C0(void);
extern void sub_08016D28(u8 a);

void sub_0800F8D0(u8 a)
{
    u8 i;

    for (i = 0; i != 24; i++) {
        gUnk_0202A550[i].unk7D = 0;
        gUnk_0202A550[i].unk16C = 0;
    }

    switch (a) {
    case 0:
        gUnk_02002090 = 1;
        gUnk_0202A550[0].unk162 = 0;
        sub_08008A20();
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        sub_08016D28(0);
        sub_0800F3C0();
        gUnk_02002184 = 1;
        gUnk_0202EFC0 = gUnk_0202A550;
        break;
    case 1:
        gUnk_02002090 = 1;
        gUnk_0202A550[0].unk162 = 0;
        sub_08008A20();
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        sub_08016D28(0);
        sub_0800F3C0();
        gUnk_02002184 = 5;
        gUnk_0202EFC0 = gUnk_0202A550;
        break;
    case 2:
        gUnk_02002090 = 24;
        gUnk_0202A550[0].unk162 = 0;
        sub_08008A20();
        for (i = 1; i != 24; i++) {
            gUnk_0202A550[i].unk16C = i;
            gUnk_0202A550[i].unk7D = 1;
        }
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        sub_0800F3C0();
        gUnk_02002184 = 10;
        break;
    case 3:
        gUnk_02002090 = 24;
        gUnk_0202A550[0].unk162 = 0;
        sub_08008A20();
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        for (i = 1; i != 24; i++) {
            gUnk_0202A550[i].unk16C = i + 500;
            gUnk_0202A550[i].unk7D = 1;
        }
        sub_0800F3C0();
        gUnk_02002184 = 50;
        gUnk_0202CBD0 = 0;
        break;
    case 4:
        gUnk_0202A550[0].unk162 = 0;
        sub_08008A20();
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        sub_08016D28(0);
        sub_0800F3C0();
        gUnk_02002184 = 2;
        gUnk_02002090 = 1;
        gUnk_0202EFC0 = gUnk_0202A550;
        break;
    case 5:
        gUnk_02002090 = 24;
        gUnk_0202A550[0].unk162 = 11;
        sub_08008A20();
        for (i = 1; i != 24; i++) {
            gUnk_0202A550[i].unk16C = i * 2;
            gUnk_0202A550[i].unk7D = 1;
        }
        gUnk_0202A550[0].unk16C = 8;
        gUnk_0202A550[0].unk7D = 1;
        sub_0800F3C0();
        gUnk_02002184 = 10;
        break;
    case 6:
        gUnk_02002090 = 24;
        gUnk_0202A550[0].unk162 = 4;
        sub_08008A20();
        for (i = 1; i != 15; i++) {
            gUnk_0202A550[i].unk16C = i;
            gUnk_0202A550[i].unk7D = 1;
        }
        gUnk_0202A550[0].unk16C = 15;
        gUnk_0202A550[0].unk7D = 1;
        for (i = 15; i != 24; i++) {
            gUnk_0202A550[i].unk16C = i + 2;
            gUnk_0202A550[i].unk7D = 1;
        }
        sub_0800F3C0();
        gUnk_02002184 = 50;
        break;
    case 7:
        gUnk_02002090 = 1;
        gUnk_0202A550[0].unk162 = 8;
        sub_08008A20();
        for (i = 0; i != 24; i++)
            gUnk_0202A550[i].unk7D = 0;
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        sub_08016D28(0);
        sub_0800F3C0();
        gUnk_02002184 = 5;
        gUnk_0202EFC0 = gUnk_0202A550;
        break;
    case 8:
        gUnk_02002090 = 1;
        gUnk_0202A550[0].unk162 = 0;
        sub_08008A20();
        for (i = 0; i != 24; i++)
            gUnk_0202A550[i].unk7D = 0;
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        sub_08016D28(0);
        sub_0800F3C0();
        gUnk_02002184 = 3;
        gUnk_0202EFC0 = gUnk_0202A550;
        break;
    case 9:
        gUnk_02002090 = 1;
        gUnk_0202A550[0].unk162 = 9;
        sub_08008A20();
        for (i = 0; i != 24; i++)
            gUnk_0202A550[i].unk7D = 0;
        gUnk_0202A550[0].unk16C = 0;
        gUnk_0202A550[0].unk7D = 1;
        sub_08016D28(0);
        sub_0800F3C0();
        gUnk_02002184 = 3;
        gUnk_0202CBD8 = 0;
        gUnk_0202EFC0 = gUnk_0202A550;
        for (i = 0; i != 32; i++)
            gUnk_0202CB40[i] = 0;
        break;
    case 10:
        gUnk_02002090 = 24;
        gUnk_0202A550[0].unk162 = 5;
        sub_08008A20();
        for (i = 1; i != 24; i++) {
            gUnk_0202A550[i].unk16C = i;
            gUnk_0202A550[i].unk7D = 1;
        }
        gUnk_0202A550[0].unk16C = 100;
        gUnk_0202A550[0].unk7D = 1;
        sub_0800F3C0();
        gUnk_02002184 = 25;
        break;
    case 11:
        gUnk_02002090 = 24;
        gUnk_0202A550[0].unk162 = 0;
        sub_08008A20();
        for (i = 1; i != 24; i++) {
            gUnk_0202A550[i].unk16C = i * 5;
            gUnk_0202A550[i].unk7D = 1;
        }
        gUnk_0202A550[0].unk16C = 27;
        gUnk_0202A550[0].unk7D = 1;
        sub_0800F3C0();
        gUnk_02002184 = 20;
        break;
    case 12:
        gUnk_02002090 = 6;
        gUnk_0202A550[0].unk162 = 0;
        sub_08008A20();
        for (i = 1; i != 4; i++) {
            gUnk_0202A550[i].unk16C = i;
            gUnk_0202A550[i].unk7D = 1;
        }
        gUnk_0202A550[0].unk16C = 4;
        gUnk_0202A550[0].unk7D = 1;
        for (i = 4; i != 24; i++) {
            gUnk_0202A550[i].unk16C = i + 10;
            gUnk_0202A550[i].unk7D = 1;
        }
        sub_0800F3C0();
        gUnk_02002184 = 100;
        break;
    case 13:
        gUnk_02002090 = 24;
        for (i = 0; i != 24; i++)
            gUnk_0202A550[i].unk162 = 99;
        gUnk_0202A550[0].unk162 = 1;
        gUnk_0202A550[1].unk162 = 0;
        gUnk_0202A550[2].unk162 = 8;
        sub_08008AB0();
        gUnk_0202A550[0].unk16C = 100;
        gUnk_0202A550[0].unk7D = 1;
        gUnk_0202A550[1].unk16C = 99;
        gUnk_0202A550[1].unk7D = 1;
        gUnk_0202A550[2].unk16C = 98;
        gUnk_0202A550[2].unk7D = 1;
        for (i = 3; i != 24; i++) {
            gUnk_0202A550[i].unk16C = i + 100;
            gUnk_0202A550[i].unk7D = 1;
        }
        sub_0800F3C0();
        gUnk_02002184 = 20;
        break;
    case 14:
        gUnk_02002090 = 24;
        gUnk_0202A550[0].unk162 = 1;
        sub_08008A20();
        for (i = 1; i != 3; i++) {
            gUnk_0202A550[i].unk16C = i;
            gUnk_0202A550[i].unk7D = 1;
        }
        gUnk_0202A550[0].unk16C = 3;
        gUnk_0202A550[0].unk7D = 1;
        for (i = 3; i != 24; i++) {
            gUnk_0202A550[i].unk16C = i + 1;
            gUnk_0202A550[i].unk7D = 1;
        }
        sub_0800F3C0();
        gUnk_02002184 = 20;
        break;
    case 15:
        gUnk_02002090 = 24;
        gUnk_0202A550[0].unk162 = 4;
        sub_08008A20();
        for (i = 1; i != 24; i++) {
            gUnk_0202A550[i].unk16C = i;
            gUnk_0202A550[i].unk7D = 1;
        }
        gUnk_0202A550[0].unk16C = 100;
        gUnk_0202A550[0].unk7D = 1;
        sub_0800F3C0();
        gUnk_02002184 = 40;
        break;
    }
    gUnk_0202EEE4 = 0;
}
