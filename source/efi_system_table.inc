; EFI System Table

__EFI_SYSTEM_TABLE_PTR__ PTR EFI_SYSTEM_TABLE

EFI_SYSTEM_TABLE_SIGNATURE fix 0x5453595320494249

struc EFI_SYSTEM_TABLE {
    .Header                 EFI_TABLE_HEADER
    .FirmwareVendor         PTR CHAR16
    .FirmwareRevision       UINT32
    .ConsoleInHandle        EFI_HANDLE
    .ConsoleInTable         PTR EFI_SIMPLE_TEXT_INPUT_PROTOCOL
    .ConsoleOutHandle       EFI_HANDLE
    .ConsoleOutTable        PTR EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
    .StandardErrorHandle    EFI_HANDLE
    .StandardErrorTable     PTR EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
    .RuntimeServicesTable   PTR EFI_RUNTIME_SERVICES
    .BootServicesTable      PTR EFI_BOOT_SERVICES
    .NumberOfTableEntries   UINTN
    .ConfigurationTable     PTR EFI_CONFIGURATION_TABLE
}
__STRUCT__ EFI_SYSTEM_TABLE

macro EfiSystemTable.Init {
    mov [__EFI_SYSTEM_TABLE_PTR__], rdx
}
macro EfiSystemTable.GetTableHeader {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
}

macro EfiSystemTable.GetFirmwareVendor {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.FirmwareVendor]
}

macro EfiSystemTable.GetFirmwareRevision {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.FirmwareRevision]
}

macro EfiSystemTable.GetConsoleInHandle {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.ConsoleInHandle]
}

macro EfiSystemTable.GetConsoleInTable {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.ConsoleInTable]
}

macro EfiSystemTable.GetConsoleOutHandle {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.ConsoleOutHandle]
}

macro EfiSystemTable.GetConsoleOutTable {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.ConsoleOutTable]
}

macro EfiSystemTable.GetStandardErrorHandle {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.StandardErrorHandle]
}

macro EfiSystemTable.GetStandardErrorTable {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.StandardErrorTable]
}

macro EfiSystemTable.GetRuntimeServicesTable {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.RuntimeServicesTable]
}

macro EfiSystemTable.GetBootServicesTable {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.BootServicesTable]
}

macro EfiSystemTable.GetNumberOfTableEntries {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.NumberOfTableEntries]
}

macro EfiSystemTable.GetConfigurationTable {
    mov rax, [__EFI_SYSTEM_TABLE_PTR__]
    mov rax, [rax + EFI_SYSTEM_TABLE.ConfigurationTable]
}
