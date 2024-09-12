#pragma once

#include "Includes.h"
#include "Algorithm.h"
#include "Utility.h"
#include "Data.h"
#include "Esp.h"

namespace Memory
{
	extern	bool IsMagicInitialized;// = false;
	extern	bool WasBuggedHook;// = false;


	int AimFindBestTarget();
	VECTOR3 GetMagicCoordinate();
	VOID RestoreHook();
	VOID MODSKIN();
	VOID MemoryThread();
	VOID MemoryFeaturesThread();
	VOID WeaponCheats();
	int skinssss();

}