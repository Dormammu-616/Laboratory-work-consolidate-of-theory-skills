#include "CompetitionLogger.h"

void CompetitionLogger::log_deep_scan(const Participant& member)
{
	std::cout << "Info from class 'Participant':\n"
		<< "\tname: " << member.name << "\n"
		<< "\tscore: " << member.score << "\n"
		<< "\tadress: " << &member<< "\n\n";
}