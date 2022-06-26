#include <cstdint>
#include <Windows.h>

namespace rbx
{
	std::uintptr_t print_address = reinterpret_cast<std::uintptr_t>(GetModuleHandle(NULL)) + 0x3E9470;
}