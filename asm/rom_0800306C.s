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
	thumb_func_start sub_0800306C
sub_0800306C:
	push {r4, lr}
	bl m4aSoundVSync
	ldr r2, _08003098 @ =0x02002124
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	strh r0, [r2, #0x00]
	ldr r1, _0800309C @ =0x0200216C
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldr r0, _080030A0 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080030B4
	ldrh r0, [r2, #0x00]
	cmp r0, #0x01
	bls _080030A8
	ldr r1, _080030A4 @ =0x020020EC
	movs r0, #0x01
	b _080030BC
	.byte 0x00, 0x00
_08003098: .4byte 0x02002124
_0800309C: .4byte 0x0200216C
_080030A0: .4byte 0x020020DC
_080030A4: .4byte 0x020020EC
_080030A8:
	ldr r1, _080030B0 @ =0x020020EC
	movs r0, #0x00
	b _080030BC
	.byte 0x00, 0x00
_080030B0: .4byte 0x020020EC
_080030B4:
	ldr r1, _08003140 @ =0x020020EC
	movs r0, #0x01
	ldrb r2, [r1, #0x00]
	eors r0, r2
_080030BC:
	strb r0, [r1, #0x00]
	ldr r0, _08003144 @ =0x020020DC
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080030CA
	movs r0, #0x01
	strb r0, [r1, #0x00]
_080030CA:
	ldr r1, _08003148 @ =0x020021B8
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bls _08003182
	ldr r0, _0800314C @ =0x020020C0
	ldrb r0, [r0, #0x00]
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _08003182
	strb r4, [r1, #0x00]
	ldr r0, _08003150 @ =0x02024830
	movs r1, #0xE0
	lsls r1, r1, #0x13
	movs r2, #0x80
	lsls r2, r2, #0x01
	bl sub_08016E0C
	ldr r0, _08003154 @ =0x020021C4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08003178
	ldr r1, _08003158 @ =0x0400001C
	ldr r0, _0800315C @ =0x02022DE0
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	ldr r0, _08003160 @ =0x02022DE8
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	subs r1, #0x06
	ldr r0, _08003164 @ =0x02022DF8
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	ldr r0, _08003168 @ =0x0200BC2C
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	subs r1, #0x06
	ldr r0, _0800316C @ =0x0200BC48
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	adds r1, #0x02
	ldr r0, _08003170 @ =0x0200BC4C
	ldr r0, [r0, #0x00]
	strh r0, [r1, #0x00]
	ldr r0, _08003174 @ =0x04000010
	strh r4, [r0, #0x00]
	adds r0, #0x02
	strh r4, [r0, #0x00]
	bl sub_08003D90
	bl sub_08007760
	b _0800317C
	.byte 0x00, 0x00
_08003140: .4byte 0x020020EC
_08003144: .4byte 0x020020DC
_08003148: .4byte 0x020021B8
_0800314C: .4byte 0x020020C0
_08003150: .4byte 0x02024830
_08003154: .4byte 0x020021C4
_08003158: .4byte 0x0400001C
_0800315C: .4byte 0x02022DE0
_08003160: .4byte 0x02022DE8
_08003164: .4byte 0x02022DF8
_08003168: .4byte 0x0200BC2C
_0800316C: .4byte 0x0200BC48
_08003170: .4byte 0x0200BC4C
_08003174: .4byte 0x04000010
_08003178:
	bl sub_08007760
_0800317C:
	ldr r1, _080031A4 @ =0x020020C0
	movs r0, #0x01
	strb r0, [r1, #0x00]
_08003182:
	bl sub_080041E0
	bl sub_080011FC
	ldr r3, _080031A8 @ =0x04000208
	movs r0, #0x00
	strh r0, [r3, #0x00]
	ldr r2, _080031AC @ =0x03007FF8
	ldrh r0, [r2, #0x00]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x00]
	strh r1, [r3, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080031A4: .4byte 0x020020C0
_080031A8: .4byte 0x04000208
_080031AC: .4byte 0x03007FF8
