; EFI Console Out Table

__EFI_CONSOLE_OUT_TABLE__ PTR EFI_SIMPLE_TEXT_OUTPUT

macro EfiConsoleOut.Init __SYSTEM_NAME {
    __SYSTEM_NAME#.#GetConsoleOutTable
    mov [__EFI_CONSOLE_OUT_TABLE__], rax
    EFI_SIMPLE_TEXT_OUTPUT_Init EfiConsoleOut, __EFI_CONSOLE_OUT_TABLE__
}
