; EFI Runtime Services

EFI_RUNTIME_SERVICES_SIGNATURE fix 0x56524553544e5552

struc EFI_RUNTIME_SERVICES {
    .Header    EFI_TABLE_HEADER

    ; Time services
    .GetTime        PTR EFI_RUNTIME_SERVICES_GetTime
    .SetTime        PTR EFI_RUNTIME_SERVICES_SetTime
    .GetWakeupTime  PTR EFI_RUNTIME_SERVICES_GetWakeupTime
    .SetWakeupTime  PTR EFI_RUNTIME_SERVICES_SetWakeupTime

    ; Virtual memory services
    .SetVirtualAddressMap   PTR EFI_RUNTIME_SERVICES_SetVirtualAddressMap
    .ConvertPointer         PTR EFI_RUNTIME_SERVICES_ConvertPointer

    ; Variable services
    .GetVariable            PTR EFI_RUNTIME_SERVICES_GetVariable
    .GetNextVariableName    PTR EFI_RUNTIME_SERVICES_GetNexVariableName
    .SetVariable            PTR EFI_RUNTIME_SERVICES_SetVariable

    ; Miscellaneous Services
    .GetNextHighMonotonicCount  PTR EFI_RUNTIME_SERVICES_GetNextHighMonotonicCount
    .ResetSystem                PTR EFI_RUNTIME_SERVICES_ResetSystem

    ; UEFI 2.0 Capsule Services
    .UpdateCapsule              PTR EFI_RUNTIME_SERVICES_UpdateCapsule
    .QueryCapsuleCapabilities   PTR EFI_RUNTIME_SERVICES_QueryCapsuleCapabilities

    ; Miscellaneous UEFI 2.0 Service
    .QueryVariableInfo  PTR EFI_RUNTIME_SERVICES_QueryVariableInfo
}
__STRUCT__ EFI_RUNTIME_SERVICES

macro EFI_RUNTIME_SERVICES_Init __NAME, __PTR {

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

    ; EFI_RUNTIME_SERVICES_GetTime macro
    __EFI_CALL_2__ EFI_RUNTIME_SERVICES, GetTime, OUT Time PTR EFI_TIME, OUT Capabilities PTR EFI_TIME_CAPABILITIES OPTIONAL
    macro __NAME#.#GetTime TimePtr, CapabilitiesPtr \{
        EFI_RUNTIME_SERVICES_GetTime [__PTR], TimePtr, CapabilitiesPtr
    \}

    ; EFI_RUNTIME_SERVICES_SetTime macro
    __EFI_CALL_1__ EFI_RUNTIME_SERVICES, SetTime, IN Time PTR EFI_TIME
    macro __NAME#.#SetTime TimePtr \{
        EFI_RUNTIME_SERVICES_SetTime [__PTR], TimePtr
    \}

    ; EFI_RUNTIME_SERVICES_GetWakeupTime macro
    __EFI_CALL_3__ EFI_RUNTIME_SERVICES, GetWakeupTime, OUT Enabled PTR BOOLEAN, OUT Pending PTR BOOLEAN, OUT Time PTR EFI_TIME
    macro __NAME#.#GetWakeupTime EnabledPtr, PendingPtr, TimePtr \{
        EFI_RUNTIME_SERVICES_GetWakeupTime [__PTR], EnabledPtr,  PendingPtr, TimePtr
    \}

    ; EFI_RUNTIME_SERVICES_SetWakeupTime macro
    __EFI_CALL_2__ EFI_RUNTIME_SERVICES, SetWakeupTime, IN Enabled BOOLEAN, IN Time PTR EFI_TIME
    macro __NAME#.#SetWakeupTime Enabled, TimePtr \{
        EFI_RUNTIME_SERVICES_SetWakeupTime [__PTR], Enabled, TimePtr
    \}

    ; EFI_RUNTIME_SERVICES_SetVirtualAddressMap macro
    __EFI_CALL_4__ EFI_RUNTIME_SERVICES, SetVirtualAddressMap, IN MemoryMapSize UINTN, IN DescriptorSize UINTN, IN DescriptorVersion UINT32, IN VirtualMap PTR EFI_MEMORY_DESCRIPTOR
    macro __NAME#.#SetVirtualAddressMap MemoryMapSize, DescriptorSize, DescriptorVersion, VirtualMapPtr \{
        EFI_RUNTIME_SERVICES_SetVirtualAddressMap [__PTR], MemoryMapSize, DescriptorSize, DescriptorVersion, VirtualMapPtr
    \}

    ; EFI_RUNTIME_SERVICES_ConvertPointer macro
    __EFI_CALL_2__ EFI_RUNTIME_SERVICES, ConvertPointer, IN DebugDesposition UINTN, IN Address PTR PTR VOID
    macro __NAME#.#ConvertPointer DebugDesposition, AddressPtrPtr \{
        EFI_RUNTIME_SERVICES_ConvertPointer [__PTR], DebugDesposition, AddressPtrPtr
    \}

    ; EFI_RUNTIME_SERVICES_GetVariable macro
    __EFI_CALL_5__ EFI_RUNTIME_SERVICES, GetVariable, IN VariableName PTR CHAR16, IN VendorGuid PTR EFI_GUID, OUT Attributes PTR UINT32 OPTIONAL, IN OUT DataSize PTR UINTN, OUT Data PTR VOID
    macro __NAME#.#GetVariable VariableName, VendorGuid, Attributes, DataSize, Data \{
        EFI_RUNTIME_SERVICES_GetVariable [__PTR], VariableName, VendorGuid, Attributes, DataSize, Data
    \}

    ; EFI_RUNTIME_SERVICES_GetNexVariableName macro
    __EFI_CALL_3__ EFI_RUNTIME_SERVICES, GetNextVariableName, IN OUT VariableNameSize PTR UINTN, IN OUT VariableName PTR CHAR16, IN OUT VendorGuid PTR EFI_GUID
    macro __NAME#.#GetNextVariableName VariableNameSize, VariableName, VendorGuid \{
        EFI_RUNTIME_SERVICES_GetNexVariableName [__PTR], VariableNameSize, VariableName, VendorGuid
    \}

    ; EFI_RUNTIME_SERVICES_SetVariable macro
    __EFI_CALL_5__ EFI_RUNTIME_SERVICES, SetVariable, IN VariableName PTR CHAR16, IN VendorGuid PTR EFI_GUID, IN Attributes UINT32, IN DataSize UINTN, IN Data PTR VOID
    macro __NAME#.#SetVariable VariableName, VendorGuid, Attributes, DataSize, Data \{
        EFI_RUNTIME_SERVICES_SetVariable [__PTR], VariableName, VendorGuid, Attributes, DataSize, Data
    \}

    ; EFI_RUNTIME_SERVICES_GetNextHighMonotonicCount macro
    __EFI_CALL_1__ EFI_RUNTIME_SERVICES, GetNextHighMonotonicCount, OUT HighCount PTR UINT32
    macro __NAME#.#GetNextHighMonotonicCount HighCount \{
        EFI_RUNTIME_SERVICES_GetNextHighMonotonicCount [__PTR], HighCount
    \}

    ; EFI_RUNTIME_SERVICES_ResetSystem macro
    __EFI_CALL_4__ EFI_RUNTIME_SERVICES, ResetSystem, IN ResetType EFI_RESET_TYPE, IN ResetStatus EFI_STATUS, IN DataSize UINTN, IN ResetData PTR VOID OPTIONAL
    macro __NAME#.#ResetSystem ResetType, ResetStatus, DataSize, ResetData \{
        EFI_RUNTIME_SERVICES_ResetSystem [__PTR], ResetType, ResetStatus, DataSize, ResetData
    \}

    ; EFI_RUNTIME_SERVICES_UpdateCapsule macro
    __EFI_CALL_3__ EFI_RUNTIME_SERVICES, UpdateCapsule, IN CapsuleHeaderArray PTR PTR EFI_CAPSULE_HEADER, IN CapsuleCount UINTN, IN ScatterGatherList EFI_PHYSICAL_ADDRESS
    macro __NAME#.#UpdateCapsule CapsuleHeaderArray, CapsuleCount, ScatterGatherList \{
        EFI_RUNTIME_SERVICES_UpdateCapsule [__PTR], CapsuleHeaderArray, CapsuleCount, ScatterGatherList
    \}

    ; EFI_RUNTIME_SERVICES_QueryCapsuleCapabilities macro
    __EFI_CALL_4__ EFI_RUNTIME_SERVICES, QueryCapsuleCapabilities, IN CapsuleHeaderArray PTR PTR EFI_CAPSULE_HEADER, IN CapsuleCount UINTN, OUT MaximumCapsuleSize PTR UINT64, OUT ResetType PTR EFI_RESET_TYPE
    macro __NAME#.#QueryCapsuleCapabilities CapsuleHeaderArray, CapsuleCount, MaximumCapsuleSize, ResetType \{
        EFI_RUNTIME_SERVICES_QueryCapsuleCapabilities [__PTR], CapsuleHeaderArray, CapsuleCount, MaximumCapsuleSize, ResetType
    \}

    ; EFI_RUNTIME_SERVICES_QueryVariableInfo macro
    __EFI_CALL_4__ EFI_RUNTIME_SERVICES, QueryVariableInfo, IN Attributes UINT32, OUT MaximumVariableStorageSize PTR UINT64, OUT RemainingVariableStorageSize PTR UINT64, OUT MaximumVariableSize PTR UINT64
    macro __NAME#.#QueryVariableInfo Attributes, MaximumVariableStorageSize, RemainingVariableStorageSize, MaximumVariableSize \{
        EFI_RUNTIME_SERVICES_QueryVariableInfo [__PTR], Attributes, MaximumVariableStorageSize, RemainingVariableStorageSize, MaximumVariableSize
    \}

}
