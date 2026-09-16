#include "global.h"

struct Car {
    u8 pad00[0x50];
    u32 unk50;
};

extern u8 gUnk_0200215C;
extern u8 gUnk_0202ED70;
extern u8 gUnk_0202CAE8;
extern u8 gUnk_0202EEE4;
extern s32 gUnk_0202CBD8;
extern u8 gUnk_0202CB10;
extern u32 gUnk_0202CB14;
extern struct Car gUnk_0202A550[];

extern void sub_08008CDC(void);
extern u8 sub_08008B40(u32 a);
extern u8 sub_08008B6C(u32 a);
extern void sub_08008B94(void);
extern void sub_08008D20(void);
extern void sub_0800AFF0(void);
extern s32 sub_08008D3C(void);
extern void sub_08008C48(s32 a);
extern void sub_08008CB8(void);

void sub_08008D8C(void)
{
    u8 x;
    s32 v;

    if (gUnk_0200215C == 0x10) {
        sub_08008CDC();
        switch (gUnk_0202ED70) {
        case 0:
            x = gUnk_0202CAE8;
            switch (x) {
            case 0:
                if (sub_08008B40(0xDC)) {
                    gUnk_0202CAE8 = 1;
                    sub_08008D20();
                }
                break;
            case 1:
                if (sub_08008B40(0x15E)) {
                    if (sub_08008B6C(0x2328))
                        gUnk_0202EEE4 = x;
                    sub_0800AFF0();
                    gUnk_0202CAE8 = 0;
                }
                sub_08008B94();
                break;
            }
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            break;
        case 4:
            x = gUnk_0202CAE8;
            switch (x) {
            case 0:
                if (sub_08008B40(0x55)) {
                    gUnk_0202CAE8 = 1;
                    sub_08008D20();
                }
                break;
            case 1:
                if (sub_08008B40(0x96)) {
                    if (sub_08008B6C(0xFA0))
                        gUnk_0202EEE4 = x;
                    sub_0800AFF0();
                    gUnk_0202CAE8 = 0;
                }
                sub_08008B94();
                break;
            }
            break;
        case 9:
            v = sub_08008D3C();
            if (v < 0)
                v = 0;
            if (v > gUnk_0202CBD8)
                gUnk_0202CBD8 = v;
            if (gUnk_0202CBD8 > 0x76) {
                gUnk_0202EEE4 = 1;
                sub_0800AFF0();
            }
            if (gUnk_0202CBD8 > 0x79) {
                if (gUnk_0202CB10 & 8)
                    sub_08008C48(gUnk_0202CBD8);
                else
                    sub_08008CB8();
                gUnk_0202CB10++;
                if (gUnk_0202CB10 > 0x40)
                    sub_0800AFF0();
            } else if (gUnk_0202CBD8 != 0) {
                sub_08008C48(v);
            }
            break;
        }
        gUnk_0202CB14 = gUnk_0202A550[0].unk50 & 0xFFFF;
    }
}
