#include "Includes.h"

cBhop *pBhop = new cBhop();

cBhop::cBhop()
{

}

cBhop::~cBhop()
{

}

int cBhop::fl_onGround()
{
	return onGround;
}

DWORD cBhop::getBhopKey()
{
	return bhopKey;
}

void cBhop::Bhop()
{

	if (!pLocalPlayer->inAir())
	{
		Mem->Write<int>(pLocalPlayer->ClientDLL + ForceJump, 5);
	}
	else if (pLocalPlayer->inAir())
	{
		Mem->Write<int>(pLocalPlayer->ClientDLL + ForceJump, 4);
		Mem->Write<int>(pLocalPlayer->ClientDLL + ForceJump, 5);
		Mem->Write<int>(pLocalPlayer->ClientDLL + ForceJump, 4);
	}
	else
	{
		Mem->Write<int>(pLocalPlayer->ClientDLL + ForceJump, 4);
	}
}
