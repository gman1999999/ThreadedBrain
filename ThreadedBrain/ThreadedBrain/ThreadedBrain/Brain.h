#pragma once
#include "Organ.h"

class Brain : Organ
{
private:
	
public:
	Brain();
	~Brain();

	void AddCell();		//add cell in brain set with random multiplier
	void AddCell(double multiplier);	//add cell to brain set with specific multiplier
	bool RemoveCell(int ID, uint32_t orderNumber);	//remove cell from brain set by ID or order number if ID is -1
	void InitStart();	//create thread and keep alive
};

