#ifndef OFFSETS_H
#define OFFSETS_H
#include <Windows.h>

struct Offsets
{
	DWORD dwLocalPlayer = 0xAA6614;
	DWORD flagsAddress = 0x4F1AAF4;
	DWORD flagsOffset = 0x100;
	DWORD teamNumOffset = 0xF0;
	DWORD dwEntityList = 0x4A8387C;
	DWORD m_iGlowIndex = 0xA310;
	DWORD m_Dormant = 0xE9;
	DWORD dwGlowObject = 0x4FA08E8;
	DWORD m_Ammo = 0x03FC4B90;
	DWORD m_iShotsFired = 0xA2B0;
	DWORD dwClientState = 0x57D894;
	DWORD m_viewPunchAngle = 0x3010;
	DWORD m_iCrosshairId = 0xB2A4;
	DWORD m_iHealth = 0xFC;
	DWORD dwForceAttack = 0x2EC5BD8;
	DWORD m_vecViewOffset = 0x104;
	DWORD dwViewAngles = 0x4D10;
	DWORD m_flFlashMaxAlpha = 0xA2F4;
	DWORD m_bSpotted = 0x939;
	DWORD dwSetClanTag = 0x87120;
	DWORD entityLoopDistance = 0x00000010;
};

#endif // !OFFSETS_H