; EFI Graphics Output Protocol

EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID fix 0x9042a9de,0x23dc,0x4a38,0x96,0xfb,0x7a,0xde,0xd0,0x80,0x51,0x6a

struc EFI_GRAPHICS_OUTPUT_PROTOCOL {
    .QueryMode  PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE
    .SetMode    PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE
    .Blt        PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT
    .ModeTable  PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE
}
__STRUCT__ EFI_GRAPHICS_OUTPUT_PROTOCOL

; EFI_GRAPHICS_OUTPUT_PROTOCOL_QueryMode macro
__EFI_CALL_4__ EFI_GRAPHICS_OUTPUT_PROTOCOL, QueryMode, IN This PTR EFI_GRAPHICS_OUTPUT_PROTOCOL, IN ModeNumber UINT32, OUT SizeOfInfo PTR UINTN, OUT Info PTR PTR EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE_INFORMATION

; EFI_GRAPHICS_OUTPUT_PROTOCOL_SetMode macro
__EFI_CALL_2__ EFI_GRAPHICS_OUTPUT_PROTOCOL, SetMode, IN This PTR EFI_GRAPHICS_OUTPUT_PROTOCOL, IN ModeNumber UINT32

; EFI_GRAPHICS_OUTPUT_PROTOCOL_Blt macro
__EFI_CALL_10__ EFI_GRAPHICS_OUTPUT_PROTOCOL, Blt, IN This PTR EFI_GRAPHICS_OUTPUT_PROTOCOL, IN OUT BltBuffer PTR EFI_GRAPHICS_OUTPUT_BLT_PIXEL OPTIONAL, IN BltOperation EFI_GRAPHICS_OUTPUT_BLT_OPERATION \
    IN SourceX UINTN, IN SourceY UINTN, IN DestinationX UINTN, IN DestinationY UINTN, IN Width UINTN, IN Height UINTN, IN Delta UINTN OPTIONAL

macro EFI_GRAPHICS_OUTPUT_PROTOCOL.GetModeTable GopTable {
    mov rax, GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_PROTOCOL.ModeTable]
}

EFI_GRAPHICS_OUTPUT_PROTOCOL.InitTable TableName, Table {

    macro TableName#.#QueryMode ModeNumber, SizeOfInfo, Info {
        EFI_GRAPHICS_OUTPUT_PROTOCOL_QueryMode [Table], [Table], ModeNumber, SizeOfInfo, Info
    }

    macro TableName#.#SetMode ModeNumber {
        EFI_GRAPHICS_OUTPUT_PROTOCOL_SetMode [Table], [Table], ModeNumber
    }

    macro TableName#.#Blt BltBuffer, BltOperation, SourceX, SourceY, DestinationX, DestinationY, Width, Height, Delta {
        EFI_GRAPHICS_OUTPUT_PROTOCOL_Blt [Table], [Table], BltBuffer, BltOperation, SourceX, SourceY, DestinationX, DestinationY, Width, Height, Delta
    }

    macro TableName#.#GetModeTable {
        EFI_GRAPHICS_OUTPUT_PROTOCOL.GetModeTable [Table]
    }
}

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

macro EfiGraphicsOutputModeInformation.GetVersion GopTable {
    EfiGraphicsOutputMode.GetInfo GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.Version]
}

macro EfiGraphicsOutputModeInformation.GetHorizontalResolution GopTable {
    EfiGraphicsOutputMode.GetInfo GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.HorisontalResolution]
}

macro EfiGraphicsOutputModeInformation.GetVerticalResolution GopTable {
    EfiGraphicsOutputMode.GetInfo GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.VerticalResolution]
}

macro EfiGraphicsOutputModeInformation.GetPixelFormat GopTable {
    EfiGraphicsOutputMode.GetInfo GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelFormat]
}

macro EfiGraphicsOutputModeInformation.GetPixelInformation GopTable {
    EfiGraphicsOutputMode.GetInfo GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelInformation]
}

macro EfiGraphicsOutputModeInformation.GetPixelsPerScanLine GopTable {
    EfiGraphicsOutputMode.GetInfo GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelsPerScanLine]
}

struc EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE {
    .MaxMode            UINT32
    .Mode               UINT32
    .Info               PTR EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
    .SizeOfInfo         UINTN
    .FrameBufferBase    EFI_PHYSICAL_ADDRESS
    .FrameBufferSize    UINTN
}
__STRUCT__ EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE

macro EfiGraphicsOutputMode.GetMaxMode GopTable {
    EFI_GRAPHICS_OUTPUT_PROTOCOL.GetModeTable GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.MaxMode]
}

macro EfiGraphicsOutputMode.GetMode GopTable {
    EFI_GRAPHICS_OUTPUT_PROTOCOL.GetModeTable GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.Mode]
}

macro EfiGraphicsOutputMode.GetInfo GopTable {
    EFI_GRAPHICS_OUTPUT_PROTOCOL.GetModeTable GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.Info]
}

macro EfiGraphicsOutputMode.GetSizeOfInfo GopTable {
    EFI_GRAPHICS_OUTPUT_PROTOCOL.GetModeTable GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.SizeOfInfo]
}

macro EfiGraphicsOutputMode.GetFrameBufferBase GopTable {
    EFI_GRAPHICS_OUTPUT_PROTOCOL.GetModeTable GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.FrameBufferBase]
}

macro EfiGraphicsOutputMode.GetFrameBufferSize GopTable {
    EFI_GRAPHICS_OUTPUT_PROTOCOL.GetModeTable GopTable
    mov rax, [rax + EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE.FrameBufferSize]
}

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
