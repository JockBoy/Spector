#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Collections;

public ref class Config
{
public:
	Config(void) { ; }
	System::Boolean isLoadError;

	Generic::List<String^>^ IGlow_StockList = gcnew Generic::List<String^>();
	Generic::List<String^>^ IGlow1_List = gcnew Generic::List<String^>();
	Generic::List<String^>^ IGlow2_List = gcnew Generic::List<String^>();
	Generic::List<String^>^ IGlow3_List = gcnew Generic::List<String^>();

	Byte IGlow1_ColorR;
	Byte IGlow1_ColorG;
	Byte IGlow1_ColorB;
	Byte IGlow2_ColorR;
	Byte IGlow2_ColorG;
	Byte IGlow2_ColorB;
	Byte IGlow3_ColorR;
	Byte IGlow3_ColorG;
	Byte IGlow3_ColorB;

	Byte PGlow_Visible_ColorR;
	Byte PGlow_Visible_ColorG;
	Byte PGlow_Visible_ColorB;
	Byte PGlow_Invisible_ColorR;
	Byte PGlow_Invisible_ColorG;
	Byte PGlow_Invisible_ColorB;
	Byte PGlow_Down_ColorR;
	Byte PGlow_Down_ColorG;
	Byte PGlow_Down_ColorB;

	Decimal Aimbot_Fov;
	Decimal Aimbot_Smooth;
	Decimal Aimbot_Offset;
	String^ Aimbot_AimKey;

	Decimal Triggerbot_Fov;
	Decimal Triggerbot_RDelay;
	String^ Triggerbot_Key;

	Byte WindowColor_R;
	Byte WindowColor_G;
	Byte WindowColor_B;
	Decimal MouseSensitivity;
};
