@ The multiboot island's header, laid out as the cartridge header
@ (lib/rom_header.s) plus the multiboot fields. The Makefile copies the
@ Nintendo logo in from the main header after gbafix writes it there.

	.syntax unified

	.text
	.arm

IslandStart:
	b IslandMultibootEntry

IslandHeaderNintendoLogo:
	.space 156

IslandHeaderGameTitle:
	.space 12

@ crt0_island.s sends the game code to the parent as a handshake.
	.global IslandHeaderGameCode
IslandHeaderGameCode:
	.space 4

IslandHeaderMakerCode:
	.ascii "01"

IslandHeaderMagic:
	.byte 0x96

IslandHeaderMainUnitCode:
	.byte 0

IslandHeaderDeviceType:
	.byte 0

IslandHeaderReserved1:
	.space 7

IslandHeaderSoftwareVersion:
	.byte 0

@ -(sum of the bytes from the title to the software version) - 0x19
IslandHeaderChecksum:
	.byte 0xF0

IslandHeaderReserved2:
	.space 2

@ The BIOS starts a multiboot image here, not at IslandStart.
IslandMultibootEntry:
	b sub_08363FF4

IslandHeaderBootMode:
	.byte 0

IslandHeaderSlaveId:
	.byte 0

IslandHeaderReserved3:
	.space 26
