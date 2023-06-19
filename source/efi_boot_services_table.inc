; EFI Boot Services Table

__EFI_BOOT_SERVICES_TABLE_PTR__ PTR EFI_BOOT_SERVICES

EFI_BOOT_SERVICES_SIGNATURE fix 0x56524553544f4f42

struc EFI_BOOT_SERVICES {
    .Header EFI_TABLE_HEADER

    ; Task Priority Services
    .RaiseTPL   PTR EFI_RAISE_TPL
    .RestoreTPL PTR EFI_RESTORE_TPL

    ; Memory Services
    .AllocatePages  PTR EFI_ALLOCATE_PAGES
    .FreePages      PTR EFI_FREE_PAGES
    .GetMemoryMap   PTR EFI_GET_MEMORY_MAP
    .AllocatePool   PTR EFI_ALLOCATE_POOL
    .FreePool       PTR EFI_FREE_POOL

    ; Event & Timer Services
    .CreateEvent    PTR EFI_CREATE_EVENT
    .SetTimer       PTR EFI_SET_TIMER
    .WaitForEvent   PTR EFI_WAIT_FOR_EVENT
    .SignalEvent    PTR EFI_SIGNAL_EVENT
    .CloseEvent     PTR EFI_CLOSE_EVENT
    .CheckEvent     PTR EFI_CHECK_EVENT

    ; Protocol Handler Services
    .InstallProtocolInterface   PTR EFI_INSTALL_PROTOCOL_INTERFACE
    .ReinstallProtocolInterface PTR EFI_REINSTALL_PROTOCOL_INTERFACE
    .UninstallProtocolInterface PTR EFI_UNINSTALL_PROTOCOL_INTERFACE
    .HandleProtocol             PTR EFI_HANDLE_PROTOCOL
    .Reserved                   PTR VOID
    .RegisterProtocolNotify     PTR EFI_REGISTER_PROTOCOL_NOTIFY
    .LocateHandle               PTR EFI_LOCATE_HANDLE
    .LocateDevicePath           PTR EFI_LOCATE_DEVICE_PATH
    .InstallConfigurationTable  PTR EFI_INSTALL_CONFIGURATION_TABLE

    ; Image Services
    .LoadImage          PTR EFI_IMAGE_LOAD
    .StartImage         PTR EFI_IMAGE_START
    .Exit               PTR EFI_EXIT
    .UnloadImage        PTR EFI_IMAGE_UNLOAD
    .ExitBootServices   PTR EFI_EXIT_BOOT_SERVICES

    ; Miscellaneous Services
    .GetNextMonotonicCount  PTR EFI_GET_NEXT_MONOTONIC_COUNT
    .Stall                  PTR EFI_STALL
    .SetWatchdogTimer       PTR EFI_SET_WATCHDOG_TIMER

    ; DriverSupport Services
    .ConnectController      PTR EFI_CONNECT_CONTROLLER
    .DisconnectController   PTR EFI_DISCONNECT_CONTROLLER

    ; Open and Close Protocol Services
    .OpenProtocol               PTR EFI_OPEN_PROTOCOL
    .CloseProtocol              PTR EFI_CLOSE_PROTOCOL
    .OpenProtocolInformation    PTR EFI_OPEN_PROTOCOL_INFORMATION

    ; Library Services
    .ProtocolsPerHandle                     PTR EFI_PROTOCOLS_PER_HANDLE
    .LocateHandleBuffer                     PTR EFI_LOCATE_HANDLE_BUFFER
    .LocateProtocol                         PTR EFI_LOCATE_PROTOCOL
    .InstallMultipleProtocolInterfaces      PTR EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES
    .UninstallMultipleProtocolInterfaces    PTR EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES

    ; 32-bit CRC Services
    .CalculateCrc32 PTR EFI_CALCULATE_CRC32

    ; Miscellaneous Services
    .CopyMem        PTR EFI_COPY_MEM
    .SetMem         PTR EFI_SET_MEM
    .CreateEventEx  PTR EFI_CREATE_EVENT_EX
}
__STRUCT__ EFI_BOOT_SERVICES

macro EfiBootServices.Init {
    EfiSystemTable.GetBootServicesTable
    mov [__EFI_BOOT_SERVICES_TABLE_PTR__], rax
}

macro EfiBootServices.GetHeader {
    mov rax, [__EFI_BOOT_SERVICES_TABLE_PTR__]
}

; EFI_BOOT_SERVICES_RaiseTPL macro
__EFI_CALL_1__ EFI_BOOT_SERVICES, RaiseTPL, IN NewTPL EFI_TPL
macro EfiBootServices.RaiseTPL NewTPL {
    EFI_BOOT_SERVICES_RaiseTPL [__EFI_BOOT_SERVICES_TABLE_PTR__], NewTPL
}

; EFI_BOOT_SERVICES_RestoreTPL macro
__EFI_CALL_1__ EFI_BOOT_SERVICES, RestoreTPL, IN OldTPL
macro EfiBootServices.RestoreTPL OldTPL {
    EFI_BOOT_SERVICES_RestoreTPL [__EFI_BOOT_SERVICES_TABLE_PTR__], OldTPL
}

; EFI_BOOT_SERVICES_AllocatePages macro
__EFI_CALL_4__ EFI_BOOT_SERVICES, AllocatePages, IN Type EFI_ALLOCATE_TYPE, IN MemoryType EFI_MEMORY_TYPE, IN Pages UINTN, IN OUT Memory PTR EFI_PHYSICAL_ADDRESS
macro EfiBootServices.AllocatePages Type, MemoryType, Pages, Memory {
    EFI_BOOT_SERVICES_AllocatePages [__EFI_BOOT_SERVICES_TABLE_PTR__], Type, MemoryType, Pages, Memory
}

; EFI_BOOT_SERVICES_FreePages macro
__EFI_CALL_2__ EFI_BOOT_SERVICES, FreePages, IN Memory EFI_PHYSICAL_ADDRESS, IN Pages UINTN
macro EfiBootServices.FreePages Memory, Pages {
    EFI_BOOT_SERVICES_FreePages [__EFI_BOOT_SERVICES_TABLE_PTR__], Memory, Pages
}

; EFI_BOOT_SERVICES_GetMemoryMap macro
__EFI_CALL_5__ EFI_BOOT_SERVICES, GetMemoryMap, IN OUT MemoryMapSize PTR UINTN, IN OUT MemoryMap PTR EFI_MEMORY_DESCRIPTOR, OUT MapKey PTR UINTN, OUT DescriptorSize PTR UINTN, OUT DescriptorVersion PTR UINT32
macro EfiBootServices.GetMemoryMap MemoryMapSize, MemoryMap, MapKey, DescriptorSize, DescriptorVersion {
    EFI_BOOT_SERVICES_GetMemoryMap [__EFI_BOOT_SERVICES_TABLE_PTR__], MemoryMapSize, MemoryMap, MapKey, DescriptorSize, DescriptorVersion
}

; EFI_BOOT_SERVICES_AllocatePool macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, AllocatePool, IN PoolType EFI_MEMORY_TYPE, IN Size UINTN, OUT Buffer PTR VOID
macro EfiBootServices.AllocatePool PoolType, Size, Buffer {
    EFI_BOOT_SERVICES_AllocatePool [__EFI_BOOT_SERVICES_TABLE_PTR__], PoolType, Size, Buffer
}

; EFI_BOOT_SERVICES_FreePool macro
__EFI_CALL_1__ EFI_BOOT_SERVICES, FreePool, IN Buffer PTR VOID
macro EfiBootServices.FreePool Buffer {
    EFI_BOOT_SERVICES_FreePool [__EFI_BOOT_SERVICES_TABLE_PTR__], Buffer
}

; EFI_BOOT_SERVICES_CreateEvent macro
__EFI_CALL_5__ EFI_BOOT_SERVICES, CreateEvent, IN Type UINT32, IN NotifyTpl EFI_TLP, IN NotifyFunction EFI_EVENT_NOTIFY OPTIONAL, IN NotifyContext PTR VOID OPTIONAL, OUT Event PTR EFI_EVENT
macro EfiBootServices.CreateEvent Type, NotifyTpl, NotifyFunction, NotifyContext, Event {
    EFI_BOOT_SERVICES_CreateEvent [__EFI_BOOT_SERVICES_TABLE_PTR__], Type, NotifyTpl, NotifyFunction, NotifyContext, Event
}

; EFI_BOOT_SERVICES_SetTimer macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, SetTimer, IN Event EFI_EVENT, IN Type EFI_TIMER_DELAY, IN TriggerTime UINT64
macro EfiBootServices.SetTimer Event, Type, TriggerTime {
    EFI_BOOT_SERVICES_SetTimer [__EFI_BOOT_SERVICES_TABLE_PTR__], Event, Type, TriggerTime
}

; EFI_BOOT_SERVICES_WaitForEvent macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, WaitForEvent, IN NumberOfEvents, IN Event PTR EFI_EVENT, OUT Index PTR UINTN
macro EfiBootServices.WaitForEvent NumberOfEvents, Event, Index {
    EFI_BOOT_SERVICES_WaitForEvent [__EFI_BOOT_SERVICES_TABLE_PTR__], NumberOfEvents, Event, Index
}

; EFI_BOOT_SERVICES_SignalEvent macro
__EFI_CALL_1__ EFI_BOOT_SERVICES, SignalEvent, IN Event EFI_EVENT
macro EfiBootServices.SignalEvent Event {
    EFI_BOOT_SERVICES_SignalEvent [__EFI_BOOT_SERVICES_TABLE_PTR__], Event
}

; EFI_BOOT_SERVICES_CloseEvent macro
__EFI_CALL_1__ EFI_BOOT_SERVICES, CloseEvent, IN Event EFI_EVENT
macro EfiBootServices.CloseEvent Event {
    EFI_BOOT_SERVICES_CloseEvent [__EFI_BOOT_SERVICES_TABLE_PTR__], Event
}

; EFI_BOOT_SERVICES_CheckEvent macro
__EFI_CALL_1__ EFI_BOOT_SERVICES, CheckEvent, IN Event EFI_EVENT
macro EfiBootServices.CheckEvent Event {
    EFI_BOOT_SERVICES_CheckEvent [__EFI_BOOT_SERVICES_TABLE_PTR__], Event
}

; EFI_BOOT_SERVICES_InstallProtocolInterface macro
__EFI_CALL_4__ EFI_BOOT_SERVICES, InstallProtocolInterface, IN OUT Handle PTR EFI_HANDLE, IN Protocol PTR EFI_GUID, IN InterfaceType EFI_INTERFACE_TYPE, IN Interface PTR VOID
macro EfiBootServices.InstallProtocolInterface Handle, Protocol, InterfaceType, Interface {
    EFI_BOOT_SERVICES_InstallProtocolInterface [__EFI_BOOT_SERVICES_TABLE_PTR__], Handle, Protocol, InterfaceType, Interface
}

; EFI_BOOT_SERVICES_ReinstallProtocolInterface macro
__EFI_CALL_4__ EFI_BOOT_SERVICES, ReinstallProtocolInterface, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, IN OldInterface PTR VOID, IN NewInterface PTR VOID
macro EfiBootServices.ReinstallProtocolInterface Handle, Protocol, OldInterface, NewInterface {
    EFI_BOOT_SERVICES_ReinstallProtocolInterface [__EFI_BOOT_SERVICES_TABLE_PTR__], Handle, Protocol, OldInterface, NewInterface
}

; EFI_BOOT_SERVICES_UninstallProtocolInterface macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, UninstallProtocolInterface, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, IN Interface PTR VOID
macro EfiBootServices.UninstallProtocolInterface Handle, Protocol, Interface {
    EFI_BOOT_SERVICES_UninstallProtocolInterface [__EFI_BOOT_SERVICES_TABLE_PTR__], Handle, Protocol, Interface
}

; EFI_BOOT_SERVICES_HandleProtocol macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, HandleProtocol, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, OUT Interface PTR PTR VOID
macro EfiBootServices.HandleProtocol Handle, Protocol, Interface {
    EFI_BOOT_SERVICES_HandleProtocol [__EFI_BOOT_SERVICES_TABLE_PTR__], Handle, Protocol, Interface
}

; EFI_BOOT_SERVICES_RegisterProtocolNotify macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, RegisterProtocolNotify, IN Protocol PTR EFI_GUID, IN Event EFI_EVENT, OUT Registration PTR PTR VOID
macro EfiBootServices.RegisterProtocolNotify Protocol, Event, Registration {
    EFI_BOOT_SERVICES_RegisterProtocolNotify [__EFI_BOOT_SERVICES_TABLE_PTR__], Protocol, Event, Registration
}

; EFI_BOOT_SERVICES_LocateHandle macro
__EFI_CALL_5__ EFI_BOOT_SERVICES, LocateHandle, IN SearchType EFI_LOCATE_SEARCH_TYPE, IN Protocol PTR EFI_GUID OPTIONAL, IN SearchKey PTR VOID OPTIONAL, IN OUT BufferSize PTR UINTN, OUT Buffer PTR EFI_HANDLE
macro EfiBootServices.LocateHandle SearchType, Protocol, SearchKey, BufferSize, Buffer {
    EFI_BOOT_SERVICES_LocateHandle [__EFI_BOOT_SERVICES_TABLE_PTR__], SearchType, Protocol, SearchKey, BufferSize, Buffer
}

; EFI_BOOT_SERVICES_LocateDevicePath macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, LocateDevicePath, IN Protocol PTR EFI_GUID, IN OUT DevicePath PTR PTR EFI_DEVICE_PATH_PROTOCOL, OUT Device PTR EFI_HANDLE
macro EfiBootServices.LocateDevicePath Protocol, DevicePath, Device {
    EFI_BOOT_SERVICES_LocateDevicePath [__EFI_BOOT_SERVICES_TABLE_PTR__], Protocol, DevicePath, Device
}

; EFI_BOOT_SERVICES_InstallConfigurationTable macro
__EFI_CALL_2__ EFI_BOOT_SERVICES, InstallConfigurationTable, IN Guid PTR EFI_GUID, IN Table PTR VOID
macro EfiBootServices.InstallConfigurationTable Guid, Table {
    EFI_BOOT_SERVICES_InstallConfigurationTable [__EFI_BOOT_SERVICES_TABLE_PTR__], Guid, Table
}

; EFI_BOOT_SERVICES_LoadImage macro
__EFI_CALL_6__ EFI_BOOT_SERVICES, LoadImage, IN BootPolicy BOOLEAN, IN ParentImageHandle EFI_HANDLE, IN FilePath PTR EFI_DEVICE_PATH_PROTOCOL, IN SourceBuffer PTR VOID OPTIONAL, IN SourceSize UINTN, OUT ImageHandle PTR EFI_HANDLE
macro EfiBootServices.LoadImage BootPolicy, ParentImageHandle, FilePath, SourceBuffer, SourceSize, ImageHandle {
    EFI_BOOT_SERVICES_LoadImage [__EFI_BOOT_SERVICES_TABLE_PTR__], BootPolicy, ParentImageHandle, FilePath, SourceBuffer, SourceSize, ImageHandle
}

; EFI_BOOT_SERVICES_StartImage macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, StartImage, IN ImageHandle EFI_HANDLE, OUT ExitDataSize PTR UINTN, OUT ExitData PTR PTR CHAR16 OPTIONAL
macro EfiBootServices.StartImage ImageHandle, ExitDataSize, ExitData {
    EFI_BOOT_SERVICES_StartImage [__EFI_BOOT_SERVICES_TABLE_PTR__], ImageHandle, ExitDataSize, ExitData
}

; EFI_BOOT_SERVICES_Exit macro
__EFI_CALL_4__ EFI_BOOT_SERVICES, Exit, IN ImageHandle EFI_HANDLE, IN ExitStatus EFI_STATUS, IN ExitDataSize UINTN, IN ExitData PTR CHAR16
macro EfiBootServices.Exit ImageHandle, ExitStatus, ExitDataSize, ExitData {
    EFI_BOOT_SERVICES_Exit [__EFI_BOOT_SERVICES_TABLE_PTR__], ImageHandle, ExitStatus, ExitDataSize, ExitData
}

; EFI_BOOT_SERVICES_UnloadImage macro
__EFI_CALL_1__ EFI_BOOT_SERVICES, UnloadImage, IN ImageHandle EFI_HANDLE
macro EfiBootServices.UnloadImage ImageHandle {
    EFI_BOOT_SERVICES_UnloadImage [__EFI_BOOT_SERVICES_TABLE_PTR__], ImageHandle
}

; EFI_BOOT_SERVICES_ExitBootServices macro
__EFI_CALL_2__ EFI_BOOT_SERVICES, ExitBootServices, IN ImageHandle EFI_HANDLE, IN MapKey UINTN
macro EfiBootServices.ExitBootServices ImageHandle, MapKey {
    EFI_BOOT_SERVICES_ExitBootServices [__EFI_BOOT_SERVICES_TABLE_PTR__], ImageHandle, MapKey
}

; EFI_BOOT_SERVICES_GetNextMonotonicCount macro
__EFI_CALL_1__ EFI_BOOT_SERVICES, GetNextMonotonicCount, OUT Count PTR UINT64
macro EfiBootServices.GetNextMonotonicCount Count {
    EFI_BOOT_SERVICES_GetNextMonotonicCount [__EFI_BOOT_SERVICES_TABLE_PTR__], Count
}

; EFI_BOOT_SERVICES_Stall macro
__EFI_CALL_1__ EFI_BOOT_SERVICES, Stall, IN Microseconds UINTN
macro EfiBootServices.Stall Microseconds {
    EFI_BOOT_SERVICES_Stall [__EFI_BOOT_SERVICES_TABLE_PTR__], Microseconds
}

; EFI_BOOT_SERVICES_SetWatchdogTimer macro
__EFI_CALL_4__ EFI_BOOT_SERVICES, SetWatchdogTimer, IN Timeout UINTN, IN WatchdogCode UINT64, IN DataSize UINTN, IN WatchdogData PTR CHAR16 OPTIONAL
macro EfiBootServices.SetWatchdogTimer Timeout, WatchdogCode, DataSize, WatchdogData {
    EFI_BOOT_SERVICES_SetWatchdogTimer [__EFI_BOOT_SERVICES_TABLE_PTR__], Timeout, WatchdogCode, DataSize, WatchdogData
}

; EFI_BOOT_SERVICES_ConnectController macro
__EFI_CALL_4__ EFI_BOOT_SERVICES, ConnectController, IN ControllerHandle EFI_HANDLE, IN DriverImageHandle PTR EFI_HANDLE OPTIONAL, IN RemainingDevicePath PTR EFI_DEVICE_PATH_PROTOCOL OPTIONAL, IN Recursive BOOLEAN
macro EfiBootServices.ConnectController ControllerHandle, DriverImageHandle, RemainingDevicePath, Recursive {
    EFI_BOOT_SERVICES_ConnectController [__EFI_BOOT_SERVICES_TABLE_PTR__], ControllerHandle, DriverImageHandle, RemainingDevicePath, Recursive
}

; EFI_BOOT_SERVICES_DisconnectController macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, DisconnectController, IN ControllerHandle EFI_HANDLE, IN DriverImageHandle EFI_HANDLE OPTIONAL, IN ChildHandle EFI_HANDLE OPTIONAL
macro EfiBootServices.DisconnectController ControllerHandle, DriverImageHandle, ChildHandle {
    EFI_BOOT_SERVICES_DisconnectController [__EFI_BOOT_SERVICES_TABLE_PTR__], ControllerHandle, DriverImageHandle, ChildHandle
}

; EFI_BOOT_SERVICES_OpenProtocol macro
__EFI_CALL_6__ EFI_BOOT_SERVICES, OpenProtocol, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, OUT Interface PTR PTR VOID OPTIONAL, IN AgentHandle EFI_HANDLE, IN ControllerHandle EFI_HANDLE, IN Attributes UINT32
macro EfiBootServices.OpenProtocol Handle, Protocol, Interface, AgentHandle, ControllerHandle, Attributes {
    EFI_BOOT_SERVICES_OpenProtocol [__EFI_BOOT_SERVICES_TABLE_PTR__], Handle, Interface, AgentHandle, ControllerHandle, Attributes
}

; EFI_BOOT_SERVICES_CloseProtocol macro
__EFI_CALL_4__ EFI_BOOT_SERVICES, CloseProtocol, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, IN AgentHandle EFI_HANDLE, IN ControllerHandle EFI_HANDLE
macro EfiBootServices.CloseProtocol Handle, Protocol, AgentHandle, ControllerHandle {
    EFI_BOOT_SERVICES_CloseProtocol [__EFI_BOOT_SERVICES_TABLE_PTR__], Handle, Protocol, AgentHandle, ControllerHandle
}

; EFI_BOOT_SERVICES_OpenProtocolInformation macro
__EFI_CALL_4__ EFI_BOOT_SERVICES, OpenProtocolInformation, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, OUT EntryBuffer PTR PTR EFI_OPEN_PROTOCOL_INFORMATION_ENTRY, OUT EntryCount PTR UINTN
macro EfiBootServices.OpenProtocolInformation Handle, Protocol, EntryBuffer, EntryCount {
    EFI_BOOT_SERVICES_OpenProtocolInformation [__EFI_BOOT_SERVICES_TABLE_PTR__], Handle, Protocol, EntryBuffer, EntryCount
}

; EFI_BOOT_SERVICES_ProtocolSPerHandle macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, ProtocolsPerHandle, IN Handle EFI_HANDLE, OUT ProtocolBuffer PTR PTR PTR EFI_GUID, OUT ProtocolBufferCount PTR UINTN
macro EfiBootServices.ProtocolsPerHandle Handle, ProtocolBuffer, ProtocolBufferCount {
    EFI_BOOT_SERVICES_ProtocolSPerHandle [__EFI_BOOT_SERVICES_TABLE_PTR__], Handle, ProtocolBuffer, ProtocolsPerHandle
}

; EFI_BOOT_SERVICES_LocateHandleBuffer macro
__EFI_CALL_5__ EFI_BOOT_SERVICES, LocateHandleBuffer, IN SearchType EFI_LOCATE_SEARCH_TYPE, IN Protocol PTR EFI_GUID OPTIONAL, IN SearchKey PTR VOID OPTIONAL, IN OUT NoHandles PTR UINTN, OUT Buffer PTR PTR EFI_HANDLE
macro EfiBootServices.LocateHandleBuffer SearchType, Protocol, SearchKey, NoHandles, Buffer {
    EFI_BOOT_SERVICES_LocateHandleBuffer [__EFI_BOOT_SERVICES_TABLE_PTR__], SearchType, Protocol, SearchKey, NoHandles, Buffer
}

; EFI_BOOT_SERVICES_LocateProtocol macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, LocateProtocol, IN Protocol PTR EFI_GUID, IN Registration PTR VOID OPTIONAL, Interface PTR PTR VOID
macro EfiBootServices.LocateProtocol Protocol, Registration, Interface {
    EFI_BOOT_SERVICES_LocateProtocol [__EFI_BOOT_SERVICES_TABLE_PTR__], Protocol, Registration, Interface
}

; EFI_BOOT_SERVICES_InstallMultipleProtocolInterfaces macro
; TODO

; EFI_BOOT_SERVICES_UninstallMultipleProtocolInterfaces macro
; TODO

; EFI_BOOT_SERVICES_CalculateCrc32 macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, CalculateCrc32, IN Data PTR VOID, IN DataSize UINTN, OUT Crc32 PTR UINT32
macro EfiBootServices.CalculateCrc32 Data, DataSize, Crc32 {
    EFI_BOOT_SERVICES_CalculateCrc32 [__EFI_BOOT_SERVICES_TABLE_PTR__], Data, DataSize, Crc32
}

; EFI_BOOT_SERVICES_CopyMem macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, CopyMem, IN Destination PTR VOID, IN Source PTR VOID, IN Lenght UINTN
macro EfiBootServices.CopyMem Destination, Source, Lenght {
    EFI_BOOT_SERVICES_CopyMem [__EFI_BOOT_SERVICES_TABLE_PTR__], Destination, Source, Lenght
}

; EFI_BOOT_SERVICES_SetMem macro
__EFI_CALL_3__ EFI_BOOT_SERVICES, SetMem, IN Buffer PTR VOID, IN Size UINTN, IN Value UINT8
macro EfiBootServices.SetMem Buffer, Size, Value {
    EFI_BOOT_SERVICES_SetMem [__EFI_BOOT_SERVICES_TABLE_PTR__], Buffer, Size, Value
}

; EFI_BOOT_SERVICES_CreateEventEx macro
__EFI_CALL_6__ EFI_BOOT_SERVICES, CreateEventEx, IN Type UINT32, IN NotifyTpl EFI_TPL, IN NotifyFunction EFI_EVENT_NOTIFY OPTIONAL, IN NotifyContext PTR CONST VOID OPTIONAL, IN EventGroup PTR CONST EFI_GUID OPTIONAL, OUT Event PTR EFI_EVENT
macro EfiBootServices.CreateEventEx Type, NotifyTpl, NotifyFunction, NotifyContext, EventGroup, Event {
    EFI_BOOT_SERVICES_CreateEventEx [__EFI_BOOT_SERVICES_TABLE_PTR__], Type, NotifyTpl, NotifyFunction, NotifyContext, EventGroup, Event
}
