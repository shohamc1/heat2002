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
	thumb_func_start sub_080126BC
sub_080126BC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _08012748 @ =0xFFFFFE00
	add sp, r4
	movs r6, #0x00
	movs r0, #0x03
	mov r1, sp
	bl sub_08011C9C
	movs r0, #0x00
	bl sub_0801264C
	mov r0, sp
	movs r1, #0x0F
	bl FadeToBrightenedPalette
	movs r7, #0x40
	ldr r0, _0801274C @ =0x020005CC
	mov r8, r0
_080126E4:
	bl ReadKeys
	lsls r4, r6, #0x18
	asrs r5, r4, #0x18
	adds r0, r5, #0x0
	bl sub_0801264C
	movs r0, #0x01
	mov r1, r8
	ldrh r1, [r1, #0x00]
	ands r0, r1
	cmp r0, #0x00
	beq _08012704
	lsrs r7, r4, #0x18
	ldr r0, _08012750 @ =0x0202ED70
	strb r6, [r0, #0x00]
_08012704:
	mov r2, r8
	ldrh r0, [r2, #0x00]
	adds r1, r5, #0x0
	movs r2, #0x00
	movs r3, #0x03
	bl MenuMoveVertical
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	bl WaitForVBlank
	lsls r4, r7, #0x18
	cmp r7, #0x40
	beq _080126E4
	ldr r0, _08012754 @ =0x0202EF00
	ldrb r0, [r0, #0x03]
	cmp r0, #0x00
	beq _0801272E
	movs r0, #0x09
	bl m4aSongNumStart
_0801272E:
	movs r0, #0x00
	movs r1, #0x0F
	bl FadeToColor
	lsrs r0, r4, #0x18
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_08012748: .4byte 0xFFFFFE00
_0801274C: .4byte 0x020005CC
_08012750: .4byte 0x0202ED70
_08012754: .4byte 0x0202EF00
