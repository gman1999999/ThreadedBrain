#include "Logger.h"

Logger* Logger::logger;

std::mutex Logger::locker;

std::ofstream Logger::file;

Logger::Logger()
{
	file.open("log.txt", std::ios::app);
}


Logger::~Logger()
{
}

Logger* Logger::getInstance()
{
	if (logger != NULL)
	{
		return logger;
	}
	else 
	{
		file.open("log.txt", std::ios::out);
		file.close();
		logger = &Logger();
		return logger;
	}
}

