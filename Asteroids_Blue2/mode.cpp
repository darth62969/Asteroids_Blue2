#include "mode.h"

std::vector<std::shared_ptr<object>> mode::getOnScreen()
{
	return *onScreen;
}

void mode::addToOnScreen(std::shared_ptr<object> obj)
{
	onScreen->push_back(obj);
}