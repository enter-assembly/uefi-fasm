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

macro EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.GetMaxMod EfiSimpleTextOutputTablePtr {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.GetSimpleTextOutputModeTable EfiSimpleTextOutputTablePtr
    mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.MaxMode]
}

macro EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.GetMode EfiSimpleTextOutputTablePtr {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.GetSimpleTextOutputModeTable EfiSimpleTextOutputTablePtr
    mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.Mode]
}

macro EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.GetAttribute EfiSimpleTextOutputTablePtr {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.GetSimpleTextOutputModeTable EfiSimpleTextOutputTablePtr
    mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.Attribute]
}

macro EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.GetCursorColumln EfiSimpleTextOutputTablePtr {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.GetSimpleTextOutputModeTable EfiSimpleTextOutputTablePtr
    mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.CursorColumn]
}

macro EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.GetCursorRow EfiSimpleTextOutputTablePtr {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.GetSimpleTextOutputModeTable EfiSimpleTextOutputTablePtr
    mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.CursorRow]
}

macro EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.GetCursorVisible EfiSimpleTextOutputTablePtr {
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.GetSimpleTextOutputModeTable EfiSimpleTextOutputTablePtr
    mov rax, [rax + EFI_SIMPLE_TEXT_OUTPUT_MODE_TABLE.CursorVisible]
}
