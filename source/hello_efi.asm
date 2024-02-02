format pe64 dll efi
entry main

include '../include/efi_x64.inc'

section '.data' data readable writeable

include 'efi_table/efi_system_table.inc'
include 'efi_table/efi_console_out_table.inc'
include 'efi_table/efi_standard_error_table.inc'

section '.text' code executable readable

main:
    EfiSystemTable.Init
    EfiConsoleOut.Init EfiSystemTable
    EfiStandardError.Init EfiSystemTable

    EfiConsoleOut.EnableCursor 1
    EfiConsoleOut.ClearScreen
    EfiConsoleOut.OutputString hello_string
    EfiStandardError.OutputString error_string
 
    jmp $
    retn

section '.data' data readable writeable
 
hello_string du 'Hello, Uefi Fasm Library!!',13,10,0
error_string du 'This is error string',13,10,0

section '.reloc' fixups data discardable

