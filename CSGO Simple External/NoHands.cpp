#include "Includes.h"

cNoHands *pNoHands = new cNoHands();

cNoHands::cNoHands()
{

}

cNoHands::~cNoHands()
{

}

void cNoHands::NoHands()
{
	char nohands[256] = { 0 };
	Mem->Write<char[256]>(pLocalPlayer->getLocalPLayer() + m_szArmsModel, nohands);
	
}

void cNoHands::forceUpdateHands()
{
	pMisc->forceUpdate();
	
	NoHandsToggle = !NoHandsToggle;
}