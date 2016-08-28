#pragma once

class cTrigger
{
public:
	cTrigger();
	~cTrigger();
	void Trigger();
	DWORD getTriggerKey();
private:
	DWORD triggerKey = 0x05;
};

extern cTrigger *pTrigger;

