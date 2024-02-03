; EFI Simple Text Input

EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID fix 0x387477c1,0x69c7,0x11d2,0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b

struc EFI_SIMPLE_TEXT_INPUT {
    .Reset              PTR EFI_SIMPLE_TEXT_INPUT_Reset
    .ReadKeyStroke      PTR EFI_SIMPLE_TEXT_INPUT_ReadKeyStroke
    .WaitForKeyEvent    PTR EFI_EVENT
}
__STRUCT__ EFI_SIMPLE_TEXT_INPUT

struc EFI_INPUT_KEY {
    .ScanCode       UINT16
    .UnicodeChar    CHAR16
}
__STRUCT__ EFI_INPUT_KEY

macro EFI_SIMPLE_TEXT_INPUT_Init __NAME, __PTR {

    ; EFI_SIMPLE_TEXT_INPUT_Reset macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_INPUT, Reset, IN This PTR EFI_SIMPLE_TEXT_INPUT, IN ExtendedVerification BOOLEAN
    macro __NAME#.#Reset ExtendedVerification \{
        EFI_SIMPLE_TEXT_INPUT_Reset [__PTR], [__PTR], ExtendedVerification
    \}

    ; EFI_SIMPLE_TEXT_INPUT_ReadKeyStroke macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_INPUT, ReadKeyStroke, IN This PTR EFI_SIMPLE_TEXT_INPUT, OUT Key PTR EFI_INPUT_KEY
    macro __NAME#.#ReadKeyStroke Key \{
        EFI_SIMPLE_TEXT_INPUT_ReadKeyStroke [__PTR], [__PTR], Key
    \}

    macro __NAME#.#GetWaitForKeyEvent \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SIMPLE_TEXT_INPUT.WaitForKeyEvent]
    \}

}
