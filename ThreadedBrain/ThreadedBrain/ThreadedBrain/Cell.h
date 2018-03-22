#pragma once
#include <set>
#include <thread>
#include "Logger.h"
#include <iostream>

class Cell
{
protected:
	int m_ID;
	double m_multiplier=1;
	std::set<Cell*> receivers;
	std::thread m_life;
	Logger* m_logger;
public:
	static int s_cell_nr;
	Cell() : m_life(&Cell::doStuff, this) 
	{
		srand(reinterpret_cast <unsigned int> (this));
		m_ID = s_cell_nr;
		//s_cell_nr++;
		m_multiplier = (static_cast <double> (rand()) / static_cast <double> (RAND_MAX)) * 2;
		std::string message = "";
		message = "Neuron " + std::to_string(m_ID) + " has multiplier " + std::to_string(this->getMultiplier()) + ".\n";
		
		m_logger->write(message);
	};

	Cell(double m);
	~Cell();

	void doStuff();

	std::thread::id getThreadID();

	double getMultiplier();

	int getID();
};