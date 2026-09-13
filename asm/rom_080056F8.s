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
	thumb_func_start sub_080056F8
sub_080056F8:
	push {r4, r5, r6, lr}
	ldr r0, _080057B4 @ =0x020020C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080057AE
	ldr r0, _080057B8 @ =0x020021E0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080057AE
	ldr r0, _080057BC @ =0x0200215C
	ldrb r0, [r0, #0x00]
	subs r0, #0x03
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _080057C0 @ =0x020253CC
	ldr r6, _080057C4 @ =0x02025224
	cmp r0, #0x02
	bhi _08005746
	movs r2, #0x00
	ldr r3, _080057C8 @ =0x020020AC
	ldrb r0, [r3, #0x00]
	cmp r2, r0
	beq _08005746
	ldr r4, _080057CC @ =0x0202A6BC
	.global _08005728
_08005728:
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	adds r0, r0, r2
	lsls r0, r0, #0x04
	adds r0, r0, r4
	ldr r1, [r0, #0x00]
	adds r1, #0x01
	str r1, [r0, #0x00]
	adds r0, r2, #0x1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldrb r1, [r3, #0x00]
	cmp r2, r1
	bne _08005728
	.global _08005746
_08005746:
	ldrh r2, [r5, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x28
	strh r0, [r5, #0x00]
	lsls r0, r0, #0x10
	ldr r1, _080057D0 @ =0x03E70000
	cmp r0, r1
	bls _0800577A
	ldr r1, _080057D4 @ =0xFFFFFC40
	adds r0, r2, r1
	strh r0, [r5, #0x00]
	ldr r1, _080057D8 @ =0x020251FC
	ldrh r2, [r1, #0x00]
	adds r0, r2, #0x1
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3B
	bls _0800577A
	adds r0, r2, #0x0
	subs r0, #0x3B
	strh r0, [r1, #0x00]
	ldr r1, _080057DC @ =0x02025218
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	.global _0800577A
_0800577A:
	ldrh r2, [r6, #0x00]
	adds r0, r2, #0x0
	adds r0, #0x28
	strh r0, [r6, #0x00]
	lsls r0, r0, #0x10
	ldr r1, _080057D0 @ =0x03E70000
	cmp r0, r1
	bls _080057AE
	ldr r1, _080057D4 @ =0xFFFFFC40
	adds r0, r2, r1
	strh r0, [r6, #0x00]
	ldr r1, _080057E0 @ =0x02025220
	ldrh r2, [r1, #0x00]
	adds r0, r2, #0x1
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3B
	bls _080057AE
	adds r0, r2, #0x0
	subs r0, #0x3B
	strh r0, [r1, #0x00]
	ldr r1, _080057E4 @ =0x02025260
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	.global _080057AE
_080057AE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.global _080057B4
_080057B4: .4byte 0x020020C4
	.global _080057B8
_080057B8: .4byte 0x020021E0
	.global _080057BC
_080057BC: .4byte 0x0200215C
	.global _080057C0
_080057C0: .4byte 0x020253CC
	.global _080057C4
_080057C4: .4byte 0x02025224
	.global _080057C8
_080057C8: .4byte 0x020020AC
	.global _080057CC
_080057CC: .4byte 0x0202A6BC
	.global _080057D0
_080057D0: .4byte 0x03E70000
	.global _080057D4
_080057D4: .4byte 0xFFFFFC40
	.global _080057D8
_080057D8: .4byte 0x020251FC
	.global _080057DC
_080057DC: .4byte 0x02025218
	.global _080057E0
_080057E0: .4byte 0x02025220
	.global _080057E4
_080057E4: .4byte 0x02025260
	.byte 0x04, 0x48, 0x00, 0x68, 0x00, 0x28, 0x09, 0xD1, 0x03, 0x48, 0x00, 0x68, 0x00, 0x28, 0x05, 0xD1
	.byte 0x00, 0x20, 0x04, 0xE0, 0x1C, 0x52, 0x02, 0x02, 0xC0, 0x53, 0x02, 0x02, 0x01, 0x20, 0x70, 0x47
	.byte 0x30, 0xB5, 0x13, 0x48, 0x00, 0x78, 0x00, 0x28, 0x1F, 0xD0, 0x12, 0x48, 0x04, 0x78, 0x00, 0x2C
	.byte 0x1B, 0xD1, 0x11, 0x4D, 0x29, 0x68, 0x08, 0x1C, 0x18, 0x38, 0x28, 0x60, 0x00, 0x28, 0x14, 0xDA
	.byte 0xF4, 0x22, 0x92, 0x00, 0x88, 0x18, 0x28, 0x60, 0x0C, 0x4B, 0x19, 0x68, 0x01, 0x39, 0x19, 0x60
	.byte 0x0B, 0x4A, 0x01, 0x20, 0x10, 0x70, 0x00, 0x29, 0x07, 0xDA, 0x1C, 0x60, 0x2C, 0x60, 0x09, 0x48
	.byte 0x00, 0x78, 0x00, 0x28, 0x01, 0xD1, 0x05, 0xF0, 0x25, 0xFC, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47
	.byte 0xC4, 0x20, 0x00, 0x02, 0xE0, 0x21, 0x00, 0x02, 0xC0, 0x53, 0x02, 0x02, 0x1C, 0x52, 0x02, 0x02
	.byte 0x38, 0x52, 0x02, 0x02, 0x5C, 0x21, 0x00, 0x02
	thumb_func_start sub_08005870
sub_08005870:
	push {r4, r5, lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x16
	ldr r2, _080058C4 @ =0x08334DE2
	adds r1, r1, r2
	ldr r4, _080058C8 @ =0x08335A8C
	ldrh r3, [r1, #0x00]
	lsls r2, r3, #0x01
	adds r2, r2, r4
	movs r5, #0xE0
	lsls r5, r5, #0x08
	adds r3, r5, #0x0
	ldrh r2, [r2, #0x00]
	orrs r2, r3
	strh r2, [r0, #0x00]
	ldrh r5, [r1, #0x02]
	lsls r2, r5, #0x01
	adds r2, r2, r4
	ldrh r2, [r2, #0x00]
	orrs r2, r3
	strh r2, [r0, #0x02]
	adds r5, r0, #0x0
	adds r5, #0x40
	adds r2, r1, #0x0
	adds r2, #0x88
	ldrh r2, [r2, #0x00]
	lsls r2, r2, #0x01
	adds r2, r2, r4
	ldrh r2, [r2, #0x00]
	orrs r2, r3
	strh r2, [r5, #0x00]
	adds r0, #0x42
	adds r1, #0x8A
	ldrh r1, [r1, #0x00]
	lsls r1, r1, #0x01
	adds r1, r1, r4
	ldrh r1, [r1, #0x00]
	orrs r3, r1
	strh r3, [r0, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.global _080058C4
_080058C4: .4byte 0x08334DE2
	.global _080058C8
_080058C8: .4byte 0x08335A8C
