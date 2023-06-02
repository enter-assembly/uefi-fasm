format pe64 dll efi
entry main
 
include 'uefi_x64.inc'
include 'func_defines.inc'

section '.data' data readable writeable
    uefi_use_system_table
    uefi_use_image_handle
    uefi_use_con_out_table
 
section '.text' code executable readable
 
main:
    efi_init system_table
    efi_init image_handle
    efi_init con_out_table

    ConOut.ClearScreen
    ConOut.OutputString hello_string
 
    jmp $
    retn

section '.data' data readable writeable
 
GOPU EFI_GUID EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID
GOP PTR EFI_GRAPHICS_OUTPUT_PROTOCOL 0

hello_string du 'Hello World, from UEFI FASM',13,10,0

section '.reloc' fixups data discardable

