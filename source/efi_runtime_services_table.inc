; EFI Runtime Services Table

__EFI_RUNTIME_SERVICES_TABLE_PTR__ PTR EFI_RUNTIME_SERVICES_TABLE

EFI_RUNTIME_SERVICES_SIGNATURE fix 0x56524553544e5552

struc EFI_RUNTIME_SERVICES {
    .Header    EFI_TABLE_HEADER

    ; Time services
    .GetTime        PTR EFI_GET_TIME
    .SetTime        PTR EFI_SET_TIME
    .GetWakeupTime  PTR EFI_GET_WAKEUP_TIME
    .SetWakeupTime  PTR EFI_SET_WAKEUP_TIME

    ; Virtual memory services
    .SetVirtualAddressMap   PTR EFI_SET_VIRTUAL_ADDRESS_MAP
    .ConvertPointer         PTR EFI_CONVERT_POINTER

    ; Variable services
    .GetVariable            PTR EFI_GET_VARIABLE
    .GetNextVariableName    PTR EFI GET_NEXT_VARIABLE_NAME
    .SetVariable            PTR EFI_SET_VARIABLE

    ; Miscellaneous Services
    .GetNextHighMonotonicCount  PTR EFI_GET_NEXT_HIGH_MONOTONIC_COUNT
    .ResetSystem                PTR EFI_RESET_SYSTEM

    ; UEFI 2.0 Capsule Services
    .UpdateCapsule              PTR EFI_UPDATE_CAPSULE
    .QueryCapsuleCapabilities   PTR EFI_QUERY_CAPSULE_CAPABILITIES

    ; Miscellaneous UEFI 2.0 Service
    .QueryVariableInfo  PTR EFI_QUERY_VARIABLE_INFO
}
__STRUCT__ EFI_RUNTIME_SERVICES

macro EfiRuntimeServices.Init {
    EfiSystemTable.GetRuntimeServicesTable
    mov [__EFI_RUNTIME_SERVICES_TABLE_PTR__], rax
}

macro EfiRuntimeServices.GetHeader {
    mov rax, [__EFI_RUNTIME_SERVICES_TABLE_PTR__]
}

; EFI_RUNTIME_SERVICES_GetTime macro
__EFI_CALL_2__ EFI_RUNTIME_SERVICES, GetTime, OUT Time PTR EFI_TIME, OUT Capabilities PTR EFI_TIME_CAPABILITIES OPTIONAL
macro EfiRuntimeServices.GetTime TimePtr, CapabilitiesPtr {
    EFI_RUNTIME_SERVICES_GetTime [__EFI_RUNTIME_SERVICES_TABLE_PTR__], TimePtr, CapabilitiesPtr
}

; EFI_RUNTIME_SERVICES_SetTime macro
__EFI_CALL_1__ EFI_RUNTIME_SERVICES, SetTime, IN Time PTR EFI_TIME
macro EfiRuntimeServices.SetTime TimePtr {
    EFI_RUNTIME_SERVICES_SetTime [__EFI_RUNTIME_SERVICES_TABLE_PTR__], TimePtr
}

; EFI_RUNTIME_SERVICES_GetWakeupTime macro
__EFI_CALL_3__ EFI_RUNTIME_SERVICES, GetWakeupTime, OUT Enabled PTR BOOLEAN, OUT Pending PTR BOOLEAN, OUT Time PTR EFI_TIME
macro EfiRuntimeServices.GetWakeupTime EnabledPtr, PendingPtr, TimePtr {
    EFI_RUNTIME_SERVICES_GetWakeupTime [__EFI_RUNTIME_SERVICES_TABLE_PTR__], EnabledPtr,  PendingPtr, TimePtr
}

; EFI_RUNTIME_SERVICES_SetWakeupTime macro
__EFI_CALL_2__ EFI_RUNTIME_SERVICES, SetWakeupTime, IN Enabled BOOLEAN, IN Time PTR EFI_TIME
macro EfiRuntimeServices.SetWakeupTime Enabled, TimePtr {
    EFI_RUNTIME_SERVICES_SetWakeupTime [__EFI_RUNTIME_SERVICES_TABLE_PTR__], Enabled, TimePtr
}

; EFI_RUNTIME_SERVICES_SetVirtualAddressMap macro
__EFI_CALL_4__ EFI_RUNTIME_SERVICES, SetVirtualAddressMap, IN MemoryMapSize UINTN, IN DescriptorSize UINTN, IN DescriptorVersion UINT32, IN VirtualMap PTR EFI_MEMORY_DESCRIPTOR
macro EfiRuntimeServices.SetVirtualAddressMap MemoryMapSize, DescriptorSize, DescriptorVersion, VirtualMapPtr {
    EFI_RUNTIME_SERVICES_SetVirtualAddressMap [__EFI_RUNTIME_SERVICES_TABLE_PTR__], MemoryMapSize, DescriptorSize, DescriptorVersion, VirtualMapPtr
}

; EFI_RUNTIME_SERVICES_ConvertPointer macro
__EFI_CALL_2__ EFI_RUNTIME_SERVICES, ConvertPointer, IN DebugDesposition UINTN, IN Address PTR PTR VOID
macro EfiRuntimeServices.ConvertPointer DebugDesposition, AddressPtrPtr {
    EFI_RUNTIME_SERVICES_ConvertPointer [__EFI_RUNTIME_SERVICES_TABLE_PTR__], DebugDesposition, AddressPtrPtr
}

; EFI_RUNTIME_SERVICES_GetVariable macro
__EFI_CALL_5__ EFI_RUNTIME_SERVICES, GetVariable, IN VariableName PTR CHAR16, IN VendorGuid PTR EFI_GUID, OUT Attributes PTR UINT32 OPTIONAL, IN OUT DataSize PTR UINTN, OUT Data PTR VOID
macro EfiRuntimeServices.GetVariable VariableName, VendorGuid, Attributes, DataSize, Data {
    EFI_RUNTIME_SERVICES_GetVariable [__EFI_RUNTIME_SERVICES_TABLE_PTR__], VariableName, VendorGuid, Attributes, DataSize, Data
}

; EFI_RUNTIME_SERVICES_GetNexVariableName macro
__EFI_CALL_3__ EFI_RUNTIME_SERVICES, GetNextVariableName, IN OUT VariableNameSize PTR UINTN, IN OUT VariableName PTR CHAR16, IN OUT VendorGuid PTR EFI_GUID
macro EfiRuntimeServices.GetNextVariableName VariableNameSize, VariableName, VendorGuid {
    EFI_RUNTIME_SERVICES_GetNexVariableName [__EFI_RUNTIME_SERVICES_TABLE_PTR__], VariableNameSize, VariableName, VendorGuid
}

; EFI_RUNTIME_SERVICES_SetVariable macro
__EFI_CALL_5__ EFI_RUNTIME_SERVICES, SetVariable, IN VariableName PTR CHAR16, IN VendorGuid PTR EFI_GUID, IN Attributes UINT32, IN DataSize UINTN, IN Data PTR VOID
macro EfiRuntimeServices.SetVariable VariableName, VendorGuid, Attributes, DataSize, Data {
    EFI_RUNTIME_SERVICES_SetVariable [__EFI_RUNTIME_SERVICES_TABLE_PTR__], VariableName, VendorGuid, Attributes, DataSize, Data
}

; EFI_RUNTIME_SERVICES_QueryVariableInfo macro
__EFI_CALL_4__ EFI_RUNTIME_SERVICES, QueryVariableInfo, IN Attributes UINT32, OUT MaximumVariableStorageSize PTR UINT64, OUT RemainingVariableStorageSize PTR UINT64, OUT MaximumVariableSize PTR UINT64
macro EfiRuntimeServices.QueryVariableInfo Attributes, MaximumVariableStorageSize, RemainingVariableStorageSize, MaximumVariableSize {
    EFI_RUNTIME_SERVICES_QueryVariableInfo [__EFI_RUNTIME_SERVICES_TABLE_PTR__], Attributes, MaximumVariableStorageSize, RemainingVariableStorageSize, MaximumVariableSize
}

; EFI_RUNTIME_SERVICES_GetNextHighMonotonicCount macro
__EFI_CALL_1__ EFI_RUNTIME_SERVICES, GetNextHighMonotonicCount, OUT HighCount PTR UINT32
macro EfiRuntimeServices.GetNextHighMonotonicCount HighCount {
    EFI_RUNTIME_SERVICES_GetNextHighMonotonicCount [__EFI_RUNTIME_SERVICES_TABLE_PTR__], HighCount
}

; EFI_RUNTIME_SERVICES_ResetSystem macro
__EFI_CALL_4__ EFI_RUNTIME_SERVICES, ResetSystem, IN ResetType EFI_RESET_TYPE, IN ResetStatus EFI_STATUS, IN DataSize UINTN, IN ResetData PTR VOID OPTIONAL
macro EfiRuntimeServices.ResetSystem ResetType, ResetStatus, DataSize, ResetData {
    EFI_RUNTIME_SERVICES_ResetSystem [__EFI_RUNTIME_SERVICES_TABLE_PTR__], ResetType, ResetStatus, DataSize, ResetData
}

; EFI_RUNTIME_SERVICES_UpdateCapsule macro
__EFI_CALL_3__ EFI_RUNTIME_SERVICES, UpdateCapsule, IN CapsuleHeaderArray PTR PTR EFI_CAPSULE_HEADER, IN CapsuleCount UINTN, IN ScatterGatherList EFI_PHYSICAL_ADDRESS
macro EfiRuntimeServices.UpdateCapsule CapsuleHeaderArray, CapsuleCount, ScatterGatherList {
    EFI_RUNTIME_SERVICES_UpdateCapsule [__EFI_RUNTIME_SERVICES_TABLE_PTR__], CapsuleHeaderArray, CapsuleCount, ScatterGatherList
}

; EFI_RUNTIME_SERVICES_QueryCapsuleCapabilities macro
__EFI_CALL_4__ EFI_RUNTIME_SERVICES, QueryCapsuleCapabilities, IN CapsuleHeaderArray PTR PTR EFI_CAPSULE_HEADER, IN CapsuleCount UINTN, OUT MaximumCapsuleSize PTR UINT64, OUT ResetType PTR EFI_RESET_TYPE
macro EfiRuntimeServices.QueryCapsuleCapabilities CapsuleHeaderArray, CapsuleCount, MaximumCapsuleSize, ResetType {
    EFI_RUNTIME_SERVICES_QueryCapsuleCapabilities [__EFI_RUNTIME_SERVICES_TABLE_PTR__], CapsuleHeaderArray, CapsuleCount, MaximumCapsuleSize, ResetType
}
