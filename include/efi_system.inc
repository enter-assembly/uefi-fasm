; EFI System

EFI_SYSTEM_SIGNATURE fix 0x5453595320494249

struc EFI_SYSTEM {
    .Header                 EFI_TABLE_HEADER
    .FirmwareVendor         PTR CHAR16
    .FirmwareRevision       UINT32
    .ConsoleInHandle        EFI_HANDLE
    .ConsoleInTable         PTR EFI_SIMPLE_TEXT_INPUT
    .ConsoleOutHandle       EFI_HANDLE
    .ConsoleOutTable        PTR EFI_SIMPLE_TEXT_OUTPUT
    .StandardErrorHandle    EFI_HANDLE
    .StandardErrorTable     PTR EFI_SIMPLE_TEXT_OUTPUT
    .RuntimeServicesTable   PTR EFI_RUNTIME_SERVICES
    .BootServicesTable      PTR EFI_BOOT_SERVICES
    .NumberOfTableEntries   UINTN
    .ConfigurationTable     PTR EFI_CONFIGURATION_TABLE
}
__STRUCT__ EFI_SYSTEM

struc EFI_CONFIGURATION_TABLE {
    .VendorGuid     EFI_GUID
    .VendorTable    PTR VOID
}
__STRUCT__ EFI_CONFIGURATION_TABLE

macro EFI_SYSTEM_Init __NAME, __PTR {

    EFI_TABLE_HEADER_CreateGetFunctions __NAME, __PTR

    macro __NAME#.#GetFirmwareVendor \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.FirmwareVendor]
    \}

    macro __NAME#.#GetFirmwareRevision \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.FirmwareRevision]
    \}

    macro __NAME#.#GetConsoleInHandle \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.ConsoleInHandle]
    \}

    macro __NAME#.#GetConsoleInTable \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.ConsoleInTable]
    \}

    macro __NAME#.#GetConsoleOutHandle \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.ConsoleOutHandle]
    \}

    macro __NAME#.#GetConsoleOutTable \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.ConsoleOutTable]
    \}

    macro __NAME#.#GetStandardErrorHandle \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.StandardErrorHandle]
    \}

    macro __NAME#.#GetStandardErrorTable \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.StandardErrorTable]
    \}

    macro __NAME#.#GetRuntimeServicesTable \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.RuntimeServicesTable]
    \}

    macro __NAME#.#GetBootServicesTable \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.BootServicesTable]
    \}

    macro __NAME#.#GetNumberOfTableEntries \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.NumberOfTableEntries]
    \}

    macro __NAME#.#GetConfigurationTable \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_SYSTEM.ConfigurationTable]
    \}

}
