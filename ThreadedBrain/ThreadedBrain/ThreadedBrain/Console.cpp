#include "Console.h"
#include <ios>
#include <iostream>


Console::Console()
{
}

void Console::WaitInput()
{
	char buffer[256];
	std::string aux;
	while (true)
	{
		buffer[0] = 0;
		std::cin.clear();
		std::cin >> buffer;
		aux = buffer;
		//do something with the message
	}
}


Console::~Console()
{
}
