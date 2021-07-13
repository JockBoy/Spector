#pragma once

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
//#include <memory>
//#include <string_view>
//#include <cstdint>
//#include <vector>
//#include <string>
//#include <iostream>
//#include <ctime>
#include <random>

#include "Offsets.h"

//using namespace std;

typedef struct _NULL_MEMORY
{
	void* buffer_address;
	UINT_PTR address;
	ULONGLONG size;
	ULONG pid;
	BOOLEAN write;
	BOOLEAN read;
	BOOLEAN req_base;
	void* output;
	const char* module_name;
	ULONG64 base_address;
}NULL_MEMORY;

uintptr_t base_address = 0;
std::uint32_t process_id = 0;

// Vector3 is used to store 3 floats, the x, y, and z coordinates.
struct Vector3 {
	float x, y, z;
};

// Matrix is used to store 16 bytes for our view matrix.
struct Matrix {
	float matrix[16];
};

struct GlowMode
{
	int8_t GeneralGlowMode, BorderGlowMode, BorderSize, TransparentLevel;
};

struct GlowColor
{
	float R, G, B;
};


template<typename ... Arg>
uint64_t CallHook(const Arg ... args)
{
	void* hooked_func = GetProcAddress(LoadLibrary("win32u.dll"), "NtDxgkVailPromoteCompositionSurface");

	auto func = static_cast<uint64_t(_stdcall*)(Arg...)>(hooked_func);

	return func(args ...);
}

struct HandleDisposer
{
	using pointer = HANDLE;
	void operator()(HANDLE handle) const
	{
		if (handle == NULL || handle == INVALID_HANDLE_VALUE) return;
		CloseHandle(handle);
	}
};

using unique_handle = std::unique_ptr<HANDLE, HandleDisposer>;

std::uint32_t GetProcessId(std::string_view process_name)
{
	PROCESSENTRY32 processentry;
	const unique_handle snapshot_handle(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL));

	if (snapshot_handle.get() == INVALID_HANDLE_VALUE)
		return NULL;

	processentry.dwSize = sizeof(MODULEENTRY32);

	while (Process32Next(snapshot_handle.get(), &processentry) == TRUE)
	{
		if (process_name.compare(processentry.szExeFile) == NULL)
		{
			return processentry.th32ProcessID;
		}
	}
	return NULL;
}

static ULONG64 GetModuleBaseAddress(const char* module_name)
{
	NULL_MEMORY instructions = { 0 };
	instructions.pid = process_id;
	instructions.req_base = TRUE;
	instructions.read = FALSE;
	instructions.write = FALSE;
	instructions.module_name = module_name;
	CallHook(&instructions);
	
	ULONG64 base = NULL;
	base = instructions.base_address;
	return base;
}
template <class T>
T Read(uintptr_t read_address)
{
	T response{};
	NULL_MEMORY instructions;
	instructions.pid = process_id;
	instructions.size = sizeof(T);
	instructions.address = read_address;
	instructions.read = TRUE;
	instructions.write = FALSE;
	instructions.req_base = FALSE;
	instructions.output = &response;
	CallHook(&instructions);

	return response;
}


bool WriteMemory(UINT_PTR write_address, UINT_PTR source_address, SIZE_T write_size)
{
	NULL_MEMORY instructions;
	instructions.address = write_address;
	instructions.pid = process_id;
	instructions.write = TRUE;
	instructions.read = FALSE;
	instructions.req_base = FALSE;
	instructions.buffer_address = (void*)source_address;
	instructions.size = write_size;
	CallHook(&instructions);

	return true;
}

template<typename S>
bool Write(UINT_PTR write_address, const S& value)
{
	return WriteMemory(write_address, (UINT_PTR)&value, sizeof(S));
}

DWORD64 GetEntityById(int Ent)
{
	DWORD64 EntityList = base_address + OFFSET_ENTITYLIST;
	DWORD64 BaseEntity = Read<DWORD64>(EntityList);
	if (!BaseEntity)
	return NULL;
	return  Read<DWORD64>(EntityList + (Ent << 5));
}

std::string GetRandomString(const int len) {
	const std::string alpha_numeric("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890");

	std::default_random_engine generator{ std::random_device{}() };
	const std::uniform_int_distribution< std::string::size_type > distribution{ 0, alpha_numeric.size() - 1 };

	std::string str(len, 0);
	for (auto& it : str) {
		it = alpha_numeric[distribution(generator)];
	}

	return str;
}

// WorldToScreen
struct Vector3 _WorldToScreen(const struct Vector3 pos, struct Matrix matrix, int width, int height) {
	struct Vector3 out;
	float _x = matrix.matrix[0] * pos.x + matrix.matrix[1] * pos.y + matrix.matrix[2] * pos.z + matrix.matrix[3];
	float _y = matrix.matrix[4] * pos.x + matrix.matrix[5] * pos.y + matrix.matrix[6] * pos.z + matrix.matrix[7];
	out.z = matrix.matrix[12] * pos.x + matrix.matrix[13] * pos.y + matrix.matrix[14] * pos.z + matrix.matrix[15];

	_x *= 1.f / out.z;
	_y *= 1.f / out.z;

	out.x = width * .5f;
	out.y = height * .5f;

	out.x += 0.5f * _x * width + 0.5f;
	out.y -= 0.5f * _y * height + 0.5f;

	return out;
}

float GetDistance2D(float x1, float y1, float x2, float y2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void WaitForProcessLaunch(const char* module_name) {
	while (!process_id) {
		process_id = GetProcessId(module_name);
		Sleep(500);
	}
	base_address = GetModuleBaseAddress(module_name);
}
