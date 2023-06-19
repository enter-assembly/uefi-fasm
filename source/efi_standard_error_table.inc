; EFI Standard Error Table

__EFI_STANDARD_ERROR_TABLE_PTR__ PTR EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL

macro EfiStandardError.Init {
    EfiSystemTable.GetConsoleOutTable
    mov [__EFI_STANDARD_ERROR_TABLE_PTR__], rax
}
    
macro EfiStandardError.Reset ExtendedVerification {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_Reset [__EFI_STANDARD_ERROR_TABLE_PTR__], [__EFI_STANDARD_ERROR_TABLE_PTR__], ExtendedVerification
}

macro EfiStandardError.OutputString String {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_OutputString [__EFI_STANDARD_ERROR_TABLE_PTR__], [__EFI_STANDARD_ERROR_TABLE_PTR__], String
}

macro EfiStandardError.TestString String {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_TestString [__EFI_STANDARD_ERROR_TABLE_PTR__], [__EFI_STANDARD_ERROR_TABLE_PTR__], String
}

macro EfiStandardError.QueryMode ModeNumber, Columns, Rows {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_QueryMode [__EFI_STANDARD_ERROR_TABLE_PTR__], [__EFI_STANDARD_ERROR_TABLE_PTR__], ModeNumber, Columns, Rows
}

macro EfiStandardError.SetMode ModeNumber {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetMode [__EFI_STANDARD_ERROR_TABLE_PTR__], [__EFI_STANDARD_ERROR_TABLE_PTR__], ModeNumber
}

macro EfiStandardError.SetAttribute Attribute {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetAttribute [__EFI_STANDARD_ERROR_TABLE_PTR__], [__EFI_STANDARD_ERROR_TABLE_PTR__], Attribute
}

macro EfiStandardError.ClearScreen {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_ClearScreen [__EFI_STANDARD_ERROR_TABLE_PTR__], [__EFI_STANDARD_ERROR_TABLE_PTR__]
}

macro EfiStandardError.SetCursorPosition Column, Row {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetCursorPosition [__EFI_STANDARD_ERROR_TABLE_PTR__], [__EFI_STANDARD_ERROR_TABLE_PTR__], Column, Row
}

macro EfiStandardError.EnableCursor Visible {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_EnableCursor [__EFI_STANDARD_ERROR_TABLE_PTR__], [__EFI_STANDARD_ERROR_TABLE_PTR__], Visible
}

macro EfiStandardError.GetSimpleTextOutputModeTable {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.GetSimpleTextOutputModeTable [__EFI_STANDARD_ERROR_TABLE_PTR__]
}
