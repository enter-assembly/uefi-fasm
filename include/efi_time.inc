; EFI Time

struc EFI_TIME {
    .Year       UINT16A
    .Month      UINT8A
    .Day        UINT8A
    .Hour       UINT8A
    .Minute     UINT8A
    .Second     UINT8A
    .Pad1       UINT8A
    .Nanosecond UINT32A
    .TimeZone   INT16A
    .Dayligh    UINT8A
    .Pad2       UINT8A
}
STRUCT EFI_TIME

macro EFI_TIME.GetYear EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Year]
}

macro EFI_TIME.GetMonth EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Month]
}

macro EFI_TIME.GetDay EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Day]
}

macro EFI_TIME.GetHour EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Hour]
}

macro EFI_TIME.GetMinute EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Minute]
}

macro EFI_TIME.GetSecond EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Second]
}

macro EFI_TIME.GetPad1 EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Pad1]
}

macro EFI_TIME.GetNanosecond EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Nanosecond]
}

macro EFI_TIME.GetTimeZone EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.TimeZone]
}

macro EFI_TIME.GetDayligh EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Dayligh]
}

macro EFI_TIME.GetPad2 EfiTimePtr {
    mov rax, EfiTimePtr
    mov rax, [rax + EFI_TIME.Pad2]
}
