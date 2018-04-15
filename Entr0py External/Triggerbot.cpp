#include "Triggerbot.h"


Triggerbot::Triggerbot(MemUtils* mem)
{
	this->Mem = mem;
	this->fAttack = mem->ClientBaseAddress + offsets.dwForceAttack;
}

Triggerbot::~Triggerbot()
{
}

void Triggerbot::Start()
{
	while (running)
	{
		Sleep(2);
		DWORD address = Mem->ClientBaseAddress + offsets.dwLocalPlayer;
		int LocalPlayer = Mem->Read<int>(address);

		address = LocalPlayer + offsets.teamNumOffset;
		int MyTeam = Mem->Read<int>(address);

		address = LocalPlayer + offsets.m_iCrosshairId;
		int PlayerInCrosshair = Mem->Read<int>(address);

		if (PlayerInCrosshair > 0 && PlayerInCrosshair < 65)
		{
			address = Mem->ClientBaseAddress + offsets.dwEntityList + (PlayerInCrosshair - 1) * offsets.entityLoopDistance;
			int PtrToPIC = Mem->Read<int>(address);

			address = PtrToPIC + offsets.m_iHealth;
			int PICHealth = Mem->Read<int>(address);

			address = PtrToPIC + offsets.teamNumOffset;
			int PICTeam = Mem->Read<int>(address);

			if ((PICTeam != MyTeam) && (PICTeam > 1) && (PICHealth > 0))
			{
				// Shoot at Enemy
				Sleep(delay);
				Mem->Write<int>(fAttack, 1);
				Sleep(1);
				Mem->Write<int>(fAttack, 4);
			}
		}
	}
}
