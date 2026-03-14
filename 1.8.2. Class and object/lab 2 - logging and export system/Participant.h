#pragma once
#include <iostream>

class Participant
{
public:
	Participant() = delete;
	Participant(const size_t start_score, const std::string& name_from_user);
	~Participant();
	friend class CompetitionLogger;
	friend std::ostream& operator<<(std::ostream& os, const Participant& participant);
private:
	size_t score;
	std::string name;
};