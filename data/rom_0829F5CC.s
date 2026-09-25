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
	.thumb
	.global gUnk_0829F5CC
gUnk_0829F5CC:
	.incbin "build/assets/unknown/data_0829F5CC.bin"
	.global gUnk_0829F5DC
gUnk_0829F5DC:
	.incbin "build/assets/unknown/data_0829F5DC.bin"
	.global gUnk_0829F5EC
gUnk_0829F5EC:
	.incbin "build/assets/unknown/data_0829F5EC.bin"
	.global gUnk_0829F5FC
gUnk_0829F5FC:
	.incbin "build/assets/unknown/data_0829F5FC.bin"
	.global gUnk_0829F60C
gUnk_0829F60C:
	.incbin "build/assets/unknown/data_0829F60C.bin"
	.global gUnk_0829F624
gUnk_0829F624:
	.incbin "build/assets/unknown/data_0829F624.bin"
	.global gUnk_0829F630
gUnk_0829F630:
	.incbin "build/assets/unknown/data_0829F630.bin"
	.global gUnk_0829F64C
gUnk_0829F64C:
	.incbin "build/assets/unknown/data_0829F64C.bin"
	.global gUnk_0829F65C
gUnk_0829F65C:
	.incbin "build/assets/unknown/data_0829F65C.bin"
	.global gUnk_0829F668
gUnk_0829F668:
	.incbin "build/assets/unknown/data_0829F668.bin"
	.global gUnk_0829F674
gUnk_0829F674:
	.incbin "build/assets/unknown/data_0829F674.bin"
	.global gUnk_0829F684
gUnk_0829F684:
	.incbin "build/assets/unknown/data_0829F684.bin"
	.global gUnk_0829F694
gUnk_0829F694:
	.incbin "build/assets/unknown/data_0829F694.bin"
	.global gUnk_0829F6A0
gUnk_0829F6A0:
	.incbin "build/assets/unknown/data_0829F6A0.bin"
	.global gUnk_0829F6B8
gUnk_0829F6B8:
	.incbin "build/assets/unknown/data_0829F6B8.bin"
	.global gUnk_0829F6D0
gUnk_0829F6D0:
	.incbin "build/assets/unknown/data_0829F6D0.bin"
	.global gUnk_0829F6DC
gUnk_0829F6DC:
	.incbin "build/assets/unknown/data_0829F6DC.bin"
	.global gUnk_0829F6F0
gUnk_0829F6F0:
	.incbin "build/assets/unknown/data_0829F6F0.bin"
	.global gUnk_0829F6FC
gUnk_0829F6FC:
	.incbin "build/assets/unknown/data_0829F6FC.bin"
	.global gUnk_0829F710
gUnk_0829F710:
	.incbin "build/assets/unknown/data_0829F710.bin"
	.global gUnk_0829F720
gUnk_0829F720:
	.incbin "build/assets/unknown/data_0829F720.bin"
	.global gUnk_0829F738
gUnk_0829F738:
	.incbin "build/assets/unknown/data_0829F738.bin"
	.global gUnk_0829F748
gUnk_0829F748:
	.incbin "build/assets/unknown/data_0829F748.bin"
	.global gUnk_0829F758
gUnk_0829F758:
	.incbin "build/assets/unknown/data_0829F758.bin"
	.global gUnk_0829F764
gUnk_0829F764:
	.incbin "build/assets/unknown/data_0829F764.bin"
	.global gUnk_0829F784
gUnk_0829F784:
	.incbin "build/assets/unknown/data_0829F784.bin"
	.global gUnk_0829F798
gUnk_0829F798:
	.incbin "build/assets/unknown/data_0829F798.bin"
	.global gUnk_0829F7B8
gUnk_0829F7B8:
	.incbin "build/assets/unknown/data_0829F7B8.bin"
	.global gUnk_0829F7C4
gUnk_0829F7C4:
	.incbin "build/assets/unknown/data_0829F7C4.bin"
	.global gUnk_0829F7D0
gUnk_0829F7D0:
	.incbin "build/assets/unknown/data_0829F7D0.bin"
	.global gUnk_0829F7E4
gUnk_0829F7E4:
	.incbin "build/assets/unknown/data_0829F7E4.bin"
	.global gUnk_0829F7F4
gUnk_0829F7F4:
	.incbin "build/assets/unknown/data_0829F7F4.bin"
	.global gUnk_0829F800
gUnk_0829F800:
	.incbin "build/assets/unknown/data_0829F800.bin"
	.global gUnk_0829F814
gUnk_0829F814:
	.incbin "build/assets/unknown/data_0829F814.bin"
	.global gUnk_0829F824
gUnk_0829F824:
	.incbin "build/assets/unknown/data_0829F824.bin"
	.global gUnk_0829F838
gUnk_0829F838:
	.incbin "build/assets/unknown/data_0829F838.bin"
	.global gUnk_0829F850
gUnk_0829F850:
	.incbin "build/assets/unknown/data_0829F850.bin"
	.global gUnk_0829F860
gUnk_0829F860:
	.incbin "build/assets/unknown/data_0829F860.bin"
	.global gUnk_0829F874
gUnk_0829F874:
	.incbin "build/assets/unknown/data_0829F874.bin"
	.global gUnk_0829F88C
gUnk_0829F88C:
	.incbin "build/assets/unknown/data_0829F88C.bin"
	.global gUnk_0829F8A0
gUnk_0829F8A0:
	.incbin "build/assets/unknown/data_0829F8A0.bin"
	.global gUnk_0829F8B0
gUnk_0829F8B0:
	.incbin "build/assets/unknown/data_0829F8B0.bin"
	.global gUnk_0829F8BC
gUnk_0829F8BC:
	.incbin "build/assets/unknown/data_0829F8BC.bin"
	.global gUnk_0829F8C8
gUnk_0829F8C8:
	.incbin "build/assets/unknown/data_0829F8C8.bin"
	.global gUnk_0829F8D8
gUnk_0829F8D8:
	.incbin "build/assets/unknown/data_0829F8D8.bin"
	.global gUnk_0829F8E4
gUnk_0829F8E4:
	.incbin "build/assets/unknown/data_0829F8E4.bin"
	.global gUnk_0829F8F4
gUnk_0829F8F4:
	.incbin "build/assets/unknown/data_0829F8F4.bin"
	.global gUnk_0829F908
gUnk_0829F908:
	.incbin "build/assets/unknown/data_0829F908.bin"
	.global gUnk_0829F920
gUnk_0829F920:
	.incbin "build/assets/unknown/data_0829F920.bin"
	.global gUnk_0829F930
gUnk_0829F930:
	.incbin "build/assets/unknown/data_0829F930.bin"
	.global gUnk_0829F948
gUnk_0829F948:
	.incbin "build/assets/unknown/data_0829F948.bin"
