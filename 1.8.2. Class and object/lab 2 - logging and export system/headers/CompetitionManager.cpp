#include "CompetitionManager.h"

CompetitionManager::CompetitionManager(const size_t points, const std::string& name)
{
	size_t point_for_save{ points };
	DataProcessor check_data;

	if (!check_data.is_valid_score(points))
	{
		std::cout << "\tCompetitionManager::CompetitionManager: ERROR - the score must be greater than 0!\n"
			<< "\tThe 'score' field will be assigned the default value '1'.\n";
		point_for_save = 1;
	}

	this->participants.emplace_back(new Participant(point_for_save, name));
	std::cout << "\tCompetitionManager::CompetitionManager: the point value '" << point_for_save << "' was successfully saved!\n";
}

CompetitionManager::~CompetitionManager()
{
	for (auto& member : participants)
	{
		delete member;
		member = nullptr;
	}

	std::cout << "\tCompetitionManager::~CompetitionManager: all participants have been removed!\n";
}

void CompetitionManager::add_participant(const size_t points, const std::string& name)
{
	DataProcessor check_data;

	if (!check_data.is_valid_score(points))
	{
		std::cout << "\tCompetitionManager::add_participant: ERROR - the score must be greater than 0!\n";
		return;
	}

	this->participants.emplace_back(new Participant(points, name));
}

bool CompetitionManager::DataProcessor::is_valid_score(const size_t score) const
{
	std::cout << "\tChecking the value of points to assign to a participant.\n";

	if (score <= 0)
	{
		return false;
	}

	return true;
}

std::ostream& operator<< (std::ostream& os, const CompetitionManager& manager)
{
	os << "The manager contains elements:\n";

	for (const auto& member : manager.participants)
	{
		os << *member;
	}

	return os;
}