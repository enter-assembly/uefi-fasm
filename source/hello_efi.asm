format pe64 dll efi
entry main
 
section '.data' data readable writeable

include 'efi_x64_types.inc'
include 'efi_call.inc'
include 'efi_table.inc'
include 'efi_system_table.inc'
include 'efi_simple_text_output_protocol.inc'
include 'efi_console_out_table.inc'
 
section '.text' code executable readable

main:
    EfiSystemTable.Init
    EfiConsoleOut.Init

    EfiConsoleOut.ClearScreen
    EfiConsoleOut.OutputString hello_string
 
    jmp $
    retn

section '.data' data readable writeable
 
hello_string du 'Hello, Uefi Fasm Library!!',13,10,0

section '.reloc' fixups data discardable

