; x64 functions

macro efi_init uefi_element {
if defined __#uefi_element#__
    __init__#uefi_element#__
end if
}

macro uefi_use_system_table {
    macro __init__system_table__ \{
        mov [__system_table__], rdx
    \}
__system_table__ PTR EFI_SYSTEM_TABLE, 0
}

macro uefi_use_image_handle {
    macro __init__image_handle__ \{
        mov [__image_handle__], rcx
    \}
__image_handle__ EFI_HANDLE 0
}

macro uefi_use_boot_services {
    macro __init__boot_services__ \{
        mov rdi, [rdx + EFI_SYSTEM_TABLE.BootServices]
        mov [__boot_services_table__], rdi
    \}
__boot_services__ PTR EFI_BOOT_SERVICES, 0
}

macro uefi_use_con_out_table {
    macro __init__con_out_table__ \{
        mov rdi, [rdx + EFI_SYSTEM_TABLE.ConOut]
        mov [__con_out_table__], rdi
    \}
__con_out_table__ PTR EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, 0
}

; rcx, rdx, r8, r9, rsp + 32 rsp + 40, rsp + 48, rsp + 56, rsp + 64, rsp + 72, rsp + 80
; The stack is aligned at 16.
; 48 = 32 (temporary area for the function being called) + 8 (for aling) + 8 (ret address)

macro __EFI_CALL__ TABLE, PROTOCOL, FUNCTION {
    mov rdi, TABLE
    mov rdi, [rdi + PROTOCOL#.#FUNCTION]
    call rdi
}

macro __EFI_CALL_0__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION \{
        sub rsp, 40
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp 40
    \}
}

macro __EFI_CALL_1__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, IGNORE \{
        sub rsp, 40
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 40
    \}
}

macro __EFI_CALL_2__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, arg2 \{
        sub rsp, 40
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 40
    \}
}

macro __EFI_CALL_3__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, arg2, arg3 \{
        sub rsp, 40
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 40
    \}
}

macro __EFI_CALL_4__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, arg2, arg3, arg4 \{
        sub rsp, 40
        mov r9, arg4
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 40
    \}
}

macro __EFI_CALL_5__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, arg2, arg3, arg4, arg5 \{
        sub rsp, 40
        mov rax, arg5
        mov [rsp + 32], rax
        mov r9, arg4
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 40
    \}
}

macro __EFI_CALL_6__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, arg2, arg3, arg4, arg5, arg6 \{
        sub rsp, 56
        mov rax, arg6
        mov [rsp + 40], rax
        mov rax, arg5
        mov [rsp + 32], rax
        mov r9, arg4
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 56
    \}
}

macro __EFI_CALL_7__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, arg2, arg3, arg4, arg5, arg6, arg7 \{
        sub rsp, 56
        mov rax, arg7
        mov [rsp + 48], rax
        mov rax, arg6
        mov [rsp + 40], rax
        mov rax, arg5
        mov [rsp + 32], rax
        mov r9, arg4
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 56
    \}
}

macro __EFI_CALL_8__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 \{
        sub rsp, 72
        mov rax, arg8
        mov [rsp + 56], rax
        mov rax, arg7
        mov [rsp + 48], rax
        mov rax, arg6
        mov [rsp + 40], rax
        mov rax, arg5
        mov [rsp + 32], rax
        mov r9, arg4
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 72
    \}
}

macro __EFI_CALL_9__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 \{
        sub rsp, 72
        mov rax, arg9
        mov [rsp + 64], rax
        mov rax, arg8
        mov [rsp + 56], rax
        mov rax, arg7
        mov [rsp + 48], rax
        mov rax, arg6
        mov [rsp + 40], rax
        mov rax, arg5
        mov [rsp + 32], rax
        mov r9, arg4
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 72
    \}
}

macro __EFI_CALL_10__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10 \{
        sub rsp, 88
        mov rax, arg10
        mov [rsp + 72], rax
        mov rax, arg9
        mov [rsp + 64], rax
        mov rax, arg8
        mov [rsp + 56], rax
        mov rax, arg7
        mov [rsp + 48], rax
        mov rax, arg6
        mov [rsp + 40], rax
        mov rax, arg5
        mov [rsp + 32], rax
        mov r9, arg4
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 88
    \}
}

macro __EFI_CALL_11__ TABLE, PROTOCOL, FUNCTION, [ARG_NAME] {
    macro FUNCTION arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11 \{
        sub rsp, 88
        mov rax, arg11
        mov [rsp + 80], rax
        mov rax, arg10
        mov [rsp + 72], rax
        mov rax, arg9
        mov [rsp + 64], rax
        mov rax, arg8
        mov [rsp + 56], rax
        mov rax, arg7
        mov [rsp + 48], rax
        mov rax, arg6
        mov [rsp + 40], rax
        mov rax, arg5
        mov [rsp + 32], rax
        mov r9, arg4
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 88
    \}
}

macro __MAKE_THIS_ARG_FIRST_FUNCTION__ THIS, PREFIX, FUNCTION {
    macro PREFIX#.#FUNCTION [ARG] \{
    \common
        FUNCTION THIS, ARG
    \}
}

macro __MAKE_CONOUT_FUNCTION__ EFI_CALL, FUNCTION, [ARG_NAME] {
common
    EFI_CALL [__con_out_table__], EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, FUNCTION, ARG_NAME
    __MAKE_THIS_ARG_FIRST_FUNCTION__ [__con_out_table__], ConOut, FUNCTION
}

__MAKE_CONOUT_FUNCTION__ __EFI_CALL_2__, Reset, IN ThisPtr, IN ExtendedVerificationBoolean
__MAKE_CONOUT_FUNCTION__ __EFI_CALL_2__, OutputString, IN ThisPtr, IN StringChar16Ptr
__MAKE_CONOUT_FUNCTION__ __EFI_CALL_2__, TestString, IN ThisPtr, IN StringChar16Ptr
__MAKE_CONOUT_FUNCTION__ __EFI_CALL_4__, QueryMode, IN ThisPtr, IN ModeNumberUintn, OUT ColomsUintnPtr, OUT RowsUintnPtr
__MAKE_CONOUT_FUNCTION__ __EFI_CALL_2__, SetMode, IN ThisPtr, IN ModeNumberUintn
__MAKE_CONOUT_FUNCTION__ __EFI_CALL_2__, SetAttribute, IN ThisPtr, IN AttributeUintn
__MAKE_CONOUT_FUNCTION__ __EFI_CALL_1__, ClearScreen, IN ThisPtr
__MAKE_CONOUT_FUNCTION__ __EFI_CALL_3__, SetCursorPosition, IN ThisPtr, IN ColomnUintn, IN RowUintn
__MAKE_CONOUT_FUNCTION__ __EFI_CALL_2__, EnableCursor, IN ThisPtr, IN VisibleBoolean
