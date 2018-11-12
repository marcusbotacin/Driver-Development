/* Very Simple Driver Example
 * Marcus Botacin - 2018
 * Federal University of Paraná (UFPR)
 */

#include<fltKernel.h>

VOID UnloadRoutine(PDRIVER_OBJECT  DriverObject)
{
	UNREFERENCED_PARAMETER(DriverObject);
	DbgPrint("Bye...");
}

NTSTATUS
DriverEntry (
    _In_ PDRIVER_OBJECT DriverObject,
    _In_ PUNICODE_STRING RegistryPath
    )

{
    NTSTATUS status=STATUS_SUCCESS;
	UNREFERENCED_PARAMETER(DriverObject);
    UNREFERENCED_PARAMETER( RegistryPath );
	DbgPrint("Hello from the Kernel");
	DriverObject->DriverUnload=UnloadRoutine;
    return status;
}