; EFI Console In Table

__EFI_CONSOLE_IN_TABLE__ PTR EFI_SIMPLE_TEXT_INPUT

macro EfiConsoleIn.Init __SYSTEM_NAME {
    __SYSTEM_NAME#.#GetConsoleInTable
    mov [__EFI_CONSOLE_IN_TABLE__], rax
    EFI_SIMPLE_TEXT_INPUT_Init EfiConsoleIn, __EFI_CONSOLE_IN_TABLE__
}
