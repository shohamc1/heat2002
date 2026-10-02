@ Generated with Luvdis v0.9.0
@ Both builds preprocess this file (preproc inlines the .include files,
@ cpp resolves the switch below). The GBA keeps the exact luvdis layout;
@ the hosted build switches to a writable data section, because its mPtr
@ pointer fields carry relocations the host linker must be able to write.
	.include "asm/macros/portable.inc"
#if PLATFORM_GBA
.syntax unified
.text
#else
mSectionData
#endif
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
#if PLATFORM_GBA
	.thumb
#endif
	.global gUnk_0807CE30
gUnk_0807CE30:
	cSym gUnk_0807CE30
	.incbin "build/assets/tracks/hooley_downs/bg3Map.bin"
	.global gUnk_0807EDEC
gUnk_0807EDEC:
	cSym gUnk_0807EDEC
	.incbin "build/assets/tracks/hooley_downs/bg3Metatiles.bin"
	.global gUnk_08086D6C
gUnk_08086D6C:
	cSym gUnk_08086D6C
	.incbin "build/assets/tracks/hooley_downs/bg3Tiles.bin"
	.global gUnk_0808A98C
gUnk_0808A98C:
	cSym gUnk_0808A98C
	.incbin "build/assets/tracks/hooley_downs/palette.bin"
	.global gUnk_0808AB8C
gUnk_0808AB8C:
	cSym gUnk_0808AB8C
	.incbin "build/assets/tracks/hooley_downs/bg2Map.bin"
	.global gUnk_0808C638
gUnk_0808C638:
	cSym gUnk_0808C638
	.incbin "build/assets/tracks/hooley_downs/bg2Metatiles.bin"
	.global gUnk_080954F8
gUnk_080954F8:
	cSym gUnk_080954F8
	.incbin "build/assets/tracks/hooley_downs/bg2Tiles.bin"
	.global gUnk_0809C718
gUnk_0809C718:
	cSym gUnk_0809C718
	.incbin "build/assets/tracks/darlington_raceway/palette.bin"
	.global gUnk_0809C918
gUnk_0809C918:
	cSym gUnk_0809C918
	.incbin "build/assets/tracks/darlington_raceway/bg3Map.bin"
	.global gUnk_0809D954
gUnk_0809D954:
	cSym gUnk_0809D954
	.incbin "build/assets/tracks/darlington_raceway/bg3Metatiles.bin"
	.global gUnk_080A6C74
gUnk_080A6C74:
	cSym gUnk_080A6C74
	.incbin "build/assets/tracks/darlington_raceway/bg3Tiles.bin"
	.global gUnk_080AAD54
gUnk_080AAD54:
	cSym gUnk_080AAD54
	.incbin "build/assets/tracks/darlington_raceway/bg2Map.bin"
	.global gUnk_080ABC14
gUnk_080ABC14:
	cSym gUnk_080ABC14
	.incbin "build/assets/tracks/darlington_raceway/bg2Metatiles.bin"
	.global gUnk_080B1434
gUnk_080B1434:
	cSym gUnk_080B1434
	.incbin "build/assets/tracks/darlington_raceway/bg2Tiles.bin"
	.global gUnk_080B9234
gUnk_080B9234:
	cSym gUnk_080B9234
	.incbin "build/assets/tracks/green_valley/palette.bin"
	.global gUnk_080B9434
gUnk_080B9434:
	cSym gUnk_080B9434
	.incbin "build/assets/tracks/green_valley/bg3Map.bin"
	.global gUnk_080BAEF0
gUnk_080BAEF0:
	cSym gUnk_080BAEF0
	.incbin "build/assets/tracks/green_valley/bg3Metatiles.bin"
	.global gUnk_080CA7F0
gUnk_080CA7F0:
	cSym gUnk_080CA7F0
	.incbin "build/assets/tracks/green_valley/bg3Tiles.bin"
	.global gUnk_080CE6D0
gUnk_080CE6D0:
	cSym gUnk_080CE6D0
	.incbin "build/assets/tracks/green_valley/bg2Map.bin"
	.global gUnk_080D1EF0
gUnk_080D1EF0:
	cSym gUnk_080D1EF0
	.incbin "build/assets/tracks/green_valley/bg2Metatiles.bin"
	.global gUnk_080EC8B0
gUnk_080EC8B0:
	cSym gUnk_080EC8B0
	.incbin "build/assets/tracks/green_valley/bg2Tiles.bin"
	.global gUnk_080F3FD0
gUnk_080F3FD0:
	cSym gUnk_080F3FD0
	.incbin "build/assets/tracks/michigan_international_speedway/palette.bin"
	.global gUnk_080F41D0
gUnk_080F41D0:
	cSym gUnk_080F41D0
	.incbin "build/assets/tracks/michigan_international_speedway/bg3Map.bin"
	.global gUnk_080F613C
gUnk_080F613C:
	cSym gUnk_080F613C
	.incbin "build/assets/tracks/michigan_international_speedway/bg3Metatiles.bin"
	.global gUnk_0810721C
gUnk_0810721C:
	cSym gUnk_0810721C
	.incbin "build/assets/tracks/michigan_international_speedway/bg3Tiles.bin"
	.global gUnk_0810B27C
gUnk_0810B27C:
	cSym gUnk_0810B27C
	.incbin "build/assets/tracks/michigan_international_speedway/bg2Map.bin"
	.global gUnk_0810E2B0
gUnk_0810E2B0:
	cSym gUnk_0810E2B0
	.incbin "build/assets/tracks/michigan_international_speedway/bg2Metatiles.bin"
	.global gUnk_08125DD0
gUnk_08125DD0:
	cSym gUnk_08125DD0
	.incbin "build/assets/tracks/michigan_international_speedway/bg2Tiles.bin"
	.global gUnk_0812DF70
gUnk_0812DF70:
	cSym gUnk_0812DF70
	.incbin "build/assets/tracks/great_canyon/bg3Map.bin"
	.global gUnk_0812FE5C
gUnk_0812FE5C:
	cSym gUnk_0812FE5C
	.incbin "build/assets/tracks/great_canyon/bg3Metatiles.bin"
	.global gUnk_0813EDFC
gUnk_0813EDFC:
	cSym gUnk_0813EDFC
	.incbin "build/assets/tracks/great_canyon/bg3Tiles.bin"
	.global gUnk_081428DC
gUnk_081428DC:
	cSym gUnk_081428DC
	.incbin "build/assets/tracks/great_canyon/palette.bin"
	.global gUnk_08142ADC
gUnk_08142ADC:
	cSym gUnk_08142ADC
	.incbin "build/assets/tracks/great_canyon/bg2Map.bin"
	.global gUnk_08145D84
gUnk_08145D84:
	cSym gUnk_08145D84
	.incbin "build/assets/tracks/great_canyon/bg2Metatiles.bin"
	.global gUnk_0815E024
gUnk_0815E024:
	cSym gUnk_0815E024
	.incbin "build/assets/tracks/great_canyon/bg2Tiles.bin"
	.global gUnk_08166024
gUnk_08166024:
	cSym gUnk_08166024
	.incbin "build/assets/tracks/fuji_port/palette.bin"
	.global gUnk_08166224
gUnk_08166224:
	cSym gUnk_08166224
	.incbin "build/assets/tracks/fuji_port/bg3Map.bin"
	.global gUnk_081698F0
gUnk_081698F0:
	cSym gUnk_081698F0
	.incbin "build/assets/tracks/fuji_port/bg3Metatiles.bin"
	.global gUnk_08178110
gUnk_08178110:
	cSym gUnk_08178110
	.incbin "build/assets/tracks/fuji_port/bg3Tiles.bin"
	.global gUnk_0817C190
gUnk_0817C190:
	cSym gUnk_0817C190
	.incbin "build/assets/tracks/fuji_port/bg2Map.bin"
	.global gUnk_0817E918
gUnk_0817E918:
	cSym gUnk_0817E918
	.incbin "build/assets/tracks/fuji_port/bg2Metatiles.bin"
	.global gUnk_0818F958
gUnk_0818F958:
	cSym gUnk_0818F958
	.incbin "build/assets/tracks/fuji_port/bg2Tiles.bin"
	.global gUnk_08197518
gUnk_08197518:
	cSym gUnk_08197518
	.incbin "build/assets/tracks/crawfish_raceway/palette.bin"
	.global gUnk_08197718
gUnk_08197718:
	cSym gUnk_08197718
	.incbin "build/assets/tracks/crawfish_raceway/bg3Map.bin"
	.global gUnk_08198DC8
gUnk_08198DC8:
	cSym gUnk_08198DC8
	.incbin "build/assets/tracks/crawfish_raceway/bg3Metatiles.bin"
	.global gUnk_081A34C8
gUnk_081A34C8:
	cSym gUnk_081A34C8
	.incbin "build/assets/tracks/crawfish_raceway/bg3Tiles.bin"
	.global gUnk_081A4B88
gUnk_081A4B88:
	cSym gUnk_081A4B88
	.incbin "build/assets/tracks/crawfish_raceway/bg2Map.bin"
	.global gUnk_081A7164
gUnk_081A7164:
	cSym gUnk_081A7164
	.incbin "build/assets/tracks/crawfish_raceway/bg2Metatiles.bin"
	.global gUnk_081B4F24
gUnk_081B4F24:
	cSym gUnk_081B4F24
	.incbin "build/assets/tracks/crawfish_raceway/bg2Tiles.bin"
	.global gUnk_081BCEE4
gUnk_081BCEE4:
	cSym gUnk_081BCEE4
	.incbin "build/assets/tracks/purley_park/bg3Map.bin"
	.global gUnk_081C317C
gUnk_081C317C:
	cSym gUnk_081C317C
	.incbin "build/assets/tracks/purley_park/bg3Metatiles.bin"
	.global gUnk_081C515C
gUnk_081C515C:
	cSym gUnk_081C515C
	.incbin "build/assets/tracks/purley_park/bg3Tiles.bin"
	.global gUnk_081C6ADC
gUnk_081C6ADC:
	cSym gUnk_081C6ADC
	.incbin "build/assets/tracks/purley_park/palette.bin"
	.global gUnk_081C6CDC
gUnk_081C6CDC:
	cSym gUnk_081C6CDC
	.incbin "build/assets/tracks/purley_park/bg2Map.bin"
	.global gUnk_081C7EA8
gUnk_081C7EA8:
	cSym gUnk_081C7EA8
	.incbin "build/assets/tracks/purley_park/bg2Metatiles.bin"
	.global gUnk_081C9BC8
gUnk_081C9BC8:
	cSym gUnk_081C9BC8
	.incbin "build/assets/tracks/purley_park/bg2Tiles.bin"
	.global gUnk_081CB608
gUnk_081CB608:
	cSym gUnk_081CB608
	.incbin "build/assets/tracks/kansas_speedway/palette.bin"
	.global gUnk_081CB808
gUnk_081CB808:
	cSym gUnk_081CB808
	.incbin "build/assets/tracks/kansas_speedway/bg3Map.bin"
	.global gUnk_081CDE68
gUnk_081CDE68:
	cSym gUnk_081CDE68
	.incbin "build/assets/tracks/kansas_speedway/bg3Metatiles.bin"
	.global gUnk_081DECC8
gUnk_081DECC8:
	cSym gUnk_081DECC8
	.incbin "build/assets/tracks/kansas_speedway/bg3Tiles.bin"
	.global gUnk_081E2188
gUnk_081E2188:
	cSym gUnk_081E2188
	.incbin "build/assets/tracks/kansas_speedway/bg2Map.bin"
	.global gUnk_081E4A64
gUnk_081E4A64:
	cSym gUnk_081E4A64
	.incbin "build/assets/tracks/kansas_speedway/bg2Metatiles.bin"
	.global gUnk_081F8744
gUnk_081F8744:
	cSym gUnk_081F8744
	.incbin "build/assets/tracks/kansas_speedway/bg2Tiles.bin"
	.global gUnk_08200444
gUnk_08200444:
	cSym gUnk_08200444
	.incbin "build/assets/tracks/asphalt_city/palette.bin"
	.global gUnk_08200644
gUnk_08200644:
	cSym gUnk_08200644
	.incbin "build/assets/tracks/asphalt_city/bg3Map.bin"
	.global gUnk_08203A14
gUnk_08203A14:
	cSym gUnk_08203A14
	.incbin "build/assets/tracks/asphalt_city/bg3Metatiles.bin"
	.global gUnk_0820E234
gUnk_0820E234:
	cSym gUnk_0820E234
	.incbin "build/assets/tracks/asphalt_city/bg3Tiles.bin"
	.global gUnk_082121D4
gUnk_082121D4:
	cSym gUnk_082121D4
	.incbin "build/assets/tracks/asphalt_city/bg2Map.bin"
	.global gUnk_08215980
gUnk_08215980:
	cSym gUnk_08215980
	.incbin "build/assets/tracks/asphalt_city/bg2Metatiles.bin"
	.global gUnk_08228880
gUnk_08228880:
	cSym gUnk_08228880
	.incbin "build/assets/tracks/asphalt_city/bg2Tiles.bin"
	.global gUnk_082307A0
gUnk_082307A0:
	cSym gUnk_082307A0
	.incbin "build/assets/tracks/phoenix_international_raceway/bg3Map.bin"
	.global gUnk_08231DC8
gUnk_08231DC8:
	cSym gUnk_08231DC8
	.incbin "build/assets/tracks/phoenix_international_raceway/bg3Metatiles.bin"
	.global gUnk_0823F128
gUnk_0823F128:
	cSym gUnk_0823F128
	.incbin "build/assets/tracks/phoenix_international_raceway/bg3Tiles.bin"
	.global gUnk_08242CA8
gUnk_08242CA8:
	cSym gUnk_08242CA8
	.incbin "build/assets/tracks/phoenix_international_raceway/palette.bin"
	.global gUnk_08242EA8
gUnk_08242EA8:
	cSym gUnk_08242EA8
	.incbin "build/assets/tracks/phoenix_international_raceway/bg2Map.bin"
	.global gUnk_08244C24
gUnk_08244C24:
	cSym gUnk_08244C24
	.incbin "build/assets/tracks/phoenix_international_raceway/bg2Metatiles.bin"
	.global gUnk_08253884
gUnk_08253884:
	cSym gUnk_08253884
	.incbin "build/assets/tracks/phoenix_international_raceway/bg2Tiles.bin"
	.global gUnk_0825B764
gUnk_0825B764:
	cSym gUnk_0825B764
	.incbin "build/assets/tracks/infogrames_super_speedway/palette.bin"
	.global gUnk_0825B964
gUnk_0825B964:
	cSym gUnk_0825B964
	.incbin "build/assets/tracks/infogrames_super_speedway/bg3Map.bin"
	.global gUnk_0825D510
gUnk_0825D510:
	cSym gUnk_0825D510
	.incbin "build/assets/tracks/infogrames_super_speedway/bg3Metatiles.bin"
	.global gUnk_082683F0
gUnk_082683F0:
	cSym gUnk_082683F0
	.incbin "build/assets/tracks/infogrames_super_speedway/bg3Tiles.bin"
	.global gUnk_0826BC70
gUnk_0826BC70:
	cSym gUnk_0826BC70
	.incbin "build/assets/tracks/infogrames_super_speedway/bg2Map.bin"
	.global gUnk_0826DE48
gUnk_0826DE48:
	cSym gUnk_0826DE48
	.incbin "build/assets/tracks/infogrames_super_speedway/bg2Metatiles.bin"
	.global gUnk_0827AAA8
gUnk_0827AAA8:
	cSym gUnk_0827AAA8
	.incbin "build/assets/tracks/infogrames_super_speedway/bg2Tiles.bin"
	.global gUnk_08282468
gUnk_08282468:
	cSym gUnk_08282468
	.incbin "build/assets/tracks/hooley_downs/cellMap.bin"
	.global gUnk_08283E0C
gUnk_08283E0C:
	cSym gUnk_08283E0C
	.incbin "build/assets/tracks/hooley_downs/surfaceTable.bin"
	.global gUnk_0828519C
gUnk_0828519C:
	cSym gUnk_0828519C
	.incbin "build/assets/tracks/darlington_raceway/cellMap.bin"
	.global gUnk_082855D8
gUnk_082855D8:
	cSym gUnk_082855D8
	.incbin "build/assets/tracks/darlington_raceway/surfaceTable.bin"
	.global gUnk_08285968
gUnk_08285968:
	cSym gUnk_08285968
	.incbin "build/assets/tracks/green_valley/cellMap.bin"
	.global gUnk_082876D4
gUnk_082876D4:
	cSym gUnk_082876D4
	.incbin "build/assets/tracks/green_valley/surfaceTable.bin"
	.global gUnk_08288BD4
gUnk_08288BD4:
	cSym gUnk_08288BD4
	.incbin "build/assets/tracks/michigan_international_speedway/cellMap.bin"
	.global gUnk_0828AA90
gUnk_0828AA90:
	cSym gUnk_0828AA90
	.incbin "build/assets/tracks/michigan_international_speedway/surfaceTable.bin"
	.global gUnk_0828BA60
gUnk_0828BA60:
	cSym gUnk_0828BA60
	.incbin "build/assets/tracks/great_canyon/cellMap.bin"
	.global gUnk_0828DD4C
gUnk_0828DD4C:
	cSym gUnk_0828DD4C
	.incbin "build/assets/tracks/great_canyon/surfaceTable.bin"
	.global gUnk_0828F52C
gUnk_0828F52C:
	cSym gUnk_0828F52C
	.incbin "build/assets/tracks/fuji_port/cellMap.bin"
	.global gUnk_082914A0
gUnk_082914A0:
	cSym gUnk_082914A0
	.incbin "build/assets/tracks/fuji_port/surfaceTable.bin"
	.global gUnk_08292650
gUnk_08292650:
	cSym gUnk_08292650
	.incbin "build/assets/tracks/crawfish_raceway/cellMap.bin"
	.global gUnk_08293548
gUnk_08293548:
	cSym gUnk_08293548
	.incbin "build/assets/tracks/crawfish_raceway/surfaceTable.bin"
	.global gUnk_082939A8
gUnk_082939A8:
	cSym gUnk_082939A8
	.incbin "build/assets/tracks/kansas_speedway/cellMap.bin"
	.global gUnk_08295820
gUnk_08295820:
	cSym gUnk_08295820
	.incbin "build/assets/tracks/kansas_speedway/surfaceTable.bin"
	.global gUnk_08296A30
gUnk_08296A30:
	cSym gUnk_08296A30
	.incbin "build/assets/tracks/asphalt_city/cellMap.bin"
	.global gUnk_08298BE4
gUnk_08298BE4:
	cSym gUnk_08298BE4
	.incbin "build/assets/tracks/asphalt_city/surfaceTable.bin"
	.global gUnk_08299AF4
gUnk_08299AF4:
	cSym gUnk_08299AF4
	.incbin "build/assets/tracks/phoenix_international_raceway/cellMap.bin"
	.global gUnk_0829B024
gUnk_0829B024:
	cSym gUnk_0829B024
	.incbin "build/assets/tracks/phoenix_international_raceway/surfaceTable.bin"
	.global gUnk_0829C7B4
gUnk_0829C7B4:
	cSym gUnk_0829C7B4
	.incbin "build/assets/tracks/infogrames_super_speedway/cellMap.bin"
	.global gUnk_0829DBB0
gUnk_0829DBB0:
	cSym gUnk_0829DBB0
	.incbin "build/assets/tracks/infogrames_super_speedway/surfaceTable.bin"
