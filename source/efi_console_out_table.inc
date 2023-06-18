; EFI Console Out Table

__EFI_CONSOLE_OUT_TABLE_PTR__ PTR EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL

macro EfiConsoleOut.Init {
    EfiSystemTable.GetConsoleOutTable
    mov [__EFI_CONSOLE_OUT_TABLE_PTR__], rax
}
    
macro EfiConsoleOut.Reset ExtendedVerification {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_Reset [__EFI_CONSOLE_OUT_TABLE_PTR__], [__EFI_CONSOLE_OUT_TABLE_PTR__], ExtendedVerification
}

macro EfiConsoleOut.OutputString String {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_OutputString [__EFI_CONSOLE_OUT_TABLE_PTR__], [__EFI_CONSOLE_OUT_TABLE_PTR__], String
}

macro EfiConsoleOut.TestString String {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_TestString [__EFI_CONSOLE_OUT_TABLE_PTR__], [__EFI_CONSOLE_OUT_TABLE_PTR__], String
}

macro EfiConsoleOut.QueryMode ModeNumber, Columns, Rows {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_QueryMode [__EFI_CONSOLE_OUT_TABLE_PTR__], [__EFI_CONSOLE_OUT_TABLE_PTR__], ModeNumber, Columns, Rows
}

macro EfiConsoleOut.SetMode ModeNumber {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetMode [__EFI_CONSOLE_OUT_TABLE_PTR__], [__EFI_CONSOLE_OUT_TABLE_PTR__], ModeNumber
}

macro EfiConsoleOut.SetAttribute Attribute {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetAttribute [__EFI_CONSOLE_OUT_TABLE_PTR__], [__EFI_CONSOLE_OUT_TABLE_PTR__], Attribute
}

macro EfiConsoleOut.ClearScreen {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_ClearScreen [__EFI_CONSOLE_OUT_TABLE_PTR__], [__EFI_CONSOLE_OUT_TABLE_PTR__]
}

macro EfiConsoleOut.SetCursorPosition Column, Row {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_SetCursorPosition [__EFI_CONSOLE_OUT_TABLE_PTR__], [__EFI_CONSOLE_OUT_TABLE_PTR__], Column, Row
}

macro EfiConsoleOut.EnableCursor Visible {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_EnableCursor [__EFI_CONSOLE_OUT_TABLE_PTR__], [__EFI_CONSOLE_OUT_TABLE_PTR__], Visible
}

macro EfiConsoleOut.GetSimpleTextOutputModeTable {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.GetSimpleTextOutputModeTable [__EFI_CONSOLE_OUT_TABLE_PTR__]
}
