; EFI Simple Text Output Protocol

EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID fix 0x387477c2,0x69c7,0x11d2,0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b

struc EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    .Reset                      PTR EFI_TEXT_RESET
    .OutputString               PTR EFI_TEXT_STRING
    .TestString                 PTR EFI_TEXT_TEST_STRING
    .QueryMode                  PTR EFI_TEXT_QUERY_MODE
    .SetMode                    PTR EFI_TEXT_SET_MODE
    .SetAttribute               PTR EFI_TEXT_SET_ATTRIBUTE
    .ClearScreen                PTR EFI_TEXT_CLEAR_SCREEN
    .SetCursorPosition          PTR EFI_TEXT_SET_CURSOR_POSITION
    .EnableCursor               PTR EFI_TEXT_ENABLE_CURSOR
    .SimpleTextOutputModeTable  PTR SIMPLE_TEXT_OUTPUT_MODE
}
__STRUCT__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL

macro EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_InitTable TableName, Table {

    ; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_Reset macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, Reset, IN This PTR EFI_SIMPLE_TEXT_OUTPUT_TABLE, IN ExtendedVerification BOOLEAN
    macro TableName#.#Reset ExtendedVerification \{
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_Reset [Table], [Table], ExtendedVerification
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_OutputString macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, OutputString, IN This PTR EFI_SIMPLE_TEXT_OUTPUT_TABLE, IN String PTR CHAR16
    macro TableName#.#OutputString String \{
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_OutputString [Table], [Table], String
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_TestString macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, TestString, IN This PTR EFI_SIMPLE_TEXT_OUTPUT_TABLE, IN String PTR CHAR16
    macro TableName#.#TestString String \{
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_TestString [Table], [Table], String
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_QueryMode macro
    __EFI_CALL_4__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, QueryMode, IN This PTR EFI_SIMPLE_TEXT_OUTPUT_TABLE, IN ModeNumber UINTN, OUT Columns PTR UINTN, OUT Rows PTR UINTN
    macro TableName#.#QueryMode ModeNumber, Columns, Rows \{
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_QueryMode [Table], [Table], ModeNumber, Columns, Rows
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetMode macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, SetMode, IN This PTR EFI_SIMPLE_TEXT_OUTPUT_TABLE, IN ModeNumber UINTN
    macro TableName#.#SetMode ModeNumber \{
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetMode [Table], [Table], ModeNumber
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetAttribute macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, SetAttribute, IN This PTR EFI_SIMPLE_TEXT_OUTPUT_TABLE, IN Attribute UINTN
    macro TableName#.#SetAttribute Attribute \{
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetAttribute [Table], [Table], Attribute
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_ClearScreen macro
    __EFI_CALL_1__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, ClearScreen, IN This PTR EFI_SIMPLE_TEXT_OUTPUT_TABLE
    macro TableName#.#ClearScreen \{
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_ClearScreen [Table], [Table]
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetCursorPosition macro
    __EFI_CALL_3__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, SetCursorPosition, IN This PTR EFI_SIMPLE_TEXT_OUTPUT_TABLE, IN Column UINTN, IN Row UINTN
    macro TableName#.#SetCursorPosition Column, Row \{
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetCursorPosition [Table], [Table], Column, Row
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_EnableCursor macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL, EnableCursor, IN This PTR EFI_SIMPLE_TEXT_OUTPUT_TABLE, IN Visible BOOLEAN
    macro TableName#.#EnableCursor Visible \{
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_EnableCursor [Table], [Table], Visible
    \}

    macro EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.GetSimpleTextOutputModeTable EfiSimpleTextOutputTable {
        mov rax, EfiSimpleTextOutputTable
        mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.SimpleTextOutputModeTable]
    }
    macro TableName#.#GetSimpleTextOutputModeTable \{
        EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.GetSimpleTextOutputModeTable [Table]
    \}

}
