#pragma once

class cBhop
{
public:
	cBhop();
	~cBhop();
	void Bhop();
	int fl_onGround();
	DWORD getBhopKey();
private:
	int onGround = 257;
	DWORD bhopKey = 0x20;
};

extern cBhop *pBhop;
