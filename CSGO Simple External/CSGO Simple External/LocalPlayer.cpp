#include "Includes.h"

LocalPlayer *pLocalPlayer = new LocalPlayer();

LocalPlayer::LocalPlayer()
{

}

LocalPlayer::~LocalPlayer()
{

}

DWORD LocalPlayer::getClientDLL()
{
	return Mem->Module(XOR("client.dll"));
}

DWORD LocalPlayer::getEngineDLL()
{
	return Mem->Module(XOR("engine.dll"));
}

DWORD LocalPlayer::getShotsFired()
{
	return Mem->Read<DWORD>(getLocalPLayer() + m_iShotsFired);
}

DWORD LocalPlayer::getLocalPLayer()
{
	return Mem->Read<DWORD>(ClientDLL + playerBase);
}

DWORD LocalPlayer::getHandleWeap()
{
	return Mem->Read<DWORD>(getLocalPLayer() + ActiveWeapon);
}

DWORD LocalPlayer::getWeaponEntity()
{
	return getHandleWeap() & 0xFFF;
}

DWORD LocalPlayer::getCurrentWeapon()
{
	return Mem->Read<DWORD>(ClientDLL + entityBase + (getWeaponEntity() - 1) * 0x10);
}

int LocalPlayer::getWeaponID()
{
	return Mem->Read<int>(getCurrentWeapon() + iWeaponID);
}

int LocalPlayer::getLocalTeam()
{
	return Mem->Read<int>(getLocalPLayer() + teamOffset);
}

int LocalPlayer::getCrossHairID()
{
	return Mem->Read<int>(getLocalPLayer() + crosshairOffset);
}

DWORD LocalPlayer::getEnemyInCH()
{
	return Mem->Read<DWORD>(ClientDLL + entityBase + ((getCrossHairID() - 1) * EntLoopDist));
}

int LocalPlayer::getEnemyHealth()
{
	return Mem->Read<int>(getEnemyInCH() + healthOffset);
}

int LocalPlayer::getEnemyTeam()
{
	return Mem->Read<int>(getEnemyInCH() + teamOffset);
}

int LocalPlayer::getTeam()
{
	return Mem->Read<int>(player + teamOffset);
}

int LocalPlayer::getHealth()
{
	return Mem->Read<int>(player + healthOffset);
}


int LocalPlayer::getFlags()
{
	return Mem->Read<int>(getLocalPLayer() + Flags);
}

DWORD LocalPlayer::getGlowPointer()
{
	return Mem->Read<DWORD>(ClientDLL + GlowObject);
}

int LocalPlayer::getGlowCurrentPlayer(int index)
{
	return Mem->Read<int>(ClientDLL + entityBase + index * 0x10);
}

float LocalPlayer::getFlashMaxAlpha()
{
	return Mem->Read<float>(getLocalPLayer() + FlashMaxAlpha);
}

DWORD LocalPlayer::getLocalEntity()
{
	return Mem->Read<DWORD>(ClientDLL + getLocalPLayer());
}

DWORD LocalPlayer::getEnginePointer()
{
	return Mem->Read<DWORD>(EngineDLL + clientState);
}

bool LocalPlayer::inAir()
{
	return getFlags() == 256 || getFlags() == 258 || getFlags() == 260 || getFlags() == 262;
}

void LocalPlayer::getPlayer(int i)
{
	player = Mem->Read<DWORD>(ClientDLL + entityBase + (i * 0x10));
}	

bool LocalPlayer::isDormant()
{
	return Mem->Read<bool>(player + Dormant);
}

float LocalPlayer::getSensitivity()
{
	DWORD thisPtr = (int)(ClientDLL + dwSensitivityPtr);
	DWORD sensitivity = Mem->Read<DWORD>(ClientDLL + dwSensitivity);

	sensitivity ^= thisPtr;

	float sens = *reinterpret_cast<float*>(&sensitivity);
	
	return sens;
}

void LocalPlayer::setSensitivity(float x)
{
	DWORD thisPtr = (int)(ClientDLL + dwSensitivityPtr);
	DWORD xored = *(DWORD*)&x ^ thisPtr;

	Mem->Write<DWORD>(ClientDLL + dwSensitivity, xored);
}
