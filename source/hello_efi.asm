format pe64 dll efi
entry main

include '../include/efi_x64.inc'

section '.data' data readable writeable

include 'efi_table/efi_system_table.inc'
include 'efi_table/efi_console_out_table.inc'
include 'efi_table/efi_boot_services_table.inc'

__GOP__ PTR EFI_GRAPHICS_OUTPUT
__GOP_GUID__ EFI_GUID EFI_GRAPHICS_OUTPUT_GUID
__FRAME_BASE__ EFI_PHYSICAL_ADDRESS 0

__BLUE__ EFI_GRAPHICS_OUTPUT_BLT_PIXEL 0xff, 0, 0
__GREEN__ EFI_GRAPHICS_OUTPUT_BLT_PIXEL 0, 255, 0
__RED__ EFI_GRAPHICS_OUTPUT_BLT_PIXEL 0, 0, 255

section '.text' code executable readable

main:
    EfiSystemTable.Init
    EfiConsoleOut.Init EfiSystemTable
    EfiBootServices.Init EfiSystemTable

    EfiConsoleOut.ClearScreen
    EfiConsoleOut.OutputString _looking_for_message

    EfiBootServices.LocateProtocol __GOP_GUID__, NULL, __GOP__
    call print_error

    EFI_GRAPHICS_OUTPUT_Init Gop, __GOP__
    Gop.ModeTable.GetFrameBufferBase
    
    mov rcx, 4096 * 32
    xor rdx, rdx
    mov edx, [__BLUE__]
    .iter:
    mov [rax + rcx * 4], edx
    loop .iter
    EfiConsoleOut.OutputString _ready
    jmp .ok

    .failed:
    EfiConsoleOut.OutputString _failed
    jmp .exit
    .ok:
    EfiConsoleOut.OutputString _ok
    .exit:
    jmp $
    retn

; rax - error
print_error:
    cmp rax, 0
    jne .fail
    EfiConsoleOut.OutputString __EFI_SUCCESS
    EfiConsoleOut.OutputString _new_line
    ret
        .fail:
    EfiConsoleOut.OutputString __EFI_ERROR
    EfiConsoleOut.OutputString _new_line
    ret

section '.data' data readable writeable

_looking_for_message du "Looking for Graphics Output Protocol", 13, 10, 0
_new_line du 13, 10, 0
_ready du "Ready", 13, 10, 0
_ok du "Ok", 13, 10, 0
_failed du "Failed", 13, 10, 0
 
hello_string du 'Hello, Uefi!!!',13,10,0
error_string du 'This is error string',13,10,0

section '.reloc' fixups data discardable

