; Efi System Table

__EFI_SYSTEM_TABLE__ PTR EFI_SYSTEM

macro EfiSystemTable.Init {
    mov [__EFI_SYSTEM_TABLE__], rdx
    EFI_SYSTEM_Init EfiSystemTable, __EFI_SYSTEM_TABLE__
}
