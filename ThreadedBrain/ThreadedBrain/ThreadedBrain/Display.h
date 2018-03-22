#pragma once
#include "Organ.h"

class Display :
	public Organ
{
public:
	Display();
	~Display();
	void InitStart();	//function containing the life of the display; used to create a separate thread
};

