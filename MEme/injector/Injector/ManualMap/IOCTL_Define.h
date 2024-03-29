#pragma once
#include <Windows.h>
#include <iostream>
using namespace std;

#define DRIVER_NAME L"ianndior"
#define DRIVER_DEVICE_NAME     L"\\Device\\ianndior"
#define DRIVER_DOS_DEVICE_NAME L"\\DosDevices\\ianndior"
#define DRIVER_DEVICE_PATH  L"\\\\.\\ianndior"
#define DRIVER_DEVICE_TYPE 0x00000022

#define IOCTL_DRIVER_INIT ((ULONG)CTL_CODE(DRIVER_DEVICE_TYPE, 0x700, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS))
#define IOCTL_DRIVER_GET_BASE_ADDRESS ((ULONG)CTL_CODE(DRIVER_DEVICE_TYPE, 0x701, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS))
#define IOCTL_DRIVER_MANAGE_MEMORY ((ULONG)CTL_CODE(DRIVER_DEVICE_TYPE, 0x702, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS))

typedef struct _DRIVER_INIT {
	ULONG ProcessId;
} DRIVER_INIT, *PDRIVER_INIT;

typedef struct _DRIVER_MANAGE_MEMORY {
	ULONGLONG Src;
	ULONGLONG Dst;
	ULONGLONG Size;
	BOOLEAN isWrite;
	BOOLEAN isIgnoreProtect;
} DRIVER_MANAGE_MEMORY, *PDRIVER_MANAGE_MEMORY;

typedef struct _GET_BASE_ADDRESS
{
	ULONGLONG *Result;
} GET_BASE_ADDRESS, *PGET_BASE_ADDRESS;