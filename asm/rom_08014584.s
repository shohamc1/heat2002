@ Generated with Luvdis v0.9.0
.syntax unified
.text
@ Begin embedded Luvdis macros
	.macro arm_func_start name
	.align 2, 0
	.global \name
	.arm
	.type \name, %function
	.endm

	.macro arm_func_end name
	.size \name, .-\name
	.endm

	.macro thumb_func_start name
	.align 2, 0
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro non_word_aligned_thumb_func_start name
	.global \name
	.thumb
	.thumb_func
	.type \name, %function
	.endm

	.macro thumb_func_end name
	.size \name, .-\name
	.endm
@ End embedded Luvdis macros
	.byte 0x00, 0xB5, 0x04, 0x48, 0x54, 0x21, 0x4C, 0x22, 0xFD, 0xF7, 0xFA, 0xFE, 0x00, 0x06, 0x00, 0x0E
	.byte 0x02, 0xBC, 0x08, 0x47, 0x84, 0xF4, 0x29, 0x08, 0x00, 0xB5, 0x04, 0x48, 0x40, 0x21, 0x4C, 0x22
	.byte 0xFD, 0xF7, 0xEE, 0xFE, 0x00, 0x06, 0x00, 0x0E, 0x02, 0xBC, 0x08, 0x47, 0x90, 0xF4, 0x29, 0x08
	.byte 0x00, 0xB5, 0x04, 0x48, 0x38, 0x21, 0x4C, 0x22, 0xFD, 0xF7, 0xE2, 0xFE, 0x00, 0x06, 0x00, 0x0E
	.byte 0x02, 0xBC, 0x08, 0x47, 0xA0, 0xF4, 0x29, 0x08, 0x00, 0xB5, 0x04, 0x48, 0x3C, 0x21, 0x4C, 0x22
	.byte 0xFD, 0xF7, 0xD6, 0xFE, 0x00, 0x06, 0x00, 0x0E, 0x02, 0xBC, 0x08, 0x47, 0xB4, 0xF4, 0x29, 0x08
	.byte 0x00, 0xB5, 0x04, 0x48, 0x20, 0x21, 0x4C, 0x22, 0xFD, 0xF7, 0xCA, 0xFE, 0x00, 0x06, 0x00, 0x0E
	.byte 0x02, 0xBC, 0x08, 0x47, 0xC4, 0xF4, 0x29, 0x08, 0x00, 0xB5, 0x04, 0x48, 0x48, 0x21, 0x4C, 0x22
	.byte 0xFD, 0xF7, 0xBE, 0xFE, 0x00, 0x06, 0x00, 0x0E, 0x02, 0xBC, 0x08, 0x47, 0xDC, 0xF4, 0x29, 0x08
	thumb_func_start sub_08014614
sub_08014614:
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, _08014658 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0xA4
	bl sub_08016558
	bl sub_080065A8
	movs r4, #0x00
	.global _0801462C
_0801462C:
	adds r0, r4, #0x0
	adds r0, #0xA5
	bl sub_08016558
	adds r3, r0, #0x0
	lsls r0, r4, #0x01
	adds r1, r0, #0x6
	movs r2, #0x00
	cmp r5, r4
	bne _08014642
	movs r2, #0x01
	.global _08014642
_08014642:
	adds r0, r3, #0x0
	bl sub_08006950
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x04
	bne _0801462C
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _08014658
_08014658: .4byte 0x083FDE18
	thumb_func_start sub_0801465C
sub_0801465C:
	push {r4, r5, r6, lr}
	ldr r4, _080146F4 @ =0xFFFFFE00
	add sp, r4
	movs r6, #0x00
	movs r0, #0x05
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_08014614
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r5, #0x40
	.global _0801467C
_0801467C:
	bl sub_0800048C
	lsls r4, r6, #0x18
	asrs r0, r4, #0x18
	bl sub_08014614
	ldr r1, _080146F8 @ =0x020005CC
	movs r0, #0x01
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _0801469A
	lsrs r5, r4, #0x18
	ldr r0, _080146FC @ =0x0202EF14
	strb r6, [r0, #0x00]
	.global _0801469A
_0801469A:
	ldr r4, _080146F8 @ =0x020005CC
	ldrh r0, [r4, #0x00]
	lsls r1, r6, #0x18
	asrs r1, r1, #0x18
	movs r2, #0x00
	movs r3, #0x03
	bl sub_08011D38
	lsls r0, r0, #0x18
	ldr r1, _08014700 @ =0x0202EF08
	lsrs r6, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0801469A
	movs r0, #0x02
	ldrh r4, [r4, #0x00]
	ands r0, r4
	cmp r0, #0x00
	beq _080146C6
	movs r5, #0x00
	.global _080146C6
_080146C6:
	bl sub_08000458
	lsls r4, r5, #0x18
	cmp r5, #0x40
	beq _0801467C
	ldr r0, _08014704 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _080146DE
	movs r0, #0x09
	bl sub_08001208
	.global _080146DE
_080146DE:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.global _080146F4
_080146F4: .4byte 0xFFFFFE00
	.global _080146F8
_080146F8: .4byte 0x020005CC
	.global _080146FC
_080146FC: .4byte 0x0202EF14
	.global _08014700
_08014700: .4byte 0x0202EF08
	.global _08014704
_08014704: .4byte 0x0202EF00
	thumb_func_start sub_08014708
sub_08014708:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r9, r1
	ldr r0, _08014858 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	adds r0, r4, #0x0
	adds r0, #0xAE
	bl sub_08016558
	bl sub_080065A8
	lsls r4, r4, #0x1A
	lsrs r4, r4, #0x18
	mov r10, r4
	movs r6, #0x03
	movs r4, #0x00
	mov r7, r9
	ands r7, r6
	ldr r0, _0801485C @ =0x0202EF60
	mov r8, r0
	.global _08014744
_08014744:
	ldr r0, _08014860 @ =0x083FE9EC
	mov r1, r10
	adds r2, r1, r4
	lsls r1, r2, #0x02
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	movs r3, #0x00
	adds r5, r2, #0x0
	cmp r4, r7
	bne _0801475A
	movs r3, #0x01
	.global _0801475A
_0801475A:
	movs r1, #0x00
	adds r2, r6, #0x0
	bl sub_080063BC
	mov r2, r8
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0801477E
	ldr r0, _08014864 @ =0x0829F4EC
	movs r3, #0x00
	cmp r4, r7
	bne _08014776
	movs r3, #0x01
	.global _08014776
_08014776:
	movs r1, #0x16
	adds r2, r6, #0x0
	bl sub_080063BC
	.global _0801477E
_0801477E:
	mov r1, r8
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _0801479A
	ldr r0, _08014864 @ =0x0829F4EC
	movs r3, #0x00
	cmp r4, r7
	bne _08014792
	movs r3, #0x01
	.global _08014792
_08014792:
	movs r1, #0x16
	adds r2, r6, #0x0
	bl sub_080063BC
	.global _0801479A
_0801479A:
	mov r2, r8
	adds r0, r5, r2
	movs r1, #0x00
	ldsb r1, [r0, r1]
	cmp r1, #0x03
	bne _080147BC
	ldr r0, _08014864 @ =0x0829F4EC
	movs r3, #0x00
	mov r2, r9
	ands r1, r2
	cmp r4, r1
	bne _080147B4
	movs r3, #0x01
	.global _080147B4
_080147B4:
	movs r1, #0x16
	adds r2, r6, #0x0
	bl sub_080063BC
	.global _080147BC
_080147BC:
	mov r1, r8
	adds r0, r5, r1
	movs r1, #0x00
	ldsb r1, [r0, r1]
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	bne _080147DE
	ldr r0, _08014868 @ =0x0829F4F4
	movs r3, #0x00
	cmp r4, r7
	bne _080147D6
	movs r3, #0x01
	.global _080147D6
_080147D6:
	movs r1, #0x16
	adds r2, r6, #0x0
	bl sub_080063BC
	.global _080147DE
_080147DE:
	mov r2, r8
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	bne _080147FE
	ldr r0, _0801486C @ =0x0829F4FC
	movs r3, #0x00
	cmp r4, r7
	bne _080147F6
	movs r3, #0x01
	.global _080147F6
_080147F6:
	movs r1, #0x16
	adds r2, r6, #0x0
	bl sub_080063BC
	.global _080147FE
_080147FE:
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x04
	bne _08014744
	movs r6, #0x08
	mov r1, r9
	lsls r0, r1, #0x02
	add r0, r9
	lsls r0, r0, #0x19
	lsrs r4, r0, #0x18
	mov r10, r4
	adds r0, r4, #0x0
	adds r0, #0x0A
	cmp r4, r0
	beq _0801484A
	ldr r5, _08014870 @ =0x083FEA2C
	.global _08014826
_08014826:
	lsls r0, r4, #0x02
	adds r0, r0, r5
	ldr r0, [r0, #0x00]
	movs r1, #0x00
	adds r2, r6, #0x0
	movs r3, #0x01
	bl sub_080063BC
	adds r0, r6, #0x1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r0, r10
	adds r0, #0x0A
	cmp r4, r0
	bne _08014826
	.global _0801484A
_0801484A:
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _08014858
_08014858: .4byte 0x083FDE18
	.global _0801485C
_0801485C: .4byte 0x0202EF60
	.global _08014860
_08014860: .4byte 0x083FE9EC
	.global _08014864
_08014864: .4byte 0x0829F4EC
	.global _08014868
_08014868: .4byte 0x0829F4F4
	.global _0801486C
_0801486C: .4byte 0x0829F4FC
	.global _08014870
_08014870: .4byte 0x083FEA2C
	thumb_func_start sub_08014874
sub_08014874:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08014934 @ =0xFFFFFE00
	add sp, r4
	adds r4, r1, #0x0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r5, r4, #0x18
	movs r0, #0x05
	mov r1, sp
	bl sub_08011C9C
	adds r1, r5, #0x0
	adds r0, r7, #0x0
	bl sub_08014708
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r0, #0x40
	mov r8, r0
	lsrs r4, r4, #0x1A
	lsls r3, r4, #0x12
	mov r10, r3
	lsls r4, r4, #0x02
	adds r4, #0x03
	lsls r4, r4, #0x10
	mov r9, r4
	.global _080148B6
_080148B6:
	bl sub_0800048C
	adds r1, r5, #0x0
	adds r0, r7, #0x0
	bl sub_08014708
	.global _080148C2
_080148C2:
	ldr r6, _08014938 @ =0x020005CC
	ldrh r0, [r6, #0x00]
	lsls r1, r5, #0x18
	asrs r1, r1, #0x18
	mov r4, r10
	asrs r2, r4, #0x10
	mov r4, r9
	asrs r3, r4, #0x10
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _0801493C @ =0x0202EF60
	lsls r4, r5, #0x18
	asrs r0, r4, #0x18
	adds r0, r0, r1
	movs r1, #0x00
	ldsb r1, [r0, r1]
	movs r0, #0x01
	negs r0, r0
	cmp r1, r0
	beq _080148C2
	movs r0, #0x03
	ldrh r6, [r6, #0x00]
	ands r0, r6
	cmp r0, #0x00
	beq _080148FC
	movs r0, #0x01
	mov r8, r0
	.global _080148FC
_080148FC:
	bl sub_08000458
	mov r3, r8
	cmp r3, #0x40
	beq _080148B6
	ldr r0, _08014940 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08014914
	movs r0, #0x09
	bl sub_08001208
	.global _08014914
_08014914:
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
	.global _08014934
_08014934: .4byte 0xFFFFFE00
	.global _08014938
_08014938: .4byte 0x020005CC
	.global _0801493C
_0801493C: .4byte 0x0202EF60
	.global _08014940
_08014940: .4byte 0x0202EF00
	thumb_func_start sub_08014944
sub_08014944:
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0x0
	ldr r0, _080149A0 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x0D
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x05
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _0801496C
	movs r2, #0x01
	.global _0801496C
_0801496C:
	movs r1, #0x08
	bl sub_08006950
	movs r0, #0x0E
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08014980
	movs r2, #0x01
	.global _08014980
_08014980:
	movs r1, #0x0A
	bl sub_08006950
	movs r0, #0x08
	bl sub_08016558
	movs r2, #0x00
	cmp r5, #0x02
	bne _08014994
	movs r2, #0x01
	.global _08014994
_08014994:
	movs r1, #0x0C
	bl sub_08006950
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _080149A0
_080149A0: .4byte 0x083FDE18
	.byte 0xF0, 0xB5, 0x21, 0x4C, 0xA5, 0x44, 0x00, 0x24, 0x05, 0x20, 0x69, 0x46, 0xFD, 0xF7, 0x74, 0xF9
	.byte 0x00, 0x20, 0xFF, 0xF7, 0xC5, 0xFF, 0x68, 0x46, 0x0F, 0x21, 0xEF, 0xF7, 0x3B, 0xFC, 0x40, 0x26
	.byte 0x1A, 0x4F, 0xEB, 0xF7, 0x61, 0xFD, 0x25, 0x06, 0x2C, 0x0E, 0x20, 0x1C, 0xFF, 0xF7, 0xB8, 0xFF
	.byte 0x01, 0x20, 0x39, 0x88, 0x08, 0x40, 0x00, 0x28, 0x00, 0xD0, 0x26, 0x1C, 0x38, 0x88, 0x29, 0x16
	.byte 0x00, 0x22, 0x02, 0x23, 0xFD, 0xF7, 0xA6, 0xF9, 0x00, 0x06, 0x04, 0x0E, 0x02, 0x20, 0x39, 0x88
	.byte 0x08, 0x40, 0x00, 0x28, 0x00, 0xD0, 0x00, 0x26, 0xEB, 0xF7, 0x2C, 0xFD, 0x35, 0x06, 0x40, 0x2E
	.byte 0xDF, 0xD0, 0x0B, 0x48, 0xC0, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x09, 0x20, 0xEC, 0xF7, 0xFA, 0xFB
	.byte 0x00, 0x20, 0x0F, 0x21, 0xEF, 0xF7, 0xF8, 0xFB, 0x28, 0x0E, 0x80, 0x23, 0x9B, 0x00, 0x9D, 0x44
	.byte 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xCC, 0x05, 0x00, 0x02
	.byte 0x00, 0xEF, 0x02, 0x02
	thumb_func_start sub_08014A38
sub_08014A38:
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0x0
	ldr r0, _08014A80 @ =0x083FDE18
	ldr r0, [r0, #0x00]
	bl sub_08006734
	movs r0, #0x4E
	bl sub_08016558
	bl sub_080065A8
	movs r0, #0x5F
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x00
	bne _08014A60
	movs r2, #0x01
	.global _08014A60
_08014A60:
	movs r1, #0x08
	bl sub_08006950
	movs r0, #0x5E
	bl sub_08016558
	movs r2, #0x00
	cmp r4, #0x01
	bne _08014A74
	movs r2, #0x01
	.global _08014A74
_08014A74:
	movs r1, #0x0A
	bl sub_08006950
	pop {r4}
	pop {r0}
	bx r0
	.global _08014A80
_08014A80: .4byte 0x083FDE18
