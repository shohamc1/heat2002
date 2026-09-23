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
	thumb_func_start sub_08364730
sub_08364730:
	push {r4, r5, lr}
	ldr r2, _08364754 @ =0x04000120
	ldr r3, [r2, #0x00]
	ldr r5, _08364758 @ =0x03000C00
	adds r4, r5, #0x0
	ldrb r0, [r5, #0x00]
	cmp r0, #0x01
	beq _08364760
	ldr r0, _0836475C @ =0x04000128
	ldrh r1, [r0, #0x00]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0, #0x00]
	ldr r2, [r4, #0x08]
	cmp r2, #0x00
	bge _083647AC
	b _0836479A
	.byte 0x00, 0x00
_08364754: .4byte 0x04000120
_08364758: .4byte 0x03000C00
_0836475C: .4byte 0x04000128
_08364760:
	ldr r1, _08364774 @ =0x0400010E
	movs r0, #0x00
	strh r0, [r1, #0x00]
	ldr r1, [r4, #0x08]
	cmp r1, #0x00
	bge _0836477C
	ldr r0, _08364778 @ =0xFEFEFEFE
	str r0, [r2, #0x00]
	b _083647C2
	.byte 0x00, 0x00
_08364774: .4byte 0x0400010E
_08364778: .4byte 0xFEFEFEFE
_0836477C:
	ldr r0, _08364790 @ =0x00001FFF
	cmp r1, r0
	bgt _08364794
	ldr r0, [r4, #0x04]
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	str r0, [r2, #0x00]
	b _083647C2
	.byte 0x00, 0x00
_08364790: .4byte 0x00001FFF
_08364794:
	ldr r0, [r4, #0x0C]
	str r0, [r2, #0x00]
	b _083647C2
_0836479A:
	ldr r0, _083647A8 @ =0xFEFEFEFE
	cmp r3, r0
	beq _083647C2
	subs r0, r2, #0x1
	str r0, [r5, #0x08]
	b _083647C2
	.byte 0x00, 0x00
_083647A8: .4byte 0xFEFEFEFE
_083647AC:
	ldr r0, _083647BC @ =0x00001FFF
	cmp r2, r0
	bgt _083647C0
	ldr r1, [r4, #0x04]
	lsls r0, r2, #0x02
	adds r0, r0, r1
	str r3, [r0, #0x00]
	b _083647C2
_083647BC: .4byte 0x00001FFF
_083647C0:
	str r3, [r4, #0x0C]
_083647C2:
	ldr r1, [r4, #0x08]
	ldr r0, _083647EC @ =0x00002002
	cmp r1, r0
	bgt _083647E4
	adds r0, r1, #0x1
	str r0, [r4, #0x08]
	ldrb r4, [r4, #0x00]
	cmp r4, #0x01
	bne _083647E4
	ldr r2, _083647F0 @ =0x04000128
	ldrh r0, [r2, #0x00]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldr r1, _083647F4 @ =0x0400010E
	movs r0, #0xC0
	strh r0, [r1, #0x00]
_083647E4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_083647EC: .4byte 0x00002002
_083647F0: .4byte 0x04000128
_083647F4: .4byte 0x0400010E
