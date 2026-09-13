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
	thumb_func_start sub_0800C534
sub_0800C534:
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x038
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	bl sub_08008394
	adds r0, r5, #0x0
	bl sub_0800C430
	movs r0, #0x00
	mov r9, r0
	ldr r0, _0800C588 @ =0x0202CC28
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800C574
	ldr r0, _0800C58C @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0800C574
	cmp r0, #0x0D
	beq _0800C574
	cmp r0, #0x0E
	beq _0800C574
	cmp r0, #0x0F
	beq _0800C574
	cmp r0, #0x11
	bne _0800C590
	.global _0800C574
_0800C574:
	adds r1, r5, #0x0
	adds r1, #0xA0
	movs r2, #0x00
	movs r0, #0x01
	strh r0, [r1, #0x00]
	ldr r0, _0800C588 @ =0x0202CC28
	strb r2, [r0, #0x00]
	adds r7, r1, #0x0
	b _0800C602
	.byte 0x00, 0x00
	.global _0800C588
_0800C588: .4byte 0x0202CC28
	.global _0800C58C
_0800C58C: .4byte 0x0200215C
	.global _0800C590
_0800C590:
	ldr r1, _0800C5B0 @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800C5B8
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x28
	ble _0800C5B8
	adds r1, r5, #0x0
	adds r1, #0xA0
	ldr r0, _0800C5B4 @ =0x0000FFFE
	ldrh r2, [r1, #0x00]
	ands r0, r2
	b _0800C5BE
	.global _0800C5B0
_0800C5B0: .4byte 0x00000175
	.global _0800C5B4
_0800C5B4: .4byte 0x0000FFFE
	.global _0800C5B8
_0800C5B8:
	adds r1, r5, #0x0
	adds r1, #0xA0
	movs r0, #0x01
	.global _0800C5BE
_0800C5BE:
	strh r0, [r1, #0x00]
	adds r7, r1, #0x0
	ldr r3, _0800C7D8 @ =0x00000175
	adds r0, r5, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800C602
	ldr r0, _0800C7DC @ =0x0202CC2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800C5D8
	movs r0, #0x02
	strh r0, [r7, #0x00]
	.global _0800C5D8
_0800C5D8:
	ldr r0, _0800C7E0 @ =0x0202CC28
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800C602
	adds r2, r5, #0x0
	adds r2, #0xF0
	ldr r0, [r2, #0x00]
	subs r0, #0x20
	ldr r1, _0800C7E4 @ =0x000007FF
	ands r0, r1
	str r0, [r2, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x01
	cmp r0, r1
	bgt _0800C5FA
	ldr r0, _0800C7E8 @ =0x000006FF
	str r0, [r2, #0x00]
	.global _0800C5FA
_0800C5FA:
	ldr r1, [r2, #0x00]
	adds r0, r5, #0x0
	bl sub_0800BE00
	.global _0800C602
_0800C602:
	adds r0, r5, #0x0
	bl sub_0800C28C
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl sub_0800C358
	mov r8, r0
	movs r0, #0x01
	negs r0, r0
	cmp r8, r0
	bne _0800C61C
	b _0800C968
	.global _0800C61C
_0800C61C:
	ldr r0, _0800C7EC @ =0x0202CC24
	ldr r0, [r0, #0x00]
	ldr r1, _0800C7F0 @ =0x0202CC38
	ldr r1, [r1, #0x00]
	adds r6, r5, #0x0
	adds r6, #0xF4
	ldr r2, [r6, #0x00]
	ldr r3, _0800C7F4 @ =0x0202CC3C
	ldr r3, [r3, #0x00]
	ldr r4, _0800C7F8 @ =0x0202CC34
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	bl sub_0800BBFC
	adds r1, r0, #0x0
	adds r1, #0x40
	movs r4, #0xAA
	lsls r4, r4, #0x01
	adds r0, r5, r4
	ldr r0, [r0, #0x00]
	cmp r1, r0
	blt _0800C64A
	subs r1, r1, r0
	.global _0800C64A
_0800C64A:
	add r4, sp, #0x02C
	ldr r2, [r6, #0x00]
	adds r0, r5, #0x0
	adds r0, #0xF8
	ldr r3, [r0, #0x00]
	adds r0, r1, #0x0
	adds r1, r4, #0x0
	bl sub_0800BD98
	ldr r0, _0800C7D8 @ =0x00000175
	adds r6, r5, r0
	ldrb r0, [r6, #0x00]
	mov r10, r4
	cmp r0, #0x00
	beq _0800C748
	cmp r0, #0x01
	bne _0800C68C
	adds r0, r5, #0x0
	bl sub_0800C4E0
	cmp r0, #0x63
	ble _0800C688
	ldr r0, _0800C7FC @ =0x020020CC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0800C68C
	adds r0, r5, #0x0
	bl sub_0800C4E0
	cmp r0, #0xC7
	bgt _0800C68C
	.global _0800C688
_0800C688:
	movs r0, #0x02
	strb r0, [r6, #0x00]
	.global _0800C68C
_0800C68C:
	ldr r1, _0800C7D8 @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x02
	bne _0800C6F4
	adds r0, r5, #0x0
	bl sub_0800C4E0
	cmp r0, #0x13
	ble _0800C6BE
	ldr r0, _0800C800 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800C6BE
	ldr r0, _0800C804 @ =0x0202A550
	cmp r5, r0
	bne _0800C6C6
	ldr r0, _0800C808 @ =0x0202CAD0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800C6C6
	ldr r0, _0800C80C @ =0x0202A53C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800C6C6
	.global _0800C6BE
_0800C6BE:
	ldr r2, _0800C7D8 @ =0x00000175
	adds r1, r5, r2
	movs r0, #0x03
	strb r0, [r1, #0x00]
	.global _0800C6C6
_0800C6C6:
	ldr r2, _0800C810 @ =0x083672F0
	ldr r1, _0800C7FC @ =0x020020CC
	ldrb r3, [r1, #0x00]
	lsls r0, r3, #0x03
	ldr r4, _0800C814 @ =0x00000181
	adds r3, r5, r4
	ldrb r4, [r3, #0x00]
	adds r0, r4, r0
	lsls r0, r0, #0x03
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x02C]
	ldrb r1, [r1, #0x00]
	lsls r0, r1, #0x03
	ldrb r3, [r3, #0x00]
	adds r0, r3, r0
	lsls r0, r0, #0x01
	adds r0, #0x01
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	mov r1, r10
	str r0, [r1, #0x04]
	.global _0800C6F4
_0800C6F4:
	ldr r2, _0800C7D8 @ =0x00000175
	adds r1, r5, r2
	ldrb r3, [r1, #0x00]
	cmp r3, #0x03
	bne _0800C748
	ldr r0, _0800C800 @ =0x0202EEB0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800C70A
	movs r0, #0x04
	strb r0, [r1, #0x00]
	.global _0800C70A
_0800C70A:
	ldr r4, _0800C810 @ =0x083672F0
	ldr r0, _0800C7FC @ =0x020020CC
	ldrb r0, [r0, #0x00]
	lsls r3, r0, #0x03
	adds r1, r3, #0x6
	lsls r0, r1, #0x03
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	lsls r1, r1, #0x01
	adds r1, #0x01
	lsls r1, r1, #0x02
	adds r1, r1, r4
	ldr r1, [r1, #0x00]
	adds r3, #0x07
	lsls r2, r3, #0x03
	adds r2, r2, r4
	ldr r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r3, r3, #0x01
	adds r3, #0x01
	lsls r3, r3, #0x02
	adds r3, r3, r4
	ldr r2, [r3, #0x00]
	subs r1, r1, r2
	bl sub_0800CB18
	lsls r0, r0, #0x08
	movs r1, #0x84
	lsls r1, r1, #0x08
	subs r0, r1, r0
	str r0, [sp, #0x034]
	.global _0800C748
_0800C748:
	movs r1, #0x04
	ldr r0, _0800C818 @ =0x0200215C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x09
	beq _0800C762
	cmp r0, #0x0D
	beq _0800C762
	cmp r0, #0x0E
	beq _0800C762
	cmp r0, #0x0F
	beq _0800C762
	cmp r0, #0x11
	bne _0800C766
	.global _0800C762
_0800C762:
	movs r1, #0x63
	negs r1, r1
	.global _0800C766
_0800C766:
	cmp r8, r1
	bgt _0800C776
	ldr r4, _0800C7D8 @ =0x00000175
	adds r0, r5, r4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0800C776
	b _0800C90A
	.global _0800C776
_0800C776:
	ldr r0, [sp, #0x02C]
	lsls r0, r0, #0x10
	ldr r1, [r5, #0x00]
	subs r3, r0, r1
	mov r0, r10
	ldr r1, [r0, #0x04]
	lsls r1, r1, #0x10
	ldr r0, [r5, #0x08]
	subs r1, r1, r0
	asrs r0, r3, #0x05
	asrs r1, r1, #0x05
	bl sub_0800CB18
	lsls r0, r0, #0x08
	movs r1, #0x84
	lsls r1, r1, #0x08
	subs r4, r1, r0
	ldr r1, _0800C7D8 @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0800C7BE
	ldrh r2, [r5, #0x34]
	subs r1, r4, r2
	cmp r1, #0x00
	bge _0800C7AC
	negs r1, r1
	.global _0800C7AC
_0800C7AC:
	movs r0, #0x80
	lsls r0, r0, #0x07
	cmp r1, r0
	ble _0800C7BE
	strh r4, [r5, #0x34]
	movs r3, #0x96
	lsls r3, r3, #0x01
	adds r0, r5, r3
	str r4, [r0, #0x00]
	.global _0800C7BE
_0800C7BE:
	ldr r1, _0800C7D8 @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0800C81C
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r0, [r0, #0x00]
	ldr r1, [sp, #0x034]
	subs r3, r1, r0
	b _0800C826
	.byte 0x00, 0x00
	.global _0800C7D8
_0800C7D8: .4byte 0x00000175
	.global _0800C7DC
_0800C7DC: .4byte 0x0202CC2C
	.global _0800C7E0
_0800C7E0: .4byte 0x0202CC28
	.global _0800C7E4
_0800C7E4: .4byte 0x000007FF
	.global _0800C7E8
_0800C7E8: .4byte 0x000006FF
	.global _0800C7EC
_0800C7EC: .4byte 0x0202CC24
	.global _0800C7F0
_0800C7F0: .4byte 0x0202CC38
	.global _0800C7F4
_0800C7F4: .4byte 0x0202CC3C
	.global _0800C7F8
_0800C7F8: .4byte 0x0202CC34
	.global _0800C7FC
_0800C7FC: .4byte 0x020020CC
	.global _0800C800
_0800C800: .4byte 0x0202EEB0
	.global _0800C804
_0800C804: .4byte 0x0202A550
	.global _0800C808
_0800C808: .4byte 0x0202CAD0
	.global _0800C80C
_0800C80C: .4byte 0x0202A53C
	.global _0800C810
_0800C810: .4byte 0x083672F0
	.global _0800C814
_0800C814: .4byte 0x00000181
	.global _0800C818
_0800C818: .4byte 0x0200215C
	.global _0800C81C
_0800C81C:
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r0, [r0, #0x00]
	subs r3, r4, r0
	.global _0800C826
_0800C826:
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	ldr r1, _0800C8AC @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0800C878
	ldr r2, [sp, #0x034]
	ldrh r0, [r5, #0x34]
	subs r1, r2, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, r1, #0x0
	cmp r1, #0x00
	bge _0800C846
	negs r2, r1
	.global _0800C846
_0800C846:
	ldr r0, _0800C8B0 @ =0x000003FF
	cmp r2, r0
	ble _0800C870
	ldr r0, _0800C8B4 @ =0x020020CC
	ldrb r2, [r0, #0x00]
	cmp r2, #0x03
	beq _0800C870
	cmp r2, #0x01
	beq _0800C870
	cmp r2, #0x09
	beq _0800C870
	cmp r1, #0x00
	bge _0800C862
	negs r1, r1
	.global _0800C862
_0800C862:
	ldr r0, _0800C8B8 @ =0x00000FFF
	cmp r1, r0
	bgt _0800C878
	cmp r2, #0x04
	beq _0800C870
	cmp r2, #0x02
	bne _0800C878
	.global _0800C870
_0800C870:
	ldr r2, _0800C8AC @ =0x00000175
	adds r1, r5, r2
	movs r0, #0x04
	strb r0, [r1, #0x00]
	.global _0800C878
_0800C878:
	ldr r1, _0800C8AC @ =0x00000175
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	ldr r1, _0800C8BC @ =0x0202CC28
	cmp r0, #0x00
	bne _0800C894
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _0800C89A
	adds r0, r3, #0x0
	cmp r3, #0x00
	bge _0800C892
	adds r0, r3, #0x7
	.global _0800C892
_0800C892:
	asrs r3, r0, #0x03
	.global _0800C894
_0800C894:
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _0800C89C
	.global _0800C89A
_0800C89A:
	lsls r3, r3, #0x02
	.global _0800C89C
_0800C89C:
	ldr r0, [r5, #0x2C]
	cmp r0, #0x00
	ble _0800C8C0
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r1, r5, r2
	negs r0, r4
	b _0800C8CA
	.global _0800C8AC
_0800C8AC: .4byte 0x00000175
	.global _0800C8B0
_0800C8B0: .4byte 0x000003FF
	.global _0800C8B4
_0800C8B4: .4byte 0x020020CC
	.global _0800C8B8
_0800C8B8: .4byte 0x00000FFF
	.global _0800C8BC
_0800C8BC: .4byte 0x0202CC28
	.global _0800C8C0
_0800C8C0:
	movs r4, #0x96
	lsls r4, r4, #0x01
	adds r1, r5, r4
	ldr r0, [r1, #0x00]
	adds r0, r0, r3
	.global _0800C8CA
_0800C8CA:
	str r0, [r1, #0x00]
	adds r1, r3, #0x0
	cmp r3, #0x00
	bge _0800C8D4
	negs r1, r3
	.global _0800C8D4
_0800C8D4:
	movs r0, #0xFA
	lsls r0, r0, #0x01
	cmp r1, r0
	ble _0800C8EE
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x28
	ble _0800C8EE
	ldr r0, _0800C978 @ =0x0000FFFE
	ldrh r1, [r7, #0x00]
	ands r0, r1
	strh r0, [r7, #0x00]
	.global _0800C8EE
_0800C8EE:
	adds r1, r3, #0x0
	cmp r1, #0x00
	bge _0800C8F6
	negs r1, r1
	.global _0800C8F6
_0800C8F6:
	ldr r0, _0800C97C @ =0x0000028A
	cmp r1, r0
	ble _0800C90A
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x28
	ble _0800C90A
	movs r0, #0x02
	strh r0, [r7, #0x00]
	.global _0800C90A
_0800C90A:
	ldr r2, _0800C980 @ =0x00000175
	adds r0, r5, r2
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _0800C922
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x50
	ble _0800C922
	movs r0, #0x02
	strh r0, [r7, #0x00]
	.global _0800C922
_0800C922:
	ldr r3, _0800C980 @ =0x00000175
	adds r0, r5, r3
	ldrb r1, [r0, #0x00]
	cmp r1, #0x02
	bne _0800C938
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x28
	ble _0800C938
	strh r1, [r7, #0x00]
	.global _0800C938
_0800C938:
	ldr r4, _0800C980 @ =0x00000175
	adds r0, r5, r4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x03
	bne _0800C950
	ldr r0, [r5, #0x2C]
	negs r0, r0
	asrs r0, r0, #0x0C
	cmp r0, #0x0A
	ble _0800C950
	movs r0, #0x02
	strh r0, [r7, #0x00]
	.global _0800C950
_0800C950:
	mov r0, r9
	cmp r0, #0x00
	beq _0800C968
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r9, r0
	movs r2, #0x96
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r0, [r1, #0x00]
	add r0, r9
	str r0, [r1, #0x00]
	.global _0800C968
_0800C968:
	add sp, #0x038
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800C978
_0800C978: .4byte 0x0000FFFE
	.global _0800C97C
_0800C97C: .4byte 0x0000028A
	.global _0800C980
_0800C980: .4byte 0x00000175
