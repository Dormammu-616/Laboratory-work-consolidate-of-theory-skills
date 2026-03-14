#pragma once
#include "Participant.h"
#include <vector>

class CompetitionManager
{
public:
	CompetitionManager() = delete;
	CompetitionManager(const size_t points, const std::string& name);
	~CompetitionManager();
	friend std::ostream& operator<< (std::ostream& os, const CompetitionManager& manager);
	void add_participant(const size_t points, const std::string& name);
private:
	std::vector<Participant*> participants{};
	class DataProcessor
	{
	public:
		bool is_valid_score(const size_t score) const;
	};
};