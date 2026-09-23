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
	thumb_func_start sub_08010134
sub_08010134:
	push {r4, r5, lr}
	adds r5, r1, #0x0
	lsls r1, r3, #0x18
	movs r4, #0xFF
	ands r4, r5
	ldr r3, _08010160 @ =0x000001FF
	ands r3, r0
	lsls r3, r3, #0x10
	orrs r3, r4
	movs r0, #0xC0
	lsls r0, r0, #0x18
	orrs r0, r3
	lsrs r1, r1, #0x0C
	movs r3, #0x80
	lsls r3, r3, #0x04
	orrs r1, r3
	orrs r1, r2
	bl sub_080044A4
	pop {r4, r5}
	pop {r0}
	bx r0
_08010160: .4byte 0x000001FF
	thumb_func_start sub_08010164
sub_08010164:
	push {r4, r5, lr}
	adds r5, r1, #0x0
	lsls r1, r3, #0x18
	movs r4, #0xFF
	ands r4, r5
	ldr r3, _08010190 @ =0x000001FF
	ands r3, r0
	lsls r3, r3, #0x10
	orrs r3, r4
	movs r0, #0xC0
	lsls r0, r0, #0x18
	orrs r0, r3
	lsrs r1, r1, #0x0C
	movs r3, #0x80
	lsls r3, r3, #0x04
	orrs r1, r3
	orrs r1, r2
	bl sub_080044A4
	pop {r4, r5}
	pop {r0}
	bx r0
_08010190: .4byte 0x000001FF
