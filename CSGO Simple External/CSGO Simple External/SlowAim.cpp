#include "Includes.h"

cSlowAim *pSlowAim = new cSlowAim();

cSlowAim::cSlowAim()
{

}

cSlowAim::~cSlowAim()
{

}

void cSlowAim::SlowAim(float sensitivity)
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