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
	thumb_func_start sub_08012E48
sub_08012E48:
	push {r4, r5, r6, r7, lr}
	ldr r4, _08012ED8 @ =0xFFFFFE00
	add sp, r4
	movs r5, #0x00
	bl WaitForVBlank
	movs r0, #0x03
	mov r1, sp
	bl sub_08011C9C
	ldr r0, _08012EDC @ =0x0202ED70
	ldrb r1, [r0, #0x00]
	movs r0, #0x00
	bl sub_08012DEC
	mov r0, sp
	movs r1, #0x0F
	bl FadeToBrightenedPalette
	movs r7, #0x40
	ldr r6, _08012EE0 @ =0x020005CC
_08012E72:
	bl ReadKeys
	lsls r5, r5, #0x18
	lsrs r4, r5, #0x18
	ldr r0, _08012EDC @ =0x0202ED70
	ldrb r1, [r0, #0x00]
	adds r0, r4, #0x0
	bl sub_08012DEC
	movs r0, #0x01
	ldrh r1, [r6, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08012E90
	adds r7, r4, #0x0
_08012E90:
	ldrh r0, [r6, #0x00]
	asrs r1, r5, #0x18
	movs r2, #0x00
	movs r3, #0x01
	bl MenuMoveVertical
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl WaitForVBlank
	lsls r0, r7, #0x18
	asrs r4, r0, #0x18
	cmp r4, #0x40
	beq _08012E72
	ldr r0, _08012EE4 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _08012EBA
	movs r0, #0x09
	bl m4aSongNumStart
_08012EBA:
	movs r0, #0x00
	movs r1, #0x0F
	bl FadeToColor
	movs r1, #0x01
	adds r0, r4, #0x0
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08012ED8: .4byte 0xFFFFFE00
_08012EDC: .4byte 0x0202ED70
_08012EE0: .4byte 0x020005CC
_08012EE4: .4byte 0x0202EF00
