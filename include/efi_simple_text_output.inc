; EFI Simple Text Output

EFI_SIMPLE_TEXT_OUTPUT_GUID fix 0x387477c2,0x69c7,0x11d2,0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b

struc EFI_SIMPLE_TEXT_OUTPUT {
    .Reset                      PTR EFI_SIMPLE_TEXT_OUTPUT_Reset
    .OutputString               PTR EFI_SIMPLE_TEXT_OUTPUT_OutputString
    .TestString                 PTR EFI_SIMPLE_TEXT_OUTPUT_TestString
    .QueryMode                  PTR EFI_SIMPLE_TEXT_OUTPUT_QueryMode
    .SetMode                    PTR EFI_SIMPLE_TEXT_OUTPUT_SetMode
    .SetAttribute               PTR EFI_SIMPLE_TEXT_OUTPUT_SetAttribute
    .ClearScreen                PTR EFI_SIMPLE_TEXT_OUTPUT_ClearScreen
    .SetCursorPosition          PTR EFI_SIMPLE_TEXT_OUTPUT_SetCursorPosition
    .EnableCursor               PTR EFI_SIMPLE_TEXT_OUTPUT_EnableCursor
    .Mode                       PTR EFI_SIMPLE_TEXT_OUTPUT_MODE
}
__STRUCT__ EFI_SIMPLE_TEXT_OUTPUT

struc EFI_SIMPLE_TEXT_OUTPUT_MODE {
    .MaxMode        INT32
    .Mode           INT32
    .Attribute      INT32
    .CursorColumn   INT32
    .CursorRow      INT32
    .CursorVisible  BOOLEAN
}
__STRUCT__ EFI_SIMPLE_TEXT_OUTPUT_MODE

macro EFI_SIMPLE_TEXT_OUTPUT_Init __NAME, __PTR {

    ; EFI_SIMPLE_TEXT_OUTPUT_Reset macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT, Reset, IN This PTR EFI_SIMPLE_TEXT_OUTPUT, IN ExtendedVerification BOOLEAN
    macro __NAME#.#Reset ExtendedVerification \{
        EFI_SIMPLE_TEXT_OUTPUT_Reset [__PTR], [__PTR], ExtendedVerification
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_OutputString macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT, OutputString, IN This PTR EFI_SIMPLE_TEXT_OUTPUT, IN String PTR CHAR16
    macro __NAME#.#OutputString String \{
        EFI_SIMPLE_TEXT_OUTPUT_OutputString [__PTR], [__PTR], String
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_TestString macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT, TestString, IN This PTR EFI_SIMPLE_TEXT_OUTPUT, IN String PTR CHAR16
    macro __NAME#.#TestString String \{
        EFI_SIMPLE_TEXT_OUTPUT_TestString [__PTR], [__PTR], String
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_QueryMode macro
    __EFI_CALL_4__ EFI_SIMPLE_TEXT_OUTPUT, QueryMode, IN This PTR EFI_SIMPLE_TEXT_OUTPUT, IN ModeNumber UINTN, OUT Columns PTR UINTN, OUT Rows PTR UINTN
    macro __NAME#.#QueryMode ModeNumber, Columns, Rows \{
        EFI_SIMPLE_TEXT_OUTPUT_QueryMode [__PTR], [__PTR], ModeNumber, Columns, Rows
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_SetMode macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT, SetMode, IN This PTR EFI_SIMPLE_TEXT_OUTPUT, IN ModeNumber UINTN
    macro __NAME#.#SetMode ModeNumber \{
        EFI_SIMPLE_TEXT_OUTPUT_SetMode [__PTR], [__PTR], ModeNumber
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_SetAttribute macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT, SetAttribute, IN This PTR EFI_SIMPLE_TEXT_OUTPUT, IN Attribute UINTN
    macro __NAME#.#SetAttribute Attribute \{
        EFI_SIMPLE_TEXT_OUTPUT_SetAttribute [__PTR], [__PTR], Attribute
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_ClearScreen macro
    __EFI_CALL_1__ EFI_SIMPLE_TEXT_OUTPUT, ClearScreen, IN This PTR EFI_SIMPLE_TEXT_OUTPUT
    macro __NAME#.#ClearScreen \{
        EFI_SIMPLE_TEXT_OUTPUT_ClearScreen [__PTR], [__PTR]
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_SetCursorPosition macro
    __EFI_CALL_3__ EFI_SIMPLE_TEXT_OUTPUT, SetCursorPosition, IN This PTR EFI_SIMPLE_TEXT_OUTPUT, IN Column UINTN, IN Row UINTN
    macro __NAME#.#SetCursorPosition Column, Row \{
        EFI_SIMPLE_TEXT_OUTPUT_SetCursorPosition [__PTR], [__PTR], Column, Row
    \}

    ; EFI_SIMPLE_TEXT_OUTPUT_EnableCursor macro
    __EFI_CALL_2__ EFI_SIMPLE_TEXT_OUTPUT, EnableCursor, IN This PTR EFI_SIMPLE_TEXT_OUTPUT, IN Visible BOOLEAN
    macro __NAME#.#EnableCursor Visible \{
        EFI_SIMPLE_TEXT_OUTPUT_EnableCursor [__PTR], [__PTR], Visible
    \}

    macro __NAME#.#GetMode \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT.Mode]
    \}
    
    macro __NAME#.#Mode#.#GetMaxMod \{
        __NAME#.#GetMode
        mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE.MaxMode]
    \}

    macro __NAME#.#Mode#.#GetMode EfiSimpleTextOutputTablePtr \{
        __NAME#.#GetMode
        mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE.Mode]
    \}

    macro __NAME#.#Mode#.#GetAttribute EfiSimpleTextOutputTablePtr \{
        __NAME#.#GetMode
        mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE.Attribute]
    \}

    macro __NAME#.#Mode#.#GetCursorColumln EfiSimpleTextOutputTablePtr \{
        __NAME#.#GetMode
        mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE_.CursorColumn]
    \}

    macro __NAME#.#Mode#.#GetCursorRow EfiSimpleTextOutputTablePtr \{
        __NAME#.#GetMode
        mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE.CursorRow]
    \}

    macro __NAME#.#Mode#.#GetCursorVisible EfiSimpleTextOutputTablePtr \{
        __NAME#.#GetMode
        mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE_.CursorVisible]
    \}
    
}
