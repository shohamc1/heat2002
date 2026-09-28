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
	.global gModule_SinTable
gModule_SinTable:
	.incbin "build/assets/unknown/data_08344E68.bin"
	.global gUnk_0200C668
gUnk_0200C668:
	.4byte sub_08339FE8
	.4byte sub_0833A058
	.4byte sub_0833A078
	.4byte sub_0833A094
	.4byte sub_0833A0A8
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_0833A0D8
	.4byte sub_0833A0E4
	.4byte sub_0833A0F8
	.4byte sub_0833A10C
	.4byte sub_0833A13C
	.4byte sub_0833A150
	.4byte sub_0833A164
	.4byte sub_0833A178
	.4byte sub_0833A764
	.4byte sub_0833A18C
	.4byte sub_0833A778
	.4byte sub_0833A198
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_0833A1B0
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_08339FE8
	.4byte sub_0833A1C4
	.4byte sub_08339FE8
	.4byte sub_0833A6FC
	.4byte ModuleSampleFreqSet
	.4byte sub_0833A488
	.4byte ModuleFadeOutBody
	.4byte ModuleTrkVolPitSet
	.4byte sub_08339FC8
	.4byte sub_08339FB0
	.global gUnk_0200C6F8
gUnk_0200C6F8:
	.incbin "build/assets/unknown/data_08345178.bin"
	.global gUnk_0200C7AC
gUnk_0200C7AC:
	.incbin "build/assets/unknown/data_0834522C.bin"
	.global gUnk_0200C7DC
gUnk_0200C7DC:
	.incbin "build/assets/unknown/data_0834525C.bin"
	.global gUnk_0200C7F4
gUnk_0200C7F4:
	.incbin "build/assets/unknown/data_08345274.bin"
	.global gUnk_0200C878
gUnk_0200C878:
	.incbin "build/assets/unknown/data_083452F8.bin"
	.global gUnk_0200C890
gUnk_0200C890:
	.incbin "build/assets/unknown/data_08345310.bin"
	.global gUnk_0200C8CC
gUnk_0200C8CC:
	.incbin "build/assets/unknown/data_0834534C.bin"
	.global gUnk_0200C8DC
gUnk_0200C8DC:
	.incbin "build/assets/unknown/data_0834535C.bin"
	.global gUnk_08345390
gUnk_08345390:
	.4byte ModulePlyXxx
	.4byte ModulePlyXwave
	.4byte ModulePlyXtype
	.4byte ModulePlyXxx
	.4byte ModulePlyXatta
	.4byte ModulePlyXdeca
	.4byte sub_0833BC10
	.4byte sub_0833BC24
	.4byte sub_0833BC38
	.4byte sub_0833BC44
	.4byte sub_0833BC50
	.4byte sub_0833BC64
	.4byte 0x3C0B
	.4byte gUnk_083454D4
	.4byte 0xD0000
	.4byte 0x3C01
	.4byte 0x2
	.4byte 0xF0000
	.4byte 0x3C0C
	.4byte 0
	.4byte 0xF0000
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.4byte 0
	.incbin "build/assets/unknown/data_083453FC.bin"
	.global gUnk_083454D4
gUnk_083454D4:
	.incbin "build/assets/unknown/data_083454D4.bin"
	.global gModule_MPlayTable
gModule_MPlayTable:
	.incbin "build/assets/unknown/data_083454F4.bin"
	.global gModule_SongTable
gModule_SongTable:
	.incbin "build/assets/unknown/data_08345524.bin"
