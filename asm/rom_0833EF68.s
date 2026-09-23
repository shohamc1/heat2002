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
	thumb_func_start sub_0833EF68
sub_0833EF68:
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	lsls r3, r3, #0x18
	ldr r0, _0833F00C @ =0x020251B8
	lsls r2, r2, #0x05
	adds r2, r2, r1
	lsls r2, r2, #0x01
	ldr r0, [r0, #0x00]
	adds r0, r0, r2
	mov r12, r0
	movs r6, #0xE0
	lsls r6, r6, #0x08
	cmp r3, #0x00
	beq _0833EF88
	movs r6, #0xF0
	lsls r6, r6, #0x08
_0833EF88:
	ldrb r1, [r4, #0x00]
	adds r4, #0x01
	cmp r1, #0x00
	beq _0833F006
	ldr r5, _0833F010 @ =0x0201F9D0
	ldr r7, _0833F014 @ =0x0201F590
_0833EF94:
	subs r1, #0x20
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x1D
	lsls r2, r2, #0x16
	movs r0, #0xC0
	lsls r0, r0, #0x0F
	adds r2, r2, r0
	lsrs r2, r2, #0x10
	movs r0, #0xF8
	lsls r0, r0, #0x15
	ands r0, r1
	lsrs r0, r0, #0x18
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x0F
	adds r2, r2, r7
	ldrh r0, [r2, #0x00]
	lsls r1, r0, #0x01
	adds r1, r1, r5
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	mov r1, r12
	strh r0, [r1, #0x00]
	ldrh r0, [r2, #0x02]
	lsls r1, r0, #0x01
	adds r1, r1, r5
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	mov r1, r12
	strh r0, [r1, #0x02]
	adds r0, r2, #0x0
	adds r0, #0x40
	ldrh r0, [r0, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r5
	adds r1, r6, #0x0
	ldrh r0, [r0, #0x00]
	orrs r1, r0
	mov r3, r12
	adds r3, #0x40
	strh r1, [r3, #0x00]
	adds r2, #0x42
	ldrh r2, [r2, #0x00]
	lsls r1, r2, #0x01
	adds r1, r1, r5
	adds r0, r6, #0x0
	ldrh r1, [r1, #0x00]
	orrs r0, r1
	strh r0, [r3, #0x02]
	movs r0, #0x02
	add r12, r0
	ldrb r1, [r4, #0x00]
	adds r4, #0x01
	cmp r1, #0x00
	bne _0833EF94
_0833F006:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0833F00C: .4byte 0x020251B8
_0833F010: .4byte 0x0201F9D0
_0833F014: .4byte 0x0201F590
