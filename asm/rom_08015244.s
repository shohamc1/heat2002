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
	thumb_func_start sub_08015244
sub_08015244:
	push {r4, r5, r6, r7, lr}
	ldr r4, _080152B0 @ =0xFFFFFE00
	add sp, r4
	movs r6, #0x00
	bl sub_0800F3C0
	movs r0, #0x00
	mov r1, sp
	bl sub_08011C9C
	bl sub_080150F4
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r5, #0x40
	ldr r7, _080152B4 @ =0x020005CC
_08015268:
	bl sub_0800048C
	bl sub_080150F4
	movs r0, #0x01
	ldrh r1, [r7, #0x00]
	ands r0, r1
	lsls r1, r6, #0x18
	cmp r0, #0x00
	beq _0801527E
	lsrs r5, r1, #0x18
_0801527E:
	ldrh r0, [r7, #0x00]
	asrs r1, r1, #0x18
	movs r2, #0x00
	movs r3, #0x00
	bl sub_08011D38
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	bl sub_08000458
	lsls r4, r5, #0x18
	cmp r5, #0x40
	beq _08015268
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080152B0: .4byte 0xFFFFFE00
_080152B4: .4byte 0x020005CC
	thumb_func_start sub_080152B8
sub_080152B8:
	push {lr}
	ldr r0, _080152CC @ =0x0829F558
	movs r1, #0x28
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_080152CC: .4byte 0x0829F558
	thumb_func_start sub_080152D0
sub_080152D0:
	push {lr}
	ldr r0, _080152E4 @ =0x0829F570
	movs r1, #0x44
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_080152E4: .4byte 0x0829F570
	thumb_func_start sub_080152E8
sub_080152E8:
	push {lr}
	ldr r0, _080152FC @ =0x0829F580
	movs r1, #0x40
	movs r2, #0x4C
	bl sub_08012384
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
_080152FC: .4byte 0x0829F580
	thumb_func_start sub_08015300
sub_08015300:
	bx lr
	.byte 0x00, 0x00
