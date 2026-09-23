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
	thumb_func_start sub_080101BC
sub_080101BC:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	adds r6, r1, #0x0
	adds r0, r2, #0x0
	adds r4, r3, #0x0
	ldr r1, [sp, #0x018]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	bl sub_0800754C
	adds r5, r0, #0x0
	cmp r5, #0x00
	beq _0801020E
	adds r0, r4, #0x0
	bl sub_08007714
	lsls r0, r0, #0x18
	movs r2, #0xFF
	ands r2, r6
	ldr r1, _08010218 @ =0x000001FF
	ands r1, r7
	lsls r1, r1, #0x10
	orrs r2, r1
	movs r1, #0x80
	lsls r1, r1, #0x18
	orrs r2, r1
	lsrs r0, r0, #0x0C
	ldr r1, [r5, #0x10]
	orrs r1, r0
	mov r0, r8
	cmp r0, #0x00
	beq _08010208
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r2, r0
_08010208:
	adds r0, r2, #0x0
	bl sub_080044A4
_0801020E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08010218: .4byte 0x000001FF
	thumb_func_start sub_0801021C
sub_0801021C:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0x0
	adds r6, r1, #0x0
	adds r0, r2, #0x0
	adds r4, r3, #0x0
	ldr r1, [sp, #0x018]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	bl sub_08007630
	adds r5, r0, #0x0
	cmp r5, #0x00
	beq _0801026E
	adds r0, r4, #0x0
	bl sub_08007714
	lsls r0, r0, #0x18
	movs r2, #0xFF
	ands r2, r6
	ldr r1, _08010278 @ =0x000001FF
	ands r1, r7
	lsls r1, r1, #0x10
	orrs r2, r1
	movs r1, #0x80
	lsls r1, r1, #0x17
	orrs r2, r1
	lsrs r0, r0, #0x0C
	ldr r1, [r5, #0x10]
	orrs r1, r0
	mov r0, r8
	cmp r0, #0x00
	beq _08010268
	movs r0, #0x80
	lsls r0, r0, #0x15
	orrs r2, r0
_08010268:
	adds r0, r2, #0x0
	bl sub_080044A4
_0801026E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08010278: .4byte 0x000001FF
