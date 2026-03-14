#include "Participant.h"

size_t Participant::global_instance_count{ 0 };

Participant::~Participant()
{
	--global_instance_count;
	std::cout << "Participant " << name << " deleted! Number of living objects left: '" << Participant::global_instance_count << "'\n";
}

void Participant::print_info_about_participant() const
{
	std::cout << "Info about participant:\n"
		<< "\tname:\t" << this->name << "\n\n";
}

size_t Participant::get_live_objects_count()
{
	return Participant::global_instance_count;
}