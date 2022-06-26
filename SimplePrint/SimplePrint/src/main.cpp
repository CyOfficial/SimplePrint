#pragma warning(disable:4996)

#include "functions/functions.h"

#include <thread>
#include <iostream>

void user_input()
{
	static int print_type = 0;
	static bool ask_for_type = true;

	while (true)
	{
		if (ask_for_type)
		{
			std::string type_received;
			std::cout << "Please enter a Type! (0 = Print, 1 = Info, 2 = Warn, 3 = Error): ";
			getline(std::cin, type_received);
			print_type = stoi(type_received);

			ask_for_type = false;
		}
		else
		{
			std::string string_to_output;
			std::cout << "Please enter the Message you would like to be Outputted to the Console: ";
			getline(std::cin, string_to_output);

			Functions::print_to_developer_console(print_type, string_to_output);

			ask_for_type = true;
		}

		Sleep(1);
	}
}

void main()
{
	Functions::Console(); // Create a Console

	// Welcome the User
	std::cout << "Welcome to SimplePrint!" << std::endl;
	std::cout << "This is a Simple Print Exploit that aims to help Developers learn how to make Exploits!" << std::endl;
	std::cout << "Have fun!" << std::endl;
	std::cout << "(Made by Cy#0730. Licensed under GPL V3.0. Please follow the License to avoid action being taken.)" << std::endl;
	
	// Print to the Developer Console to Notify the User that SimplePrint is Ready!
	Functions::print_to_developer_console(0, "SimplePrint is Ready!");

	// Get Input from the User
	CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)user_input, nullptr, NULL, nullptr);
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		std::thread(main).detach();
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}