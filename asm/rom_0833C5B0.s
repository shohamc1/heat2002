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
	thumb_func_start sub_0833C5B0
sub_0833C5B0:
	push {r4, lr}
	bl sub_0833A1DC
	ldr r2, _0833C5DC @ =0x02039134
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	strh r0, [r2, #0x00]
	ldr r1, _0833C5E0 @ =0x0203917C
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldr r0, _0833C5E4 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833C5F8
	ldrh r0, [r2, #0x00]
	cmp r0, #0x01
	bls _0833C5EC
	ldr r1, _0833C5E8 @ =0x020390FC
	movs r0, #0x01
	b _0833C600
	.byte 0x00, 0x00
_0833C5DC: .4byte 0x02039134
_0833C5E0: .4byte 0x0203917C
_0833C5E4: .4byte 0x020390EC
_0833C5E8: .4byte 0x020390FC
_0833C5EC:
	ldr r1, _0833C5F4 @ =0x020390FC
	movs r0, #0x00
	b _0833C600
	.byte 0x00, 0x00
_0833C5F4: .4byte 0x020390FC
_0833C5F8:
	ldr r1, _0833C684 @ =0x020390FC
	movs r0, #0x01
	ldrb r2, [r1, #0x00]
	eors r0, r2
_0833C600:
	strb r0, [r1, #0x00]
	ldr r0, _0833C688 @ =0x020390EC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0833C60E
	movs r0, #0x01
	strb r0, [r1, #0x00]
_0833C60E:
	ldr r1, _0833C68C @ =0x020391C8
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _0833C6C6
	ldr r0, _0833C690 @ =0x020390D0
	ldrb r0, [r0, #0x00]
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _0833C6C6
	strb r4, [r1, #0x00]
	ldr r0, _0833C694 @ =0x0203ACE0
	movs r1, #0xE0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl sub_08344B60
	ldr r0, _0833C698 @ =0x020391D4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0833C6BC
	ldr r1, _0833C69C @ =0x0400001C
	ldr r0, _0833C6A0 @ =0x02039290
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	ldr r0, _0833C6A4 @ =0x02039298
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	subs r1, #0x06
	ldr r0, _0833C6A8 @ =0x020392A8
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	ldr r0, _0833C6AC @ =0x02039240
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	subs r1, #0x06
	ldr r0, _0833C6B0 @ =0x0203925C
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	ldr r0, _0833C6B4 @ =0x02039260
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldr r0, _0833C6B8 @ =0x04000010
	strh r4, [r0, #0x00]
	adds r0, #0x02
	strh r4, [r0, #0x00]
	bl sub_0833D094
	bl sub_0833FDC4
	b _0833C6C0
	.byte 0x00, 0x00
_0833C684: .4byte 0x020390FC
_0833C688: .4byte 0x020390EC
_0833C68C: .4byte 0x020391C8
_0833C690: .4byte 0x020390D0
_0833C694: .4byte 0x0203ACE0
_0833C698: .4byte 0x020391D4
_0833C69C: .4byte 0x0400001C
_0833C6A0: .4byte 0x02039290
_0833C6A4: .4byte 0x02039298
_0833C6A8: .4byte 0x020392A8
_0833C6AC: .4byte 0x02039240
_0833C6B0: .4byte 0x0203925C
_0833C6B4: .4byte 0x02039260
_0833C6B8: .4byte 0x04000010
_0833C6BC:
	bl sub_0833FDC4
_0833C6C0:
	ldr r1, _0833C6E8 @ =0x020390D0
	movs r0, #0x01
	strb r0, [r1, #0x00]
_0833C6C6:
	bl sub_0833D4E4
	bl sub_0833A8BC
	ldr r3, _0833C6EC @ =0x04000208
	movs r0, #0x00
	strh r0, [r3, #0x00]
	ldr r2, _0833C6F0 @ =0x03007FF8
	ldrh r0, [r2, #0x00]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x00]
	strh r1, [r3, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0833C6E8: .4byte 0x020390D0
_0833C6EC: .4byte 0x04000208
_0833C6F0: .4byte 0x03007FF8
