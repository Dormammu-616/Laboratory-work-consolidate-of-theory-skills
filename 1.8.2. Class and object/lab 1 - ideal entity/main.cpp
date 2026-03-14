#include "Participant.h"

void test_operation_of_class(Participant& obj_participant)
{
    std::cout << "Start ";
    obj_participant.print_info_about_participant();

    const double START_SCORE{ 40.8 };
    std::cout << "User rating changed to '" << START_SCORE << "'.\n";
    obj_participant.set_score(START_SCORE);

    const std::string FIRST_MOD_NAME{ "First_mod_name" };
    const std::string START_NAME{ obj_participant.change_name(FIRST_MOD_NAME) };
    std::cout << "The old name '" << START_NAME << "' has been replaced with the new '" << FIRST_MOD_NAME << "'.\n";

    std::cout << "The rounded value of the rating will be equal to '" << obj_participant.round_to_int_score() << "'.\n";
    std::cout << "The hash value for participant ID: " << obj_participant.id_hash() << "'\n";

    std::cout << "\nAfter first change ";
    obj_participant.print_info_about_participant();

    const double MOD_SCORE{ 14.2 };
    const std::string SECOND_MOD_NAME{ "Second_mod_name" };
    std::cout << "The points value has been changed to '" << MOD_SCORE << "' and the name to '" << SECOND_MOD_NAME << "' via call chains.";
    obj_participant.set_score(MOD_SCORE).change_name(SECOND_MOD_NAME);

    std::cout << "\nAfter second change ";
    obj_participant.print_info_about_participant();
}

int main()
{
    const size_t ID_USER{ 5 };
    const std::string START_NAME_USER{ "Start_name" };

    std::cout << "Checking the operation of an object on the stack and heap.\n";

    {
        std::cout << "\n*** Creating an object on the stack ***\n\n";
        Participant participant_stack(ID_USER, START_NAME_USER);

        test_operation_of_class(participant_stack);
    }

    {
        std::cout << "\n*** Creating an object on the heap ***\n\n";
        Participant* participant_heap{ new Participant(ID_USER, START_NAME_USER) };

        test_operation_of_class(*participant_heap);

        delete participant_heap;
        participant_heap = nullptr;
    }

    return 0;
}