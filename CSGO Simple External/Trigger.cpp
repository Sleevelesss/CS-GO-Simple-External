#include "Includes.h"

cTrigger *pTrigger = new cTrigger();

cTrigger::cTrigger()
{

}

cTrigger::~cTrigger()
{

}

DWORD cTrigger::getTriggerKey()
{
	return triggerKey;
}

void cTrigger::Trigger()
{
	if (pLocalPlayer->getLocalTeam() != pLocalPlayer->getEnemyTeam() && pLocalPlayer->getCrossHairID() > 0 && pLocalPlayer->getEnemyHealth() > 0)
	{
		pAutoPistol->Shoot();
	}
}

void cTrigger::slowAim(float sensitivity)
{
	if (pLocalPlayer->getLocalTeam() != pLocalPlayer->getEnemyTeam() && pLocalPlayer->getCrossHairID() > 0 && pLocalPlayer->getEnemyHealth() > 0 && pLocalPlayer->getShotsFired() < 2)
	{	
		pLocalPlayer->setSensitivity(sensitivity);
	}
	else
	{
		pLocalPlayer->setSensitivity(pLocalPlayer->getSensitivity());
	}
}