#include "RCS.h"
#include <string>

RCS::RCS(MemUtils* mem)
{
	this->Mem = mem;
	DWORD address = mem->ClientBaseAddress + offsets.dwLocalPlayer;
	this->LocalPlayer = mem->Read<int>(address);
}


RCS::~RCS()
{
}

void RCS::Start()
{
	while (running)
	{
		Sleep(2);
		
	}
}
