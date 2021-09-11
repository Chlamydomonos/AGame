#include "AllRegistries.h"

AllRegistries *AllRegistries::instance{ nullptr };

AllRegistries::~AllRegistries()
{
	for (auto i : map)
	{
		delete i;
	}
}
