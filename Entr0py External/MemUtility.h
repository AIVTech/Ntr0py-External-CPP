#ifndef MEMUTILITY_H
#define MEMUTILITY_H

#include <cstdio>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>

class MemUtils
{
public:
	MemUtils();
	
	template<class cData>
	cData Read(DWORD dwAddress)
	{
		cData data;
		ReadProcessMemory(pHandle, (LPVOID)dwAddress, &data, sizeof(cData), 0);
		return data;
	}

	template<class cData>
	void Write(DWORD dwAddress, cData Value)
	{
		WriteProcessMemory(pHandle, (LPVOID)dwAddress, &Value, sizeof(cData), 0);
	}

	DWORD ClientBaseAddress = 0;
	DWORD EngineBaseAddress = 0;

	~MemUtils();
private:
	DWORD pid = 0;
	HANDLE pHandle;
	void Init();
};

#endif // !MEMUTILITY_H