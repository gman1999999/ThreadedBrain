#pragma once
#include "Organ.h"

class Eye :
	public Organ
{
public:
	Eye();
	~Eye();
	void AddCell();		//add cell in Eye set (generate multiplier randomly between 0 and 2 (limits excluded)
	void AddCell(double multiplier);	//add a cell in Eye set with set multiplier
	bool RemoveCell(int ID, uint32_t orderNumber);	//remove cell from eye set by ID, or by order in set if ID is -1
	void InitStart();	//start new thread and keep alive
};

