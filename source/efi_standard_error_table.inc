; EFI Standard Error Table

__EFI_STANDARD_ERROR_TABLE_PTR__ PTR EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL

macro EfiStandardError.Init {
    EfiSystemTable.GetConsoleOutTable
    mov [__EFI_STANDARD_ERROR_TABLE_PTR__], rax
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_InitTable EfiStandardError, __EFI_STANDARD_ERROR_TABLE_PTR__
}
