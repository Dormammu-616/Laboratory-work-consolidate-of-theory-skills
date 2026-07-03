#include "CompetitionManager.h"

CompetitionManager::CompetitionManager(const std::string& heading, const size_t limit_participant) : setting(heading, limit_participant) {};

CompetitionManager::~CompetitionManager()
{
	for (auto& member : participants)
	{
		delete member;
		member = nullptr;
	}

	std::cout << "All participants have been removed!\n";
}

void CompetitionManager::dispatch_participant(const std::string& name)
{
	if (participants.size() > setting.max_participants)
	{
		std::cout << "ERROR: the max limit of participants has been exceeded!\n";
		return;
	}

	participants.emplace_back(new Participant(name));
}

void CompetitionManager::perform_check_up()
{
	{
		Participant inspector{ "Inspector" };
		inspector.print_info_about_participant();
	}

	std::cout << "Check up finished!\n";
}
