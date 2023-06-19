; EFI x64 structures

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
