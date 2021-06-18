#include "ManualMap.h"
#include <random>
#pragma warning(disable : 4996)

BOOL load_driver(string TargetDriver, string TargetServiceName, string TargetServiceDesc)
{
	SC_HANDLE ServiceManager = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
	if (!ServiceManager) return FALSE;
	SC_HANDLE ServiceHandle = CreateService(ServiceManager, TargetServiceName.c_str(), TargetServiceDesc.c_str(), SERVICE_START | DELETE | SERVICE_STOP, SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE, TargetDriver.c_str(), NULL, NULL, NULL, NULL, NULL);
	if (!ServiceHandle)
	{
		ServiceHandle = OpenService(ServiceManager, TargetServiceName.c_str(), SERVICE_START | DELETE | SERVICE_STOP);
		if (!ServiceHandle) return FALSE;
	}
	if (!StartServiceA(ServiceHandle, NULL, NULL)) return FALSE;
	CloseServiceHandle(ServiceHandle);
	CloseServiceHandle(ServiceManager);
	return TRUE;
}

BOOL delete_service(string TargetServiceName)
{
	SERVICE_STATUS ServiceStatus;
	SC_HANDLE ServiceManager = OpenSCManager(NULL, NULL, SC_MANAGER_CONNECT);
	if (!ServiceManager) return FALSE;
	SC_HANDLE ServiceHandle = OpenService(ServiceManager, TargetServiceName.c_str(), SERVICE_STOP | DELETE);
	if (!ServiceHandle) return FALSE;
	if (!ControlService(ServiceHandle, SERVICE_CONTROL_STOP, &ServiceStatus)) return FALSE;
	if (!DeleteService(ServiceHandle)) return FALSE;
	CloseServiceHandle(ServiceHandle);
	CloseServiceHandle(ServiceManager);
	return TRUE;
}

std::string random_string(std::string::size_type length)
{
	const char *chrs = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	thread_local static std::mt19937 rg{ std::random_device{}() };
	thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);
	std::string s;
	s.reserve(length);
	while (length--)
		s += chrs[pick(rg)];
	return s;
}

int main()
{
	SetConsoleTitle("");
	//string service_name = random_string(15);
	string service_name = "ianndior";
	load_driver("C:\\ianndior.sys", service_name, service_name);
	while (!mem->Init("TslGame.exe"))
		Sleep(1);
	while (mem->RPM<int>(mem->ModuleBase) != 9460301)
		Sleep(1);
	ManualMap("C:\\RMB.dll");
	CloseHandle(mem->hDevice);
	delete_service(service_name);
}