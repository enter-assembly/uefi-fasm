; Efi File Protocol

EFI_FILE_PROTOCOL_REVISION fix 0x00010000

struc EFI_FILE_PROTOCOL {
    .Revision       UINT64A
    .Open           PTRA EFI_FILE_PROTOCOL_Open
    .Close          PTRA EFI_FILE_PROTOCOL_Close
    .Delete         PTRA EFI_FILE_PROTOCOL_Delete
    .Read           PTRA EFI_FILE_PROTOCOL_Read
    .Write          PTRA EFI_FILE_PROTOCOL_Write
    .GetPosition    PTRA EFI_FILE_PROTOCOL_GetPosition
    .SetPosition    PTRA EFI_FILE_PROTOCOL_SetPosition
    .GetInfo        PTRA EFI_FILE_PROTOCOL_GetInfo
    .SetInfo        PTRA EFI_FILE_PROTOCOL_SetInfo
    .Flush          PTRA EFI_FILE_PROTOCOL_Flush
}
STRUCT EFI_FILE_PROTOCOL

;*******************************************************
; Open Modes
;*******************************************************
EFI_FILE_MODE_READ      = 0x0000000000000001
EFI_FILE_MODE_WRITE     = 0x0000000000000002
EFI_FILE_MODE_CREATE    = 0x8000000000000000

;*******************************************************
; File Attributes
;*******************************************************
EFI_FILE_READ_ONLY      = 0x0000000000000001
EFI_FILE_HIDDEN         = 0x0000000000000002
EFI_FILE_SYSTEM         = 0x0000000000000004
EFI_FILE_RESERVED       = 0x0000000000000008
EFI_FILE_DIRECTORY      = 0x0000000000000010
EFI_FILE_ARCHIVE        = 0x0000000000000020
EFI_FILE_VALID_ATTR     = 0x0000000000000037

EFI_FILE_INFO_ID fix 0x09576e92,0x6d3f,0x11d2,0x8e39,0x00,0xa0,0xc9,0x69,0x72,0x3b

struc EFI_FILE_INFO {
    .Size               UINT64A
    .FileSize           UINT64A
    .PhysicalSize       UINT64A
    .CreateTime         EFI_TIME
    .LastAccessTime     EFI_TIME
    .ModificationTime   EFI_TIME
    .Attribute          UINT64A
    .FileName           PTRA CHAR16
}
STRUCT EFI_FILE_INFO

EFI_FILE_SYSTEM_INFO_ID fix 0x09576e93,0x6d3f,0x11d2,0x8e39,0x00,0xa0,0xc9,0x69,0x72,0x3b

struc EFI_FILE_SYSTEM_INFO {
    .Size           UINT64A
    .ReadOnly       BOOLA
    .VolumeSize     UINT64A
    .FreeSpace      UINT64A
    .BlockSize      UINT32A
    .VolumeLabel    PTRA CHAR16
}
STRUCT EFI_FILE_SYSTEM_INFO

EFI_FILE_SYSTEM_VOLUME_LABEL_ID fix 0xDB47D7D3,0xFE81,0x11d3,0x9A35,0x00,0x90,0x27,0x3F,0xC1,0x4D

struc EFI_FILE_SYSTEM_VOLUME_LABEL {
    .VolumeLabel    PTRA CHAR16
}
STRUCT EFI_FILE_SYSTEM_VOLUME_LABEL

macro EFI_FILE_PROTOCOL_Init __NAME, __PTR {
    
    macro __NAME#.#GetRevision {
        mov rax, [__PTR]
        mov rax, [rax + EFI_FILE_PROTOCOL.Revision]
    }

    ; EFI_FILE_PROTOCOL_Open macro
    __EFI_CALL_5__ EFI_FILE_PROTOCOL, Open, IN This PTR EFI_FILE_PROTOCOL, OUT NewHandle PTR PTR EFI_FILE_PROTOCOL, IN FileName PTR CHAR16, IN OpenMode UINT64, IN Attributes UINT64
    macro __NAME#.#Open NewHandle, FileName, OpenMode, Attributes {
        EFI_FILE_PROTOCOL_Open [__PTR], [__PTR], NewHandle, FileName, OpenMode, Attributes
    }

    ; EFI_FILE_PROTOCOL_Close macro
    __EFI_CALL_1__ EFI_FILE_PROTOCOL, Close, IN This PTR EFI_FILE_PROTOCOL
    macro __NAME#.#Close {
        EFI_FILE_PROTOCOL_Close [__PTR], [__PTR]
    }

    ; EFI_FILE_PROTOCOL_Delete macro
    __EFI_CALL_1__ EFI_FILE_PROTOCOL, Delete, IN This PTR EFI_FILE_PROTOCOL
    macro __NAME#.#Delete {
        EFI_FILE_PROTOCOL_Delete [__PTR], [__PTR]
    }

    ; EFI_FILE_PROTOCOL_Read macro
    __EFI_CALL_3__ EFI_FILE_PROTOCOL, Read, IN This PTR EFI_FILE_PROTOCOL, IN OUT BufferSize PTR UINTN, OUT Buffer PTR VOID
    macro __NAME#.#Read BufferSize, Buffer {
        EFI_FILE_PROTOCOL_Read [__PTR], [__PTR], BufferSize, Buffer
    }

    ; EFI_FILE_PROTOCOL_Write macro
    __EFI_CALL_3__ EFI_FILE_PROTOCOL, Write, IN This PTR EFI_FILE_PROTOCOL, IN OUT BufferSize PTR UINTN, IN Buffer PTR VOID
    macro __NAME#.#Write BufferSize, Buffer {
        EFI_FILE_PROTOCOL_Write [__PTR], [__PTR], BufferSize, Buffer
    }

    ; EFI_FILE_PROTOCOL_SetPosition macro
    __EFI_CALL_2__ EFI_FILE_PROTOCOL, SetPosition, IN This PTR EFI_FILE_PROTOCOL, IN Position UINT64
    macro __NAME#.SetPosition Position {
        EFI_FILE_PROTOCOL_SetPosition [__PTR], [__PTR], Position
    }

    ; EFI_FILE_PROTOCOL_GetPosition macro
    __EFI_CALL_2__ EFI_FILE_PROTOCOL, GetPosition, IN This PTR EFI_FILE_PROTOCOL, OUT Position PTR UINT64
    macro __NAME#.GetPosition Position {
        EFI_FILE_PROTOCOL_GetPosition [__PTR], [__PTR], Position
    }

    ; EFI_FILE_PROTOCOL_GetInfo macro
    __EFI_CALL_4__ EFI_FILE_PROTOCOL, GetInfo, IN This PTR EFI_FILE_PROTOCOL, IN InformationType PTR EFI_GUID, IN OUT BufferSize PTR UINTN, OUT Buffer PTR VOID
    macro __NAME#.#GetInfo InformationType, BufferSize, Buffer {
        EFI_FILE_PROTOCOL_GetInfo [__PTR], [__PTR], InformationType, BufferSize, Buffer
    }

    ; EFI_FILE_PROTOCOL_SetInfo macro
    __EFI_CALL_4__ EFI_FILE_PROTOCOL, SetInfo, IN This PTR EFI_FILE_PROTOCOL, IN InformationType PTR EFI_GUID, IN BufferSize UINTN, IN Buffer PTR VOID
    macro __NAME#.#SetInfo InformationType, BufferSize, Buffer {
        EFI_FILE_PROTOCOL_SetInfo [__PTR], [__PTR], InformationType, BufferSize, Buffer
    }

    ; EFI_FILE_PROTOCOL_Flush macro
    __EFI_CALL_1__ EFI_FILE_PROTOCOL, Flush, IN This PTR EFI_FILE_PROTOCOL
    macro __NAME#.#Flush {
        EFI_FILE_PROTOCOL_Flush [__PTR], [__PTR]
    }

}
