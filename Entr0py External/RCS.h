#ifndef RCS_H
#define RCS_H

#include "MemUtility.h"
#include "Offsets.h"

struct Vector3f
{
	float x, y, z;
};

class RCS
{
public:
	bool running = false;

	RCS(MemUtils* mem);

	void Start();

	~RCS();

private:
	Offsets offsets;
	MemUtils* Mem;
	int LocalPlayer = 0;
};

#endif // !RCS_H