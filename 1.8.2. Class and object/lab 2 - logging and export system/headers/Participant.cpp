#include "Participant.h"

Participant::Participant(const size_t start_score, const std::string& name_from_user) : score(start_score), name((name_from_user == "") ? "Unknown" : name_from_user)
{
	std::cout << "\tParticipant::Participant: the participant '" << name << "' created!\n";
}

Participant::~Participant()
{
	std::cout << "\tParticipant::~Participant: participant " << name << " deleted!\n";
}

std::ostream& operator<<(std::ostream& os, const Participant& participant)
{
	os << "Participant\n" << "\tname: " << participant.name << "\n"
		<< "\tscore: " << participant.score << "\n\n";

	return os;
}