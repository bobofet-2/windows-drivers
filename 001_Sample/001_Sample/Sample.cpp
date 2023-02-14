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

    RTL_OSVERSIONINFOW os_version {};
    if (auto status = RtlGetVersion(&os_version))
    {
        KdPrint(("Unable to get the RtGetVersion: Error: %lu", status));
        return status;
    }

    os_version.dwOSVersionInfoSize = sizeof(PRTL_OSVERSIONINFOW);

    KdPrint(("Sample driver initialized successfully\n"));
    KdPrint(("OSVersion: '%lu.%lu.%lu %lu, Service Pack: '%hs'"
        , os_version.dwMajorVersion
        , os_version.dwMinorVersion
        , os_version.dwBuildNumber
        , os_version.dwPlatformId
        , os_version.szCSDVersion));

    return STATUS_SUCCESS;
}
