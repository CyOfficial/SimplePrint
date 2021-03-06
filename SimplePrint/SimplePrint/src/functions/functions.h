#pragma once

#include "rbx/addresses.h"

#include <string>
#include <time.h>
#include <Windows.h>

typedef int(__cdecl* print_rbx_t)(int, const char*, ...);
print_rbx_t print_rbx = (print_rbx_t)(rbx::print_address);

namespace Functions
{
	std::string RandomString(const size_t length)
	{
		std::string r;
		static const char bet[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYabcdefghijklmnopqrstuvwxyzZ1234567890" };
		srand((unsigned)time(NULL) * 5);
		for (int i = 0; i < length; ++i)
			r += bet[rand() % (sizeof(bet) - 1)];
		return r;
	}

	auto Console = []() {
		DWORD TuxHurtPro;
		VirtualProtect((PVOID)&FreeConsole, 1, PAGE_EXECUTE_READWRITE, &TuxHurtPro);
		*(BYTE*)(&FreeConsole) = 0xC3;
		AllocConsole();
		freopen("CONOUT$", "w", stdout);
		freopen("CONIN$", "r", stdin);
		HWND ConsoleHandle = GetConsoleWindow();
		SetConsoleTitleA(RandomString(25).c_str());
		::SetWindowPos(ConsoleHandle, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
		::ShowWindow(ConsoleHandle, SW_NORMAL);
	};

	bool print_to_developer_console(int printType, std::string output)
	{
		// 0 = Print, 1 = Info, 2 = Warn, 3 = Error.
		if (printType < 0 || printType > 3) return false;

		print_rbx(printType, output.c_str());

		return true;
	}
}