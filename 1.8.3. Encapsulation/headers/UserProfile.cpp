#include "UserProfile.h"
#include <iostream>
#include <stdexcept>

struct User_Profile::Impl
{
	std::string name{};
	size_t age{};
	std::string email{};
};

User_Profile::User_Profile(const std::string& name_user, const int age_user, const std::string& mail) : pimpl(std::make_unique<Impl>())
{
	change_name(name_user);
	change_age(age_user);
	change_email(mail);
}

const bool User_Profile::is_valid_email(const std::string& mail) const
{
	if (!mail.empty() && mail.at(0) == '@')
	{
		return true;
	}

	return false;
}

User_Profile::~User_Profile() = default;

void User_Profile::print_profile_summary()
{
	std::cout << "Profile information\n"
		<< "Name:\t" << pimpl->name
		<< "\nAge:\t" << pimpl->age
		<< "\nEmail:\t" << pimpl->email << "\n";
}

void User_Profile::change_name(const std::string& new_name)
{
	if (new_name.empty())
	{
		throw std::invalid_argument("the name must not be empty!\n");
	}

	pimpl->name = new_name;
}

void User_Profile::change_age(const int new_age)
{
	if (new_age <= 0)
	{
		throw std::invalid_argument("age must be greater than 0!\n");
	}

	pimpl->age = new_age;
}

void User_Profile::change_email(const std::string& new_email)
{
	if (!is_valid_email(new_email))
	{
		throw std::invalid_argument("the email must begin with the '@' sign!\n");
	}

	pimpl->email = new_email;
}