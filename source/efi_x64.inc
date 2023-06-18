; EFI x64 structures

EFI_BOOT_SERVICES_SIGNATURE fix 0x56524553544f4f42
struc EFI_BOOT_SERVICES {
    .Hdr    EFI_TABLE_HEADER

    ; Task Priority Services
    .RaiseTPL   PTR EFI_RAISE_TPL
    .RestoreTPL PTR EFI_RESTORE_TPL

    ; Memory Services
    .AllocatePages  PTR EFI_ALLOCATE_PAGES
    .FreePages      PTR EFI_FREE_PAGES
    .GetMemoryMap   PTR EFI_GET_MEMORY_MAP
    .AllocatePool   PTR EFI_ALLOCATE_POOL
    .FreePool       PTR EFI_FREE_POOL

    ; Event & Timer Services
    .CreateEvent    PTR EFI_CREATE_EVENT
    .SetTimer       PTR EFI_SET_TIMER
    .WaitForEvent   PTR EFI_WAIT_FOR_EVENT
    .SignalEvent    PTR EFI_SIGNAL_EVENT
    .CloseEvent     PTR EFI_CLOSE_EVENT
    .CheckEvent     PTR EFI_CHECK_EVENT

    ; Protocol Handler Services
    .InstallProtocolInterface   PTR EFI_INSTALL_PROTOCOL_INTERFACE
    .ReinstallProtocolInterface PTR EFI_REINSTALL_PROTOCOL_INTERFACE
    .UninstallProtocolInterface PTR EFI_UNINSTALL_PROTOCOL_INTERFACE
    .HandleProtocol             PTR EFI_HANDLE_PROTOCOL
    .Reserved                   PTR VOID
    .RegisterProtocolNotify     PTR EFI_REGISTER_PROTOCOL_NOTIFY
    .LocateHandle               PTR EFI_LOCATE_HANDLE
    .LocateDevicePath           PTR EFI_LOCATE_DEVICE_PATH
    .InstallConfigurationTable  PTR EFI_INSTALL_CONFIGURATION_TABLE

    ; Image Services
    .LoadImage          PTR EFI_IMAGE_LOAD
    .StartImage         PTR EFI_IMAGE_START
    .Exit               PTR EFI_EXIT
    .UnloadImage        PTR EFI_IMAGE_UNLOAD
    .ExitBootServices   PTR EFI_EXIT_BOOT_SERVICES

    ; Miscellaneous Services
    .GetNextMonotonicCount  PTR EFI_GET_NEXT_MONOTONIC_COUNT
    .Stall                  PTR EFI_STALL
    .SetWatchdogTimer       PTR EFI_SET_WATCHDOG_TIMER

    ; DriverSupport Services
    .ConnectController      PTR EFI_CONNECT_CONTROLLER
    .DisconnectController   PTR EFI_DISCONNECT_CONTROLLER

    ; Open and Close Protocol Services
    .OpenProtocol               PTR EFI_OPEN_PROTOCOL
    .CloseProtocol              PTR EFI_CLOSE_PROTOCOL
    .OpenProtocolInformation    PTR EFI_OPEN_PROTOCOL_INFORMATION

    ; Library Services
    .ProtocolsPerHandle                     PTR EFI_PROTOCOLS_PER_HANDLE
    .LocateHandleBuffer                     PTR EFI_LOCATE_HANDLE_BUFFER
    .LocateProtocol                         PTR EFI_LOCATE_PROTOCOL
    .InstallMultipleProtocolInterfaces      PTR EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES
    .UninstallMultipleProtocolInterfaces    PTR EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES

    ; 32-bit CRC Services
    .CalculateCrc32 PTR EFI_CALCULATE_CRC32

    ; Miscellaneous Services
    .CopyMem        PTR EFI_COPY_MEM
    .SetMem         PTR EFI_SET_MEM
    .CreateEventEx  PTR EFI_CREATE_EVENT_EX
}
__STRUCT__ EFI_BOOT_SERVICES

struc EFI_CONFIGURATION_TABLE {
    .VendorGuid     EFI_GUID
    .VendorTable    PTR VOID
}
__STRUCT__ EFI_CONFIGURATION_TABLE

EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID fix 0x9042a9de,0x23dc,0x4a38,0x96,0xfb,0x7a,0xde,0xd0,0x80,0x51,0x6a
struc EFI_GRAPHICS_OUTPUT_PROTOCOL {
    .QueryMode  PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE
    .SetMode    PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE
    .Blt        PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT
    .Mode       PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE
}
__STRUCT__ EFI_GRAPHICS_OUTPUT_PROTOCOL

struc EFI_PIXEL_BITMASK {
    .RedMask        UINT32
    .GreenMask      UINT32
    .BlueMask       UINT32
    .ResevedMask    UINT32
}
__STRUCT__ EFI_PIXEL_BITMASK

;RGBR     - PixelRedGreenBlueReseved8BitPerColor
;BGRR     - PixelBlueRedGreenReseved8BitPerColor
;BIT_MASK - PixelBitMask
;BLT_ONLY - PixelBltOnly
;MAX      - PixelFormatMax
ENUM EFI_GRAPHICS_PIXEL_FORMAT, \
    RGBR, \
    BGRR, \
    BIT_MASK, \
    BLT_ONLY, \
    MAX

struc EFI_GRAPHICS_OUTPUT_MODE_INFORMATION {
    .Version                 UINT32
    .HorisontalResolution    UINT32
    .VerticalResolution      UINT32
    .PixelFormat             EFI_GRAPHICS_PIXEL_FORMAT
    .PixelInformation        EFI_PIXEL_BITMASK
    .PixelsPerScanLine       UINT32
}
__STRUCT__ EFI_GRAPHICS_OUTPUT_MODE_INFORMATION

struc EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE {
    .MaxMode            UINT32
    .Mode               UINT32
    .Info               PTR EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
    .SizeOfInfo         UINTN
    .FrameBufferBase    EFI_PHYSICAL_ADDRESS
    .FrameBufferSize    UINTN
}
__STRUCT__ EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE

struc EFI_GRAPHICS_OUTPUT_BLT_PIXEL {
    .Blue       UINT8
    .Green      UINT8
    .Red        UINT8
    .Reseved    UINT8
}
__STRUCT__ EFI_GRAPHICS_OUTPUT_BLT_PIXEL

; VFILL - EfiBltVideoFill
; VTOBUF - EfiBltVideoToBltBuffer
; BUFTOV - EfiBltBufferToVideo 
; VTOV - EfiBltVideoToVideo
; MAX - EfiGraphicsOutputBltOperationMax
ENUM EFI_GRAPHICS_OUTPUT_BLT_OPERATION, \
    VFILL, \
    VTOBUF, \
    BUFTOV, \
    VTOV, \
    MAX
