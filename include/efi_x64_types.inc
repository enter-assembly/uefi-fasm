; EFI x64 types

macro __ALIGN__ _align {
if ~ _align eq
    align _align
end if
}

macro __TYPE__ typename, data_mnemonic, _align {
    struc typename value \{
        __ALIGN__ _align
    if value eq
        . data_mnemonic ?
    else
        . data_mnemonic value
    end if
    \}

    struc typename#_ARR size, [value] \{
    \common
        __ALIGN__ _align
    if size eq
        "error: arr size is null"
    end if
        vc = 0
    \forward
        vc = vc + 1
    \common
    if value eq
        . data_mnemonic size dup(?)
    else
        if ~ size = vc
            "error: data values count != " size
        end if
        . data_mnemonic value
    end if
    \}
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

struc PTR typename, value {
    . UINT64 value
}

struc EFI_PHYSICAL_ADDRESS value {
    . PTR VOID, value
}

struc EFI_GUID data1, data2, data3, [data4] {
common
    .data1 UINT32 data1
    .data2 UINT16 data2
    .data3 UINT16 data3
    .data4 UINT8_ARR 8, data4
}

struc EFI_STATUS value {
    . INTN value
}

struc EFI_HANDLE value {
    . PTR VOID, value
}

struc EFI_EVENT value {
    . PTR VOID, value
}

struc EFI_LBA value {
    . UINT64 value
}

struc EFI_TPL value {
    . UINTN value
}

struc EFI_MAC_ADDRESS [value] {
    . UINT8_ARR 32, value
}

struc EFI_IPv4_ADDRESS [value] {
    . UINT8_ARR 4, value
}

struc EFI_IPv6_ADDRESS [value] {
    . UINT8_ARR 16, value
}

struc EFI_IP_ADDRESS [value] {
    . UINT32_ARR 4, value
}

struc EFI_SIGNATURE value {
    . UINT64 value
}

macro ENUM enum_name, [value_name] {
common
    struc enum_name value \{
    if value eq
        . UINT32
    else
        if ~ value in <value_name>
            "error: unknown value" value ". use" value_name
        else
            . UINT32 enum_name#.\#value
        end if
    end if
    \}
    value_count = 0
forward
    enum_name#.#value_name = value_count
    value_count = value_count + 1
}

macro __STRUCT__ NAME {
    virtual at 0
        NAME NAME
    end virtual
}
