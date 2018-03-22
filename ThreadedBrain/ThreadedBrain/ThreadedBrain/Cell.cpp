#pragma once
#include "Cell.h"

int Cell::s_cell_nr = 0;

Cell::Cell(double m):m_ID(s_cell_nr),m_multiplier(m),m_logger(Logger::getInstance())
{
	s_cell_nr++;

	std::string message = "";
	message = "Neuron " + std::to_string(m_ID) + " has multiplier " + std::to_string(getMultiplier()) + ".\n";
	
	m_logger->write(message);
}

Cell::~Cell()
{
	std::string message = "";
	message = "Shit, I'm dead #" + std::to_string(getID());
	m_logger->write(message);
}

void Cell::doStuff()
{

}

std::thread::id Cell::getThreadID()
{
	return m_life.get_id();
}

double Cell::getMultiplier()
{
	return m_multiplier;
}

int Cell::getID()
{
	return m_ID;
}
