; stdtype.inc

; Not aligned types

__TYPE__ BOOL, db

__TYPE__ INT8, db
__TYPE__ INT16, dw
__TYPE__ INT32, dd
__TYPE__ INT64, dq

__TYPE__ UINT8, db
__TYPE__ UINT16, dw
__TYPE__ UINT32, dd
__TYPE__ UINT64, dq

__TYPE__ CHAR8, db
__TYPE__ CHAR16, du

struc INTN [__value] {
common
    . SSIZE __value
}

struc UINTN [__value] {
common
    . USIZE __value
}

struc PTR __typename, __value {
    . USIZE __value
}

; Aligned types

ALIGN_1 equ 1
ALIGN_2 equ 2
ALIGN_4 equ 4
ALIGN_8 equ 8

__TYPE__ BOOLA, db, ALIGN_1

__TYPE__ INT8A, db, ALIGN_1
__TYPE__ INT16A, dw, ALIGN_2
__TYPE__ INT32A, dd, ALIGN_4
__TYPE__ INT64A, dq, ALIGN_8

__TYPE__ UINT8A, db, ALIGN_1
__TYPE__ UINT16A, dw, ALIGN_2
__TYPE__ UINT32A, dd, ALIGN_4
__TYPE__ UINT64A, dq, ALIGN_8

__TYPE__ CHAR8A, db, ALIGN_1
__TYPE__ CHAR16A, du, ALIGN_2

struc INTNA [__value] {
common
    . SSIZEA __value
}

struc UINTNA [__value] {
common
    . USIZEA __value
}

struc PTRA __typename, __value {
    . USIZEA __value
}
