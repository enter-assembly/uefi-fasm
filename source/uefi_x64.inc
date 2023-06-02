; UEFI x64 structures

include 'types_x64.inc'

EFIERR = 0x8000000000000000
EFI_SUCCESS = 0
EFI_LOAD_ERROR          = EFIERR or 1
EFI_INVALID_PARAMETER   = EFIERR or 2
EFI_UNSUPPORTED         = EFIERR or 3
EFI_BAD_BUFFER_SIZE     = EFIERR or 4
EFI_BUFFER_TOO_SMALL    = EFIERR or 5
EFI_NOT_READY           = EFIERR or 6
EFI_DEVICE_ERROR        = EFIERR or 7
EFI_WRITE_PROTECTED     = EFIERR or 8
EFI_OUT_OF_RESOURCES    = EFIERR or 9
EFI_VOLUME_CORRUPTED    = EFIERR or 10
EFI_VOLUME_FULL         = EFIERR or 11
EFI_NO_MEDIA            = EFIERR or 12
EFI_MEDIA_CHANGED       = EFIERR or 13
EFI_NOT_FOUND           = EFIERR or 14
EFI_ACCESS_DENIED       = EFIERR or 15
EFI_NO_RESPONSE         = EFIERR or 16
EFI_NO_MAPPING          = EFIERR or 17
EFI_TIMEOUT             = EFIERR or 18
EFI_NOT_STARTED         = EFIERR or 19
EFI_ALREADY_STARTED     = EFIERR or 20
EFI_ABORTED             = EFIERR or 21
EFI_ICMP_ERROR          = EFIERR or 22
EFI_TFTP_ERROR          = EFIERR or 23
EFI_PROTOCOL_ERROR      = EFIERR or 24

macro __STRUCT__ NAME {
    virtual at 0
        NAME NAME
    end virtual
}

struc EFI_SIGNATURE value {
    . UINT64 value
}

struc EFI_TABLE_HEADER {
    .Signature  UINT64
    .Revision   UINT32
    .HeaderSize UINT32
    .CRC32      UINT32
    .Reserved   UINT32
}
__STRUCT__ EFI_TABLE_HEADER

EFI_SYSTEM_TABLE_SIGNATURE fix 0x5453595320494249
struc EFI_SYSTEM_TABLE {
    .Hdr                    EFI_TABLE_HEADER
    .FirmwareVendor         PTR CHAR16
    .FirmwareRevision       UINT32
    .ConsoleInHandle        EFI_HANDLE
    .ConIn                  PTR EFI_SIMPLE_TEXT_INPUT_PROTOCOL
    .ConsoleOutHandle       EFI_HANDLE
    .ConOut                 PTR EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
    .StandardErrorHandle    EFI_HANDLE
    .StdErr                 PTR EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
    .RuntimeServices        PTR EFI_RUNTIME_SERVICES
    .BootServices           PTR EFI_BOOT_SERVICES
    .NumberOfTableEntries   UINTN
    .ConfigurationTable     PTR EFI_CONFIGURATION_TABLE
}
__STRUCT__ EFI_SYSTEM_TABLE

EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID fix 0x387477c1,0x69c7,0x11d2,0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b
struc EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    .Reset          PTR EFI_INPUT_RESET
    .ReadKeyStroke  PTR EFI_INPUT_READ_KEY
    .WaitForKey     EFI_EVENT
}
__STRUCT__ EFI_SIMPLE_TEXT_INPUT_PROTOCOL

EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID fix 0x387477c2,0x69c7,0x11d2,0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b
struc EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    .Reset              PTR EFI_TEXT_RESET
    .OutputString       PTR EFI_TEXT_STRING
    .TestString         PTR EFI_TEXT_TEST_STRING
    .QueryMode          PTR EFI_TEXT_QUERY_MODE
    .SetMode            PTR EFI_TEXT_SET_MODE
    .SetAttribute       PTR EFI_TEXT_SET_ATTRIBUTE
    .ClearScreen        PTR EFI_TEXT_CLEAR_SCREEN
    .SetCursorPosition  PTR EFI_TEXT_SET_CURSOR_POSITION
    .EnableCursor       PTR EFI_TEXT_ENABLE_CURSOR
    .Mode               PTR SIMPLE_TEXT_OUTPUT_MODE
}
__STRUCT__ EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL

struc SIMPLE_TEXT_OUTPUT_MODE {
    .MaxMode        INT32
    .Mode           INT32
    .Attribute      INT32
    .CursorColumn   INT32
    .CursorRow      INT32
    .CursorVisible  BOOLEAN
}
__STRUCT__ SIMPLE_TEXT_OUTPUT_MODE

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

EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID fix 0x9042a9de,0x23dc,0x4a38,0x96,0xfb,0x7a,0xde,0xd0,0x80,0x51,0x6a
struc EFI_GRAPHICS_OUTPUT_PROTOCOL {
    .QueryMode   PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE
    .SetMode     PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE
    .Blt         PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT
    .Mode    PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE
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
