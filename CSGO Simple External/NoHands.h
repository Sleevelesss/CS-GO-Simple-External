#pragma once

class cNoHands
{
public:
	cNoHands();
	~cNoHands();
	void NoHands();
	void forceUpdateHands();
	bool NoHandsToggle = true;
};

extern cNoHands *pNoHands;