#include "Memory.h"
#include "Aimbot.h"
#include<thread>
#include "skinss.h"


BYTE MagicBulletShell[60] = {
0xC7, 0x45, 0x78, 0x00, 0x00, 0x00, 0x00,
	0x83, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x74, 0x0E,
	0x60,
	0x8B, 0x5D, 0x50,
	0x8B, 0x53, 0x18,
	0x8A, 0x02,
	0x3C, 0x88,
	0x74, 0x02,
	0x61,
	0xC3,
	0x8A, 0x42, 0x01,
	0x3C, 0x94,  //0x76
	0x75, 0x14,
	0xC7, 0x83, 0x80, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xC7, 0x83, 0x84, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xEB, 0xE1

};
BYTE RealByteCode[7];

// 0x66 , 0x0F , 0x7E, 0xBE , 0x38, 0x02 , 0x00 , 0x00 , 0xC7 , 0x45 , 0x68 , 0x48 
//66 0F 7E ? ? 38 02 00 00 C7 45 78 48
BYTE BackupSeach[] = { 0xE8, '?', '?', '?', '?', 0x90, 0x90 }; // Need update
BYTE MagicBulletSearch1[] = { 0x66, 0x0F, 0x7E, '?', 0x80, 0x02, 0x00, 0x00, 0xC7, 0x45, 0x78, 0xC0 }; // Need update
BYTE MagicBulletSearch2[] = { 0x66, 0x0F, 0x7E, '?', 0x80, 0x02, 0x00, 0x00, 0xC7, 0x45, 0x78, 0xC0 }; // Need update

DWORD MagicBulletAddress = 0;
vector<DWORD_PTR> MagicBulletList = {};
INT MagicBulletHook = 0;
bool MemoryThreadEnalbed = false;
bool WeaponCheatsEnabled = false;
bool  Memory::IsMagicInitialized = false;
DWORD FlyCarAddress = 0;
bool IsFlyCarInitialized = false;
bool  Memory::WasBuggedHook = false;


FRotator ToRotator(VECTOR3 local, VECTOR3 target) {
	VECTOR3 rotation = Subtract(local, target);

	FRotator newViewAngle = { 0 };

	float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);

	newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float)3.14159265358979323846);
	newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float)3.14159265358979323846);
	newViewAngle.Roll = (float)0.f;

	if (rotation.X >= 0.f)
		newViewAngle.Yaw += 180.0f;

	return newViewAngle;
}

VECTOR3 FRotatorToVector(FRotator ft)
{
	FLOAT angle, sr, sp, sy, cr, cp, cy;

	angle = ft.Yaw * (3.1415926535897f * 2 / 360);
	sy = sin(angle);
	cy = cos(angle);

	angle = ft.Pitch * (3.1415926535897f * 2 / 360);
	sp = sin(angle);
	cp = cos(angle);

	angle = ft.Roll * (3.1415926535897f * 2 / 360);
	sr = sin(angle);
	cr = cos(angle);
	VECTOR3 dd;
	dd.X = cp * cy;
	dd.Y = cp * sy;
	dd.Z = -sp;

	return dd;
}

VECTOR3 MULTIPLYVECT(VECTOR3 ve, float value)
{
	VECTOR3 vec;
	vec.X = ve.X * value;
	vec.Y = ve.Y * value;
	vec.Z = ve.Z * value;
	return vec;

}
VECTOR3 ADDVECTORS(VECTOR3 ve, VECTOR3 ve2)
{
	VECTOR3 vec;
	vec.X = ve.X + ve2.X;
	vec.Y = ve.Y + ve2.Y;
	vec.Z = ve.Z + ve2.Z;
	return vec;

}


void ClampAngles(FRotator& angles) {
	if (angles.Pitch > 180)
		angles.Pitch -= 360;
	if (angles.Pitch < -180)
		angles.Pitch += 360;

	if (angles.Pitch < -75.f)
		angles.Pitch = -75.f;
	else if (angles.Pitch > 75.f)
		angles.Pitch = 75.f;

	while (angles.Yaw < -180.0f)
		angles.Yaw += 360.0f;
	while (angles.Yaw > 180.0f)
		angles.Yaw -= 360.0f;
}
VOID GetMagicAddress()
{
	std::vector<DWORD_PTR> FoundedBase;

	if (Emulator::IsGameLoop4 == true)
	{
		Utility::MemSearch(MagicBulletSearch2, sizeof(MagicBulletSearch2), 0x18000000, 0x20000000, 0, 0, FoundedBase);
	}
	else if (Emulator::IsGameLoop7 == true)
	{
		Utility::MemSearch(MagicBulletSearch1, sizeof(MagicBulletSearch1), 0x0D000000, 0x10000000, 0, 0, FoundedBase);
	}
	else if (Emulator::IsSmartGaGa4 == true)
	{
		Utility::MemSearch(MagicBulletSearch2, sizeof(MagicBulletSearch2), 0x18000000, 0x20000000, 0, 0, FoundedBase);
	}
	else if (Emulator::IsSmartGaGa7 == true)
	{
		Utility::MemSearch(MagicBulletSearch1, sizeof(MagicBulletSearch1), 0x0D000000, 0x10000000, 0, 0, FoundedBase);
	}

	for (int i = 0; i < FoundedBase.size(); i++)
	{
		if (Utility::ReadMemoryEx<BYTE>(FoundedBase[i] + 0xC) == 0x52) // Need update 
		{
			MagicBulletList.push_back(FoundedBase[i]);
			MagicBulletAddress = FoundedBase[i];
		}
	}

	FoundedBase.clear();
}

VOID InitializeMagic()
{
	INT Addv = MagicBulletAddress;

	MagicBulletHook = (INT)VirtualAllocEx(Game::hProcess, 0, 500, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	WriteProcessMemory(Game::hProcess, (LPVOID)MagicBulletHook, &MagicBulletShell, sizeof(MagicBulletShell), 0);

	if (Emulator::IsGameLoop4 == true)
	{
		Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 0x13, 0x40);
	}
	else if (Emulator::IsGameLoop7 == true)
	{
		Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 0x13, 0x50);
	}
	if (Emulator::IsSmartGaGa4 == true)
	{
		Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 0x13, 0x40);
	}
	else if (Emulator::IsSmartGaGa7 == true)
	{
		Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 0x13, 0x50);
	}

	Utility::WriteMemoryEx<INT>(MagicBulletHook + 9, MagicBulletHook + 0x5E);
	ReadProcessMemory(Game::hProcess, (LPCVOID)(Addv + 0x8), &RealByteCode, sizeof(RealByteCode), 0);
	WriteProcessMemory(Game::hProcess, (LPVOID)(MagicBulletHook), &RealByteCode, sizeof(RealByteCode), 0);
}

VOID HookCall(INT Address, INT HookAdress)
{
	BYTE Shell[7] = { 0xE8, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90 };
	*(INT*)(Shell + 1) = (INT)(HookAdress - Address - 5);
	WriteProcessMemory(Game::hProcess, (LPVOID)Address, &Shell, sizeof(Shell), 0);
}

bool IsEqual(BYTE Array1[], BYTE Array2[])
{
	for (int i = 0; i < 6; i++)
	{
		if (Array1[i] != Array2[i])
		{
			return false;
		}
	}

	return true;
}

bool Hooked(int Address)
{
	unsigned char Tmp[7];
	ReadProcessMemory(Game::hProcess, (LPCVOID)(Address + 0x8), &Tmp, sizeof(Tmp), 0);

	if ((Tmp[0] == 0xE8 && Tmp[5] == 0x90 && Tmp[6] == 0x90))
	{
		return true;
	}

	return false;
}

VOID HookMagic()
{
	for (DWORD_PTR& Addv : MagicBulletList)
	{
		BYTE Tmp[7];
		ReadProcessMemory(Game::hProcess, (LPCVOID)((int)Addv + 0x8), &Tmp, sizeof(Tmp), 0);

		if (IsEqual(Tmp, RealByteCode))
		{
			HookCall((INT)(Addv + 0x8), (INT)MagicBulletHook);
		}
	}
}

VOID Memory::RestoreHook()
{
	for (DWORD_PTR& Addv : MagicBulletList)
	{
		if (Hooked(Addv))
		{
			WriteProcessMemory(Game::hProcess, (LPVOID)(Addv + 0x8), &RealByteCode, sizeof(RealByteCode), 0);
		}
	}
}

VECTOR3 Subtract(VECTOR3 Src, VECTOR3 Dst)
{
	VECTOR3 Result;
	Result.X = Src.X - Dst.X;
	Result.Y = Src.Y - Dst.Y;
	Result.Z = Src.Z - Dst.Z;

	return Result;
}

float Magnitude(VECTOR3 Vec)
{
	return sqrtf(Vec.X * Vec.X + Vec.Y * Vec.Y + Vec.Z * Vec.Z);
}

float GetDistance(VECTOR3 Src, VECTOR3 Dst)
{
	VECTOR3 Result = Subtract(Src, Dst);
	return Magnitude(Result);
}

VECTOR3 NormalizeVec(VECTOR3 Vector)
{
	float Length = Magnitude(Vector);

	Vector.X /= Length;
	Vector.Y /= Length;
	Vector.Z /= Length;

	return Vector;
}
float Distance(VECTOR3 myPos, VECTOR3 enPos)
{
	return sqrt((myPos.X - enPos.X) * (myPos.X - enPos.X) + (myPos.Y - enPos.Y) * (myPos.Y - enPos.Y) + (myPos.Z - enPos.Z) * (myPos.Z - enPos.Z));
}
float BulletDrop(float TravelTime)
{
	return (TravelTime * TravelTime * 980 / 2);
}
bool Fov(float OverlayScreenWidth, float OverlayScreenHeight, VECTOR2 PlayerW2SBone, float FovRadius)
{
	VECTOR2 Cenpoint;
	Cenpoint.X = PlayerW2SBone.X - (OverlayScreenWidth / 2);
	Cenpoint.Y = PlayerW2SBone.Y - (OverlayScreenHeight / 2);

	if (Cenpoint.X * Cenpoint.X + Cenpoint.Y * Cenpoint.Y <= FovRadius * FovRadius)
	{
		return true;
	}


	return false;
}
VECTOR3 GetMagicNoFOV()
{
	VECTOR3 Coordinate;
	Coordinate.X = 0;
	Coordinate.Y = 0;
	Coordinate.Z = 0;


	VECTOR3 EnemyTruePosition;
	EnemyTruePosition.X = 0;
	EnemyTruePosition.Y = 0;
	EnemyTruePosition.Z = 0;
	VECTOR2 Screen;
	Screen.X = 0;
	Screen.Y = 0;

	VECTOR3 Velocity;
	Velocity.X = 0;
	Velocity.Y = 0;
	Velocity.Z = 0;
	FLOAT Dummydistance = 9999.0f;
	FLOAT DistanceBetweenCorssHairAndEnemy = 0;
	INT Distance4 = 0;
	VECTOR3 posi;
	int numbers = 0;
	AActor TargetActor;
	DWORD TEMp{};

	for (AActor& AActor : Data::AActorList)
	{
		if (Setting::SkipKnocked == true && AActor.Health < 0)
		{
			continue;
		}
		if (Setting::SkipBots == true && AActor.IsBot == true)
		{
			continue;
		}
		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
		{
			if (Distance4 > Setting::magicrange)
			{
				continue;
			}
			DistanceBetweenCorssHairAndEnemy = sqrt(pow(Screen.X - DX11Window::Width / 2, 2) + pow(Screen.Y - DX11Window::Height / 2, 2));
			if (DistanceBetweenCorssHairAndEnemy < Dummydistance)
			{
				if (Setting::curraim == 0)
				{
					EnemyTruePosition = AActor.HeadPos;
					EnemyTruePosition.Z += 7;
				}
				if (Setting::curraim == 1)
				{
					EnemyTruePosition = AActor.ChestPos;
					// EnemyTruePosition.Z += 3;
				}
				if (Setting::curraim == 2)
				{
					EnemyTruePosition = AActor.PelvisPos;
					// EnemyTruePosition.Z += 1;
				}
				if (Setting::curraim == 3)
				{


					if (Setting::autocurraim == 0) //head
					{
						EnemyTruePosition = AActor.ChestPos;

					}
					else if (Setting::autocurraim == 1) //rshould
					{
						EnemyTruePosition = AActor.PelvisPos;

					}

					else if (Setting::autocurraim == 2) //lknee
					{
						EnemyTruePosition = AActor.HeadPos;

					}
					else if (Setting::autocurraim == 3) // lshould
					{
						EnemyTruePosition = AActor.rAnklePos;

					}


				}

				TargetActor = AActor;
				numbers++;
				TEMp = AActor.Address;
				Dummydistance = DistanceBetweenCorssHairAndEnemy;
			}
		}
	}
	if (numbers == 0 && Setting::CameraCatch) {
		int targetDistance{};
		for (int i = 0; i < Data::AActorList.size(); i++)
		{

			if (Setting::SkipKnocked == true && Data::AActorList[i].Health < 0)
			{
				continue;
			}
			if (Setting::SkipBots == true && Data::AActorList[i].IsBot == true)
			{
				continue;
			}
			//Find Closet Enemy//
			float dis = sqrt(pow(Data::CameraCache.POV.Location.X - Data::AActorList[i].Position.X, 2) + pow(Data::CameraCache.POV.Location.Y - Data::AActorList[i].Position.Y, 2) + pow(Data::CameraCache.POV.Location.Z - Data::AActorList[i].Position.Z, 2));
			INT DIS = dis / 100.0f;

			if (DIS < targetDistance)
			{
				if (Setting::curraim == 0)
				{
					EnemyTruePosition = Data::AActorList[i].HeadPos;
					EnemyTruePosition.Z += 7;
				}
				if (Setting::curraim == 1)
				{
					EnemyTruePosition = Data::AActorList[i].ChestPos;
					// EnemyTruePosition.Z += 3;
				}
				if (Setting::curraim == 2)
				{
					EnemyTruePosition = Data::AActorList[i].PelvisPos;
					// EnemyTruePosition.Z += 1;
				}
				if (Setting::curraim == 3)
				{

					if (Setting::autocurraim == 0) //head
					{
						EnemyTruePosition = Data::AActorList[i].ChestPos;

					}
					else if (Setting::autocurraim == 1) //rshould
					{
						EnemyTruePosition = Data::AActorList[i].PelvisPos;

					}

					else if (Setting::autocurraim == 2) //lknee
					{
						EnemyTruePosition = Data::AActorList[i].HeadPos;

					}
					else if (Setting::autocurraim == 3) // lshould
					{
						EnemyTruePosition = Data::AActorList[i].rAnklePos;

					}



				}

				TargetActor = Data::AActorList[i];
				numbers++;
				TEMp = Data::AActorList[i].Address;
				Dummydistance = DistanceBetweenCorssHairAndEnemy;
			}
		}
	}
	if (numbers == 0) {
		Setting::CurrentTargetAddress = -1;
		VECTOR3 end;
		end.X = 9999.0f;
		end.Y = 9999.0f;
		end.Z = 9999.0f;
		return end;
	}
	else
	{
		Data::TargetActor = TargetActor;

		Data::TargetActor = TargetActor;






		auto curVehicle = Utility::ReadMemoryEx<uint32_t>(Data::TargetActor.Address + Offset::CurrentVehicle); // 0x8e8

		if (curVehicle)
		{
			Data::TargetActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(curVehicle + Offset::ReplicatedMovement); // Actor.Object:ReplicatedMovement + 0x0 -> 0x78
		}
		else
		{
			Data::TargetActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Data::TargetActor.Address + Offset::RootComponent) + Offset::ComponentVelocity);
		}

		Setting::CurrentTargetAddress = TEMp;



		return EnemyTruePosition;

	}

}
VECTOR3 GetMagicFOV()
{
	VECTOR3 Coordinate;
	Coordinate.X = 0;
	Coordinate.Y = 0;
	Coordinate.Z = 0;


	VECTOR3 EnemyTruePosition;
	EnemyTruePosition.X = 0;
	EnemyTruePosition.Y = 0;
	EnemyTruePosition.Z = 0;
	VECTOR2 Screen;
	Screen.X = 0;
	Screen.Y = 0;
	VECTOR3 HeadPos;
	HeadPos.X = 0;
	HeadPos.Y = 0;
	HeadPos.Z = 0;
	VECTOR3 Velocity;
	Velocity.X = 0;
	Velocity.Y = 0;
	Velocity.Z = 0;
	FLOAT Dummydistance = 9999.0f;
	FLOAT DistanceBetweenCorssHairAndEnemy = 0;
	INT Distance4 = 0;
	VECTOR3 posi;
	AActor TargetActor;
	DWORD TEMp;
	int number = 0;
	for (AActor& AActor : Data::AActorList)
	{
		if (Setting::SkipKnocked == true && AActor.Health < 0)
		{
			continue;
		}
		if (Setting::SkipBots == true && AActor.IsBot == true)
		{
			continue;
		}
		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
		{
			if (Distance4 > Setting::magicrange)
			{
				continue;
			}
			if (Setting::fovcircle)
			{
				if (Aimbot::InsideFov(DX11Window::Width, DX11Window::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
				{

					DistanceBetweenCorssHairAndEnemy = sqrt(pow(Screen.X - DX11Window::Width / 2, 2) + pow(Screen.Y - DX11Window::Height / 2, 2));

					if (DistanceBetweenCorssHairAndEnemy < Dummydistance)
					{
						if (Setting::curraim == 0)
						{
							EnemyTruePosition = AActor.HeadPos;
							EnemyTruePosition.Z += 7;
						}
						if (Setting::curraim == 1)
						{
							EnemyTruePosition = AActor.ChestPos;
							//EnemyTruePosition.Z += 3;
						}
						if (Setting::curraim == 2)
						{
							EnemyTruePosition = AActor.PelvisPos;
							//EnemyTruePosition.Z += 1;
						}
						if (Setting::curraim == 3)
						{


							if (Setting::autocurraim == 0) //head
							{
								EnemyTruePosition = AActor.ChestPos;

							}
							else if (Setting::autocurraim == 1) //rshould
							{
								EnemyTruePosition = AActor.PelvisPos;

							}

							else if (Setting::autocurraim == 2) //lknee
							{
								EnemyTruePosition = AActor.HeadPos;

							}
							else if (Setting::autocurraim == 3) // lshould
							{
								EnemyTruePosition = AActor.rAnklePos;

							}
						}


						Dummydistance = DistanceBetweenCorssHairAndEnemy;
						number++;
						TargetActor = AActor;
						TEMp = AActor.Address;
					}

				}
			}

		}
	}
	if (number == 0)
	{
		//CameraCacheEntry CameraCache = Data::CameraCache;
		//VECTOR3 currentViewLocation = Data::lOCALPLAYERHEAD;
		//VECTOR3 currentViewRotation = FRotatorToVector(CameraCache.POV.Rotation);
		//VECTOR3 end = ADDVECTORS(currentViewLocation, MULTIPLYVECT(currentViewRotation, 10000.0f));
		Setting::CurrentTargetAddress = -1;

		VECTOR3 end;
		end.X = 9999.0f;
		end.Y = 9999.0f;
		end.Z = 9999.0f;

		return end;
	}
	else
	{

		Data::TargetActor = TargetActor;


		auto curVehicle = Utility::ReadMemoryEx<uint32_t>(Data::TargetActor.Address + Offset::CurrentVehicle); // 0x8e8

		if (curVehicle)
		{
			Data::TargetActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(curVehicle + Offset::ReplicatedMovement); // Actor.Object:ReplicatedMovement + 0x0 -> 0x78
		}
		else
		{
			Data::TargetActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(Data::TargetActor.Address + Offset::RootComponent) + Offset::ComponentVelocity);
		}



		Setting::CurrentTargetAddress = TEMp;


		return EnemyTruePosition;
	}

}

int Memory::AimFindBestTarget() {
	float targetDistance = 9999.0;
	VECTOR2 retval{};
	int dist, headdist = 0;
	int ret{};
	for (int i = 0; i < Data::AActorList.size(); i++)
	{
		DWORD tmpAddv = Utility::ReadMemoryEx<INT>(Data::AActorList[i].Address + Offset::Mesh);
		DWORD bodyAddv = tmpAddv + Offset::BodyAddv;
		DWORD boneAddv = Utility::ReadMemoryEx<INT>(tmpAddv + Offset::MinLOD) + 48;

		VECTOR2 chest;
		VECTOR2 head;
		VECTOR3 chestPos = Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 4 * 48);


		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, Data::AActorList[i].ChestPos, chest, &dist))
		{
			if (Setting::fovcircle)
			{
				if (Aimbot::InsideFov(DX11Window::Width, DX11Window::Height, chest, Setting::fovcircleredus/*FovRadius*/))
				{
					float cross_dist = sqrt(pow(chest.X - DX11Window::Width / 2, 2) + pow(chest.Y - DX11Window::Height / 2, 2));
					if (cross_dist < targetDistance)
					{
						ret = i;
						targetDistance = cross_dist;

					}
				}
			}
			else
			{

				float cross_dist = sqrt(pow(chest.X - DX11Window::Width / 2, 2) + pow(chest.Y - DX11Window::Height / 2, 2));

				if (cross_dist < targetDistance)
				{
					ret = i;
					targetDistance = cross_dist;

				}

			}
		}
	}
	return ret;

}
void WideView() {
	while (true) {

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

}
bool IpadActivated = false;
VECTOR3 GetainmRotation(VECTOR3 WorldLocation)
{
	// FRotator Rotation = Data::CameraCache.POV.Rotation; 
	// VECTOR3 Angle = FRotatorToVector(Rotation); 
	// NormalizeVec(Angle);
	// VECTOR3 vDelta = Subtract(WorldLocation, Data::CameraCache.POV.Location);
	// NormalizeVec(vDelta);
	// VECTOR3 vTransformed;
	// vTransformed.X = (vDelta.X * Angle.X) + (vDelta.Y * Angle.Y) + (vDelta.Z * Angle.Z);
	// vTransformed.Y = (vDelta.X * Angle.X) + (vDelta.Y * Angle.Y) + (vDelta.Z * Angle.Z);
	// vTransformed.Z = (vDelta.X * Angle.X) + (vDelta.Y * Angle.Y) + (vDelta.Z * Angle.Z);

	//FRotator Rotation = Data::CameraCache.POV.Rotation;
	//D3DMATRIX1 tempMatrix = ToMatrix(Rotation);
	//
	//VECTOR3 vAxisX, vAxisY, vAxisZ;
	//
	//vAxisX.X = tempMatrix.m[0][0];
	//vAxisX.Y = tempMatrix.m[0][1];
	//vAxisX.Z = tempMatrix.m[0][2];
	//vAxisY.X = tempMatrix.m[1][0];
	//vAxisY.Y = tempMatrix.m[1][1];
	//vAxisY.Z = tempMatrix.m[1][2];
	//vAxisZ.X = tempMatrix.m[2][0];
	//vAxisZ.Y = tempMatrix.m[2][1];
	//vAxisZ.Z = tempMatrix.m[2][2];
	//VECTOR3 vDelta = Subtract(WorldLocation, Data::CameraCache.POV.Location);
	//
	//VECTOR3 vTransformed;
	//
	//vTransformed.X = (vDelta.X * vAxisY.X) + (vDelta.Y * vAxisY.Y) + (vDelta.Z * vAxisY.Z);
	//vTransformed.Y = (vDelta.X * vAxisZ.X) + (vDelta.Y * vAxisZ.Y) + (vDelta.Z * vAxisZ.Z);
	//vTransformed.Z = (vDelta.X * vAxisX.X) + (vDelta.Y * vAxisX.Y) + (vDelta.Z * vAxisX.Z);

 //	DWORD WeaponManagerComponent = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::WeaponManagerComponent);
 //	DWORD CurrentWeaponReplicated = Utility::ReadMemoryEx<DWORD>(WeaponManagerComponent + Offset::CurrentWeaponReplicated);
 //	VECTOR3 CurrentWeaponReplicated = Utility::ReadMemoryEx<VECTOR3>(Data::LocalPlayer + 0x98);

	VECTOR3 vDelta = Subtract(WorldLocation, Data::lOCALPLAYERHEAD);
	NormalizeVec(vDelta);
	float distance = sqrtf((vDelta.X * vDelta.X) + (vDelta.Y * vDelta.Y) + (vDelta.Z * vDelta.Z));


	VECTOR3 LAST;
	LAST.X = (RAD2DEG(atan2(vDelta.Z, distance)));
	LAST.X -= 0.1;
	LAST.Y = RAD2DEG(atan2(vDelta.Y, vDelta.X));

	//FRotator Rotation = Data::CameraCache.POV.Rotation;
	//  VECTOR3 Angle = FRotatorToVector(Rotation); 
	//  NormalizeVec(Angle);
	//  VECTOR3 vDelta2 = (LAST - Angle);
	//
	//  VECTOR3 LLL = LAST - vDelta2;
	//


	return LAST;



}
VECTOR3 GetMagicRunningCoordinatesVip()
{
	VECTOR3 Coordinate;
	Coordinate.X = 0;
	Coordinate.Y = 0;
	VECTOR3 HeadPos;
	HeadPos.X = 0;
	HeadPos.Y = 0;
	HeadPos.Z = 0;
	VECTOR2 Screen;
	Screen.X = 0;
	Screen.Y = 0;
	VECTOR3 Velocity;
	Velocity.X = 0;
	Velocity.Y = 0;
	Velocity.Z = 0;
	FLOAT TargetDistance = 9999.0f;
	FLOAT CrossDist = 0;
	INT Distance4 = 0;
	VECTOR3 posi;
	//bool isEnemyInsideFOV = false;
	/**/
	for (AActor& AActor : Data::AActorList)
	{
		/*if (Screen.Z < 0.001f || Distance < 10)
			continue;*/
		if (Setting::knocked == true && AActor.Health < 0)
		{
			continue;
		}
		if (Setting::SkipBots == true && AActor.IsBot == true)
		{
			continue;
		}
		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
		{
			if (Setting::fovcircle)
			{
				if (Aimbot::InsideFov(DX11Window::Width, DX11Window::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
				{
					//no will fix your prop
					HookMagic();
					CrossDist = sqrt(pow(Screen.X - DX11Window::Width / 2, 2) + pow(Screen.Y - DX11Window::Height / 2, 2));
					if (CrossDist < TargetDistance)
					{
						if (Setting::curraim == 0)
						{
							HeadPos = AActor.HeadPos;
							HeadPos.Z += 7;
						}
						if (Setting::curraim == 1)
						{
							HeadPos = AActor.ChestPos;
						}
						if (Setting::curraim == 2)
						{
							HeadPos = AActor.PelvisPos;
						}
						if (Setting::curraim == 3)
						{
							HeadPos = AActor.rAnklePos;
						}
						//if (Setting::knocked)
						//{
						//	if (AActor.Health <= 0)
						//	{
						//		Memory::RestoreHook();
						//		continue;
						//	}
						//}
						//if (Setting::SkipBots)
						//{
						//	if (AActor.IsBot)
						//	{
						//		Memory::RestoreHook();
						//		continue;
						//	}
						//}
						TargetDistance = CrossDist;


						auto curVehicle = Utility::ReadMemoryEx<uint32_t>(AActor.Address + Offset::CurrentVehicle); // 0x8e8

						if (curVehicle)
						{
							AActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(curVehicle + Offset::ReplicatedMovement); // Actor.Object:ReplicatedMovement + 0x0 -> 0x78
						}
						else
						{
							AActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(AActor.Address + 0x154) + 0x1a0);
						}

						//	AActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(AActor.Address + 0x154) + 0x1a0);
						Velocity = AActor.Velocity;
					}

				}

			}
			else
			{
				HookMagic();
				if (Setting::knocked == true && AActor.Health < 0)
				{
					continue;
				}
				if (Setting::SkipBots == true && AActor.IsBot == true)
				{
					continue;
				}
				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, AActor.ChestPos, Screen, &Distance4))
				{
					CrossDist = sqrt(pow(Screen.X - DX11Window::Width / 2, 2) + pow(Screen.Y - DX11Window::Height / 2, 2));

					if (CrossDist < TargetDistance)
					{
						if (Setting::curraim == 0)
						{
							HeadPos = AActor.HeadPos;
							HeadPos.Z += 7;
						}
						if (Setting::curraim == 1)
						{
							HeadPos = AActor.ChestPos;
						}
						if (Setting::curraim == 2)
						{
							HeadPos = AActor.PelvisPos;
						}
						if (Setting::curraim == 3)
						{
							HeadPos = AActor.rAnklePos;
						}
						if (Setting::knocked)
						{
							if (AActor.Health <= 0)
							{
								Memory::RestoreHook();
								continue;
							}
						}
						if (Setting::SkipBots)
						{
							if (AActor.IsBot)
							{
								Memory::RestoreHook();
								continue;
							}
						}
						TargetDistance = CrossDist;
						auto curVehicle = Utility::ReadMemoryEx<uint32_t>(AActor.Address + Offset::CurrentVehicle); // 0x8e8

						if (curVehicle)
						{
							AActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(curVehicle + Offset::ReplicatedMovement); // Actor.Object:ReplicatedMovement + 0x0 -> 0x78
						}
						else
						{
							AActor.Velocity = Utility::ReadMemoryEx<VECTOR3>(Utility::ReadMemoryEx<DWORD>(AActor.Address + 0x154) + 0x1a0);
						}
						Velocity = AActor.Velocity;
					}
				}
			}

			if (Setting::fovcircle)
			{
				if (!Algorithm::WorldToScreenBone(Esp::ViewMatrix, HeadPos, Screen, &Distance4))
				{
					Memory::RestoreHook();
					continue;

				}

				if (!Aimbot::InsideFov(DX11Window::Width, DX11Window::Height, Screen, Setting::fovcircleredus/*FovRadius*/))
				{
					Memory::RestoreHook();
					continue;
				}

			}
		}
	}

	DWORD MeshAddv = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
	DWORD BodyAddv = MeshAddv + Offset::BodyAddv;
	DWORD BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;

	VECTOR3 MyPosition = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);

	if (Setting::PREDICTION)
	{
		float Gravity = 5.24f;
		float AddTime = 30 / 10.0f + 1.0f;
		float distance = GetDistance(MyPosition, HeadPos) / 100.0f;
		float temp = 1.23f;
		DWORD CurrentReloadWeapon = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::CurrentReloadWeapon);
		DWORD ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrentReloadWeapon + Offset::ShootWeaponEntity);
		float BulletSpeed = Utility::ReadMemoryEx<FLOAT>(ShootWeaponEntity + Offset::BulletFireSpeed);
		//DWORD SceneComponent = Utility::ReadMemoryEx<INT>(Offset::RootComponent + 0x140);//SceneComponent* HomingTargetComponent? old 14c
		//DWORD VehicleCommon = Utility::ReadMemoryEx<INT>(Offset::VehicleCommon + 0x6f8);//VehicleCommonComponent* VehicleCommon? old 6a0
		FLOAT BaseFlyTime = distance / BulletSpeed;
		FLOAT SecFlyTime = BaseFlyTime * temp;
		float BulletTravelTime = distance / (BulletSpeed / 100.f);
		float zAssist{ 1.0f };

		if (distance < 5000.f)
			zAssist = 1.8f;
		else if (distance < 10000.f)
			zAssist = 1.72f;
		else if (distance < 15000.f)
			zAssist = 1.23f;
		else if (distance < 20000.f)
			zAssist = 1.24f;
		else if (distance < 25000.f)
			zAssist = 1.25f;
		else if (distance < 30000.f)
			zAssist = 1.26f;
		else if (distance < 35000.f)
			zAssist = 1.27f;
		else if (distance < 40000.f)
			zAssist = 1.28f;
		else if (distance < 45000.f)
			zAssist = 1.29f;
		else if (distance < 50000.f)
			zAssist = 1.30f;
		else zAssist = 1.35f;

		HeadPos.X += Velocity.X * BulletTravelTime;
		HeadPos.Y += Velocity.Y * BulletTravelTime;
		HeadPos.Z += Velocity.Z * BulletTravelTime * zAssist + 50.5f * 5.72f * BulletTravelTime * BulletTravelTime;
	}
	FLOAT xDif = HeadPos.X - MyPosition.X;
	FLOAT yDif = HeadPos.Y - MyPosition.Y;
	FLOAT zDif = HeadPos.Z - MyPosition.Z;

	float Hyp = sqrt(xDif * xDif + yDif * yDif);
	Coordinate.X = atan2(zDif, Hyp) * 180.0f / 3.1415926535897f;
	Coordinate.Y = atan2(yDif, xDif) * 180.0f / 3.1415926535897f;

	return Coordinate;
}

//VOID Memory::MemoryThread()
//{
//	static bool BulletKeyState = false;
//	VECTOR3 MagicCoordinate;
//	VECTOR3 AimRotation{};
//
//	while (true)
//	{
//		if (Data::NetDriver > 0)
//		{
//			if (Setting::MagicBullet || Setting::engine == 1)
//			{
//				if (IsMagicInitialized == false)
//				{
//					GetMagicAddress();
//					InitializeMagic();
//					IsMagicInitialized = true;
//				}
//				MagicCoordinate = GetMagicRunningCoordinatesVip();
//				if (GetAsyncKeyState(VK_LBUTTON))
//				{
//					if (IsMagicInitialized == false)
//					{
//						GetMagicAddress();
//							InitializeMagic();
//							IsMagicInitialized = true;
//					}
//					BulletKeyState = true;
//						//MagicCoordinate = GetMagicCoordinates();
//
//						Utility::WriteMemoryEx<FLOAT>(MagicBulletHook + 44, MagicCoordinate.X);
//					Utility::WriteMemoryEx<FLOAT>(MagicBulletHook + 54, MagicCoordinate.Y);
//
//					if (IsMagicInitialized == false)
//					{
//						GetMagicAddress();
//						InitializeMagic();
//						IsMagicInitialized = true;
//					}
//				}
//				if (GetAsyncKeyState(VK_LBUTTON) == 0 && BulletKeyState == true && IsMagicInitialized == true)
//				{
//					BulletKeyState = false;
//					RestoreHook();
//					MagicBulletList.clear();
//					VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
//					MagicBulletAddress = 0;
//					MagicBulletHook = 0;
//					ZeroMemory(RealByteCode, sizeof(RealByteCode));
//					IsMagicInitialized = false;
//				}
//				else if (IsMagicInitialized == false)
//				{
//					RestoreHook();
//					MagicBulletList.clear();
//					VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
//					MagicBulletAddress = 0;
//					MagicBulletHook = 0;
//					ZeroMemory(RealByteCode, sizeof(RealByteCode));
//					GetMagicAddress();
//					InitializeMagic();
//					IsMagicInitialized = true;
//				}
//				if (GetAsyncKeyState('R'))
//				{
//					RestoreHook();
//					MagicBulletList.clear();
//					VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
//					MagicBulletAddress = 0;
//					MagicBulletHook = 0;
//					ZeroMemory(RealByteCode, sizeof(RealByteCode));
//					IsMagicInitialized = false;
//				}
//			}
//			else if (Setting::MagicBullet == false /*&& IsMagicInitialized == true*/)
//			{
//				RestoreHook();
//				MagicBulletList.clear();
//				VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
//				MagicBulletAddress = 0;
//				MagicBulletHook = 0;
//				ZeroMemory(RealByteCode, sizeof(RealByteCode));
//				//    MagicRested = false;
//				IsMagicInitialized = false;
//			}
//
//		}
//		std::this_thread::sleep_for(std::chrono::milliseconds(10));
//	}
//}

VOID Memory::MemoryThread()
{
	VECTOR3 Bones;
	VECTOR3 MagicCoordinate;
	VECTOR3 AimRotation{};

	while (true)
	{

		try {
			if (Data::NetDriver > 0)
			{

				if (Setting::MagicBullet || Setting::CameraAimBot || Setting::CameraCatch)
				{
					if (Data::AActorList.size() != 0)
					{


						if (Setting::fovcircle)
						{
							MagicCoordinate = GetMagicFOV();
						}
						else
						{
							MagicCoordinate = GetMagicNoFOV();
						}


						if (Setting::CameraCatch)
						{

							if (Data::LocalController)
							{

								//	CameraCacheEntry CameraCache = Data::CameraCache;
								//	VECTOR3 currentViewAngle = CameraCache.POV.Location;

								FRotator aimRotation = ToRotator(Data::CameraCache.POV.Location, MagicCoordinate);
								Data::CameraCache.POV.Rotation = aimRotation;
								Utility::WriteMemoryEx<CameraCacheEntry>(Data::PlayerCameraManager + Offset::PlayerCameraManager1::CameraCache, Data::CameraCache);



							}


						}
						if (Setting::CameraAimBot)
						{
							DWORD LocalController = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::STExtraPlayerCharacter::STPlayerController);
							if (LocalController)
							{

								DWORD PlayerCameraManager = Utility::ReadMemoryEx<DWORD>(LocalController + Offset::PlayerController1::PlayerCameraManager);
								if (PlayerCameraManager)
								{
									CameraCacheEntry CameraCache = Utility::ReadMemoryEx<CameraCacheEntry>(PlayerCameraManager + Offset::PlayerCameraManager1::CameraCache);

									VECTOR3 currentViewAngle = CameraCache.POV.Location;

									if (Setting::camsmooth)
									{
										//Reading Original FRotator/control rotater
										auto ControlRotation = Utility::ReadMemoryEx<FRotator>(LocalController + Offset::ControlRotation);

										//Callculat Angles
										FRotator aimRotation = ToRotator(currentViewAngle, MagicCoordinate);

										aimRotation.Pitch -= ControlRotation.Pitch;
										aimRotation.Yaw -= ControlRotation.Yaw;


										ClampAngles(aimRotation);
										aimRotation.Pitch += aimRotation.Pitch / (float)Setting::camsmoothness;
										aimRotation.Yaw += aimRotation.Yaw / (float)Setting::camsmoothness;
										if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
										{
											Utility::WriteMemoryEx<FRotator>(LocalController + Offset::ControlRotation, aimRotation);
										}
									}

									else
									{
										//Reading Original FRotator/control rotater
										auto ControlRotation = Utility::ReadMemoryEx<FRotator>(LocalController + Offset::ControlRotation);

										//Callculat Angles
										FRotator aimRotation = ToRotator(currentViewAngle, MagicCoordinate);

										ClampAngles(aimRotation);
										aimRotation.Pitch += aimRotation.Pitch / (float)Setting::camsmoothness;
										aimRotation.Yaw += aimRotation.Yaw / (float)Setting::camsmoothness;
										if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
										{
											Utility::WriteMemoryEx<FRotator>(LocalController + Offset::ControlRotation, aimRotation); \
										}
									}

								}
							}

						}


						if (IsMagicInitialized == false && Setting::MagicBulletticked)
						{
							GetMagicAddress();
							InitializeMagic();
							HookMagic();

							IsMagicInitialized = true;
						}
						if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
						{
							if (MagicCoordinate.X == 9999.0f && MagicCoordinate.Y == 9999.0f && MagicCoordinate.Z == 9999.0f)
							{
								if (Setting::MagicBulletticked) {
									RestoreHook();//On Off Based On FOV
									//Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 26, 0xbc);
									//Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 35, 0x03);

								}
								continue;
							}
							else
							{


								if (Setting::MagicBullet)
								{
									HookMagic();//FOV ON OFF
									//Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 26, 0xE8);
									//Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 35, 0x73);
									DWORD MeshAddv = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
									DWORD BodyAddv = MeshAddv + Offset::BodyAddv;
									DWORD BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
									VECTOR3 MyPosition = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);

									if (Setting::PREDICTION)
									{

										float Gravity = 5.24f;
										float AddTime = 30 / 10.0f + 1.0f;
										float distance = GetDistance(MyPosition, MagicCoordinate) / 100.0f;
										float temp = 1.23f;
										DWORD CurrentReloadWeapon = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::CurrentReloadWeapon);
										DWORD ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrentReloadWeapon + Offset::ShootWeaponEntity);
										float BulletSpeed = Utility::ReadMemoryEx<FLOAT>(ShootWeaponEntity + Offset::BulletFireSpeed);
										//DWORD SceneComponent = Utility::ReadMemoryEx<INT>(Offset::RootComponent + 0x140);//SceneComponent* HomingTargetComponent? old 14c
										//DWORD VehicleCommon = Utility::ReadMemoryEx<INT>(Offset::VehicleCommon + 0x6f8);//VehicleCommonComponent* VehicleCommon? old 6a0
										FLOAT BaseFlyTime = distance / BulletSpeed;
										FLOAT SecFlyTime = BaseFlyTime * temp;
										float BulletTravelTime = distance / (BulletSpeed / 100.f);
										float zAssist{ 1.0f };

										if (distance < 5000.f)
											zAssist = 1.8f;
										else if (distance < 10000.f)
											zAssist = 1.72f;
										else if (distance < 15000.f)
											zAssist = 1.23f;
										else if (distance < 20000.f)
											zAssist = 1.24f;
										else if (distance < 25000.f)
											zAssist = 1.25f;
										else if (distance < 30000.f)
											zAssist = 1.26f;
										else if (distance < 35000.f)
											zAssist = 1.27f;
										else if (distance < 40000.f)
											zAssist = 1.28f;
										else if (distance < 45000.f)
											zAssist = 1.29f;
										else if (distance < 50000.f)
											zAssist = 1.30f;
										else zAssist = 1.35f;

										MagicCoordinate.X += Data::TargetActor.Velocity.X * BulletTravelTime;
										MagicCoordinate.Y += Data::TargetActor.Velocity.Y * BulletTravelTime;
										MagicCoordinate.Z += Data::TargetActor.Velocity.Z * BulletTravelTime * zAssist + 50.5f * 5.72f * BulletTravelTime * BulletTravelTime;
									}
									FLOAT xDif = MagicCoordinate.X - MyPosition.X;
									FLOAT yDif = MagicCoordinate.Y - MyPosition.Y;
									FLOAT zDif = MagicCoordinate.Z - MyPosition.Z;
									float Hyp = sqrt(xDif * xDif + yDif * yDif);
									MagicCoordinate.X = atan2(zDif, Hyp) * 180.0f / 3.1415926535897f;
									MagicCoordinate.Y = atan2(yDif, xDif) * 180.0f / 3.1415926535897f;

									Utility::WriteMemoryEx<FLOAT>(MagicBulletHook + 44, MagicCoordinate.X);
									Utility::WriteMemoryEx<FLOAT>(MagicBulletHook + 54, MagicCoordinate.Y);

								}
							}
						}

						// Refresh magic
						if (GetAsyncKeyState(0x52) & 1)//r
						{
							if (IsMagicInitialized == true && Setting::MagicBulletticked)
							{
								if (Data::NetDriver > 0)
								{
									IsMagicInitialized = false;
									GetMagicAddress();
									HookMagic();
									IsMagicInitialized = true;
								}
							}
						}
					}
					else {
						if (Setting::MagicBulletticked) {
							RestoreHook();
							//	Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 26, 0xbc);
							//	Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 35, 0x03);
						}
					}


				}

				if (Setting::MagicBullet == false && IsMagicInitialized == true)// && WasBuggedHook == false)
				{
					RestoreHook();
					MagicBulletList.clear();
					VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
					MagicBulletAddress = 0;
					MagicBulletHook = 0;
					ZeroMemory(RealByteCode, sizeof(RealByteCode));
					IsMagicInitialized = false;
				}


			}

			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		catch (int e)
		{
			std::cout << e << std::endl;
		}
	}
}

//VOID Memory::MemoryThread()
//{
//
//	VECTOR3 MagicCoordinate;
//	VECTOR3 AimRotation{};
//
//	while (true)
//	{
//
//		try {
//			if (Data::NetDriver > 0)
//			{
//
//				if (Setting::MagicBullet || Setting::CameraAimBot || Setting::CameraCatch)
//				{
//					if (Data::AActorList.size() != 0)
//					{
//						if (IsMagicInitialized == false && Setting::MagicBulletticked)
//						{
//							GetMagicAddress(); 
//							 InitializeMagic();
//							 HookMagic();
//							 
//							IsMagicInitialized = true;
//						}
//						if (Setting::fovcircle)
//						{
//							MagicCoordinate = GetMagicFOV();
//						}
//						else
//						{
//							MagicCoordinate = GetMagicNoFOV();
//						}
//						if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
//						{ 
//							if (MagicCoordinate.X == 9999.0f && MagicCoordinate.Y == 9999.0f && MagicCoordinate.Z == 9999.0f)
//							{
//								if (Setting::MagicBulletticked) {
//									RestoreHook();//On Off Based On FOV
//									//Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 26, 0xbc);
//									//Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 35, 0x03);
//								}
//								continue;
//							}
//							else
//							{
//								if (Setting::CameraCatch)
//								{
//									if (Data::LocalController)
//									{
//										if (Data::PlayerCameraManager)
//										{
//											CameraCacheEntry CameraCache = Data::CameraCache;
//											VECTOR3 currentViewAngle = CameraCache.POV.Location;
//
//											FRotator aimRotation = ToRotator(currentViewAngle, MagicCoordinate);
//											CameraCache.POV.Rotation = aimRotation;
//											Utility::WriteMemoryEx<CameraCacheEntry>(Data::PlayerCameraManager + Offset::PlayerCameraManager1::CameraCache, CameraCache);
//
//
//										}
//									}
//
//
//								}
//								if (Setting::CameraAimBot)
//								{
//									DWORD LocalController = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::STExtraPlayerCharacter::STPlayerController);
//									if (LocalController)
//									{
//
//										DWORD PlayerCameraManager = Utility::ReadMemoryEx<DWORD>(LocalController + Offset::PlayerController1::PlayerCameraManager);
//										if (PlayerCameraManager)
//										{
//											CameraCacheEntry CameraCache = Utility::ReadMemoryEx<CameraCacheEntry>(PlayerCameraManager + Offset::PlayerCameraManager1::CameraCache);
//
//											VECTOR3 currentViewAngle = CameraCache.POV.Location;
//
//											if (Setting::camsmooth)
//											{
//												//Reading Original FRotator/control rotater
//												auto ControlRotation = Utility::ReadMemoryEx<FRotator>(LocalController + Offset::ControlRotation);
//
//												//Callculat Angles
//												FRotator aimRotation = ToRotator(currentViewAngle, MagicCoordinate);
//
//												aimRotation.Pitch -= ControlRotation.Pitch;
//												aimRotation.Yaw -= ControlRotation.Yaw;
//
//
//												ClampAngles(aimRotation);
//												aimRotation.Pitch += aimRotation.Pitch / (float)Setting::camsmoothness;
//												aimRotation.Yaw += aimRotation.Yaw / (float)Setting::camsmoothness;
//
//												Utility::WriteMemoryEx<FRotator>(LocalController + Offset::ControlRotation, aimRotation);
//											}
//
//											else
//											{
//												//Reading Original FRotator/control rotater
//												auto ControlRotation = Utility::ReadMemoryEx<FRotator>(LocalController + Offset::ControlRotation);
//
//												//Callculat Angles
//												FRotator aimRotation = ToRotator(currentViewAngle, MagicCoordinate);
//
//												ClampAngles(aimRotation);
//												aimRotation.Pitch += aimRotation.Pitch / (float)Setting::camsmoothness;
//												aimRotation.Yaw += aimRotation.Yaw / (float)Setting::camsmoothness;
//
//												Utility::WriteMemoryEx<FRotator>(LocalController + Offset::ControlRotation, aimRotation);
//											}
//
//										}
//									}
//
//								}
//								if (Setting::MagicBullet)
//								{
//									HookMagic();//FOV ON OFF
//									//Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 26, 0xE8);
//									//Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 35, 0x73);
//									DWORD MeshAddv = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
//									DWORD BodyAddv = MeshAddv + Offset::BodyAddv;
//									DWORD BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
//									VECTOR3 MyPosition = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);
//									if (Setting::PREDICTION) {
//									/*	DWORD MeshAddv = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::Mesh);
//										DWORD BodyAddv = MeshAddv + Offset::BodyAddv;
//										DWORD BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
//										VECTOR3 MyPosition = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 5 * 48);*/
//
//								/*		MeshAddv = Utility::ReadMemoryEx<DWORD>(AActor.Address + Offset::Mesh);
//										BodyAddv = MeshAddv + Offset::BodyAddv;
//										BoneAddv = Utility::ReadMemoryEx<DWORD>(MeshAddv + Offset::MinLOD) + 48;
//										lOCALPLAYERHEAD = Algorithm::GetBoneWorldPosition(BodyAddv, BoneAddv + 1 * 48);*/
//
//										float Distance = GetDistance(MyPosition, MagicCoordinate) / 100.0f;
//										float temp = 1.23f;
//
//										if (Distance < 50.f)
//											temp = 1.8f;
//										else if (Distance < 100.f)
//											temp = 1.72f;
//										else if (Distance < 150.f)
//											temp = 1.23f;
//										else if (Distance < 200.f)
//											temp = 1.24f;
//										else if (Distance < 250.f)
//											temp = 1.25f;
//										else if (Distance < 300.f)
//											temp = 1.26f;
//										else if (Distance < 350.f)
//											temp = 1.27f;
//										else if (Distance < 400.f)
//											temp = 1.28f;
//										else if (Distance < 450.f)
//											temp = 1.29f;
//										else if (Distance < 500.f)
//											temp = 1.30f;
//										else temp = 1.35f;
//
//										float Gravity = 9.82f;
//
//										DWORD CurrentReloadWeapon = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::CurrentWeapon);
//										DWORD ShootWeaponEntity = Utility::ReadMemoryEx<DWORD>(CurrentReloadWeapon + Offset::ShootWeaponEntity);
//										float BulletSpeed = Utility::ReadMemoryEx<FLOAT>(ShootWeaponEntity + Offset::BulletFireSpeed);
//										float BulletTravelTime = Distance / BulletSpeed;
//										float secFlyTime = BulletTravelTime * temp;
//
//										MagicCoordinate.X += Data::TargetActor.Velocity.X * secFlyTime;
//										MagicCoordinate.Y += Data::TargetActor.Velocity.Y * secFlyTime;
//										MagicCoordinate.Z += Data::TargetActor.Velocity.Z * secFlyTime;
//										if (Distance > 100.f)
//											MagicCoordinate.Z += 0.5 * Gravity * BulletTravelTime * BulletTravelTime * 5.0f;
//
//									}
//									FLOAT xDif = MagicCoordinate.X - MyPosition.X;
//									FLOAT yDif = MagicCoordinate.Y - MyPosition.Y;
//									FLOAT zDif = MagicCoordinate.Z - MagicCoordinate.Z;
//									float Hyp = sqrt(xDif * xDif + yDif * yDif);
//
//									VECTOR3 Coordinate;
//									Coordinate.X = 0;
//									Coordinate.Y = 0;
//									Coordinate.X = atan2(zDif, Hyp) * 180.0f / 3.1415926535897f;
//									Coordinate.Y = atan2(yDif, xDif) * 180.0f / 3.1415926535897f;
//
//								
//									//VECTOR3 Aim = GetainmRotation(MagicCoordinate);
//									Utility::WriteMemoryEx<FLOAT>(MagicBulletHook + 44, Coordinate.X);
//									Utility::WriteMemoryEx<FLOAT>(MagicBulletHook + 54, Coordinate.Y);
//
//								}
//							}
//						}
//
//						// Refresh magic
//						if (GetAsyncKeyState(0x52) & 1)//r
//						{
//							if (IsMagicInitialized == true && Setting::MagicBulletticked)
//							{
//								if (Data::NetDriver > 0)
//								{
//									IsMagicInitialized = false;
//									GetMagicAddress();
//									HookMagic();
//									IsMagicInitialized = true;
//								}
//							}
//						}
//					}
//					else {
//						if (Setting::MagicBulletticked) {
//							RestoreHook();
//						//	Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 26, 0xbc);
//						//	Utility::WriteMemoryEx<BYTE>(MagicBulletHook + 35, 0x03);
//						}
//					}
//
//				}
//				if (Setting::IpadView) {
//					//Utility::WriteMemoryEx<float>(Data::PlayerCameraManager + Offset::PlayerCameraManager1::CameraCache + 0x10 + 0x24, Setting::IpadViewValue);//FOR IPAD FOV
//					DWORD CAEMRACOMONENT = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + 0x1328);
//					Utility::WriteMemoryEx<float>(CAEMRACOMONENT + 0x260, Setting::IpadViewValue);
//				}
//				if (Setting::ForceTPP)
//				{
//					Utility::WriteMemoryEx<bool>((Data::LocalPlayer + Offset::bIsFPPOnVehicle/*bool IsNetFPPt*/), false);
//					Utility::WriteMemoryEx<bool>((Data::LocalPlayer + Offset::IsNetFPP/*bool IsFPP*/), false);
//					Utility::WriteMemoryEx<bool>((Data::LocalPlayer + Offset::IsFPP/*bool IsFPP*/), false);
//					Utility::WriteMemoryEx<bool>((Data::GameState + Offset::IsFPPGameMode), false);
//
//					//DWORD CAEMRACOMONENT = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + 0x1330);//CameraComponent* FPPCameraComp;//[Offset: 0x1330, Size: 4]
//					//DWORD THridPers = Utility::ReadMemoryEx<float>(Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + 0x1328) + 0x260);
//					//Utility::WriteMemoryEx<float>(CAEMRACOMONENT + 0x260, Setting::ttpview);
//
//
//				}
//				if (Setting::MagicBullet == false && IsMagicInitialized == true)// && WasBuggedHook == false)
//				{
//					RestoreHook();
//					MagicBulletList.clear();
//					VirtualFreeEx(Game::hProcess, (LPVOID)MagicBulletHook, 0, MEM_RELEASE);
//					MagicBulletAddress = 0;
//					MagicBulletHook = 0;
//					ZeroMemory(RealByteCode, sizeof(RealByteCode));
//					IsMagicInitialized = false;
//				}
//
//				if ( Setting::instanthit || Setting::FastWeponSwith || Setting::recoil || Setting::XEffect || Setting::fastShoot || Setting::fastrun || Setting::speedcar || Setting::ScopeZoom|| Setting::IpadView || Setting::ForceTPP)
//				{
//					if (WeaponCheatsEnabled == false)
//					{
//					//Utility::WriteMemoryEx<DWORD>(Data::LocalPlayer + 0xf70, 0);
//					//Utility::WriteMemoryEx<DWORD>(Data::LocalPlayer + 0x1774, 0); // PlayerAntiCheatManager)
//					//Utility::WriteMemoryEx<bool>(Data::LocalPlayer + 0x1778, false);// UseAntiCheat)
//					//Utility::WriteMemoryEx<DWORD>(Data::ShootWeaponEntity + 0xcb8, 0);// WeaponAntiCheatManager)
//					 
//						Thread::instanthitThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Memory::WeaponCheats, 0, 0, 0);
//						CloseHandle(Thread::instanthitThread);
//						WeaponCheatsEnabled = true;
//					}
//
//				} 
//				 
//			}
//
//			std::this_thread::sleep_for(std::chrono::milliseconds(10));
//		}
//		catch (int e)
//		{
//			std::cout << e << std::endl;
//		}
//	}
//}

#define skissssssn *(int*)(*(int*)(*(int*)(*(int*)(*(int*)(0x56E30000 + 0x8ED64EC) + 0x0) + 0x24c) + 0x1E0) + 0x2A0)
int Memory::skinssss() {
	int detectLobby = *(int*)(0x56E30000 + 0x8CF57AC);
	//DWORD skissssssn = *(int*)(*(int*)(*(int*)(*(int*)(*(int*)(0x56E30000 + 0x8ED64EC) + 0x0) + 0x24c) + 0x1E0) + 0x2A0);
	//auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	//DWORD skin = *(int*)(*(int*)(*(int*)(*(int*)(*(int*)(0x56E30000 + 0x8ED64EC) + 0x0) + 0x24c) + 0x1E0) + 0x2A0);
	if (detectLobby != 1) {
		DWORD skin = *(int*)(*(int*)(*(int*)(*(int*)(*(int*)(0x56E30000 + 0x8ED64EC) + 0x0) + 0x24c) + 0x1E0) + 0x2A0);
	}
	
	return 1;
}



VOID Memory::WeaponCheats() {

	//auto MainPointer = get_value<DWORD>(get_value<DWORD>(get_value<DWORD>(get_value<DWORD>(0xE0C3868 + Data::LocalPlayer) + 0x0) + 0x24c) + 0x1E0) + 0x2A0; //Method 2

	while (true)
	{

		if (Setting::XXXX) {
			if (Data::LocalController != 0) {
				LinearColor XeffectColor;
				LinearColor XeffectColorHead;
				if (Setting::XEffectRandomBody)
				{
					XeffectColor = RandomColor();
				}
				else
				{
					XeffectColor = ToLinerColor(Setting::XEffectBodyColor);
				}
				if (Setting::XEffectRandomHead)
				{
					XeffectColorHead = RandomColor2();
				}
				else
				{
					XeffectColorHead = ToLinerColor(Setting::XEffectHeadColor);
				}
				DWORD LocalController = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::STExtraPlayerCharacter::STPlayerController);
				DWORD HUD = Utility::ReadMemoryEx<DWORD>(LocalController + Offset::MyHUD);
				if (HUD != 0)
				{
					////////Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x20, 9.0f);
					//////Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x28, 44.0f);
					//////Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x10, 100.0f);
					//////Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x24, 66.0f);
					////////Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0xC, 99999.0f);
					//////Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x48, 66.0f);
					//////Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x84, 66.0f);
					//////Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0xC0, 66.0f);
					//////
					Utility::WriteMemoryEx<LinearColor>(HUD + Offset::HitPerform + 0x30, XeffectColor);
					Utility::WriteMemoryEx<LinearColor>(HUD + Offset::HitPerform + 0x40, XeffectColorHead);
					Utility::WriteMemoryEx<LinearColor>(HUD + Offset::HitPerform + 0x50, XeffectColor);
					Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x10, Setting::XeffectLineSize);//100.0f

				}

			}

		}






	}
		////////////////if (Setting::fastrun)
		//{
		//	if (GetAsyncKeyState(Setting::fastrunkey) & 0x8000) {
		//		float write = Setting::fastrv;
		//		CharacterOverrideAttrs ar;
		//		ar.GameModeOverride_EnergySpeedScaleModifier = write;
		//		ar.GameModeOverride_LastBreathSpeedScaleModifier = write;
		//		ar.GameModeOverride_SpeedScaleModifier = write;
		//		ar.GameModeOverride_SwimSpeedScaleModifier = write;
		//		Utility::WriteMemoryEx<CharacterOverrideAttrs>(Data::LocalPlayer + Offset::CharacterOverrideAttrs, ar);
		//	}
		//	else {
		//		Utility::WriteMemoryEx<float>(Data::LocalPlayer + Offset::CharacterOverrideAttrs, 1.0f);
		//	}
		//
		//}
		////////////////if (Setting::speedcar)
		//{
		//	if (GetAsyncKeyState(Setting::FastCarKeys) & 0x8000) {
		//		auto currentvehicla = Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::VehicleMovement) + 0x194) + 0x58);
		//		if (currentvehicla)
		//		{
		//
		//			//RepMovement rep = Utility::ReadMemoryEx<RepMovement>(currentvehicla + Offset::ReplicatedMovement);
		//			//VECTOR3 Velocity = rep.LinearVelocity;
		//			//Velocity.X = (float)Setting::carsv;
		//
		//			Utility::WriteMemoryEx<float>(currentvehicla, (float)Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 4, (float)Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 8, (float)Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 12, (float)Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 16, (float)Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 20, (float)Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 24, (float)Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 28, (float)Setting::carsv);
		//
		//		}
		//	}
		//	else if (GetAsyncKeyState('S') & 0x8000) {
		//		auto currentvehicla = Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::VehicleMovement) + 0x194) + 0x58);
		//		if (currentvehicla)
		//		{
		//
		//			//RepMovement rep = Utility::ReadMemoryEx<RepMovement>(currentvehicla + Offset::ReplicatedMovement);
		//			//VECTOR3 Velocity = rep.LinearVelocity;
		//			//Velocity.X = (float)Setting::carsv;
		//
		//			Utility::WriteMemoryEx<float>(currentvehicla, (float)-Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 4, (float)-Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 8, (float)-Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 12, (float)-Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 16, (float)-Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 20, (float)-Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 24, (float)-Setting::carsv);
		//			Utility::WriteMemoryEx<float>(currentvehicla + 28, (float)-Setting::carsv);
		//
		//		}
		//	}

		//}
		//////////////if (Data::CurrentReloadWeapon != 0)
		//////////////{
		//////////////	if (Data::ShootWeaponEntity != 0)
		//////////////	{
		//////////////		if (Setting::XXXX) {
				///	if (Data::LocalController != 0) {
				///		LinearColor XeffectColor;
				///		LinearColor XeffectColorHead;
				///		if (Setting::XEffectRandomBody)
				///		{
				///			XeffectColor = RandomColor();
				///		}
				///		else
				///		{
				///			XeffectColor = ToLinerColor(Setting::XEffectBodyColor);
				///		}
				///		if (Setting::XEffectRandomHead)
				///		{
				///			XeffectColorHead = RandomColor2();
				///		}
				///		else
				///		{
				///			XeffectColorHead = ToLinerColor(Setting::XEffectHeadColor);
				///		}
				///		DWORD HUD = Utility::ReadMemoryEx<DWORD>(Data::LocalController + Offset::MyHUD);
				///		if (HUD != 0)
				///		{
				///			Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x18, 9.0f);
				///			Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x24, 9.0f);
				///			Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x10, Setting::XeffectLineSize);//100.0f
				///			Utility::WriteMemoryEx<float>(HUD + Offset::HitPerform + 0x28, 35.00f);
				///			Utility::WriteMemoryEx<LinearColor>(HUD + Offset::HitPerform + 0x30, XeffectColor);
				///			Utility::WriteMemoryEx<LinearColor>(HUD + Offset::HitPerform + 0x40, XeffectColorHead);
				///			Utility::WriteMemoryEx<LinearColor>(HUD + Offset::HitPerform + 0x50, XeffectColor);
				///
				///		}
				///
				///	}
				///	
				///}
		//////////////		
		//////////////
		//////////////	
		//////////////
		//////////////	}
		//////////////}
		//if (Setting::IpadView) {
		//	//		Utility::WriteMemoryEx<float>(Data::PlayerCameraManager + Offset::PlayerCameraManager1::CameraCache + 0x10 + 0x24, Setting::IpadViewValue);//FOR IPAD FOV
		//	DWORD CAEMRACOMONENT = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + Offset::ThirdPersonCameraComponent);
		//	Utility::WriteMemoryEx<float>(CAEMRACOMONENT + 0x260, Setting::IpadViewValue);
		//}



		//if (Setting::ForceTPP)
		//					{
		//						Utility::WriteMemoryEx<bool>((Data::LocalPlayer + Offset::bIsFPPOnVehicle/*bool IsNetFPPt*/), false);
		//						Utility::WriteMemoryEx<bool>((Data::LocalPlayer + Offset::IsNetFPP/*bool IsFPP*/), false);
		//						Utility::WriteMemoryEx<bool>((Data::LocalPlayer + Offset::IsFPP/*bool IsFPP*/), false);
		//						Utility::WriteMemoryEx<bool>((Data::GameState + Offset::IsFPPGameMode), false);
		//	
		//						DWORD CAEMRACOMONENT = Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + 0x1330);//CameraComponent* FPPCameraComp;//[Offset: 0x1330, Size: 4]
		//						DWORD THridPers = Utility::ReadMemoryEx<float>(Utility::ReadMemoryEx<DWORD>(Data::LocalPlayer + 0x1328) + 0x260);
		//						Utility::WriteMemoryEx<float>(CAEMRACOMONENT + 0x260, Setting::ttpview);
		//	
		//	
		//					}




		std::this_thread::sleep_for(std::chrono::milliseconds(10));

//	}

}
//VOID Memory::MODSKIN()
//{
//	bool IsChanged = false;
//	while (true)
//	{
//		Sleep(15);
//		//--------
//		if (Setting::M416Glacier && IsChanged == false)
//		{
//			BYTE pattern[] = { 0x89 ,0x1E,0x06 ,0x00 };
//			BYTE patter2[] = { 0x6C ,0x91 ,0x6B ,0x02 };
//			DWORD bytes;
//			std::vector<DWORD_PTR> foundedBases2;
//			DWORD oldprotect, temps;
//			foundedBases2.clear();
//			Utility::FindPattern(pattern, sizeof(pattern), 0x10000000, 0xF0000000, false, 0, foundedBases2);
//
//			for (int i = 0; i < foundedBases2.size(); i++)
//			{
//				VirtualProtectEx(Game::hProcess, LPVOID(foundedBases2[i]), 4, PAGE_EXECUTE_READWRITE, &oldprotect);
//				WriteProcessMemory(Game::hProcess, (PVOID)foundedBases2[i], patter2, sizeof(patter2), nullptr);
//				VirtualProtectEx(Game::hProcess, LPVOID(foundedBases2[i]), 4, oldprotect, &temps);
//
//			}
//			IsChanged = true;
//		}
//		else if (!Setting::M416Glacier && IsChanged == true)
//		{
//			BYTE pattern[] = { 0x89 ,0x1E,0x06 ,0x00 };
//			BYTE patter2[] = { 0x6C ,0x91 ,0x6B ,0x02 };
//			DWORD bytes;
//			std::vector<DWORD_PTR> foundedBases;
//			DWORD oldprotect, temps;
//			foundedBases.clear();
//
//			//    Memory::FindPattern(pattern, 28, 0x10000000, 0x90000000, false, 0, foundedBases);
//			//Utility::MemSearch(patter2, sizeof(patter2), 0x10000000, 0x90000000, false, 0, foundedBases);
//			//	Utility::MemSearch(pattern, sizeof(pattern), 0x10000000, 0x90000000, false, 0, foundedBases2);
//			Utility::FindPattern(patter2, sizeof(patter2), 0x10000000, 0xF0000000, false, 0, foundedBases);
//			for (int i = 0; i < foundedBases.size(); i++)
//			{
//				VirtualProtectEx(Game::hProcess, LPVOID(foundedBases[i]), 4, PAGE_EXECUTE_READWRITE, &oldprotect);
//				WriteProcessMemory(Game::hProcess, (PVOID)foundedBases[i], pattern, sizeof(pattern), nullptr);
//				VirtualProtectEx(Game::hProcess, LPVOID(foundedBases[i]), 4, oldprotect, &temps);
//
//			}
//			IsChanged = false;
//		}
//		if (Setting::M416Glacier)
//			std::this_thread::sleep_for(std::chrono::milliseconds(70));
//		else {
//			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//		}
//	}
//}

BYTE FlyCarSearch[] = { 0x00, 0x00, 0x75, 0xC4, 0x00, 0x00, 0x7A, 0x45, 0x9A, 0x99 };
VOID SetFlyCarAddress()
{
	std::vector<DWORD_PTR> FoundedBase;
	Utility::FindPattern(FlyCarSearch, sizeof(FlyCarSearch), 0x10000000, 0xA0000000, 0, 0, FoundedBase);
	FlyCarAddress = FoundedBase[0];
}

