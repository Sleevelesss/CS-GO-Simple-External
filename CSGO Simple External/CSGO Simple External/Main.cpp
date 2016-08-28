#include "Includes.h"
#define EXPORTING_DLL
HANDLE threadLoop;

 // _________.__                            .__                        
// /   _____/|  |   ____   _______  __ ____ |  |   ____   ______ ______
// \_____  \ |  | _/ __ \_/ __ \  \/ // __ \|  | _/ __ \ /  ___//  ___/
// /        \|  |_\  ___/\  ___/\   /\  ___/|  |_\  ___/ \___ \ \___ \ 
///_______  /|____/\___  >\___  >\_/  \___  >____/\___  >____  >____  >
//        \/           \/     \/          \/          \/     \/     \/ 

DWORD WINAPI Loop(PVOID pThreadParameter)
{

	Mem->Process(XOR("csgo.exe"));

	pMisc->setClientDLL();
	pMisc->setEngineDLL();

	while (threadLoop)
	{
		assert(threadLoop);

		if (pMisc->isFocused())
		{
			pMisc->triggerEnabled();
			pMisc->GlowEnabled();
			pMisc->bhopEnabled();

			if (pNoHands->NoHandsToggle)
			{
				pNoHands->NoHands();
			}
			if (GetAsyncKeyState(0x64) & 0x8000)
			{
				pNoHands->forceUpdateHands();
			}
			if (pMisc->isPistol() && GetAsyncKeyState(0x01) & 0x8000)
			{
				pAutoPistol->Shoot();
			}
			if (pMisc->Glow)
			{
				pGlow->GlowEsp();
			}
			if (pMisc->Trigger && GetAsyncKeyState(pTrigger->getTriggerKey()) & 0x8000 && pMisc->isWeapon())
			{
				pTrigger->Trigger();
			}
			if (pMisc->Bhop && GetAsyncKeyState(pBhop->getBhopKey()) & 0x8000)
			{
				pBhop->Bhop();
			}
			if (pLocalPlayer->getFlashMaxAlpha() > 50.f)
			{
				pNoFlash->noFlash();
			}
			if (pMisc->isWeapon())
			{
				pSlowAim->SlowAim(0.5);
			}		
		}
		Sleep(5);
	}
	return 0;
}



BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		threadLoop = CreateThread(0, 0, Loop, 0, 0, NULL);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		if (threadLoop)
			CloseHandle(threadLoop);
		break;
	}
	return TRUE;
}
