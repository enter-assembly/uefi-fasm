; EFI x64 types

struc EFI_STRING [__value] {
common
    . CHAR16A __value, 0
}

EFI_NEW_LINE equ 0xD, 0xA

struc EFI_STRING_NL [__value] {
common
if ~ __value eq
    . CHAR16A __value, EFI_NEW_LINE, 0
else
    . CHAR16A EFI_NEW_LINE, 0
end if
}

struc PTR __typename, __value {
    . UINTNA __value
}

struc EFI_PHYSICAL_ADDRESS __value {
    . PTR VOID, __value
}

struc EFI_GUID __data1, __data2, __data3, [__data4] {
common
    .data1 UINT32A __data1
    .data2 UINT16A __data2
    .data3 UINT16A __data3
    .data4 ARRAY UINT8A, 8, __data4
}

struc EFI_STATUS __value {
    . INTNA __value
}

struc EFI_HANDLE __value {
    . PTR VOID, __value
}

struc EFI_EVENT __value {
    . PTR VOID, __value
}

struc EFI_LBA __value {
    . UINT64A __value
}

struc EFI_TPL __value {
    . UINTNA __value
}

struc EFI_MAC_ADDRESS [__value] {
    . ARRAY UINT8A, 32, __value
}

struc EFI_IPv4_ADDRESS [__value] {
    . ARRAY UINT8A, 4, __value
}

struc EFI_IPv6_ADDRESS [__value] {
    . ARRAY UINT8A, 16, __value
}

struc EFI_IP_ADDRESS [__value] {
    . ARRAY UINT32A, 4, __value
}

struc EFI_SIGNATURE __value {
    . UINT64A __value
}

NULL    equ 0
FALSE   equ 0
TRUE    equ 1
