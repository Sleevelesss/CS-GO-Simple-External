#include "Includes.h"

cAutoPistol *pAutoPistol = new cAutoPistol();

cAutoPistol::cAutoPistol()
{

}

cAutoPistol::~cAutoPistol()
{

}

void cAutoPistol::Shoot()
{
	Mem->Write<int>(pLocalPlayer->ClientDLL + ForceAttack, 5);
	Sleep(50);
	Mem->Write<int>(pLocalPlayer->ClientDLL + ForceAttack, 4);
}