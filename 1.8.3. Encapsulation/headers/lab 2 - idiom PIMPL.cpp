#include "lab 2 - idiom PIMPL.h"
#include "UserProfile.h"
#include <iostream>

void Idiom_PIMPL::run_lab()
{
	std::cout << "***\tLab # 2 - Idiom PIMPL\t***";
	std::cout << "--- Correct data ---\n";
	User_Profile correct_user{ "Bob", 39, "@bob" };
	
	std::cout << "Correct profile created!\n";
	correct_user.print_profile_summary();

	std::cout << "\nCorrect data change\n";
	correct_user.change_name("Alice");
	correct_user.change_age(20);
	correct_user.change_email("@alice");
	correct_user.print_profile_summary();
	std::cout << "\n";

	std::cout << "--- Incorrect data ---\n";
	
	std::cout << "Attempt to create profile with incorrect data: ";
	try
	{
		User_Profile nocorrect_profile{ "", 20, "@nocorrect" };
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "\tERROR - " << e.what();
	}

	std::cout << "Attempt to change name to empty: ";
	try
	{
		correct_user.change_name("");
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "\t\tERROR - " << e.what();
	}

	std::cout << "Attempt to change age to negative: ";
	try
	{
		correct_user.change_age(-5);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "\t\tERROR - " << e.what();
	}

	std::cout << "Attempt to change email without the '@' sign: ";
	try
	{
		correct_user.change_email("nocorrect email");
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "\tERROR - " << e.what();
	}

	// ÎØÈÁÊÈ êîìïèëÿöèè:
	//correct_user.age;

	std::cout << "\n***\tThe end labs #2\t***\n\n";
}