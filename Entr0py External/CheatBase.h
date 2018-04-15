#ifndef CHEATBASE_H
#define CHEATBASE_H

#include "Offsets.h"
#include "MemUtility.h"
#include <thread>

#include "BunnyHop.h"
#include "ESPGlow.h"
#include "Triggerbot.h"
#include "RCS.h"

class CheatBase
{
public:
	MemUtils* mem = new MemUtils();

	CheatBase() {}

	void SetBhop(bool state)
	{
		bunnyHop->running = state;
		if (state)
		{
			std::thread running_thread(&CheatBase::StartBunnyHop, this);
			running_thread.detach();
		}
	}

	void SetESPGlow(bool state)
	{
		espGlow->running = state;
		if (state)
		{
			std::thread running_thread(&CheatBase::StartESPGlow, this);
			running_thread.detach();
		}
	}

	void SetTriggerbot(bool state)
	{
		triggerbot->running = state;
		if (state)
		{
			std::thread running_thread(&CheatBase::StartTriggerbot, this);
			running_thread.detach();
		}
	}

	void SetTriggerbotDelay(int delay)
	{
		triggerbot->delay = delay;
	}

	void SetRCS(bool state)
	{
		rcs->running = state;
		if (state)
		{
			std::thread running_thread(&CheatBase::StartRCS, this);
			running_thread.detach();
		}
	}

private:
	BunnyHop * bunnyHop = new BunnyHop(mem);
	ESPGlow* espGlow = new ESPGlow(mem);
	Triggerbot* triggerbot = new Triggerbot(mem);
	RCS* rcs = new RCS(mem);

	void StartBunnyHop()
	{
		bunnyHop->Start();
	}

	void StartESPGlow()
	{
		espGlow->Start();
	}

	void StartTriggerbot()
	{
		triggerbot->Start();
	}

	void StartRCS()
	{
		rcs->Start();
	}
};

#endif // !CHEATBASE_H