; EFI Standard Error Table

__EFI_STANDARD_ERROR_TABLE__ PTR EFI_SIMPLE_TEXT_OUTPUT

macro EfiStandardError.Init __SYSTEM_NAME {
    __SYSTEM_NAME#.#GetStandardErrorTable
    mov [__EFI_STANDARD_ERROR_TABLE__], rax
    EFI_SIMPLE_TEXT_OUTPUT_Init EfiStandardError, __EFI_STANDARD_ERROR_TABLE__
}
