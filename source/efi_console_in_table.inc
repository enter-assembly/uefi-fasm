; EFI Console In Table

section '.data' readable writeable
__EFI_CONSOLE_IN_TABLE_PTR__ PTR EFI_SIMPLE_TEXT_INPUT_PROTOCOL

macro EfiConsoleIn.Init {
    EfiSystemTable.GetConsoleInTable
    mov [__EFI_CONSOLE_IN_TABLE_PTR__], rax
}

macro EfiConsoleIn.Reset ExtendedVerification {
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL_Reset [__EFI_CONSOLE_IN_TABLE_PTR__], [__EFI_CONSOLE_IN_TABLE_PTR__], ExtendedVerification
}

macro EfiConsoleIn.ReadKeyStroke Key {
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL_ReadKeyStroke [__EFI_CONSOLE_IN_TABLE_PTR__], [__EFI_CONSOLE_IN_TABLE_PTR__], Key
}

macro EfiConsoleIn.GetWayForKeyEvent {
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL.WaitForKeyEvent [__EFI_CONSOLE_IN_TABLE_PTR__]
}