#ifndef ANTIFLASH_H
#define ANTIFLASH_H

#include "MemUtility.h"
#include "Offsets.h"

class AntiFlash
{
public:
	bool running = false;
	int LocalPlayer = 0;
	AntiFlash(MemUtils* mem)
	{
		this->Mem = mem;
		LocalPlayer = Mem->Read<int>((mem->ClientBaseAddress+offsets.dwLocalPlayer));
	}

	void Start()
	{
		while (running)
		{
			Sleep(2);
			DWORD address = LocalPlayer + offsets.m_flFlashMaxAlpha;
			if (Mem->Read<float>(address) > 0.0f)
			{
				for (int i = 0; i < 2000; i++)
				{
					Mem->Write<float>(address, 0.0f);
					Sleep(1);
				}
				Mem->Write<float>(address, 255.0f);
			}
			else if (Mem->Read<float>(address) == 0.0f)
			{
				Mem->Write<float>(address, 255.0f);
			}
		}
	}

private:
	MemUtils* Mem;
	Offsets offsets;
};

#endif // !ANTIFLASH_H