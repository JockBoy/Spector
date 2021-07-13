#include "MainForm.h"
#include "Threads.h"
#include "MemUtil.h"
#include "Offsets.h"
#include <chrono>
#include<iostream>

using namespace System::Windows::Forms;
using namespace System::Diagnostics;
using namespace Spector;
using namespace std;
using std::chrono::milliseconds;

namespace Threads
{
	int screenWidth = 1920;
	int screenHeight = 1080;
	int crosshairX = screenWidth / 2;
	int crosshairY = screenHeight / 2;
	bool triggerState = false;
	int prevTriggerMs = 0;

	void MainThread() {
		srand(time(NULL));
		WaitForProcessLaunch("r5apex.exe");
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ItemGlow, NULL, 0, NULL);
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PlayerGlow, NULL, 0, NULL);
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)AimBot, NULL, 0, NULL);
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)TriggerBot, NULL, 0, NULL);
	}

	void LeftClick() {
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		Sleep(50 + (rand() % 50));
		//Sleep(400 + (rand() % 100));
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		Sleep(10 + (rand() % 15));
		//Sleep(10 + (rand() % 50));
	}

	int GetSystemMilliseconds() {
		auto t = chrono::high_resolution_clock::now();
		return t.time_since_epoch().count();
	}

	void ItemGlow() {
		while (true)
		{
			for (int i = 0; i < 10000; i++) // TODO: Å“K’l
			{
				DWORD64 Entity = GetEntityById(i);
				if (Entity == 0) continue;
				int ItemId = Read<int>(Entity + OFFSET_ITEM_ID);
				if (ItemId <= 0 || ItemId > 255) continue;

				char Contain = 0;
				Contain = MainForm::ItemGlowList1->Contains(ItemId) ? 1 : Contain;
				Contain = MainForm::ItemGlowList2->Contains(ItemId) ? 2 : Contain;
				Contain = MainForm::ItemGlowList3->Contains(ItemId) ? 3 : Contain;

				if (MainForm::IsEnableItemGlow && !!Contain) {
					Color TargetColor;
					switch (Contain) {
					case 1: TargetColor = MainForm::IGColor1; break;
					case 2: TargetColor = MainForm::IGColor2; break;
					case 3: TargetColor = MainForm::IGColor3; break;
					}
					Write<GlowColor>(Entity + GLOW_COLOR, {
						(float)TargetColor.R * 1.0f,
						(float)TargetColor.G * 1.0f,
						(float)TargetColor.B * 1.0f });
					Write<GlowMode>(Entity + GLOW_TYPE, { 101,101,46,90 });
					Write<int>(Entity + GLOW_CONTEXT, 1);
					Write<int>(Entity + GLOW_VISIBLE_TYPE, 2);
				} else {
					Write<int>(Entity + GLOW_CONTEXT, 0);
					Write<int>(Entity + GLOW_VISIBLE_TYPE, 0);
				}
				Sleep(5);
			}
			Sleep(1000);
		}
	}

	void PlayerGlow() {

		float entNewVisTime = 0;
		float entOldVisTime[120];
		
		while (true)
		{
			uintptr_t locPlayer = Read<uintptr_t>(base_address + OFFSET_LOCAL_ENT);

			for (int i = 0; i < 120; i++)
			{
				DWORD64 Entity = GetEntityById(i);
				if (Entity == 0) continue;

				DWORD64 nameData = Read<DWORD64>(Entity + OFFSET_NAME);
				if (nameData != 0x726579616C70) continue;

				int playerTeamID = Read<int>(locPlayer + OFFSET_TEAM);
				int entTeamID = Read<int>(Entity + OFFSET_TEAM);
				if (entTeamID == playerTeamID) continue;

				if (MainForm::IsEnablePlayerGlow) {
					entNewVisTime = Read<float>(Entity + OFFSET_VISIBLE_TIME);
					if (entNewVisTime < 0 || entNewVisTime > 10000) continue;

					int entKnockedState = Read<int>(Entity + OFFSET_BLEED_OUT_STATE);
					Color TargetColor;

					//Debug::WriteLine(i + ":" + (entOldVisTime[i] - entNewVisTime));
					// 
					// Is visible
					if (entNewVisTime != entOldVisTime[i])
					{
						TargetColor = entKnockedState == 0 ?
							MainForm::PGColorVisible : MainForm::PGColorDown;
					} else {
						TargetColor = entKnockedState == 0 ?
							MainForm::PGColorInvisible : MainForm::PGColorDown;
					}
					entOldVisTime[i] = entNewVisTime;
					
					Write<int>(Entity + GLOW_CONTEXT, 1);
					Write<int>(Entity + GLOW_VISIBLE_TYPE, 2);
					//Sleep(1);
					// GeneralGlowMode, BorderGlowMode, BorderSize, TransparentLevel
					Write<GlowMode>(Entity + GLOW_TYPE, { 101,101,46,90 });
					Sleep(1);
					Write<GlowColor>(Entity + GLOW_COLOR, {
						(float)TargetColor.R * 1.0f,
						(float)TargetColor.G * 1.0f,
						(float)TargetColor.B * 1.0f });
				} else {
					Write<int>(Entity + GLOW_CONTEXT, 0);
					Write<int>(Entity + GLOW_VISIBLE_TYPE, 0);
				}
				Sleep(1);
			}

			if (!MainForm::IsEnablePlayerGlow) {
				Sleep(1000);
			} else {
				Sleep(10);
			}
		}
	}

	void AimBot() {

		DWORD64 LockedEntity = 0;
		float LockedEntOldVisTime = 0;

		uintptr_t locPlayer = Read<uintptr_t>(base_address + OFFSET_LOCAL_ENT);

		while (true)
		{
			if (!MainForm::IsEnableAimBot) {
				Sleep(100);
				continue;
			}

			int xFOV = MainForm::AimbotFov;
			int yFOV = MainForm::AimbotFov;
			int triggerFovX = MainForm::TriggerbotFov;
			int triggerFovY = MainForm::TriggerbotFov;
			float aimSmoothAmount = MainForm::AimbotSmooth;
			float mouseSensitivity = MainForm::MouseSensitivity * 1.0f;
			float aimPosition = (float)MainForm::AimbotAimVirticalOffset * 1.0f;

			int aimKeyType = 1;
			aimKeyType = MainForm::AimbotAimKey == "Left" ? 1 : aimKeyType;
			aimKeyType = MainForm::AimbotAimKey == "Right" ? 2 : aimKeyType;
			aimKeyType = MainForm::AimbotAimKey == "Both" ? 3 : aimKeyType;

			bool isAimKeyPress = false;
			switch (aimKeyType) {
			case 1: isAimKeyPress = GetAsyncKeyState(VK_LBUTTON);  break;
			case 2: isAimKeyPress = GetAsyncKeyState(VK_RBUTTON);  break;
			case 3: isAimKeyPress = GetAsyncKeyState(VK_LBUTTON)
				|| GetAsyncKeyState(VK_RBUTTON);  break;
			}
			
			if (!isAimKeyPress) {
				LockedEntity = 0;
				continue;
			}

			int closestX = 9999;
			int closestY = 9999;

			float entOldVisTime[100];

			triggerState = false;

			DWORD64 closestEntity = 0;

			if (LockedEntity != 0) {
				Sleep(1);
				float entNewVisTime = Read<float>(LockedEntity + OFFSET_VISIBLE_TIME);
				if (entNewVisTime == LockedEntOldVisTime) continue;
				LockedEntOldVisTime = entNewVisTime;

				uint64_t viewRenderer = Read<uint64_t>(base_address + OFFSET_RENDER);
				uint64_t viewMatrix = Read<uint64_t>(viewRenderer + OFFSET_MATRIX);
				Matrix m = Read<Matrix>(viewMatrix);

				Vector3 entFeet = Read<Vector3>(LockedEntity + OFFSET_ORIGIN);
				Vector3 entAimPos = entFeet;
				entAimPos.z += aimPosition;
				Vector3 w2sEntFeet = _WorldToScreen(entFeet, m, screenWidth, screenHeight);
				if (w2sEntFeet.z <= 0.f) continue;
				Vector3 w2sEntAimPos = _WorldToScreen(entAimPos, m, screenWidth, screenHeight);
				if (w2sEntAimPos.z <= 0.f) continue;

				// If enemy knocked continue
				if (Read<int>(LockedEntity + OFFSET_BLEED_OUT_STATE) != 0) continue;
				closestX = w2sEntAimPos.x;
				closestY = w2sEntAimPos.y;
			}
			else
			{
				for (int x = 0; x < 5; x++)
				{
					for (int i = 0; i < 100; i++)
					{
						DWORD64 Entity = GetEntityById(i);
						if (Entity == 0) continue;

						DWORD64 nameData = Read<DWORD64>(Entity + OFFSET_NAME);
						if (nameData != 0x726579616C70) continue;

						int playerTeamID = Read<int>(locPlayer + OFFSET_TEAM);
						int entTeamID = Read<int>(Entity + OFFSET_TEAM);
						if (entTeamID == playerTeamID) continue;

						float entNewVisTime = Read<float>(Entity + OFFSET_VISIBLE_TIME);
						if (entNewVisTime <= 0 || entNewVisTime > 10000) continue;
						if (entNewVisTime == entOldVisTime[i]) continue;
						entOldVisTime[i] = entNewVisTime;

						uint64_t viewRenderer = Read<uint64_t>(base_address + OFFSET_RENDER);
						uint64_t viewMatrix = Read<uint64_t>(viewRenderer + OFFSET_MATRIX);
						Matrix m = Read<Matrix>(viewMatrix);

						Vector3 entFeet = Read<Vector3>(Entity + OFFSET_ORIGIN);
						Vector3 entAimPos = entFeet;
						entAimPos.z += aimPosition;
						Vector3 w2sEntFeet = _WorldToScreen(entFeet, m, screenWidth, screenHeight);
						if (w2sEntFeet.z <= 0.f) continue;
						Vector3 w2sEntAimPos = _WorldToScreen(entAimPos, m, screenWidth, screenHeight);
						if (w2sEntAimPos.z <= 0.f) continue;

						// If enemy knocked continue
						if (Read<int>(Entity + OFFSET_BLEED_OUT_STATE) != 0) continue;
						int entX = w2sEntAimPos.x;
						int entY = w2sEntAimPos.y;
						if (abs(crosshairX - entX) < xFOV && abs(crosshairY - entY) < yFOV)
						{ // Aimbot find closest target
							if (abs(entX - crosshairX) <= abs(crosshairX - closestX) ||
								abs(entY - crosshairY) <= abs(crosshairY - closestY)) {
								closestX = entX;
								closestY = entY;
								closestEntity = Entity;
							}
						}
					}
					Sleep(1);
				}
				
			}

			if (closestX == 9999 || closestY == 9999) continue;

			if (LockedEntity == 0) {
				LockedEntity = closestEntity;
			}

			if (MainForm::IsEnableTriggerBot) {
				if (abs(closestX - crosshairX) < triggerFovX &&
					abs(closestY - crosshairY) < triggerFovY)
				{
					triggerState = true;
				}
			}

			// enable aimbot when mouse cursor is hidden
			CURSORINFO ci = { sizeof(CURSORINFO) };
			if (GetCursorInfo(&ci) && ci.flags == 0) {
				int aX = ((closestX - crosshairX) / mouseSensitivity) / aimSmoothAmount;
				int aY = ((closestY - crosshairY) / mouseSensitivity) / aimSmoothAmount;
				mouse_event(MOUSEEVENTF_MOVE, aX, aY, 0, 0);
			}	
		}
	}

	void TriggerBot() {

		while (true)
		{
			
			if (!MainForm::IsEnableTriggerBot) {
				Sleep(100);
				continue;
			}

			if (MainForm::IsEnableAimBot) {
				if (triggerState) {
					bool isAimKeyPress = false;
					if (MainForm::TriggerbotKey == "Always") {
						isAimKeyPress = true;
					} else {
						isAimKeyPress = GetAsyncKeyState(VK_RBUTTON);
					}
					if (!isAimKeyPress) continue;

					CURSORINFO ci = { sizeof(CURSORINFO) };
					if (GetCursorInfo(&ci) && ci.flags == 0) LeftClick();
				}
				continue;
			}
			
			int xFOV = MainForm::TriggerbotFov;
			int yFOV = MainForm::TriggerbotFov;
			float aimPosition = (float)MainForm::AimbotAimVirticalOffset * 1.0f;

			uint64_t viewRenderer = Read<uint64_t>(base_address + OFFSET_RENDER);
			uint64_t viewMatrix = Read<uint64_t>(viewRenderer + OFFSET_MATRIX);
			Matrix m = Read<Matrix>(viewMatrix);
			uintptr_t locPlayer = Read<uintptr_t>(base_address + OFFSET_LOCAL_ENT);

			float entOldVisTime[100];

			for (int i = 0; i < 100; i++)
			{
				DWORD64 Entity = GetEntityById(i);
				if (Entity == 0) continue;

				int playerTeamID = Read<int>(locPlayer + OFFSET_TEAM);
				int entTeamID = Read<int>(Entity + OFFSET_TEAM);
				if (entTeamID == playerTeamID) continue;

				float entNewVisTime = Read<float>(Entity + OFFSET_VISIBLE_TIME);
				if (entNewVisTime < 0 || entNewVisTime > 10000) continue;

				Vector3 entFeet = Read<Vector3>(Entity + OFFSET_ORIGIN);
				Vector3 entAimPos = entFeet;
				entAimPos.z += aimPosition;
				Vector3 w2sEntFeet = _WorldToScreen(entFeet, m, screenWidth, screenHeight);
				if (w2sEntFeet.z <= 0.f) continue;
				Vector3 w2sEntAimPos = _WorldToScreen(entAimPos, m, screenWidth, screenHeight);
				if (w2sEntAimPos.z <= 0.f) continue;

				if (entNewVisTime != entOldVisTime[i])
				{
					int entX = w2sEntAimPos.x;
					int entY = w2sEntAimPos.y;
					if (abs(crosshairX - entX) < xFOV && abs(crosshairY - entY) < yFOV)
					{ 
						bool isAimKeyPress = false;
						if (MainForm::TriggerbotKey == "Always") {
							isAimKeyPress = true;
						} else {
							isAimKeyPress = GetAsyncKeyState(VK_RBUTTON);
						}
						if (!isAimKeyPress) continue;

						CURSORINFO ci = { sizeof(CURSORINFO) };
						if (GetCursorInfo(&ci) && ci.flags == 0) LeftClick();
					}
				}
				entOldVisTime[i] = entNewVisTime;
				Sleep(1);
			}
		}
	}

}
