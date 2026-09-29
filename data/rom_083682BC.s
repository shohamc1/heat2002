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
	.global gUnk_083682BC
gUnk_083682BC:
	.incbin "build/assets/unknown/data_083682BC.bin"
	.global gLaneSegs_Track0_Lane00
gLaneSegs_Track0_Lane00:
	.incbin "build/assets/unknown/data_0836844C.bin"
	.global gUnk_08368C1C
gUnk_08368C1C:
	.incbin "build/assets/unknown/data_08368C1C.bin"
	.global gUnk_08368FAE
gUnk_08368FAE:
	.incbin "build/assets/unknown/data_08368FAE.bin"
	.incbin "build/assets/unknown/data_08369780.bin"
	.global gUnk_0836A1B0
gUnk_0836A1B0:
	.incbin "build/assets/unknown/data_0836A1B0.bin"
	.global gLaneSegs_Track0_Lane04
gLaneSegs_Track0_Lane04:
	.incbin "build/assets/unknown/data_0836A318.bin"
	.global gUnk_0836AA20
gUnk_0836AA20:
	.incbin "build/assets/unknown/data_0836AA20.bin"
	.global gUnk_0836ADC2
gUnk_0836ADC2:
	.incbin "build/assets/unknown/data_0836ADC2.bin"
	.global gUnk_0836BFC4
gUnk_0836BFC4:
	.incbin "build/assets/unknown/data_0836BFC4.bin"
	.global gLaneSegs_Track0_Lane07
gLaneSegs_Track0_Lane07:
	.incbin "build/assets/unknown/data_0836C128.bin"
	.global gUnk_0836C81C
gUnk_0836C81C:
	.incbin "build/assets/unknown/data_0836C81C.bin"
	.global gUnk_0836CB40
gUnk_0836CB40:
	.incbin "build/assets/unknown/data_0836CB40.bin"
	.global gUnk_0836DD42
gUnk_0836DD42:
	.incbin "build/assets/unknown/data_0836DD42.bin"
	.global gUnk_0836DD4A
gUnk_0836DD4A:
	.incbin "build/assets/unknown/data_0836DD4A.bin"
	.global gUnk_0836DD4E
gUnk_0836DD4E:
	.incbin "build/assets/unknown/data_0836DD4E.bin"
	.global gUnk_0836DD50
gUnk_0836DD50:
	.incbin "build/assets/unknown/data_0836DD50.bin"
	.global gLaneSegs_Track1_Lane00
gLaneSegs_Track1_Lane00:
	.incbin "build/assets/unknown/data_0836DE3C.bin"
	.global gUnk_0836E2D8
gUnk_0836E2D8:
	.incbin "build/assets/unknown/data_0836E2D8.bin"
	.global gUnk_0836E4DA
gUnk_0836E4DA:
	.incbin "build/assets/unknown/data_0836E4DA.bin"
	.global gUnk_0836F6DC
gUnk_0836F6DC:
	.incbin "build/assets/unknown/data_0836F6DC.bin"
	.global gLaneSegs_Track1_Lane01
gLaneSegs_Track1_Lane01:
	.incbin "build/assets/unknown/data_0836F79C.bin"
	.global gUnk_0836FB5C
gUnk_0836FB5C:
	.incbin "build/assets/unknown/data_0836FB5C.bin"
	.global gUnk_0836FD0A
gUnk_0836FD0A:
	.incbin "build/assets/unknown/data_0836FD0A.bin"
	.incbin "build/assets/unknown/data_08370030.bin"
	.incbin "build/assets/unknown/data_08370814.bin"
	.incbin "build/assets/unknown/data_08370838.bin"
	.incbin "build/assets/unknown/data_08370C20.bin"
	.incbin "build/assets/unknown/data_08370C2C.bin"
	.global gUnk_08370F0C
gUnk_08370F0C:
	.incbin "build/assets/unknown/data_08370F0C.bin"
	.global gLaneSegs_Track1_Lane04
gLaneSegs_Track1_Lane04:
	.incbin "build/assets/unknown/data_08370FD4.bin"
	.global gUnk_083713BC
gUnk_083713BC:
	.incbin "build/assets/unknown/data_083713BC.bin"
	.global gUnk_0837157A
gUnk_0837157A:
	.incbin "build/assets/unknown/data_0837157A.bin"
	.global gUnk_0837401C
gUnk_0837401C:
	.incbin "build/assets/unknown/data_0837401C.bin"
	.global gUnk_0837401E
gUnk_0837401E:
	.incbin "build/assets/unknown/data_0837401E.bin"
	.global gUnk_08374026
gUnk_08374026:
	.incbin "build/assets/unknown/data_08374026.bin"
	.global gUnk_0837402C
gUnk_0837402C:
	.incbin "build/assets/unknown/data_0837402C.bin"
	.global gLaneSegs_Track2_Lane00
gLaneSegs_Track2_Lane00:
	.incbin "build/assets/unknown/data_08374234.bin"
	.global gUnk_08374C5C
gUnk_08374C5C:
	.incbin "build/assets/unknown/data_08374C5C.bin"
	.global gUnk_08375188
gUnk_08375188:
	.incbin "build/assets/unknown/data_08375188.bin"
	.global gUnk_08376388
gUnk_08376388:
	.incbin "build/assets/unknown/data_08376388.bin"
	.global gLaneSegs_Track2_Lane01
gLaneSegs_Track2_Lane01:
	.incbin "build/assets/unknown/data_08376574.bin"
	.global gUnk_08376F10
gUnk_08376F10:
	.incbin "build/assets/unknown/data_08376F10.bin"
	.global gUnk_08377408
gUnk_08377408:
	.incbin "build/assets/unknown/data_08377408.bin"
	.global gUnk_0837EE98
gUnk_0837EE98:
	.incbin "build/assets/unknown/data_0837EE98.bin"
	.global gLaneSegs_Track2_Lane04
gLaneSegs_Track2_Lane04:
	.incbin "build/assets/unknown/data_0837F090.bin"
	.global gUnk_0837FA68
gUnk_0837FA68:
	.incbin "build/assets/unknown/data_0837FA68.bin"
	.global gUnk_0837FF6C
gUnk_0837FF6C:
	.incbin "build/assets/unknown/data_0837FF6C.bin"
	.global gUnk_08383430
gUnk_08383430:
	.incbin "build/assets/unknown/data_08383430.bin"
	.global gLaneSegs_Track2_Lane07
gLaneSegs_Track2_Lane07:
	.incbin "build/assets/unknown/data_0838361C.bin"
	.global gUnk_08383FB8
gUnk_08383FB8:
	.incbin "build/assets/unknown/data_08383FB8.bin"
	.global gUnk_0838449E
gUnk_0838449E:
	.incbin "build/assets/unknown/data_0838449E.bin"
	.global gUnk_0838569E
gUnk_0838569E:
	.incbin "build/assets/unknown/data_0838569E.bin"
	.global gUnk_083856A0
gUnk_083856A0:
	.incbin "build/assets/unknown/data_083856A0.bin"
	.global gUnk_083856A8
gUnk_083856A8:
	.incbin "build/assets/unknown/data_083856A8.bin"
	.global gUnk_083856AC
gUnk_083856AC:
	.incbin "build/assets/unknown/data_083856AC.bin"
	.global gUnk_083856B0
gUnk_083856B0:
	.incbin "build/assets/unknown/data_083856B0.bin"
	.global gLaneSegs_Track3_Lane00
gLaneSegs_Track3_Lane00:
	.incbin "build/assets/unknown/data_08385810.bin"
	.global gUnk_08385EF0
gUnk_08385EF0:
	.incbin "build/assets/unknown/data_08385EF0.bin"
	.global gUnk_08386238
gUnk_08386238:
	.incbin "build/assets/unknown/data_08386238.bin"
	.global gUnk_08387438
gUnk_08387438:
	.incbin "build/assets/unknown/data_08387438.bin"
	.global gLaneSegs_Track3_Lane01
gLaneSegs_Track3_Lane01:
	.incbin "build/assets/unknown/data_08387580.bin"
	.global gUnk_08387BE8
gUnk_08387BE8:
	.incbin "build/assets/unknown/data_08387BE8.bin"
	.global gUnk_08387EDE
gUnk_08387EDE:
	.incbin "build/assets/unknown/data_08387EDE.bin"
	.global gUnk_083890E0
gUnk_083890E0:
	.incbin "build/assets/unknown/data_083890E0.bin"
	.global gLaneSegs_Track3_Lane04
gLaneSegs_Track3_Lane04:
	.incbin "build/assets/unknown/data_08389238.bin"
	.global gUnk_083898F0
gUnk_083898F0:
	.incbin "build/assets/unknown/data_083898F0.bin"
	.global gUnk_08389BD2
gUnk_08389BD2:
	.incbin "build/assets/unknown/data_08389BD2.bin"
	.global gUnk_0838ADD4
gUnk_0838ADD4:
	.incbin "build/assets/unknown/data_0838ADD4.bin"
	.global gLaneSegs_Track3_Lane07
gLaneSegs_Track3_Lane07:
	.incbin "build/assets/unknown/data_0838AF50.bin"
	.global gUnk_0838B6BC
gUnk_0838B6BC:
	.incbin "build/assets/unknown/data_0838B6BC.bin"
	.global gUnk_0838BA2E
gUnk_0838BA2E:
	.incbin "build/assets/unknown/data_0838BA2E.bin"
	.global gUnk_0838CC2E
gUnk_0838CC2E:
	.incbin "build/assets/unknown/data_0838CC2E.bin"
	.global gUnk_0838CC30
gUnk_0838CC30:
	.incbin "build/assets/unknown/data_0838CC30.bin"
	.global gUnk_0838CC38
gUnk_0838CC38:
	.incbin "build/assets/unknown/data_0838CC38.bin"
	.global gUnk_0838CC3C
gUnk_0838CC3C:
	.incbin "build/assets/unknown/data_0838CC3C.bin"
	.global gUnk_0838CC40
gUnk_0838CC40:
	.incbin "build/assets/unknown/data_0838CC40.bin"
	.global gLaneSegs_Track4_Lane00
gLaneSegs_Track4_Lane00:
	.incbin "build/assets/unknown/data_0838CEA0.bin"
	.global gUnk_0838DA6C
gUnk_0838DA6C:
	.incbin "build/assets/unknown/data_0838DA6C.bin"
	.global gUnk_0838E028
gUnk_0838E028:
	.incbin "build/assets/unknown/data_0838E028.bin"
	.incbin "build/assets/unknown/data_0838E364.bin"
	.global gUnk_0838F228
gUnk_0838F228:
	.incbin "build/assets/unknown/data_0838F228.bin"
	.global gLaneSegs_Track4_Lane01
gLaneSegs_Track4_Lane01:
	.incbin "build/assets/unknown/data_0838F47C.bin"
	.global gUnk_08390020
gUnk_08390020:
	.incbin "build/assets/unknown/data_08390020.bin"
	.incbin "build/assets/unknown/data_0839049C.bin"
	.global gUnk_083905EC
gUnk_083905EC:
	.incbin "build/assets/unknown/data_083905EC.bin"
	.incbin "build/assets/unknown/data_083906A8.bin"
	.incbin "build/assets/unknown/data_08390798.bin"
	.incbin "build/assets/unknown/data_083907EC.bin"
	.incbin "build/assets/unknown/data_083907F4.bin"
	.incbin "build/assets/unknown/data_08390838.bin"
	.incbin "build/assets/unknown/data_08390C2C.bin"
	.incbin "build/assets/unknown/data_08391400.bin"
	.global gUnk_083917EC
gUnk_083917EC:
	.incbin "build/assets/unknown/data_083917EC.bin"
	.global gLaneSegs_Track4_Lane04
gLaneSegs_Track4_Lane04:
	.incbin "build/assets/unknown/data_08391A6C.bin"
	.incbin "build/assets/unknown/data_08391FE0.bin"
	.global gUnk_083926EC
gUnk_083926EC:
	.incbin "build/assets/unknown/data_083926EC.bin"
	.global gUnk_08392CEA
gUnk_08392CEA:
	.incbin "build/assets/unknown/data_08392CEA.bin"
	.global gUnk_08393EEC
gUnk_08393EEC:
	.incbin "build/assets/unknown/data_08393EEC.bin"
	.global gLaneSegs_Track4_Lane07
gLaneSegs_Track4_Lane07:
	.incbin "build/assets/unknown/data_08394140.bin"
	.global gUnk_08394CE4
gUnk_08394CE4:
	.incbin "build/assets/unknown/data_08394CE4.bin"
	.global gUnk_0839523A
gUnk_0839523A:
	.incbin "build/assets/unknown/data_0839523A.bin"
	.global gUnk_0839643A
gUnk_0839643A:
	.incbin "build/assets/unknown/data_0839643A.bin"
	.global gUnk_0839643C
gUnk_0839643C:
	.incbin "build/assets/unknown/data_0839643C.bin"
	.global gUnk_08396444
gUnk_08396444:
	.incbin "build/assets/unknown/data_08396444.bin"
	.global gUnk_08396448
gUnk_08396448:
	.incbin "build/assets/unknown/data_08396448.bin"
	.global gUnk_0839644C
gUnk_0839644C:
	.incbin "build/assets/unknown/data_0839644C.bin"
	.global gLaneSegs_Track5_Lane00
gLaneSegs_Track5_Lane00:
	.incbin "build/assets/unknown/data_08396630.bin"
	.global gUnk_08396FA4
gUnk_08396FA4:
	.incbin "build/assets/unknown/data_08396FA4.bin"
	.global gUnk_08397436
gUnk_08397436:
	.incbin "build/assets/unknown/data_08397436.bin"
	.global gUnk_08398638
gUnk_08398638:
	.incbin "build/assets/unknown/data_08398638.bin"
	.global gLaneSegs_Track5_Lane01
gLaneSegs_Track5_Lane01:
	.incbin "build/assets/unknown/data_08398824.bin"
	.global gUnk_083991C0
gUnk_083991C0:
	.incbin "build/assets/unknown/data_083991C0.bin"
	.global gUnk_08399686
gUnk_08399686:
	.incbin "build/assets/unknown/data_08399686.bin"
	.global gUnk_0839A888
gUnk_0839A888:
	.incbin "build/assets/unknown/data_0839A888.bin"
	.global gLaneSegs_Track5_Lane04
gLaneSegs_Track5_Lane04:
	.incbin "build/assets/unknown/data_0839AA4C.bin"
	.global gUnk_0839B320
gUnk_0839B320:
	.incbin "build/assets/unknown/data_0839B320.bin"
	.global gUnk_0839B788
gUnk_0839B788:
	.incbin "build/assets/unknown/data_0839B788.bin"
	.global gUnk_0839C988
gUnk_0839C988:
	.incbin "build/assets/unknown/data_0839C988.bin"
	.global gLaneSegs_Track5_Lane07
gLaneSegs_Track5_Lane07:
	.incbin "build/assets/unknown/data_0839CB7C.bin"
	.global gUnk_0839D540
gUnk_0839D540:
	.incbin "build/assets/unknown/data_0839D540.bin"
	.global gUnk_0839DA64
gUnk_0839DA64:
	.incbin "build/assets/unknown/data_0839DA64.bin"
	.global gUnk_0839EC64
gUnk_0839EC64:
	.incbin "build/assets/unknown/data_0839EC64.bin"
	.global gUnk_0839EC66
gUnk_0839EC66:
	.incbin "build/assets/unknown/data_0839EC66.bin"
	.global gUnk_0839EC6E
gUnk_0839EC6E:
	.incbin "build/assets/unknown/data_0839EC6E.bin"
	.global gUnk_0839EC72
gUnk_0839EC72:
	.incbin "build/assets/unknown/data_0839EC72.bin"
	.global gUnk_0839EC74
gUnk_0839EC74:
	.incbin "build/assets/unknown/data_0839EC74.bin"
	.global gLaneSegs_Track6_Lane00
gLaneSegs_Track6_Lane00:
	.incbin "build/assets/unknown/data_0839ED64.bin"
	.global gUnk_0839F214
gUnk_0839F214:
	.incbin "build/assets/unknown/data_0839F214.bin"
	.global gUnk_0839F3A6
gUnk_0839F3A6:
	.incbin "build/assets/unknown/data_0839F3A6.bin"
	.global gUnk_083A05A8
gUnk_083A05A8:
	.incbin "build/assets/unknown/data_083A05A8.bin"
	.global gLaneSegs_Track6_Lane01
gLaneSegs_Track6_Lane01:
	.incbin "build/assets/unknown/data_083A06A4.bin"
	.incbin "build/assets/unknown/data_083A082C.bin"
	.global gUnk_083A0B90
gUnk_083A0B90:
	.incbin "build/assets/unknown/data_083A0B90.bin"
	.global gUnk_083A0DA4
gUnk_083A0DA4:
	.incbin "build/assets/unknown/data_083A0DA4.bin"
	.global gUnk_083A1FA4
gUnk_083A1FA4:
	.incbin "build/assets/unknown/data_083A1FA4.bin"
	.global gLaneSegs_Track6_Lane04
gLaneSegs_Track6_Lane04:
	.incbin "build/assets/unknown/data_083A20D0.bin"
	.global gUnk_083A26AC
gUnk_083A26AC:
	.incbin "build/assets/unknown/data_083A26AC.bin"
	.global gUnk_083A2964
gUnk_083A2964:
	.incbin "build/assets/unknown/data_083A2964.bin"
	.global gUnk_083A3B64
gUnk_083A3B64:
	.incbin "build/assets/unknown/data_083A3B64.bin"
	.global gLaneSegs_Track6_Lane07
gLaneSegs_Track6_Lane07:
	.incbin "build/assets/unknown/data_083A3C7C.bin"
	.global gUnk_083A41F4
gUnk_083A41F4:
	.incbin "build/assets/unknown/data_083A41F4.bin"
	.global gUnk_083A4458
gUnk_083A4458:
	.incbin "build/assets/unknown/data_083A4458.bin"
	.global gUnk_083A5658
gUnk_083A5658:
	.incbin "build/assets/unknown/data_083A5658.bin"
	.global gUnk_083A565A
gUnk_083A565A:
	.incbin "build/assets/unknown/data_083A565A.bin"
	.global gUnk_083A565C
gUnk_083A565C:
	.incbin "build/assets/unknown/data_083A565C.bin"
	.global gUnk_083A5662
gUnk_083A5662:
	.incbin "build/assets/unknown/data_083A5662.bin"
	.global gUnk_083A5666
gUnk_083A5666:
	.incbin "build/assets/unknown/data_083A5666.bin"
	.global gUnk_083A5668
gUnk_083A5668:
	.incbin "build/assets/unknown/data_083A5668.bin"
	.global gLaneSegs_Track8_Lane00
gLaneSegs_Track8_Lane00:
	.incbin "build/assets/unknown/data_083A5784.bin"
	.global gUnk_083A5D10
gUnk_083A5D10:
	.incbin "build/assets/unknown/data_083A5D10.bin"
	.global gUnk_083A5F3E
gUnk_083A5F3E:
	.incbin "build/assets/unknown/data_083A5F3E.bin"
	.global gUnk_083A7140
gUnk_083A7140:
	.incbin "build/assets/unknown/data_083A7140.bin"
	.global gLaneSegs_Track8_Lane01
gLaneSegs_Track8_Lane01:
	.incbin "build/assets/unknown/data_083A7270.bin"
	.global gUnk_083A7860
gUnk_083A7860:
	.incbin "build/assets/unknown/data_083A7860.bin"
	.global gUnk_083A7B28
gUnk_083A7B28:
	.incbin "build/assets/unknown/data_083A7B28.bin"
	.global gUnk_083A8D28
gUnk_083A8D28:
	.incbin "build/assets/unknown/data_083A8D28.bin"
	.global gLaneSegs_Track8_Lane04
gLaneSegs_Track8_Lane04:
	.incbin "build/assets/unknown/data_083A8E60.bin"
	.global gUnk_083A9478
gUnk_083A9478:
	.incbin "build/assets/unknown/data_083A9478.bin"
	.global gUnk_083A9710
gUnk_083A9710:
	.incbin "build/assets/unknown/data_083A9710.bin"
	.global gUnk_083AA910
gUnk_083AA910:
	.incbin "build/assets/unknown/data_083AA910.bin"
	.global gLaneSegs_Track8_Lane07
gLaneSegs_Track8_Lane07:
	.incbin "build/assets/unknown/data_083AAA50.bin"
	.global gUnk_083AB090
gUnk_083AB090:
	.incbin "build/assets/unknown/data_083AB090.bin"
	.global gUnk_083AB36C
gUnk_083AB36C:
	.incbin "build/assets/unknown/data_083AB36C.bin"
	.global gUnk_083AC56C
gUnk_083AC56C:
	.incbin "build/assets/unknown/data_083AC56C.bin"
	.global gUnk_083AC56E
gUnk_083AC56E:
	.incbin "build/assets/unknown/data_083AC56E.bin"
	.global gUnk_083AC576
gUnk_083AC576:
	.incbin "build/assets/unknown/data_083AC576.bin"
	.global gUnk_083AC57A
gUnk_083AC57A:
	.incbin "build/assets/unknown/data_083AC57A.bin"
	.global gUnk_083AC57C
gUnk_083AC57C:
	.incbin "build/assets/unknown/data_083AC57C.bin"
	.global gLaneSegs_Track9_Lane00
gLaneSegs_Track9_Lane00:
	.incbin "build/assets/unknown/data_083AC780.bin"
	.global gUnk_083AD194
gUnk_083AD194:
	.incbin "build/assets/unknown/data_083AD194.bin"
	.global gUnk_083AD67A
gUnk_083AD67A:
	.incbin "build/assets/unknown/data_083AD67A.bin"
	.global gUnk_083AE87C
gUnk_083AE87C:
	.incbin "build/assets/unknown/data_083AE87C.bin"
	.global gLaneSegs_Track9_Lane01
gLaneSegs_Track9_Lane01:
	.incbin "build/assets/unknown/data_083AEA88.bin"
	.global gUnk_083AF4C4
gUnk_083AF4C4:
	.incbin "build/assets/unknown/data_083AF4C4.bin"
	.global gUnk_083AF9AC
gUnk_083AF9AC:
	.incbin "build/assets/unknown/data_083AF9AC.bin"
	.incbin "build/assets/unknown/data_083B0000.bin"
	.incbin "build/assets/unknown/data_083B083C.bin"
	.incbin "build/assets/unknown/data_083B6054.bin"
	.global gUnk_083B73C0
gUnk_083B73C0:
	.incbin "build/assets/unknown/data_083B73C0.bin"
	.global gLaneSegs_Track9_Lane04
gLaneSegs_Track9_Lane04:
	.incbin "build/assets/unknown/data_083B75C4.bin"
	.global gUnk_083B7FD8
gUnk_083B7FD8:
	.incbin "build/assets/unknown/data_083B7FD8.bin"
	.global gUnk_083B84C4
gUnk_083B84C4:
	.incbin "build/assets/unknown/data_083B84C4.bin"
	.global gUnk_083B96C4
gUnk_083B96C4:
	.incbin "build/assets/unknown/data_083B96C4.bin"
	.global gLaneSegs_Track9_Lane07
gLaneSegs_Track9_Lane07:
	.incbin "build/assets/unknown/data_083B98C0.bin"
	.global gUnk_083BA2AC
gUnk_083BA2AC:
	.incbin "build/assets/unknown/data_083BA2AC.bin"
	.global gUnk_083BA78E
gUnk_083BA78E:
	.incbin "build/assets/unknown/data_083BA78E.bin"
	.global gUnk_083BB98E
gUnk_083BB98E:
	.incbin "build/assets/unknown/data_083BB98E.bin"
	.global gUnk_083BB990
gUnk_083BB990:
	.incbin "build/assets/unknown/data_083BB990.bin"
	.global gUnk_083BB998
gUnk_083BB998:
	.incbin "build/assets/unknown/data_083BB998.bin"
	.global gUnk_083BB99C
gUnk_083BB99C:
	.incbin "build/assets/unknown/data_083BB99C.bin"
	.global gUnk_083BB9A0
gUnk_083BB9A0:
	.incbin "build/assets/unknown/data_083BB9A0.bin"
	.global gLaneSegs_Track10_Lane00
gLaneSegs_Track10_Lane00:
	.incbin "build/assets/unknown/data_083BBA60.bin"
	.global gUnk_083BBE20
gUnk_083BBE20:
	.incbin "build/assets/unknown/data_083BBE20.bin"
	.global gUnk_083BBF98
gUnk_083BBF98:
	.incbin "build/assets/unknown/data_083BBF98.bin"
	.global gUnk_083BD198
gUnk_083BD198:
	.incbin "build/assets/unknown/data_083BD198.bin"
	.global gLaneSegs_Track10_Lane01
gLaneSegs_Track10_Lane01:
	.incbin "build/assets/unknown/data_083BD254.bin"
	.global gUnk_083BD600
gUnk_083BD600:
	.incbin "build/assets/unknown/data_083BD600.bin"
	.global gUnk_083BD77A
gUnk_083BD77A:
	.incbin "build/assets/unknown/data_083BD77A.bin"
	.global gUnk_083BE97C
gUnk_083BE97C:
	.incbin "build/assets/unknown/data_083BE97C.bin"
	.global gLaneSegs_Track10_Lane04
gLaneSegs_Track10_Lane04:
	.incbin "build/assets/unknown/data_083BEA28.bin"
	.global gUnk_083BED84
gUnk_083BED84:
	.incbin "build/assets/unknown/data_083BED84.bin"
	.global gUnk_083BEED8
gUnk_083BEED8:
	.incbin "build/assets/unknown/data_083BEED8.bin"
	.incbin "build/assets/unknown/data_083C0000.bin"
	.global gUnk_083C00D8
gUnk_083C00D8:
	.incbin "build/assets/unknown/data_083C00D8.bin"
	.global gLaneSegs_Track10_Lane07
gLaneSegs_Track10_Lane07:
	.incbin "build/assets/unknown/data_083C01B4.bin"
	.global gUnk_083C0600
gUnk_083C0600:
	.incbin "build/assets/unknown/data_083C0600.bin"
	.global gUnk_083C07C2
gUnk_083C07C2:
	.incbin "build/assets/unknown/data_083C07C2.bin"
	.incbin "build/assets/unknown/data_083C0CF8.bin"
	.global gUnk_083C19C2
gUnk_083C19C2:
	.incbin "build/assets/unknown/data_083C19C2.bin"
	.global gUnk_083C19C4
gUnk_083C19C4:
	.incbin "build/assets/unknown/data_083C19C4.bin"
	.global gUnk_083C19CC
gUnk_083C19CC:
	.incbin "build/assets/unknown/data_083C19CC.bin"
	.global gUnk_083C19D0
gUnk_083C19D0:
	.incbin "build/assets/unknown/data_083C19D0.bin"
	.global gUnk_083C19D4
gUnk_083C19D4:
	.incbin "build/assets/unknown/data_083C19D4.bin"
	.global gLaneSegs_Track11_Lane00
gLaneSegs_Track11_Lane00:
	.incbin "build/assets/unknown/data_083C1B5C.bin"
	.global gUnk_083C2304
gUnk_083C2304:
	.incbin "build/assets/unknown/data_083C2304.bin"
	.incbin "build/assets/unknown/data_083C253C.bin"
	.global gUnk_083C267E
gUnk_083C267E:
	.incbin "build/assets/unknown/data_083C267E.bin"
	.incbin "build/assets/unknown/data_083C2E38.bin"
	.global gUnk_083C3880
gUnk_083C3880:
	.incbin "build/assets/unknown/data_083C3880.bin"
	.global gLaneSegs_Track11_Lane01
gLaneSegs_Track11_Lane01:
	.incbin "build/assets/unknown/data_083C3A08.bin"
	.global gUnk_083C41B0
gUnk_083C41B0:
	.incbin "build/assets/unknown/data_083C41B0.bin"
	.global gUnk_083C4524
gUnk_083C4524:
	.incbin "build/assets/unknown/data_083C4524.bin"
	.global gUnk_083C5724
gUnk_083C5724:
	.incbin "build/assets/unknown/data_083C5724.bin"
	.global gLaneSegs_Track11_Lane04
gLaneSegs_Track11_Lane04:
	.incbin "build/assets/unknown/data_083C58A4.bin"
	.global gUnk_083C6024
gUnk_083C6024:
	.incbin "build/assets/unknown/data_083C6024.bin"
	.global gUnk_083C639C
gUnk_083C639C:
	.incbin "build/assets/unknown/data_083C639C.bin"
	.global gUnk_083C759C
gUnk_083C759C:
	.incbin "build/assets/unknown/data_083C759C.bin"
	.global gLaneSegs_Track11_Lane07
gLaneSegs_Track11_Lane07:
	.incbin "build/assets/unknown/data_083C7740.bin"
	.global gUnk_083C7F74
gUnk_083C7F74:
	.incbin "build/assets/unknown/data_083C7F74.bin"
	.global gUnk_083C8362
gUnk_083C8362:
	.incbin "build/assets/unknown/data_083C8362.bin"
	.global gUnk_083C9562
gUnk_083C9562:
	.incbin "build/assets/unknown/data_083C9562.bin"
	.global gUnk_083C9564
gUnk_083C9564:
	.incbin "build/assets/unknown/data_083C9564.bin"
	.global gUnk_083C956A
gUnk_083C956A:
	.incbin "build/assets/unknown/data_083C956A.bin"
	.global gUnk_083C9570
gUnk_083C9570:
	.incbin "build/assets/unknown/data_083C9570.bin"
