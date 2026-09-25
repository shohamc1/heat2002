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
	.global gUnk_0807CE30
gUnk_0807CE30:
	.incbin "build/assets/unknown/data_0807CE30.bin"
	.global gUnk_0807EDEC
gUnk_0807EDEC:
	.incbin "build/assets/unknown/data_0807EDEC.bin"
	.incbin "build/assets/unknown/data_0807FF08.bin"
	.incbin "build/assets/unknown/data_0807FF14.bin"
	.incbin "build/assets/unknown/data_0807FF2C.bin"
	.incbin "build/assets/unknown/data_0807FF38.bin"
	.incbin "build/assets/unknown/data_08080000.bin"
	.incbin "build/assets/unknown/data_08080008.bin"
	.incbin "build/assets/unknown/data_08080010.bin"
	.incbin "build/assets/unknown/data_08080088.bin"
	.incbin "build/assets/unknown/data_080800B8.bin"
	.incbin "build/assets/unknown/data_08080408.bin"
	.incbin "build/assets/unknown/data_0808040C.bin"
	.incbin "build/assets/unknown/data_08080418.bin"
	.incbin "build/assets/unknown/data_08080470.bin"
	.incbin "build/assets/unknown/data_08080490.bin"
	.incbin "build/assets/unknown/data_080804A8.bin"
	.incbin "build/assets/unknown/data_080804B0.bin"
	.incbin "build/assets/unknown/data_080804C8.bin"
	.incbin "build/assets/unknown/data_080804D0.bin"
	.incbin "build/assets/unknown/data_080804E0.bin"
	.incbin "build/assets/unknown/data_080806B8.bin"
	.incbin "build/assets/unknown/data_08080700.bin"
	.incbin "build/assets/unknown/data_08080800.bin"
	.incbin "build/assets/unknown/data_08080808.bin"
	.incbin "build/assets/unknown/data_0808080C.bin"
	.incbin "build/assets/unknown/data_08080810.bin"
	.incbin "build/assets/unknown/data_0808081C.bin"
	.incbin "build/assets/unknown/data_08080888.bin"
	.incbin "build/assets/unknown/data_080808D8.bin"
	.incbin "build/assets/unknown/data_08082768.bin"
	.incbin "build/assets/unknown/data_08083128.bin"
	.incbin "build/assets/unknown/data_08084A60.bin"
	.incbin "build/assets/unknown/data_08084A80.bin"
	.incbin "build/assets/unknown/data_08084B00.bin"
	.incbin "build/assets/unknown/data_08084C00.bin"
	.incbin "build/assets/unknown/data_08084C60.bin"
	.incbin "build/assets/unknown/data_08084D08.bin"
	.incbin "build/assets/unknown/data_08084D60.bin"
	.incbin "build/assets/unknown/data_08084D80.bin"
	.incbin "build/assets/unknown/data_08084ED8.bin"
	.incbin "build/assets/unknown/data_08085C5C.bin"
	.global gUnk_08086D6C
gUnk_08086D6C:
	.incbin "build/assets/unknown/data_08086D6C.bin"
	.incbin "build/assets/unknown/data_080874F8.bin"
	.incbin "build/assets/unknown/data_08088D00.bin"
	.global gUnk_0808A98C
gUnk_0808A98C:
	.incbin "build/assets/unknown/data_0808A98C.bin"
	.global gUnk_0808AB8C
gUnk_0808AB8C:
	.incbin "build/assets/unknown/data_0808AB8C.bin"
	.global gUnk_0808C638
gUnk_0808C638:
	.incbin "build/assets/unknown/data_0808C638.bin"
	.incbin "build/assets/unknown/data_0808D8D8.bin"
	.incbin "build/assets/unknown/data_0808EAEC.bin"
	.incbin "build/assets/unknown/data_0808FEF4.bin"
	.incbin "build/assets/unknown/data_08090000.bin"
	.incbin "build/assets/unknown/data_08090110.bin"
	.incbin "build/assets/unknown/data_08090408.bin"
	.incbin "build/assets/unknown/data_0809040C.bin"
	.incbin "build/assets/unknown/data_08090414.bin"
	.incbin "build/assets/unknown/data_08090808.bin"
	.incbin "build/assets/unknown/data_08090810.bin"
	.incbin "build/assets/unknown/data_08090818.bin"
	.incbin "build/assets/unknown/data_08090908.bin"
	.incbin "build/assets/unknown/data_080909CC.bin"
	.incbin "build/assets/unknown/data_08090C10.bin"
	.incbin "build/assets/unknown/data_08090C40.bin"
	.incbin "build/assets/unknown/data_08091000.bin"
	.global gUnk_080954F8
gUnk_080954F8:
	.incbin "build/assets/unknown/data_080954F8.bin"
	.incbin "build/assets/unknown/data_08098010.bin"
	.global gUnk_0809C718
gUnk_0809C718:
	.incbin "build/assets/unknown/data_0809C718.bin"
	.global gUnk_0809C918
gUnk_0809C918:
	.incbin "build/assets/unknown/data_0809C918.bin"
	.global gUnk_0809D954
gUnk_0809D954:
	.incbin "build/assets/unknown/data_0809D954.bin"
	.incbin "build/assets/unknown/data_080A0000.bin"
	.incbin "build/assets/unknown/data_080A0014.bin"
	.incbin "build/assets/unknown/data_080A031C.bin"
	.incbin "build/assets/unknown/data_080A040C.bin"
	.incbin "build/assets/unknown/data_080A0410.bin"
	.incbin "build/assets/unknown/data_080A0414.bin"
	.incbin "build/assets/unknown/data_080A041C.bin"
	.incbin "build/assets/unknown/data_080A0808.bin"
	.incbin "build/assets/unknown/data_080A0810.bin"
	.incbin "build/assets/unknown/data_080A0814.bin"
	.incbin "build/assets/unknown/data_080A081C.bin"
	.incbin "build/assets/unknown/data_080A0C08.bin"
	.incbin "build/assets/unknown/data_080A0CC0.bin"
	.incbin "build/assets/unknown/data_080A0D2C.bin"
	.incbin "build/assets/unknown/data_080A0D30.bin"
	.incbin "build/assets/unknown/data_080A0D40.bin"
	.incbin "build/assets/unknown/data_080A0D54.bin"
	.incbin "build/assets/unknown/data_080A0D80.bin"
	.incbin "build/assets/unknown/data_080A0DC0.bin"
	.incbin "build/assets/unknown/data_080A0DC8.bin"
	.incbin "build/assets/unknown/data_080A5C5C.bin"
	.incbin "build/assets/unknown/data_080A6118.bin"
	.global gUnk_080A6C74
gUnk_080A6C74:
	.incbin "build/assets/unknown/data_080A6C74.bin"
	.global gUnk_080AAD54
gUnk_080AAD54:
	.incbin "build/assets/unknown/data_080AAD54.bin"
	.global gUnk_080ABC14
gUnk_080ABC14:
	.incbin "build/assets/unknown/data_080ABC14.bin"
	.incbin "build/assets/unknown/data_080AED08.bin"
	.incbin "build/assets/unknown/data_080AFFFC.bin"
	.incbin "build/assets/unknown/data_080B00B4.bin"
	.incbin "build/assets/unknown/data_080B01CC.bin"
	.incbin "build/assets/unknown/data_080B0408.bin"
	.incbin "build/assets/unknown/data_080B040C.bin"
	.incbin "build/assets/unknown/data_080B0410.bin"
	.incbin "build/assets/unknown/data_080B0414.bin"
	.incbin "build/assets/unknown/data_080B0448.bin"
	.incbin "build/assets/unknown/data_080B0808.bin"
	.incbin "build/assets/unknown/data_080B080C.bin"
	.incbin "build/assets/unknown/data_080B0A0C.bin"
	.incbin "build/assets/unknown/data_080B0C10.bin"
	.global gUnk_080B1434
gUnk_080B1434:
	.incbin "build/assets/unknown/data_080B1434.bin"
	.global gUnk_080B9234
gUnk_080B9234:
	.incbin "build/assets/unknown/data_080B9234.bin"
	.global gUnk_080B9434
gUnk_080B9434:
	.incbin "build/assets/unknown/data_080B9434.bin"
	.global gUnk_080BAEF0
gUnk_080BAEF0:
	.incbin "build/assets/unknown/data_080BAEF0.bin"
	.incbin "build/assets/graphics/rl_080C0000.bin"
	.incbin "build/assets/unknown/data_080C347D.bin"
	.global gUnk_080CA7F0
gUnk_080CA7F0:
	.incbin "build/assets/unknown/data_080CA7F0.bin"
	.global gUnk_080CE6D0
gUnk_080CE6D0:
	.incbin "build/assets/unknown/data_080CE6D0.bin"
	.incbin "build/assets/unknown/data_080D0008.bin"
	.incbin "build/assets/unknown/data_080D000C.bin"
	.incbin "build/assets/unknown/data_080D040C.bin"
	.incbin "build/assets/unknown/data_080D0800.bin"
	.incbin "build/assets/unknown/data_080D080C.bin"
	.incbin "build/assets/unknown/data_080D0814.bin"
	.incbin "build/assets/unknown/data_080D08FC.bin"
	.incbin "build/assets/unknown/data_080D0C08.bin"
	.incbin "build/assets/unknown/data_080D0C0C.bin"
	.incbin "build/assets/unknown/data_080D1218.bin"
	.incbin "build/assets/unknown/data_080D1C0C.bin"
	.global gUnk_080D1EF0
gUnk_080D1EF0:
	.incbin "build/assets/unknown/data_080D1EF0.bin"
	.incbin "build/assets/unknown/data_080E0000.bin"
	.incbin "build/assets/unknown/data_080E000C.bin"
	.incbin "build/assets/unknown/data_080E00FC.bin"
	.incbin "build/assets/unknown/data_080E01DC.bin"
	.incbin "build/assets/unknown/data_080E040C.bin"
	.incbin "build/assets/unknown/data_080E0410.bin"
	.incbin "build/assets/unknown/data_080E0428.bin"
	.incbin "build/assets/unknown/data_080E042C.bin"
	.incbin "build/assets/unknown/data_080E0434.bin"
	.incbin "build/assets/unknown/data_080E045C.bin"
	.incbin "build/assets/unknown/data_080E04B0.bin"
	.incbin "build/assets/unknown/data_080E0808.bin"
	.incbin "build/assets/unknown/data_080E080C.bin"
	.incbin "build/assets/unknown/data_080E0810.bin"
	.incbin "build/assets/unknown/data_080E0814.bin"
	.incbin "build/assets/unknown/data_080E0818.bin"
	.incbin "build/assets/unknown/data_080E0828.bin"
	.incbin "build/assets/unknown/data_080E082C.bin"
	.incbin "build/assets/unknown/data_080E085C.bin"
	.incbin "build/assets/unknown/data_080E090C.bin"
	.incbin "build/assets/unknown/data_080E0978.bin"
	.incbin "build/assets/unknown/data_080E0AFC.bin"
	.incbin "build/assets/unknown/data_080E0B04.bin"
	.incbin "build/assets/unknown/data_080E0B6C.bin"
	.incbin "build/assets/unknown/data_080E0C30.bin"
	.incbin "build/assets/unknown/data_080E0C34.bin"
	.incbin "build/assets/unknown/data_080E0CE0.bin"
	.incbin "build/assets/unknown/data_080E0D04.bin"
	.incbin "build/assets/unknown/data_080E0D0C.bin"
	.incbin "build/assets/unknown/data_080E0D1C.bin"
	.incbin "build/assets/unknown/data_080E0F08.bin"
	.incbin "build/assets/unknown/data_080E2CD0.bin"
	.global gUnk_080EC8B0
gUnk_080EC8B0:
	.incbin "build/assets/unknown/data_080EC8B0.bin"
	.incbin "build/assets/unknown/data_080EFAFC.bin"
	.incbin "build/assets/unknown/data_080F0000.bin"
	.incbin "build/assets/unknown/data_080F0014.bin"
	.incbin "build/assets/unknown/data_080F0408.bin"
	.incbin "build/assets/unknown/data_080F0808.bin"
	.incbin "build/assets/unknown/data_080F080C.bin"
	.incbin "build/assets/unknown/data_080F0810.bin"
	.incbin "build/assets/unknown/data_080F0814.bin"
	.incbin "build/assets/unknown/data_080F081C.bin"
	.incbin "build/assets/unknown/data_080F0C14.bin"
	.incbin "build/assets/unknown/data_080F0CD0.bin"
	.incbin "build/assets/unknown/data_080F0F08.bin"
	.incbin "build/assets/unknown/data_080F1000.bin"
	.global gUnk_080F3FD0
gUnk_080F3FD0:
	.incbin "build/assets/unknown/data_080F3FD0.bin"
	.global gUnk_080F41D0
gUnk_080F41D0:
	.incbin "build/assets/unknown/data_080F41D0.bin"
	.global gUnk_080F613C
gUnk_080F613C:
	.incbin "build/assets/unknown/data_080F613C.bin"
	.incbin "build/assets/unknown/data_080F6DF8.bin"
	.incbin "build/assets/unknown/data_080FF9EC.bin"
	.incbin "build/assets/unknown/data_08100000.bin"
	.incbin "build/assets/unknown/data_08100414.bin"
	.incbin "build/assets/unknown/data_08100808.bin"
	.incbin "build/assets/unknown/data_0810080C.bin"
	.incbin "build/assets/unknown/data_08100810.bin"
	.incbin "build/assets/unknown/data_08100814.bin"
	.incbin "build/assets/unknown/data_08100B0C.bin"
	.incbin "build/assets/unknown/data_08100C08.bin"
	.incbin "build/assets/unknown/data_08100DB8.bin"
	.incbin "build/assets/unknown/data_08101000.bin"
	.incbin "build/assets/unknown/data_08106418.bin"
	.global gUnk_0810721C
gUnk_0810721C:
	.incbin "build/assets/unknown/data_0810721C.bin"
	.global gUnk_0810B27C
gUnk_0810B27C:
	.incbin "build/assets/unknown/data_0810B27C.bin"
	.global gUnk_0810E2B0
gUnk_0810E2B0:
	.incbin "build/assets/unknown/data_0810E2B0.bin"
	.incbin "build/assets/unknown/data_08110004.bin"
	.incbin "build/assets/unknown/data_0811000C.bin"
	.incbin "build/assets/unknown/data_08110014.bin"
	.incbin "build/assets/unknown/data_0811012C.bin"
	.incbin "build/assets/unknown/data_081102F4.bin"
	.incbin "build/assets/unknown/data_08110408.bin"
	.incbin "build/assets/unknown/data_08110414.bin"
	.incbin "build/assets/unknown/data_08110470.bin"
	.incbin "build/assets/unknown/data_08110810.bin"
	.incbin "build/assets/unknown/data_08110814.bin"
	.incbin "build/assets/unknown/data_08110818.bin"
	.incbin "build/assets/unknown/data_0811081C.bin"
	.incbin "build/assets/unknown/data_08110880.bin"
	.incbin "build/assets/unknown/data_08110904.bin"
	.incbin "build/assets/unknown/data_08110968.bin"
	.incbin "build/assets/unknown/data_08110C20.bin"
	.incbin "build/assets/unknown/data_08111000.bin"
	.incbin "build/assets/unknown/data_081142E4.bin"
	.incbin "build/assets/unknown/data_0811E5D8.bin"
	.incbin "build/assets/unknown/data_08120000.bin"
	.incbin "build/assets/unknown/data_08120014.bin"
	.incbin "build/assets/unknown/data_0812048C.bin"
	.incbin "build/assets/unknown/data_081204AC.bin"
	.incbin "build/assets/unknown/data_08120810.bin"
	.incbin "build/assets/unknown/data_08120814.bin"
	.incbin "build/assets/unknown/data_08120818.bin"
	.incbin "build/assets/unknown/data_08120864.bin"
	.incbin "build/assets/unknown/data_08120894.bin"
	.incbin "build/assets/unknown/data_08120C10.bin"
	.incbin "build/assets/unknown/data_08120CB8.bin"
	.incbin "build/assets/unknown/data_08120E3C.bin"
	.incbin "build/assets/unknown/data_08121000.bin"
	.incbin "build/assets/unknown/data_08121326.bin"
	.incbin "build/assets/unknown/data_08122910.bin"
	.global gUnk_08125DD0
gUnk_08125DD0:
	.incbin "build/assets/unknown/data_08125DD0.bin"
	.global gUnk_0812DF70
gUnk_0812DF70:
	.incbin "build/assets/unknown/data_0812DF70.bin"
	.global gUnk_0812FE5C
gUnk_0812FE5C:
	.incbin "build/assets/unknown/data_0812FE5C.bin"
	.incbin "build/assets/unknown/data_08130014.bin"
	.incbin "build/assets/unknown/data_0813001C.bin"
	.incbin "build/assets/unknown/data_081300BC.bin"
	.incbin "build/assets/unknown/data_08130408.bin"
	.incbin "build/assets/unknown/data_08130410.bin"
	.incbin "build/assets/unknown/data_08130628.bin"
	.incbin "build/assets/unknown/data_08130808.bin"
	.incbin "build/assets/unknown/data_0813080C.bin"
	.incbin "build/assets/unknown/data_08130810.bin"
	.incbin "build/assets/unknown/data_08130814.bin"
	.incbin "build/assets/unknown/data_0813081C.bin"
	.incbin "build/assets/unknown/data_08130830.bin"
	.incbin "build/assets/unknown/data_0813085C.bin"
	.incbin "build/assets/unknown/data_0813096C.bin"
	.incbin "build/assets/unknown/data_08130D0C.bin"
	.incbin "build/assets/unknown/data_08132908.bin"
	.incbin "build/assets/unknown/data_08132D3C.bin"
	.global gUnk_0813EDFC
gUnk_0813EDFC:
	.incbin "build/assets/unknown/data_0813EDFC.bin"
	.incbin "build/assets/unknown/data_08140000.bin"
	.incbin "build/assets/unknown/data_08140014.bin"
	.incbin "build/assets/unknown/data_0814001C.bin"
	.incbin "build/assets/unknown/data_08140204.bin"
	.incbin "build/assets/unknown/data_0814040C.bin"
	.incbin "build/assets/unknown/data_08140414.bin"
	.incbin "build/assets/unknown/data_0814041C.bin"
	.incbin "build/assets/unknown/data_08140808.bin"
	.incbin "build/assets/unknown/data_08140810.bin"
	.incbin "build/assets/unknown/data_08140814.bin"
	.incbin "build/assets/unknown/data_081408C0.bin"
	.incbin "build/assets/unknown/data_08140C08.bin"
	.incbin "build/assets/unknown/data_08140C10.bin"
	.incbin "build/assets/unknown/data_08140D40.bin"
	.incbin "build/assets/unknown/data_08140F18.bin"
	.incbin "build/assets/unknown/data_08141000.bin"
	.global gUnk_081428DC
gUnk_081428DC:
	.incbin "build/assets/unknown/data_081428DC.bin"
	.global gUnk_08142ADC
gUnk_08142ADC:
	.incbin "build/assets/unknown/data_08142ADC.bin"
	.global gUnk_08145D84
gUnk_08145D84:
	.incbin "build/assets/unknown/data_08145D84.bin"
	.incbin "build/assets/unknown/data_08148070.bin"
	.incbin "build/assets/unknown/data_0814F9D8.bin"
	.incbin "build/assets/unknown/data_08150000.bin"
	.incbin "build/assets/unknown/data_0815005C.bin"
	.incbin "build/assets/unknown/data_081500FC.bin"
	.incbin "build/assets/unknown/data_08150414.bin"
	.incbin "build/assets/unknown/data_08150428.bin"
	.incbin "build/assets/unknown/data_08150434.bin"
	.incbin "build/assets/unknown/data_0815045C.bin"
	.incbin "build/assets/unknown/data_081507A8.bin"
	.incbin "build/assets/unknown/data_081507CC.bin"
	.incbin "build/assets/unknown/data_08150810.bin"
	.incbin "build/assets/unknown/data_08150814.bin"
	.incbin "build/assets/unknown/data_0815081C.bin"
	.incbin "build/assets/unknown/data_08150820.bin"
	.incbin "build/assets/unknown/data_0815082C.bin"
	.incbin "build/assets/unknown/data_0815085C.bin"
	.incbin "build/assets/unknown/data_08150908.bin"
	.incbin "build/assets/unknown/data_08150920.bin"
	.incbin "build/assets/unknown/data_08150950.bin"
	.incbin "build/assets/unknown/data_08151000.bin"
	.incbin "build/assets/unknown/data_081516FC.bin"
	.global gUnk_0815E024
gUnk_0815E024:
	.incbin "build/assets/unknown/data_0815E024.bin"
	.incbin "build/assets/unknown/data_08160000.bin"
	.incbin "build/assets/unknown/data_08160408.bin"
	.incbin "build/assets/unknown/data_08160410.bin"
	.incbin "build/assets/unknown/data_08160414.bin"
	.incbin "build/assets/unknown/data_08160428.bin"
	.incbin "build/assets/unknown/data_0816042C.bin"
	.incbin "build/assets/unknown/data_08160430.bin"
	.incbin "build/assets/unknown/data_081605C0.bin"
	.incbin "build/assets/unknown/data_08160808.bin"
	.incbin "build/assets/unknown/data_0816080C.bin"
	.incbin "build/assets/unknown/data_08160814.bin"
	.incbin "build/assets/unknown/data_0816081C.bin"
	.incbin "build/assets/unknown/data_08160828.bin"
	.incbin "build/assets/unknown/data_0816082C.bin"
	.incbin "build/assets/unknown/data_08160830.bin"
	.incbin "build/assets/unknown/data_08160834.bin"
	.incbin "build/assets/unknown/data_08160CEC.bin"
	.global gUnk_08166024
gUnk_08166024:
	.incbin "build/assets/unknown/data_08166024.bin"
	.global gUnk_08166224
gUnk_08166224:
	.incbin "build/assets/unknown/data_08166224.bin"
	.global gUnk_081698F0
gUnk_081698F0:
	.incbin "build/assets/unknown/data_081698F0.bin"
	.incbin "build/assets/unknown/data_0816E508.bin"
	.incbin "build/assets/unknown/data_08170014.bin"
	.incbin "build/assets/unknown/data_08170428.bin"
	.incbin "build/assets/unknown/data_08170430.bin"
	.incbin "build/assets/unknown/data_08170700.bin"
	.incbin "build/assets/unknown/data_0817080C.bin"
	.incbin "build/assets/unknown/data_08170828.bin"
	.incbin "build/assets/unknown/data_08170A28.bin"
	.incbin "build/assets/unknown/data_08170CC4.bin"
	.incbin "build/assets/unknown/data_08171DE4.bin"
	.global gUnk_08178110
gUnk_08178110:
	.incbin "build/assets/unknown/data_08178110.bin"
	.incbin "build/assets/unknown/data_0817831C.bin"
	.global gUnk_0817C190
gUnk_0817C190:
	.incbin "build/assets/unknown/data_0817C190.bin"
	.global gUnk_0817E918
gUnk_0817E918:
	.incbin "build/assets/unknown/data_0817E918.bin"
	.incbin "build/assets/unknown/data_08180000.bin"
	.incbin "build/assets/unknown/data_08180808.bin"
	.incbin "build/assets/unknown/data_081808A0.bin"
	.incbin "build/assets/unknown/data_08182244.bin"
	.incbin "build/assets/unknown/data_0818EFFC.bin"
	.global gUnk_0818F958
gUnk_0818F958:
	.incbin "build/assets/unknown/data_0818F958.bin"
	.incbin "build/assets/unknown/data_08190000.bin"
	.incbin "build/assets/unknown/data_08190818.bin"
	.global gUnk_08197518
gUnk_08197518:
	.incbin "build/assets/unknown/data_08197518.bin"
	.global gUnk_08197718
gUnk_08197718:
	.incbin "build/assets/unknown/data_08197718.bin"
	.global gUnk_08198DC8
gUnk_08198DC8:
	.incbin "build/assets/unknown/data_08198DC8.bin"
	.incbin "build/assets/unknown/data_081A0080.bin"
	.incbin "build/assets/unknown/data_081A0160.bin"
	.global gUnk_081A34C8
gUnk_081A34C8:
	.incbin "build/assets/unknown/data_081A34C8.bin"
	.incbin "build/assets/unknown/data_081A49CC.bin"
	.global gUnk_081A4B88
gUnk_081A4B88:
	.incbin "build/assets/unknown/data_081A4B88.bin"
	.global gUnk_081A7164
gUnk_081A7164:
	.incbin "build/assets/unknown/data_081A7164.bin"
	.incbin "build/assets/unknown/data_081B0414.bin"
	.incbin "build/assets/unknown/data_081B080C.bin"
	.incbin "build/assets/unknown/data_081B0814.bin"
	.incbin "build/assets/unknown/data_081B081C.bin"
	.incbin "build/assets/unknown/data_081B40F0.bin"
	.global gUnk_081B4F24
gUnk_081B4F24:
	.incbin "build/assets/unknown/data_081B4F24.bin"
	.global gUnk_081BCEE4
gUnk_081BCEE4:
	.incbin "build/assets/unknown/data_081BCEE4.bin"
	.incbin "build/assets/unknown/data_081C0000.bin"
	.incbin "build/assets/unknown/data_081C0014.bin"
	.incbin "build/assets/unknown/data_081C001C.bin"
	.incbin "build/assets/unknown/data_081C0024.bin"
	.incbin "build/assets/unknown/data_081C0050.bin"
	.incbin "build/assets/unknown/data_081C042C.bin"
	.incbin "build/assets/unknown/data_081C0430.bin"
	.incbin "build/assets/unknown/data_081C06F8.bin"
	.incbin "build/assets/unknown/data_081C080C.bin"
	.incbin "build/assets/unknown/data_081C0814.bin"
	.incbin "build/assets/unknown/data_081C0818.bin"
	.incbin "build/assets/unknown/data_081C081C.bin"
	.incbin "build/assets/unknown/data_081C0834.bin"
	.incbin "build/assets/unknown/data_081C0874.bin"
	.incbin "build/assets/unknown/data_081C0C08.bin"
	.global gUnk_081C317C
gUnk_081C317C:
	.incbin "build/assets/unknown/data_081C317C.bin"
	.global gUnk_081C515C
gUnk_081C515C:
	.incbin "build/assets/unknown/data_081C515C.bin"
	.global gUnk_081C6ADC
gUnk_081C6ADC:
	.incbin "build/assets/unknown/data_081C6ADC.bin"
	.global gUnk_081C6CDC
gUnk_081C6CDC:
	.incbin "build/assets/unknown/data_081C6CDC.bin"
	.global gUnk_081C7EA8
gUnk_081C7EA8:
	.incbin "build/assets/unknown/data_081C7EA8.bin"
	.global gUnk_081C9BC8
gUnk_081C9BC8:
	.incbin "build/assets/unknown/data_081C9BC8.bin"
	.global gUnk_081CB608
gUnk_081CB608:
	.incbin "build/assets/unknown/data_081CB608.bin"
	.global gUnk_081CB808
gUnk_081CB808:
	.incbin "build/assets/unknown/data_081CB808.bin"
	.global gUnk_081CDE68
gUnk_081CDE68:
	.incbin "build/assets/unknown/data_081CDE68.bin"
	.incbin "build/assets/unknown/data_081D0024.bin"
	.incbin "build/assets/unknown/data_081D002C.bin"
	.incbin "build/assets/unknown/data_081D0414.bin"
	.incbin "build/assets/unknown/data_081D041C.bin"
	.incbin "build/assets/unknown/data_081D0430.bin"
	.incbin "build/assets/unknown/data_081D0434.bin"
	.incbin "build/assets/unknown/data_081D081C.bin"
	.incbin "build/assets/unknown/data_081D0908.bin"
	.incbin "build/assets/unknown/data_081D096C.bin"
	.incbin "build/assets/unknown/data_081D09A0.bin"
	.incbin "build/assets/unknown/data_081D0CD8.bin"
	.incbin "build/assets/unknown/data_081D0D44.bin"
	.incbin "build/assets/unknown/data_081D2D34.bin"
	.incbin "build/assets/unknown/data_081DE82C.bin"
	.global gUnk_081DECC8
gUnk_081DECC8:
	.incbin "build/assets/unknown/data_081DECC8.bin"
	.incbin "build/assets/unknown/data_081E0000.bin"
	.incbin "build/assets/unknown/data_081E001C.bin"
	.incbin "build/assets/unknown/data_081E002C.bin"
	.incbin "build/assets/unknown/data_081E0034.bin"
	.incbin "build/assets/unknown/data_081E014C.bin"
	.incbin "build/assets/unknown/data_081E041C.bin"
	.incbin "build/assets/unknown/data_081E042C.bin"
	.incbin "build/assets/unknown/data_081E0814.bin"
	.incbin "build/assets/unknown/data_081E081C.bin"
	.incbin "build/assets/unknown/data_081E0824.bin"
	.incbin "build/assets/unknown/data_081E0830.bin"
	.incbin "build/assets/unknown/data_081E0834.bin"
	.incbin "build/assets/unknown/data_081E086C.bin"
	.incbin "build/assets/unknown/data_081E0C98.bin"
	.global gUnk_081E2188
gUnk_081E2188:
	.incbin "build/assets/unknown/data_081E2188.bin"
	.global gUnk_081E4A64
gUnk_081E4A64:
	.incbin "build/assets/unknown/data_081E4A64.bin"
	.incbin "build/assets/unknown/data_081F0038.bin"
	.incbin "build/assets/unknown/data_081F0094.bin"
	.incbin "build/assets/unknown/data_081F041C.bin"
	.incbin "build/assets/unknown/data_081F0420.bin"
	.incbin "build/assets/unknown/data_081F042C.bin"
	.incbin "build/assets/unknown/data_081F082C.bin"
	.incbin "build/assets/unknown/data_081F08D4.bin"
	.incbin "build/assets/unknown/data_081F0C30.bin"
	.incbin "build/assets/unknown/data_081F0EF8.bin"
	.incbin "build/assets/unknown/data_081F1B14.bin"
	.global gUnk_081F8744
gUnk_081F8744:
	.incbin "build/assets/unknown/data_081F8744.bin"
	.incbin "build/assets/unknown/data_08200014.bin"
	.incbin "build/assets/unknown/data_0820001C.bin"
	.incbin "build/assets/unknown/data_0820002C.bin"
	.incbin "build/assets/unknown/data_0820041C.bin"
	.global gUnk_08200444
gUnk_08200444:
	.incbin "build/assets/unknown/data_08200444.bin"
	.incbin "build/assets/unknown/data_08200594.bin"
	.global gUnk_08200644
gUnk_08200644:
	.incbin "build/assets/unknown/data_08200644.bin"
	.incbin "build/assets/unknown/data_08200820.bin"
	.incbin "build/assets/unknown/data_08200828.bin"
	.incbin "build/assets/unknown/data_08200830.bin"
	.global gUnk_08203A14
gUnk_08203A14:
	.incbin "build/assets/unknown/data_08203A14.bin"
	.incbin "build/assets/unknown/data_08206868.bin"
	.global gUnk_0820E234
gUnk_0820E234:
	.incbin "build/assets/unknown/data_0820E234.bin"
	.incbin "build/assets/unknown/data_08210378.bin"
	.incbin "build/assets/unknown/data_0821041C.bin"
	.incbin "build/assets/unknown/data_08210420.bin"
	.incbin "build/assets/unknown/data_08210558.bin"
	.incbin "build/assets/unknown/data_082107E4.bin"
	.incbin "build/assets/unknown/data_08210814.bin"
	.incbin "build/assets/unknown/data_0821081C.bin"
	.incbin "build/assets/unknown/data_08210820.bin"
	.incbin "build/assets/unknown/data_08210834.bin"
	.incbin "build/assets/unknown/data_08210938.bin"
	.incbin "build/assets/unknown/data_08210C38.bin"
	.incbin "build/assets/unknown/data_08210DCC.bin"
	.global gUnk_082121D4
gUnk_082121D4:
	.incbin "build/assets/unknown/data_082121D4.bin"
	.incbin "build/assets/unknown/data_08214000.bin"
	.incbin "build/assets/unknown/data_08215800.bin"
	.incbin "build/assets/unknown/data_08215804.bin"
	.global gUnk_08215980
gUnk_08215980:
	.incbin "build/assets/unknown/data_08215980.bin"
	.incbin "build/assets/unknown/data_08215C5C.bin"
	.incbin "build/assets/unknown/data_08220000.bin"
	.incbin "build/assets/unknown/data_082204F0.bin"
	.incbin "build/assets/unknown/data_08220820.bin"
	.incbin "build/assets/unknown/data_08220D48.bin"
	.global gUnk_08228880
gUnk_08228880:
	.incbin "build/assets/unknown/data_08228880.bin"
	.incbin "build/assets/unknown/data_08230110.bin"
	.incbin "build/assets/unknown/data_0823014C.bin"
	.incbin "build/assets/unknown/data_0823041C.bin"
	.global gUnk_082307A0
gUnk_082307A0:
	.incbin "build/assets/unknown/data_082307A0.bin"
	.incbin "build/assets/unknown/data_08230CA4.bin"
	.incbin "build/assets/unknown/data_08230D4C.bin"
	.global gUnk_08231DC8
gUnk_08231DC8:
	.incbin "build/assets/unknown/data_08231DC8.bin"
	.incbin "build/assets/unknown/data_08236800.bin"
	.incbin "build/assets/unknown/data_08236844.bin"
	.global gUnk_0823F128
gUnk_0823F128:
	.incbin "build/assets/unknown/data_0823F128.bin"
	.incbin "build/assets/unknown/data_08240000.bin"
	.incbin "build/assets/unknown/data_0824001C.bin"
	.incbin "build/assets/unknown/data_0824002C.bin"
	.incbin "build/assets/unknown/data_082407BC.bin"
	.incbin "build/assets/unknown/data_08240824.bin"
	.global gUnk_08242CA8
gUnk_08242CA8:
	.incbin "build/assets/unknown/data_08242CA8.bin"
	.global gUnk_08242EA8
gUnk_08242EA8:
	.incbin "build/assets/unknown/data_08242EA8.bin"
	.global gUnk_08244C24
gUnk_08244C24:
	.incbin "build/assets/unknown/data_08244C24.bin"
	.incbin "build/assets/unknown/data_08248274.bin"
	.incbin "build/assets/unknown/data_0824C6F4.bin"
	.incbin "build/assets/unknown/data_08250000.bin"
	.incbin "build/assets/unknown/data_0825001C.bin"
	.incbin "build/assets/unknown/data_0825002C.bin"
	.incbin "build/assets/unknown/data_08250030.bin"
	.incbin "build/assets/unknown/data_08250220.bin"
	.incbin "build/assets/unknown/data_08250420.bin"
	.incbin "build/assets/unknown/data_08250524.bin"
	.incbin "build/assets/unknown/data_0825054C.bin"
	.incbin "build/assets/unknown/data_082507D8.bin"
	.incbin "build/assets/unknown/data_0825081C.bin"
	.incbin "build/assets/unknown/data_08250824.bin"
	.incbin "build/assets/unknown/data_08250C1C.bin"
	.incbin "build/assets/unknown/data_08250C20.bin"
	.incbin "build/assets/unknown/data_08250C30.bin"
	.incbin "build/assets/unknown/data_08251720.bin"
	.incbin "build/assets/unknown/data_08251824.bin"
	.incbin "build/assets/unknown/data_08251CA0.bin"
	.global gUnk_08253884
gUnk_08253884:
	.incbin "build/assets/unknown/data_08253884.bin"
	.global gUnk_0825B764
gUnk_0825B764:
	.incbin "build/assets/unknown/data_0825B764.bin"
	.global gUnk_0825B964
gUnk_0825B964:
	.incbin "build/assets/unknown/data_0825B964.bin"
	.global gUnk_0825D510
gUnk_0825D510:
	.incbin "build/assets/unknown/data_0825D510.bin"
	.incbin "build/assets/unknown/data_08260004.bin"
	.incbin "build/assets/unknown/data_0826000C.bin"
	.incbin "build/assets/unknown/data_08260530.bin"
	.global gUnk_082683F0
gUnk_082683F0:
	.incbin "build/assets/unknown/data_082683F0.bin"
	.global gUnk_0826BC70
gUnk_0826BC70:
	.incbin "build/assets/unknown/data_0826BC70.bin"
	.global gUnk_0826DE48
gUnk_0826DE48:
	.incbin "build/assets/unknown/data_0826DE48.bin"
	.incbin "build/assets/unknown/data_0827002C.bin"
	.incbin "build/assets/unknown/data_08270180.bin"
	.incbin "build/assets/unknown/data_082701DC.bin"
	.incbin "build/assets/unknown/data_08270428.bin"
	.incbin "build/assets/unknown/data_08270430.bin"
	.incbin "build/assets/unknown/data_08270480.bin"
	.incbin "build/assets/unknown/data_082707D4.bin"
	.incbin "build/assets/unknown/data_0827082C.bin"
	.global gUnk_0827AAA8
gUnk_0827AAA8:
	.incbin "build/assets/unknown/data_0827AAA8.bin"
	.incbin "build/assets/unknown/data_0827B7D2.bin"
	.incbin "build/assets/unknown/data_08280428.bin"
	.incbin "build/assets/unknown/data_08280430.bin"
	.incbin "build/assets/unknown/data_08280828.bin"
	.incbin "build/assets/unknown/data_08280D64.bin"
	.global gUnk_08282468
gUnk_08282468:
	.incbin "build/assets/unknown/data_08282468.bin"
	.global gUnk_08283E0C
gUnk_08283E0C:
	.incbin "build/assets/unknown/data_08283E0C.bin"
	.global gUnk_0828519C
gUnk_0828519C:
	.incbin "build/assets/unknown/data_0828519C.bin"
	.global gUnk_082855D8
gUnk_082855D8:
	.incbin "build/assets/unknown/data_082855D8.bin"
	.global gUnk_08285968
gUnk_08285968:
	.incbin "build/assets/unknown/data_08285968.bin"
	.global gUnk_082876D4
gUnk_082876D4:
	.incbin "build/assets/unknown/data_082876D4.bin"
	.global gUnk_08288BD4
gUnk_08288BD4:
	.incbin "build/assets/unknown/data_08288BD4.bin"
	.global gUnk_0828AA90
gUnk_0828AA90:
	.incbin "build/assets/unknown/data_0828AA90.bin"
	.global gUnk_0828BA60
gUnk_0828BA60:
	.incbin "build/assets/unknown/data_0828BA60.bin"
	.incbin "build/assets/unknown/data_0828C600.bin"
	.global gUnk_0828DD4C
gUnk_0828DD4C:
	.incbin "build/assets/unknown/data_0828DD4C.bin"
	.global gUnk_0828F52C
gUnk_0828F52C:
	.incbin "build/assets/unknown/data_0828F52C.bin"
	.incbin "build/assets/unknown/data_082901DC.bin"
	.incbin "build/assets/unknown/data_0829035C.bin"
	.incbin "build/assets/unknown/data_08290428.bin"
	.incbin "build/assets/unknown/data_0829042C.bin"
	.incbin "build/assets/unknown/data_08290430.bin"
	.incbin "build/assets/unknown/data_08290434.bin"
	.incbin "build/assets/unknown/data_082904C8.bin"
	.incbin "build/assets/unknown/data_08290828.bin"
	.incbin "build/assets/unknown/data_0829082C.bin"
	.incbin "build/assets/unknown/data_08290830.bin"
	.incbin "build/assets/unknown/data_08290938.bin"
	.incbin "build/assets/unknown/data_08290988.bin"
	.incbin "build/assets/unknown/data_08290ABC.bin"
	.global gUnk_082914A0
gUnk_082914A0:
	.incbin "build/assets/unknown/data_082914A0.bin"
	.global gUnk_08292650
gUnk_08292650:
	.incbin "build/assets/unknown/data_08292650.bin"
	.incbin "build/assets/unknown/data_0829295C.bin"
	.global gUnk_08293548
gUnk_08293548:
	.incbin "build/assets/unknown/data_08293548.bin"
	.global gUnk_082939A8
gUnk_082939A8:
	.incbin "build/assets/unknown/data_082939A8.bin"
	.global gUnk_08295820
gUnk_08295820:
	.incbin "build/assets/unknown/data_08295820.bin"
	.global gUnk_08296A30
gUnk_08296A30:
	.incbin "build/assets/unknown/data_08296A30.bin"
	.global gUnk_08298BE4
gUnk_08298BE4:
	.incbin "build/assets/unknown/data_08298BE4.bin"
	.global gUnk_08299AF4
gUnk_08299AF4:
	.incbin "build/assets/unknown/data_08299AF4.bin"
	.global gUnk_0829B024
gUnk_0829B024:
	.incbin "build/assets/unknown/data_0829B024.bin"
	.global gUnk_0829C7B4
gUnk_0829C7B4:
	.incbin "build/assets/unknown/data_0829C7B4.bin"
	.global gUnk_0829DBB0
gUnk_0829DBB0:
	.incbin "build/assets/unknown/data_0829DBB0.bin"
	.global gUnk_0829EAE0
gUnk_0829EAE0:
	.incbin "build/assets/unknown/data_0829EAE0.bin"
	.global gUnk_0829EAFC
gUnk_0829EAFC:
	.incbin "build/assets/unknown/data_0829EAFC.bin"
	.global gUnk_0829EB00
gUnk_0829EB00:
	.incbin "build/assets/unknown/data_0829EB00.bin"
	.global gUnk_0829EB0C
gUnk_0829EB0C:
	.incbin "build/assets/unknown/data_0829EB0C.bin"
	.global gUnk_0829EB2C
gUnk_0829EB2C:
	.incbin "build/assets/unknown/data_0829EB2C.bin"
	.global gUnk_0829EB30
gUnk_0829EB30:
	.incbin "build/assets/unknown/data_0829EB30.bin"
	.global gUnk_0829EB3C
gUnk_0829EB3C:
	.incbin "build/assets/unknown/data_0829EB3C.bin"
	.global gUnk_0829EB4C
gUnk_0829EB4C:
	.incbin "build/assets/unknown/data_0829EB4C.bin"
	.global gUnk_0829EB50
gUnk_0829EB50:
	.incbin "build/assets/unknown/data_0829EB50.bin"
	.global gUnk_0829EB5C
gUnk_0829EB5C:
	.incbin "build/assets/unknown/data_0829EB5C.bin"
	.global gUnk_0829EB70
gUnk_0829EB70:
	.incbin "build/assets/unknown/data_0829EB70.bin"
	.global gUnk_0829EB74
gUnk_0829EB74:
	.incbin "build/assets/unknown/data_0829EB74.bin"
	.global gUnk_0829EB7C
gUnk_0829EB7C:
	.incbin "build/assets/unknown/data_0829EB7C.bin"
	.global gUnk_0829EB88
gUnk_0829EB88:
	.incbin "build/assets/unknown/data_0829EB88.bin"
	.global gUnk_0829EB8C
gUnk_0829EB8C:
	.incbin "build/assets/unknown/data_0829EB8C.bin"
	.global gUnk_0829EB98
gUnk_0829EB98:
	.incbin "build/assets/unknown/data_0829EB98.bin"
	.global gUnk_0829EBAC
gUnk_0829EBAC:
	.incbin "build/assets/unknown/data_0829EBAC.bin"
	.global gUnk_0829EBB0
gUnk_0829EBB0:
	.incbin "build/assets/unknown/data_0829EBB0.bin"
	.global gUnk_0829EBBC
gUnk_0829EBBC:
	.incbin "build/assets/unknown/data_0829EBBC.bin"
	.global gUnk_0829EBC8
gUnk_0829EBC8:
	.incbin "build/assets/unknown/data_0829EBC8.bin"
	.global gUnk_0829EBD4
gUnk_0829EBD4:
	.incbin "build/assets/unknown/data_0829EBD4.bin"
	.global gUnk_0829EBE4
gUnk_0829EBE4:
	.incbin "build/assets/unknown/data_0829EBE4.bin"
	.global gUnk_0829EBE8
gUnk_0829EBE8:
	.incbin "build/assets/unknown/data_0829EBE8.bin"
	.global gUnk_0829EBF4
gUnk_0829EBF4:
	.incbin "build/assets/unknown/data_0829EBF4.bin"
	.global gUnk_0829EC18
gUnk_0829EC18:
	.incbin "build/assets/unknown/data_0829EC18.bin"
	.global gUnk_0829EC1C
gUnk_0829EC1C:
	.incbin "build/assets/unknown/data_0829EC1C.bin"
	.global gUnk_0829EC28
gUnk_0829EC28:
	.incbin "build/assets/unknown/data_0829EC28.bin"
	.global gUnk_0829EC38
gUnk_0829EC38:
	.incbin "build/assets/unknown/data_0829EC38.bin"
	.global gUnk_0829EC3C
gUnk_0829EC3C:
	.incbin "build/assets/unknown/data_0829EC3C.bin"
	.global gUnk_0829EC44
gUnk_0829EC44:
	.incbin "build/assets/unknown/data_0829EC44.bin"
	.global gUnk_0829EC58
gUnk_0829EC58:
	.incbin "build/assets/unknown/data_0829EC58.bin"
	.global gUnk_0829EC5C
gUnk_0829EC5C:
	.incbin "build/assets/unknown/data_0829EC5C.bin"
	.global gUnk_0829EC68
gUnk_0829EC68:
	.incbin "build/assets/unknown/data_0829EC68.bin"
	.global gUnk_0829EC78
gUnk_0829EC78:
	.incbin "build/assets/unknown/data_0829EC78.bin"
	.global gUnk_0829EC7C
gUnk_0829EC7C:
	.incbin "build/assets/unknown/data_0829EC7C.bin"
	.global gUnk_0829EC88
gUnk_0829EC88:
	.incbin "build/assets/unknown/data_0829EC88.bin"
	.global gUnk_0829EC9C
gUnk_0829EC9C:
	.incbin "build/assets/unknown/data_0829EC9C.bin"
	.global gUnk_0829ECA8
gUnk_0829ECA8:
	.incbin "build/assets/unknown/data_0829ECA8.bin"
	.global gUnk_0829ECB8
gUnk_0829ECB8:
	.incbin "build/assets/unknown/data_0829ECB8.bin"
	.global gUnk_0829ECC4
gUnk_0829ECC4:
	.incbin "build/assets/unknown/data_0829ECC4.bin"
	.global gUnk_0829ECD4
gUnk_0829ECD4:
	.incbin "build/assets/unknown/data_0829ECD4.bin"
	.global gUnk_0829ECE4
gUnk_0829ECE4:
	.incbin "build/assets/unknown/data_0829ECE4.bin"
	.global gUnk_0829ECF0
gUnk_0829ECF0:
	.incbin "build/assets/unknown/data_0829ECF0.bin"
	.global gUnk_0829ED00
gUnk_0829ED00:
	.incbin "build/assets/unknown/data_0829ED00.bin"
	.global gUnk_0829ED0C
gUnk_0829ED0C:
	.incbin "build/assets/unknown/data_0829ED0C.bin"
	.global gUnk_0829ED18
gUnk_0829ED18:
	.incbin "build/assets/unknown/data_0829ED18.bin"
	.global gUnk_0829ED24
gUnk_0829ED24:
	.incbin "build/assets/unknown/data_0829ED24.bin"
	.global gUnk_0829ED34
gUnk_0829ED34:
	.incbin "build/assets/unknown/data_0829ED34.bin"
	.global gUnk_0829ED44
gUnk_0829ED44:
	.incbin "build/assets/unknown/data_0829ED44.bin"
	.global gUnk_0829ED54
gUnk_0829ED54:
	.incbin "build/assets/unknown/data_0829ED54.bin"
	.global gUnk_0829ED60
gUnk_0829ED60:
	.incbin "build/assets/unknown/data_0829ED60.bin"
	.global gUnk_0829ED6C
gUnk_0829ED6C:
	.incbin "build/assets/unknown/data_0829ED6C.bin"
	.global gUnk_0829ED78
gUnk_0829ED78:
	.incbin "build/assets/unknown/data_0829ED78.bin"
	.global gUnk_0829ED88
gUnk_0829ED88:
	.incbin "build/assets/unknown/data_0829ED88.bin"
	.global gUnk_0829ED94
gUnk_0829ED94:
	.incbin "build/assets/unknown/data_0829ED94.bin"
	.global gUnk_0829EDA0
gUnk_0829EDA0:
	.incbin "build/assets/unknown/data_0829EDA0.bin"
	.global gUnk_0829EDB0
gUnk_0829EDB0:
	.incbin "build/assets/unknown/data_0829EDB0.bin"
	.global gUnk_0829EDC0
gUnk_0829EDC0:
	.incbin "build/assets/unknown/data_0829EDC0.bin"
	.global gUnk_0829EDCC
gUnk_0829EDCC:
	.incbin "build/assets/unknown/data_0829EDCC.bin"
	.global gUnk_0829EDD8
gUnk_0829EDD8:
	.incbin "build/assets/unknown/data_0829EDD8.bin"
	.global gUnk_0829EDE4
gUnk_0829EDE4:
	.incbin "build/assets/unknown/data_0829EDE4.bin"
	.global gUnk_0829EDF0
gUnk_0829EDF0:
	.incbin "build/assets/unknown/data_0829EDF0.bin"
	.global gUnk_0829EE00
gUnk_0829EE00:
	.incbin "build/assets/unknown/data_0829EE00.bin"
	.global gUnk_0829EE10
gUnk_0829EE10:
	.incbin "build/assets/unknown/data_0829EE10.bin"
	.global gUnk_0829EE24
gUnk_0829EE24:
	.incbin "build/assets/unknown/data_0829EE24.bin"
	.global gUnk_0829EE30
gUnk_0829EE30:
	.incbin "build/assets/unknown/data_0829EE30.bin"
	.global gUnk_0829EE40
gUnk_0829EE40:
	.incbin "build/assets/unknown/data_0829EE40.bin"
	.global gUnk_0829EE8C
gUnk_0829EE8C:
	.incbin "build/assets/unknown/data_0829EE8C.bin"
