#include "Algorithm.h"

BOOL Algorithm::WorldToScreen(VECTOR3 LPosition, VECTOR3 Position, VECTOR3& Screen, INT* Distance, D3DMATRIX ViewMatrix)
{
	FLOAT ScreenW = (ViewMatrix._14 * Position.X) + (ViewMatrix._24 * Position.Y) + (ViewMatrix._34 * Position.Z + ViewMatrix._44);
	*Distance = LPosition.Distance(Position) / 100.f;
	//auto Distance = LPosition.Distance(Position) / 100.f;
	if (ScreenW < 0.0001f) return FALSE;

	ScreenW = 1 / ScreenW;
	FLOAT SightX = (DX11Window::Width / 2);
	FLOAT SightY = (DX11Window::Height / 2);

	Screen.X = SightX + (ViewMatrix._11 * Position.X + ViewMatrix._21 * Position.Y + ViewMatrix._31 * Position.Z + ViewMatrix._41) * ScreenW * SightX;
	Screen.Y = SightY - (ViewMatrix._12 * Position.X + ViewMatrix._22 * Position.Y + ViewMatrix._32 * Position.Z + ViewMatrix._42) * ScreenW * SightY;

	return TRUE;
}

VECTOR3 WorldToRadar(float Yaw, VECTOR3 Origin, VECTOR3 LocalOrigin, float PosX, float PosY, VECTOR3 Size, bool& outbuff)
{
	bool flag = false;
	double num = (double)Yaw;
	double num2 = num * 0.017453292519943295;
	float num3 = (float)std::cos(num2);
	float num4 = (float)std::sin(num2);
	float num5 = Origin.X - LocalOrigin.X;
	float num6 = Origin.Y - LocalOrigin.Y;
	VECTOR3 vector;
	vector.X = (num6 * num3 - num5 * num4) / 150.f;
	vector.Y = (num5 * num3 + num6 * num4) / 150.f;
	VECTOR3 vector2;
	vector2.X = vector.X + PosX + Size.X / 2.f;
	vector2.Y = -vector.Y + PosY + Size.Y / 2.f;
	bool flag2 = vector2.X > PosX + Size.X;
	if (flag2)
	{
		vector2.X = PosX + Size.X;
	}
	else
	{
		bool flag3 = vector2.X < PosX;
		if (flag3)
		{
			vector2.X = PosX;
		}
	}
	bool flag4 = vector2.Y > PosY + Size.Y;
	if (flag4)
	{
		vector2.Y = PosY + Size.Y;
	}
	else
	{
		bool flag5 = vector2.Y < PosY;
		if (flag5)
		{
			vector2.Y = PosY;
		}
	}
	bool flag6 = vector2.Y == PosY || vector2.X == PosX;
	if (flag6)
	{
		flag = true;
	}
	outbuff = flag;
	return vector2;
}
void VectorAnglesRadar(VECTOR3& forward, VECTOR3& angles)
{
	if (forward.X == 0.f && forward.Y == 0.f)
	{
		angles.X = forward.Z > 0.f ? -90.f : 90.f;
		angles.Y = 0.f;
	}
	else
	{
		angles.X = RAD2DEG(atan2(-forward.Z, forward.Size()));
		angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
	}
	angles.Z = 0.f;
}

VECTOR3 ToVECTOR3(float x, float y, float z)
{
	VECTOR3 tem;
	tem.X = x;
	tem.Y = y;
	tem.Z = z;
	return tem;
}
BOOL Algorithm::WorldToScreenPlayer(VECTOR3 LPosition, VECTOR3 Position, VECTOR3& Screen, INT* Distance, D3DMATRIX ViewMatrix)
{



	FLOAT ScreenW = (ViewMatrix._14 * Position.X) + (ViewMatrix._24 * Position.Y) + (ViewMatrix._34 * Position.Z + ViewMatrix._44);
	//	*Distance = (ScreenW / 100);	
	*Distance = LPosition.Distance(Position) / 100.f;
	//if (ScreenW < 0.0001f) return FALSE;

	FLOAT ScreenX = (ViewMatrix._11 * Position.X) + (ViewMatrix._21 * Position.Y) + (ViewMatrix._31 * Position.Z + ViewMatrix._41);
	FLOAT ScreenY = (ViewMatrix._12 * Position.X) + (ViewMatrix._22 * Position.Y) + (ViewMatrix._32 * (Position.Z + 85) + ViewMatrix._42);

	Screen.X = (DX11Window::Width / 2) + (DX11Window::Width / 2) * ScreenX / ScreenW;
	Screen.Y = (DX11Window::Height / 2) - (DX11Window::Height / 2) * ScreenY / ScreenW;
	FLOAT Y1 = (DX11Window::Height / 2) - (ViewMatrix._12 * Position.X + ViewMatrix._22 * Position.Y + ViewMatrix._32 * (Position.Z - 95) + ViewMatrix._42) * (DX11Window::Height / 2) / ScreenW;
	Screen.Z = Y1 - Screen.Y;

	return TRUE;
}

BOOL Algorithm::WorldToScreenBone(D3DMATRIX ViewMatrix, VECTOR3 Position, VECTOR2& Screen, INT* Distance)
{

	FLOAT ScreenW = (ViewMatrix._14 * Position.X) + (ViewMatrix._24 * Position.Y) + (ViewMatrix._34 * Position.Z + ViewMatrix._44);
	*Distance = (ScreenW / 100);
	if (ScreenW < 0.0001f) return FALSE;

	ScreenW = 1 / ScreenW;
	FLOAT SightX = (DX11Window::Width / 2);
	FLOAT SightY = (DX11Window::Height / 2);

	Screen.X = SightX + (ViewMatrix._11 * Position.X + ViewMatrix._21 * Position.Y + ViewMatrix._31 * Position.Z + ViewMatrix._41) * ScreenW * SightX;
	Screen.Y = SightY - (ViewMatrix._12 * Position.X + ViewMatrix._22 * Position.Y + ViewMatrix._32 * Position.Z + ViewMatrix._42) * ScreenW * SightY;

	return TRUE;
}

D3DMATRIX Algorithm::ToMatrixWithScale(VECTOR3 translation, VECTOR3 scale, VECTOR4 rot)
{
	D3DMATRIX m;
	m._41 = translation.X;
	m._42 = translation.Y;
	m._43 = translation.Z;

	float x2 = rot.X + rot.X;
	float y2 = rot.Y + rot.Y;
	float z2 = rot.Z + rot.Z;

	float xx2 = rot.X * x2;
	float yy2 = rot.Y * y2;
	float zz2 = rot.Z * z2;
	m._11 = (1.0f - (yy2 + zz2)) * scale.X;
	m._22 = (1.0f - (xx2 + zz2)) * scale.Y;
	m._33 = (1.0f - (xx2 + yy2)) * scale.Z;

	float yz2 = rot.Y * z2;
	float wx2 = rot.W * x2;
	m._32 = (yz2 - wx2) * scale.Z;
	m._23 = (yz2 + wx2) * scale.Y;

	float xy2 = rot.X * y2;
	float wz2 = rot.W * z2;
	m._21 = (xy2 - wz2) * scale.Y;
	m._12 = (xy2 + wz2) * scale.X;

	float xz2 = rot.X * z2;
	float wy2 = rot.W * y2;
	m._31 = (xz2 + wy2) * scale.Z;
	m._13 = (xz2 - wy2) * scale.X;

	m._14 = 0.0f;
	m._24 = 0.0f;
	m._34 = 0.0f;
	m._44 = 1.0f;

	return m;
}

D3DMATRIX Algorithm::MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
{
	D3DMATRIX pOut =
	{
		pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41,
		pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42,
		pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43,
		pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44,
		pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41,
		pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42,
		pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43,
		pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44,
		pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41,
		pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42,
		pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43,
		pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44,
		pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41,
		pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42,
		pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43,
		pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44
	};

	return pOut;
}
LinearColor ToLinerColor(float Input[4]) {
	LinearColor Ouput;
	Ouput.R = Input[0];
	Ouput.G = Input[1];
	Ouput.B = Input[2];
	Ouput.A = Input[3];

	return Ouput;
}
LinearColor RandomColor() {

	static float x = 0, y = 0;
	static float r = 0, g = 0, b = 0;

	if (y >= 0.0f && y < 255.0f) {
		r = 255.0f;
		g = 0.0f;
		b = x;
	}
	else if (y >= 255.0f && y < 510.0f) {
		r = 255.0f - x;
		g = 0.0f;
		b = 255.0f;
	}
	else if (y >= 510.0f && y < 765.0f) {
		r = 0.0f;
		g = x;
		b = 255.0f;
	}
	else if (y >= 765.0f && y < 1020.0f) {
		r = 0.0f;
		g = 255.0f;
		b = 255.0f - x;
	}
	else if (y >= 1020.0f && y < 1275.0f) {
		r = x;
		g = 255.0f;
		b = 0.0f;
	}
	else if (y >= 1275.0f && y < 1530.0f) {
		r = 255.0f;
		g = 255.0f - x;
		b = 0.0f;
	}

	x += 1.25f; //increase this value to switch colors faster
	if (x >= 255.0f)
		x = 0.0f;

	y += 1.25f; //increase this value to switch colors faster
	if (y > 1530.0f)
		y = 0.0f;


	return { (float)r, (float)g, (float)b, 255 };
}
LinearColor RandomColor2() {

	static float x = 0, y = 0;
	static float r = 0, g = 0, b = 0;

	if (y >= 0.0f && y < 255.0f) {
		r = 255.0f;
		g = 0.0f;
		b = x;
	}
	else if (y >= 255.0f && y < 510.0f) {
		r = 255.0f - x;
		g = 0.0f;
		b = 255.0f;
	}
	else if (y >= 510.0f && y < 765.0f) {
		r = 0.0f;
		g = x;
		b = 255.0f;
	}
	else if (y >= 765.0f && y < 1020.0f) {
		r = 0.0f;
		g = 255.0f;
		b = 255.0f - x;
	}
	else if (y >= 1020.0f && y < 1275.0f) {
		r = x;
		g = 255.0f;
		b = 0.0f;
	}
	else if (y >= 1275.0f && y < 1530.0f) {
		r = 255.0f;
		g = 255.0f - x;
		b = 0.0f;
	}

	x += 2.25f; //increase this value to switch colors faster
	if (x >= 255.0f)
		x = 0.0f;

	y += 2.25f; //increase this value to switch colors faster
	if (y > 1530.0f)
		y = 0.0f;


	return { (float)r, (float)g, (float)b, 255 };
}
VECTOR3 Algorithm::GetBoneWorldPosition(DWORD ActorAddv, DWORD BoneAddv)
{
	FTTransform Bone = Utility::ReadMemoryEx<FTTransform>(BoneAddv);
	FTTransform Actor = Utility::ReadMemoryEx<FTTransform>(ActorAddv);
	D3DMATRIX BoneMatrix = ToMatrixWithScale(Bone.Translation, Bone.Scale3D, Bone.Rotation);
	D3DMATRIX ComponentToWorldMatrix = ToMatrixWithScale(Actor.Translation, Actor.Scale3D, Actor.Rotation);
	D3DMATRIX NewMatrix = MatrixMultiplication(BoneMatrix, ComponentToWorldMatrix);

	VECTOR3 BonePos;
	BonePos.X = NewMatrix._41;
	BonePos.Y = NewMatrix._42;
	BonePos.Z = NewMatrix._43;

	return BonePos;
}

void Algorithm::AddLine(const ImVec2& from, const ImVec2& to, const ImColor Color, float thickness)
{
	auto window = ImGui::GetCurrentWindow();

	window->DrawList->AddLine(from, to, ImGui::ColorConvertFloat4ToU32(Color), thickness);
}
void Algorithm::Draw3Dcircle(D3DMATRIX matrix, VECTOR3 LPosition, VECTOR3 position, float points, float radius, float thickness, ImColor Color)
{
	int dist;
	float step = (float)IM_PI * 2.0f / points;

	for (float a = 0; a < (IM_PI * 2.0f); a += step)
	{
		VECTOR3 start = { radius * cosf(a) + position.X,
			radius * sinf(a) + position.Y,
			position.Z };


		VECTOR3 end = {
			radius * cosf(a + step) + position.X,
			radius * sinf(a + step) + position.Y,
			position.Z
		};

		VECTOR3 start2d, end2d;

		if (!Algorithm::WorldToScreen(LPosition, start, start2d, &dist, matrix) || !Algorithm::WorldToScreen(LPosition, end, end2d, &dist, matrix))
			return;
		DX11::ImGui_DX11::DrawLine(start2d.X, start2d.Y, end2d.X, end2d.Y, Color, thickness);

	}
}