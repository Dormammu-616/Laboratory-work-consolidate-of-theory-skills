#pragma once
#include <iostream>

class Participant
{
public:
	Participant() = delete;
	Participant(const size_t id_from_user, const std::string& name_from_user) : id(id_from_user), name((name_from_user == "") ? "Unknown" : name_from_user) { std::cout << "The participant '" << name << "' created!\n"; };
	~Participant();
	Participant& set_score(const double score);
	std::string change_name(const std::string& name);
	int round_to_int_score() const;
	size_t id_hash() const;
	void print_info_about_participant() const;
private:
	size_t id;
	std::string name{"Unknown"};
	double score{ 0.0 };
};