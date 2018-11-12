/* Very Simple Driver Example
 * Marcus Botacin - 2018
 * Federal University of Paraná (UFPR)
 */

#include<fltKernel.h>

void PcreateProcessNotifyRoutine(
  HANDLE ParentId,
  HANDLE ProcessId,
  BOOLEAN Create
)
{
	DbgPrint("[%d] %x -> %x",Create,ParentId,ProcessId);
}

VOID UnloadRoutine(PDRIVER_OBJECT  DriverObject)
{
	UNREFERENCED_PARAMETER(DriverObject);
	PsSetCreateProcessNotifyRoutine(PcreateProcessNotifyRoutine,TRUE);
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
	PsSetCreateProcessNotifyRoutine(PcreateProcessNotifyRoutine,FALSE);
	DriverObject->DriverUnload=UnloadRoutine;
    return status;
}