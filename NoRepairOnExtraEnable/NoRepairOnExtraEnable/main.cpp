#include "main.hpp"

#include "pattern.hpp"

#include <fstream>

void patch()
{
	std::ofstream log("NoRepairOnExtraEnable.log");

	log << "Searching for virtual function call." << std::endl;
	if (void* loc = ScanPattern("\xFF\x90\x00\x00\x00\x00\x48\x8B\x4B\x20\x8B\x81", "xx????xxxxxx"))
	{
		memset(loc, 0x90, 6);
		log << "Virtual function call patched." << std::endl;
	}
	else
	{
		log << "Failed to find virtual function call." << std::endl;
	}
}
