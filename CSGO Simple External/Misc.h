#pragma once

class cMisc
{
public:
	cMisc();
	~cMisc();
	
	bool isWeapon();
	bool isPistol();

	bool glowToggleKeyPressed = true;
	bool bhopToggleKeyPressed = true;
	bool triggerToggleKeyPressed = true;

	bool Trigger = true;
	bool Glow = true;
	bool Bhop = true;

	float fClosest;
	bool isFocused();

	void bhopEnabled();
	void GlowEnabled();
	void triggerEnabled();
	
	void forceJump();
	void forceUpdate();
	
	void setClientDLL();
	void setEngineDLL();

};

extern cMisc* pMisc;