#include "Includes.h"

cMisc *pMisc = new cMisc();

cMisc::cMisc()
{

}

cMisc::~cMisc()
{

}

void cMisc::setClientDLL()
{
	pLocalPlayer->ClientDLL = pLocalPlayer->getClientDLL();
}

void cMisc::setEngineDLL()
{
	pLocalPlayer->EngineDLL = pLocalPlayer->getEngineDLL();
}

void cMisc::forceJump()
{
	Mem->Write<int>(pLocalPlayer->ClientDLL + ForceJump, 1);
	Sleep(30);
	Mem->Write<int>(pLocalPlayer->ClientDLL + ForceJump, 0);
}

bool cMisc::isFocused()
{
	HWND tWnd = FindWindowA(0, XOR("Counter-Strike: Global Offensive"));

	if (GetForegroundWindow() == tWnd)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void cMisc::bhopEnabled()
{
	if (GetAsyncKeyState(bhopToggleKey) & 1)
	{
		Bhop = !Bhop;
		Beep(750, 250);
	}
}

void cMisc::GlowEnabled()
{
	if (GetAsyncKeyState(glowToggleKey) & 1)
	{
		Glow = !Glow;
		Beep(750, 250);
	}
}

void cMisc::triggerEnabled()
{
	if (GetAsyncKeyState(triggerToggleKey) & 1)
	{
		Trigger = !Trigger;
		Beep(750, 250);
	}

}

bool cMisc::isWeapon()
{
	if (pLocalPlayer->getWeaponID() != weapon_knife && pLocalPlayer->getWeaponID() != weapon_c4 && pLocalPlayer->getWeaponID() != weapon_molotov && pLocalPlayer->getWeaponID() != weapon_hegrenade
		&& pLocalPlayer->getWeaponID() != weapon_flashbang && pLocalPlayer->getWeaponID() != weapon_smokegrenade && pLocalPlayer->getWeaponID() != weapon_incgrenade && pLocalPlayer->getWeaponID() != weapon_decoy
		&& pLocalPlayer->getWeaponID() != weapon_taser)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cMisc::isPistol()
{
	if (pLocalPlayer->getWeaponID() == weapon_glock || pLocalPlayer->getWeaponID() == weapon_usp || pLocalPlayer->getWeaponID() == weapon_deagle || pLocalPlayer->getWeaponID() == weapon_p250
		|| pLocalPlayer->getWeaponID() == weapon_tec9 || pLocalPlayer->getWeaponID() == weapon_hkp2000 || pLocalPlayer->getWeaponID() == weapon_elite || pLocalPlayer->getWeaponID() == weapon_fiveseven)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void cMisc::forceUpdate()
{
	Mem->Write<int>(pLocalPlayer->getEnginePointer() + 0x16C, -1);
}

