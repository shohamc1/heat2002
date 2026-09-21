#include "global.h"

extern u8 gUnk_0202EF00[];
extern u8 gUnk_0829F2AC[];
extern u8 gUnk_0829F94C[];
extern u16 gKeysPressed;

struct Tbl {
    s32 f00;
    u8 f04;
    u8 pad[3];
};

extern struct Tbl gUnk_083FE114[];

void sub_0800420C(u32 a, u32 b);
void sub_08001208(u16 a);
void sub_08011D2C(u32 a, void *b);
void sub_08006738(u8 *a);
void sub_08006950(u8 *p, u32 a1, u8 a2);
void sub_08004238(void *a, u32 b);
void sub_08016E30(void);
void sub_0800048C(void);
void sub_08015304(void);

void sub_08016330(u8 x)
{
    u8 buf[0x200];
    u16 *p;
    u16 i;
    u8 j, sel, cnt;
    u8 *q;

    p = (u16 *)0x06008000;
    sub_0800420C(0, 0xF);
    sel = 0;
    if (x == 0)
        x = 1;
    cnt = x;
    if (gUnk_0202EF00[2] != 0)
        sub_08001208(1);
    sub_08011D2C(1, buf);
    for (i = 0; i != 0x380; i++)
        *p++ = 0;
    sub_08006738(gUnk_0829F94C);
    j = 0x14;
    for (i = 0; i <= 0x13; i++) {
        sub_08006950(gUnk_0829F2AC, (i + j - 0x14) % 32, 1);
        sub_08006950(gUnk_083FE114[i + j - 0x14].f00, (i + j - 0x14) % 32,
                     gUnk_083FE114[i + j - 0x14].f04);
    }
    sub_08004238(buf, 0xF);
    for (i = 0; i <= 0x13; i++)
        sub_08016E30();
    for (;;) {
        sub_0800048C();
        if (gKeysPressed & 2)
            break;
        if (--cnt == 0) {
            cnt = x;
            if (++sel > 7) {
                sel = 0;
                j++;
                if (j == 0xB6)
                    break;
                q = gUnk_0829F2AC;
                sub_08006950(q, (j - 1) % 32, 1);
                sub_08006950(gUnk_083FE114[j - 1].f00, (j - 1) % 32,
                             gUnk_083FE114[j - 1].f04);
            }
            *(volatile u16 *)0x04000012 = (j - 0x14) * 8 + sel;
        }
        sub_08016E30();
    }
    sub_0800420C(0, 0xF);
    sub_08015304();
}
