#pragma once
#include <iostream>

class CompetitionSettings
{
public:
	CompetitionSettings() = delete;
	const std::string title{};
	const size_t max_participants{};
	CompetitionSettings(const std::string& heading, const size_t limit_participant);
	~CompetitionSettings() { std::cout << "The setting with name '" << title << "' destroyed.\n"; };
};