; EFI x64 structures

struc EFI_CONFIGURATION_TABLE {
    .VendorGuid     EFI_GUID
    .VendorTable    PTR VOID
}
__STRUCT__ EFI_CONFIGURATION_TABLE
