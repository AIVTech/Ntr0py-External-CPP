#ifndef RCS_H
#define RCS_H

#include "MemUtility.h"
#include "Offsets.h"

struct Angle
{
	float x, y, z;
};

class RCS
{
public:
	bool running = false;
	Angle angle;
	Angle m_ViewAngle;
	Angle oldAngle;
	int shotsFired = 0;

	RCS(MemUtils* mem);

	void Start();

	~RCS();

private:
	Offsets offsets;
	MemUtils* Mem;
	int LocalPlayer = 0;
};

#endif // !RCS_H