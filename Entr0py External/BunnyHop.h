#ifndef BUNNYHOP_H
#define BUNNYHOP_H

#include <Windows.h>
#include "MemUtility.h"
#include "Offsets.h"

class BunnyHop
{
public:
	bool running = false;
	Offsets offsets;
	BunnyHop(MemUtils* mem)
	{
		this->mem = mem;
		fJump = mem->ClientBaseAddress + offsets.flagsAddress;
		DWORD LocalPlayerAddress = mem->ClientBaseAddress + 0xAA6614;
		LocalPlayer = mem->Read<int>(LocalPlayerAddress);
		JumpAddress = LocalPlayer + 0x100;
	}

	void Start()
	{
		while (running)
		{
			Sleep(2);
			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			{
				Jump();
			}
		}
	}


private:
	DWORD fJump = 0;
	DWORD LocalPlayer = 0;
	DWORD JumpAddress = 0;
	MemUtils* mem;

	void Jump()
	{
		mem->Write(fJump, 5);
		Sleep(2);
		mem->Write(fJump, 4);
	}
};

#endif // !BUNNYHOP_H