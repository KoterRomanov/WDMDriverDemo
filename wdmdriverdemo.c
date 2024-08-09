#include <ntddk.h>
#include <stdio.h>

void WDMDriverDemoUnload(_In_ PDRIVER_OBJECT DriverObject)
{

	UNREFERENCED_PARAMETER(DriverObject);

	KdPrint(("WDM driver demo unload!\n"));
}


/**
 * @brief		驱动程序入口函数 
 * @param		[In]DriverObject
 * @param		[In]RegistryPath
 * @return
 */
NTSTATUS
DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(RegistryPath);

	DriverObject->DriverUnload = WDMDriverDemoUnload;

	RTL_OSVERSIONINFOW VersionInformation = { 0 };

	NTSTATUS ntStatus = RtlGetVersion(&VersionInformation);
	if (ntStatus == STATUS_SUCCESS) {
		KdPrint(("VersionInformation.dwBuildNumber = %ld\n", VersionInformation.dwBuildNumber));
		KdPrint(("VersionInformation.dwMajorVersion = %ld\n", VersionInformation.dwMajorVersion));
		KdPrint(("VersionInformation.dwMinorVersion = %ld\n", VersionInformation.dwMinorVersion));
	}
	
	KdPrint(("WDM driver entry successfully!\n"));

	return STATUS_SUCCESS;
}