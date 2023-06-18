; EFI Time

struc EFI_TIME {
    .Year       UINT16
    .Month      UINT8
    .Day        UINT8
    .Hour       UINT8
    .Minute     UINT8
    .Second     UINT8
    .Pad1       UINT8
    .Nanosecond UINT32
    .TimeZone   INT16
    .Dayligh    UINT8
    .Pad2       UINT8
}
__STRUCT__ EFI_TIME

macro EFI_TIME.Year EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Year]
}

macro EFI_TIME.Month EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Month]
}

macro EFI_TIME.Day EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Day]
}

macro EFI_TIME.Hour EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Hour]
}

macro EFI_TIME.Minute EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Minute]
}

macro EFI_TIME.Second EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Second]
}

macro EFI_TIME.Pad1 EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Pad1]
}

macro EFI_TIME.Nanosecond EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Nanosecond]
}

macro EFI_TIME.TimeZone EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.TimeZone]
}

macro EFI_TIME.Dayligh EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Dayligh]
}

macro EFI_TIME.Pad2 EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Pad2]
}
