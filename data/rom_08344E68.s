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
	.global gUnk_0200C3E8
gUnk_0200C3E8:
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
	.4byte sub_0833AD00
	.4byte sub_0833A488
	.4byte sub_0833B0B4
	.4byte sub_0833B134
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
	.4byte sub_0833BB78
	.4byte sub_0833BB8C
	.4byte sub_0833BBD4
	.4byte sub_0833BB78
	.4byte sub_0833BBE8
	.4byte sub_0833BBFC
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
	.global gUnk_0200CA74
gUnk_0200CA74:
	.incbin "build/assets/unknown/data_083454F4.bin"
	.global gUnk_0200CAA4
gUnk_0200CAA4:
	.incbin "build/assets/unknown/data_08345524.bin"
	.global gUnk_0200CEC0
gUnk_0200CEC0:
	.incbin "build/assets/unknown/data_08345940.bin"
	.global gUnk_0200CED8
gUnk_0200CED8:
	.incbin "build/assets/unknown/data_08345958.bin"
	.global gUnk_0200CEEC
gUnk_0200CEEC:
	.incbin "build/assets/unknown/data_0834596C.bin"
	.global gUnk_0200CEF8
gUnk_0200CEF8:
	.incbin "build/assets/unknown/data_08345978.bin"
	.global gUnk_0200CF04
gUnk_0200CF04:
	.incbin "build/assets/unknown/data_08345984.bin"
	.global gUnk_0200CF10
gUnk_0200CF10:
	.incbin "build/assets/unknown/data_08345990.bin"
	.global gUnk_0200CF1C
gUnk_0200CF1C:
	.incbin "build/assets/unknown/data_0834599C.bin"
	.global gUnk_0200CF34
gUnk_0200CF34:
	.incbin "build/assets/unknown/data_083459B4.bin"
	.global gUnk_0200CF48
gUnk_0200CF48:
	.incbin "build/assets/unknown/data_083459C8.bin"
	.global gUnk_0200CF5C
gUnk_0200CF5C:
	.incbin "build/assets/unknown/data_083459DC.bin"
	.global gUnk_0200CF70
gUnk_0200CF70:
	.incbin "build/assets/unknown/data_083459F0.bin"
	.global gUnk_0200CF74
gUnk_0200CF74:
	.incbin "build/assets/unknown/data_083459F4.bin"
	.global gUnk_0200CF84
gUnk_0200CF84:
	.incbin "build/assets/unknown/data_08345A04.bin"
	.global gUnk_0200CF88
gUnk_0200CF88:
	.incbin "build/assets/unknown/data_08345A08.bin"
	.global gUnk_0200CF90
gUnk_0200CF90:
	.incbin "build/assets/unknown/data_08345A10.bin"
	.global gUnk_0200D058
gUnk_0200D058:
	.incbin "build/assets/unknown/data_08345AD8.bin"
	.global gUnk_0200D064
gUnk_0200D064:
	.incbin "build/assets/unknown/data_08345AE4.bin"
	.global gUnk_0200D07C
gUnk_0200D07C:
	.incbin "build/assets/unknown/data_08345AFC.bin"
	.global gUnk_0200D098
gUnk_0200D098:
	.incbin "build/assets/unknown/data_08345B18.bin"
	.global gUnk_0200D0A4
gUnk_0200D0A4:
	.incbin "build/assets/unknown/data_08345B24.bin"
	.global gUnk_0200D0B8
gUnk_0200D0B8:
	.incbin "build/assets/unknown/data_08345B38.bin"
	.global gUnk_0200D0C0
gUnk_0200D0C0:
	.incbin "build/assets/unknown/data_08345B40.bin"
	.global gUnk_0200D0F4
gUnk_0200D0F4:
	.incbin "build/assets/unknown/data_08345B74.bin"
	.global gUnk_0200D100
gUnk_0200D100:
	.incbin "build/assets/unknown/data_08345B80.bin"
	.global gUnk_0200D118
gUnk_0200D118:
	.incbin "build/assets/unknown/data_08345B98.bin"
	.incbin "build/assets/unknown/data_08349780.bin"
	.incbin "build/assets/unknown/data_0835041C.bin"
	.incbin "build/assets/unknown/data_08350528.bin"
	.incbin "build/assets/unknown/data_0835081C.bin"
	.incbin "build/assets/unknown/data_08350830.bin"
	.incbin "build/assets/unknown/data_08350834.bin"
	.incbin "build/assets/unknown/data_0835085C.bin"
	.incbin "build/assets/unknown/data_08350C20.bin"
	.incbin "build/assets/unknown/data_08351780.bin"
	.global gUnk_0201AA30
gUnk_0201AA30:
	.incbin "build/assets/unknown/data_083534B0.bin"
	.global gUnk_0201AA40
gUnk_0201AA40:
	.incbin "build/assets/unknown/data_083534C0.bin"
	.global gUnk_0201AA54
gUnk_0201AA54:
	.incbin "build/assets/unknown/data_083534D4.bin"
	.global gUnk_0201B590
gUnk_0201B590:
	.incbin "build/assets/unknown/data_08354010.bin"
	.global gUnk_0201F370
gUnk_0201F370:
	.incbin "build/assets/unknown/data_08357DF0.bin"
	.global gUnk_0201F390
gUnk_0201F390:
	.incbin "build/assets/unknown/data_08357E10.bin"
	.global gUnk_0201F550
gUnk_0201F550:
	.incbin "build/assets/unknown/data_08357FD0.bin"
	.global gUnk_0201F590
gUnk_0201F590:
	.incbin "build/assets/unknown/data_08358010.bin"
	.incbin "build/assets/unknown/data_08358070.bin"
	.global gUnk_0201F9D0
gUnk_0201F9D0:
	.incbin "build/assets/unknown/data_08358450.bin"
	.global gUnk_0201FB54
gUnk_0201FB54:
	.incbin "build/assets/unknown/data_083585D4.bin"
	.incbin "build/assets/unknown/data_08359780.bin"
	.global gUnk_02021394
gUnk_02021394:
	.incbin "build/assets/unknown/data_08359E14.bin"
	.global gUnk_02021594
gUnk_02021594:
	.incbin "build/assets/unknown/data_0835A014.bin"
	.global gUnk_020215AA
gUnk_020215AA:
	.incbin "build/assets/unknown/data_0835A02A.bin"
	.global gUnk_020215D2
gUnk_020215D2:
	.incbin "build/assets/unknown/data_0835A052.bin"
	.global gUnk_020215EA
gUnk_020215EA:
	.incbin "build/assets/unknown/data_0835A06A.bin"
	.global gUnk_02021D04
gUnk_02021D04:
	.incbin "build/assets/unknown/data_0835A784.bin"
	.global gUnk_02022254
gUnk_02022254:
	.incbin "build/assets/unknown/data_0835ACD4.bin"
	.global gUnk_02022428
gUnk_02022428:
	.incbin "build/assets/unknown/data_0835AEA8.bin"
	.global gUnk_020243E8
gUnk_020243E8:
	.incbin "build/assets/unknown/data_0835CE68.bin"
	.global gUnk_02024EE8
gUnk_02024EE8:
	.incbin "build/assets/unknown/data_0835D968.bin"
	.global gUnk_02024F50
gUnk_02024F50:
	.incbin "build/assets/unknown/data_0835D9D0.bin"
	.global gUnk_02024F70
gUnk_02024F70:
	.incbin "build/assets/unknown/data_0835D9F0.bin"
	.global gUnk_020250EC
gUnk_020250EC:
	.incbin "build/assets/unknown/data_0835DB6C.bin"
	.global gUnk_020250F0
gUnk_020250F0:
	.incbin "build/assets/unknown/data_0835DB70.bin"
	.global gUnk_02025190
gUnk_02025190:
	.incbin "build/assets/unknown/data_0835DC10.bin"
	.global gUnk_020251A4
gUnk_020251A4:
	.incbin "build/assets/unknown/data_0835DC24.bin"
	.global gUnk_020251B8
gUnk_020251B8:
	.incbin "build/assets/unknown/data_0835DC38.bin"
	.global gUnk_020251BC
gUnk_020251BC:
	.incbin "build/assets/unknown/data_0835DC3C.bin"
	.global gUnk_02025230
gUnk_02025230:
	.incbin "build/assets/unknown/data_0835DCB0.bin"
	.global gUnk_02025234
gUnk_02025234:
	.incbin "build/assets/unknown/data_0835DCB4.bin"
	.global gUnk_020269C0
gUnk_020269C0:
	.incbin "build/assets/unknown/data_0835F440.bin"
	.global gUnk_020269C4
gUnk_020269C4:
	.incbin "build/assets/unknown/data_0835F444.bin"
	.global gUnk_020269CC
gUnk_020269CC:
	.incbin "build/assets/unknown/data_0835F44C.bin"
	.global gUnk_020269FC
gUnk_020269FC:
	.incbin "build/assets/unknown/data_0835F47C.bin"
	.global gUnk_02026A3C
gUnk_02026A3C:
	.incbin "build/assets/unknown/data_0835F4BC.bin"
	.global gUnk_02026A64
gUnk_02026A64:
	.incbin "build/assets/unknown/data_0835F4E4.bin"
	.global gUnk_02026A84
gUnk_02026A84:
	.incbin "build/assets/unknown/data_0835F504.bin"
	.global gUnk_02026DC4
gUnk_02026DC4:
	.incbin "build/assets/unknown/data_0835F844.bin"
	.global gUnk_02026DDC
gUnk_02026DDC:
	.incbin "build/assets/unknown/data_0835F85C.bin"
	.global gUnk_02026DF4
gUnk_02026DF4:
	.incbin "build/assets/unknown/data_0835F874.bin"
	.global gUnk_02026E14
gUnk_02026E14:
	.incbin "build/assets/unknown/data_0835F894.bin"
	.global gUnk_02026E18
gUnk_02026E18:
	.incbin "build/assets/unknown/data_0835F898.bin"
	.global gUnk_02026E1C
gUnk_02026E1C:
	.incbin "build/assets/unknown/data_0835F89C.bin"
	.global gUnk_02026E20
gUnk_02026E20:
	.incbin "build/assets/unknown/data_0835F8A0.bin"
	.global gUnk_0202708C
gUnk_0202708C:
	.incbin "build/assets/unknown/data_0835FB0C.bin"
	.global gUnk_020270C6
gUnk_020270C6:
	.incbin "build/assets/unknown/data_0835FB46.bin"
	.global gUnk_020270D0
gUnk_020270D0:
	.incbin "build/assets/unknown/data_0835FB50.bin"
	.global gUnk_0202713E
gUnk_0202713E:
	.incbin "build/assets/unknown/data_0835FBBE.bin"
	.global gUnk_0202714A
gUnk_0202714A:
	.incbin "build/assets/unknown/data_0835FBCA.bin"
	.global gUnk_02027154
gUnk_02027154:
	.incbin "build/assets/unknown/data_0835FBD4.bin"
	.global gUnk_02027500
gUnk_02027500:
	.incbin "build/assets/unknown/data_0835FF80.bin"
	.global gUnk_02027578
gUnk_02027578:
	.incbin "build/assets/unknown/data_0835FFF8.bin"
	.incbin "build/assets/unknown/data_08360000.bin"
	.global gUnk_020275F0
gUnk_020275F0:
	.incbin "build/assets/unknown/data_08360070.bin"
	.global gUnk_02027680
gUnk_02027680:
	.incbin "build/assets/unknown/data_08360100.bin"
	.global gUnk_02027690
gUnk_02027690:
	.incbin "build/assets/unknown/data_08360110.bin"
	.global gUnk_020276A0
gUnk_020276A0:
	.incbin "build/assets/unknown/data_08360120.bin"
	.global gUnk_020276AC
gUnk_020276AC:
	.incbin "build/assets/unknown/data_0836012C.bin"
	.incbin "build/assets/unknown/data_0836019C.bin"
	.global gUnk_0202772C
gUnk_0202772C:
	.incbin "build/assets/unknown/data_083601AC.bin"
	.global gUnk_0202773C
gUnk_0202773C:
	.incbin "build/assets/unknown/data_083601BC.bin"
	.global gUnk_020277B4
gUnk_020277B4:
	.incbin "build/assets/unknown/data_08360234.bin"
	.global gUnk_020277C4
gUnk_020277C4:
	.incbin "build/assets/unknown/data_08360244.bin"
	.global gUnk_020277D4
gUnk_020277D4:
	.incbin "build/assets/unknown/data_08360254.bin"
	.global gUnk_020277F4
gUnk_020277F4:
	.incbin "build/assets/unknown/data_08360274.bin"
	.global gUnk_02027800
gUnk_02027800:
	.incbin "build/assets/unknown/data_08360280.bin"
	.global gUnk_02027804
gUnk_02027804:
	.incbin "build/assets/unknown/data_08360284.bin"
	.global gUnk_02027808
gUnk_02027808:
	.incbin "build/assets/unknown/data_08360288.bin"
	.global gUnk_0202780C
gUnk_0202780C:
	.incbin "build/assets/unknown/data_0836028C.bin"
	.incbin "build/assets/unknown/data_08360860.bin"
	.incbin "build/assets/unknown/data_08360888.bin"
	.incbin "build/assets/unknown/data_083608F8.bin"
	.incbin "build/assets/unknown/data_08360C2C.bin"
	.incbin "build/assets/unknown/data_08361780.bin"
	.global gUnk_0202AED4
gUnk_0202AED4:
	.incbin "build/assets/unknown/data_08363954.bin"
	.global gUnk_0202AF08
gUnk_0202AF08:
	.incbin "build/assets/unknown/data_08363988.bin"
	.global gUnk_0202AF44
gUnk_0202AF44:
	.incbin "build/assets/unknown/data_083639C4.bin"
	.global gUnk_0202B078
gUnk_0202B078:
	.incbin "build/assets/unknown/data_08363AF8.bin"
	.global gUnk_0202B089
gUnk_0202B089:
	.incbin "build/assets/unknown/data_08363B09.bin"
	.global gUnk_0202B370
gUnk_0202B370:
	.incbin "build/assets/unknown/data_08363DF0.bin"
