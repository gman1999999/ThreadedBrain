#include "Display.h"


//empty constructor
Display::Display()
{
}

//empty destructor
Display::~Display()
{
}





//start a new thread and keep alive
void Display::InitStart()
{
	for (int i = 0; i < NR; i++)
	{
			this->AddCell();
	}

	while (true)
	{
		std::string message = "";
		message = "Display thread works.\n";
		Logger* log = Logger::getInstance();
		log->write(message);
		Sleep(2000);
	}
}
