#include "AllRegistries.h"

AllRegistries AllRegistries::instance{};

AllRegistries::~AllRegistries()
{
	for (auto i : map)
	{
		delete i;
	}
}
