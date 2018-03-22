#include "Eye.h"


//empty constructor
Eye::Eye()
{
}

//empty destructor
Eye::~Eye()
{
}

//add cell in eye set using random multiplier
void Eye::AddCell()
{
	this->cellList.insert(new Cell());
}

//add cell in eye set using specific multiplier
void Eye::AddCell(double multiplier)
{
	this->cellList.insert(new Cell(multiplier));
}

//remove cell from eye using ID, or oder number in set if ID is -1
bool Eye::RemoveCell(int ID, uint32_t orderNumber)
{
	return false;
}

//start thread and keep alive
void Eye::InitStart()
{
	for (int i = 0; i < NR; i++)
	{
		this->AddCell();
	}

	while (true)
	{
		std::string message = "";
		message = "Eye thread works.\n";
		Logger* log = Logger::getInstance();
		log->write(message);
		Sleep(2000);
	}
}
