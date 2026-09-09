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
	thumb_func_start sub_0800F3C0
sub_0800F3C0:
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r4, #0x00
	ldr r0, _0800F42C @ =0x0202EFC0
	mov r8, r0
	mov r3, r8
	ldr r2, _0800F430 @ =0x0202A550
	.global _0800F3D0
_0800F3D0:
	lsls r0, r4, #0x02
	adds r0, r0, r3
	lsls r1, r4, #0x01
	adds r1, r1, r4
	lsls r1, r1, #0x03
	adds r1, r1, r4
	lsls r1, r1, #0x04
	adds r1, r1, r2
	str r1, [r0, #0x00]
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x18
	bne _0800F3D0
	.global _0800F3EC
_0800F3EC:
	movs r0, #0x00
	mov r12, r0
	mov r6, r8
	movs r4, #0x00
	movs r7, #0xB6
	lsls r7, r7, #0x01
	.global _0800F3F8
_0800F3F8:
	ldr r5, [r6, #0x00]
	ldr r3, [r6, #0x04]
	adds r0, r5, r7
	adds r1, r3, r7
	ldr r2, [r0, #0x00]
	ldr r0, [r1, #0x00]
	cmp r2, r0
	bls _0800F410
	str r3, [r6, #0x00]
	str r5, [r6, #0x04]
	movs r0, #0x01
	mov r12, r0
	.global _0800F410
_0800F410:
	adds r6, #0x04
	adds r0, r4, #0x1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x17
	bne _0800F3F8
	mov r0, r12
	cmp r0, #0x00
	bne _0800F3EC
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.global _0800F42C
_0800F42C: .4byte 0x0202EFC0
	.global _0800F430
_0800F430: .4byte 0x0202A550
	thumb_func_start sub_0800F434
sub_0800F434:
	push {lr}
	ldr r1, _0800F478 @ =0x04000008
	ldr r2, _0800F47C @ =0x00001C0E
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F480 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F484 @ =0x082A9F0C
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F488 @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F48C @ =0x0833338C
	ldr r1, _0800F490 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F494 @ =0x082A9930
	bl sub_08010680
	pop {r0}
	bx r0
	.global _0800F478
_0800F478: .4byte 0x04000008
	.global _0800F47C
_0800F47C: .4byte 0x00001C0E
	.global _0800F480
_0800F480: .4byte 0x00001F82
	.global _0800F484
_0800F484: .4byte 0x082A9F0C
	.global _0800F488
_0800F488: .4byte 0x00005140
	.global _0800F48C
_0800F48C: .4byte 0x0833338C
	.global _0800F490
_0800F490: .4byte 0x0600C000
	.global _0800F494
_0800F494: .4byte 0x082A9930
	thumb_func_start sub_0800F498
sub_0800F498:
	push {lr}
	ldr r1, _0800F4DC @ =0x04000008
	ldr r2, _0800F4E0 @ =0x00001C0E
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F4E4 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F4E8 @ =0x082EE8E0
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F4EC @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F4F0 @ =0x0833338C
	ldr r1, _0800F4F4 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F4F8 @ =0x082EE304
	bl sub_08010680
	pop {r0}
	bx r0
	.global _0800F4DC
_0800F4DC: .4byte 0x04000008
	.global _0800F4E0
_0800F4E0: .4byte 0x00001C0E
	.global _0800F4E4
_0800F4E4: .4byte 0x00001F82
	.global _0800F4E8
_0800F4E8: .4byte 0x082EE8E0
	.global _0800F4EC
_0800F4EC: .4byte 0x00005140
	.global _0800F4F0
_0800F4F0: .4byte 0x0833338C
	.global _0800F4F4
_0800F4F4: .4byte 0x0600C000
	.global _0800F4F8
_0800F4F8: .4byte 0x082EE304
	thumb_func_start sub_0800F4FC
sub_0800F4FC:
	push {lr}
	ldr r1, _0800F540 @ =0x04000008
	ldr r2, _0800F544 @ =0x00001C0D
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F548 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F54C @ =0x082E4B04
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F550 @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F554 @ =0x0833338C
	ldr r1, _0800F558 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F55C @ =0x082E4528
	bl sub_08010680
	pop {r0}
	bx r0
	.global _0800F540
_0800F540: .4byte 0x04000008
	.global _0800F544
_0800F544: .4byte 0x00001C0D
	.global _0800F548
_0800F548: .4byte 0x00001F82
	.global _0800F54C
_0800F54C: .4byte 0x082E4B04
	.global _0800F550
_0800F550: .4byte 0x00005140
	.global _0800F554
_0800F554: .4byte 0x0833338C
	.global _0800F558
_0800F558: .4byte 0x0600C000
	.global _0800F55C
_0800F55C: .4byte 0x082E4528
	thumb_func_start sub_0800F560
sub_0800F560:
	push {lr}
	mov r12, r4
	ldr r4, _0800F5D4 @ =0xFFFFFE00
	add sp, r4
	mov r4, r12
	ldr r1, _0800F5D8 @ =0x04000008
	ldr r2, _0800F5DC @ =0x00001C0D
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F5E0 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F5E4 @ =0x0831A450
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F5E8 @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F5EC @ =0x0833338C
	ldr r1, _0800F5F0 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xA8
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F5F4 @ =0x0831A0E4
	ldr r1, _0800F5F8 @ =0x0831A210
	bl sub_080106CC
	ldr r0, _0800F5FC @ =0x08319EE4
	mov r1, sp
	bl sub_0800F328
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r0, #0xB4
	bl sub_080102A4
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r0}
	bx r0
	.byte 0x00, 0x00
	.global _0800F5D4
_0800F5D4: .4byte 0xFFFFFE00
	.global _0800F5D8
_0800F5D8: .4byte 0x04000008
	.global _0800F5DC
_0800F5DC: .4byte 0x00001C0D
	.global _0800F5E0
_0800F5E0: .4byte 0x00001F82
	.global _0800F5E4
_0800F5E4: .4byte 0x0831A450
	.global _0800F5E8
_0800F5E8: .4byte 0x00005140
	.global _0800F5EC
_0800F5EC: .4byte 0x0833338C
	.global _0800F5F0
_0800F5F0: .4byte 0x0600C000
	.global _0800F5F4
_0800F5F4: .4byte 0x0831A0E4
	.global _0800F5F8
_0800F5F8: .4byte 0x0831A210
	.global _0800F5FC
_0800F5FC: .4byte 0x08319EE4
	thumb_func_start sub_0800F600
sub_0800F600:
	push {lr}
	mov r12, r4
	ldr r4, _0800F674 @ =0xFFFFFE00
	add sp, r4
	mov r4, r12
	ldr r1, _0800F678 @ =0x04000008
	ldr r2, _0800F67C @ =0x00001C0D
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F680 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F684 @ =0x083107FC
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F688 @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F68C @ =0x0833338C
	ldr r1, _0800F690 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0x88
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F694 @ =0x08310380
	ldr r1, _0800F698 @ =0x083104AC
	bl sub_080106CC
	ldr r0, _0800F69C @ =0x08310180
	mov r1, sp
	bl sub_0800F328
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r0, #0x96
	lsls r0, r0, #0x02
	bl sub_080102BC
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r0}
	bx r0
	.global _0800F674
_0800F674: .4byte 0xFFFFFE00
	.global _0800F678
_0800F678: .4byte 0x04000008
	.global _0800F67C
_0800F67C: .4byte 0x00001C0D
	.global _0800F680
_0800F680: .4byte 0x00001F82
	.global _0800F684
_0800F684: .4byte 0x083107FC
	.global _0800F688
_0800F688: .4byte 0x00005140
	.global _0800F68C
_0800F68C: .4byte 0x0833338C
	.global _0800F690
_0800F690: .4byte 0x0600C000
	.global _0800F694
_0800F694: .4byte 0x08310380
	.global _0800F698
_0800F698: .4byte 0x083104AC
	.global _0800F69C
_0800F69C: .4byte 0x08310180
	thumb_func_start sub_0800F6A0
sub_0800F6A0:
	push {lr}
	mov r12, r4
	ldr r4, _0800F714 @ =0xFFFFFE00
	add sp, r4
	mov r4, r12
	ldr r1, _0800F718 @ =0x04000008
	ldr r2, _0800F71C @ =0x00001C0D
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F720 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F724 @ =0x08313DF0
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F728 @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F72C @ =0x0833338C
	ldr r1, _0800F730 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0x88
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F734 @ =0x0831397C
	ldr r1, _0800F738 @ =0x08313AA8
	bl sub_080106CC
	ldr r0, _0800F73C @ =0x0831377C
	mov r1, sp
	bl sub_0800F328
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r0, #0x96
	lsls r0, r0, #0x02
	bl sub_080102BC
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r0}
	bx r0
	.global _0800F714
_0800F714: .4byte 0xFFFFFE00
	.global _0800F718
_0800F718: .4byte 0x04000008
	.global _0800F71C
_0800F71C: .4byte 0x00001C0D
	.global _0800F720
_0800F720: .4byte 0x00001F82
	.global _0800F724
_0800F724: .4byte 0x08313DF0
	.global _0800F728
_0800F728: .4byte 0x00005140
	.global _0800F72C
_0800F72C: .4byte 0x0833338C
	.global _0800F730
_0800F730: .4byte 0x0600C000
	.global _0800F734
_0800F734: .4byte 0x0831397C
	.global _0800F738
_0800F738: .4byte 0x08313AA8
	.global _0800F73C
_0800F73C: .4byte 0x0831377C
	thumb_func_start sub_0800F740
sub_0800F740:
	push {lr}
	mov r12, r4
	ldr r4, _0800F7B4 @ =0xFFFFFE00
	add sp, r4
	mov r4, r12
	ldr r1, _0800F7B8 @ =0x04000008
	ldr r2, _0800F7BC @ =0x00001C0D
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	adds r1, #0x04
	ldr r2, _0800F7C0 @ =0x00001F82
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F7C4 @ =0x083171A4
	movs r1, #0xC0
	lsls r1, r1, #0x13
	ldr r2, _0800F7C8 @ =0x00005140
	bl sub_08016E10
	ldr r0, _0800F7CC @ =0x0833338C
	ldr r1, _0800F7D0 @ =0x0600C000
	movs r2, #0x80
	lsls r2, r2, #0x05
	bl sub_08016E10
	bl sub_08000458
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0x88
	lsls r2, r2, #0x03
	adds r0, r2, #0x0
	strh r0, [r1, #0x00]
	ldr r0, _0800F7D4 @ =0x08316D30
	ldr r1, _0800F7D8 @ =0x08316E5C
	bl sub_080106CC
	ldr r0, _0800F7DC @ =0x08316B30
	mov r1, sp
	bl sub_0800F328
	mov r0, sp
	movs r1, #0x0F
	bl sub_08004238
	movs r0, #0x96
	lsls r0, r0, #0x02
	bl sub_080102BC
	movs r0, #0x00
	movs r1, #0x0F
	bl sub_0800420C
	movs r3, #0x80
	lsls r3, r3, #0x02
	add sp, r3
	pop {r0}
	bx r0
	.global _0800F7B4
_0800F7B4: .4byte 0xFFFFFE00
	.global _0800F7B8
_0800F7B8: .4byte 0x04000008
	.global _0800F7BC
_0800F7BC: .4byte 0x00001C0D
	.global _0800F7C0
_0800F7C0: .4byte 0x00001F82
	.global _0800F7C4
_0800F7C4: .4byte 0x083171A4
	.global _0800F7C8
_0800F7C8: .4byte 0x00005140
	.global _0800F7CC
_0800F7CC: .4byte 0x0833338C
	.global _0800F7D0
_0800F7D0: .4byte 0x0600C000
	.global _0800F7D4
_0800F7D4: .4byte 0x08316D30
	.global _0800F7D8
_0800F7D8: .4byte 0x08316E5C
	.global _0800F7DC
_0800F7DC: .4byte 0x08316B30
