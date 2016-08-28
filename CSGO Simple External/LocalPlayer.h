#pragma once

class LocalPlayer
{

public:
	LocalPlayer();
	~LocalPlayer();

	DWORD ClientDLL;
	DWORD EngineDLL;

	DWORD getClientDLL();
	DWORD getLocalPLayer();
	DWORD getHandleWeap();
	DWORD getWeaponEntity();
	DWORD getCurrentWeapon();
	DWORD getEngineDLL();
	DWORD getEnemyInCH();
	DWORD getGlowPointer();
	DWORD getLocalEntity();
	DWORD getEnginePointer();
	DWORD getShotsFired();

	DWORD player;

	int getGlowCurrentPlayer(int);
	int getWeaponID();
	int getLocalTeam();
	int getCrossHairID();
	int getEnemyHealth();
	int getEnemyTeam();
	int getFlags();
	int getTeam();
	int getHealth();

	float getFlashMaxAlpha();

	float getSensitivity();

	void setSensitivity(float x);
	void getPlayer(int i);

	bool inAir();
	bool isDormant();


};

extern LocalPlayer* pLocalPlayer;