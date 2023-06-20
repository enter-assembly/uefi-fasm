; EFI Table Header

macro __STRUCT__ NAME {
    virtual at 0
        NAME NAME
    end virtual
}

struc EFI_TABLE_HEADER {
    .Signature  UINT64
    .Revision   UINT32
    .HeaderSize UINT32
    .CRC32      UINT32
    .Reserved   UINT32
}
__STRUCT__ EFI_TABLE_HEADER

macro EfiTableHeader.GetSignature Table {
    mov rax, Table
    mov rax, [rax + EFI_TABLE_HEADER.Signature]
}

macro EfiTableHeader.GetRevision Table {
    mov rax, Table
    mov rax, [rax + EFI_TABLE_HEADER.Revision]
}

macro EfiTableHeader.GetHeaderSize Table {
    mov rax, Table
    mov rax, [rax + EFI_TABLE_HEADER.HeaderSize]
}

macro EfiTableHeader.GetCRC32 Table {
    mov rax, Table
    mov rax, [rax + EFI_TABLE_HEADER.CRC32]
}
