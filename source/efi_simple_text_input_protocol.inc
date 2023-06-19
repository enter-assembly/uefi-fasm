; EFI Simple Text Input Table

EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID fix 0x387477c1,0x69c7,0x11d2,0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b

struc EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    .Reset              PTR EFI_INPUT_RESET
    .ReadKeyStroke      PTR EFI_INPUT_READ_KEY
    .WaitForKeyEvent    PTR EFI_EVENT
}
__STRUCT__ EFI_SIMPLE_TEXT_INPUT_PROTOCOL

; EFI_SIMPLE_TEXT_INPUT_PROTOCOL_Reset macro
__EFI_CALL_2__ EFI_SIMPLE_TEXT_INPUT_PROTOCOL, Reset, IN This PTR EFI_SIMPLE_TEXT_INPUT_TABLE, IN ExtendedVerification BOOLEAN
; EFI_SIMPLE_TEXT_INPUT_PROTOCOL_ReadKeyStroke macro
__EFI_CALL_2__ EFI_SIMPLE_TEXT_INPUT_PROTOCOL, ReadKeyStroke, IN This PTR EFI_SIMPLE_TEXT_INPUT_TABLE, OUT Key PTR EFI_INPUT_KEY

macro EFI_SIMPLE_TEXT_INPUT_PROTOCOL.GetWaitForKeyEvent TABLE {
    mov rax, TABLE
    mov rax, [rax + EFI_SIMPLE_TEXT_INPUT_PROTOCOL.WaitForKeyEvent]
}

macro EFI_SIMPLE_TEXT_INPUT_PROTOCOL_InitTable TableName, Table {

    macro TableName#.#Reset ExtendedVerification \{
        EFI_SIMPLE_TEXT_INPUT_PROTOCOL_Reset [Table], [Table], ExtendedVerification
    \}

    macro TableName#.#ReadKeyStroke Key \{
        EFI_SIMPLE_TEXT_INPUT_PROTOCOL_ReadKeyStroke [Table], [Table], Key
    \}

    macro TableName#.#GetWayForKeyEvent \{
        EFI_SIMPLE_TEXT_INPUT_PROTOCOL.GetWaitForKeyEvent [Table]
    \}

}
