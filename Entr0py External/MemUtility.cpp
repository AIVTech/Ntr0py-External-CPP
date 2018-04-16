#include "MemUtility.h"

DWORD dwGetModuleBaseAddress(DWORD dwProcID, const wchar_t *szModuleName);

MemUtils::MemUtils()
{
	Init();
}

MemUtils::~MemUtils()
{
	//CloseHandle(this->pHandle);
}

void MemUtils::Init()
{
	HWND hWnd = FindWindowA(0, ("Counter-Strike: Global Offensive"));
	GetWindowThreadProcessId(hWnd, &pid);
	pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	ClientBaseAddress = dwGetModuleBaseAddress(pid, L"client.dll");
	EngineBaseAddress = dwGetModuleBaseAddress(pid, L"engine.dll");
}

DWORD dwGetModuleBaseAddress(DWORD dwProcID, const wchar_t *szModuleName)
{
	DWORD_PTR dwModuleBaseAddress = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwProcID);
	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 ModuleEntry32;
		ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &ModuleEntry32))
		{
			do
			{
				if (_tcsicmp(ModuleEntry32.szModule, szModuleName) == 0)
				{
					dwModuleBaseAddress = (DWORD_PTR)ModuleEntry32.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnapshot, &ModuleEntry32));
		}
		CloseHandle(hSnapshot);
	}
	return dwModuleBaseAddress;
}