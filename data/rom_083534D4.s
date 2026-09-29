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
	.global gModule_TextGlyphTileIndices
gModule_TextGlyphTileIndices:
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
	.global gModule_FontTileEntries
gModule_FontTileEntries:
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
	.global gModule_LocalizedText
gModule_LocalizedText:
	.incbin "build/assets/unknown/data_0835DB70.bin"
	.global gUnk_02025190
gUnk_02025190:
	.incbin "build/assets/unknown/data_0835DC10.bin"
	.global gUnk_020251A4
gUnk_020251A4:
	.incbin "build/assets/unknown/data_0835DC24.bin"
	.global gModule_TextLayerMapPtr
gModule_TextLayerMapPtr:
	.incbin "build/assets/unknown/data_0835DC38.bin"
	.global gModule_TrackData
gModule_TrackData:
	.incbin "build/assets/unknown/data_0835DC3C.bin"
	.global gModule_02025220
gModule_02025220:
	.incbin "build/assets/unknown/data_0835DCA0.bin"
	.global gModule_0202522C
gModule_0202522C:
	.incbin "build/assets/unknown/data_0835DCAC.bin"
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
	.global gModule_TireGripDefaults
gModule_TireGripDefaults:
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
	.global gModule_DriverGearPowerTables
gModule_DriverGearPowerTables:
	.incbin "build/assets/unknown/data_0835FF80.bin"
	.global gModule_DriverGearRatioTables
gModule_DriverGearRatioTables:
	.incbin "build/assets/unknown/data_0835FFF8.bin"
	.incbin "build/assets/unknown/data_08360000.bin"
	.global gModule_DriverRpmPerSpeedTables
gModule_DriverRpmPerSpeedTables:
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

