#pragma once
#include "Cell.h"
struct sigMsg
{
	Cell* caller;
	int ID;
	float sigPower;
};