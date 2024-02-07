; EFI Table Header

struc EFI_TABLE_HEADER {
    .Signature  UINT64A
    .Revision   UINT32A
    .HeaderSize UINT32A
    .CRC32      UINT32A
    .Reserved   UINT32A
}
STRUCT EFI_TABLE_HEADER

macro EFI_TABLE_HEADER_CreateGetFunctions __NAME, __PTR {

    macro __NAME#.#GetHeader \{
        mov rax, [__PTR]
    \}

    macro __NAME#.#Header#.#GetSignature \{
        __NAME#.#GetHeader
        mov rax, [rax + EFI_TABLE_HEADER.Signature]
    \}

    macro __NAME#.#Header#.#GetRevision \{
        __NAME#.#GetHeader
        mov rax, [rax + EFI_TABLE_HEADER.Revision]
    \}

    macro __NAME#.#Header#.#GetHeaderSize \{
        __NAME#.#GetHeader
        mov rax, [rax + EFI_TABLE_HEADER.HeaderSize]
    \}

    macro __NAME#.#Header#.#GetCRC32 \{
        __NAME#.#GetHeader
        mov rax, [rax + EFI_TABLE_HEADER.CRC32]
    \}

}
