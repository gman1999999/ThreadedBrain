#include "Brain.h"

void Brain::AddCell()
{
	this->cellList.insert(new Cell());
}

void Brain::AddCell(double multiplier)
{
	this->cellList.insert(new Cell(multiplier));
}

bool Brain::RemoveCell(int ID, uint32_t orderNumber)
{
	bool res = false;
	if (ID==-1)
	{
		if (orderNumber < this->cellList.size())
		{
			std::set<Cell*>::iterator it;
			it = this->cellList.begin();
			for (uint32_t i = 0; i < orderNumber; i++)
			{
				it++;
			}
			this->cellList.erase(it);
			printf("Cell at position %d in set was removed.\n", orderNumber);
			res = true;
		}
	}
	else
	{
		for each (Cell* aux in this->cellList)
		{
			if (aux->getID() == ID)
			{
				this->cellList.erase(aux);
				printf("Cell with ID %d was removed.\n", ID);
				res = true;
				break;
			}
		}
	}
	return res;
}

Brain::Brain()
{
}

Brain::~Brain()
{
}

void Brain::InitStart()
{
	for (int i = 0; i < NR; i++)
	{
		this->AddCell();
	}
	
	while (true)
	{
		std::string message = "";
		message = "Brain thread works.\n";
		Logger* log = Logger::getInstance();
		log->write(message);
		Sleep(2000);
	}
}

