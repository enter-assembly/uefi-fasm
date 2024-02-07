; EFI Graphics Output

EFI_GRAPHICS_OUTPUT_GUID fix 0x9042a9de,0x23dc,0x4a38,0x96,0xfb,0x7a,0xde,0xd0,0x80,0x51,0x6a

struc EFI_GRAPHICS_OUTPUT {
    .QueryMode  PTR EFI_GRAPHICS_OUTPUT_QueryMode
    .SetMode    PTR EFI_GRAPHICS_OUTPUT_SetMode
    .Blt        PTR EFI_GRAPHICS_OUTPUT_Blt
    .ModeTable  PTR EFI_GRAPHICS_OUTPUT_MODE
}
STRUCT EFI_GRAPHICS_OUTPUT

struc EFI_GRAPHICS_OUTPUT_MODE {
    .MaxMode            UINT32A
    .Mode               UINT32A
    .Info               PTR EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
    .SizeOfInfo         UINTNA
    .FrameBufferBase    EFI_PHYSICAL_ADDRESS
    .FrameBufferSize    UINTNA
}
STRUCT EFI_GRAPHICS_OUTPUT_MODE

;RGBR     - PixelRedGreenBlueReseved8BitPerColor
;BGRR     - PixelBlueRedGreenReseved8BitPerColor
;BIT_MASK - PixelBitMask
;BLT_ONLY - PixelBltOnly
;MAX      - PixelFormatMax
__ENUM__ INT32, EFI_GRAPHICS_PIXEL_FORMAT, \
    RGBR, \
    BGRR, \
    BIT_MASK, \
    BLT_ONLY, \
    MAX

struc EFI_PIXEL_BITMASK {
    .RedMask        UINT32A
    .GreenMask      UINT32A
    .BlueMask       UINT32A
    .ResevedMask    UINT32A
}
STRUCT EFI_PIXEL_BITMASK

struc EFI_GRAPHICS_OUTPUT_MODE_INFORMATION {
    .Version                 UINT32A
    .HorisontalResolution    UINT32A
    .VerticalResolution      UINT32A
    .PixelFormat             EFI_GRAPHICS_PIXEL_FORMAT
    .PixelInformation        EFI_PIXEL_BITMASK
    .PixelsPerScanLine       UINT32A
}
STRUCT EFI_GRAPHICS_OUTPUT_MODE_INFORMATION

struc EFI_GRAPHICS_OUTPUT_BLT_PIXEL BLUE, GREEN, RED {
    .Blue       UINT8A   BLUE
    .Green      UINT8A   GREEN
    .Red        UINT8A   RED
    .Reseved    UINT8A   NULL
}
STRUCT EFI_GRAPHICS_OUTPUT_BLT_PIXEL

; VFILL - EfiBltVideoFill
; VTOBUF - EfiBltVideoToBltBuffer
; BUFTOV - EfiBltBufferToVideo 
; VTOV - EfiBltVideoToVideo
; MAX - EfiGraphicsOutputBltOperationMax
__ENUM__ INT32, EFI_GRAPHICS_OUTPUT_BLT_OPERATION, \
    VFILL, \
    VTOBUF, \
    BUFTOV, \
    VTOV, \
    MAX

macro EFI_GRAPHICS_OUTPUT_Init __NAME, __PTR {
    
    ; EFI_GRAPHICS_OUTPUT_QueryMode macro
    __EFI_CALL_4__ EFI_GRAPHICS_OUTPUT, QueryMode, IN This PTR EFI_GRAPHICS_OUTPUT, IN ModeNumber UINT32, OUT SizeOfInfo PTR UINTN, OUT Info PTR PTR EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
    macro __NAME#.#QueryMode ModeNumber, SizeOfInfo, Info \{
        EFI_GRAPHICS_OUTPUT_QueryMode [__PTR], [__PTR], ModeNumber, SizeOfInfo, Info
    \}

    ; EFI_GRAPHICS_OUTPUT_SetMode macro
    __EFI_CALL_2__ EFI_GRAPHICS_OUTPUT, SetMode, IN This PTR EFI_GRAPHICS_OUTPUT, IN ModeNumber UINT32
    macro __NAME#.#SetMode ModeNumber \{
        EFI_GRAPHICS_OUTPUT_SetMode [__PTR], [__PTR], ModeNumber
    \}

    ; EFI_GRAPHICS_OUTPUT_Blt macro
    __EFI_CALL_10__ EFI_GRAPHICS_OUTPUT, Blt, IN This PTR EFI_GRAPHICS_OUTPUT, IN OUT BltBuffer PTR EFI_GRAPHICS_OUTPUT_BLT_PIXEL OPTIONAL, IN BltOperation EFI_GRAPHICS_OUTPUT_BLT_OPERATION IN SourceX UINTN, IN SourceY UINTN, IN DestinationX UINTN, IN DestinationY UINTN, IN Width UINTN, IN Height UINTN, IN Delta UINTN OPTIONAL
    macro __NAME#.#Blt BltBuffer, BltOperation, SourceX, SourceY, DestinationX, DestinationY, Width, Height, Delta \{
        EFI_GRAPHICS_OUTPUT_Blt [__PTR], [__PTR], BltBuffer, BltOperation, SourceX, SourceY, DestinationX, DestinationY, Width, Height, Delta
    \}

    macro __NAME#.#GetModeTable \{
        mov rax, [__PTR]
        mov rax, [rax + EFI_GRAPHICS_OUTPUT.ModeTable]
    \}

    macro __NAME#.#ModeTable#.#GetMaxMode \{
        __NAME#.#GetModeTable
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE.MaxMode]
    \}
    
    macro __NAME#.#ModeTable#.#GetMode \{
        __NAME#.#GetModeTable
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE.Mode]
    \}

    macro __NAME#.#ModeTable#.#GetInfo \{
        __NAME#.#GetModeTable
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE.Info]
    \}

    macro __NAME#.#ModeTable#.#GetSizeOfInfo \{
        __NAME#.#GetModeTable
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE.SizeOfInfo]
    \}

    macro __NAME#.#ModeTable#.#GetFrameBufferBase \{
        __NAME#.#GetModeTable
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE.FrameBufferBase]
    \}

    macro __NAME#.#ModeTable#.#GetFrameBufferSize \{
        __NAME#.#GetModeTable
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE.FrameBufferSize]
    \}

    macro __NAME#.#ModeTable#.#Info#.#GetVersion \{
        __NAME#.#ModeTable#.#GetInfo
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.Version]
    \}

    macro __NAME#.#ModeTable#.#Info#.#GetHorizontalResolution \{
        __NAME#.#ModeTable#.#GetInfo
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.HorisontalResolution]
    \}

    macro __NAME#.#ModeTable#.#Info#.#GetVerticalResolution \{
        __NAME#.#ModeTable#.#GetInfo
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.VerticalResolution]
    \}

    macro __NAME#.#ModeTable#.#Info#.#GetPixelFormat \{
        __NAME#.#ModeTable#.#GetInfo
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelFormat]
    \}

    macro  __NAME#.#ModeTable#.#Info#.#GetPixelInformation \{
        __NAME#.#ModeTable#.#GetInfo
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelInformation]
    \}

    macro __NAME#.#ModeTable#.#Info#.#GetPixelsPerScanLine \{
        __NAME#.#ModeTable#.#GetInfo
        mov rax, [rax + EFI_GRAPHICS_OUTPUT_MODE_INFORMATION.PixelsPerScanLine]
    \}

}
