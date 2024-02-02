; EFI Table Header

struc EFI_TABLE_HEADER {
    .Signature  UINT64
    .Revision   UINT32
    .HeaderSize UINT32
    .CRC32      UINT32
    .Reserved   UINT32
}
__STRUCT__ EFI_TABLE_HEADER
