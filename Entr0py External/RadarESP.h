#ifndef RADARESP_H
#define RADARESP_H

#include "MemUtility.h"
#include "Offsets.h"

class RadarESP
{
public:
	bool running = false;
	int LocalPlayer = 0;
	Graphics* g = new Graphics();
	RadarESP(MemUtils* mem)
	{
		this->Mem = mem;
		LocalPlayer = Mem->Read<int>((mem->ClientBaseAddress + offsets.dwLocalPlayer));
	}

	void Start()
	{
		while (running)
		{
			Sleep(4);
			DWORD address = LocalPlayer + offsets.teamNumOffset;
			int MyTeam = Mem->Read<int>(address);
			for (int i = 1; i <= 64; i++)
			{
				address = Mem->ClientBaseAddress + offsets.dwEntityList + (i - 1) * 0x10;
				int Player = Mem->Read<int>(address);
				int PlayerTeam = Mem->Read<int>(Player + offsets.teamNumOffset);
				int PlayerDormant = Mem->Read<int>(Player + offsets.m_Dormant);
				
				if (PlayerTeam != MyTeam && !PlayerDormant)
				{
					Mem->Write<int>((Player + offsets.m_bSpotted), 1);
				}
			}
		}
	}

private:
	MemUtils* Mem;
	Offsets offsets;
};

#endif // !RADARESP_H