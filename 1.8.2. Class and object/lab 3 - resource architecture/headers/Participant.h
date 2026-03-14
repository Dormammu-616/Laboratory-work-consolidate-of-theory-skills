#pragma once
#include <iostream>

class Participant
{
public:
	Participant() = delete;
	Participant(const std::string& name_from_user) : name((name_from_user == "") ? "Unknown" : name_from_user)
	{
		++global_instance_count;
		std::cout << "The participant '" << name << "' created! (Active participant: " << Participant::global_instance_count << ")\n";
	};
	~Participant();
	void print_info_about_participant() const;
	static size_t get_live_objects_count();
private:
	std::string name{};
	static size_t global_instance_count;
};