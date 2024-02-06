; EFI Boot Services

EFI_BOOT_SERVICES_SIGNATURE fix 0x56524553544f4f42

struc EFI_BOOT_SERVICES {
    .Header EFI_TABLE_HEADER

    ; Task Priority Services
    .RaiseTPL   PTR EFI_BOOT_SERVICES_RaiseTPL
    .RestoreTPL PTR EFI_BOOT_SERVICES_RestoreTPL

    ; Memory Services
    .AllocatePages  PTR EFI_BOOT_SERVICES_AllocatePages
    .FreePages      PTR EFI_BOOT_SERVICES_FreePages
    .GetMemoryMap   PTR EFI_BOOT_SERVICES_GetMemoryMap
    .AllocatePool   PTR EFI_BOOT_SERVICES_AllocatePool
    .FreePool       PTR EFI_BOOT_SERVICES_FreePool

    ; Event & Timer Services
    .CreateEvent    PTR EFI_BOOT_SERVICES_CreateEvent
    .SetTimer       PTR EFI_BOOT_SERVICES_SetTimer
    .WaitForEvent   PTR EFI_BOOT_SERVICES_WaitForEvent
    .SignalEvent    PTR EFI_BOOT_SERVICES_SignalEvent
    .CloseEvent     PTR EFI_BOOT_SERVICES_CloseEvent
    .CheckEvent     PTR EFI_BOOT_SERVICES_CheckEvent

    ; Protocol Handler Services
    .InstallProtocolInterface   PTR EFI_BOOT_SERVICES_InstallProtocolInterface
    .ReinstallProtocolInterface PTR EFI_BOOT_SERVICES_ReinstallProtocolInterface
    .UninstallProtocolInterface PTR EFI_BOOT_SERVICES_UninstallProtocolInterface
    .HandleProtocol             PTR EFI_BOOT_SERVICES_HandleProtocol
    .Reserved                   PTR VOID
    .RegisterProtocolNotify     PTR EFI_BOOT_SERVICES_RegisterProtocolNotify
    .LocateHandle               PTR EFI_BOOT_SERVICES_LocateHandle
    .LocateDevicePath           PTR EFI_BOOT_SERVICES_LocateDevicePath
    .InstallConfigurationTable  PTR EFI_BOOT_SERVICES_InstallConfigurationTable

    ; Image Services
    .LoadImage          PTR EFI_BOOT_SERVICES_LoadImage
    .StartImage         PTR EFI_BOOT_SERVICES_StartImage
    .Exit               PTR EFI_BOOT_SERVICES_Exit
    .UnloadImage        PTR EFI_BOOT_SERVICES_UnloadImage
    .ExitBootServices   PTR EFI_BOOT_SERVICES_ExitBootServices

    ; Miscellaneous Services
    .GetNextMonotonicCount  PTR EFI_BOOT_SERVICES_GetNextMonotonicCount
    .Stall                  PTR EFI_BOOT_SERVICES_Stall
    .SetWatchdogTimer       PTR EFI_BOOT_SERVICES_SetWatchdogTimer

    ; DriverSupport Services
    .ConnectController      PTR EFI_BOOT_SERVICES_ConnectController
    .DisconnectController   PTR EFI_BOOT_SERVICES_DisconnectController

    ; Open and Close Protocol Services
    .OpenProtocol               PTR EFI_BOOT_SERVICES_OpenProtocol
    .CloseProtocol              PTR EFI_BOOT_SERVICES_CloseProtocol
    .OpenProtocolInformation    PTR EFI_BOOT_SERVICES_OpenProtocolInformation

    ; Library Services
    .ProtocolsPerHandle                     PTR EFI_BOOT_SERVICES_ProtocolSPerHandle
    .LocateHandleBuffer                     PTR EFI_BOOT_SERVICES_LocateHandleBuffer
    .LocateProtocol                         PTR EFI_BOOT_SERVICES_LocateProtocol
    .InstallMultipleProtocolInterfaces      PTR EFI_BOOT_SERVICES_InstallMultipleProtocolInterfaces
    .UninstallMultipleProtocolInterfaces    PTR EFI_BOOT_SERVICES_UninstallMultipleProtocolInterfaces

    ; 32-bit CRC Services
    .CalculateCrc32 PTR EFI_BOOT_SERVICES_CalculateCrc32

    ; Miscellaneous Services
    .CopyMem        PTR EFI_BOOT_SERVICES_CopyMem
    .SetMem         PTR EFI_BOOT_SERVICES_SetMem
    .CreateEventEx  PTR EFI_BOOT_SERVICES_CreateEventEx
}
__STRUCT__ EFI_BOOT_SERVICES

macro EFI_BOOT_SERVICES_Init __NAME, __PTR {

    EFI_TABLE_HEADER_CreateGetFunctions __NAME, __PTR

    ; EFI_BOOT_SERVICES_RaiseTPL macro
    __EFI_CALL_1__ EFI_BOOT_SERVICES, RaiseTPL, IN NewTPL EFI_TPL
    macro __NAME#.#RaiseTPL NewTPL \{
        EFI_BOOT_SERVICES_RaiseTPL [__PTR], NewTPL
    \}

    ; EFI_BOOT_SERVICES_RestoreTPL macro
    __EFI_CALL_1__ EFI_BOOT_SERVICES, RestoreTPL, IN OldTPL
    macro __NAME#.#RestoreTPL OldTPL \{
        EFI_BOOT_SERVICES_RestoreTPL [__PTR], OldTPL
    \}

    ; EFI_BOOT_SERVICES_AllocatePages macro
    __EFI_CALL_4__ EFI_BOOT_SERVICES, AllocatePages, IN Type EFI_ALLOCATE_TYPE, IN MemoryType EFI_MEMORY_TYPE, IN Pages UINTN, IN OUT Memory PTR EFI_PHYSICAL_ADDRESS
    macro __NAME#.#AllocatePages Type, MemoryType, Pages, Memory \{
        EFI_BOOT_SERVICES_AllocatePages [__PTR], Type, MemoryType, Pages, Memory
    \}

    ; EFI_BOOT_SERVICES_FreePages macro
    __EFI_CALL_2__ EFI_BOOT_SERVICES, FreePages, IN Memory EFI_PHYSICAL_ADDRESS, IN Pages UINTN
    macro __NAME#.#FreePages Memory, Pages \{
        EFI_BOOT_SERVICES_FreePages [__PTR], Memory, Pages
    \}

    ; EFI_BOOT_SERVICES_GetMemoryMap macro
    __EFI_CALL_5__ EFI_BOOT_SERVICES, GetMemoryMap, IN OUT MemoryMapSize PTR UINTN, IN OUT MemoryMap PTR EFI_MEMORY_DESCRIPTOR, OUT MapKey PTR UINTN, OUT DescriptorSize PTR UINTN, OUT DescriptorVersion PTR UINT32
    macro __NAME#.#GetMemoryMap MemoryMapSize, MemoryMap, MapKey, DescriptorSize, DescriptorVersion \{
        EFI_BOOT_SERVICES_GetMemoryMap [__PTR], MemoryMapSize, MemoryMap, MapKey, DescriptorSize, DescriptorVersion
    \}

    ; EFI_BOOT_SERVICES_AllocatePool macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, AllocatePool, IN PoolType EFI_MEMORY_TYPE, IN Size UINTN, OUT Buffer PTR VOID
    macro __NAME#.#AllocatePool PoolType, Size, Buffer \{
        EFI_BOOT_SERVICES_AllocatePool [__PTR], PoolType, Size, Buffer
    \}

    ; EFI_BOOT_SERVICES_FreePool macro
    __EFI_CALL_1__ EFI_BOOT_SERVICES, FreePool, IN Buffer PTR VOID
    macro __NAME#.#FreePool Buffer \{
        EFI_BOOT_SERVICES_FreePool [__PTR], Buffer
    \}

    ; EFI_BOOT_SERVICES_CreateEvent macro
    __EFI_CALL_5__ EFI_BOOT_SERVICES, CreateEvent, IN Type UINT32, IN NotifyTpl EFI_TLP, IN NotifyFunction EFI_EVENT_NOTIFY OPTIONAL, IN NotifyContext PTR VOID OPTIONAL, OUT Event PTR EFI_EVENT
    macro __NAME#.#CreateEvent Type, NotifyTpl, NotifyFunction, NotifyContext, Event \{
        EFI_BOOT_SERVICES_CreateEvent [__PTR], Type, NotifyTpl, NotifyFunction, NotifyContext, Event
    \}

    ; EFI_BOOT_SERVICES_SetTimer macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, SetTimer, IN Event EFI_EVENT, IN Type EFI_TIMER_DELAY, IN TriggerTime UINT64
    macro __NAME#.#SetTimer Event, Type, TriggerTime \{
        EFI_BOOT_SERVICES_SetTimer [__PTR], Event, Type, TriggerTime
    \}

    ; EFI_BOOT_SERVICES_WaitForEvent macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, WaitForEvent, IN NumberOfEvents, IN Event PTR EFI_EVENT, OUT Index PTR UINTN
    macro __NAME#.#WaitForEvent NumberOfEvents, Event, Index \{
        EFI_BOOT_SERVICES_WaitForEvent [__PTR], NumberOfEvents, Event, Index
    \}

    ; EFI_BOOT_SERVICES_SignalEvent macro
    __EFI_CALL_1__ EFI_BOOT_SERVICES, SignalEvent, IN Event EFI_EVENT
    macro __NAME#.#SignalEvent Event \{
        EFI_BOOT_SERVICES_SignalEvent [__PTR], Event
    \}

    ; EFI_BOOT_SERVICES_CloseEvent macro
    __EFI_CALL_1__ EFI_BOOT_SERVICES, CloseEvent, IN Event EFI_EVENT
    macro __NAME#.#CloseEvent Event \{
        EFI_BOOT_SERVICES_CloseEvent [__PTR], Event
    \}

    ; EFI_BOOT_SERVICES_CheckEvent macro
    __EFI_CALL_1__ EFI_BOOT_SERVICES, CheckEvent, IN Event EFI_EVENT
    macro __NAME#.#CheckEvent Event \{
        EFI_BOOT_SERVICES_CheckEvent [__PTR], Event
    \}

    ; EFI_BOOT_SERVICES_InstallProtocolInterface macro
    __EFI_CALL_4__ EFI_BOOT_SERVICES, InstallProtocolInterface, IN OUT Handle PTR EFI_HANDLE, IN Protocol PTR EFI_GUID, IN InterfaceType EFI_INTERFACE_TYPE, IN Interface PTR VOID
    macro __NAME#.#InstallProtocolInterface Handle, Protocol, InterfaceType, Interface \{
        EFI_BOOT_SERVICES_InstallProtocolInterface [__PTR], Handle, Protocol, InterfaceType, Interface
    \}

    ; EFI_BOOT_SERVICES_ReinstallProtocolInterface macro
    __EFI_CALL_4__ EFI_BOOT_SERVICES, ReinstallProtocolInterface, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, IN OldInterface PTR VOID, IN NewInterface PTR VOID
    macro __NAME#.#ReinstallProtocolInterface Handle, Protocol, OldInterface, NewInterface \{
        EFI_BOOT_SERVICES_ReinstallProtocolInterface [__PTR], Handle, Protocol, OldInterface, NewInterface
    \}

    ; EFI_BOOT_SERVICES_UninstallProtocolInterface macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, UninstallProtocolInterface, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, IN Interface PTR VOID
    macro __NAME#.#UninstallProtocolInterface Handle, Protocol, Interface \{
        EFI_BOOT_SERVICES_UninstallProtocolInterface [__PTR], Handle, Protocol, Interface
    \}

    ; EFI_BOOT_SERVICES_HandleProtocol macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, HandleProtocol, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, OUT Interface PTR PTR VOID
    macro __NAME#.#HandleProtocol Handle, Protocol, Interface \{
        EFI_BOOT_SERVICES_HandleProtocol [__PTR], Handle, Protocol, Interface
    \}

    ; EFI_BOOT_SERVICES_RegisterProtocolNotify macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, RegisterProtocolNotify, IN Protocol PTR EFI_GUID, IN Event EFI_EVENT, OUT Registration PTR PTR VOID
    macro __NAME#.#RegisterProtocolNotify Protocol, Event, Registration \{
        EFI_BOOT_SERVICES_RegisterProtocolNotify [__PTR], Protocol, Event, Registration
    \}

    ; EFI_BOOT_SERVICES_LocateHandle macro
    __EFI_CALL_5__ EFI_BOOT_SERVICES, LocateHandle, IN SearchType EFI_LOCATE_SEARCH_TYPE, IN Protocol PTR EFI_GUID OPTIONAL, IN SearchKey PTR VOID OPTIONAL, IN OUT BufferSize PTR UINTN, OUT Buffer PTR EFI_HANDLE
    macro __NAME#.#LocateHandle SearchType, Protocol, SearchKey, BufferSize, Buffer \{
        EFI_BOOT_SERVICES_LocateHandle [__PTR], SearchType, Protocol, SearchKey, BufferSize, Buffer
    \}

    ; EFI_BOOT_SERVICES_LocateDevicePath macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, LocateDevicePath, IN Protocol PTR EFI_GUID, IN OUT DevicePath PTR PTR EFI_DEVICE_PATH_PROTOCOL, OUT Device PTR EFI_HANDLE
    macro __NAME#.#LocateDevicePath Protocol, DevicePath, Device \{
        EFI_BOOT_SERVICES_LocateDevicePath [__PTR], Protocol, DevicePath, Device
    \}

    ; EFI_BOOT_SERVICES_InstallConfigurationTable macro
    __EFI_CALL_2__ EFI_BOOT_SERVICES, InstallConfigurationTable, IN Guid PTR EFI_GUID, IN Table PTR VOID
    macro __NAME#.#InstallConfigurationTable Guid, Table \{
        EFI_BOOT_SERVICES_InstallConfigurationTable [__PTR], Guid, Table
    \}

    ; EFI_BOOT_SERVICES_LoadImage macro
    __EFI_CALL_6__ EFI_BOOT_SERVICES, LoadImage, IN BootPolicy BOOLEAN, IN ParentImageHandle EFI_HANDLE, IN FilePath PTR EFI_DEVICE_PATH_PROTOCOL, IN SourceBuffer PTR VOID OPTIONAL, IN SourceSize UINTN, OUT ImageHandle PTR EFI_HANDLE
    macro __NAME#.#LoadImage BootPolicy, ParentImageHandle, FilePath, SourceBuffer, SourceSize, ImageHandle \{
        EFI_BOOT_SERVICES_LoadImage [__PTR], BootPolicy, ParentImageHandle, FilePath, SourceBuffer, SourceSize, ImageHandle
    \}

    ; EFI_BOOT_SERVICES_StartImage macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, StartImage, IN ImageHandle EFI_HANDLE, OUT ExitDataSize PTR UINTN, OUT ExitData PTR PTR CHAR16 OPTIONAL
    macro __NAME#.#StartImage ImageHandle, ExitDataSize, ExitData \{
        EFI_BOOT_SERVICES_StartImage [__PTR], ImageHandle, ExitDataSize, ExitData
    \}

    ; EFI_BOOT_SERVICES_Exit macro
    __EFI_CALL_4__ EFI_BOOT_SERVICES, Exit, IN ImageHandle EFI_HANDLE, IN ExitStatus EFI_STATUS, IN ExitDataSize UINTN, IN ExitData PTR CHAR16
    macro __NAME#.#Exit ImageHandle, ExitStatus, ExitDataSize, ExitData \{
        EFI_BOOT_SERVICES_Exit [__PTR], ImageHandle, ExitStatus, ExitDataSize, ExitData
    \}

    ; EFI_BOOT_SERVICES_UnloadImage macro
    __EFI_CALL_1__ EFI_BOOT_SERVICES, UnloadImage, IN ImageHandle EFI_HANDLE
    macro __NAME#.#UnloadImage ImageHandle \{
        EFI_BOOT_SERVICES_UnloadImage [__PTR], ImageHandle
    \}

    ; EFI_BOOT_SERVICES_ExitBootServices macro
    __EFI_CALL_2__ EFI_BOOT_SERVICES, ExitBootServices, IN ImageHandle EFI_HANDLE, IN MapKey UINTN
    macro __NAME#.#ExitBootServices ImageHandle, MapKey \{
        EFI_BOOT_SERVICES_ExitBootServices [__PTR], ImageHandle, MapKey
    \}

    ; EFI_BOOT_SERVICES_GetNextMonotonicCount macro
    __EFI_CALL_1__ EFI_BOOT_SERVICES, GetNextMonotonicCount, OUT Count PTR UINT64
    macro __NAME#.#GetNextMonotonicCount Count \{
        EFI_BOOT_SERVICES_GetNextMonotonicCount [__PTR], Count
    \}

    ; EFI_BOOT_SERVICES_Stall macro
    __EFI_CALL_1__ EFI_BOOT_SERVICES, Stall, IN Microseconds UINTN
    macro __NAME#.#Stall Microseconds \{
        EFI_BOOT_SERVICES_Stall [__PTR], Microseconds
    \}

    ; EFI_BOOT_SERVICES_SetWatchdogTimer macro
    __EFI_CALL_4__ EFI_BOOT_SERVICES, SetWatchdogTimer, IN Timeout UINTN, IN WatchdogCode UINT64, IN DataSize UINTN, IN WatchdogData PTR CHAR16 OPTIONAL
    macro __NAME#.#SetWatchdogTimer Timeout, WatchdogCode, DataSize, WatchdogData \{
        EFI_BOOT_SERVICES_SetWatchdogTimer [__PTR], Timeout, WatchdogCode, DataSize, WatchdogData
    \}

    ; EFI_BOOT_SERVICES_ConnectController macro
    __EFI_CALL_4__ EFI_BOOT_SERVICES, ConnectController, IN ControllerHandle EFI_HANDLE, IN DriverImageHandle PTR EFI_HANDLE OPTIONAL, IN RemainingDevicePath PTR EFI_DEVICE_PATH_PROTOCOL OPTIONAL, IN Recursive BOOLEAN
    macro __NAME#.#ConnectController ControllerHandle, DriverImageHandle, RemainingDevicePath, Recursive \{
        EFI_BOOT_SERVICES_ConnectController [__PTR], ControllerHandle, DriverImageHandle, RemainingDevicePath, Recursive
    \}

    ; EFI_BOOT_SERVICES_DisconnectController macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, DisconnectController, IN ControllerHandle EFI_HANDLE, IN DriverImageHandle EFI_HANDLE OPTIONAL, IN ChildHandle EFI_HANDLE OPTIONAL
    macro __NAME#.#DisconnectController ControllerHandle, DriverImageHandle, ChildHandle \{
        EFI_BOOT_SERVICES_DisconnectController [__PTR], ControllerHandle, DriverImageHandle, ChildHandle
    \}

    ; EFI_BOOT_SERVICES_OpenProtocol macro
    __EFI_CALL_6__ EFI_BOOT_SERVICES, OpenProtocol, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, OUT Interface PTR PTR VOID OPTIONAL, IN AgentHandle EFI_HANDLE, IN ControllerHandle EFI_HANDLE, IN Attributes UINT32
    macro __NAME#.#OpenProtocol Handle, Protocol, Interface, AgentHandle, ControllerHandle, Attributes \{
        EFI_BOOT_SERVICES_OpenProtocol [__PTR], Handle, Interface, AgentHandle, ControllerHandle, Attributes
    \}

    ; EFI_BOOT_SERVICES_CloseProtocol macro
    __EFI_CALL_4__ EFI_BOOT_SERVICES, CloseProtocol, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, IN AgentHandle EFI_HANDLE, IN ControllerHandle EFI_HANDLE
    macro __NAME#.#CloseProtocol Handle, Protocol, AgentHandle, ControllerHandle \{
        EFI_BOOT_SERVICES_CloseProtocol [__PTR], Handle, Protocol, AgentHandle, ControllerHandle
    \}

    ; EFI_BOOT_SERVICES_OpenProtocolInformation macro
    __EFI_CALL_4__ EFI_BOOT_SERVICES, OpenProtocolInformation, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, OUT EntryBuffer PTR PTR EFI_OPEN_PROTOCOL_INFORMATION_ENTRY, OUT EntryCount PTR UINTN
    macro __NAME#.#OpenProtocolInformation Handle, Protocol, EntryBuffer, EntryCount \{
        EFI_BOOT_SERVICES_OpenProtocolInformation [__PTR], Handle, Protocol, EntryBuffer, EntryCount
    \}

    ; EFI_BOOT_SERVICES_ProtocolSPerHandle macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, ProtocolsPerHandle, IN Handle EFI_HANDLE, OUT ProtocolBuffer PTR PTR PTR EFI_GUID, OUT ProtocolBufferCount PTR UINTN
    macro __NAME#.#ProtocolsPerHandle Handle, ProtocolBuffer, ProtocolBufferCount \{
        EFI_BOOT_SERVICES_ProtocolSPerHandle [__PTR], Handle, ProtocolBuffer, ProtocolsPerHandle
    \}

    ; EFI_BOOT_SERVICES_LocateHandleBuffer macro
    __EFI_CALL_5__ EFI_BOOT_SERVICES, LocateHandleBuffer, IN SearchType EFI_LOCATE_SEARCH_TYPE, IN Protocol PTR EFI_GUID OPTIONAL, IN SearchKey PTR VOID OPTIONAL, IN OUT NoHandles PTR UINTN, OUT Buffer PTR PTR EFI_HANDLE
    macro __NAME#.#LocateHandleBuffer SearchType, Protocol, SearchKey, NoHandles, Buffer \{
        EFI_BOOT_SERVICES_LocateHandleBuffer [__PTR], SearchType, Protocol, SearchKey, NoHandles, Buffer
    \}

    ; EFI_BOOT_SERVICES_LocateProtocol macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, LocateProtocol, IN Protocol PTR EFI_GUID, IN Registration PTR VOID OPTIONAL, Interface PTR PTR VOID
    macro __NAME#.#LocateProtocol Protocol, Registration, Interface \{
        EFI_BOOT_SERVICES_LocateProtocol [__PTR], Protocol, Registration, Interface
    \}

    ; EFI_BOOT_SERVICES_InstallMultipleProtocolInterfaces macro
    __EFI_CALL_VARARGS__ EFI_BOOT_SERVICES, InstallMultipleProtocolInterfaces, IN OUT Handle PTR EFI_HANDLE, IN Protocol PTR EFI_GUID, IN Interface PTR , ... , 0
    macro __NAME#.#InstallMultipleProtocolInterfaces Handle, [ARGS_NULL_TERMINATED] \{
    common
        EFI_BOOT_SERVICES_InstallMultipleProtocolInterfaces [__PTR], ARGS_NULL_TERMINATED
    \}

    ; EFI_BOOT_SERVICES_UninstallMultipleProtocolInterfaces macro
    __EFI_CALL_VARARGS__ EFI_BOOT_SERVICES, UninstallMultipleProtocolInterfaces, IN Handle EFI_HANDLE, IN Protocol PTR EFI_GUID, IN Interface PTR , ... , 0
    macro __NAME#.#UninstallMultipleProtocolInterfaces Handle, [ARGS_NULL_TERMINATED] \{
    common
        EFI_BOOT_SERVICES_UninstallMultipleProtocolInterfaces [__PTR], ARGS_NULL_TERMINATED
    \}

    ; EFI_BOOT_SERVICES_CalculateCrc32 macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, CalculateCrc32, IN Data PTR VOID, IN DataSize UINTN, OUT Crc32 PTR UINT32
    macro __NAME#.#CalculateCrc32 Data, DataSize, Crc32 \{
        EFI_BOOT_SERVICES_CalculateCrc32 [__PTR], Data, DataSize, Crc32
    \}

    ; EFI_BOOT_SERVICES_CopyMem macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, CopyMem, IN Destination PTR VOID, IN Source PTR VOID, IN Lenght UINTN
    macro __NAME#.#CopyMem Destination, Source, Lenght \{
        EFI_BOOT_SERVICES_CopyMem [__PTR], Destination, Source, Lenght
    \}

    ; EFI_BOOT_SERVICES_SetMem macro
    __EFI_CALL_3__ EFI_BOOT_SERVICES, SetMem, IN Buffer PTR VOID, IN Size UINTN, IN Value UINT8
    macro __NAME#.#SetMem Buffer, Size, Value \{
        EFI_BOOT_SERVICES_SetMem [__PTR], Buffer, Size, Value
    \}

    ; EFI_BOOT_SERVICES_CreateEventEx macro
    __EFI_CALL_6__ EFI_BOOT_SERVICES, CreateEventEx, IN Type UINT32, IN NotifyTpl EFI_TPL, IN NotifyFunction EFI_EVENT_NOTIFY OPTIONAL, IN NotifyContext PTR CONST VOID OPTIONAL, IN EventGroup PTR CONST EFI_GUID OPTIONAL, OUT Event PTR EFI_EVENT
    macro __NAME#.#CreateEventEx Type, NotifyTpl, NotifyFunction, NotifyContext, EventGroup, Event \{
        EFI_BOOT_SERVICES_CreateEventEx [__PTR], Type, NotifyTpl, NotifyFunction, NotifyContext, EventGroup, Event
    \}
}
