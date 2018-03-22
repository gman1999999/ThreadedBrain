#pragma once
#include <mutex>
#include <fstream>
#include <string>
#include <time.h>

class Logger
{
private:
	Logger();
	static Logger* logger;
	static std::mutex locker;
	static std::ofstream file;
public:
	~Logger();
	static Logger* getInstance();
	void Logger::write(std::string message)
	{
		time_t rawtime;
		tm timeinfo;
		char buffer[80] = "";

		locker.lock();
		
		file.open("log.txt", std::ios::app);

		rawtime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		
		localtime_s(&timeinfo, &rawtime);
		ctime_s(buffer, sizeof(buffer), &rawtime);
		buffer[strlen(buffer)-1] = 0;

		file << buffer;
		file << "\t";
		file << message;

		file.close();

		locker.unlock();
	}
};

