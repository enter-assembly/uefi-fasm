format pe64 dll efi
entry main

include '../include/efi_x64.inc'

section '.data' data readable writeable

__SYSTEM_TABLE__    PTR EFI_SYSTEM
__CONSOLE_OUTPUT__  PTR EFI_SIMPLE_TEXT_OUTPUT
__CONSOLE_INPUT__   PTR EFI_SIMPLE_TEXT_INPUT
__BOOT_SERVICES__   PTR EFI_BOOT_SERVICES

__GRAPHICS_OUTPUT_GUID__ EFI_GUID EFI_GRAPHICS_OUTPUT_GUID
__GRAPHICS_OUTPUT__      PTR EFI_GRAPHICS_OUTPUT
__FRAME_BUFFER_BASE__    PTR EFI_GRAPHICS_OUTPUT_BLT_PIXEL

__BLUE__ EFI_GRAPHICS_OUTPUT_BLT_PIXEL 0xff, 0, 0

__INPUT_KEY EFI_INPUT_KEY

section '.text' code executable readable

main:
; Initialize lib
    mov [__SYSTEM_TABLE__], rdx
    EFI_SYSTEM_Init Sys, __SYSTEM_TABLE__

    Sys.GetConsoleInTable
    mov [__CONSOLE_INPUT__], rax
    EFI_SIMPLE_TEXT_INPUT_Init Cin, __CONSOLE_INPUT__

    Sys.GetConsoleOutTable
    mov [__CONSOLE_OUTPUT__], rax
    EFI_SIMPLE_TEXT_OUTPUT_Init Cout, __CONSOLE_OUTPUT__

    Sys.GetBootServicesTable
    mov [__BOOT_SERVICES__], rax
    EFI_BOOT_SERVICES_Init BootServices, __BOOT_SERVICES__

; Locating EFI_GRAPHICS_OUTPUT table
    Cout.ClearScreen
    Cout.OutputString _looking_for_message

    BootServices.LocateProtocol __GRAPHICS_OUTPUT_GUID__, NULL, __GRAPHICS_OUTPUT__
    call print_error

; Initialize EFI_GRAPHICS_OUTPUT table
    EFI_GRAPHICS_OUTPUT_Init Gout, __GRAPHICS_OUTPUT__

; Getting frame buffer pointer
    Gout.ModeTable.GetFrameBufferBase
    mov [__FRAME_BUFFER_BASE__], rax
    
; Filling frame buffer
    mov rcx, 4096 * 32
    xor rdx, rdx
    mov edx, [__BLUE__]
    .iter:
    mov [rax + rcx * 4], edx
    loop .iter
    Cout.OutputString _ready
    jmp .ok

    .failed:
    Cout.OutputString _failed
    jmp .exit
    .ok:
    Cout.OutputString _ok

; Reading from keyboard loop
    .read_key:
        Cin.ReadKeyStroke __INPUT_KEY
        test rax, rax

    ; read failed
        jne .read_key

    ; read ok
        mov ax, [__INPUT_KEY + EFI_INPUT_KEY.UnicodeChar]
        mov [__output_key], ax
        Cout.OutputString __output_key
        jmp .read_key

    .exit:
    jmp $
    retn

; rax - error
print_error:
    push rdx
    cmp rax, 0
    jne .fail
    pop rdx
    Cout.OutputString __EFI_SUCCESS
    Cout.OutputString _new_line
    ret
        .fail:
    mov rdx, EFI_NOT_READY
    test rax, rdx
    jne @f
    pop rdx
    Cout.OutputString __EFI_NOT_READY
    Cout.OutputString _new_line
    ret
    @@:
    pop rdx
    Cout.OutputString __EFI_ERROR
    Cout.OutputString _new_line
    ret

section '.data' data readable writeable

_looking_for_message    EFI_STRING_NL "Looking for Graphics Output Protocol"
_new_line               EFI_STRING_NL
_ready                  EFI_STRING_NL "Ready"
_ok                     EFI_STRING_NL "Ok"
_failed                 EFI_STRING_NL "Failed"

hello_string    EFI_STRING_NL 'Hello, Uefi!!!'
error_string    EFI_STRING_NL 'This is error string'

__output_key    EFI_STRING 0
 
section '.reloc' fixups data discardable

