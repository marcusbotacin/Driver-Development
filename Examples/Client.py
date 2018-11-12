import win32file as w #use windows API

print("Starting")

# Open Driver as a File Device
hdevice=w.CreateFile("\\\\.\\ReadWrite",0x80000000|0x40000000,0,None,3,0x00000080,None)

w.WriteFile(hdevice,"Hello",None)
tam,string = w.ReadFile(hdevice,200,None)
print(string)
w.CloseHandle(hdevice)