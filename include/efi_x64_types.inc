; EFI x64 types

macro __TYPE__ __typename, __data_mnemonic, __align {
    struc __typename [__value] \{
    \common
    if ~ __align eq
        align __align
    end if
    if __value eq
        . __data_mnemonic ?
    else
        . __data_mnemonic __value
    end if
    \}
}

struc ARRAY __typename, __size, __value, [__values] {
common
    __vc = 0
forward
    __vc = __vc + 1
common
if ~ __values eq
    if ~ __size = __vc + 1
        'error: sizeof(' __value, __values ') !=' __size
    end if
    . __typename __value, __values
else if ~ __value eq
    . __typename __size dup(__value)
else
    . __typename __size dup(?)
end if
}

struc EFI_STRING [__value] {
common
    . CHAR16 __value, 0
}

EFI_NEW_LINE equ 0xD, 0xA

struc EFI_STRING_NL [__value] {
common
if ~ __value eq
    . CHAR16 __value, EFI_NEW_LINE, 0
else
    . CHAR16 EFI_NEW_LINE, 0
end if
}

ALIGN_1 equ 1
ALIGN_2 equ 2
ALIGN_4 equ 4
ALIGN_8 equ 8

__TYPE__ BOOLEAN, db, ALIGN_1
__TYPE__ INTN,    dq, ALIGN_8
__TYPE__ UINTN,   dq, ALIGN_8
__TYPE__ INT8,    db, ALIGN_1
__TYPE__ UINT8,   db, ALIGN_1
__TYPE__ INT16,   dw, ALIGN_2
__TYPE__ UINT16,  dw, ALIGN_2
__TYPE__ INT32,   dd, ALIGN_4
__TYPE__ UINT32,  dd, ALIGN_4
__TYPE__ INT64,   dq, ALIGN_8
__TYPE__ UINT64,  dq, ALIGN_8
__TYPE__ CHAR8,   db, ALIGN_1
__TYPE__ CHAR16,  du, ALIGN_2

struc PTR __typename, __value {
    . UINT64 __value
}

struc EFI_PHYSICAL_ADDRESS __value {
    . PTR VOID, __value
}

struc EFI_GUID __data1, __data2, __data3, [__data4] {
common
    .data1 UINT32 __data1
    .data2 UINT16 __data2
    .data3 UINT16 __data3
    .data4 ARRAY UINT8, 8, __data4
}

struc EFI_STATUS __value {
    . INTN __value
}

struc EFI_HANDLE __value {
    . PTR VOID, __value
}

struc EFI_EVENT __value {
    . PTR VOID, __value
}

struc EFI_LBA __value {
    . UINT64 __value
}

struc EFI_TPL __value {
    . UINTN __value
}

struc EFI_MAC_ADDRESS [__value] {
    . ARRAY UINT8, 32, __value
}

struc EFI_IPv4_ADDRESS [__value] {
    . ARRAY UINT8, 4, __value
}

struc EFI_IPv6_ADDRESS [__value] {
    . ARRAY UINT8, 16, __value
}

struc EFI_IP_ADDRESS [__value] {
    . ARRAY UINT32, 4, __value
}

struc EFI_SIGNATURE __value {
    . UINT64 __value
}

macro ENUM __enum_name, [__value_name] {
common
    struc __enum_name __value \{
    if __value eq
        . UINT32
    else if ~ __value in <__value_name>
        'error: no value' __value 'in' __value_name
    else
        . UINT32 __enum_name#.\#__value
    end if
    \}
    __vc = 0
forward
    __enum_name#.#__value_name = __vc
    __vc = __vc + 1
}

macro __STRUCT__ __name {
virtual at 0
    __name __name
end virtual
}

NULL    equ 0
FALSE   equ 0
TRUE    equ 1
