#pragma once
#include <string>
#include <memory>

class User_Profile
{
public:
	User_Profile(const std::string& name_user, const int age_user, const std::string& mail);
	~User_Profile();
	void print_profile_summary();
	void change_name(const std::string& new_name);
	void change_age(const int new_age);
	void change_email(const std::string& new_email);
private:
	struct Impl;
	std::unique_ptr<Impl> pimpl{};
	const bool is_valid_email(const std::string& mail) const;
};