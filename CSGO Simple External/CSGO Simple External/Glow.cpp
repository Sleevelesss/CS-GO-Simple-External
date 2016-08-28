#include "Includes.h"

cGlow *pGlow = new cGlow();

cGlow::cGlow()
{

}

cGlow::~cGlow()
{

}

//credits https://github.com/Kyrr0/GlowESP (kinda took this from there) kek

void cGlow::GlowEsp()
{

	for (int i = 0; i < 64; i++)
	{
		bool glow_currentPlayerDormant = Mem->Read<bool>(pLocalPlayer->getGlowCurrentPlayer(i) + Dormant);
		int glow_currentPlayerGlowIndex = Mem->Read<int>(pLocalPlayer->getGlowCurrentPlayer(i) + GlowIndex);
		int EntityBaseTeamID = Mem->Read<int>(pLocalPlayer->getGlowCurrentPlayer(i) + teamOffset);

		if (glow_currentPlayerDormant == true || EntityBaseTeamID == false)
			continue;
		else
			if (pLocalPlayer->getLocalTeam() != EntityBaseTeamID || GlowTeamCheck == false)
				switch (EntityBaseTeamID)
				{
				case 2:
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x4)), GlowTerroristRed);
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x8)), GlowTerroristGreen);
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0xC)), GlowTerroristBlue);
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x10)), GlowTerroristAlpha);
					Mem->Write<BOOL>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x24)), true);
					Mem->Write<BOOL>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x25)), false);
					break;
				case 3:
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x4)), GlowCounterTerroristRed);
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x8)), GlowCounterTerroristGreen);
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0xC)), GlowCounterTerroristBlue);
					Mem->Write<float>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x10)), GlowCounterTerroristAlpha);
					Mem->Write<BOOL>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x24)), true);
					Mem->Write<BOOL>((pLocalPlayer->getGlowPointer() + ((glow_currentPlayerGlowIndex * 0x38) + 0x25)), false);
					break;
				}
	}

}


