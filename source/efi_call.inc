; EFI Call
; rcx, rdx, r8, r9, rsp + 32 rsp + 40, rsp + 48, rsp + 56, rsp + 64, rsp + 72, rsp + 80
; The stack is aligned at 16.
; 48 = 32 (temporary area for the function being called) + 8 (for aling) + 8 (ret address)

macro __EFI_CALL__ TABLE, PROTOCOL, FUNCTION {
    mov rdi, TABLE
    mov rdi, [rdi + PROTOCOL#.#FUNCTION]
    call rdi
}

macro __EFI_CALL_0__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE \{
        sub rsp, 40
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp 40
    \}
}

macro __EFI_CALL_1__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1 \{
        sub rsp, 40
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 40
    \}
}

macro __EFI_CALL_2__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2 \{
        sub rsp, 40
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 40
    \}
}

macro __EFI_CALL_3__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2, arg3 \{
        sub rsp, 40
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 40
    \}
}

macro __EFI_CALL_4__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2, arg3, arg4 \{
        sub rsp, 40
        mov r9, arg4
        mov r8, arg3
        mov rdx, arg2
        mov rcx, arg1
        __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
        add rsp, 40
    \}
}

macro __EFI_CALL_5__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2, arg3, arg4, arg5 \{
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

macro __EFI_CALL_6__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2, arg3, arg4, arg5, arg6 \{
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

macro __EFI_CALL_7__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2, arg3, arg4, arg5, arg6, arg7 \{
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

macro __EFI_CALL_8__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 \{
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

macro __EFI_CALL_9__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 \{
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

macro __EFI_CALL_10__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10 \{
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

macro __EFI_CALL_11__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11 \{
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
