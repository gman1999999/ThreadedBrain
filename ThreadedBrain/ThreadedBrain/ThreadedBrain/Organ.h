#pragma once
#include <set>
#include "Cell.h"
#include <Windows.h>

#define NR 3

class Organ
{
protected:
	std::set <Cell*> cellList;
public:
	Organ();
	virtual ~Organ();
	void AddCell();		//add a cell to the display, with a random multiplier
	void AddCell(double multiplier);	//add a cell to the display, with a set multiplier
	bool RemoveCell(int ID, uint32_t orderNumber);		//remove a cell from the display, using either the ID or the order in the set of the display; if the ID is not -1, the orderNumber param is ignored, else the cell in the orderNumber position of the set will be removed
};

