#include <stdio.h>
#include <windows.h>

#define MAX_STR 1024

int main()
{
	HANDLE hFile = CreateFile(L"\\\\.\\ReadWrite",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if(hFile==INVALID_HANDLE_VALUE) /* Check */
	{
		printf("Open Driver Problem %d\n",GetLastError());
		printf("Finishing\n");
		return 0;
	}
	char input[MAX_STR];
	char output[MAX_STR];
	scanf("%s",input);
	WriteFile(hFile,input,sizeof(char)*strlen(input)+1,NULL,NULL);
	ReadFile(hFile,output,MAX_STR,NULL,NULL);
	printf("Output: %s\n",output);
	CloseHandle(hFile);
	return 0;
}