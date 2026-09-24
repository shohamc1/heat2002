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
	thumb_func_start sub_0801037C
sub_0801037C:
	push {r4, r5, lr}
	ldr r4, _08010408 @ =0xFFFFFE00
	add sp, r4
	ldr r0, _0801040C @ =0x0833338C
	ldr r1, _08010410 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl WaitForVBlank
	ldr r1, _08010414 @ =0x0400000C
	ldr r2, _08010418 @ =0x00001081
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	subs r1, #0x04
	ldr r2, _0801041C @ =0x00001C0D
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	subs r1, #0x08
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _08010420 @ =0x082B76F0
	movs r1, #0xC0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x07
	bl sub_08016E10
	bl sub_08010714
	movs r2, #0x00
	ldr r5, _08010424 @ =0x08364B08
	movs r4, #0x00
	movs r3, #0xE0
	lsls r3, r3, #0x02
_080103C8:
	ldr r0, [r5, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r0
	strh r4, [r1, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, r3
	bne _080103C8
	ldr r0, _08010428 @ =0x082B731C
	movs r2, #0x80
	lsls r2, r2, #0x01
	mov r1, sp
	bl sub_08016E10
	mov r0, sp
	movs r1, #0x0F
	bl FadeToBrightenedPalette
	movs r0, #0xB4
	bl WaitFrames
	movs r0, #0x00
	movs r1, #0x0F
	bl FadeToColor
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r4, r5}
	pop {r0}
	bx r0
_08010408: .4byte 0xFFFFFE00
_0801040C: .4byte 0x0833338C
_08010410: .4byte 0x0600C000
_08010414: .4byte 0x0400000C
_08010418: .4byte 0x00001081
_0801041C: .4byte 0x00001C0D
_08010420: .4byte 0x082B76F0
_08010424: .4byte 0x08364B08
_08010428: .4byte 0x082B731C
