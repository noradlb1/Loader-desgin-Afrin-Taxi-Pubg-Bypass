#include "Aimbot.h"
#include"Memory.h"
#include<thread>


bool Aimbot::InsideFov(float OverlayScreenWidth, float OverlayScreenHeight, VECTOR2 PlayerW2SBone, float FovRadius)
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

VECTOR2 Aimbot::GetClosestEnemy1()
{
	float targetDistance = 9999.0;
	VECTOR2 retval;
	int dist, headdist;
	VECTOR2 ret;
	for (int i = 0; i < Data::AActorList.size(); i++) {
		DWORD tmpAddv = Utility::ReadMemoryEx<INT>(Data::AActorList[i].Address + Offset::Mesh);
		DWORD bodyAddv = tmpAddv + Offset::BodyAddv;
		DWORD boneAddv = Utility::ReadMemoryEx<INT>(tmpAddv + Offset::MinLOD) + 48;

		VECTOR2 chest;
		VECTOR2 head;
		VECTOR3 chestPos = Data::AActorList[i].HeadPos;//  Algorithm::GetBoneWorldPosition(bodyAddv, boneAddv + 4 * 48);
		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, chestPos, chest, &dist))
		{
			if (Setting::fovcircle)
			{
				if (InsideFov(DX11Window::Width, DX11Window::Height, chest, Setting::fovcircleredus/*FovRadius*/))
				{
					float cross_dist = sqrt(pow(chest.X - DX11Window::Width / 2, 2) + pow(chest.Y - DX11Window::Height / 2, 2));
					if (cross_dist < targetDistance)
					{
						ret = chest;
						targetDistance = cross_dist;

					}
				}
			}
			else
			{
				if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, chestPos, chest, &dist))
				{
					float cross_dist = sqrt(pow(chest.X - DX11Window::Width / 2, 2) + pow(chest.Y - DX11Window::Height / 2, 2));

					if (cross_dist < targetDistance)
					{
						ret = chest;
						targetDistance = cross_dist;

					}
				}
			}
		}
	}
	return ret;
}
VECTOR3 Subtract1(VECTOR3 Src, VECTOR3 Dst)
{
	VECTOR3 Result;
	Result.X = Src.X - Dst.X;
	Result.Y = Src.Y - Dst.Y;
	Result.Z = Src.Z - Dst.Z;

	return Result;
}
float Magnitude1(VECTOR3 Vec)
{
	return sqrtf(Vec.X * Vec.X + Vec.Y * Vec.Y + Vec.Z * Vec.Z);
}

float GetDistance1(VECTOR3 Src, VECTOR3 Dst)
{
	VECTOR3 Result = Subtract1(Src, Dst);
	return Magnitude1(Result);
}

VECTOR2 Aimbot::GetClosestEnemy()
{
	VECTOR2 Coordinate;
	Coordinate.X = 0;
	Coordinate.Y = 0;
	VECTOR3 HeadPos;
	HeadPos.X = 0;
	HeadPos.Y = 0;
	HeadPos.Z = 0;
	VECTOR2 Screen;
	VECTOR2 returnv{};
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


	for (AActor& AActor : Data::AActorList)
	{
		if (Setting::curraim == 0)
		{
			HeadPos = AActor.HeadPos;
		//	HeadPos.Z += Setting::magicv;
		}
		if (Setting::curraim == 1)
		{
			HeadPos = AActor.ChestPos;
		}
		if (Setting::curraim == 2)
		{
			HeadPos = AActor.PelvisPos;
		}


		if (Algorithm::WorldToScreenBone(Esp::ViewMatrix, HeadPos, Screen, &Distance4))
		{
	
			CrossDist = sqrt(pow(Screen.X - DX11Window::Width / 2, 2) + pow(Screen.Y - DX11Window::Height / 2, 2));

			if (CrossDist < TargetDistance)
			{ 
				TargetDistance = CrossDist;
				returnv = Screen;
			}

		}

	}
 

 
	return returnv;
}


void MoveMouse(int x, int y) {
	int buffer;
	for (buffer = 0; x >= buffer && y >= buffer; buffer++) {
		SetCursorPos(x, y);
		//Sleep(1);
	}
}
void MouseMoveInput(float x, float y)
{
 	{
		INPUT Input = { 0 };
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_MOVE;
		Input.mi.dx = x;
		Input.mi.dy = y;
		SendInput(1, &Input, sizeof(INPUT));

	}

}

VOID Aimbot::AimbotThread()
{
	INT Num = 0;
	INT Num2 = 0;
//	FLOAT Setting::Aimspeed = 0;
	FLOAT Num4 = 0;
	FLOAT Num5 = 0;
	int dis;
	VECTOR2 Head;
	Head.X = 0;
	Head.Y = 0;
	FLOAT X = 0;
	FLOAT Y = 0;

	while (true)
	{
		VECTOR2 MagicCoordinate{};
		//Sleep(10);
		if (Setting::Aimbot)
		{
			 
				if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000)) // Left Mouse button
				{
					 Head = GetClosestEnemy();
					//if (Data::AimingCoordinates.X == 0&& Data::AimingCoordinates.Y == 0)continue;
				//	if (Algorithm::WorldToScreen(Data::AimingCoordinates, Head, &dis, Esp::ViewMatrix))
					{
						if ((Head.X > 0 && Head.Y > 0))
						{
							Num = DX11Window::Width / 2;
							Num2 = DX11Window::Height / 2;
							//Setting::Aimspeed = 11;  // Aim speed
							Num4 = 0.0f;
							Num5 = 0.0f;

							X = Head.X;
							Y = Head.Y;

							if (X > 0)
							{
								if (X > (float)Num)
								{
									Num4 = -((float)Num - X);
									Num4 /= Setting::Aimspeed;
									if (Num4 + (float)Num > (float)(Num * 2))
									{
										Num4 = 0.0f;
									}
								}

								if (X < (float)Num)
								{
									Num4 = X - (float)Num;
									Num4 /= Setting::Aimspeed;
									if (Num4 + (float)Num < 0.0f)
									{
										Num4 = 0.0f;
									}
								}
							}

							if (Y > 0)
							{
								if (Y > (float)Num2)
								{
									Num5 = -((float)Num2 - Y);
									Num5 /= Setting::Aimspeed;
									if (Num5 + (float)Num2 > (float)(Num2 * 2))
									{
										Num5 = 0.0f;
									}
								}

								if (Y < (float)Num2)
								{
									Num5 = Y - (float)Num2;
									Num5 /= Setting::Aimspeed;
									if (Num5 + (float)Num2 < 0.0f)
									{
										Num5 = 0.0f;
									}
								}
							}
							MouseMoveInput((int)Num4, (int)Num5);
							//mouse_event(1U, (int)Num4, (int)Num5, NULL, NULL);
						}
					} 
				} 
		}
		
		std::this_thread::sleep_for(std::chrono::milliseconds(40));
	}
}