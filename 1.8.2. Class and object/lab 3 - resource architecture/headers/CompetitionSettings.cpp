#include "CompetitionSettings.h"

CompetitionSettings::CompetitionSettings(const std::string& heading, const size_t limit_participant) : title(heading), max_participants(limit_participant)
{
	std::cout << "The setting was successfully created with the name '" << title << "'.\n";
};