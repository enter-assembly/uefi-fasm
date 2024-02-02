; EFI Boot Services Table

__EFI_BOOT_SERVICES_TABLE__ PTR EFI_BOOT_SERVICES

macro EfiBootServices.Init __SYSTEM_NAME {
    __SYSTEM_NAME#.#GetBootServicesTable
    mov [__EFI_BOOT_SERVICES_TABLE__], rax
    EFI_BOOT_SERVICES_Init EfiBootServices, __EFI_BOOT_SERVICES_TABLE__
}
