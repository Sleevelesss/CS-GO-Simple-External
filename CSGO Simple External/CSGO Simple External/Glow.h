#pragma once

class cGlow
{
public:
	cGlow();
	~cGlow();
	void GlowEsp();
	
	float GlowTerroristRed = 1.f;
	float GlowTerroristGreen = 0.f;
	float GlowTerroristBlue = 0.f;
	float GlowTerroristAlpha = 1.f;

	float GlowCounterTerroristRed = 0.f;
	float GlowCounterTerroristGreen = 0.f;
	float GlowCounterTerroristBlue = 1.f;
	float GlowCounterTerroristAlpha = 1.f;

	bool GlowActive = true;
	bool GlowTeamCheck = true;
};

extern cGlow *pGlow;


