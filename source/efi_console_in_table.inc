; EFI Console In Table

section '.data' readable writeable
__EFI_CONSOLE_IN_TABLE_PTR__ PTR EFI_SIMPLE_TEXT_INPUT_PROTOCOL

macro EfiConsoleIn.Init {
    EfiSystemTable.GetConsoleInTable
    mov [__EFI_CONSOLE_IN_TABLE_PTR__], rax
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL_InitTable EfiConsoleIn, __EFI_CONSOLE_IN_TABLE_PTR__
}
