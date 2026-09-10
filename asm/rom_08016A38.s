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
	thumb_func_start sub_08016A38
sub_08016A38:
	push {r4, r5, lr}
	ldr r4, _08016BE4 @ =0x0202F170
	ldr r1, _08016BE8 @ =0x083FECB0
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x00]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x02]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldrh r0, [r1, #0x04]
	strh r0, [r4, #0x00]
	adds r4, #0x02
	movs r0, #0x98
	lsls r0, r0, #0x01
	movs r1, #0x48
	bl sub_0801659C
	ldr r0, _08016BEC @ =0xFFFFFE98
	adds r4, r4, r0
	movs r1, #0x01
	strb r1, [r4, #0x00]
	strb r1, [r4, #0x01]
	adds r5, r4, #0x2
	strb r1, [r5, #0x00]
	adds r5, #0x01
	strb r1, [r5, #0x00]
	adds r5, #0x01
	strb r1, [r5, #0x00]
	adds r5, #0x01
	movs r0, #0x00
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r1, [r5, #0x00]
	adds r5, #0x01
	strb r1, [r5, #0x00]
	adds r5, #0x01
	strb r1, [r5, #0x00]
	adds r5, #0x01
	strb r1, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	strb r0, [r5, #0x00]
	adds r5, #0x01
	movs r0, #0x10
	movs r1, #0x30
	bl sub_0801659C
	subs r4, #0x08
	movs r1, #0x01
	strh r1, [r4, #0x00]
	adds r4, #0x02
	movs r0, #0x00
	strh r0, [r4, #0x00]
	adds r4, #0x02
	strh r1, [r4, #0x00]
	adds r4, #0x02
	strh r0, [r4, #0x00]
	movs r0, #0x08
	movs r1, #0x08
	bl sub_0801659C
	adds r4, r5, #0x0
	subs r4, #0x2E
	ldr r1, _08016BF0 @ =0x0000A482
	adds r0, r1, #0x0
	strh r0, [r4, #0x00]
	adds r4, #0x02
	ldr r1, _08016BF4 @ =0x00007674
	adds r0, r1, #0x0
	strh r0, [r4, #0x00]
	movs r0, #0x00
	movs r1, #0x08
	bl sub_0801659C
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _08016BE4
_08016BE4: .4byte 0x0202F170
	.global _08016BE8
_08016BE8: .4byte 0x083FECB0
	.global _08016BEC
_08016BEC: .4byte 0xFFFFFE98
	.global _08016BF0
_08016BF0: .4byte 0x0000A482
	.global _08016BF4
_08016BF4: .4byte 0x00007674
