#ifndef ESPGLOW_H
#define ESPGLOW_H

#include "MemUtility.h"
#include "Offsets.h"

struct Glow_T
{
	float r, g, b, a;
	bool rwo, rwuo;
};

class ESPGlow
{
public:
	bool running = false;
	bool glowHealth = true;
	bool glowAllPlayers = false;
	Glow_T Team;
	Glow_T EnemyTeam;

	ESPGlow(MemUtils* mem);

	void Start();

	~ESPGlow();

private:
	Offsets offsets;
	MemUtils* Mem;
	DWORD base;
	void EnableGlow(int GlowIndex, Glow_T Team);
};

#endif // !ESPGLOW_H