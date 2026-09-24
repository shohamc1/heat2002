@ The cartridge header. Every field is empty here: gbafix fills in the
@ Nintendo logo, title, game code, maker code, fixed value and checksum
@ after the link (see the Makefile), as pokeemerald's src/rom_header.s does.

	.syntax unified

	.text
	.arm

	.global Start
Start:
	b Init

	.global RomHeaderNintendoLogo
RomHeaderNintendoLogo:
	.space 156

RomHeaderGameTitle:
	.space 12

	.global RomHeaderGameCode
RomHeaderGameCode:
	.space 4

RomHeaderMakerCode:
	.space 2

	.global RomHeaderMagic
RomHeaderMagic:
	.byte 0

RomHeaderMainUnitCode:
	.byte 0

RomHeaderDeviceType:
	.byte 0

RomHeaderReserved1:
	.space 7

RomHeaderSoftwareVersion:
	.byte 0

RomHeaderChecksum:
	.byte 0

RomHeaderReserved2:
	.space 2
