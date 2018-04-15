#include "ESPGlow.h"


ESPGlow::ESPGlow(MemUtils* mem)
{
	this->Mem = mem;

	Team.r = 0;
	Team.g = 1;
	Team.b = 0;
	Team.a = 1;
	Team.rwo = true;
	Team.rwuo = true;
	
	EnemyTeam.r = 1;
	EnemyTeam.g = 0;
	EnemyTeam.b = 0;
	EnemyTeam.a = 1;
	EnemyTeam.rwo = true;
	EnemyTeam.rwuo = true;
}


ESPGlow::~ESPGlow()
{
}

void ESPGlow::Start()
{
	while (running)
	{
		Sleep(2);
		int i = 1;
		DWORD address;

		EnemyTeam.r = 1;
		EnemyTeam.g = 0;
		EnemyTeam.b = 0;

		Team.r = 0;
		Team.g = 1;
		Team.b = 0;

		do
		{
			address = Mem->ClientBaseAddress + offsets.dwLocalPlayer;
			int LocalPlayer = Mem->Read<int>(address);

			address = LocalPlayer + offsets.teamNumOffset;
			int MyTeam = Mem->Read<int>(address);

			address = Mem->ClientBaseAddress + offsets.dwEntityList + (i - 1) * 0x10;
			int Entity = Mem->Read<int>(address);

			address = Entity + offsets.teamNumOffset;
			int OpponentTeam = Mem->Read<int>(address);

			address = Entity + offsets.m_Dormant;
			if (!Mem->Read<bool>(address))
			{
				address = Entity + offsets.m_iGlowIndex;
				int GlowIndex = Mem->Read<int>(address);

				if (glowHealth)
				{
					address = Entity + offsets.m_iHealth;
					int health = Mem->Read<int>(address);

					if (MyTeam != OpponentTeam)
					{
						// Glow Enemies
						if (health >= 76)
						{
							EnemyTeam.r = 0;
							EnemyTeam.g = 1;
							EnemyTeam.b = 0;
						}
						else if (health >= 35 && health <= 75)
						{
							EnemyTeam.r = 1;
							EnemyTeam.g = 1;
							EnemyTeam.b = 0;
						}
						else
						{
							EnemyTeam.r = 1;
							EnemyTeam.g = 0;
							EnemyTeam.b = 0;
						}
						EnableGlow(GlowIndex, EnemyTeam);
					}
					else
					{
						// Glow Teammates
						//EnableGlow(GlowIndex, Team); // off for later user choices
					}
				}
			}

			i++;
		} while (i < 65);
	}
}

void ESPGlow::EnableGlow(int GlowIndex, Glow_T Team)
{
	DWORD address = Mem->ClientBaseAddress + offsets.dwGlowObject;
	int GlowObject = Mem->Read<int>(address);

	DWORD calculation = GlowIndex * 0x38 + 0x4;
	DWORD current = GlowObject + calculation;
	Mem->Write<float>(current, Team.r);

	calculation = GlowIndex * 0x38 + 0x8;
	current = GlowObject + calculation;
	Mem->Write<float>(current, Team.g);

	calculation = GlowIndex * 0x38 + 0xC;
	current = GlowObject + calculation;
	Mem->Write<float>(current, Team.b);

	calculation = GlowIndex * 0x38 + 0x10;
	current = GlowObject + calculation;
	Mem->Write<float>(current, Team.a);

	calculation = GlowIndex * 0x38 + 0x24;
	current = GlowObject + calculation;
	Mem->Write<bool>(current, Team.rwo);

	calculation = GlowIndex * 0x38 + 0x25;
	current = GlowObject + calculation;
	Mem->Write<bool>(current, Team.rwuo);
}
