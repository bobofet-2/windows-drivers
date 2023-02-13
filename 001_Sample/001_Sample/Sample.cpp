#include <ntddk.h>

//#include <tuple>

void SampleUnload(_In_ PDRIVER_OBJECT DriverObject) 
{
    KdPrint(("Sample driver Unload called\n"));

    UNREFERENCED_PARAMETER(DriverObject);
}

extern "C"
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING /*RegistryPath*/) 
{
    DriverObject->DriverUnload = SampleUnload;

    KdPrint(("Sample driver initialized successfully\n"));

    return STATUS_SUCCESS;
}
