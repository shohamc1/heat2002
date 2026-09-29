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
	.incbin "build/assets/graphics/palettes/driver_number.pal.bin"
	.incbin "build/assets/graphics/rl_0832975C.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08329890.bin"
	.space 3
	.incbin "build/assets/graphics/rl_083299BC.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08329AF4.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08329C28.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08329D4C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08329E6C.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08329F78.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832A084.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832A198.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832A2AC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832A3BC.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832A4C8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832A5D4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832A6E0.bin"
	.incbin "build/assets/graphics/rl_0832A7E8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832A8F0.bin"
	.incbin "build/assets/graphics/rl_0832A9F8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832AAFC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832AC04.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832AD18.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832AE30.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832AF40.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832B050.bin"
	.incbin "build/assets/graphics/rl_0832B168.bin"
	.incbin "build/assets/graphics/rl_0832B27C.bin"
	.incbin "build/assets/graphics/rl_0832B390.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832B4A0.bin"
	.incbin "build/assets/graphics/rl_0832B5A4.bin"
	.incbin "build/assets/graphics/rl_0832B6A4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832B7A4.bin"
	.incbin "build/assets/graphics/rl_0832B89C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832B994.bin"
	.space 2
	.incbin "build/assets/graphics/palettes/pal_0832BA88.pal.bin"
	.incbin "build/assets/graphics/rl_0832BAA8.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832BB04.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832BB50.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BBA0.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832BBF4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BC58.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BCE0.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BD74.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BE08.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832BE9C.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832BF30.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832BFC4.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832C054.bin"
	.incbin "build/assets/graphics/rl_0832C0E0.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C168.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C1EC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832C270.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832C2F0.bin"
	.incbin "build/assets/graphics/rl_0832C36C.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832C3EC.bin"
	.incbin "build/assets/graphics/rl_0832C464.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832C4DC.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C550.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C5BC.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832C628.bin"
	.incbin "build/assets/graphics/rl_0832C690.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C6F0.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C734.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832C778.bin"
	.space 3
	.incbin "build/assets/graphics/rl_0832C7BC.bin"
	.incbin "build/assets/graphics/rl_0832C7FC.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0832C83C.bin"
	.space 2
	.incbin "build/assets/graphics/rl_0832C890.bin"
	.space 2
	.incbin "build/assets/graphics/palettes/pal_0832C8D4.pal.bin"
	.incbin "build/assets/graphics/palettes/pal_08330D38.pal.bin"
	.incbin "build/assets/graphics/rl_08331380.bin"
	.space 2
	.incbin "build/assets/graphics/rl_083313A0.bin"
	.space 1
	.incbin "build/assets/graphics/rl_083313C8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_083313F8.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331438.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331480.bin"
	.space 2
	.incbin "build/assets/graphics/rl_083314CC.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331520.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08331574.bin"
	.space 2
	.incbin "build/assets/graphics/rl_083315D0.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331638.bin"
	.space 1
	.incbin "build/assets/graphics/rl_083316A8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0833171C.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331798.bin"
	.space 1
	.incbin "build/assets/graphics/rl_0833181C.bin"
	.space 1
	.incbin "build/assets/graphics/rl_083318A0.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331924.bin"
	.space 2
	.incbin "build/assets/graphics/rl_083319A8.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08331A28.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331AA8.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331B20.bin"
	.incbin "build/assets/graphics/rl_08331B94.bin"
	.incbin "build/assets/graphics/rl_08331C08.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331C7C.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331CEC.bin"
	.incbin "build/assets/graphics/rl_08331D54.bin"
	.space 3
	.incbin "build/assets/graphics/rl_08331DBC.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331E1C.bin"
	.space 1
	.incbin "build/assets/graphics/rl_08331E74.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08331EC4.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08331F0C.bin"
	.space 2
	.incbin "build/assets/graphics/rl_08331F4C.bin"
	.space 1
	.global gUnk_0201F370
gUnk_0201F370:
	.incbin "build/assets/graphics/palettes/skid_smoke.pal.bin"
	.global gUnk_0201F390
gUnk_0201F390:
	.incbin "build/assets/graphics/palettes/font.pal.bin"
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
	.incbin "build/assets/graphics/tiles/text_layer.tiles.bin", 0, 4524
	.incbin "build/assets/graphics/tiles/text_layer.tiles.bin", 4524, 1684
	.global gUnk_02021394
gUnk_02021394:
	.incbin "build/assets/graphics/palettes/race_hud_bg.pal.bin"
	.global gUnk_02021594
gUnk_02021594:
	.incbin "build/assets/unknown/data_0835A014.bin"
	.global gModule_BigDigitGlyphs
gModule_BigDigitGlyphs:
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
	.incbin "build/assets/graphics/tiles/race_hud_bg.tiles.bin"
	.incbin "build/assets/graphics/rl_083378A0.bin"
	.incbin "build/assets/graphics/rl_08337920.bin"
	.incbin "build/assets/graphics/rl_083379A0.bin"
	.incbin "build/assets/graphics/rl_08337A20.bin"
	.incbin "build/assets/graphics/rl_08337AA0.bin"
	.incbin "build/assets/graphics/rl_08337B20.bin"
	.incbin "build/assets/graphics/rl_08337BA0.bin"
	.global gUnk_020243E8
gUnk_020243E8:
	.incbin "build/assets/graphics/palettes/link_marker.pal.bin"
	.incbin "build/assets/graphics/rl_08337C40.bin"
	.incbin "build/assets/graphics/rl_08337CC0.bin"
	.incbin "build/assets/graphics/rl_08337D40.bin"
	.incbin "build/assets/graphics/rl_08337DC0.bin"
	.incbin "build/assets/graphics/rl_08337E40.bin"
	.incbin "build/assets/graphics/rl_08337EC0.bin"
	.incbin "build/assets/graphics/rl_08337F40.bin"
	.incbin "build/assets/graphics/palettes/pal_08337FC0.pal.bin"
	.incbin "build/assets/graphics/rl_08337FE0.bin"
	.incbin "build/assets/graphics/rl_08338060.bin"
	.incbin "build/assets/graphics/rl_083380E0.bin"
	.incbin "build/assets/graphics/rl_08338160.bin"
	.incbin "build/assets/graphics/rl_083381E0.bin"
	.incbin "build/assets/graphics/rl_08338260.bin"
	.incbin "build/assets/graphics/rl_083382E0.bin"
	.incbin "build/assets/graphics/palettes/pal_08338360.pal.bin"
	.incbin "build/assets/graphics/rl_08338380.bin"
	.incbin "build/assets/graphics/rl_08338400.bin"
	.incbin "build/assets/graphics/rl_08338480.bin"
	.incbin "build/assets/graphics/rl_08338500.bin"
	.incbin "build/assets/graphics/rl_08338580.bin"
	.incbin "build/assets/graphics/rl_08338600.bin"
	.incbin "build/assets/graphics/rl_08338680.bin"
	.incbin "build/assets/graphics/palettes/pal_08338700.pal.bin"
	.global gUnk_02024EE8
gUnk_02024EE8:
	.incbin "build/assets/graphics/rl_08338720.bin"
	.global gUnk_02024F50
gUnk_02024F50:
	.incbin "build/assets/graphics/palettes/track_select_arrow.pal.bin"
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
	.global gModule_TrackSegTables
gModule_TrackSegTables:
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
	.global gModule_TrackStartGrids
gModule_TrackStartGrids:
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
	.global gModule_TrackWallTables
gModule_TrackWallTables:
	.incbin "build/assets/unknown/data_08363954.bin"
	.global gModule_CarCollisionNormals
gModule_CarCollisionNormals:
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

