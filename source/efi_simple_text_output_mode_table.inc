; EFI Simple Text Output Mode Table

struc EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE {
    .MaxMode        INT32
    .Mode           INT32
    .Attribute      INT32
    .CursorColumn   INT32
    .CursorRow      INT32
    .CursorVisible  BOOLEAN
}
__STRUCT__ SIMPLE_TEXT_OUTPUT_MODE
