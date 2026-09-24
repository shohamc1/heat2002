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
	thumb_func_start sub_0833BB58
sub_0833BB58:
	push {lr}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2, #0x00]
	adds r2, #0x01
	str r2, [r1, #0x40]
	ldr r2, _0833BB74 @ =0x0200C910
	lsls r3, r3, #0x02
	adds r3, r3, r2
	ldr r2, [r3, #0x00]
	bl _08344B84
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0833BB74: .4byte 0x0200C910
	thumb_func_start sub_0833BB78
sub_0833BB78:
	push {lr}
	ldr r2, _0833BB88 @ =0x02038DE0
	ldr r2, [r2, #0x00]
	bl _08344B84
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0833BB88: .4byte 0x02038DE0
	thumb_func_start sub_0833BB8C
sub_0833BB8C:
	push {r4, lr}
	ldr r2, [r1, #0x40]
	ldr r0, _0833BBC4 @ =0xFFFFFF00
	ands r4, r0
	ldrb r0, [r2, #0x00]
	orrs r4, r0
	ldrb r0, [r2, #0x01]
	lsls r3, r0, #0x08
	ldr r0, _0833BBC8 @ =0xFFFF00FF
	ands r4, r0
	orrs r4, r3
	ldrb r0, [r2, #0x02]
	lsls r3, r0, #0x10
	ldr r0, _0833BBCC @ =0xFF00FFFF
	ands r4, r0
	orrs r4, r3
	ldrb r0, [r2, #0x03]
	lsls r3, r0, #0x18
	ldr r0, _0833BBD0 @ =0x00FFFFFF
	ands r4, r0
	orrs r4, r3
	str r4, [r1, #0x28]
	adds r2, #0x04
	str r2, [r1, #0x40]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0833BBC4: .4byte 0xFFFFFF00
_0833BBC8: .4byte 0xFFFF00FF
_0833BBCC: .4byte 0xFF00FFFF
_0833BBD0: .4byte 0x00FFFFFF
	thumb_func_start sub_0833BBD4
sub_0833BBD4:
	ldr r0, [r1, #0x40]
	ldrb r2, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x24
	strb r2, [r0, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833BBE8
sub_0833BBE8:
	ldr r0, [r1, #0x40]
	ldrb r2, [r0, #0x00]
	adds r0, r1, #0x0
	adds r0, #0x2C
	strb r2, [r0, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833BBFC
sub_0833BBFC:
	ldr r0, [r1, #0x40]
	ldrb r0, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x2D
	strb r0, [r2, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833BC10
sub_0833BC10:
	ldr r0, [r1, #0x40]
	ldrb r0, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x2E
	strb r0, [r2, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833BC24
sub_0833BC24:
	ldr r0, [r1, #0x40]
	ldrb r0, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x2F
	strb r0, [r2, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833BC38
sub_0833BC38:
	ldr r0, [r1, #0x40]
	ldrb r2, [r0, #0x00]
	strb r2, [r1, #0x1E]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	thumb_func_start sub_0833BC44
sub_0833BC44:
	ldr r0, [r1, #0x40]
	ldrb r2, [r0, #0x00]
	strb r2, [r1, #0x1F]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	thumb_func_start sub_0833BC50
sub_0833BC50:
	ldr r0, [r1, #0x40]
	ldrb r0, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x26
	strb r0, [r2, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
	thumb_func_start sub_0833BC64
sub_0833BC64:
	ldr r0, [r1, #0x40]
	ldrb r0, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x27
	strb r0, [r2, #0x00]
	ldr r0, [r1, #0x40]
	adds r0, #0x01
	str r0, [r1, #0x40]
	bx lr
	.byte 0x00, 0x00
