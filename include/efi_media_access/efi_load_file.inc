; Efi Load File

EFI_LOAD_FILE_GUID fix 0x56EC3091,0x954C,0x11d2,0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B

struc EFI_LOAD_FILE {
    .LoadFile   PTR EFI_LOAD_FILE_LoadFile
}
STRUCT EFI_LOAD_FILE

macro EFI_LOAD_FILE_Init __NAME, __PTR {

    ; EFI_LOAD_FILE_LoadFile macro
    __EFI_CALL_5__ EFI_LOAD_FILE, LoadFile, IN This PTR EFI_LOAD_FILE, IN FilePath PTR EFI_DEVICE_PATH, IN BootPolicy BOOLEAN, IN OUT BufferSize PTR UINTN, IN Buffer PTR VOID OPTIONAL
    macro __NAME#.#LoadFile __file_path, __boot_policy, __buffer_size, __buffer {
        EFI_LOAD_FILE_LoadFile [__PTR], [__PTR], __file_path, __boot_policy, __buffer_size, __buffer
    }

}
