; EFI Console Out Table

__EFI_CONSOLE_OUT_TABLE_PTR__ PTR EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL

macro EfiConsoleOut.Init {
    EfiSystemTable.GetConsoleOutTable
    mov [__EFI_CONSOLE_OUT_TABLE_PTR__], rax
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_InitTable EfiConsoleOut, __EFI_CONSOLE_OUT_TABLE_PTR__
}
