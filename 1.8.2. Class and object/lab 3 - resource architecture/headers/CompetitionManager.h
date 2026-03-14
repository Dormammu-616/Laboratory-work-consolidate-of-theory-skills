#pragma once
#include "CompetitionSettings.h"
#include "Participant.h"
#include <vector>

class CompetitionManager
{
public:
	CompetitionManager() = delete;
	CompetitionManager(const std::string& heading, const size_t limit_participant);
	~CompetitionManager();
	void dispatch_participant(const std::string& name);
	void perform_check_up();
private:
	CompetitionSettings setting;
	std::vector<Participant*> participants{};
};