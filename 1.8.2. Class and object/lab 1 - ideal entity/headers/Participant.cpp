#include "Participant.h"
#include <functional>

Participant::~Participant()
{
	std::cout << "Participant " << name << " deleted!\n";
}

Participant& Participant::set_score(const double score)
{
	this->score = score;
	return *this;
}

std::string Participant::change_name(const std::string& name)
{
	const std::string OLD_NAME = this->name;
	this->name = name;
	return OLD_NAME;
}

int Participant::round_to_int_score() const
{
	const int ROUNDED_VALUE(static_cast<int>(this->score));
	return ROUNDED_VALUE;
}

size_t Participant::id_hash() const
{
	const size_t ID_HASH{ std::hash<size_t>{} (this->id)};
	return ID_HASH;
}

void Participant::print_info_about_participant() const
{
	std::cout << "Info about participant:\n"
		<< "\tname:\t" << this->name << "\n"
		<< "\tid:\t" << this->id << "\n"
		<< "\tscore:\t" << this->score << "\n\n";
}
