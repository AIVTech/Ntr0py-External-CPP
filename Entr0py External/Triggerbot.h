#ifndef TRIGGERBOT_H
#define TRIGGERBOT_H

#include "MemUtility.h"
#include "Offsets.h"

class Triggerbot
{
public:
	bool running = false;
	int delay = 0;
	Triggerbot(MemUtils* mem);

	void Start();

	~Triggerbot();

private:
	Offsets offsets;
	MemUtils* Mem;
	DWORD fAttack = 0;
};

#endif // !TRIGGERBOT_H