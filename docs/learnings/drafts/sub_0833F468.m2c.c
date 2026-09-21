? sub_0833E05C();                                   /* extern */
? sub_0833E094(u8);                                 /* extern */
? sub_0833E160(u16, u16, u16);                      /* extern */
? sub_08341EC8(void *);                             /* extern */
? sub_08342908();                                   /* extern */
? sub_08342A94();                                   /* extern */
? sub_08342BA4(u16, u16, u16);                      /* extern */
? sub_08342D10();                                   /* extern */
u32 sub_08344BB8(s32, s32);                         /* extern */

s32 sub_0833F468(void *arg0, u8 arg1) {
    s32 sp28;
    s32 sp54;
    u32 sp58;
    s32 sp5C;
    s32 sp60;
    void *sp64;
    s32 sp68;
    s32 sp6C;
    u8 *sp70;
    s32 sp74;
    u8 *sp78;
    u8 *sp7C;
    u8 *sp80;
    s32 sp84;
    s32 sp88;
    s32 sp8C;
    s32 sp90;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r2_2;
    s32 temp_r2_3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r5_3;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 temp_r6_3;
    s32 temp_r6_4;
    u16 temp_r2_4;
    u16 temp_r3_4;
    u16 temp_r5_4;
    u32 temp_r1;
    u8 *var_r0_2;
    u8 temp_r0_5;
    u8 temp_r0_6;
    u8 temp_r3;
    u8 var_r0;
    void *temp_r0;
    void *temp_r2;
    void *var_r3;

    sp54 = (s32) arg1;
    sp58 = (u32) (u8) (3 - *(u8 *)0x0203E120);
    *(s8 *)0x020390CC = 0;
    if (*(u8 *)0x020390EC != 0) {
        var_r0 = *(u8 *)0x0203E1B0;
    } else {
        var_r0 = 0;
    }
    sp6C = (s32) var_r0;
    if (*(u8 *)0x020390EC != 0) {
        var_r0_2 = (u8 *)0x020390BC;
    } else {
        var_r0_2 = (u8 *)0x020390A0;
    }
    sp68 = (s32) *var_r0_2;
    temp_r2 = *(void **)0x0203B860;
    temp_r0 = temp_r2 + (arg0->unk4D * 0x18);
    sp64 = temp_r0;
    var_r3 = temp_r0 + 0x18;
    sp7C = arg0 + 0x4D;
    if (temp_r0->unk10 == 1) {
        var_r3 = temp_r2;
    }
    temp_r5 = arg0->unk0;
    sp28 = temp_r5 >> 0x10;
    temp_r6 = arg0->unk8;
    temp_r0_2 = temp_r6 >> 0x10;
    sp28.unk4 = temp_r0_2;
    temp_r5_2 = (s32) (temp_r5 + arg0->unkC) >> 0x10;
    sp28.unk8 = temp_r5_2;
    temp_r6_2 = (s32) (temp_r6 + arg0->unk14) >> 0x10;
    sp90 = temp_r6_2;
    sp28.unkC = temp_r6_2;
    sp84 = sp64->unk4;
    temp_r6_3 = sp64->unkC;
    sp88 = temp_r6_3;
    sp70 = arg0 + 0x4E;
    temp_r3 = arg0->unk4E;
    temp_r2_2 = 0x10 - temp_r3;
    temp_r0_3 = (s32) ((sp64->unk0 * temp_r2_2) + (var_r3->unk0 * temp_r3)) >> 4;
    sp5C = temp_r0_3;
    sp8C = (s32) ((sp64->unk8 * temp_r2_2) + (var_r3->unk8 * temp_r3)) >> 4;
    sp60 = (s32) ((sp84 * temp_r2_2) + (var_r3->unk4 * temp_r3)) >> 4;
    arg0->unk50 = (s32) (((s8) arg0->unk4C << 0x10) + (*sp7C * 0x10) + temp_r3);
    temp_r0_4 = temp_r5_2 - sp28;
    sp74 = temp_r0_4;
    temp_r2_3 = ((s32) ((temp_r2_2 * temp_r6_3) + (var_r3->unkC * temp_r3)) >> 4) - sp60;
    temp_r3_2 = sp90 - temp_r0_2;
    temp_r3_3 = sp8C - temp_r0_3;
    temp_r4 = (temp_r0_4 * temp_r2_3) - (temp_r3_2 * temp_r3_3);
    sp80 = sp70;
    sp78 = arg0 + 0x4C;
    if ((temp_r4 == 0) || (temp_r6_4 = temp_r0_2 - sp60, temp_r5_3 = sp28 - sp5C, (sub_08344BB8(((temp_r6_4 * temp_r3_3) - (temp_r5_3 * temp_r2_3)) << 8, temp_r4) > 0x100U)) || (sub_08344BB8(((temp_r6_4 * sp74) - (temp_r3_2 * temp_r5_3)) << 8, temp_r4) > 0x100U)) {
        return 0;
    }
    if (arg0->unk174 == 0) {
        arg0->unk174 = 1U;
        *(u8 *)0x0203DD10 += 1;
    }
    *sp80 += 1;
    *(void *)0x020390CC = 1;
    arg0->unk50 = (s32) (*sp80 + ((M2C_ERROR(/* unknown instruction: ldsb $r0, ($mem_loc_fictive_) */) << 0x10) + (*sp7C * 0x10)));
    if (*sp80 != 0x10) {

    } else {
        *sp80 = 0;
        arg0->unk36 = (u16) arg0->unk34;
        arg0->unk38 = (s16) *sp7C;
        temp_r3_4 = sp64->unk10;
        if (temp_r3_4 != 1) {

        } else {
            if ((*(u8 *)0x0203916C == 0xC) && ((u32) (*(u16 *)0x0203B858 + ((*(u16 *)0x0203B6C8 * 0xEA60) + (*(u16 *)0x0203B6A8 * 0x3E8))) < (u32) *(u32 *)0x0203DFC4)) {
                *(s8 *)0x0203E104 = (s8) temp_r3_4;
            }
            if ((sp54 == sp6C) && (*(u8 *)0x0203916C != 0xC) && (arg0->unk166 != 0)) {
                arg0->unk167 = 0x1E;
                arg0->unk168 = (u8) (arg0->unk168 + 1);
            }
            *sp78 += 1;
            *sp7C = -1U;
            *sp80 = 0;
            arg0->unk50 = (s32) ((M2C_ERROR(/* unknown instruction: ldsb $r0, ($mem_loc_fictive_) */) << 0x10) + (*sp7C * 0x10));
            if ((sp54 == sp6C) && (*(u8 *)0x0203E1E0 != 0) && (arg0->unk18E != 0)) {
                sub_0833E160(*(void *)0x0203B6C8, *(void *)0x0203B6A8, *(void *)0x0203B858);
            }
            arg0->unk166 = 1U;
            if ((arg0 == (void *)0x0203D520) && (*(void *)0x0203916C == 5) && (arg0->unk18E != 0)) {
                temp_r1 = *(void *)0x0203B858 + ((*(void *)0x0203B6C8 * 0xEA60) + (*(void *)0x0203B6A8 * 0x3E8));
                if (temp_r1 < (u32) arg0->unk16C) {
                    arg0->unk16C = temp_r1;
                }
            }
            if (M2C_ERROR(/* unknown instruction: ldsb $r1, ($mem_loc_fictive_) */) != *(u8 *)0x02039194) {
                if (sp54 == sp6C) {
                    if (arg0->unk18E != 0) {
                        sub_08342BA4(*(void *)0x0203B6C8, *(void *)0x0203B6A8, *(void *)0x0203B858);
                    }
                    goto block_55;
                }
            } else {
                temp_r0_5 = *(void *)0x0203916C;
                if ((temp_r0_5 == 0) || (temp_r0_5 == 6) || (temp_r0_5 == 1)) {
                    arg0->unk16C = (u32) (*(u16 *)0x0203B6D4 + ((*(u16 *)0x0203B704 * 0xEA60) + (*(u16 *)0x0203B6D0 * 0x3E8)));
                }
                if ((sp54 == sp6C) && (arg0->unk18E != 0)) {
                    sub_08342BA4(*(void *)0x0203B6C8, *(void *)0x0203B6A8, *(void *)0x0203B858);
                }
                if (*(void *)0x0203916C != 2) {
                    sub_08341EC8(arg0);
                    *(0x0203B868 + *(u8 *)0x0203B864) = (u8) sp54;
                    *(u8 *)0x0203B864 += 1;
                    if ((u32) (u8) (*(void *)0x0203916C - 3) <= 1U) {
                        arg0->unk16C = (u32) (*(void *)0x0203B6D4 + ((*(void *)0x0203B704 * 0xEA60) + (*(void *)0x0203B6D0 * 0x3E8)));
                    }
                    if (*(u8 *)0x0203B864 == sp68) {
                        temp_r0_6 = *(void *)0x0203916C;
                        if ((temp_r0_6 != 0x10) && (temp_r0_6 != 0xF) && (temp_r0_6 != 2) && (temp_r0_6 != 0xE)) {
                            sub_08342908();
                        }
                    }
                }
block_55:
                if (sp54 == sp6C) {
                    sub_0833E05C();
                }
            }
        }
        temp_r2_4 = sp64->unk10;
        if ((u32) (u16) (temp_r2_4 - 1) <= 1U) {
            if (sp54 == sp6C) {
                *(s32 *)0x0203DE40 = arg0->unk15C;
                if (temp_r2_4 != 1) {
                    sub_08342D10();
                }
                if (*(void *)0x0203916C != 0xA) {
                    sub_0833E094((u8) (sp64->unk14 + ((sp58 >> 1) + 6)));
                }
            }
            temp_r5_4 = sp64->unk10;
            if ((temp_r5_4 == 1) && (arg0->unk18E == 0)) {
                if (arg0 == (void *)0x0203D520) {
                    sub_08342A94();
                }
                arg0->unk18E = (u8) temp_r5_4;
            }
        }
        *sp7C += 1;
    }
    return 1;
}
