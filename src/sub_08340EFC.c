#include "global.h"
#include "functions.h"

struct Car {
    u8 pad00[0x50];
    u32 unk50;
};

extern u8 gUnk_0203916C[];
extern u8 gUnk_0203DFB0;
extern u8 gUnk_0203DD08;
extern u8 gUnk_0203E104;
extern s32 gUnk_0203DDF8;
extern u8 gUnk_0203DD30;
extern u32 gUnk_0203DD34;
extern struct Car gUnk_0203D520[];


void sub_08340EFC(void)
{
    u8 x;
    s32 v;

    if (gUnk_0203916C[0] == 0x10) {
        sub_08340E4C();
        switch (gUnk_0203DFB0) {
        case 0:
            x = gUnk_0203DD08;
            switch (x) {
            case 0:
                if (sub_08340CB0(0xDC)) {
                    gUnk_0203DD08 = 1;
                    sub_08340E90();
                }
                break;
            case 1:
                if (sub_08340CB0(0x15E)) {
                    /* sub_08340CDC: this file's old prototype returns u8;
                       the matched definition returns u32 */
                    if (((u8 (*)(u32))sub_08340CDC)(0x2328))
                        gUnk_0203E104 = x;
                    sub_08342908();
                    gUnk_0203DD08 = 0;
                }
                sub_08340D04();
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
            x = gUnk_0203DD08;
            switch (x) {
            case 0:
                if (sub_08340CB0(0x55)) {
                    gUnk_0203DD08 = 1;
                    sub_08340E90();
                }
                break;
            case 1:
                if (sub_08340CB0(0x96)) {
                    if (((u8 (*)(u32))sub_08340CDC)(0xFA0))
                        gUnk_0203E104 = x;
                    sub_08342908();
                    gUnk_0203DD08 = 0;
                }
                sub_08340D04();
                break;
            }
            break;
        case 9:
            v = sub_08340EAC();
            if (v < 0)
                v = 0;
            if (v > gUnk_0203DDF8)
                gUnk_0203DDF8 = v;
            if (gUnk_0203DDF8 > 0x76) {
                gUnk_0203E104 = 1;
                sub_08342908();
            }
            if (gUnk_0203DDF8 > 0x79) {
                if (gUnk_0203DD30 & 8)
                    sub_08340DB8(gUnk_0203DDF8);
                else
                    sub_08340E28();
                gUnk_0203DD30++;
                if (gUnk_0203DD30 > 0x40)
                    sub_08342908();
            } else if (gUnk_0203DDF8 != 0) {
                sub_08340DB8(v);
            }
            break;
        }
        gUnk_0203DD34 = gUnk_0203D520[0].unk50 & 0xFFFF;
    }
}
