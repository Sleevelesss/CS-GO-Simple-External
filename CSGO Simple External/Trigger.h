#pragma once

class cTrigger
{
public:
	cTrigger();
	~cTrigger();
	void Trigger();
	DWORD getTriggerKey();
	void slowAim(float);
private:
	DWORD triggerKey = 0x05;
};

extern cTrigger *pTrigger;

