#include "Organ.h"

Organ::Organ()
{
}


Organ::~Organ()
{
}

//add the pointer of a newly created cell to the set
void Organ::AddCell()
{
	this->cellList.insert(new Cell());
}

//add the pointer of a newly created cell to the set; cell is created with a set multiplier
void Organ::AddCell(double multiplier)
{
	this->cellList.insert(new Cell(multiplier));
}

//remove cell by ID if ID is not -1, remove by order number in the set if ID is -1
bool Organ::RemoveCell(int ID, uint32_t orderNumber)
{
	return false;
}