; EFI Call
; rcx, rdx, r8, r9, rsp + 32 rsp + 40, rsp + 48, rsp + 56, rsp + 64, rsp + 72, rsp + 80
; The stack is aligned at 16.
; 48 = 32 (temporary area for the function being called) + 8 (for aling) + 8 (ret address)

macro __EFI_CALL__ TABLE, PROTOCOL, FUNCTION {
    mov rdi, TABLE
    mov rdi, [rdi + PROTOCOL#.#FUNCTION]
    call rdi
}

macro __EFI_0_ARGS_CALL TABLE, PROTOCOL, FUNCTION {
    sub rsp, 40
    __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
    add rsp 40
}

macro __EFI_CALL_0__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE \{
        __EFI_0_ARGS_CALL TABLE, PROTOCOL, FUNCTION
    \}
}

macro __EFI_1_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1 {
    sub rsp, 40
    mov rcx, arg1
    __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
    add rsp, 40
}

macro __EFI_CALL_1__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_1_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}

macro __EFI_2_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2 {
    sub rsp, 40
    mov rdx, arg2
    mov rcx, arg1
    __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
    add rsp, 40
}

macro __EFI_CALL_2__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_2_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}

macro __EFI_3_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3 {
    sub rsp, 40
    mov r8, arg3
    mov rdx, arg2
    mov rcx, arg1
    __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
    add rsp, 40
}

macro __EFI_CALL_3__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_3_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}
    
macro __EFI_4_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4 {
    sub rsp, 40
    mov r9, arg4
    mov r8, arg3
    mov rdx, arg2
    mov rcx, arg1
    __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
    add rsp, 40
}

macro __EFI_CALL_4__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_4_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}

macro __EFI_5_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5 {
    sub rsp, 40
    mov rax, arg5
    mov [rsp + 32], rax
    mov r9, arg4
    mov r8, arg3
    mov rdx, arg2
    mov rcx, arg1
    __EFI_CALL__ TABLE, PROTOCOL, FUNCTION
    add rsp, 40
}

macro __EFI_CALL_5__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_5_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}

macro __EFI_6_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6 {
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
}

macro __EFI_CALL_6__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_6_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}

macro __EFI_7_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6, arg7 {
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
}

macro __EFI_CALL_7__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_7_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}

macro __EFI_8_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 {
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
}

macro __EFI_CALL_8__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_8_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}

macro __EFI_9_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 {
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
}

macro __EFI_CALL_9__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_9_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}

macro __EFI_10_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10 {
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
}

macro __EFI_CALL_10__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_10_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}

macro __EFI_11_ARGS_CALL__ TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11 {
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
}

macro __EFI_CALL_11__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, [ARGS] \{
    \common
        __EFI_11_ARGS_CALL TABLE, PROTOCOL, FUNCTION, ARGS
    \}
}

macro __EFI_CALL_VARARGS__ PROTOCOL, FUNCTION, [ARG_NAME] {
common
    macro PROTOCOL#_#FUNCTION TABLE, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11 \{
        if ~ arg11 eq
            __EFI_11_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11
        else
        if ~ arg10 eq
            __EFI_10_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10
        else
        if ~ arg9 eq
            __EFI_9_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9
        else
        if ~ arg8 eq
            __EFI_8_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8
        else
        if ~ arg7 eq
            __EFI_7_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6, arg7
        else
        if ~ arg6 eq
            __EFI_6_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5, arg6
        else
        if ~ arg5 eq
            __EFI_5_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4, arg5
        else
        if ~ arg4 eq
            __EFI_4_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3, arg4
        else
        if ~ arg3 eq
            __EFI_3_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2, arg3
        else
        if ~ arg2 eq
            __EFI_2_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1, arg2
        else
        if ~ arg1 eq
            __EFI_1_ARGS_CALL TABLE, PROTOCOL, FUNCTION, arg1
        else
            __EFI_0_ARGS_CALL TABLE, PROTOCOL, FUNCTION
        end if
        end if
        end if
        end if
        end if
        end if
        end if
        end if
        end if
        end if
        end if
    \}
}
